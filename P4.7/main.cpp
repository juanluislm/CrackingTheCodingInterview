#include <iostream>

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

bool is_ancestor(Node* upper, Node* lower){
    if(upper==NULL) return false;
    if(upper==lower) return true;
    return is_ancestor(upper->left,lower) || is_ancestor(upper->right,lower);//return true even if they are the same
}

Node* commonAncestor(Node* root, Node* n1, Node* n2){
    if(root==NULL) return NULL;
    if(!is_ancestor(root,n1) || !is_ancestor(root, n2)) return NULL;
    if(root==n1 || root== n2) return root;
    bool is_n1_ontheleft= is_ancestor(root->left,n1);
    bool is_n2_ontheleft= is_ancestor(root->left, n2);
    if(is_n1_ontheleft!=is_n2_ontheleft) return root;//if they are on different sides, return true. If they are in the same side, traverse it
    Node* child_side= is_n1_ontheleft? root->left:root->right;
    return commonAncestor(child_side, n1,n2);//traverse
}

int main()
{
    Node* n1= new Node(1);
    Node* n2= new Node(2,n1);
    Node* n4= new Node(4);
    Node* n3= new Node(3,n2,n4);
    Node* n6= new Node(6);
    Node* n9= new Node(9);
    Node* n8= new Node(8,n6,n9);
    Node* root= new Node(5,n3,n8);
    Node* ancestor= commonAncestor(root, n1,n4);
    cout<<ancestor->data<<endl;
    return 0;
}
