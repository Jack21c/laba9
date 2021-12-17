#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void Output()
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

	for (int i = 0; i < amount; i++)
	{
		printf("%20s\t%20s\t%d\t%d\t%20s\n", St[i].Club, St[i].City, St[i].points, St[i].balls, St[i].Surname);
	}

	free(St);

}