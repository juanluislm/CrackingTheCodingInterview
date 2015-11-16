#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

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

int height(Node* root){
    if(root==NULL) return 0;
    int hl= height(root->left);
    int hr= height(root->right);
    return max(hl,hr)+1;
}

bool isBalanced(Node* root){
    if(root==NULL) return true;
    int hl= height(root->left);
    int hr= height(root->right);
    int dif= hl-hr;
    return(abs(dif)<=1);
}

int checkHeight(Node* root){
    if(root==NULL) return 0;
    int leftHeight= checkHeight(root->left);
    if(leftHeight==-1) return -1;

    int rightHeight= checkHeight(root->right);
    if(rightHeight==-1) return -1;

    int dif= abs(leftHeight-rightHeight);
    if(dif>1) return -1;
    else return max(leftHeight, rightHeight) +1;
}

bool is_balanced(Node* root){
    if(checkHeight(root)==-1) return false;
    else return true;
    //O(n) time O(log n) space
}

int main()
{
    Node *root = new Node(0);
    Node *l1 = new Node(1);
    Node *r1 = new Node(2);
    Node *l2 = new Node(3);
    Node *r2 = new Node(4);
    Node *l3 = new Node(5);
    Node *r3 = new Node(6);
    Node *l4 = new Node(7);
    root -> left = l1;
    root -> right = r1;
    l1 -> left = l2;
    //l1 -> right = r2;
    r1 -> left = l3;
    r1 -> right = r3;
    l2 -> right = r2;
    r2 -> left = l4;
    //cout<<isBalanced(root)<<endl;
    cout<<is_balanced(root)<<endl;
    return 0;
}
