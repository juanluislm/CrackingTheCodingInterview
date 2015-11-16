#include <iostream>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int d, Node* l=NULL, Node* r=NULL){
        data=d;
        right= r;
        left= l;
    };
};

Node* to_BST(int arr[], int start, int end){
    if(start>end) return NULL;
    int middle= (start+end)/2;
    Node* root= new Node(arr[middle]);
    root->left=to_BST(arr,start, middle-1);
    root->right=to_BST(arr,middle+1, end);
    return root;
}

void printTree(string space, Node* node){
    space+=" ";
    cout<<space<<node->data<<endl;
    if(node->left!=NULL){
        printTree(space, node->left);
    }
    if(node->right!=NULL){
        printTree(space, node->right);
    }
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    Node* root= to_BST(a,0,9);
    printTree("", root);
    return 0;
}
