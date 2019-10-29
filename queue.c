#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int *que;
    int size,rear;
}queue;

queue* create_queue(int sz){
    queue *q = (queue*) malloc(sizeof(queue));
    q->size = sz;
    q->que = (int*) malloc(sz*sizeof(int));
    q->rear = -1;
    return q;
}
int isFull(queue *q){
    return (q->rear == q->size-1)?1:0;
}
int isEmpty(queue *q){
    return (q->rear == -1)?1:0;
}
int Enqueue(queue *q,int elm){
    if(isFull(q)) return 1;
    q->rear++;
    q->que[q->rear] = elm;
    return 0;
}
int Dequeue(queue *q){
    if(isEmpty(q)) return 1;
    for(int i=0;i<q->rear-1;i++)
        q->que[i] = q->que[i+1];
        q->rear--;
    return 0;
}
void display_queue(queue *q){
    if(isEmpty(q))
        printf("Queue Empty!!!\n");
    else{
        printf("Queue:\n");
        for(int i=0;i<q->rear;i++)
            printf("%d ",q->que[i]);
        printf("\n");
    }
}
int getFront(queue *q){
    return q->que[0];
}
int getRear(queue *q){
    return q->que[q->rear];
}

int main(){
    int n;
    printf("Enter Size of Queue: ");
    scanf("%d",&n);
    queue *q = create_queue(n);
    int ch=1;
    while(1){
        printf("\n\t::MENU::\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display Queue\n");
        printf("4.Get Front\n");
        printf("5.Get Rear\n");
        printf("6.Check Full\n");
        printf("7.Check Empty\n");
        printf("8.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&ch);
        printf("\n");
        
        if(ch==1){
            printf("Enter Element: ");
            scanf("%d",&n);
            if(Enqueue(q,n))
                printf("Queue Full!!!\n");
            else printf("%d Enqueued!\n",n);
        }
        else if(ch==2){
            if(isEmpty(q))
                printf("Queue Empty!!!\n");
            else{
                printf("%d Dequeued!\n",q->que[0]);
                Dequeue(q);
            }
        }
        else if(ch==3){
            display_queue(q);
        }
        else if(ch==4||ch==5){
            if(isEmpty(q))
                printf("Queue Empty!!!\n");
            else if(ch==4)
                printf("Front Item: %d\n",q->que[0]);
            else printf("Rear Item: %d\n",q->que[q->rear]);
        }
        else if(ch==6){
            printf((isFull(q))?"Queue Full!\n":"Queue Not Full!\n");
        }
        else if(ch==7){
            printf((isEmpty(q))?"Queue Empty!\n":"Queue Not Empty!\n");
        }
        else if(ch==8) break;
        else printf("Invalid Choice!!\n");
        getchar();
    }
    printf("\t--THANK YOU--\n\n");
}