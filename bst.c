#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int key;
  struct node *left,*right;
}node;
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
node* dfs(node *tree,int val){
  if(tree==NULL || tree->key==val) return tree;
  node* lt = dfs(tree->left,val);
  return (lt!=NULL)?lt:dfs(tree->right,val);
}
int main(){
  node *bst = NULL;
  return 0;
}
