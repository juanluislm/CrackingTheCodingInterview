#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int d, Node* r=NULL, Node* l=NULL){
        data=d;
        right=r;
        left=l;
    };
};

int depth(Node* root){
    if(root==NULL) return 0;
    else{
        return 1 + max(depth(root->left), depth(root->right));
    }
}

void print(int path[], int start, int end){
    for(int i=start;i<=end;i++)
        cout<<path[i]<<" ";
    cout<<endl;
}

void findpaths(Node* n, int sum, int path[], int level){
    if(n==NULL) return;
    path[level]=n->data;

    int t=0;
    for(int i=0; i>=0; i--){
        t+=path[i];
        if(t==sum) print(path, i, level);
    }

    findpaths(n->left, sum, path, level+1);
    findpaths(n->right, sum, path, level+1);
}

int main()
{
    Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	int path[depth(root)];
	findpaths(root, 7, path, 0);
	for(int i=0; i<5; i++)
	cout<<path[i]<<"  ";
    return 0;
}
