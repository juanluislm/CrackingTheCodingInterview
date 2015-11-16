#include <iostream>

using namespace std;

struct Test{
    char* ptr;
};

void shallow_copy(Test& src, Test& dest){
    dest.ptr= src.ptr;
}

void deep_copy(Test& src, Test& dest){
    dest.ptr= (char*)malloc(strlen(src.ptr) + 1);
    strcpy(dest.ptr, src.ptr);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
