#include <iostream>

using namespace std;

string represent(double number){
    string message="Not able to compute";
    if(number>=1 || number<=0) return NULL;
    string s="0.";
    int count=0;
    while(number!=0){
        number*=2;
        if(number>=1){
            s+="1";
            number--;
        }else{
            s+="0";
        }
        count++;
        if(count==32) return message;
    }
    return s;
}

int main()
{
    cout << represent(0.5)<< endl;
    return 0;
}
