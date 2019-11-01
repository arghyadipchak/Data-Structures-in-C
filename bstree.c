#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node* new_node(int val){
  node *tmp = malloc(sizeof(node));
  tmp->key = val;
  tmp->left = NULL;
  tmp->right = NULL;
}
void insert(node *tree,int val){
  if(tree==NULL) tree = new_node(val);
  else if(tree->key>val) insert(tree->left,val);
  else insert(tree->right,val);
}
node* search(node *tree,int val){
  if(tree==NULL || tree->key==val) return tree;
  else if(tree->key>val) return search(tree->left,val);
  else return search(tree->right,val);
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
