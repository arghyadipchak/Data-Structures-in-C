#include <stdlib.h>

typedef struct node{
  int item;
  struct node *previous,*next;
}node;
node* create_node(int val){
  node *tmp = (node*) malloc(sizeof(node));
  tmp->item = val;
  tmp->previous = NULL;
  tmp->next = NULL;
  return tmp;
}
node* insert_at_rear(node *obj,int val){
  if(obj==NULL){
    obj = create_node(val);
  }
  else if(obj->next==NULL){
    node *tmp = create_node(val);
    tmp->previous = obj;
    obj->next = tmp;
  }
  else{
    insert_at_rear(obj->next,val);
  }
  return obj;
}
node* insert_at_front(node *obj,int val){
  node* tmp = create_node(val);
  tmp->next = obj;
  obj->previous = tmp;
  return tmp;
}
node* rem_from_front(node *obj){
  node *tmp = obj->next;
  free(obj);
  return tmp;
}
node* rem_from_rear(node *obj){
  if(obj->next==NULL){
    free(obj);
    return NULL;
  }
  else if(obj->next->next==NULL){
    free(obj->next);
    obj->next = NULL;
  }
  else rem_from_rear(obj->next);
  return obj;
}
int last_element(node *obj){
  if(obj->next==NULL) return obj->item;
  return last_element(obj->next);
}
int size(node *obj){
  if(obj==NULL)return 0;
  return 1+size(obj->next);
}
int* traverse(node *obj){
  int *arr = (int*) calloc(size(obj),sizeof(int));
  node *tm = obj;
  for(int i=0;tm!=NULL;tm=tm->next,i++)
    arr[i] = tm->item;
  return arr;
}
