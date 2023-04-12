#include <stdio.h>
void print_arr(int* arr){
    for(int i=0;i<15;i++){
        printf("%d,",arr[i]);
    }
    return;
}
void insertionSort(int* arr,int size){//function to perform insertion sort
    int temp;
    int j;
    for(int i=1;i<size;i++){//Loop for passes
        print_arr(arr);
        printf("   for i=%d,inserting %d\n",i,arr[i]);
        temp=arr[i];//element to be inserted
        j=i-1;
        while (arr[j]>temp && j>=0){//while elements before are larger
            arr[j+1]=arr[j];//right shift
            j--;
        }
        arr[j+1]=temp;//inserting temp in correct position
        
        // for(int j=i;j>0;j--){
        //     while(arr[j]<arr[j-1]){//swap
        //         temp=arr[j];
        //         arr[j]=arr[j-1];
        //         arr[j-1]=temp;
        //     }
        // }
    }
}
int main(){
    int arr[15]={5,2,13,8,15,11,3,9,14,10,1,12,6,4,7};
    insertionSort(&arr[0],15);
    print_arr(arr);
    return 0;
}