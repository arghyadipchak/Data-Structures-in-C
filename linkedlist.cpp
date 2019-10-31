#include<stdio.h>
#include<stdlib.h>
typedef struct studentNODE
      {int id;
       char* name;
       struct studentNODE* prev=NULL,next=NULL;
      }node;
node* createnode(int n,char* str)
     {node* temp=NULL;
      temp=(node*)malloc(sizeof(node));
      temp->id=n;
      temp->name=str;
      return temp;
	 }
node* append(node* head,int n,char* str)
     {node* temp=NULL,ptr=NULL;
      temp=createnode(n,str);
	  if(head==NULL)
	    {temp->prev=NULL;
	     temp->next=NULL;
	     head=temp;
		}
	  else
	    {ptr=head;
		 while(ptr->next!=NULL)
		      ptr=ptr->next;
		 ptr->next=temp;
		 temp->next=NULL;
		 temp->prev=ptr;
		}
	  return head;
	 }
node* addbegin(node* head,int n,char* str)
     {node* temp=NULL;
      temp=createnode(n,str);
      temp->prev=NULL;
      temp->next=head;
      head=temp;
      return head;
	 }
void addnode(node* head,int n,char* str,int pos)
     {node* temp=NULL,ptr=head;
      int count=0;
	  temp=createnode(n,str);
      if((count++)<(pos-1))
        ptr=ptr->next;
      temp->next=ptr;
      temp->prev=ptr->prev;
      ptr->prev->next=temp;
      ptr->prev=temp;
	 }
node* delbegin(node* head)
     {node* temp=head;
      head=head->next;
      head->prev=NULL;
      free(temp);
      return head;
	 }
node* dellast(node* head)
     {node* temp=head;
      while(temp->next!=NULL)
           temp=temp->next;
      if(temp==head)
         {free(temp);
          head=NULL;
          return head;
		 }
	  else
	    {temp->prev->next=NULL;
	     free(temp);
	     return head;
		}
	 }
node* delnodeval(node* head,int val)
     {node* temp=head;
      while((temp->id!=val)&&(temp!=NULL))
           temp=temp->next;
	  if(temp==NULL)
	     printf("ID corresponding to data to be deleted NOT found");
	  else if(temp==head)
	        {temp->next->prev=NULL;
	         head=head->next;
	         free(temp);
	         return head;
			}
			else
			 {temp->prev->next=temp->next;
			  if(temp->next!=NULL)
			     temp->next->prev=temp->prev;
			 }
	  printf("Data corresponding to ID entered deleted successfully");
	  return head;
	 }
node* delnodepos(node* head,int pos)
     {node* temp=head;int count=1;
	  if(pos==1)
        {head=delbegin(head);
         return head;
        }
      while((temp!=NULL)&&(count<pos))
           temp=temp->next;
       
	 }
int checkempty(node* head)
    {if(head==NULL)
        return 1;
     else
        return 0;
	}
void printlist(node* head)
    {node* ptr=head;
     while(ptr!=NULL)
          {printf("ID of student : %d\nName of student : %s\n\n",ptr->id,ptr->name);
           ptr=ptr->next;
		  }
	}
void searchlist(node* head,int val)
    {node* ptr=head;
    int count=1;
     while(ptr!=NULL)
          {if(ptr->id==val)
              break;
           else
              {count++;
               ptr=ptr->next;
			  }
		  }
    if(ptr==NULL)
       printf("ID not found");
    else
       printf("ID found at node number %d",count);
	}
int main()
   {node* strear=NULL;
    int id,opt;
    char name[300];
    /*printf("Enter\n(1) for entering data ina node\n(2) for deleting data of last node\n(3)for ")
    do
      {printf("Enter id and name of student respectively :");
       scanf("%d",&id);
       gets(name);
       
	  }
   }
