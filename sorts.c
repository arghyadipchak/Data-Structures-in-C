#include <stdio.h>
#include <stdlib.h>

void swap(int *arr,int p1,int p2){
  int tmp = *(arr+p1);
  *(arr+p1) = *(arr+p2);
  *(arr+p2) = tmp;
}
void selection_sort(int *arr,int n){
  int minpos=0;
  for(int i=0;i<n-1;i++){
    minpos=i;
    for(int j=i+1;j<n;j++)
      if(arr[j]<arr[minpos]) minpos=j;
    if(minpos!=i) swap(arr,i,minpos);
  }
}
void buuble_sort(int *arr,int n){
  for(int i=n-1;i>0;i--){
    for(int j=0;j<i;j++)
      if(arr[j]>arr[j+1]) swap(arr,j,j+1);
  }
}
void insertion_sort(int *arr,int n){
  
}
