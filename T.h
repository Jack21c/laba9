#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct Teamn
{
    char Club[512];
    char City[512];
    int points;
    int balls;
    char Surname[512];
} *Team;