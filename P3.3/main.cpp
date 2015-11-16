#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using std::vector;
using std::stack;

class SetofStacks{
    vector< stack<int> > set;
    int capacity;
    public:
        SetofStacks(){capacity=4;};
        void push(int i);
        void pop();
        int topof(int i);
        int popAt(int i);
        bool isEmpty(int i);
};

void SetofStacks::push(int i){
    if(set.size()>0){
        if(set[set.size()-1].size()<capacity){
            set[set.size()-1].push(i);//stack
        }else{//if we got to the limit
            stack<int> st;
            st.push(i);
            set.push_back(st);
        }
    }else{
        stack<int> st;
        st.push(i);
        set.push_back(st);
    }
}

void SetofStacks::pop(){
    if(set.size()>0){
        if(!set[set.size() -1].empty()){
            set[set.size()-1].pop();
            if(set[set.size()-1].empty()){
                set.pop_back();
            }
        }
    }
}

int SetofStacks::topof(int i){
    if(set[i-1].empty()){
        cout<<"Empty"<<endl;
        return -1;
    }
    return set[i-1].top();
}

int SetofStacks::popAt(int i){
    if(set[i-1].empty()){
        cout<<"Empty"<<endl;
        return -1;
    }
    int d= set[i-1].top();
    set[i-1].pop();
    return d;
}

bool SetofStacks::isEmpty(int i){
    return set[i-1].empty();
}

int main(){
    SetofStacks ss;
    ss.push(5);
    ss.push(8);
    ss.push(3);
    ss.push(5);
    ss.push(200);
//    while(!ss.isEmpty(1)){
//        cout<<ss.topof(1)<<"  ";
//        ss.popAt(1);
//    }
    return 0;
}
