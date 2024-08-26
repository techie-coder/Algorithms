#include <stdio.h>


int binarySearch(int arr[], int element, int size){
    int low = 0;
    int high = size-1;
    int mid;
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid]==element){
            printf("Element found at index: %d\n", mid);
            return mid;
        }
        else if(element < arr[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int a[5] = {34, 56, 72, 89, 94};
    binarySearch(a,72,5);
    binarySearch(a,34,5);
    binarySearch(a,0,5);
    return 0;
}