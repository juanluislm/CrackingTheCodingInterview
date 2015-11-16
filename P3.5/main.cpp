#include <iostream>

using namespace std;

struct Node{
    Node* next;
    int data;
};

class stack{
    Node* head;
    public:
        stack(){head=NULL;};
        int top();
        int pop();
        bool isEmpty();
        void push(int i);
};

int stack::top(){ return head->data;};

int stack::pop(){
    if(head==NULL){
        cout<<"Empty stack"<<endl;
        return -1;
    }
    int d= head->data;
    Node* temp= head;
    head= head->next;
    delete temp;
    return d;
}

bool stack::isEmpty(){ return head==NULL;};

void stack::push(int i){
    Node* temp= new Node;
    temp->data= i;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }else{
        temp->next=head;
        head=temp;
    }
}

class myq{
    stack s1, s2;
    public:
        myq(){ };
        void enqueue(int i);
        int top();
        int dequeue();
};

void shift(stack s1, stack s2){
    while(!s1.isEmpty()) s2.push(s1.pop());
}

void myq::enqueue(int i){
    s1.push(i);
}

int myq::top(){
    shift(s1,s2);
    return s2.top();
}

int myq::dequeue(){
    shift(s1,s2);
    return s2.pop();
}

int main()
{
    myq q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.top()<<endl;
    return 0;
}
