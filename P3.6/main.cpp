#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class stack{
    Node* head;
    public:
        stack(){head=NULL;};
        int top(){ return head->data;};
        int pop();
        bool isEmpty(){ return head==NULL;};
        void push(int i);
        void print();
};

int stack::pop(){
    if(head==NULL) {
        cout<<"Empty stack"<<endl;
        throw;
    }
    int d= head->data;
    Node* temp= head;
    head= head->next;
    delete temp;
    return d;
}

void stack::push(int i){
    Node* temp= new Node;
    temp->data= i;
    temp->next= NULL;
    if(head==NULL){
        head=temp;
    }else{
        temp->next=head;
        head=temp;
    }
}

stack sortStack(stack s1){
    if(s1.isEmpty()) throw;
    stack s2;
    while(!s1.isEmpty()){
        int min= s1.pop();
        while(!s2.isEmpty() && min<s2.top()){
            s1.push(s2.pop());
        }
        s2.push(min);
    }
    return s2;
}

void stack::print(){
    if(head==NULL) return;
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    stack s1;
    s1.push(7);
    s1.push(10);
    s1.push(5);
    s1.push(9);
    s1.print();
    stack s2= sortStack(s1);
    s2.print();
    return 0;
}
