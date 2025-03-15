#include<stdio.h>
#include<stdlib.h>

struct Nod {
    int timp;
    struct Nod *next;
};

struct Nod *creare_nod(int timp){
    struct Nod *nod=(struct Nod *)malloc(sizeof(struct Nod*));

    nod->timp=timp;
    nod->next=NULL;

    return nod;
}

struct Nod *adaugare_sfarsit(struct Nod *head,int timp){
    struct Nod *temp=head;
    struct Nod *nod_nou=creare_nod(timp);

    if(head==NULL){
        head=nod_nou;
        return head;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=nod_nou;

    return head;
}

void afisare(struct Nod *head){
    struct Nod *temp=head;

    while(temp!=NULL){
        printf("%d\n",temp->timp);
        temp=temp->next;
    }
}

void test2(struct Nod *head){
    struct Nod *temp=head;
    float suma=0.00;
    int nr=0;

    while(temp!=NULL){
        suma+=temp->timp;
        nr++;
        temp=temp->next;
    }

    printf("%.2f",suma/nr);
}

void test3(struct Nod *head){
    int vect[100];
    int nr=0;
    struct Nod *temp=head;

    while(temp!=NULL){
        vect[nr++]=temp->timp;
        temp=temp->next;
    }

    for(int i=0;i<nr-1;i++){
        for(int j=i+1;j<nr;j++){
            if(vect[i]>vect[j]){
                int aux=vect[i];
                vect[i]=vect[j];
                vect[j]=aux;
            }
        }
    }

    int contor=0;
    temp=head;

    while(temp!=NULL&&contor<4){
        for(int i=0;i<4;i++){
            if(temp->timp==vect[i]){
                printf("%d\n",temp->timp);
                contor++;
                break;
            }
        }
        temp=temp->next;
    }

}

void test4(struct Nod *head){

   while(head->next!=NULL){
    struct Nod *temp=head;
    struct Nod *max=head;
    struct Nod *prev=NULL;
    struct Nod *max_prev=NULL;

    while(temp->next!=NULL){
        if(temp->next->timp>max->timp){
            max=temp->next;
            max_prev=temp;
        }
        temp=temp->next;
    }
    printf("%d\n",max->timp);
    if(max==head){
        head=head->next;
        free(max);
    }
    else{max_prev->next=max->next;
    free(max);}
   }
}


int main(){
    int test;
    scanf("%d",&test);
    int timp;
    struct Nod *lista=NULL;

    while(scanf("%d",&timp)!=EOF){
        lista=adaugare_sfarsit(lista,timp);
    }

    switch(test){
        case 1:
        afisare(lista);
        break;
        case 2:
        test2(lista);
        break;
        case 3:
        test3(lista);
        break;
        case 4:
        test4(lista);
        break;

    }
}

