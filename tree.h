#include <stdlib.h>

typedef struct node{
  int key;
  struct node *left,*right;
}node;

int sint = sizeof(int);

int* preorder(node *tree){
  if(tree==NULL) return;
  int *a1,*a2,n1,n2;
  if(tree->left==NULL) n1=0;
  else{
    a1 = inorder(tree->left);
    n1 = sizeof(a1)/sint;
  }
  if(tree->right==NULL) n2=0;
  else{
    a2 = inorder(tree->right);
    n2 = sizeof(a2)/sint;
  }
  int *ar = (int*) calloc(n1+n2+1,sint);
  ar[0] = tree->key;
  for(int i=0;i<n1;i++) ar[i+1] = a1[i];
  for(int i=0;i<n2;i++) ar[n1+1+i] = a2[i];
  return ar;
}
int* inorder(node *tree){
  if(tree==NULL) return;
  int *a1,*a2,n1,n2;
  if(tree->left==NULL) n1=0;
  else{
    a1 = inorder(tree->left);
    n1 = sizeof(a1)/sint;
  }
  if(tree->right==NULL) n2=0;
  else{
    a2 = inorder(tree->right);
    n2 = sizeof(a2)/sint;
  }
  int *ar = (int*) calloc(n1+n2+1,sint);
  for(int i=0;i<n1;i++) ar[i] = a1[i];
  ar[n1] = tree->key;
  for(int i=0;i<n2;i++) ar[n1+1+i] = a2[i];
  return ar;
}
int* postorder(node *tree){
  if(tree==NULL) return;
  int *a1,*a2,n1,n2;
  if(tree->left==NULL) n1=0;
  else{
    a1 = inorder(tree->left);
    n1 = sizeof(a1)/sint;
  }
  if(tree->right==NULL) n2=0;
  else{
    a2 = inorder(tree->right);
    n2 = sizeof(a2)/sint;
  }
  int *ar = (int*) calloc(n1+n2+1,sint);
  for(int i=0;i<n1;i++) ar[i] = a1[i];
  for(int i=0;i<n2;i++) ar[n1+i] = a2[i];
  ar[n1+n2] = tree->key;
  return ar;
}
