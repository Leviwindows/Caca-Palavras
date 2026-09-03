#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

main() {
    srand(time(NULL));
    int x, y, i;
    int palpite_linha, palpite_coluna;
    char tabela[8][8];
    char palavra[4];


    printf("Digite uma palavra de exatamente 3 letras: ");
    scanf("%s", palavra);

    // sorteia a direção onde 0 é pra horizontal e 1 pra vertical
    int direcao = rand() % 2; //limitado para 0 e 1
    int l_inicial, c_inicial;

    if (direcao == 0) {
        // horizontal com linha livre (0-7), mas com coluna limitada (0-5) pra caber 3 letras
        l_inicial = rand() % 8;
        c_inicial = rand() % 6;
    } else {
        // vertical com linha limitada (0-5), mas com coluna livre (0-7)
        l_inicial = rand() % 6;
        c_inicial = rand() % 8;
    }

    // vai preencher a matriz inteira com letras aleatórias primeiro
    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            tabela[x][y] = 'a' + (rand() % 26);
        }
    }

    // depois irá sobreescrever a posição sorteada com a palavra digitada (sem separar as letras)
    for (i = 0; i < 3; i++) {
        if (direcao == 0) {
            tabela[l_inicial][c_inicial + i] = palavra[i];
        } else {
            tabela[l_inicial + i][c_inicial] = palavra[i];
        }
    }

    printf("\n--- CAÇA PALAVRAS ---\n");
    printf("    0 1 2 3 4 5 6 7\n");
    printf("    ----------------\n");
    
    for (x = 0; x < 8; x++) {
        printf("%d | ", x); // impressão do número da coluna
        for (y = 0; y < 8; y++) {
            printf("%c ", tabela[x][y]);
        }
        printf("\n");
    }
    int acertou_inicio = 0;
    int acertou_fim = 0;

    // 1. Pede o início
    printf("\n--- ONDE COMEÇA A PALAVRA? ---\n");
    printf("Digite a LINHA (0-7): ");
    scanf("%d", &palpite_linha);
    printf("Digite a COLUNA (0-7): ");
    scanf("%d", &palpite_coluna);

    // validador do início exato
    if (palpite_linha == l_inicial && palpite_coluna == c_inicial) {
        acertou_inicio = 1;
    }

    // reaproveita as mesmas variáveis para pedir o fim!
    printf("\n--- ONDE TERMINA A PALAVRA? ---\n");
    printf("Digite a LINHA (0-7): ");
    scanf("%d", &palpite_linha);
    printf("Digite a COLUNA (0-7): ");
    scanf("%d", &palpite_coluna);

    if (direcao == 0) {
        if (palpite_linha == l_inicial && palpite_coluna == c_inicial + 2) {
            acertou_fim = 1;
        }
    } else {
        if (palpite_coluna == c_inicial && palpite_linha == l_inicial + 2) {
            acertou_fim = 1;
        }
    }

    if (acertou_inicio && acertou_fim) {
        printf("\nUhuuuuuu! Voce acertou a faixa inteira da palavra!\n");
    } else {
        if (direcao == 0) {
            printf("\nAkakakaka tu errou. Começava em [%d,%d] e terminava em [%d,%d] (Horizontal).\n", 
                   l_inicial, c_inicial, l_inicial, c_inicial + 2);
        } else {
            printf("\nMds tu errou akakakak! Começava em [%d,%d] e terminava em [%d,%d] (Vertical).\n", 
                   l_inicial, c_inicial, l_inicial + 2, c_inicial);
        }
    }
}