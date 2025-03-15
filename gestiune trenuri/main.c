#include<stdio.h>
#include<stdlib.h>

struct Tren{
  int id,putere;
  int pasageri[10];
  int total;
};

void citire(struct Tren *trenuri,int n){
    for(int i=0;i<n;i++){
        int s=0;
        scanf("%d%d",&(trenuri+i)->id,&(trenuri+i)->putere);
        for(int j=0;j<10;j++){
            scanf("%d",&(trenuri+i)->pasageri[j]);
            s=s+(trenuri+i)->pasageri[j];
        }
        (trenuri+i)->total=s;
    }
}

void afisare(struct Tren *trenuri,int n){
    for(int i=0;i<n;i++){
        printf("%d\n%d\n",(trenuri+i)->id,(trenuri+i)->putere);
        for(int j=0;j<10;j++){
            printf("%d ",(trenuri+i)->pasageri[j]);
        }
        printf("\n");
    }
}

void test_2(struct Tren *trenuri,int n,int index){
    for(int i=0;i<n;i++){
        if((trenuri+i)->id==index){
            int max_pasageri=0,coborati=0;
            max_pasageri=(trenuri+i)->putere*0.1;
            coborati=(trenuri+i)->total-max_pasageri;

            //printf("%d\n",coborati);

            for(int j=9;j>0;j--){
                if((trenuri+i)->pasageri[j]<=coborati){
                    coborati=coborati-(trenuri+i)->pasageri[j];
                    (trenuri+i)->pasageri[j]=0;
                }
                else {
                    (trenuri+i)->pasageri[j]=(trenuri+i)->pasageri[j]-coborati;
                    coborati=0;
                }
            }

            for(int j=0;j<10;j++){
                printf("%d ",(trenuri+i)->pasageri[j]);
            }
            printf("\n");
        }
    }
}

int test_3(struct Tren *trenuri,int n,int index,int urca){
    for(int i=0;i<n;i++){
        if((trenuri+i)->id==index){
            int max_pasageri=0,coborati=0;
            max_pasageri=(trenuri+i)->putere*0.1;
            int poate=max_pasageri-(trenuri+i)->total;

            int nu_urca=urca-poate;
            printf("%d\n",nu_urca);

            for(int j=0;j<10;j++){
                if((trenuri+i)->pasageri[j]<30&&(30-(trenuri+i)->pasageri[j]<=poate)){
                    poate=poate-(30-(trenuri+i)->pasageri[j]);
                    (trenuri+i)->pasageri[j]=30;
                }
                else if((30-(trenuri+i)->pasageri[j])>poate){
                    (trenuri+i)->pasageri[j]=(trenuri+i)->pasageri[j]+poate;
                    poate=0;
                }
            }
             for(int j=0;j<10;j++){
            printf("%d ",(trenuri+i)->pasageri[j]);
        }
        printf("\n");
        }

    }
}

void test_4(struct Tren *trenuri,int n,int id1,int id2,int nr){
    int nr_copie=nr;
    for(int i=0;i<n;i++){
        if((trenuri+i)->id==id1){

            //printf("%d\n",coborati);

            for(int j=9;j>0;j--){
                if((trenuri+i)->pasageri[j]<=nr){
                    nr=nr-(trenuri+i)->pasageri[j];
                    (trenuri+i)->pasageri[j]=0;
                }
                else {
                    (trenuri+i)->pasageri[j]=(trenuri+i)->pasageri[j]-nr;
                    nr=0;
                }
            }

        }

        if((trenuri+i)->id==id2){
            for(int j=0;j<10;j++){
                if((trenuri+i)->pasageri[j]<30&&(30-(trenuri+i)->pasageri[j]<=nr_copie)){
                    nr_copie=nr_copie-(30-(trenuri+i)->pasageri[j]);
                    (trenuri+i)->pasageri[j]=30;
                }
                else if((30-(trenuri+i)->pasageri[j])>nr_copie){
                    (trenuri+i)->pasageri[j]=(trenuri+i)->pasageri[j]+nr_copie;
                    nr_copie=0;
                }
            }
        }
        printf("%d\n%d\n",(trenuri+i)->id,(trenuri+i)->putere);
        for(int j=0;j<10;j++){
            printf("%d ",(trenuri+i)->pasageri[j]);
        }
        printf("\n");
    }

}

int main(){
    int n;
    scanf("%d",&n);

    struct Tren *trenuri=(struct Tren*)malloc(n*sizeof(struct Tren));

    citire(trenuri,n);

    int test;
    scanf("%d",&test);

    int index;
    int id,nr;
    int i1,i2,nr_temp;
    switch(test){
        case 1:
        afisare(trenuri,n);
        break;
        case 2:
        scanf("%d",&index);
        test_2(trenuri,n,index);
        break;
        case 3:
        scanf("%d%d",&id,&nr);
        test_3(trenuri,n,id,nr);
        break;
        case 4:
        scanf("%d%d%d",&i1,&i2,&nr_temp);
        test_4(trenuri,n,i1,i2,nr_temp);
        break;
    }
}
