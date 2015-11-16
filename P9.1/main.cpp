#include <iostream>

using namespace std;

int count_ways(int n){
    if(n<0) return -1;
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    int a=1;
    int b=2;
    int c=4;
    int i=4;
    int d;
    while(i<=n){
        d= a+b+c;
        a=b;
        b=c;
        c=d;
        i++;
    }
    return d;
}

int main()
{
    cout << count_ways(4) << endl;
    return 0;
}
