#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* nextmin;
};

class Stackmin{
    Node* head;
    Node* min;
    public:
        Stackmin(){head=NULL; min=0;};
        void push(int i);
        int pop();
        int getMin();
        void print();
};

void Stackmin::push(int i){
    Node* temp= new Node;
    temp->data= i;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        min=temp;
    }else{
        temp->next=head;
        head= temp;
        if(min->data>head->data){
            head->nextmin= min;
            min=head;
        }
    }

}

int Stackmin::pop(){
    if(head==NULL) return -1;
    if(min==head){
        min= min->nextmin;
    }
    int d= head->data;
    Node* temp= head;
    head= head->next;
    delete temp;
    return d;
}

int Stackmin::getMin(){
    return min->data;
}

void Stackmin::print(){
    if(head==NULL) return;
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"  ->  ";
        temp= temp->next;
    }
    cout<<endl;
}

int main()
{
    Stackmin s;
    s.push(5);
    s.push(4);
    s.push(9);
    s.push(5);
    s.push(1);
    s.push(2);
    s.print();
    cout<<s.getMin();
    return 0;
}
