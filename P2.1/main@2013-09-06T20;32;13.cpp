#include <iostream>
#include <map>

using namespace std;

struct Node
{
  int value;
  Node *next;
  Node (int v = 0, Node *n = NULL){value = v; next = n;}
};

void remove_duplicates(Node *root)
{
  if (root == NULL)
    return;
  map<int, int> m;
  map<int, int>::iterator it;
  m.insert(pair<int, int>(root -> value, 0));
  while (root -> next != NULL)
  {
    if ((it = m.find(root -> next -> value)) != m.end())
    {
      Node *temp = root -> next;
      root -> next = temp -> next;
      delete temp;
      temp = NULL;
    }
    else
    {
      m.insert(pair<int, int>(root -> next -> value, 0));
      root = root -> next;
    }
  }
}

void remove(Node* root){
    if(root==NULL) return;
    Node* temp= root;
    while(temp!=NULL){
        Node* current= temp;
        while(current->next!=NULL){
            if(current->next->value==temp->value){
                current->next= current->next->next;
            }else{
                current=current->next;
            }
        }
        temp=temp->next;
    }
}

int main()
{
  Node *n6 = new Node(0);
  Node *n5 = new Node(3, n6);
  Node *n4 = new Node(3, n5);
  Node *n3 = new Node(0, n4);
  Node *n2 = new Node(2, n3);
  Node *n1 = new Node(1, n2);
  Node *root = new Node(0, n1);
  //remove_duplicates(root);
  remove(root);
  Node *n = root;
  while (n != NULL)
  {
    cout << n -> value << " -> ";
    n = n -> next;
  }
  cout << endl;
  return 0;
}
