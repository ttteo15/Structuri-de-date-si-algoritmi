#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Nod{
    struct Nod *next;
    char nume[20];
};

struct Queue{
  struct Nod *front;
  struct Nod *rear;

};

struct Nod *creare_nod(char *nume){
    struct Nod *nod=(struct Nod *)malloc(sizeof(struct Nod));


    strcpy(nod->nume,nume);

    nod->next=NULL;

    return nod;
}

struct Queue *creare_coada(){
    struct Queue *queue=(struct Queue*)malloc(sizeof(Queue));
    queue->front=NULL;
    queue->rear=NULL;

    return queue;
}

/*struct Queue *enqueue(){
    struct Nod *nod=creare_nod();
    struct Queue *queue;

    if(queue->rear==NULL){
        queue->front=queue->rear=creare_nod();
        return;
    }

    queue->rear->next=nod;
    queue->rear=nod;

}

struct Queue *
*/

void enqueue(struct Queue *queue,char *nume){

    struct Nod *nod_nou=creare_nod(nume);

    if(queue->front==0&&queue->rear==0){
        queue->front=queue->rear=nod_nou;
    }
    else {
        queue->rear->next=nod_nou;
        queue->rear=nod_nou;
    }

   // return queue->front;
}



char  *dequeue(struct Queue *queue){
    //struct Nod *temp=queue->front;

    if(queue->front==0)return NULL;

    char *nume=(char *)malloc(20*sizeof(char));
    strcpy(nume,queue->front->nume);

    queue->front=queue->front->next;

   // if(queue->front=NULL){
    //    queue->rear=NULL;
    //}

   // free(temp);


   return nume;
}

void display(struct Queue *queue){
    struct Nod *temp=queue->front;

    if(temp==0){
        return;
    }

    while(temp!=0){
            printf("%s\n",temp->nume);
            temp=temp->next;
        }

}

void test(struct Queue *q1,struct Queue *q2){

    while(q1->front!=NULL||q2->front!=NULL){
        if(q2->front!=NULL){
            printf("%s\n",dequeue(q2));
        }
        if(q1->front!=NULL){
            printf("%s\n",dequeue(q1));
        }
        //if(q1->front->next!=NULL&&q2->front->next==NULL){
          //  printf("%s\n",dequeue(q1));
        }
    }



int main(){
    int m,n;
    char nume[20];

    scanf("%d%d",&m,&n);

    Queue *banda1=creare_coada();
    Queue *banda2=creare_coada();

    for(int i=0;i<m;i++){
        scanf("%s",nume);
        enqueue(banda1,nume);
    }

    for(int i=0;i<n;i++){
        scanf("%s",nume);
        enqueue(banda2,nume);
    }

    //display(banda1);
    //display(banda2);

    test(banda1,banda2);

    return 0;
}
