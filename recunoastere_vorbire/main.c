#include<stdio.h>
#include<stdlib.h>

struct Persoana{
  char nume[20];
  int id;
  int esantion[20];
  float putere;
  int dist;
};

void citire(struct Persoana *persoane,int n){
    for(int i=0;i<n;i++){
        int s=0.00;
        scanf("%s %d",(persoane+i)->nume,&(persoane+i)->id);
        for(int j=0;j<20;j++){
            scanf("%d",&(persoane+i)->esantion[j]);
            s=s+((persoane+i)->esantion[j]*(persoane+i)->esantion[j]);


        }
        (persoane+i)->putere=s*0.05;
    }

}

void afisare(struct Persoana *persoane,int n){
    for(int i=0;i<n;i++){
        printf("%s\n%d\n",(persoane+i)->nume,(persoane+i)->id);
        for(int j=0;j<20;j++){
            printf("%d ",(persoane+i)->esantion[j]);
        }
        printf("\n");
    }
}

void test_2(struct Persoana *persoane,int n){
    float max=0.00;
    int x=0;
    for(int i=0;i<n;i++){

            if((persoane+i)->putere>max)
               {
                max=(persoane+i)->putere;
                x=i;}

        //printf("%.2f ",(persoane+i)->putere);
    }

    printf("%s\n",(persoane+x)->nume);
}


void test_3(struct Persoana *persoane,int n,int index){
    for(int i=0;i<n;i++){
        if(index==(persoane+i)->id){
            printf("%s\n",(persoane+i)->nume);
        }
    }
}

void test_4(struct Persoana *persoane,int n,int *vect){

    for(int i=0;i<n;i++){

        for(int j=0;j<20;j++){
            int diferenta=(persoane+i)->esantion[j]-vect[j];
            (persoane+i)->dist=diferenta*diferenta;
        }

    }

    int min=999,x=0;

    for(int i=0;i<n;i++){
        if((persoane+i)->dist<min){
            min=(persoane+i)->dist;
            x=i;
        }
    }
    printf("%s\n",(persoane+x)->nume);

}


int main(){
    int n;
    scanf("%d",&n);

    struct Persoana *persoane;
    persoane=(struct Persoana*)malloc(n*sizeof(struct Persoana));

    citire(persoane,n);

    int test;
    scanf("%d",&test);
    int index;
    int vect[20];
    switch(test){
        case 1:
        afisare(persoane,n);
        break;
        case 2:
        test_2(persoane,n);
        break;
        case 3:
        scanf("%d",&index);
        test_3(persoane,n,index);
        break;
        case 4:
        for(int i=0;i<20;i++){
            scanf("%d",&vect[i]);
        test_4(persoane,n,vect);
        break;

        }
    }

}
