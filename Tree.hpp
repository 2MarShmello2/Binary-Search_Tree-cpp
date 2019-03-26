
#include <iostream>
using namespace std;

struct Node{
        Node(int value): data(value), left(NULL),right(NULL),parent(NULL) {}
        int data;
        Node *left;
        Node *right;
	Node *parent;
};
namespace ariel{

class Tree{

private:
	Node *_root ;
	int _size(Node *treeNode);
	void insert(Node *treeNode, int data);
	bool contains(Node *treeNode,int i);
	Node* deleteNode(Node *_root, int data);
	Node* minValueNode(Node *root);
	void deleteTree(Node *treeNode);
	int parent(Node *treeNode, int data);
	int left(Node* pRoot, int value);
	int right(Node* pRoot, int value);
	void print(Node *_root);
public:
	Tree();  // constructor     
	~Tree();
	void deleteTree() {deleteTree(_root);}
        void insert(int data){insert(_root, data);} 
 	void remove(int data){deleteNode(_root,data);};
	int size(){return _size(_root);};
	bool contains(int data){return contains(_root,data);};
	int  root();
	int parent(int data){return parent(_root, data);};
	int left(int data){return left(_root, data);};
	int right(int data){return right(_root, data);};
	void print(){print(_root);};
	

};
};



