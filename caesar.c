#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Argumento ausente \n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit(argv[1][i])) {
            printf("COÉ MALUCO, TÁ TENTANDO INVADIR?\n |só aceito inteiro positivo|\n");
            printf(" ./caesar key\n");
            return 1;
        }
    }

    int numero = atoi(argv[1]);

    if (numero <= 0) {
        printf("manda um numero positivo que até vai...\n");
        return 1;
    }

    printf("Numero: %i!\n", numero);

    string word;
    string resultado;

    do {
        int escolha = get_int("O que você quer fazer?\n 1 - Criptografar \n 2 - Descriptografar\n");
        word = get_string("Palavra: ");

        if (escolha == 1) {
            // Criptografar
            resultado = malloc(strlen(word) + 1);
            if (resultado == NULL) {
                return 1;
            }

            for (int i = 0; word[i] != '\0'; i++) {
                resultado[i] = word[i] + numero;
            }

            resultado[strlen(word)] = '\0';

            printf("Palavra criptografada: %s\n", resultado);
            free(resultado);
        } else if (escolha == 2) {
            // Descriptografar
            resultado = malloc(strlen(word) + 1);
            if (resultado == NULL) {
                return 1;
            }

            for (int i = 0; word[i] != '\0'; i++) {
                resultado[i] = word[i] - numero;
            }

            resultado[strlen(word)] = '\0';

            printf("Palavra descriptografada: %s\n", resultado);
            free(resultado);
        } else {
            printf("Opção inválida. encerrando o sistema.\n");
            break;
        }

    } while (1);



     printf("-------------------------------------\n");
        printf("| Autor: Guilherme Freitas de Souza \n");
        printf("| GitHub: @Guilhermefrsz\n");
        printf("| Insta: @guilhermefrsz\n");
        printf("| DATA DE CRIAÇÃO: 10/01/2024\n\n");

    return 0;
}
