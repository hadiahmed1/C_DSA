#include <stdio.h>
void print_arr(int* arr){
    for(int i=0;i<15;i++){
        printf("%d,",arr[i]);
    }
    return;
}
void selectionSort(int* arr,int size){
    int temp;
    int mini;
    for(int i=0;i<size;i++){
        print_arr(arr);
        printf("   for i=%d\n",i);
        mini=i;
        for(int j=i;j<size;j++){
            if(arr[j]<arr[mini]){//finding maximmum
                mini=j;
            }
        }
        //swap;
        temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
    return;
}
int main(){
    int arr[15]={5,2,13,8,15,11,3,9,14,10,1,12,6,4,7};
    selectionSort(arr,15);
    print_arr(arr);
    return 0;
}