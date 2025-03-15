#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Nod{
  struct Nod *next;
  int cod;
};

struct Queue{
    struct Nod *front;
    struct Nod *rear;
};

struct Nod *creare_nod(int cod){
    struct Nod *nod=(struct Nod *)malloc(sizeof(struct Nod));
    nod->cod=cod;

    nod->next=NULL;

    return nod;
}

struct Queue *creare_coada(){
    struct Queue *queue=(struct Queue*)malloc(sizeof(Queue));
    queue->front=NULL;
    queue->rear=NULL;

    return queue;
}

void enqueue(struct Queue *queue,int cod){
    struct Nod *nod_nou=creare_nod(cod);

    if(queue->front==0&&queue->rear==0){
        queue->front=queue->rear=nod_nou;
    }
    else {
        queue->rear->next=nod_nou;
        queue->rear=nod_nou;
    }
}

int dequeue(struct Queue *queue){
    struct Nod *temp=queue->front;

    if(queue->front==0)return -1;
    int cod;
    cod=temp->cod;

    queue->front=queue->front->next;

    if(queue->front==NULL){//daca coada devine goala actualizam si rear
        queue->rear=NULL;
    }

    return cod;
}

void display(struct Queue * queue){
    struct Nod *temp=queue->front;

    if(temp==0){
        return;
    }

    while(temp!=0){
        printf("%d ",temp->cod);
        temp=temp->next;
    }

}


void test(struct Queue *queue,char *proces){
    //struct Nod *temp=queue->front;
    int lungime=strlen(proces);

   //struct Queue *nerec=creare_coada();
    struct Queue *rec=creare_coada();
    struct Queue *proc=creare_coada();
    struct Queue *livrate=creare_coada();



    for(int i=0;i<lungime;i++){
        if(proces[i]=='r'){
            int cod=dequeue(queue);
            if(cod!=-1)enqueue(rec,cod);
        }
        else if(proces[i]=='p'){
            int cod=dequeue(rec);
            if(cod!=-1)enqueue(proc,cod);
        }
        else if(proces[i]=='l'){
            int cod=dequeue(proc);
            if(cod!=-1)enqueue(livrate,cod);
        }


    }
    display(queue);
    printf("\n");
    display(rec);printf("\n");
    display(proc);printf("\n");
    display(livrate);printf("\n");

    free(rec);
    free(proc);
    free(livrate);
}


int main(){
    int n;
    scanf("%d",&n);
    int cod;
    char *proces;
    proces=(char*)malloc(100*sizeof(char));
    Queue *coada1=creare_coada();

    for(int i=0;i<n;i++){
        scanf("%d",&cod);
        enqueue(coada1,cod);
    }
    scanf("%s",proces);

   // display(coada1);
    test(coada1,proces);
   return 0;
}
