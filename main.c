#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

void buscar_substring(char _string_DNIs[N][9+1]);
void buscar_letra(char _string_DNIs[N][9+1]);
void print_menu ();
void print_strings_DNIs(char string_DNIs[N][9+1]);
void rand_strings_DNIs(char string_DNIs[N][9+1]);
void rand_str_DNI(char str_DNI[9+1]);

void buscar_substring(char _string_DNIs[N][9+1]) {

}

void buscar_letra(char _string_DNIs[N][9+1]) {

}

void print_menu() {
    printf("\n1 buscar letra\n");
    printf("2 buscar substring\n");
    printf("0 END\n");

    char menu, string_DNIs[N][9+1];
    menu = getchar();

    do {
        if (menu == '1') {
            buscar_letra(string_DNIs);
        }else if (menu == '2') {
            buscar_substring(string_DNIs);
        }
    }while(menu == '0');
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
    char string_DNIs[N][9+1];
    rand_strs_DNI(string_DNIs);
    print_menu();
    return 0;
}
