#include <iostream>

using namespace std;

int next_max(int number){
    int temp=number;
    int leftmost_nontrailing_ones=0;
    int trailing_zeros=0;
    while((temp & 1)==0 && (temp!=0)){
        trailing_zeros++;
        temp>>=1;
    }
    while((temp & 1)==1){
        leftmost_nontrailing_ones++;
        temp>>=1;
    }
    cout<<trailing_zeros<<"  zeros"<<endl;
    cout<<leftmost_nontrailing_ones<<"  ones"<<endl;

    if(trailing_zeros+leftmost_nontrailing_ones==31 || trailing_zeros+leftmost_nontrailing_ones==0){
        return -1;
    }
    int position= leftmost_nontrailing_ones+trailing_zeros;
    number |= (1<<position);//flip right-most non trailing zero
    number &=~((1<< position) -1);//clear numbers after position
    number |= (1<<(leftmost_nontrailing_ones-1)) -1;
    return number;
}

int nextMin(int number){
    int temp=number;
    int trailing_zeros=0;
    int leftmost_nontrailing_ones=0;
    while((temp & 1)==0 && (temp!=0)){
        trailing_zeros++;
        temp>>=1;
    }
    while((temp & 1)==1){
        leftmost_nontrailing_ones++;
        temp>>=1;
    }
    cout<<trailing_zeros<<"  zeros"<<endl;
    cout<<leftmost_nontrailing_ones<<"  ones"<<endl;
    if(leftmost_nontrailing_ones + trailing_zeros==31 || leftmost_nontrailing_ones+trailing_zeros==0){
        return -1;
    }
    int position= leftmost_nontrailing_ones+trailing_zeros;
    int clear=((~0)<<(position+1));
    int cleared_number= number & clear;
    int mask= (1<< (leftmost_nontrailing_ones+1))-1;
    mask<<=(trailing_zeros-1);
    int final= cleared_number | mask;
    return final;
}

int main()
{
    cout << next_max(130) << endl;
    cout<< nextMin(6)<<endl;
    return 0;
}
