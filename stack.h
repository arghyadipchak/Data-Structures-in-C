#include <stdlib.h>
#include "llistint.h"

//Credits: Sandipan Misra and Varun Pramod Agrawal
typedef struct stack{
  node *stk;
  int size,capt;
}stack;
stack* create_stack(int cp){            //Creates the stack
  stack *s = (stack*) malloc(sizeof(stack));
  s->capt = cp;
  s->stk = NULL;
  s->size = 0;
  return s;
}
int isFull(stack *s){                   //Checks whether stack is full
  return (s->size == s->capt)?1:0;
}
int isEmpty(stack *s){                  //Checks whether stack is empty
  return (s->size == 0)?1:0;
}
void Push(stack *s,int elm){            //Pushes values into the stack
  if(isFull(s)) return;
  s->stk = insert_at_rear(s->stk,elm);
  s->size++;
}
int Pop(stack *s){                      //Takes out values from the stack
  if(!isEmpty(s)){
    int tmp = rear_element(s->stk);
    s->stk = rem_from_rear(s->stk);
    s->size--;
    return tmp;
  }
}
void display_stack(stack *s){           //Displays contents of the stack
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
int Peek(stack *s){                    //Displays last element of the stack
  return rear_element(s->stk);
}
