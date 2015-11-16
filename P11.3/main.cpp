#include <iostream>

using namespace std;

int search_rot(int arr[], int left, int right, int num){
    if(right<left) return -1;
    int middle= (left+right)/2;
    if(arr[middle]==num) return middle;
    //find which side is ordered... also, determine if the number is in that side
    if(arr[left]<arr[middle]){//left is ordered
        if(num>= arr[left] && num<=arr[middle]){
            return search_rot(arr,left,middle-1,num);
        }else{
            return search_rot(arr,middle+1,right, num);
        }
    }else if(arr[right]>arr[middle]){//right is ordered
        if(num>=arr[middle] && num<= arr[right]){
            return search_rot(arr, middle+1, right, num);
        }else{
            return search_rot(arr, left, middle-1, num);
        }
    }else if(arr[left]==arr[middle]){
        if(arr[middle]!=arr[right]){
            return search_rot(arr, middle+1, right, num);
        }else{
            int result= search_rot(arr,left, middle-1, num);
            if(result==-1){
                return search_rot(arr, middle+1, right, num);
            }else{
                return result;
            }
        }
    }
}

int main()
{
    int num=2;
    int arr[]={13,20,0,2,5,7,8};
    int arrd[]= {2,2,2,2,0,1,2};
    //cout<<sizeof(arr)<<endl;
    cout<<"element "<<num<<" found at position "<<search_rot(arr, 0, (sizeof(arr)/4)-1, num)<<endl;
    return 0;
}
