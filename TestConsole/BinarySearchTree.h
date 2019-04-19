#pragma once
#include <iostream>

#include "BinaryTreeNode.h"


void RunBinarySearchTreeTests()
{
	std::cout << "Testing tree balanced method functionality" << std::endl;

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


	std::cout << "Testing binary tree test function" << std::endl;

	root = new BinaryTreeNode<int>(50);
	root->InsertLeft(30)->InsertLeft(10);
	root->InsertRight(70)->InsertRight(80);
	root->GetLeftChildNode()->InsertRight(40);
	root->GetRightChildNode()->InsertLeft(60);
	std::cout << "IsBinarySearchTree(root): expected = true: " << (root->IsBinarySearchTree(root) ? "true" : "false") << std::endl;

	root = new BinaryTreeNode<int>(50);
	root->InsertLeft(30)->InsertLeft(20);
	root->InsertRight(80)->InsertRight(90);
	root->GetLeftChildNode()->InsertRight(60);
	root->GetRightChildNode()->InsertLeft(70);
	std::cout << "IsBinarySearchTree(root): expected = false: " << (root->IsBinarySearchTree(root) ? "true" : "false") << std::endl;

	root = new BinaryTreeNode<int>(50);
	root->InsertLeft(40)->InsertLeft(30)->InsertLeft(20)->InsertLeft(10);
	std::cout << "IsBinarySearchTree(root): expected = true: " << (root->IsBinarySearchTree(root) ? "true" : "false") << std::endl;

	root = new BinaryTreeNode<int>(50);
	root->InsertRight(70)->InsertRight(60)->InsertRight(80);
	std::cout << "IsBinarySearchTree(root): expected = false: " << (root->IsBinarySearchTree(root) ? "true" : "false") << std::endl;

	root = new BinaryTreeNode<int>(50);
	std::cout << "IsBinarySearchTree(root): expected = true: " << (root->IsBinarySearchTree(root) ? "true" : "false") << std::endl;


	auto stringRoot = new BinaryTreeNode<std::string>("A");
	stringRoot->InsertLeft("B")->InsertLeft("C");
	stringRoot->GetLeftChildNode()->InsertRight("D");
	stringRoot->InsertRight("E")->InsertLeft("F");
	stringRoot->GetRightChildNode()->InsertRight("G");

	std::cout << "Dept first visit: " << std::endl;
	stringRoot->DepthFirstRecursive(stringRoot);

	std::cout << "Breadth first visit " << std::endl;
	stringRoot->BreadthFirstRecursive(stringRoot);


}