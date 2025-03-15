#include<stdio.h>
#include<stdlib.h>

struct Jucator{
  char nume[20];
  int x,y;
  int total[7];
  int chinta[5];
  int punctaj;
};

void citire(struct Jucator *juc,int n,int *vect){
    for(int i=0;i<n;i++){
    scanf("%s %d %d",(juc+i)->nume,&(juc+i)->x,&(juc+i)->y);
    }
    for(int i=0;i<5;i++){
        scanf("%d",&vect[i]);

    }


    for(int i=0;i<n;i++){

        for(int j=0;j<5;j++){
            (juc+i)->total[j]=vect[j];
        }
        (juc+i)->total[5]=(juc+i)->x;
        (juc+i)->total[6]=(juc+i)->y;
    }

}

void afisare(struct Jucator *juc,int n,int *vect){
    for(int i=0;i<n;i++){
        printf("%s\n%d %d \n",(juc+i)->nume,(juc+i)->x,(juc+i)->y);
    }
    for(int i=0;i<5;i++){
        printf("%d ",vect[i]);
    }
    printf("\n");


}

void ordonare(struct Jucator *juc){

    for(int i=0;i<6;i++){
        for(int j=i+1;j<7;j++){
          if(juc->total[i]>juc->total[j]){
              int temp=juc->total[i];
              juc->total[i]=juc->total[j];
              juc->total[j]=temp;
          }
        }

    }

}

void test_2(struct Jucator *juc,int n){

    for(int i=0;i<n;i++){
        int nr=1;
        ordonare(juc+i);


        for(int j=0;j<6;j++){
            if(((juc+i)->total[j]-(juc+i)->total[j+1])==-1){
                nr++;
                (juc+i)->chinta[j]=(juc+i)->total[j];
                (juc+i)->chinta[j+1]=(juc+i)->total[j+1];
                }

                }
               // printf("%d ",nr);

            //printf("\n");

        if(nr==5){
            printf("%s\n",(juc+i)->nume);
            for(int k=0;k<5;k++){

                printf("%d ",(juc+i)->chinta[k]);
            }
            printf("\n");
        }
    }

}

void test_3(struct Jucator *jucatori,int n){
    int frecv[15];

    for(int i=0;i<n;i++){
        int nr=0;
        ordonare(jucatori+i);
        for(int j=0;j<15;j++){
            frecv[j]=0;
        }

        for(int j=0;j<7;j++){
            frecv[(jucatori+i)->total[j]]++;
        }


      for(int j=1;j<15&&nr<5;j++){
          if(frecv[j]>1){
              for(int k=nr;k<nr+frecv[j];k++){
                  (jucatori+i)->chinta[k]=j;
              }
              nr=nr+frecv[j];
          }
      }

      for(int j=14;j>1&&nr<5;j--){
          if(frecv[j]==1){
              (jucatori+i)->chinta[nr]=j;
              nr++;
          }
      }

      for(int x=0;x<4;x++){
          for(int y=x+1;y<5;y++){
              if((jucatori+i)->chinta[x]>(jucatori+i)->chinta[y]){
                  int temp=(jucatori+i)->chinta[x];
                  (jucatori+i)->chinta[x]=(jucatori+i)->chinta[y];
                  (jucatori+i)->chinta[y]=temp;
              }
          }
      }
    printf("%s\n",(jucatori+i)->nume);
      for(int j=0;j<5;j++){
          printf("%d ",(jucatori+i)->chinta[j]);
      }
       printf("\n");
    }
}

int comparare_jucatori(struct Jucator j1,struct Jucator j2){
    int t1=6,t2=6;
    while(t1>0&&t2>0){
        if(j1.total[t1]>j2.total[t2]){

            return 1;

        }
        else if(j1.total[t1]==j2.total[t2]){
            t1--;
            t2--;
        }
        else return -1;
    }
}

void test_4(struct Jucator *jucatori,int n){
    int frecv[15];

    for(int i=0;i<n;i++){
        int nr=0;
        ordonare(jucatori+i);
        for(int j=0;j<15;j++){
            frecv[j]=0;
        }

        for(int j=0;j<7;j++){
            frecv[(jucatori+i)->total[j]]++;
        }


      for(int j=1;j<15&&nr<5;j++){
          if(frecv[j]>1){
              for(int k=nr;k<nr+frecv[j];k++){
                  (jucatori+i)->chinta[k]=j;
              }
              nr=nr+frecv[j];
          }
      }



      for(int j=14;j>1&&nr<5;j--){
          if(frecv[j]==1){
              (jucatori+i)->chinta[nr]=j;
              nr++;
          }
      }


   (jucatori+i)->punctaj=0;

        for(int j=0;j<15;j++){
            if(frecv[j]==2){
                (jucatori+i)->punctaj=(jucatori+i)->punctaj+1;
            }
            else if(frecv[j]==3){
                (jucatori+i)->punctaj=(jucatori+i)->punctaj+3;
            }
        }


    }
      for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if((jucatori+i)->punctaj<(jucatori+j)->punctaj){
                struct Jucator temp=jucatori[i];
                jucatori[i]=jucatori[j];
                jucatori[j]=temp;
                }
            }
        }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n&&((jucatori+i)->punctaj==(jucatori+j)->punctaj);j++){
            if(comparare_jucatori(*(jucatori+i),*(jucatori+j))==-1){
                struct Jucator temp=jucatori[i];
                jucatori[i]=jucatori[j];
                jucatori[j]=temp;
            }
        }
    }
for(int i=0;i<n;i++){
    printf("%s\n",(jucatori+i)->nume);
}
}

int main(){
    int n;
    scanf("%d",&n);

    struct Jucator *jucatori;
    jucatori=(struct Jucator*)malloc(n*sizeof(struct Jucator));

    int vect[5];

    citire(jucatori,n,vect);

    int test;
    scanf("%d",&test);



    switch(test){
        case 1:
        afisare(jucatori,n,vect);
        break;
        case 2:
        test_2(jucatori,n);
        break;
        case 3:
        test_3(jucatori,n);
        break;
        case 4:
        test_4(jucatori,n);
    }

}
