#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define N 100

void buscar_substring(char _string_DNIs[N][9+1]);
void buscar_letra(char _string_DNIs[N][9+1]);
void print_menu ();
void print_strings_DNIs(char string_DNIs[N][9+1]);
void rand_strings_DNIs(char string_DNIs[N][9+1]);
void rand_str_DNI(char str_DNI[9+1]);

void buscar_substring(char _string_DNIs[N][9+1]) {
    printf("\nSubstring a buscar ? ");
    char substring[9+1];
    scanf("%s", substring);

    int found = 0;
    for (int i = 0; i < N; i++) {
        if(strstr(_string_DNIs[i], substring) != NULL) {
            printf("> %s", _string_DNIs[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Not found");
    }
}

void buscar_letra(char _string_DNIs[N][9+1]) {
    printf("\nLetra a buscar? ");
    char letra;
    letra = getch();
    while(getchar() != '\n');

    int found = 0;
    for (int i = 0; i < N; i++) {
        if (_string_DNIs[i][8] == letra) {
            printf("> %s ", _string_DNIs[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Not found");
    }

}

void print_strings_DNIs(char string_DNIs[N][9+1]) {
    for (int i = 0; i < N; i++) {
        printf(" %s", string_DNIs[i]);
    }
}


void rand_strs_DNI(char string_DNIs[N][9+1]) {
    for (int i = 0; i < N; i++) {
        rand_str_DNI(string_DNIs[i]);
    }
    print_strings_DNIs(string_DNIs);
}

void print_menu() {
    char string_DNIs[N][9+1];
    rand_strs_DNI(string_DNIs);
    char menu;

    do {
        printf("\n1 buscar letra\n");
        printf("2 buscar substring\n");
        printf("0 END\n");
        menu = getch();
        while(getchar() != '\n');
        if (menu == '1') {
            buscar_letra(string_DNIs);
        }else if (menu == '2') {
            buscar_substring(string_DNIs);
        }
    }while(menu != '0');
}

void rand_str_DNI(char str_DNI[9+1]) {
    int digit = 0, dni_number = 0, rest = 0;
    char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    for (int i = 0; i < 8; i++) {
        digit = rand() % 10;
        str_DNI[i] = '0' + digit;
    }
    dni_number = atoi(str_DNI);
    rest = dni_number % 23;
    str_DNI[8] = letra[rest];
    str_DNI[9] = '\0';
}

int main(void)
{
    srand(time(NULL));
    print_menu();
    return 0;
}
