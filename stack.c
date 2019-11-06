#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//Credits: Sandipan Misra and Varun Pramod Agrawal
int main(){                 //Implements Everything
  #if defined(_WIN32)
    system("cls");
  #elif defined(__linux__) || defined(__APPLE__)
    system("clear");
  #endif
  int n,ch;
  printf("Enter Capacity of Stack: ");
  scanf("%d",&n);
  stack *s = create_stack(n);
  while(1){
    printf("\n\t::MENU::\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display Stack\n");
    printf("4.Peek\n");
    printf("5.Check Full\n");
    printf("6.Check Empty\n");
    printf("7.Exit\n");
    printf("\nEnter Choice: ");
    scanf("%d",&ch);
    printf("\n");
    if(ch==1){
      if(isFull(s))
        printf("Stack Overflow!!!\n");
      else{
        printf("Enter Element: ");
        scanf("%d",&n);
        Push(s,n);
        printf("%d Pushed!\n",n);
      }
    }
    else if(ch==2){
      if(isEmpty(s))
        printf("Stack Underflow!!!\n");
      else
        printf("Poped Item: %d\n",Pop(s));
    }
    else if(ch==3){
      display_stack(s);
    }
    else if(ch==4){
      n = Peek(s);
      if(s==NULL)
        printf("Stack Underflow!!!\n");
      else printf("Item: %d\n",n);
    }
    else if(ch==5){
      printf((isFull(s))?"Stack Full!\n":"Stack has Space!\n");
    }
    else if(ch==6){
      printf((isEmpty(s))?"Stack Empty!\n":"Stack has Elements!\n");
    }
    else if(ch==7) break;
    else printf("Invalid Choice!!\n");
  }
  printf("\t----X----\n\n");
  printf("Coded By: Sandipan Misra and Varun Pramod Agrawal\n");
  return 0;
}
