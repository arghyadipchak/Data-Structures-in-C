#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

node* new_node(int val){
  node *tmp = malloc(sizeof(node));
  tmp->key = val;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
node* insert(node *tree,int val){
  if(tree==NULL) tree = new_node(val);
  else if(tree->key>val) tree->left = insert(tree->left,val);
  else tree->right = insert(tree->right,val);
  return tree;
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
  node *bst = NULL;
  int n,ch;
  while(1){
    printf("\n\t::MENU::\n");
    printf("1.Insert\n");
    printf("2.Search\n");
    printf("3.Preorder Transversal\n");
    printf("4.Inorder Transversal\n");
    printf("5.Postorder Transversal\n");
    printf("6.Exit\n");
    printf("\nEnter Choice: ");
    scanf("%d",&ch);
    printf("\n");
    if(ch==1){
      printf("Enter Element: ");
      scanf("%d",&n);
      bst = insert(bst,n);
      printf("%d Inserted!\n",n);
    }
    else if(ch==2){
      printf("Enter Element: ");
      scanf("%d",&n);
      node *fd = search(bst,n);
      printf("%d %sFound!\n",n,(fd==NULL)?"Not ":"");
    }
    else if(ch==3 || ch==4 || ch==5){
      print_order(bst,ch-3);
    }
    else if(ch==6) break;
    else printf("Invalid Choice!!\n");
  }
  printf("\t----X----\n\n");
  return 0;
}
