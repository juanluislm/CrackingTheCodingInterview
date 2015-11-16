#include <iostream>
#include <string>
#include <vector>

using namespace std;

void combine_parentheses(int left, int right, string s, vector<string> &result){
    //if(right<0 || left<0) throw;
    if(left==0 && right ==0){
        result.push_back(s);
        return;
    }
    if(left>0){
        combine_parentheses(left-1, right, s+ '(', result);
    }
    if(right>left){
        combine_parentheses(left, right-1, s+')', result);
    }
}

vector <string> combinations(int n){
    vector<string> result;
    string s;
    combine_parentheses(n,n,s,result);
    return result;
}

int main()
{
    int n=3;
    vector<string> result= combinations(n);
    for(size_t i=0; i<result.size(); ++i){
        cout<<result[i]<<endl;
    }
    cout<<"Total combinations: "<<result.size()<<endl;
    return 0;
}
