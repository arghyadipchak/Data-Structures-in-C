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
int isOperator(char c){
  return (c=='+')+(c=='-')+(c=='*')+(c=='/')+(c=='^');
}
int isValid(char c){
  return isOperator(c)+(c=='(')+(c==')');
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
      printf("%d\n",tnum);
    }
    else if(isValid(st[i])){
      add_char(tmp,st[i]);
      printf("%c\n",st[i]);
    }
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
void eval_post(array *arr){

}
int main(){
  print_array(in_to_post("(25*36^2)+6"));
}
