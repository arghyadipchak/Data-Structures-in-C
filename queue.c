#include <stdio.h>
#include <stdlib.h>
#include "llistint.h"

typedef struct queue{
  node *que;
  int size,capt;
}queue;

queue* create_queue(int cp){
  queue *q = (queue*) malloc(sizeof(queue));
  q->capt = cp;
  q->que = NULL;
  q->size = 0;
  return q;
}
int isFull(queue *q){
  return (q->size == q->capt)?1:0;
}
int isEmpty(queue *q){
  return (q->size == 0)?1:0;
}
int Enqueue(queue *q,int elm){
  if(isFull(q)) return 1;
  q->que = insert_at_rear(q->que,elm);
  q->size++;
  return 0;
}
int Dequeue(queue *q){
  if(isEmpty(q)) return 1;
  q->que = rem_from_front(q->que);
  q->size--;
  return 0;
}
void display_queue(queue *q){
  if(isEmpty(q))
      printf("Queue Empty!!!\n");
  else{
      printf("Queue:\n");
      int *arrq = traverse(q->que);
      for(int i=0;i<q->size;i++)
        printf("%d ",arrq[i]);
      printf("\n");
  }
}
int getFront(queue *q){
  return q->que->item;
}
int getRear(queue *q){
  return last_element(q->que);
}

int main(){
  int n;
  printf("Enter Capacity of Queue: ");
  scanf("%d",&n);
  queue *q = create_queue(n);
  int ch;
  while(1){
    printf("\n\t::MENU::\n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display Queue\n");
    printf("4.Get Front\n");
    printf("5.Get Rear\n");
    printf("6.Check Full\n");
    printf("7.Check Empty\n");
    printf("8.Exit\n");
    printf("\nEnter Choice: ");
    scanf("%d",&ch);
    printf("\n");
    fflush(stdin);
    if(ch==1){
      printf("Enter Element: ");
      scanf("%d",&n);
      if(Enqueue(q,n))
        printf("Queue Full!!!\n");
      else printf("%d Enqueued!\n",n);
    }
    else if(ch==2){
      if(isEmpty(q))
        printf("Queue Empty!!!\n");
      else{
        printf("%d Dequeued!\n",q->que->item);
        Dequeue(q);
      }
    }
    else if(ch==3){
      display_queue(q);
    }
    else if(ch==4||ch==5){
      if(isEmpty(q))
        printf("Queue Empty!!!\n");
      else if(ch==4)
        printf("Front Item: %d\n",getFront(q));
      else printf("Rear Item: %d\n",getRear(q));
    }
    else if(ch==6){
      printf((isFull(q))?"Queue Full!\n":"Queue Not Full!\n");
    }
    else if(ch==7){
      printf((isEmpty(q))?"Queue Empty!\n":"Queue Not Empty!\n");
    }
    else if(ch==8) break;
    else printf("Invalid Choice!!\n");
  }
  printf("\t----X----\n\n");
}
