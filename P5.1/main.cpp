#include <iostream>

using namespace std;

int place_bits(int n,int m, int i, int j){
    if(i>j) return-1;
    int ones=~0;
    int left=ones<<(j+1);//11100000
    int right= ((1<<i)-1);//00000011
    int combined= left | right;

    int n_clear= n&combined;
    int m_clear= m<<i;
    return n_clear | m_clear;
}

int main()
{
    int a= place_bits(128, 5, 2, 4);
    cout << a << endl;
    return 0;
}
