#include <iostream>
#include <vector>
#include <string>
using namespace std;

void string_permutations(string s, int index, string str, vector <string> &result){
    if(index==s.size()){
        result.push_back(str);
        return;
    }
    for(size_t i=0; i<str.size(); ++i){
        string temp(str);
        temp.insert(i,s,index, 1);
        string_permutations(s,index+1, temp, result);
    }
    str+=s[index];
    string_permutations(s,index+1, str, result);
}// O(n!) time!! crap!!!!!! it can't be improved!!!

vector <string> strings_vector(string s){
    vector <string> result;
    string str;
    string_permutations(s,0,str, result);
    return result;
}

int main()
{
    string s= "asd";
    vector<string> res= strings_vector(s);
    for(size_t i=0; i<res.size(); ++i){
        cout<<res[i]<<endl;
    }
    return 0;
}
