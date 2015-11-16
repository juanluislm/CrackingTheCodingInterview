#include <iostream>
#include <cmath>
using namespace std;

int magicIndex(int arr[],int start, int end){
    if(end<start || start<0){
        return -1;
    }
    int mid= (start+end)/2;
    if(arr[mid]==mid){
        return mid;
    }else if(arr[mid]<mid){
        magicIndex(arr, start, mid-1);
    }else{
        magicIndex(arr, mid+1,end);
    }
}

int magicIndex2(int arr[], int start, int end){
    if(end<start || start<0){
        return -1;
    }
    int mid= (start+end)/2;
    int midValue= arr[mid];
    if(midValue==mid){
        return mid;
    }
    int leftIndex= min(mid-1, midValue);
    int left= magicIndex2(arr,start, leftIndex);
    if(left>=0){
        return left;
    }//if it's not on the left branch, it's in the right one
    int rightIndex= max(mid+1, midValue);
    int right= magicIndex2(arr, rightIndex, end);
    return right;
}

int main()
{
    int arr[]= {1,2,3,3,5,7,9};
    int arr2[]= {1,1,1,4,5,6,7}; //didn't work for this one
    cout<<magicIndex(arr2,0,6)<<endl;
    cout<<magicIndex2(arr2, 0,6)<<endl;
    return 0;
}
