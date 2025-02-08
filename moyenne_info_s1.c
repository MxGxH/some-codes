#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
char answer[4];
double analyse,algebra,ALGO,STRM,LE,TCE,MP;
    printf("Hello CS student do you want to calculate your Grade?\n");
    printf("answer with yes or no: ");
    scanf("%4s",answer);
    if(strcmp(answer,"yes")==0) {
        printf("Eneter your analyse grade");
        scanf("%lf",&analyse);
        printf("Eneter your algebra grade");
        scanf("%lf",&algebra);
        printf("Eneter your ALGO grade");
        scanf("%lf",&ALGO);
        printf("Eneter your STRM grade");
        scanf("%lf",&STRM);
        printf("Eneter your LE grade");
        scanf("%lf",&LE);
        printf("Eneter your TCE grade");
        scanf("%lf",&TCE);
        printf("Eneter your MP grade");
        scanf("%lf",&MP);
        double UNF1=((analyse*4)+(algebra*3))/7;
        double UNF2=((ALGO*4)+(STRM*3))/7;
        double UNM=(LE+TCE)/2;
        double UND=MP;
        double GRADE=(UNF1*7+UNF2*7+UNM*2+UND*2)/18;
        printf("your grade is %.2lf ",GRADE);
    }
    else {
        printf("okay take care");
    }

    return 0;
}