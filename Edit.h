#pragma once
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "T.h"



void Edit()
{
    FILE* f = fopen("bd", "rb");

    if (f == NULL)
    {
        printf("Потеряли базу. Ищем. И ненаходим. Приехали\n");
        return;
    }

    Team St;

    fseek(f, 0, SEEK_END);
    int amount = ftell(f) / sizeof(struct Teamn);
    fseek(f, 0, SEEK_SET);

    St = (Team)malloc(amount * sizeof(struct Teamn));

    for (int i = 0; i < amount; i++)
    {
        fread(&St[i].Club, sizeof(St[i].Club), 1, f);
        fread(&St[i].City, sizeof(St[i].City), 1, f);
        fread(&St[i].points, sizeof(St[i].points), 1, f);
        fread(&St[i].balls, sizeof(St[i].balls), 1, f);
        fread(&St[i].Surname, sizeof(St[i].Surname), 1, f);
    }

    fclose(f);

    int num, field;
    printf("Выберите элемент(от 0 до %d): ", amount-1);
    scanf("%d", &num);
    printf("Номер поля (от 1 до 5): ");
    scanf("%d", &field);
    printf("Исходная версия:\n");
    printf("%20s\t%20s\t%d\t%d\t%20s\n", St[num].Club, St[num].City, St[num].points, St[num].balls, St[num].Surname);
    if (field == 1)
    {
        char new_val[512];
        printf("Введите новый текст: ");
        scanf("%s", &new_val);
        strcpy(St[num].Club, new_val);
    }
    if (field == 2)
    {
        char new_val[512];
        printf("Введите новое значение: ");
        scanf("%s", &new_val);
        strcpy(St[num].City, new_val);
    }
    if (field == 3)
    {
        int d;
        printf("Введите новое значение: ");
        scanf("%d", &d);
        St[num].points = d;
    }
    if (field == 4)
    {
        int d;
        printf("Введите новый текст: ");
        scanf("%d", &d);
        St[num].balls = d;
    }
    if (field == 5)
    {
        char new_val[512];
        printf("Input new value: ");
        scanf("%s", &new_val);
        strcpy(St[num].Surname, new_val);
    }
    printf("Отредаченная версия:\n");
    printf("%20s\t%20s\t%d\t%d\t%20s\n", St[num].Club, St[num].City, St[num].points, St[num].balls, St[num].Surname);
    f = fopen("D:\\text9.txt", "wb");
    fwrite(St, sizeof(St[0]), amount, f);
    fclose(f);

}