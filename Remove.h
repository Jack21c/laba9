#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "T.h"

void Remove()
{
    FILE* f = fopen("D:\\text9.txt", "rb");

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

    int a;

    printf("Введите номер элемента, который нужно удалить (от 0 до %d): ", amount-1);
    scanf("%d", &a);

    if (a > amount)
        return;
    printf("Удалённый элемент - % 20s\t % 20s\t % d\t % d\t % 20s\n", St[a].Club, St[a].City, St[a].points, St[a].balls, St[a].Surname);
    for (int i = a; i < amount; i++)
    {
        St[a] = St[a + 1];
    }

    f = fopen("D:\\text9.txt", "wb");
    fwrite(St, sizeof(St[0]), amount - 1, f);
    fclose(f);

}