#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct modules1 {
    char subject[50];
    double grade;
    int coeff;
    int credit;
};

struct modules2 {
    char subject[50];
    double grade;
    int coeff;
    int credit;
};

struct s1_mc {
    int credit;
    double grade;
};

struct s2_mc {
    int credit;
    double grade;
};

void creatmod(struct modules1 modules[], int num_sbj) {
    for (int i = 0; i < num_sbj; i++) {
        printf("Enter the name of subject %d: ", i + 1);
        scanf("%s", modules[i].subject);
        do {
            printf("Enter the grade for %s: ", modules[i].subject);
            scanf("%lf", &modules[i].grade);
        } while (modules[i].grade < 0 || modules[i].grade > 20);
        printf("Enter the coefficient of %s: ", modules[i].subject);
        scanf("%d", &modules[i].coeff);
        printf("Enter the credit of %s: ", modules[i].subject);
        scanf("%d", &modules[i].credit);
    }
}

void createmod2(struct modules2 modules[], int num_sbj2) {
    for (int i = 0; i < num_sbj2; i++) {
        printf("Enter the name of subject %d: ", i + 1);
        scanf("%s", modules[i].subject);
        do {
            printf("Enter the grade for %s: ", modules[i].subject);
            scanf("%lf", &modules[i].grade);
        } while (modules[i].grade < 0 || modules[i].grade > 20);
        printf("Enter the coefficient of %s: ", modules[i].subject);
        scanf("%d", &modules[i].coeff);
        printf("Enter the credit of %s: ", modules[i].subject);
        scanf("%d", &modules[i].credit);
    }
}

void calcule_moys1(struct modules1 modules[], int num_sbj, struct s1_mc gd[]) {
    int j = 0;
    double total = 0;
    double tcf = 0;
    gd[0].credit = 0;
    for (j = 0; j < num_sbj; j++) {
        total += (modules[j].grade) * (modules[j].coeff);
        tcf += (modules[j].coeff);
        if (modules[j].grade >= 10) { // Only add credits if grade is 10 or above
            gd[0].credit += (modules[j].credit);
        }
    }
    gd[0].grade = (total / tcf);
    if ((gd[0].grade) >= 10) {
        gd[0].credit = 30; // Set total credits to 30 if average is 10 or above
    }
    printf("Your first semester grade is %.2f and credits %d \n", gd[0].grade, gd[0].credit);
}

void calcule_moys2(struct modules2 modules[], int num_sbj, struct s2_mc gd[]) {
    int j = 0;
    double total = 0;
    double tcf = 0;
    gd[0].credit = 0;
    for (j = 0; j < num_sbj; j++) {
        total += (modules[j].grade) * (modules[j].coeff);
        tcf += (modules[j].coeff);
        if (modules[j].grade >= 10) { // Only add credits if grade is 10 or above
            gd[0].credit += (modules[j].credit);
        }
    }
    gd[0].grade = (total / tcf);
    if ((gd[0].grade) >= 10) {
        gd[0].credit = 30; // Set total credits to 30 if average is 10 or above
    }
    printf("Your second semester grade: %.2f and credits %d \n", gd[0].grade, gd[0].credit);
}

void updateGrades1(struct modules1 modules[], int num_sbj, float threshold) {
    for (int i = 0; i < num_sbj; i++) {
        if (modules[i].grade < threshold) {
            printf("Updating grade for %s (current grade: %.2lf)\n", modules[i].subject, modules[i].grade);
            printf("Enter new grade for %s: ", modules[i].subject);
            scanf("%lf", &modules[i].grade);
        }
    }
}

void updateGrades2(struct modules2 modules[], int num_sbj2, float threshold) {
    for (int i = 0; i < num_sbj2; i++) {
        if (modules[i].grade < threshold) {
            printf("Updating grade for %s (current grade: %.2lf)\n", modules[i].subject, modules[i].grade);
            printf("Enter new grade for %s: ", modules[i].subject);
            scanf("%lf", &modules[i].grade);
        }
    }
}

