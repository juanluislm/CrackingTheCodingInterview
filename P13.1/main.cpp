#include <iostream>
#include <cmath>

using namespace std;

void printLast10lines(char* filename){
    const int k=10;
    ifstream file(filename);
    string L[k];
    int size=0;
    while(file.good()){
        getline(file, L[size%k]);
        size++;
    }
    int start = size >k? (size%k):0;
    int count = min(k,size);
    for(int i=0; i<count; i++){
        cout<<L[(start+1)%k]<<endl;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
