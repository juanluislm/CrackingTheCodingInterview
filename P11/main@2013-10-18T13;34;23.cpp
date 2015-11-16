#include <iostream>

using namespace std;

void mergeSort(int a[], int b[], int lasta, int lastb){
    int lpos=lasta-1;
    int posb= lastb-1;
    int totalpos= lasta+lastb-1;
    while(lpos>=0 && posb>=0){
        if(a[lpos]> b[posb]){
            a[totalpos --] = a[lpos --];
        }else{
            b[totalpos --] = b[posb--];
        }
    }
    while(posb >= 0){
        a[totalpos -- ] = b[posb --];
    }
}

int main()
{
    int a[10]={2,4,5,7};
    int b[4]= {1,5,6,8};
    mergeSort(a,b,4,4);
    for(int i=0; i<10; i++) cout<<a[i]<<"  ";
    cout<<endl;
    return 0;
}