int main() {
    int num_sbj, num_sbj2, min_credit;
    double moy_rachat;
    char answer[8];
    printf("Enter the number of subjects in the first semester: ");
    scanf("%d", &num_sbj);
    printf("Enter the number of subjects in the second semester: ");
    scanf("%d", &num_sbj2);

    // Creation des modules s1 et s2
    struct modules1 modules1[num_sbj];
    struct modules2 modules2[num_sbj2];
    struct s1_mc gd1[1];
    struct s2_mc gd2[1];

    creatmod(modules1, num_sbj);
    calcule_moys1(modules1, num_sbj, gd1);

    createmod2(modules2, num_sbj2);
    calcule_moys2(modules2, num_sbj2, gd2);

    printf("Enter the minimum credit to pass with debts: ");
    scanf("%d", &min_credit);
    printf("Enter the moyenne pour rachat: ");
    scanf("%lf", &moy_rachat);

    if (((gd1[0].grade + gd2[0].grade) / 2) >= 10.00) {
        printf("Your grade is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
        printf("Admis(e) session normal\n");
    } else {
        printf("Your grade is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
        printf("YOU NEED TO RETAKE EXAMS TO PASS OR WITH CREDITS\n");
        printf("Do you want to pass with credits? (yes/no): ");
        scanf("%s", answer);

        if (strcmp(answer, "yes") == 0 || strcmp(answer, "YES") == 0) {
            if (gd1[0].credit + gd2[0].credit >= min_credit) {
                printf("Admis(e) avec dettes\n");
            } else {
                printf("YOU MUST RETAKE EXAMS TO PASS\n");
                if (gd1[0].grade < 10 && gd2[0].grade < 10) {
                    updateGrades1(modules1, num_sbj, 10.0);
                    updateGrades2(modules2, num_sbj2, 10.0);
                    calcule_moys1(modules1, num_sbj, gd1);
                    calcule_moys2(modules2, num_sbj2, gd2);
                    printf("Your grade after retaking the exams is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
                    if ((gd1[0].grade + gd2[0].grade) / 2 >= 10.00) {
                        printf("Admis(e) avec rattrapage\n");
                    } else if ((gd1[0].grade + gd2[0].grade) / 2 >= moy_rachat) {
                        printf("Admis(e) avec rachat\n");
                    } else if (gd1[0].credit + gd2[0].credit >= min_credit) {
                        printf("Admis(e) avec dettes\n");
                    } else {
                        printf("Ajourné\n");
                    }
                } else if (gd2[0].grade < 10 && gd1[0].grade >= 10) {
                    updateGrades2(modules2, num_sbj2, 10.0);
                    calcule_moys2(modules2, num_sbj2, gd2);
                    printf("Your grade after retaking the exams is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
                    if ((gd1[0].grade + gd2[0].grade) / 2 >= 10.00) {
                        printf("Admis(e) avec rattrapage\n");
                    } else if ((gd1[0].grade + gd2[0].grade) / 2 >= moy_rachat) {
                        printf("Admis(e) avec rachat\n");
                    } else if (gd1[0].credit + gd2[0].credit >= min_credit) {
                        printf("Admis(e) avec dettes\n");
                    } else {
                        printf("Ajourné\n");
                    }
                } else {
                    updateGrades1(modules1, num_sbj, 10.0);
                    calcule_moys1(modules1, num_sbj, gd1);
                    printf("Your grade after retaking the exams is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
                    if ((gd1[0].grade + gd2[0].grade) / 2 >= 10.00) {
                        printf("Admis(e) avec rattrapage\n");
                    } else if ((gd1[0].grade + gd2[0].grade) / 2 >= moy_rachat) {
                        printf("Admis(e) avec rachat\n");
                    } else if (gd1[0].credit + gd2[0].credit >= min_credit) {
                        printf("Admis(e) avec dettes\n");
                    } else {
                        printf("Ajourné\n");
                    }
                }
            }
        } else {
            printf("YOU MUST RETAKE EXAMS TO PASS\n");
            if (gd1[0].grade < 10 && gd2[0].grade < 10) {
                updateGrades1(modules1, num_sbj, 10.0);
                updateGrades2(modules2, num_sbj2, 10.0);
                calcule_moys1(modules1, num_sbj, gd1);
                calcule_moys2(modules2, num_sbj2, gd2);
                printf("Your grade after retaking the exams is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
                if ((gd1[0].grade + gd2[0].grade) / 2 >= 10.00) {
                    printf("Admis(e) avec rattrapage\n");
                } else if ((gd1[0].grade + gd2[0].grade) / 2 >= moy_rachat) {
                    printf("Admis(e) avec rachat\n");
                } else if (gd1[0].credit + gd2[0].credit >= min_credit) {
                    printf("Admis(e) avec dettes\n");
                } else {
                    printf("Ajourné\n");
                }
            } else if (gd2[0].grade < 10 && gd1[0].grade >= 10) {
                updateGrades2(modules2, num_sbj2, 10.0);
                calcule_moys2(modules2, num_sbj2, gd2);
                printf("Your grade after retaking the exams is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
                if ((gd1[0].grade + gd2[0].grade) / 2 >= 10.00) {
                    printf("Admis(e) avec rattrapage\n");
                } else if ((gd1[0].grade + gd2[0].grade) / 2 >= moy_rachat) {
                    printf("Admis(e) avec rachat\n");
                } else if (gd1[0].credit + gd2[0].credit >= min_credit) {
                    printf("Admis(e) avec dettes\n");
                } else {
                    printf("Ajourné\n");
                }
            } else {
                updateGrades1(modules1, num_sbj, 10.0);
                calcule_moys1(modules1, num_sbj, gd1);
                printf("Your grade after retaking the exams is %.2lf and credit is %d \n", (gd1[0].grade + gd2[0].grade) / 2, gd1[0].credit + gd2[0].credit);
                if ((gd1[0].grade + gd2[0].grade) / 2 >= 10.00) {
                    printf("Admis(e) avec rattrapage\n");
                } else if ((gd1[0].grade + gd2[0].grade) / 2 >= moy_rachat) {
                    printf("Admis(e) avec rachat\n");
                } else if (gd1[0].credit + gd2[0].credit >= min_credit) {
                    printf("Admis(e) avec dettes\n");
                } else {
                    printf("Ajourné\n");
                }
            }
        }
    }

    return 0;
}