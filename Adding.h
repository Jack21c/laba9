#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void Add()
{
	int amount;

	printf("������� ���������� ����������� ���������: ");
	scanf("%d", &amount);

	Team S = (Team)malloc(amount * sizeof(struct Teamn));

	for (int i = 0; i < amount; i++)
	{
		printf("������� �������� �����:\n");
		scanf("%s", &S[i].Club);

		printf("������� �������� ������: ");
		scanf("%s", &S[i].City);

		printf("������� ����� �����: ");
		scanf("%d", &S[i].points);

		printf("������� ������� �����: ");
		scanf("%d", &S[i].balls);

		printf("������� ������� �������: ");
		scanf("%s", &S[i].Surname);

	}

	FILE* f = fopen("D:\\text9.txt", "a+b");

	fwrite(S, sizeof(S[0]), amount, f);

	fclose(f);

	free(S);
}