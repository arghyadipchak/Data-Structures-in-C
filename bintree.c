#include <stdio.h>
#include <stdlib.h>
#include "tree_que.h"

node* new_node(int val){
  node *tmp = malloc(sizeof(node));
  tmp->key = val;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
node* insert(node *tree,int val){
  if(tree==NULL){
    tree = new_node(val);
  }
  else{
    tqueue *qt = create_queue();
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
  return tree;
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
  int n,ch;
  while(1){
    printf("\n\t::MENU::\n");
    printf("1.Insert\n");
    printf("2.DFS Search\n");
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
      bt = insert(bt,n);
      printf("%d Inserted!\n",n);
    }
    else if(ch==2){
      printf("Enter Element: ");
      scanf("%d",&n);
      node *fd = dfs(bt,n);
      printf((fd==NULL)?"%d Not Found!\n":"%d Found!\n",n);
    }
    else if(ch==3 || ch==4 || ch==5){
      print_order(bt,ch-3);
    }
    else if(ch==6) break;
    else printf("Invalid Choice!!\n");
  }
  printf("\t----X----\n\n");
  return 0;
}
