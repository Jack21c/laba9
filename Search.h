#pragma once
#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "T.h"



void Find()
{
    FILE* f = fopen("D:\\text9.txt", "rb");

    if (f == NULL)
    {
        printf("�������� ����. ����. � ���������. ��������\n");
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

    printf("�� ������ ���� ����");
    printf("(1 - ��������, 2 - �����, 3 - ����� �����, 4 - ������� �����, 5 - ������� �������): ");
    
    char c;

    scanf("%c", &c);

    //while (getchar() != '\n');

    switch (c)
    {
    
    case '1':
    {
        char a[512];
        int flag = 0;
        printf("������� �������� �����: ");
        scanf("%s", &a);
        for (int i = 0; i < amount; i++) {
            if (strcmp(a, St[i].Club) == 0)
            {
                printf("%20s\t%20s\t%d\t%d\t%20s\n", St[i].Club, St[i].City, St[i].points, St[i].balls, St[i].Surname);
                flag = 1;
            }
        }
        if (!flag)
            printf("׸-�� �����");
        break;
    }
    case '2':
    {
        char a[512];
        int flag = 0;
        printf("������� �������� ������: ");
        scanf("%s", &a);
        for (int i = 0; i < amount; i++) {
            if (strcmp(a, St[i].City) == 0)
            {
                printf("%20s\t%20s\t%d\t%d\t%20s\n", St[i].Club, St[i].City, St[i].points, St[i].balls, St[i].Surname);
                flag = 1;
            }
        }
        if (!flag)
            printf("׸-�� �����");
        break;
    }
    case '3':
    {
        int a;
        int flag = 0;
        printf("������� ����� �����: ");
        scanf("%d", &a);
        for (int i = 0; i < amount; i++)
        {
            if (a == St[i].points)
            {
                printf("%20s\t%20s\t%d\t%d\t%20s\n", St[i].Club, St[i].City, St[i].points, St[i].balls, St[i].Surname);
                flag = 1;
            }
        }
        if (!flag)
            printf("׸-�� �����");
        break;
    }
    case '4':
    {
        int a;
        int flag = 0;
        printf("������� ������� �����: ");
        scanf("%d", &a);
        for (int i = 0; i < amount; i++)
        {
            if (a == St[i].balls)
            {
                printf("%20s\t%20s\t%d\t%d\t%20s\n", St[i].Club, St[i].City, St[i].points, St[i].balls, St[i].Surname);
                flag = 1;
            }
        }
        if (!flag)
            printf("׸-�� �����");
        break;
    }
    case '5':
    {
        char a[512];
        int flag = 0;
        printf("������� ������� �������: ");
        scanf("%s", &a);
        for (int i = 0; i < amount; i++) {
            if (strcmp(a, St[i].Surname) == 0)
            {
                printf("%20s\t%20s\t%d\t%d\t%20s\n", St[i].Club, St[i].City, St[i].points, St[i].balls, St[i].Surname);
                flag = 1;
            }
        }
        if (!flag)
            printf("׸-�� �����");
        break;
    }
    default:
        printf("������ �������� ����");
        break;
    }

    

}
