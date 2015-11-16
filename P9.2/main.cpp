#include <iostream>

using namespace std;

int DOWN = 0;
int RIGHT =1;

void print_paths(int* path, int len){
    if(len==0){
        cout<<"Empty path "<<endl;
    }else{
        cout<<(path[0]==DOWN ? "d":"r")<<endl;
        for(int i=1; i<len; ++i){
            cout << " -> " << (path[i] == DOWN) ? " d" : " r";
        }
    }
    cout<<endl;
}

int find_paths(int x, int y, int* path, int len){
    if (x == 0 && y == 0) {
        print_paths(path, len);
        return 1;
    }
    int n=0;
    if (x > 0) {
        path[len] = DOWN;
        n += find_paths(x-1, y, path, len + 1);
    }
    if (y > 0) {
        path[len] = RIGHT;
        n += find_paths(x, y-1, path, len + 1);
    }
    return n;
}

int main()
{
    int x=3; int y=3;
    int *path = new int[x + y];
    cout << "Number of paths: " << find_paths(x, y, path, 0) << endl;
    delete [] path;
    return 0;
}
