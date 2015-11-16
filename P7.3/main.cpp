#include <iostream>
#include <cmath>

using namespace std;
const int epsilon=0.000001;

struct line{
    float slope;
    float x_intercept;
    float y_intercept;
    line(int s=0, int x=0, int y=0){
        slope=s;
        x_intercept=x;
        y_intercept=y;
    };
};

bool DoTheyIntersect(line l1, line l2){
    if(l1.x_intercept==l2.x_intercept && l1.y_intercept==l2.y_intercept){
        cout<< "coincident lines"<<endl;
        return true;
    }
    if((l1.slope/l2.slope <=epsilon) && (l2.slope/l1.slope <= slope)) return true;
    else return false;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
