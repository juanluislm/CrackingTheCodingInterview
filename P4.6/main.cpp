#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
    Node* parent;
    Node(int d, Node* r=NULL, Node* l=NULL, Node* p=NULL){
        data=d;
        right=r;
        left=l;
        parent=p;
    };
};

Node* succesor(Node* n){
    if(n->right!=NULL){
        Node* current= n;
        while(current!=NULL){
            current=current->left;
        }
        return current;
    }else{
        Node* current= n->parent;
        if(current->left==n){
            return current;
        }else{
            current= current->parent;
            while((current->parent!=NULL) && (current->parent->left!=current)){
                current= current->parent;
            }
            return current;
        }
    }
}

int main()
{
    Node* n1= new Node(1);
    Node* n2= new Node(2,n1);
    n1->parent=n2;
    Node* n4= new Node(4);
    Node* n3= new Node(3,n2,n4);
    n2->parent=n3;
    n4->parent=n4;
    Node* n6= new Node(6);
    Node* n9= new Node(9);
    Node* n8= new Node(8,n6,n9);
    Node* root= new Node(5,n3,n8);
    n8->parent=root;
    n3->parent=root;
    n6->parent= n8;
    n9->parent=n8;
    Node* nextt= succesor(n1);
    cout<<nextt->data<<endl;
    return 0;
}
