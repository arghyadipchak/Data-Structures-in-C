#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree_que.h"

typedef struct node{
  int key;
  struct node *left,*right;
}node;
node* new_node(int val){
  node *tmp = malloc(sizeof(node));
  tmp->key = val;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
void insert(node *tree,int val){
  queue *qt = create_queue();
  Enqueue(qt,tree);
  node *tmp;
  while(!isEmpty(qt)){
    tmp = Dequeue(qt);
    if(tmp->left==NULL){
      tmp->left = new_node(val);
      break;
    }
    else Enqueue(qt,tmp->left);
    if(tmp->right==NULL){
      tmp->right = new_node(val);
      break;
    }
    else Enqueue(qt,tmp->right);
  }
}
node* dfs(node *tree,int val){
  if(tree==NULL || tree->key==val) return tree;
  node* lt = dfs(tree->left,val);
  return (lt!=NULL)?lt:dfs(tree->right,val);
}
int main(){
  #if defined(_WIN32)
    system("cls");
  #elif defined(__linux__) || defined(__APPLE__)
    system("clear");
  #endif
  node *bt = NULL;

  return 0;
}
