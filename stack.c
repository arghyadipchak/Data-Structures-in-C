#include <stdio.h>
#include <stdlib.h>
#include "llistint.h"

typedef struct stack{
  node *stk;
  int size,capt;
}stack;

stack* create_stack(int cp){
  stack *s = (stack*) malloc(sizeof(stack));
  s->capt = cp;
  s->stk = NULL;
  s->size = 0;
  return s;
}
int isFull(stack *s){
  return (s->size == s->capt)?1:0;
}
int isEmpty(stack *s){
  return (s->size == 0)?1:0;
}
int Push(stack *s,int elm){
  if(isFull(s)) return 1;
  s->stk = insert_at_rear(s->stk,elm);
  s->size++;
  return 0;
}
int Pop(stack *s){
  if(isEmpty(s)) return 1;
  s->stk = rem_from_rear(s->stk);
  s->size--;
  return 0;
}
void display_stack(stack *s){
  if(isEmpty(s))
      printf("Stack Empty!!!\n");
  else{
      printf("Stack:\n");
      int *arrq = traverse(s->stk);
      for(int i=0;i<s->size;i++)
        printf("%d ",arrq[i]);
      printf("\n");
  }
}
int Peek(stack *s){
  return rear_element(s->stk);
}

int main(){
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
      printf("Enter Element: ");
      scanf("%d",&n);
      if(Push(s,n))
        printf("Stack Overflow!!!\n");
      else printf("%d Pushed!\n",n);
    }
    else if(ch==2){
      if(isEmpty(s))
        printf("Stack Underflow!!!\n");
      else{
        printf("Poped Item: %d\n",Peek(s));
        Pop(s);
      }
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
}
