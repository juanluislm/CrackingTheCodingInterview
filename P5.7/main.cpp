#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using std::vector;

int fetch_bit(int n, int j){
    if (j >= sizeof(int) * 8)
        return -1;
    else
        return (n >> j & 1);
}

int length(int i){
    int count=0;
    while(i>0){
        ++count;
        i/=2;
    }
    return count;
}

int search_by_bit(vector<int> v, int l, int pos){
    if(pos>l) return 0;
    vector<int> v0;
    vector<int> v1;
    for(size_t j=0; j<v.size(); ++j){
        if(v[j]>>pos & 1){
            v1.push_back(v[j]);
        }else{
            v0.push_back(v[j]);
        }
    }
    if(v0.size() > v1.size()){
        int result= search_by_bit(v1,l,pos +1);
        return result << 1 | 1;
    }else{
        int result = search_by_bit(v0, l, pos + 1);
        return result << 1| 0;
    }
}

int find_missing(vector<int> v){
    int l= length(v.size() -1);
    int result= search_by_bit(v,l,0);
    return result;
}

int main(){
    int arr[] = {1, 4, 3, 9, 2, 6, 5, 7, 0};
    vector<int> v(arr, arr + 0);
    cout<< find_missing(v)<<endl;
    return 0;
}
