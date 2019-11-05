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
void Push(stack *s,int elm){
  if(isFull(s)) return;
  s->stk = insert_at_rear(s->stk,elm);
  s->size++;
}
int Pop(stack *s){
  if(!isEmpty(s)){
    int tmp = rear_element(s->stk);
    s->stk = rem_from_rear(s->stk);
    s->size--;
    return tmp;
  }
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
