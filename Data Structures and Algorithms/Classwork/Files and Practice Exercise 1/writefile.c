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

int main() {

    Studtype students[3] = {
        {{"Kaikhosru", 'X', "Sorabji"}, 1, "BSCS", 4},
        {{"Kaikhosru", 'X', "Sorabji"}, 2, "BSCS", 4},
        {{"Kaikhosru", 'X', "Sorabji"}, 3, "BSCS", 4},
    };

    FILE *fp = fopen("./students.dat", "wb");

    if (fp != NULL) {
        for (int i = 0; i < 3; ++i) {
            fwrite(&students[i], sizeof(Studtype), 1, fp);
        }     
    }

    fclose(fp);
}
