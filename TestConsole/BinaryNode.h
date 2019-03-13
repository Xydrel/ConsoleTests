#pragma once

template<typename T>
class BinaryNode
{
public:
	// Allowing the default Ctor for tutorial purposes
	BinaryNode() { ; }
	~BinaryNode() 
	{
		if (nullptr != Data)
		{
			delete Data;
			Data = nullptr;
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
	BinaryNode(const BinaryNode& node) = delete;
	// Primary Ctor with init requirement
	/*BinaryNode(T& data, BinaryNode& lhNode, BinaryNode& rhNode) :
		Data(data),
		mLeftNode(lhNode),
		mRightNode(rhNode)
	{}*/

	BinaryNode* InitNewNode(T& data)
	{
		if (nullptr != nullptr)
		{
			BinaryNode* newNode = new BinaryNode();
			newNode->Data = data;
			newNode->mLeftNode = nullptr;
			newNode->mRightNode = nullptr;
		}
		return newNode;
	}

	// insert of new data
	void Insert(BinaryNode* root, T data);

	// jth:todo: sorting
		// 

	// jth:todo: removal

	// jth:todo traversal
		// traversal would be in the tree implementation?

	bool HasLeftChildNode() { return (nullptr != this->mLeftNode); }
	bool HasRightChildNode() { return (nullptr != this->mRightNode); }
	bool HasData() { return (nullptr != this->Data); }

	const T* GetData() { return Data; }
	const BinaryNode* GetLeftChildNode() { return this->mLeftNode; }
	const BinaryNode* GetRightChildNode() { return this->mRightNode; }

private:
	// Data could be anything so making this a pointer
	T Data = NULL;
	BinaryNode* mLeftNode = nullptr;
	BinaryNode* mRightNode = nullptr;
};
