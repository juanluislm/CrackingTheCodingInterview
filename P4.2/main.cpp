#include <iostream>
#include <malloc.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class stack{
    private:
        Node* top;
    public:
        stack();
        void push(int a);
        int pop();
        bool empty();
        void Print();
};

stack::stack(){top=NULL;}

void stack::push(int a){
    Node *temp;
    if((temp=(Node*)malloc(sizeof(Node)))==NULL){
        cout<<"Memory Exhausted";
        exit(0);
    }
    temp = new Node;
    temp->data= a;
    temp->next= NULL;
    if(top!=NULL){
        temp->next=top;
    }
    top=temp;
};

int stack::pop(){
    if(top==NULL) return -1;
    Node* temp= new Node();
    temp= top;
    int value= temp->data;
    top= top->next;
    delete temp;
    return value;
}

bool stack::empty(){
    return top==NULL;
}

void stack::Print(){
    if(top==NULL) return;
    Node* temp= top;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp= temp->next;
    }
    cout<<endl;
    delete temp;
}

class graph{
    int mat**;
    int vertices;
    public:
        graph(int v);
        bool isConnected(int u, int v);
        void addEdge(int u, int v);
        void DFS(int a, int req);
};

graph::graph(int v){
    vertices=v;
    mat= new int*[v];
    for(int i=0; i<v; i++){
        mat[i]= new int[v];
    }
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            mat[i][j]=0;
        }
    }
};

bool graph::isConnected(int u, int v){
    return mat[u-1][v-1]==1;
}

void graph::addEdge(int u, int v){
    mat[u-1][v-1]=mat[v-1][u-1]=1;
}

void graph::DFS(int a, int req){
    stack s;
    bool* visited= new bool[vertices+1];
    for(int i=0; i<vertices+1; i++){
        visited[i]=false;
    }
    s.push(a);
    visited[a]= true;
    if(a==req) return;
    cout<<"DFS starting at "<<a<<endl;
    while(!s.empty()){
        int k= s.pop();
        if(k==req) break;
        cout<<k<<"  ";
        for(int i=vertices; i>=0; i--){
            if(isConnected(k,i) && !visited[i]){
                s.push(i);
                visited[i]=true;
            }
        }
    }
    cout<<endl;
    delete [] visited;
}

int main(){
    graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 4);
    g.DFS(4,2);
    return 0;
}
