#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  char answer[4];
  printf("Hello do you want to calculate your first semestre grade?\n");
  printf("answer by yes or no:  ");
  scanf("%s",answer);
  if(strcmp(answer,"yes")==0){
    double SI,ARCHI,ALGO,LOGIQUE,MT_num,Proba,anglais;
    printf("enter your SI grade: ");
    scanf("%lf",&SI);
    printf("enter your ARCHI grade: ");
    scanf("%lf",&ARCHI);
    printf("enter your algo grade: ");
    scanf("%lf",&ALGO);
    printf("enter your logique grade: ");
    scanf("%lf",&LOGIQUE);
    printf("enter your methode numerique grade: ");
    scanf("%lf",&MT_num);
    printf("enter your proba grade: ");
    scanf("%lf",&Proba);
    printf("enter your english grade: ");
    scanf("%lf",&anglais);
    double UN1=(SI*3+ARCHI*3+ALGO*3)/9;
    double UN2=(LOGIQUE*3+MT_num*3+Proba*3)/9;
    double Grade=(UN1*9+UN2*9+anglais*2)/20;
    printf("your grade is %.2lf\n",Grade);



  }
  else {
    printf("do you want to calculate the grade of the second semestre grade?\n");
    printf("answer by yes or no:  ");
    scanf("%s",answer);
    if(strcmp(answer,"yes")==0){
      double OOP,BDD,THL,SE,ARCHI2;
      printf("enter your POO grade: ");
      scanf("%lf",&OOP);
      printf("enter your BDD grade: ");
      scanf("%lf",&BDD);
      printf("enter your THL grade: ");
      scanf("%lf",&THL);
      printf("enter your SE grade: ");
      scanf("%lf",&SE);
      printf("enter your ARCHI grade: ");
      scanf("%lf",&ARCHI2);
      double UN1=(THL*3+BDD*3+OOP*3)/9;
      double UN2=(SE*3+ARCHI2*3)/6;
      double Grade=(UN1*9+UN2*6)/15;
      printf("your grade is %.2lf\n",Grade);


    }
    else{
      printf("okay take care");
    }
  }
  return 0;
}