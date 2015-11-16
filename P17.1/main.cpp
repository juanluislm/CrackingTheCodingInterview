#include <iostream>

using namespace std;

void swap_inplace(int x, int y){//x=3, y=8
    x=y-x;//x=5
    y=y-x;//y=3
    x+=y;//x=8
    cout<<"After: "<<x<<"  "<<y<<endl;
}

int main()
{
    int x=3;
    int y=8;
    cout<<"Before: "<<x<< "   "<<y<<endl;
    swap_inplace(x,y);
    //cout <<"After: "<<x<<"    "<<y << endl;
    return 0;
}
