//https://youtube.com/playlist?list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi&si=muPW_tYbJ3ZWaisD


#include <stdio.h>


int display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

int insertAtInd(int arr[], int size, int element, int capacity, int index){
    if(size>=capacity)
    {
        return -1;
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1] = arr[i];
    }
    arr[index]=element;
    return 1;
}

int deleteAtInd(int arr[], int size, int capacity, int index){
    if(size>=capacity)
    {
        return -1;
    }
    arr[index] = 0;
    for(int i=index+1;i<size;i++){
        arr[i-1] = arr[i];
    }
    return 1;
}

int main(){
    int arr[100] = {12, 15, 6, 7, 89};
    int size = 5, element = 45, index = 3;
    display(arr,size);
    size+=1;
    insertAtInd(arr,size,element,100,index);
    printf("Array after insertion:\n");
    display(arr,size);
    deleteAtInd(arr,size,100,index);
    size-=1;
    display(arr,size);
    return 0;
}
