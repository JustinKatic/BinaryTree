/*----------------------------------------
Author: Richard Stern
Description: A simple binary search tree
Date: 17/4/2015
----------------------------------------*/
#include "BinaryTree.h"
#include "TreeNode.h"
#include "raylib.h"
#include <iostream>
#include <cstdlib>
using namespace std;


BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}

BinaryTree::~BinaryTree()
{
	//while (m_pRoot)
	//{
	//	Remove(m_pRoot->GetData());
	//}
}

// Return whether the tree is empty
bool BinaryTree::IsEmpty() const
{
	return (m_pRoot == nullptr);
}

// Insert a new element into the tree.
// Smaller elements are placed to the left, larger onces are placed to the right.
void BinaryTree::Insert(int a_nValue)
{
	TreeNode* newNode = new TreeNode(a_nValue);
	TreeNode* currentNode = m_pRoot;
	if (IsEmpty() == true)
	{
		m_pRoot = newNode;
		return;
	}
	while (currentNode != nullptr)
	{
		if (a_nValue < currentNode->GetData())
		{
			if (!currentNode->HasLeft())
			{
				break;
			}
			currentNode = currentNode->GetLeft();
		}
		else if (a_nValue > currentNode->GetData())
		{
			if (!currentNode->HasRight())
			{
				break;
			}
			currentNode = currentNode->GetRight();
		}
		else if (a_nValue == currentNode->GetData())
		{
			cout << "Number already exists in list " << endl;
			return;
		}
	}
	if (a_nValue < currentNode->GetData())
	{
		currentNode->SetLeft(newNode);
	}
	else
	{
		currentNode->SetRight(newNode);
	}
}

TreeNode* BinaryTree::Find(int a_nValue)
{
	TreeNode* pCurrent = nullptr;
	TreeNode* pParent = m_pRoot;

	return FindNode(a_nValue, pCurrent, pParent) ? pCurrent : nullptr;
}

bool BinaryTree::FindNode(int a_nSearchValue, TreeNode*& ppOutNode, TreeNode*& ppOutParent)
{
	TreeNode* currentNode = ppOutParent;
	TreeNode* currentParent = nullptr;
	while (currentNode != nullptr)
	{
		if (a_nSearchValue == currentNode->GetData())
		{
			ppOutNode = currentNode;
			ppOutParent = currentParent;
			return true;
		}
		else if (a_nSearchValue < currentNode->GetData())
		{
			currentParent = currentNode;
			if (currentNode->HasLeft() == true)
			{
				currentNode = currentNode->GetLeft();
			}
			else
			{
				break;
			}
		}
		else if (a_nSearchValue > currentNode->GetData())
		{
			currentParent = currentNode;
			if (currentNode->HasRight() == true)
			{
				currentNode = currentNode->GetRight();
			}
			else
			{
				break;
			}
		}

	}

	return false;
}

void BinaryTree::Remove(int a_nValue)
{
	currentNode = nullptr;
	TreeNode* tempNode;
	currentParent = m_pRoot;
	FindNode(a_nValue, currentNode, currentParent);
	if (currentNode->HasRight())
	{
		tempNode = currentNode;
		while (tempNode->HasLeft())
		{
			tempNode = tempNode->GetLeft();
		}
		currentNode = tempNode;
		currentParent = tempNode;

	}

}

void BinaryTree::PrintOrdered()
{
	PrintOrderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintOrderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::PrintUnordered()
{
	PrintUnorderedRecurse(m_pRoot);
	cout << endl;
}

void BinaryTree::PrintUnorderedRecurse(TreeNode* pNode)
{

}

void BinaryTree::Draw(TreeNode* selected)
{
	Draw(m_pRoot, 400, 40, 400, selected);
}

void BinaryTree::Draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected)
{

	horizontalSpacing /= 2;

	if (pNode)
	{
		if (pNode->HasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);

			Draw(pNode->GetLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		if (pNode->HasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);

			Draw(pNode->GetRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}

		pNode->Draw(x, y, (selected == pNode));
	}
}