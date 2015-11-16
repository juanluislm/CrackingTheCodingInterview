#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int d, Node* n=NULL){ data=d; next=n;};
};

void remove_middle(Node* n){
    if(n==NULL || n->next==NULL) return;
        Node *temp = n->next;
        n -> data = temp -> data;
        n -> next = temp -> next;
        delete temp;
        temp = NULL;
}

int main()
{
  Node *n6 = new Node(11);
  Node *n5 = new Node(3, n6);
  Node *n4 = new Node(3, n5);
  Node *n3 = new Node(0, n4);
  Node *n2 = new Node(2, n3);
  Node *n1 = new Node(1, n2);
  Node *root = new Node(0, n1);
  remove_middle(n3);
  Node *n = root;
  while (n != NULL)
  {
    cout << n -> data << " -> ";
    n = n -> next;
  }
  cout << endl;
  return 0;
}
