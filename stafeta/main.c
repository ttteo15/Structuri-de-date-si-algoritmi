#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Nod{
    char nume1[10],nume2[10];
    float timp;
    struct Nod *next;
};

struct Nod *creare_nod(char *nume1,char *nume2,float timp){

    struct Nod *nod=(struct Nod*)malloc(sizeof(struct Nod));

    strcpy(nod->nume1,nume1);
    strcpy(nod->nume2,nume2);
    nod->timp=timp;

    nod->next=NULL;
    return nod;
}

struct Nod *adaugare_sfarsit(struct Nod *head,char *nume1,char *nume2,float timp){
    struct Nod *temp=head;
    struct Nod *nod_nou=creare_nod(nume1,nume2,timp);

    if(head==NULL){
        head=nod_nou;
        return head;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=nod_nou;
   // nod_nou->next=NULL;

    return head;

}

void afisare(struct Nod *head){
    struct Nod *temp=head;

    while(temp!=NULL){
        printf("%s %s %.2f\n",temp->nume1,temp->nume2,temp->timp);
        temp=temp->next;
    }

}

void test2(struct Nod *head){
    struct Nod *temp=head;
    struct Nod *nod=NULL;
    float min=99.0;

    while(temp!=NULL){
        if(temp->timp<min){
            min=temp->timp;
            nod=temp;
        }
        temp=temp->next;
    }

    printf("%s %s %.2f\n",nod->nume1,nod->nume2,nod->timp);
}

void test3(struct Nod *head,int nr){
    struct Nod *temp1=head;
    struct Nod *temp2=head;

    float medie=0.0;
    float suma=0.0;

    while(temp1!=NULL){
        suma+=temp1->timp;
        temp1=temp1->next;
    }
    medie=suma/nr;

    while(temp2!=NULL){
        if(temp2->timp>=medie){
             printf("%s %s %.2f\n",temp2->nume1,temp2->nume2,temp2->timp);
        }
        temp2=temp2->next;
    }

}

void test4(struct Nod *head){
    while(head!=NULL){
        struct Nod *temp=head;
        struct Nod *min=head;
        struct Nod *prev=NULL;
        struct Nod *min_prev=NULL;

        while(temp->next!=NULL){
            if(temp->next->timp<min->timp){
                min=temp->next;
                min_prev=temp;
            }
            temp=temp->next;
        }

        printf("%s %s %.2f\n",min->nume1,min->nume2,min->timp);
        if(min==head){
            head=head->next;

        }
        else min_prev->next=min->next;
    }

}

void test5(struct Nod *head){
    while(head!=NULL){
        struct Nod *temp=head;
        struct Nod *min=head;
        struct Nod *prev=NULL;
        struct Nod *min_prev=NULL;

        while(temp->next!=NULL){
            if(temp->next->timp<min->timp){
                min=temp->next;
                min_prev=temp;
            }
            temp=temp->next;
        }

        printf("%s ",min->nume1);
        printf("5000 ");
        printf("%s ",min->nume2);
        printf("5000 \n");

        if(min==head){
            head=head->next;
           free(min);
        }
        else {min_prev->next=min->next;
            free(min);
        }
        break;
    }

}


int main(){
    int nr;
    int test;
    scanf("%d",&nr);
    float t;
    char n1[10],n2[10];
    struct Nod *lista=NULL;

    for(int i=0;i<nr;i++){
        scanf("%s%s%f",n1,n2,&t);
        lista=adaugare_sfarsit(lista,n1,n2,t);
    }

    scanf("%d",&test);

    switch(test){
        case 1:
        afisare(lista);
        break;
        case 2:
        test2(lista);
        break;
        case 3:
        test3(lista,nr);
        break;
        case 4:
        test4(lista);
        break;
        case 5:
        test5(lista);
        break;
    }
}



