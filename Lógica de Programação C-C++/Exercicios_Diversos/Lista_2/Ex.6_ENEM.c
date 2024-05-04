#include <stdio.h>
#include <stdlib.h>

int main()
{
    float BComum, BProfissionalizante, Redacao, Media;
    float NComum, NProfissionalizante, NRedacao;
    int QtdBComum, QtdBProfissionalizante;
    float Peso_Comum, Peso_Profissionalizante, Peso_Redacao;

    // valor de cada peso por categoria
    Peso_Comum = 5;
    Peso_Profissionalizante = 2.5;
    Peso_Redacao = 2.5;

    //Quantidade de questões da prova
    QtdBComum = 75;
    QtdBProfissionalizante = 25;

    printf("\nDigite a quantidade de acertos na prova Profissionalizante: ?/25 ");
    scanf("%f", &BProfissionalizante);

    printf("\nDigite a quantidade de acertos na prova Comum: ?/75 ");
    scanf("%f", &BComum);

    printf("\nDigite a nota da redacao: ");
    scanf("%f", &Redacao);

    //Cálculo de peso das Provas
    NComum = (((BComum/QtdBComum)*100)*Peso_Comum);
    NProfissionalizante = (((BProfissionalizante/QtdBProfissionalizante)*100)*Peso_Profissionalizante);
    NRedacao = (Redacao*Peso_Redacao)/10;

    //Apresentação das notas com Percentual
    printf("\nNota da prova profissionalizante: %0.2f%%", ((BProfissionalizante/QtdBProfissionalizante)*100));
    printf("\nNota da prova Comum: %0.2f%%",((BComum/QtdBComum)*100));
    printf("\nNota Conjunta Comum e Profissionalizante: %.2f%%", ((BComum+BProfissionalizante)/(QtdBProfissionalizante+QtdBComum))*100);

    //média final
    Media = NComum+NProfissionalizante+NRedacao;

    printf("\n\nSua Media final e: %0.2f\n", Media);

    system("pause");
    return 0;
}