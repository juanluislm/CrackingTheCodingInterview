#define LOWER_CASE
#ifdef LOWER_CASE
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

void count_ways(int a[], int n, int sum, int target, vector <int> t, vector <vector <int> > &path, int start=0){
    if(sum==target){
        path.push_back(t);
        return;
    }
    if(sum > target) return;
	for(int i=start;i<n;i++){
		t.push_back(a[i]);
		sum += a[i];
		count_ways(a,n,sum,target,t,path,i);
		sum -= a[i];
		t.pop_back();
	}
}

int main(){
	int a[3] = {1,2,3};
	int sum = 0;
	int target = 3;
	vector<vector<int> > path;
	vector<int> t;
	count_ways(a,3,sum,target,t,path);

	for(size_t i=0;i<path.size();i++){
		std::copy(path[i].begin(),path[i].end(),std::ostream_iterator<int>(std::cout," "));
		std::cout<<std::endl;
	}

	return 0;
}
#endif
