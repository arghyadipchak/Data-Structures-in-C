#include <stdlib.h>
#define PREORDER 0
#define INORDER 1
#define POSTORDER 2

//Credits: G Kapil Krishna
typedef struct node{              //Tree nodes structure
  int key;
  struct node *left,*right;
}node;
typedef struct tuple{             //Stores variable length array
  int *ar;
  int size;
}tuple;
int sint = sizeof(int);

tuple* preorder(node *tree){      //Returns Preorder Transversal
  tuple *t = (tuple*) malloc(sizeof(tuple));
  if(tree==NULL){
    t->ar = NULL;
    t->size = 0;
  }
  else{
    tuple *t1,*t2;
    t1 = preorder(tree->left);
    t2 = preorder(tree->right);
    t->size = t1->size+t2->size+1;
    t->ar = (int*) calloc(t->size,sint);
    t->ar[0] = tree->key;
    for(int i=0;i<t1->size;i++) t->ar[i+1] = t1->ar[i];
    for(int i=0;i<t2->size;i++) t->ar[t1->size+1+i] = t2->ar[i];
  }
  return t;
}
tuple* inorder(node *tree){       //Returns Inorder Transversal
  tuple *t = (tuple*) malloc(sizeof(tuple));
  if(tree==NULL){
    t->ar = NULL;
    t->size = 0;
  }
  else{
    tuple *t1,*t2;
    t1 = inorder(tree->left);
    t2 = inorder(tree->right);
    t->size = t1->size+t2->size+1;
    t->ar = (int*) calloc(t->size,sint);
    for(int i=0;i<t1->size;i++) t->ar[i] = t1->ar[i];
    t->ar[t1->size] = tree->key;
    for(int i=0;i<t2->size;i++) t->ar[t1->size+1+i] = t2->ar[i];
  }
  return t;

}
tuple* postorder(node *tree){     //Returns Postorder Transversal
  tuple *t = (tuple*) malloc(sizeof(tuple));
  if(tree==NULL){
    t->ar = NULL;
    t->size = 0;
  }
  else{
    tuple *t1,*t2;
    t1 = postorder(tree->left);
    t2 = postorder(tree->right);
    t->size = t1->size+t2->size+1;
    t->ar = (int*) calloc(t->size,sint);
    for(int i=0;i<t1->size;i++) t->ar[i] = t1->ar[i];
    for(int i=0;i<t2->size;i++) t->ar[t1->size+i] = t2->ar[i];
    t->ar[t->size-1] = tree->key;
  }
  return t;
}
void print_order(node *tree,int odr){   //Prints Transversal
  tuple *tup;
  if(tree==NULL) printf("Empty Tree!\n");
  else{
    switch(odr){
      case PREORDER:
        printf("Preorder Transversal:\n");
        tup = preorder(tree);
        break;
      case INORDER:
        printf("Inorder Transversal:\n");
        tup = inorder(tree);
        break;
      case POSTORDER:
        printf("Postorder Transversal:\n");
        tup = postorder(tree);
        break;
    }
    for(int i=0;i<tup->size;i++) printf("%d ",tup->ar[i]);
    printf("\n");
  }
}
