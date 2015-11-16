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

bool match(Node* t1, Node* t2){
    if(t1==NULL || t2==NULL) return true;
    if(t1->data!= t2->data) return false;//if both of these are not satisfied, keep digging... if you traverse them till the end without interruptions, you got it
    return( match(t1->left, t2->left) && match(t1->right, t2->right));
}

bool subtree(Node* t1, Node* t2){
    if(t1==NULL) return false;
    if(t1->data== t2->data){
        if (match(t1,t2)) return true;
    }
    return(subtree(t1->left, t2) || subtree(t1->right, t2));
}

bool isSubtree(Node* t1, Node* t2){
    if(t2==NULL) return true;
    return subtree(t1,t2);
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
    Node* n21= new Node(1);
    Node* root2= new Node(3,n1);
    if(isSubtree(root,root2))
    cout << "Hello world!" << endl;
    else cout<<"nope"<<endl;
    return 0;
}
