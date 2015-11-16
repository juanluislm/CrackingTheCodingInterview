#include <iostream>

using namespace std;

void hanoi(int n, int pos1, int pos2, int pos3){
    if(n==1){
        cout<<"Move disk "<<n<<" from tower "<<pos1<<" to tower "<<pos3<<endl;
    }else{
        hanoi(n-1,pos1, pos3, pos2);
        cout<<"Move disk "<<n<<" from tower "<<pos1<<" to tower "<<pos3<<endl;
        hanoi(n-1,pos2, pos1, pos3);
    }
}

struct Node{
    int data;
    Node* next;
};

class stacksolve{
    Node* head;
    public:
        stacksolve(){head=NULL;};
        bool isEmpty();
        void push(int i);
        int pop();
        void pushmany(int i);
        int size();
        void print();
        int top();
        void solvehanoi(int n, stacksolve s1, stacksolve s2, stacksolve s3);
};

int stacksolve::top(){
    return head->data;
}

bool stacksolve::isEmpty(){
    return head==NULL;
}

void stacksolve::push(int i){
    Node* temp= new Node;
    temp->data=i;
    temp->next=NULL;
    if(head!=NULL){
        temp->next=head;
        head=temp;
    }else{
        head=temp;
    }
   // delete temp;
}

int stacksolve::pop(){
    if(head==NULL){
        cout<<" Empty stack "<<endl;
        return -1;
    }
    int d= head->data;
    Node* temp= head;
    head= head->next;
    delete temp;
    return d;
}

void stacksolve::pushmany(int i){
    if(head!=NULL) return;
    for(int j=i; j>0; j--){
        push(j);
    }
}

int stacksolve::size(){
    if(head==NULL) return 0;
    Node* temp=head;
    int count=1;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

void stacksolve::print(){
    if(head==NULL) return;
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}

void stacksolve::solvehanoi(int n, stacksolve s1, stacksolve s2, stacksolve s3){
    if(n==0 || s1.isEmpty()) return;
    if(n==1){
        s3.push(s1.pop());

    }else{
        solvehanoi(n-1,s1,s3,s2);
       // cout<<"top of s2 "<<s2.top()<<endl;
        solvehanoi(n-1,s2,s1,s3);
        //cout<<"s3 "<<s3.top()<<endl;
    }
    //cout<<s3.top()<<endl;
}

int main()
{
    //hanoi(3,1,2,3);
    stacksolve s1;
    s1.pushmany(5);
    stacksolve s3;
    stacksolve s2;
    //s1.push(5);
    s1.print();
    //cout<<s1.pop()<<endl;
    //s1.print();
    s1.solvehanoi(1,s1,s2,s3);
    return 0;
}
//WTF??
