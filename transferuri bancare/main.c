*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Nod{
    char sursa[15];
    char dest[15];
    int nr;
    struct Nod *next;
};

struct Nod *creare_nod(char *sursa,char *dest,int nr){
    struct Nod *nod=(struct Nod*)malloc(sizeof(struct Nod));

    strcpy(nod->sursa,sursa);
    strcpy(nod->dest,dest);
    nod->nr=nr;

    nod->next=NULL;

    return nod;

}

struct Nod *adaugare_sfarsit(struct Nod *head,char *sursa,char *dest,int nr){
    struct Nod *temp=head;
    struct Nod *nod_nou=creare_nod(sursa,dest,nr);

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
        printf("%s %s %d\n",temp->sursa,temp->dest,temp->nr);
        temp=temp->next;
    }
}

void test2(struct Nod *head){
    struct Nod *temp=head;
    int suma=0;

    while(temp!=NULL){
        suma=suma+temp->nr;
        temp=temp->next;
    }


    printf("%d\n",suma);
}

void test3(struct Nod *head,char *nume){
   struct Nod *temp=head;

   while(temp!=NULL){
       if(strcmp(temp->sursa,nume)==0)
         printf("%s\n",temp->dest);
        temp=temp->next;
   }
}

void test4(struct Nod *head,char *nume){
    struct Nod *temp=head;

    while(temp!=NULL){
       if(strcmp(temp->sursa,nume)==0){
         printf("%s %s %d\n",temp->sursa,temp->dest,temp->nr);
        nume=temp->dest;

        temp=head;//repornim cautarea de la inceputul listei
        }
        else{
             temp=temp->next;
         }
    }

}

int main(){
    int nr;
    scanf("%d",&nr);
    struct Nod *lista=NULL;
    char s[15],d[15];
    int n;
    for(int i=0;i<nr;i++){
        scanf("%s%s%d",s,d,&n);
        lista=adaugare_sfarsit(lista,s,d,n);
    }

    int test;
    char num[15];
scanf("%d",&test);
char nn[15];

switch(test){
    case 1:
    afisare(lista);
    break;
    case 2:
    test2(lista);
    break;
    case 3:
    scanf("%s",num);
    test3(lista,num);
    break;
    case 4:
    scanf("%s",nn);
    test4(lista,nn);
    break;

}
