#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char FN[24];
    char MI;
    char LN[16]; 
} Nametype;

typedef struct {
    Nametype name;
    int ID;
    char course[8]; 
    int yrLevel;
} Studtype;

void displayHeader();
void displayStudent(Studtype S);
void readFile();

int main() {

    readFile();
}

void displayHeader() {
    printf("\n\n");
    printf("%-10s", "ID No.");
    printf("%-16s", "Lastname");
    printf("%-24s", "Firstname");
    printf("%-3s", "MI");
    printf("%-8s", "Course");
    printf("%5s", "Year");
    printf("\n");
    printf("%-10s", "======");
    printf("%-16s", "========");
    printf("%-24s", "=========");
    printf("%-3s", "==");
    printf("%-8s", "======");
    printf("%5s", "====");
}

void displayStudent(Studtype S) {
    printf("\n%-10d", S.ID);
    printf("%-16s %-24s %-3c", S.name.LN, S.name.FN, S.name.MI);
    printf("%-8s", S.course);
    printf("%-5d", S.yrLevel);
}

void readFile() {

    char fileName[256];
    
    printf("Enter file name: ");
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "rb");

    if (fp != NULL) {
        displayHeader();
        Studtype buffer;
        while (fread(&buffer, sizeof(Studtype), 1, fp)) {
            displayStudent(buffer);
        }
    }

    fclose(fp);
}
