#include <iostream>
#include <queue>
using namespace std;
using std::queue;
struct Node{
    int left_size;
    Node* left;
    Node* right;
    int data;
    Node(int d){data=d; left_size=0; left=NULL; right=NULL;};
};

class bstRank{
    private:
        Node* head;
    public:
        bstRank(){head==NULL;}
        void track(int x);
        int Rank(int x);
};

void insert(Node* root, int d){
    if(d<=root->data){
        if(root->left!=NULL) insert(root->left, d);
        else{
            root->left= new Node(d);
            root->left_size++;
        }
    }else{
        if(root->right!=NULL) insert(root->right, d);
        else{
            root->right= new Node(d);
        }
    }
}

void bstRank::track(int x){
    if(head==NULL){
        head=new Node(x);
    }else{
        insert(head, x);
    }
}

int getRank(Node* root, int d){
    if(d==root->data) return root->left_size;
    else if(d< root->data){
        if(root->left==NULL) return -1;
        else return getRank(root->left, d);
    }else{
        int right_rank;
        if(root->right==NULL) return -1;
        else right_rank= getRank(root->right, d);
        return root->left_size + 1 + right_rank;
    }
}

int bstRank::Rank(int x){
    return getRank(head, x);
}

int main()
{
    //bstRank bst;
    //bst.track(5);
    queue<int> q;
    q.push(5);
    q.push(4);
    if(q.front()==5) cout<<"works";
    return 0;
}
