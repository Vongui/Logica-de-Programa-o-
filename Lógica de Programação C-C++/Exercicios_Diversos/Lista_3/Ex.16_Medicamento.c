#include <stdio.h>
#include <stdlib.h>
/*Criar um programa que a partir da idade e peso do paciente calcule a dosagem de determinado
medicamento e imprima a receita informando quantas gotas do medicamento o paciente deve tomar
por dose. Considere que o medicamento em questão possui 500 mg por ml, e que cada ml corresponde
a 20 gotas.
• Adultos ou adolescentes desde 12 anos, inclusive, se tiverem peso igual ou acima de 60 quilos
devem tomar 1000 mg; com peso abaixo de 60 quilos devem tomar 875 mg.
• Para crianças e adolescentes abaixo de 12 anos a dosagem é calculada pelo peso corpóreo
conforme a tabela a seguir:
Peso Dosagem
5 kg a 9 kg 125 mg
10 kg a 16 kg 250 mg
17 kg a 24 kg 375 mg
25 kg a 30 kg 500 mg
Acima de 30 kg 750 mg*/
int main()
{
    int Idade;
    float Peso, Dose;

    printf("Digite a idade do paciente: ");
    scanf("%d", &Idade);
    printf("Digite o peso do paciente: ");
    scanf("%f", &Peso);

    //Somente acima de 12 anos
    if (Idade >=12 && Peso >=60)
    {
        Dose = (100*20)/500;
        printf("\nDose do medicamento ....: %.2f Gotas por dose\n", Dose);
    }
    else if (Idade >=12 && Peso <60)
    {
        Dose = (875*20)/500;
        printf("\nDose do medicamento ....: %.2f Gotas por dose\n", Dose);
    }

    //Abaixo de 12 anos; Mudança conforme o peso
    if (Peso >=5 && Peso <=9 && Idade <12)
    {
        Dose = (125*20)/500;
        printf("\nDose do medicamento ....: %.2f Gotas por dose\n", Dose);
    }
    else if (Peso >=10 && Peso <=16 && Idade <12)
    {
        Dose = (250*20)/500;
        printf("\nDose do medicamento ....: %.2f Gotas por dose\n", Dose);
    }
    else if (Peso >=17 && Peso <=24 && Idade <12)
    {
        Dose = (375*20)/500;
        printf("\nDose do medicamento ....: %.2f Gotas por dose\n", Dose);
    }
    else if (Peso >=25 && Peso <=30 && Idade <12)
    {
        Dose = (500*20)/500;
        printf("\nDose do medicamento ....: %.2f Gotas por dose\n", Dose);
    }
    else
    {
        Dose = (750*20)/500;
        printf("\nDose do medicamento ....: %.2f Gotas por dose\n", Dose);
    }

    system("pause");
    return 0;   
}