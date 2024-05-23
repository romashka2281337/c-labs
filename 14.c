#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("text.txt", "w");

    if (file == NULL) {
        printf("Ошибка при создании файла.");
        return 1;
    }

    char str[100];

    printf("Enter the text to write to the file (enter an empty line to complete):\n");

    do {
        fgets(str, 100, stdin);

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == ' ') {
                fputc('.', file);
            }
            fputc(str[i], file);
        }

    } while (str[0] != '\n');

    fclose(file);

    printf("The text has been successfully written to the file.\n");

    return 0;
}
