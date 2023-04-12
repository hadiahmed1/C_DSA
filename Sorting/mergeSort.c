#include <stdio.h>
void merge(int a[],int l,int m,int h){
    int i,j,k,b[20];
    i=l;
    j=m+1;
    k=l;
    while(i<=m && j<=h){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;k++;
        }else{
            b[k]=a[j];
            j++;k++;
        }
    }
    while (i<=m){
        b[k]=a[i];
        i++;k++;
    }
    while(j<=h){
        b[k]=a[j];
        j++;k++;
    }
    for(int i=l;i<=h;i++){
        a[i]=b[i];
    }
    return;
}
void mergeSort(int a[],int l,int h){
    int m;
    if(l<h){
        m=(l+h)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,h);
        merge(a,l,m,h);
    }
}
void printArray(int* arr, int size){
    printf("Enters print\n");
    for(int i=0;i<size;i++){
        printf("%d,",arr[i]);
    }
    printf("ret\n");
    return;
}
int main(){
    printf("Okay");
    int arr[10]={3,9,5,6,2,3,8,1,7,5};
    //printArray(arr,10);
    printf("Okay2");

    mergeSort(arr,0,10);
    printArray(arr,10);
    return 0;
}