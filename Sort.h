#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "T.h"

void Sort()
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

    int field;
    printf("По какому полю сортируем (0 по названию, 1 по числу очков): ");
    scanf("%d", &field);
    if (field == 0)
    {
        for (int i = 0; i < amount; i++)
        {
            for (int j = i+1; j < amount; j++)
            {
                Team tmp;
                tmp = (Team)malloc(sizeof(struct Teamn));

                if (strcmp(St[i].Club, St[j].Club) < 0)
                {
                    tmp = &St[i];
                    St[i] = St[j];
                    St[j] = *tmp;
                    tmp = NULL;
                }
            }
        }
    }
    if (field == 1)
    {
        for (int i = 0; i < amount; i++)
        {
            for (int j = i; j < amount; j++)
            {
                Team tmp;

                if (St[i].points > St[j].points)
                {
                    if (St[i].balls > St[j].balls)
                    {
                        tmp = &St[i];
                        St[i] = St[j];
                        St[j] = *tmp;
                        tmp = NULL;
                    }
                }
            }
        }
    }
    f = fopen("D:\\text9.txt", "wb");
    fwrite(St, sizeof(St[0]), amount, f);
    fclose(f);
    
}