#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include "funciones.h"

#define COLOR_NEGRO 0
#define COLOR_AZUL 1
#define COLOR_VERDE 2
#define COLOR_CELESTE 3
#define COLOR_ROJO 4
#define COLOR_BLANCO 15

void imprimirCalculadora(int primerOperando, float operando1, float operando2, int operador);
void setPressNumber(int primerOperando, float *operando1, float *operando2, float n);
float addDigitToNumber(float n, float a);
void printChar(char c, int a);
void setColor(int background, int text);


int main()
{
    float operando1 = 0;
    float operando2 = 0;
    int primerOperando = 1;
    int operador = 0;
    int key = 0;

    do{
        system("cls");
        imprimirCalculadora(primerOperando, operando1, operando2, operador);
        key = getch();

        switch(key) {
            //operadores
            case 8: operando1 = 0; primerOperando = 1; break;//borrar
            case 43: operador = 1; primerOperando = 0; break;//suma
            case 45: operador = 2; primerOperando = 0; break;//resta
            case 42: operador = 3; primerOperando = 0; break;//multi
            case 47: operador = 4; primerOperando = 0; break;//division
            case 33: operando1 = factorial(operando1); primerOperando = 1; operador = 0;break;//factorial
            case 13:
            case 61:
                switch(operador) {
                    case 1: operando1 = suma(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                    case 2: operando1 = resta(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                    case 3: operando1 = multiplicacion(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                    case 4: operando1 = division(operando1, operando2); operando2 = 0; primerOperando = 1; break;
                }
                break;//igual o enter

            //numeros
            case 48: setPressNumber(primerOperando, &operando1, &operando2, 0); break;//numero 1
            case 49: setPressNumber(primerOperando, &operando1, &operando2, 1); break;//numero 2
            case 50: setPressNumber(primerOperando, &operando1, &operando2, 2); break;//numero 3
            case 51: setPressNumber(primerOperando, &operando1, &operando2, 3); break;//numero 4
            case 52: setPressNumber(primerOperando, &operando1, &operando2, 4); break;//numero 5
            case 53: setPressNumber(primerOperando, &operando1, &operando2, 5); break;//numero 6
            case 54: setPressNumber(primerOperando, &operando1, &operando2, 6); break;//numero 7
            case 55: setPressNumber(primerOperando, &operando1, &operando2, 7); break;//numero 8
            case 56: setPressNumber(primerOperando, &operando1, &operando2, 8); break;//numero 9
            case 57: setPressNumber(primerOperando, &operando1, &operando2, 9); break;//numero 10
        }
    } while(key != 27);

    return 0;
}

void setPressNumber(int primerOperando, float *operando1, float *operando2, float n) {
    if(primerOperando == 1) {
        *operando1 = addDigitToNumber(*operando1, n);
    } else {
        *operando2 = addDigitToNumber(*operando2, n);
    }
}

float addDigitToNumber(float n, float a) {
    if(n > 0) {
        char c[43] = "";
        sprintf(c, "%ld", (long)n);
        if(strlen(c) < 7) {
            return n * 10+ a;
        } else {
            return n;
        }
    } else {
        return a;
    }
}

void imprimirCalculadora(int primerOperando, float operando1, float operando2, int operador) {

    //linea de inicio
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",218);
    printChar(196, 43);
    printf("%c\n",191);

    //linea operandos ingresados
    printf("%c", 179);
    char ing[43] = "";
    if(primerOperando == 0) {
        char op[5] = {'+','-','*','/','!'};
        sprintf(ing,"%.2f %c %.2f", operando1, op[operador-1], operando2);
    } else {
        sprintf(ing,"%.2f", operando1);
    }
    printf("%43s", ing);
    printf("%c\n", 179);

    //linea operandos
    printf("%c", 179);
    setColor(COLOR_NEGRO, COLOR_BLANCO);
    if(primerOperando == 1) {
        printf("%43.2f", operando1);
    } else {
        printf("%43.2f", operando2);
    }

    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c\n", 179);

    printf("%c",195);
    printChar(196, 43);
    printf("%c\n",180);

    //operandos  + - / * ! =

    printf("%c", 179);
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '+');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '-');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '*');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '/');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_VERDE, COLOR_BLANCO);
    printf("  %c  ", '!');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_CELESTE, COLOR_BLANCO);
    printf("  %c  ", '=');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf("%c",32);
    setColor(COLOR_ROJO, COLOR_BLANCO);
    printf("  %c  ", '<');
    setColor(COLOR_AZUL, COLOR_BLANCO);
    printf(" %c\n", 179);

    //linea de fin
    printf("%c",192);
    printChar(196, 43);
    printf("%c\n",217);

    setColor(COLOR_NEGRO, COLOR_BLANCO);
}

void setColor(int background, int text){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int ncolor = text + (background * 16);
    SetConsoleTextAttribute(console, ncolor);
}

void printChar(char c, int a) {
    for(int i=0;i<a;i++) {
        printf("%c", c);
    }
}
