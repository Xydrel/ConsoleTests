#pragma once
#include <iostream>

#include "BinaryTreeNode.h"


void RunBinarySearchTreeTests()
{
	auto root = new BinaryTreeNode<int>(5);
	root->InsertLeft(8)->InsertLeft(1);
	root->InsertRight(6)->InsertRight(4);
	root->GetLeftChildNode()->InsertRight(2);
	root->GetRightChildNode()->InsertLeft(3);
	std::cout << "IsBalanced(root): expected = true: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;

	root = new BinaryTreeNode<int>(6);
	root->InsertLeft(1);
	root->InsertRight(0)->InsertRight(7)->InsertRight(8);
	std::cout << "IsBalanced(root): expected = false: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;

	root = new BinaryTreeNode<int>(3);
	root->InsertLeft(4)->InsertLeft(1);
	root->InsertRight(2)->InsertRight(9);
	std::cout << "IsBalanced(root): expected = true: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;
	
	root = new BinaryTreeNode<int>(6);
	root->InsertLeft(1);
	root->InsertRight(0)->InsertRight(7);
	std::cout << "IsBalanced(root): expected = true: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;
			
	root = new BinaryTreeNode<int>(1);
	root->InsertLeft(5);
	root->InsertRight(9)->InsertRight(5);
	root->GetRightChildNode()->InsertLeft(8);
	std::cout << "IsBalanced(root): expected = true: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;
	
	root = new BinaryTreeNode<int>(1);
	root->InsertLeft(5);
	root->InsertRight(9)->InsertRight(5);
	root->GetRightChildNode()->InsertLeft(8)->InsertLeft(7);
	std::cout << "IsBalanced(root): expected = false: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;
	
	root = new BinaryTreeNode<int>(1);
	std::cout << "IsBalanced(root): expected = true: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;
	
	root = new BinaryTreeNode<int>(1);
	root->InsertRight(2)->InsertRight(3)->InsertRight(4);
	std::cout << "IsBalanced(root): expected = true: " << (root->IsBalanced(root) ? "true" : "false") << std::endl;
}