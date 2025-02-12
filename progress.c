#include <stdio.h>
#include <string.h>

void moys1(double *grade, int *credit_1, char rattrapage[][10], int *nbrrt1) {
    double analyse, algebre, mp, strm, algo, Le, TCE;

    printf("Enter the analyse grade: ");
    scanf("%lf", &analyse);
    if (analyse >= 10) {
        *credit_1 += 6;
    } else {
        strcpy(rattrapage[*nbrrt1], "analyse1");
        (*nbrrt1)++;
    }

    printf("Enter the algebre grade: ");
    scanf("%lf", &algebre);
    if (algebre >= 10) {
        *credit_1 += 5;
    } else {
        strcpy(rattrapage[*nbrrt1], "algebre1");
        (*nbrrt1)++;
    }

    printf("Enter the mp grade: ");
    scanf("%lf", &mp);
    if (mp >= 10) {
        *credit_1 += 4;
    } else {
        strcpy(rattrapage[*nbrrt1], "MP");
        (*nbrrt1)++;
    }

    printf("Enter the strm grade: ");
    scanf("%lf", &strm);
    if (strm >= 10) {
        *credit_1 += 5;
    } else {
        strcpy(rattrapage[*nbrrt1], "strm1");
        (*nbrrt1)++;
    }

    printf("Enter the algo grade: ");
    scanf("%lf", &algo);
    if (algo >= 10) {
        *credit_1 += 6;
    } else {
        strcpy(rattrapage[*nbrrt1], "algo1");
        (*nbrrt1)++;
    }

    printf("Enter the LE grade: ");
    scanf("%lf", &Le);
    if (Le >= 10) {
        *credit_1 += 2;
    } else {
        strcpy(rattrapage[*nbrrt1], "LE");
        (*nbrrt1)++;
    }

    printf("Enter the TCE grade: ");
    scanf("%lf", &TCE);
    if (TCE >= 10) {
        *credit_1 += 2;
    } else {
        strcpy(rattrapage[*nbrrt1], "TCE");
        (*nbrrt1)++;
    }

    double UF1 = (analyse * 4 + algebre * 3) / 7;
    double UF2 = (algo * 4 + strm * 3) / 7;
    double UM = (Le + TCE) / 2;

    *grade = (UF1 * 7 + UF2 * 7 + UM * 2 + mp * 2) / 18;

    if (*grade >= 10) {
        *credit_1 = 30;
        *nbrrt1 = 0;
    }

    printf("Your first semester grade is %.2lf and your credit is %d\n", *grade, *credit_1);
}

void moys2(double *grade2, int *credit_2, char rattrapage2[][10], int *nbrrt2) {
    double analyse2, algebre2, elec, strm2, algo2, TIC, OPM, STAT;

    printf("Enter the analyse2 grade: ");
    scanf("%lf", &analyse2);
    if (analyse2 >= 10) {
        *credit_2 += 6;
    } else {
        strcpy(rattrapage2[*nbrrt2], "analyse2");
        (*nbrrt2)++;
    }

    printf("Enter the algebre2 grade: ");
    scanf("%lf", &algebre2);
    if (algebre2 >= 10) {
        *credit_2 += 4;
    } else {
        strcpy(rattrapage2[*nbrrt2], "algebre2");
        (*nbrrt2)++;
    }

    printf("Enter the elec grade: ");
    scanf("%lf", &elec);
    if (elec >= 10) {
        *credit_2 += 3;
    } else {
        strcpy(rattrapage2[*nbrrt2], "elec");
        (*nbrrt2)++;
    }

    printf("Enter the strm2 grade: ");
    scanf("%lf", &strm2);
    if (strm2 >= 10) {
        *credit_2 += 3;
    } else {
        strcpy(rattrapage2[*nbrrt2], "strm2");
        (*nbrrt2)++;
    }

    printf("Enter the algo2 grade: ");
    scanf("%lf", &algo2);
    if (algo2 >= 10) {
        *credit_2 += 6;
    } else {
        strcpy(rattrapage2[*nbrrt2], "algo2");
        (*nbrrt2)++;
    }

    printf("Enter the TIC grade: ");
    scanf("%lf", &TIC);
    if (TIC >= 10) {
        *credit_2 += 2;
    } else {
        strcpy(rattrapage2[*nbrrt2], "TIC");
        (*nbrrt2)++;
    }

    printf("Enter the OPM grade: ");
    scanf("%lf", &OPM);
    if (OPM >= 10) {
        *credit_2 += 2;
    } else {
        strcpy(rattrapage2[*nbrrt2], "OPM");
        (*nbrrt2)++;
    }

    printf("Enter the STAT grade: ");
    scanf("%lf", &STAT);
    if (STAT >= 10) {
        *credit_2 += 4;
    } else {
        strcpy(rattrapage2[*nbrrt2], "STAT");
        (*nbrrt2)++;
    }

    // **Fixed calculation of semester 2 GPA**
    double UF1 = (analyse2 * 3 + algebre2 * 3) / 6;
    double UF2 = (algo2 * 3 + strm2 * 3) / 6;
    double UM = (TIC + OPM + STAT * 2) / 4;

    *grade2 = (UF1 * 6 + UF2 * 6 + UM * 4 + elec * 2) / 18;

    // If semester grade is 10 or above, grant all 30 credits
    if (*grade2 >= 10) {
        *credit_2 = 30;
        *nbrrt2 = 0;
    }

    printf("Your second semester grade is %.2lf and your credit is %d\n", *grade2, *credit_2);
}


int main() {
    double grade1, grade2;
    int credit_1 = 0, credit_2 = 0;
    int nbrrt1 = 0, nbrrt2 = 0;
    char rattrapage[17][10], rattrapage2[17][10];
    char answer[5];

    printf("To calculate the first semester grade, type 'yes': ");
    do {
        printf("\nYour answer: ");
        scanf("%4s", answer);
    } while (strcmp(answer, "yes") != 0);
    moys1(&grade1, &credit_1, rattrapage, &nbrrt1);

    printf("To calculate the second semester grade, type 'yes': ");
    do {
        printf("\nYour answer: ");
        scanf("%4s", answer);
    } while (strcmp(answer, "yes") != 0);
    moys2(&grade2, &credit_2, rattrapage2, &nbrrt2);

    double final_grade = (grade1 + grade2) / 2;
    printf("Your general grade is %.2lf and your total credits are %d\n", final_grade, credit_1 + credit_2);

    if (final_grade >= 10) {
        printf("Admis(e) session normale.\n");
    } else {
        printf("You have retakes:\n");
        for (int i = 0; i < nbrrt1; i++) printf("%s ", rattrapage[i]);
        for (int i = 0; i < nbrrt2; i++) printf("%s ", rattrapage2[i]);
        printf("\n");
    }
    int crd_ad;
    printf("enter the credit to be able to passe for the next year with subjects to take next year: ");
    scanf("%d",&crd_ad);
    printf("do you wanna retake the exames this year or the next years?");
    scanf("%s",answer);
    if (strcmp(answer, "yes") != 0) {
        if ((credit_1+credit_2) >= crd_ad) {
            printf("admise(e) avec dettes.\n");
        }
        else {
            printf("You have to retakes:\n");
        }
    }

    return 0;
}
