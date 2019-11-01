#include <stdlib.h>
#include "tree.h"

typedef struct lnode{
  node *item;
  struct lnode *next;
}lnode;
lnode* create_node(node *val){
  lnode *tmp = (lnode*) malloc(sizeof(lnode));
  tmp->item = val;
  tmp->next = NULL;
  return tmp;
}
lnode* insert_at_rear(lnode *obj,node *val){
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
lnode* rem_from_front(lnode *obj){
  lnode *tmp = obj->next;
  free(obj);
  return tmp;
}
node* front_element(lnode *obj){
  return obj->item;
}

typedef struct tqueue{
  lnode *que;
  int size;
}tqueue;
tqueue* create_queue(){
  tqueue *tq = t(queue*) malloc(sizeof(tqueue));
  tq->que = NULL;
  tq->size = 0;
  return tq;
}
int isEmpty(tqueue *tq){
  return (tq->size == 0)?1:0;
}
void Enqueue(tqueue *tq,node *elm){
  tq->que = insert_at_rear(tq->que,elm);
  tq->size++;
  return 0;
}
node* Dequeue(tqueue *tq){
  if(isEmpty(tq)) return NULL;
  node *tmp = tq->que->item;
  tq->que = rem_from_front(tq->que);
  tq->size--;
  return tmp;
}
node* getFront(tqueue *tq){
  return front_element(tq->que);
}
