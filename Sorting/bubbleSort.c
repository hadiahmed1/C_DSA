#include <stdio.h>
void print_arr(int* arr){
    for(int i=0;i<15;i++){
        printf("%d,",arr[i]);
    }
    return;
}
void bubbleSort(int* arr,int size){
    int temp;
    for(int i=0;i<size-1;i++){
        print_arr(arr);
        printf("   for i=%d\n",i);
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){//swap
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return;
}
int main(){
    int arr[15]={5,2,13,8,15,11,3,9,14,10,1,12,6,4,7};
    bubbleSort(arr,15);
    print_arr(arr);
    return 0;
}