#pragma onec
#include "T.h"
#define CHOICE 0
#pragma warning(disable:4996)


void Create()
{
	puts("C������� ���� ������ ��������, ��� ��� ���������� ������ ����� �������.\n�� �������, ��� ������ ����������? (Y/N)");
	char a;

	scanf("%c", &a);

	if (a == 'N')
		return;
	else if (a != 'Y')
	{
		puts("��-��-��. � ��� �� �����\n���� N, ���� Y, �������� �� ����. ������� �� �������� �������.\n");
		return;
	}

	if (a == 'Y') {
		int i = 0;
		char c = 'Y';
		Team S = (Team)malloc((i + 1) * sizeof(struct Teamn));

		while (c == 'Y')
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

			while (getchar() != '\n');

			printf("��������� ���������? Y/N\n");
			scanf("%c", &c);

			if (c == 'Y')
			{
				i++;
				S = (Team)realloc(S, (i + 1) * sizeof(struct Teamn));
			}
		}
		FILE* f = fopen("D:\\text9.txt", "wb");

		int am = i + 1;
		
		printf("\n\n%d\n\n", am);
		if (am) {
			fwrite(S, sizeof(S[0]), am, f);
		}
		free(S);
		fclose(f);

	}

}