#pragma once

#include <utility>
#include <limits>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

template<typename T>
class BinaryTreeNode
{
public:

	BinaryTreeNode(T data) :
		mData(data),
		mLeftNode(nullptr),
		mRightNode(nullptr)
	{
	}

	~BinaryTreeNode() 
	{
		if (nullptr != mData)
		{
			delete mData;
			mData = nullptr;
		}

		if (nullptr != mLeftNode)
		{
			delete mLeftNode;
			mLeftNode = nullptr;
		}

		if (nullptr != mRightNode)
		{
			delete mRightNode;
			mRightNode = nullptr;
		}
	}
	// disabled the copy Ctor to prevent throwing copies of nodes around
	BinaryTreeNode(const BinaryTreeNode& node) = delete;



	bool HasLeftChildNode() const { return (nullptr != this->mLeftNode); }
	bool HasRightChildNode() const { return (nullptr != this->mRightNode); }
	bool HasData() { return (nullptr != this->mData); }

	const T GetDataConst() { return mData; }
	T GetData() const { return mData; }
	const BinaryTreeNode* GetLeftChildNodeConst() const { return this->mLeftNode; }
	const BinaryTreeNode* GetRightChildNodeConst() const { return this->mRightNode; }

	BinaryTreeNode* GetLeftChildNode() { return this->mLeftNode; }
	BinaryTreeNode* GetRightChildNode() { return this->mRightNode; }

	BinaryTreeNode* InsertLeft(T data) { this->mLeftNode = new BinaryTreeNode(data); return this->mLeftNode; }
	BinaryTreeNode* InsertRight(T data) { this->mRightNode = new BinaryTreeNode(data); return this->mRightNode; }

	bool IsBalanced(const BinaryTreeNode* treeRoot);
	bool IsBinarySearchTree(const BinaryTreeNode* treeRoot);

	void BreadthFirst(const BinaryTreeNode<T>* root);
	void BreadthFirstRecursive(const BinaryTreeNode<T>* root);
	void DepthFirst(const BinaryTreeNode<T>* root);
	void DepthFirstRecursive(const BinaryTreeNode<T>* root);

private:
	// Data could be anything so making this a pointer
	T mData = NULL;
	BinaryTreeNode* mLeftNode = nullptr;
	BinaryTreeNode* mRightNode = nullptr;
};

class NodeBounds
{
public:
	NodeBounds(const BinaryTreeNode<int>* inNode = nullptr,
				int inLowerBound = std::numeric_limits<int>::min(),
				int inUpperBound = std::numeric_limits<int>::max()) :
		mNode(inNode),
		mLowerBound(inLowerBound),
		mUpperBound(inUpperBound)
	{
	}

	BinaryTreeNode<int>* GetNode() { return (BinaryTreeNode<int>*)mNode; }
	const int GetLowerBound() const { return mLowerBound; }
	const int GetUpperBound() const { return mUpperBound; }

private:
	const BinaryTreeNode<int>* mNode;
	int mLowerBound;
	int mUpperBound;
};

template<typename T>
bool BinaryTreeNode<T>::IsBalanced(const BinaryTreeNode<T>* treeRoot)
{

	// if there are no nodes, it's balanced
	if (treeRoot == nullptr)
	{
		return true;
	}

	size_t depths[3];
	//std::vector<size_t> depths;
	size_t depthCount = 0;

	std::stack<std::pair<const BinaryTreeNode*, size_t>> nodes;
	nodes.push(make_pair(treeRoot, 0));

	while (!nodes.empty())
	{
		const BinaryTreeNode* node = nodes.top().first;
		size_t depth = nodes.top().second;
		nodes.pop();

		// at a leaf so lets operate
		if (!node->mLeftNode && !node->mRightNode)
		{
			if (depthCount == 0 ||
				find(depths, depths + depthCount, depth) == depths + depthCount)
				// make this line with with a vector to better understand
				//find(depths.begin(), depths.end(), depth) == (depths + depthCount))
			{
				depths[depthCount] = depth;
				++depthCount;
			}

			if (depthCount > 2 ||
			   (depthCount == 2 && max(depths[0], depths[1]) - min(depths[0], depths[1]) > 1))
			{
				return false;
			}
		}
		else
		{
			if (node->mLeftNode)
			{
				nodes.push(make_pair(node->mLeftNode, depth + 1));
			}

			if (node->mRightNode)
			{
				nodes.push(make_pair(node->mRightNode, depth + 1));
			}
		}
	}
	
	return true;
}

