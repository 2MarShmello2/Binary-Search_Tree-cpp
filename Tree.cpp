
//source code : https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

#include <iostream>
#include "Tree.hpp"
using namespace std;





namespace ariel{
Tree::Tree()
{  
_root = NULL;   
}
void Tree::insert(Node *treeNode,int data)
{ 
   if(contains(treeNode,data)){throw std::invalid_argument( "number is already exist" );return;}
     if (treeNode == NULL)
        {
                Node *treeNode = new Node(data);           
                _root = treeNode;           
        }
        else
        {
                if (data < treeNode->data)
                {
                        if (!treeNode->left)
                        {
                                Node *treeTemp = new Node(data);
                                treeNode->left = treeTemp;
                        }
                        else
                                insert(treeNode->left, data);
                }
                else
                {
                        if (!treeNode->right)
                        {
                                Node *treeTemp = new Node(data);                         
                                treeNode->right = treeTemp;
                        }
                        else
                                insert(treeNode->right, data);
                }
        }
}
Node * Tree::minValueNode(Node *root) 
{ 
    Node *current = root; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
Node * Tree::deleteNode(Node *root, int key){
if(!contains(root,key)){throw std::invalid_argument( "number is not exist" );return NULL;}
// base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            Node *temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            Node *temp = root->left;
            delete root; 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node *temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
}

int Tree::_size(Node *treeNode){
	
	if(treeNode==NULL || treeNode->data == 0){
		return 0 ;
}
	else 
		return 1+_size(treeNode->left)+_size(treeNode->right);
}
bool Tree::contains(Node *treeNode,int data){
  if (treeNode == NULL) return false;
  else {
    if (data == treeNode->data)
        return true;
    else if (data < treeNode->data)
             return contains(treeNode->left, data);      
    else if (data > treeNode->data)
             return contains(treeNode->right, data);
    else
    	return false;	
  }

	
}
void Tree::deleteTree(Node *treeNode) 
{
        if (!treeNode)
                return;

        Node * curTreeNode = treeNode;
        Node * leftTreeNode = treeNode->left;
        Node * rightTreeNode = treeNode->right;
        delete curTreeNode;
        deleteTree(leftTreeNode);
        deleteTree(rightTreeNode);
}
Tree::~Tree()
{
        deleteTree(_root);
}
int Tree::root(){
return _root->data;
}

int Tree::parent(Node* pRoot, int value)
{
    if(pRoot->left == NULL && pRoot->right == NULL)
       return -1;
    int currentVal = pRoot->data;	
    if( (pRoot->left != NULL && pRoot->left->data == value)
        || (pRoot->right != NULL && pRoot->right->data == value))
       return pRoot->data;

    if(pRoot->data > value)
       return parent(pRoot->left,value);

    if(pRoot->data < value)
       return parent(pRoot->right,value);
    return currentVal;
}



int Tree::left(Node* pRoot, int value){
   if(!contains(pRoot,value)){throw std::invalid_argument( "number is not exist" );return -1;}
    if(pRoot->left == NULL && pRoot->right == NULL)
       return -1;
   int currentVal = pRoot->data;
    if(pRoot->left != NULL && pRoot->data == value)
       return pRoot->left->data;

    if(pRoot->data > value)
       return parent(pRoot->left,value);

    if(pRoot->data < value)
       return parent(pRoot->right,value);
 return currentVal;
}

int Tree::right(Node* pRoot, int value){
 if(pRoot->left == NULL && pRoot->right == NULL)
       return -1;
int currentVal = pRoot->data;
    if(pRoot->right != NULL && pRoot->data == value)
       return pRoot->right->data;

    if(pRoot->data > value)
       return parent(pRoot->left,value);

    if(pRoot->data < value)
       return parent(pRoot->right,value);
 return currentVal;
}
void Tree::print(Node *_root){
   if (_root != NULL) {   
      print(_root->left);
      cout<<_root->data<<" ";
      print(_root->right);
   }
 
}
};




