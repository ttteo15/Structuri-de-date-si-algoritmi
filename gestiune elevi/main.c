#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Elev{
  char nume[20];
  char cod[20];
  int note[9];
  int medie;
  //char cod_verificare[20];
};


void citire(struct Elev *elevi,int nr_elevi){
    for(int i=0;i<nr_elevi;i++){
        (elevi+i)->medie=-1;
        float s=0.00;
        scanf("%s %s",(elevi+i)->nume,(elevi+i)->cod);
        for(int j=0;j<9;j++){
            scanf("%d",&(elevi+i)->note[j]);
            s=s+(elevi+i)->note[j];
        }
        (elevi+i)->medie=(float)s/9;
    }
}

void afisare(struct Elev *elevi,int nr_elevi){
     for(int i=0;i<nr_elevi;i++){
        printf("%s\n%s\n",(elevi+i)->nume,(elevi+i)->cod);
        for(int j=0;j<9;j++){
            printf("%d ",(elevi+i)->note[j]);
        }
        printf("\n");
    }
}

void medie(struct Elev *elevi,int nr_elevi){

    int max=-1,x=0;
    for(int i=0;i<nr_elevi;i++){
        if((elevi+i)->medie>max){
            max=(elevi+i)->medie;
            x=i;
        }
    }

    printf("%s\n",(elevi+x)->nume);

}

void test_3(struct Elev *elevi,int nr_elevi){
    for(int i=0;i<nr_elevi;i++){
        if((elevi+i)->medie<6){
            printf("%s\n",(elevi+i)->nume);
        }
    }
}

void ordonare(struct Elev *elev){
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            if(elev->note[i]>elev->note[j]){
                int temp=elev->note[i];
                elev->note[i]=elev->note[j];
                elev->note[j]=temp;
            }
        }
    }

        //for(int j=0;j<9;j++){
        //    printf("%d ",elev->note[j]);
        //}

    printf("\n");
}

void test_4(struct Elev *elevi,int nr_elevi,char *cod_verificare){

    for(int i=0;i<nr_elevi;i++){
        ordonare(elevi+i);
       if(strcmp(cod_verificare,(elevi+i)->cod)==0){
            //for(int j=0;j<9;j++){
            int y=4;

            printf("%d\n",(elevi+i)->note[y]);
            break;
           // }

        }
    }




    /*for(int i=0;i<nr_elevi;i++){
        for(int j=0;j<9;j++){
            printf("%d ",(elevi+i)->note[j]);
        }
        printf("\n");
    }*/

}


int main(){
    int nr_elevi;
    scanf("%d",&nr_elevi);

    struct Elev *elevi;
    elevi=(struct Elev*)malloc(nr_elevi*sizeof(struct Elev));

    int test;
    citire(elevi,nr_elevi);
    scanf("%d",&test);
    char cod_verificare[20];
    switch(test){
        case 1:
        afisare(elevi,nr_elevi);
        break;
        case 2:
        medie(elevi,nr_elevi);
        break;
        case 3:
        test_3(elevi,nr_elevi);
        break;
        case 4:

        scanf("%s",cod_verificare);
        test_4(elevi,nr_elevi,cod_verificare);


        break;
    }

}
