#include <stdio.h>
void print_arr(int* arr){//printing array
    for(int i=0;i<15;i++){
        printf("%d,",arr[i]);
    }
    return;
}
int partition(int* arr,int low,int high){//placing arr[low] at correct position and returning the partition index
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        //[0][][][][][][].......[][][][][high]
        //    i-->                     <--j
        while(arr[i]<pivot){//finding smaller elements,right of pivot
            i++;//shifting toeards j, pivot
        }
        while(arr[j]>pivot){//finding larger elements,left of pivot
            j--;//shifting towards i,pivot
        }
        if(i<j){
            //swaping smaller and larger elements
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);//when i&j cross->j is pivot
    //pacing pivot at correct posirion, by swaping
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void quickSort(int* arr,int low,int high){//quick sorting
    if(low<high){
        int partitionIndex=partition(arr,low,high);//finding partion
        quickSort(arr,low,partitionIndex-1);//sorting left of partition(recursion)
        quickSort(arr,partitionIndex+1,high);//sorting right of partition(recursion)
    }
}
int main(){
    int arr[15]={5,2,13,8,5,11,3,9,14,10,1,2,6,4,7};
    quickSort(&arr[0],0,14);//sending the array,it's first & last index
    print_arr(arr);
    return 0;
}