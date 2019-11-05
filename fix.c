#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHAR 0
#define NUMBER 1

union element{
  int no;
  char ct;
}
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
      add_num(tmp,num);
    }
    else if(isValid(st[i]))
      add_char(tmp,st[i]);
  }
  tmp->st = (elm*) realloc(tmp,tmp->size*sizeof(elm));
  return tmp;
}

array* in_to_post(char st[]){
  array *tmp = str_to_arr(st);
  array *exp = create_array(tmp->size);
}
