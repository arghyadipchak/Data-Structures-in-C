#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct studentNODE
      {int id;
       char name[300];
       struct studentNODE *prev,*next;
      }node;
node* createnode(int n,char str[])
     {node* temp=NULL;
      temp=(node*)malloc(sizeof(node));
      temp->id=n;
      strcpy(temp->name,str);
      return temp;
	 }
node* append(node* head,int n,char str[])
     {node* temp=NULL,*ptr=NULL;
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
node* addbegin(node* head,int n,char str[])
     {node* temp=NULL;
      temp=createnode(n,str);
      temp->prev=NULL;
      temp->next=head;
      head=temp;
      return head;
	 }
void addnode(node* head,int n,char str[],int pos)
     {node* temp=NULL,*ptr=head;
      int count=0;
	  temp=createnode(n,str);
      while((count++)<(pos-2))
        ptr=ptr->next;
      temp->prev=ptr;
      temp->next=ptr->next;
      ptr->next->prev=temp;
      ptr->next=temp;
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
	     printf("ID corresponding to data to be deleted NOT found\n");
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
	  printf("Data corresponding to ID entered deleted successfully\n");
	  return head;
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
       printf("ID not found\n");
    else
       printf("ID found at node number %d\n Name of student: %s\n",count,ptr->name);
	}
int main(){
  #if defined(_WIN32)
    system("cls");
  #elif defined(__linux__) || defined(__APPLE__)
    system("clear");
  #endif
    node* start=NULL;
    int id,opt,pos,choice;
    char name[300];
    do
      {printf("\nEnter\n(1)For adding node to the end of the list\n(2)For adding node in the beginning\
	  \n(3)For adding node at a certain position\n(4)For deleting first node\n(5)For deleting last node\n(6)For deleting node with a certain data\
	 \n(7)For checking whether the list is empty\n(8)For printing the list\n(9)For searching a particular data in the list\n");
	  scanf("%d",&opt);
    printf("\n");
	  switch (opt)
	      {case 1:printf("Enter Name of student:\n");
	              scanf("%s",name);
	              printf("Enter ID of the student: ");
	              scanf("%d",&id);
	              start=append(start,id,name);
	              break;
	        case 2:printf("Enter Name of student:\n");
	              scanf("%s",name);
	              printf("Enter ID of the student: ");
	              scanf("%d",&id);
	              start=addbegin(start,id,name);
	              break;
	        case 3:printf("Enter Name of student:\n");
	              scanf("%s",name);
	              printf("Enter ID of the student: ");
	              scanf("%d",&id);
	              printf("Enter position of inserting data: ");
	              scanf("%d",&pos);
	              addnode(start,id,name,pos);
	              break;
	        case 4:if(checkempty(start))
	                 printf("List is empty,deletion operation INVALID!\n");
	                else
	                 {start=delbegin(start);
	                  printf("Deleted successfully\n");
	                 }
	                break;
	        case 5:if(checkempty(start))
	                 printf("List is empty,deletion operation INVALID!\n");
	                else
	                 {start=dellast(start);
	                  printf("Deleted successfully\n");
	                 }
	                break;
	        case 6:if(checkempty(start))
	                 printf("List is empty,deletion operation INVALID!\n");
	                else
	                 {printf("Enter ID of student whose data is to deleted: ");
	                  scanf("%d",&id);
					  start=delnodeval(start,id);
	                 }
	                break;
	        case 7: if(checkempty(start))
	                 printf("List is empty\n");
	                else
	                  printf("List is not empty\n");
	                break;
	        case 8:if(checkempty(start))
			         printf("List is empty\n");
			        else
					 printlist(start);
					break;
			case 9:if(checkempty(start))
			        printf("List empty,no data found\n");
			       else
			        {printf("Enter ID of data to be searched for: ");
			         scanf("%d",&id);
					 searchlist(start,id);
				    }
				   break;
            default:printf("INVALID choice\n");
			        break;
		  }
		printf("\nDo you want to choose again? 1 for YES,0 for NO\n");
		scanf("%d",&choice);
	  }while(choice);
    printf("\t----X----\n\n");
   return 0;
   }
