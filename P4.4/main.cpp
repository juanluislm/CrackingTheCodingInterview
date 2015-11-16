#include <iostream>
#include <vector>
#include <list>
using namespace std;
using std::vector;
using std::list;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* l=NULL, Node* r=NULL){
        data=d;
        left=l;
        right=r;
    }
};

Node* MakeSearchTree(int* begin, int* end){
	if(begin==end){
		Node* node = new Node(*begin);
		return node;
	}
	if(begin<end){
		int* mid = begin + (end-begin)/2;
		Node* node = new Node(*mid);
		if((mid-1)>=begin){
			node->left = MakeSearchTree(begin,mid-1);
		}
		if((mid+1)<=end){
			node->right = MakeSearchTree(mid+1,end);
		}
		return node;
	}
}

void GenerateLists(vector< list<int> > &lists, Node* node,int layer){
	if(lists.size()<=layer){
		list<int> list;
		lists.push_back(list);
		lists[layer].push_back(node->data);
	}else{
		lists[layer].push_back(node->data);
	}
	if(node->left!=NULL){
		GenerateLists(lists, node->left, layer+1);
	}
	if(node->right!=NULL){
		GenerateLists(lists, node->right, layer+1);
	}
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
