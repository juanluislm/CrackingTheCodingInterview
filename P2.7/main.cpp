#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
}

class List{
    Node* head;
    public:
        List(){head=NULL;};
        bool isEmpty(){ return head==NULL;};
        void push_(int i);
        bool isPalindrome();};

void List::push_(int i){
    Node* temp= new Node;
    temp->data= i;
    temp->next=NULL;
    if(head!=NULL){
        Node* temp2= head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next= temp;
        temp2->next->data= temp->data;
    }
    if(head==NULL){
        head=temp;
    }
}

bool List::isPalindrome(){
    List l2= new List();
    Node* temp= head;
    while(temp!=NULL){
        l2.push_(temp->data);
        temp=temp->next;
    }
    delete temp;
    Node* helper1=head;
    Node* helper2= l2.head;
    while(helper1!=NULL){
        if(helper1->data != helper2->data) {
            cout<<"Not a palindrome"<<endl;
            return false;
        }
    }
    return true
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
