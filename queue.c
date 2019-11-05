#include <stdio.h>
#include <stdlib.h>
#include "llistint.h"

//Credits: Amitakshar Biswas and Soumyajyoti Kundu
typedef struct queue{               //Queue Structure
  node *que;
  int size,capt;
}queue;
queue* create_queue(int cp){        //Creates a Queue of capacity cp
  queue *q = (queue*) malloc(sizeof(queue));
  q->capt = cp;
  q->que = NULL;
  q->size = 0;
  return q;
}
int isFull(queue *q){               //Checks if Queue is Full
  return (q->size == q->capt)?1:0;
}
int isEmpty(queue *q){              //Checks if Queue is Empty
  return (q->size == 0)?1:0;
}
int Enqueue(queue *q,int elm){      //Inserts new Element in Queue
  if(isFull(q)) return 1;
  q->que = insert_at_rear(q->que,elm);
  q->size++;
  return 0;
}
int Dequeue(queue *q){              //Removes last Element from Queue
  if(isEmpty(q)) return 1;
  q->que = rem_from_front(q->que);
  q->size--;
  return 0;
}
void display_queue(queue *q){       //Prints Queue
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
int getFront(queue *q){             //Returns First Element
  return front_element(q->que);
}
int getRear(queue *q){              //Returns Last Element
  return rear_element(q->que);
}
int main(){                         //Implements Everything
  #if defined(_WIN32)
    system("cls");
  #elif defined(__linux__) || defined(__APPLE__)
    system("clear");
  #endif
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
      printf((isFull(q))?"Queue Full!\n":"Queue has Space!\n");
    }
    else if(ch==7){
      printf((isEmpty(q))?"Queue Empty!\n":"Queue has Elements!\n");
    }
    else if(ch==8) break;
    else printf("Invalid Choice!!\n");
  }
  printf("\t----X----\n\n");
  printf("Amitakshar Biswas and Soumyajyoti Kundu\n");
  return 0;
}
