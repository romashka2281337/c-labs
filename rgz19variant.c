#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Функция для проверки, является ли строка палиндромом
int is_palindrome(char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Не палиндром
        }
    }
    return 1; // Палиндром
}

// Функция для удаления пробелов и знаков препинания из строки
char *preprocess_text(char *text) {
    int i, j = 0;
    for (i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            text[j++] = tolower(text[i]);
        }
    }
    text[j] = '\0';
    return text;
}

// Функция для поиска всех палиндромов в строке
void find_palindromes(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            if (is_palindrome(text + i, j - i)) {
                printf("%.*s\n", j - i, text + i);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    // Выделяем память для текста
    char *text = (char *)malloc(MAX_LENGTH * sizeof(char));
    if (text == NULL) {
        printf("Ошибка выделения памяти.\n");
        fclose(file);
        return 1;
    }

    // Считываем текст из файла
    if (fgets(text, MAX_LENGTH, file) == NULL) {
        printf("Ошибка чтения из файла.\n");
        fclose(file);
        free(text);
        return 1;
    }

    // Предварительная обработка текста
    text = preprocess_text(text);

    // Находим палиндромы в тексте и выводим их
    printf("Найденные палиндромы:\n");
    find_palindromes(text);

    fclose(file);
    free(text);
    return 0;
}