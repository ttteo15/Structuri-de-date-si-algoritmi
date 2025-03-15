#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Nod{
    struct Nod *next;
    char nume[30];
    int nr;
};

struct Queue{
  struct Nod *front;
  struct Nod *rear;
};

struct Nod *creare_nod(char *nume,int nr){
    struct Nod *nod=(struct Nod*)malloc(sizeof(struct Nod));

    nod->nr=nr;
    strcpy(nod->nume,nume);

    nod->next=NULL;
    return nod;
}

struct Queue *creare_coada(){
    struct Queue *queue=(struct Queue *)malloc(sizeof(struct Queue));

    queue->front=NULL;
    queue->rear=NULL;

    return queue;

}

void enqueue(struct Queue *queue,char *nume,int nr){
    struct Nod *nod_nou=creare_nod(nume,nr);

    if(queue->front==NULL&&queue->rear==NULL){
        queue->front=queue->rear=nod_nou;
    }
    else{
        queue->rear->next=nod_nou;//atribuie nodul nou
        //ca fiind urmatorul nod dupa cel care era la
        //sfarsitul cozii, adica queue->rear
        //practic extinde lista legata conectand nod nou la final
        //LEAGA NOUL NOD
        queue->rear=nod_nou;
        //actualizeaza pointerul queue->rear pt a indica ca
        //acum nod_nou e ult elem din coada

        //QUEUE->REAR DEVINE NOUL NOD

    }

}

//struct nod pt a returna un nod complet
struct Nod *dequeue(struct Queue *queue){
    struct Nod *temp=queue->front;

    if(queue->front==NULL)return NULL;

    //int nr;
    //nr=temp->nr;
    char *nume=(char *)malloc(30*sizeof(char));
    strcpy(nume,temp->nume);

    queue->front=queue->front->next;


    if(queue->front==NULL){
       queue->rear=NULL;
   }
   temp->next=NULL;
   return temp;
}

void display(struct Queue *queue){
    struct Nod *temp=queue->front;

    if(temp==NULL)return;

    while(temp!=NULL){
        printf("%s ",temp->nume);
        temp=temp->next;
    }

}

void test(struct Queue *queue){
    struct Queue *q1=creare_coada();
    struct Queue *q2=creare_coada();
    struct Queue *q3=creare_coada();

    while(queue->front!=NULL){

     //char *nume=dequeue(queue);
     //int nr=queue->front->nr;
     struct Nod *temp=dequeue(queue);
        if(temp->nr==1){

           enqueue(q1,temp->nume,1);
        }
        else if(temp->nr==2){

            enqueue(q2,temp->nume,2);
        }
        else if(temp->nr==3){

            enqueue(q3,temp->nume,3);
        }
        free(temp);
    }


    while(q1->front!=NULL&&q2->front!=NULL&&q3->front!=NULL){
        struct Nod *n1=dequeue(q1);
        struct Nod *n2=dequeue(q2);
        struct Nod *n3=dequeue(q3);
        printf("%s %s %s\n",n1->nume,n2->nume,n3->nume);
        free(n1);
        free(n2);
        free(n3);
    }
    free(q1);
    free(q2);
    free(q3);
}

int main(){
    char nume[30];
    int nr;

    struct Queue *queue=creare_coada();
    while(scanf("%s %d",nume,&nr)!=EOF){
        //scanf("%s",nume);
        //if(strcmp(nume,"stop")==0)break;
        //scanf("%d",&nr);
        enqueue(queue,nume,nr);
    }
    test(queue);
   return 0;
}