// Testing for if Binary Tree by performing depth-first search on nodes
template<typename T>
bool BinaryTreeNode<T>::IsBinarySearchTree(const BinaryTreeNode<T>* treeRoot)
{
	if (treeRoot == nullptr)
	{
		return true;
	}

	std::stack<NodeBounds> nodeAndBoundsStack;
	nodeAndBoundsStack.push(NodeBounds(treeRoot));

	while (!nodeAndBoundsStack.empty())
	{
		NodeBounds nodeBounds = nodeAndBoundsStack.top();
		nodeAndBoundsStack.pop();

		const int nodeValue = nodeBounds.GetNode()->GetData();
		if (nodeValue <= nodeBounds.GetLowerBound() || nodeValue >= nodeBounds.GetUpperBound())
		{
			return false;
		}

		if (nodeBounds.GetNode()->GetLeftChildNode() != nullptr)
		{
			nodeAndBoundsStack.push(NodeBounds(nodeBounds.GetNode()->GetLeftChildNode(), 
									nodeBounds.GetLowerBound(), nodeValue));
		}

		if (nodeBounds.GetNode()->GetRightChildNode() != nullptr)
		{
			nodeAndBoundsStack.push(NodeBounds(nodeBounds.GetNode()->GetRightChildNode(),
									nodeValue, nodeBounds.GetUpperBound()));
		}
	}

	return true;
}

// iterative breadthfirst, not ordering correctly - revisit
template<typename T>
void BinaryTreeNode<T>::BreadthFirst(const BinaryTreeNode<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	queue<const BinaryTreeNode<T>*> nodeQueue;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		const BinaryTreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		std::cout << "Node Data: " << (node->GetData()) << std::endl;

		if (node->HasLeftChildNode())
		{
			nodeQueue.push(node->GetLeftChildNodeConst());
		}

		if (node->HasRightChildNode())
		{
			nodeQueue.push(node->GetRightChildNodeConst());
		}
	}
}

// ordering not correct - revisit
template<typename T>
inline void BinaryTreeNode<T>::BreadthFirstRecursive(const BinaryTreeNode<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << "Node Data: " << (root->GetData()) << std::endl;

	BreadthFirstRecursive(root->GetLeftChildNodeConst());
	BreadthFirstRecursive(root->GetRightChildNodeConst());
}

// iterative depthfirst, not ordering correctly - revisit
template<typename T>
void BinaryTreeNode<T>::DepthFirst(const BinaryTreeNode<T>* root)
{
	if (root == nullptr)
	{
		return;
	}

	stack<const BinaryTreeNode<T>*> nodeStack;
	nodeStack.push(root);

	while (!nodeStack.empty())
	{
		const BinaryTreeNode* node = nodeStack.top();
		nodeStack.pop();

		std::cout << "Node Data: " << (node->GetData()) << std::endl;

		if (node->HasLeftChildNode())
		{
			nodeStack.push(node->GetLeftChildNodeConst());
		}

		if (node->HasRightChildNode())
		{
			nodeStack.push(node->GetRightChildNodeConst());
		}
	}
}

// ordering as expected
template<typename T>
inline void BinaryTreeNode<T>::DepthFirstRecursive(const BinaryTreeNode<T>* root)
{
	if (root == nullptr)
	{
		return;
	}
	
	std::cout << "Node Data: " << (root->GetData()) << std::endl;
	DepthFirstRecursive(root->GetLeftChildNodeConst());
	DepthFirstRecursive(root->GetRightChildNodeConst());
}


