#pragma once

#include <utility>
#include <stack>
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



	bool HasLeftChildNode() { return (nullptr != this->mLeftNode); }
	bool HasRightChildNode() { return (nullptr != this->mRightNode); }
	bool HasData() { return (nullptr != this->mData); }

	const T* GetData() { return mData; }
	const BinaryTreeNode* GetLeftChildNodeConst() { return this->mLeftNode; }
	const BinaryTreeNode* GetRightChildNodeConst() { return this->mRightNode; }

	BinaryTreeNode* GetLeftChildNode() { return this->mLeftNode; }
	BinaryTreeNode* GetRightChildNode() { return this->mRightNode; }

	BinaryTreeNode* InsertLeft(T data) { this->mLeftNode = new BinaryTreeNode(data); return this->mLeftNode; }
	BinaryTreeNode* InsertRight(T data) { this->mRightNode = new BinaryTreeNode(data); return this->mRightNode; }

	bool IsBalanced(const BinaryTreeNode* treeRoot);

private:
	// Data could be anything so making this a pointer
	T mData = NULL;
	BinaryTreeNode* mLeftNode = nullptr;
	BinaryTreeNode* mRightNode = nullptr;
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
