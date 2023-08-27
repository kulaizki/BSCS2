#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char input[100];
    char *name, *year;
    int sum = 0, n;
    char longest[50] = "";

    printf("Enter n: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; ++i) {
        fgets(input, sizeof(input), stdin);
        name = strtok(input, ",");
        year = strtok(NULL, ",");
        sum += atoi(year);

        if (strlen(name) > strlen(longest)) {
            strcpy(longest, name);
        }
    }

    printf("Longest name: %s\n", longest);
    printf("Average of the birth years: %.1f\n", (float)sum / n);
}