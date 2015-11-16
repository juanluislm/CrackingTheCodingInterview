#include <iostream>

using namespace std;

int convert_bits(int m, int n){//number of bits you need to flip in order to make n=m
    int a =m ^ n;
    int count = 0;
    for (a; a != 0; a >>= 1)
       // if ((a & 1) == 1)
        count+=a&1;
    return count;
}

int main()
{
    cout << convert_bits(3,1) << endl;
    return 0;
}
