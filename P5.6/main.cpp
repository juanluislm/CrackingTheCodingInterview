#include <iostream>

using namespace std;

int swap_even_odd(int x){
    return(((x & 0xaaaaaaaa)>>1) | (  (x & 0x55555555)<<1));
}

int main()
{
    cout << swap_even_odd(3) << endl;
    return 0;
}
