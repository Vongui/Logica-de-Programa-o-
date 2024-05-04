#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Considere um jogo de adivinhação, onde o computador irá sortear um número entre 1 e 100, inclusive,
e você terá que adivinhá-lo. Para adivinhar o número você terá 6 tentativas, sendo que após cada uma
das tentativas, o computador responderá se está frio ou quente, onde quente é que está a uma distância
máxima de 10 e frio quando for maior que isso. O computador também responderá se o número é maior
ou menor que o número digitado por você. O programa deverá apresentar que você foi derrotado
quando você não conseguiu descobrir o número em 6 tentativas e apresentar que você venceu quando
você acertar o número dentro das 6 tentativas.*/
int main()
{
    int numero_secreto, palpite;
    int tentativas = 0;
    int quente;

    srand(time(NULL));

    numero_secreto = rand() % 100 + 1;

    printf("Vamos brincar de adivinhacao!\n");
    printf("Adivinhe o numero entre 1 e 100.\n");

    do {
        printf("Digite o seu palpite: ");
        scanf("%d", &palpite);

        tentativas++;

        if (palpite == numero_secreto) {
            printf("Congratulations, voce acertou o numero em %d tentativas!\n", tentativas);
            return 0;
        } else {
            if (tentativas == 6) {
                printf("Voce foi derrotado! O numero secreto era: %d\n", numero_secreto);
            } 
            else {
                printf("Errado! ");

                if (palpite < numero_secreto) {
                    printf("Tente um numero maior.\n");
                } else {
                    printf("Tente um numero menor.\n");
                }

                quente = (palpite - numero_secreto) * (palpite - numero_secreto);
                if (quente <= 10 * 10) {
                    printf("Esta quente!\n");
                } else {
                    printf("Esta frio!\n");
                }
            }
        }
    } while (tentativas < 6);

    system("pause");
    return 0;
}
