#include <iostream>

using namespace std;

struct Node{
    int value;
    Node *next;
    Node (int v = 0, Node *n = NULL){value = v; next = n;}
};

Node *add_linked_list(Node *f, Node *s, int &carry)
{
  if (f == NULL && s == NULL)
    return NULL;
  Node *head = new Node;
  int num = 0;
  if (f != NULL)
  {
    num += f -> value;
    f = f -> next;
  }
  if (s != NULL)
  {
    num += s -> value;
    s = s -> next;
  }
  head -> next = add_linked_list(f, s, carry);
  num += carry;
  head -> value = num % 10;
  carry = num / 10;
  return head;
}

void padding_zeroes(Node *&f, Node *&s){
    int c1 = 0, c2 = 0;
    Node *f1 = f;
    Node *s1 = s;
    while (f1 != NULL){
        f1 = f1 -> next;
        ++c1;
    }
    while (s1 != NULL){
        s1 = s1 -> next;
        ++c2;
    }
    if (c1 > c2){
        for (int i = 0; i < c1 - c2; ++i){
            Node *temp = new Node(0);
            temp -> next = s;
            s = temp;
        }
    }else if (c2 > c1){
        for (int i = 0; i < c2 - c1; ++i){
            Node *temp = new Node(0);
            temp -> next = f;
            f = temp;
        }
    }
}

Node *handle_head(Node *f, Node *s){
    if (f == NULL && s == NULL)
        return NULL;
    padding_zeroes(f, s);
    int carry = 0;
    Node *head = add_linked_list(f, s, carry);
    if (carry == 1){
        Node *temp = new Node;
        temp -> value = 1;
        temp -> next = head;
        head = temp;
    }
    return head;
}

void print(Node* root){
    if(root==NULL) return;
    Node* temp=root;
    while(temp!=NULL){
        cout<<temp->value<<"  -> ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
    {
    Node *f1 = new Node(7);
    Node *f2 = new Node(1);
    Node *f3 = new Node(6);
    //Node *f4 = new Node(10);
    f1 -> next = f2;
    f2 -> next = f3;
    //f3 -> next = f4;
    Node *s1 = new Node(5);
    Node *s2 = new Node(9);
    Node *s3 = new Node(2);
    s1 -> next = s2;
    s2 -> next = s3;

   // Node* final= addLists(f1,s1,0);
   // print(final);
   print(f1);
    Node* final2= handle_head(s1,f1);
    print(final2);
    return 0;
}
