/*****************************************************************//**
 * \file   Funcoes.c
 * \brief  
 * 
 * getch | getche
 * \see http://zobayer.blogspot.com/2010/12/getch-getche-in-gccg.html
 * \author lufer
 * \date   November 2020
 *********************************************************************/

#include <stdio.h>
#include <malloc.h>

#include "Funcoes.h"
/*
//getch | getche em linux
#include <termios.h>
#include <unistd.h>
*/

/**
 * \brief Fun��o que conta os valores pares entre dois limites
 * 
 * \param lInf
 * \param lSup
 * \return N�mero total de pares
 */
int contaPares(int lInf, int lSup) {
    int i=lInf;
    int conta = 0;
    while (i < lSup) {
        if (i % 2 == 0) {
            conta++;
        }
        i++;
    }
    return(conta);
}

#pragma region FUNCOES_INTERACAO

/**
 * \brief Fun��o que apresenta apenas os valores num�ricos �mpares entre dois limites
 *
 * \param inicio
 * \param fim
 */
void mostraImpares(int inicio, int fim) {

    for (int i = inicio; i <= fim; i++)
    {
        if (i % 2 != 0)
            printf("%d\n", i);
    }
}

/**
 * Fun��o para ler uma password de N caracteres
 *
 * \param maxChars
 * \return
 */
char* lePassword(int maxChars) {
    char* pass = (char*)malloc(sizeof(char) * maxChars);
    char op;
    int i = 0;

    while (((op = getch()) != '\r') && (i < maxChars)) {
        putchar('*');
        //*(pass+i) = op;
        //i++;
        pass[i++] = op;
    }
    pass[i] = '\0';
    return pass;
}

/**
 * \brief Fun��o que apresenta os valores num�ricos entre dois limites
 *
 * \param inico
 * \param fim
 */
void mostraTudo(int inicio, int fim) {
    for (int i = inicio; i <= fim; i++) {
        printf("%d\n", i);
    }
}

/**
 * Apresenta um conjunto de op��es de menu.
 * 
 */
void menu() {
    puts("[0] - Sair");
    puts("[1] - Mostra Todos os valores");
    puts("[2] - Mostra apenas �mpares");
    puts("[3] - Conta valores pares");
    puts("[4] - Ler password");
}

/**
 * Ler um caracter validado
 * 
 * \param inf
 * \param sup
 * \return 
 */
char leOpcao(char inf, char sup) {
    char op = '0';
    //while (((op = getch()) < inf) || (op > sup));

    while (op < inf || op>sup) {
        op = getche();

    }
    return op;
}
#pragma endregion

#pragma region getchLINUX
///* reads from keypress, echoes */
//int getche(void)
//{
//    struct termios oldattr, newattr;
//    int ch;
//    tcgetattr(STDIN_FILENO, &oldattr);
//    newattr = oldattr;
//    newattr.c_lflag &= ~(ICANON);
//    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
//    ch = getchar();
//    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
//    return ch;
//}
//
///* reads from keypress, doesn't echo */
//int getch(void)
//{
//    struct termios oldattr, newattr;
//    int ch;
//    tcgetattr(STDIN_FILENO, &oldattr);
//    newattr = oldattr;
//    newattr.c_lflag &= ~(ICANON | ECHO);
//    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
//    ch = getchar();
//    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
//    return ch;
//}
#pragma endregion