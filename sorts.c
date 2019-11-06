#include <stdio.h>
#include <stdlib.h>

//Credits: Soham Ghosh and Rishika Agrawal

//Sorting Functions:
//Selection Sort, Bubble Sort
//Insertion Sort, Merge Sort

void swap(int *arr,int p1,int p2){          //Swaps values of 2 positions of the array
  int tmp = *(arr+p1);//arr[p1]
  *(arr+p1) = *(arr+p2);
  *(arr+p2) = tmp;
}
void selection_sort(int *arr,int n){
  int minpos;
  for(int i=0;i<n-1;i++){
    minpos=i;
    for(int j=i+1;j<n;j++)
      if(arr[j]<arr[minpos]) minpos=j;
    if(minpos!=i) swap(arr,i,minpos);
  }
}
void bubble_sort(int *arr,int n){
  for(int i=n-1;i>0;i--){
    for(int j=0;j<i;j++)
      if(arr[j]>arr[j+1]) swap(arr,j,j+1);
  }
}
void insertion_sort(int *arr,int n){
  int val,pos;
  for(int i=1;i<n;i++){
    val=arr[i];
    pos=i;
    while(pos>0 && arr[pos-1]>val){
      arr[pos] = arr[pos-1];
      pos--;
    }
    if(pos!=i) arr[pos]=val;
  }
}
void merge(int *arr,int *ar1,int n1,int *ar2,int n2){
  int p1=0;
  int p2=0;
  int p=0;
  while(p1<n1 && p2<n2){
    if(ar1[p1]<=ar2[p2])
      arr[p++] = ar1[p1++];
    else
      arr[p++] = ar2[p2++];
  }
  while(p1<n1) arr[p++] = ar1[p1++];
  while(p2<n2) arr[p++] = ar2[p2++];
}
void merge_sort(int *arr,int n){
  if(n<=1) return;
  int *ar1 = (int*) calloc(n/2,sizeof(int));
  int *ar2 = (int*) calloc(n-n/2,sizeof(int));
  for(int i=0;i<n/2;i++)
    ar1[i] = arr[i];
  for(int i=0;i<n-n/2;i++)
    ar2[i] = arr[i+n/2];
  merge_sort(ar1,n/2);
  merge_sort(ar2,n-n/2);
  merge(arr,ar1,n/2,ar2,n-n/2);
}
//All The Sorting Functions are to be called as
//func_sort(<array pointer>,<size>);
int main(){                                   //Implements Everything
  #if defined(_WIN32)
    system("cls");
  #elif defined(__linux__) || defined(__APPLE__)
    system("clear");
  #endif
  int n,ch;
  int *arr = (int*)malloc(1);
  void (*func[4])(int*,int)={selection_sort,bubble_sort,insertion_sort,merge_sort};
  while(1){
    printf("\n\t::MENU::\n");
    printf("1.Selection Sort\n");
    printf("2.Bubble Sort\n");
    printf("3.Insertion Sort\n");
    printf("4.Merge Sort\n");
    printf("5.Exit\n");
    printf("\nEnter Choice: ");
    scanf("%d",&ch);
    if(ch==5)break;
    printf("\nEnter Length: ");
    scanf("%d",&n);
    arr = (int*) realloc(arr,n*sizeof(int));
    printf("Enter %d Elements:\n",n);
    for(int i=0;i<n;i++)
      scanf("%d",arr+i);
    printf("\nArray:\n");
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    printf("\n");
    (*func[ch])(arr,n);
    printf("Sorted Array:\n");
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    printf("\n");
  }
  printf("\t----X----\n\n");
  printf("Coded By: Soham Bakshi and Rishika Agrawal\n");
  return 0;
}
