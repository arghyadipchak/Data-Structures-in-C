#include <stdlib.h>
#include "tree.h"

//Credits: Arghyadip Chakraborty
typedef struct lnode{                 //Linked list of nodes for Queue
  node *item;
  struct lnode *next;
}lnode;
lnode* create_node(node *val){        //Creates new node
  lnode *tmp = (lnode*) malloc(sizeof(lnode));
  tmp->item = val;
  tmp->next = NULL;
  return tmp;
}
lnode* insert_at_rear(lnode *obj,node *val){    //Inserts node at rear
  if(obj==NULL){
    obj = create_node(val);
  }
  else if(obj->next==NULL)
    obj->next = create_node(val);
  else{
    insert_at_rear(obj->next,val);
  }
  return obj;
}
lnode* rem_from_front(lnode *obj){    //Removes node from front
  lnode *tmp = obj->next;
  free(obj);
  return tmp;
}
node* front_element(lnode *obj){      //Returns front element
  return obj->item;
}

typedef struct tqueue{                //Queue of nodes using linked list
  lnode *que;
  int size;
}tqueue;
tqueue* create_queue(){               //Creates Queue
  tqueue *tq = (tqueue*) malloc(sizeof(tqueue));
  tq->que = NULL;
  tq->size = 0;
  return tq;
}
int isEmpty(tqueue *tq){              //Checks if Queue is Empty
  return (tq->size == 0)?1:0;
}
void Enqueue(tqueue *tq,node *elm){   //Inserts new element in Queue
  tq->que = insert_at_rear(tq->que,elm);
  tq->size++;
}
node* Dequeue(tqueue *tq){            //Removes and Returns front element
  if(isEmpty(tq)) return NULL;
  node *tmp = tq->que->item;
  tq->que = rem_from_front(tq->que);
  tq->size--;
  return tmp;
}
node* getFront(tqueue *tq){           //Returns front element of Queue
  return front_element(tq->que);
}
