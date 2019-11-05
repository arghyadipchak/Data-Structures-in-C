#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define CHAR 0
#define NUMBER 1

union element{
  int no;
  char ct;
};
typedef struct elm{
  union element data;
  int type;
}elm;
typedef struct array{
  elm *st;
  int size;
}array;
array* create_array(int cp){
  array *tmp = (array*) malloc(sizeof(array));
  tmp->st = (elm*) calloc(cp,sizeof(elm));
  tmp->size = 0;
}
void add_num(array *tm,int num){
  (tm->st[tm->size]).data.no = num;
  (tm->st[tm->size]).type = NUMBER;
  tm->size++;
}
void add_char(array *tm,char ch){
  (tm->st[tm->size]).data.ct = ch;
  (tm->st[tm->size]).type = CHAR;
  tm->size++;
}
int isValid(char c){
  return (c=='+')+(c=='-')+(c=='*')+(c=='/')+(c=='^')+(c=='(')+(c==')');
}
array* str_to_arr(char st[]){
  array *tmp = create_array(strlen(st));
  int tnum;
  for(int i=0;i<strlen(st);i++){
    if(st[i]>='0' && st[i]<='9'){
      tnum = ((int)st[i])-48;
      while(st[i+1]>='0' && st[i+1]<='9'){
        ++i;
        tnum = tnum*10 + ((int)st[i])-48;
      }
      add_num(tmp,tnum);
    }
    else if(isValid(st[i]))
      add_char(tmp,st[i]);
  }
  //tmp->st = (elm*) realloc(tmp,tmp->size*sizeof(elm));
  return tmp;
}

int prec(char ch){
  switch(ch){
    case '(': return 0;
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
  }
}
array* in_to_post(char st[]){
  array *tmp = str_to_arr(st);
  array *exp = create_array(tmp->size);
  stack *chs = create_stack(tmp->size);
  char t,x;
  for(int i=0;i<tmp->size;i++){
    if((tmp->st[i]).type == NUMBER) add_num(exp,(tmp->st[i]).data.no);
    else{
      t = (tmp->st[i]).data.ct;
      if(t=='(') Push(chs,t);
      else if(t==')')
        while(1){
          x = Pop(chs);
          if(x=='(') break;
          add_char(exp,x);
        }
      else{
        while(!isEmpty(chs) && prec(Peek(chs))>=prec(t)) add_char(exp,Pop(chs));
        Push(chs,t);
      }
    }
  }
  while(!isEmpty(chs)) add_char(exp,Pop(chs));
  return exp;
}
void print_array(array *ar){
  for(int i=0;i<ar->size;i++){
    if((ar->st[i]).type==NUMBER)
      printf((i<ar->size-1)?"%d,":"%d\n",(ar->st[i]).data.no);
    else
      printf((i<ar->size-1)?"%c,":"%c\n",(ar->st[i]).data.no);
  }
}
int power(int a,int b){
  int t=1;
  for(int i=0;i<b;i++) t*=a;
  return t;
}
int eval(int a,int b,char op){
  switch(op){
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b;
    case '/': return a/b;
    case '^': return power(a,b);
  }
}
int eval_post(array *arr){
  stack *num = create_stack(arr->size);
  for(int i=0;i<arr->size;i++){
    if((arr->st[i]).type==NUMBER) Push(num,(arr->st[i]).data.no);
    else Push(num,eval(Pop(num),Pop(num),(arr->st[i]).data.ct));
  }
  return Pop(num);
}
int main(){
  #if defined(_WIN32)
    system("cls");
  #elif defined(__linux__) || defined(__APPLE__)
    system("clear");
  #endif
  array *a;
  char *s;
  int n,ch;
  while(1){
    printf("\n\t::MENU::\n");
    printf("1.Infix to Postfix\n");
    printf("2.Evaluate Postfix\n");
    printf("3.Evaluate Expression\n");
    printf("4.Exit\n");
    printf("\nEnter Choice: ");
    scanf("%d",&ch);
    printf("\n");
    if(ch==1 || ch==2 || ch==3){
      printf("Enter Length(>=Required): ");
      scanf("%d",&n);
      s = (char*) calloc(n,sizeof(char));
      getchar();
      printf("Enter Expression:\n");
      //fgets(s,n+1,stdin);
      scanf("%[^\n]%*c",s);
      if(ch==1){
        printf("Postfix Expression:\n");
        print_array(in_to_post(s));
      }
      else if(ch==2)
        printf("Evaluated: %d\n",eval_post(str_to_arr(s)));
      else if(ch==3){
        printf("Evaluation:\n");
        printf("%s = %d\n",s,eval_post(in_to_post(s)));
      }
    }
    else if(ch==4) break;
    else printf("Invalid Choice!!\n");
  }
  printf("\t----X----\n\n");
  return 0;
}
