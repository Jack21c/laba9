#pragma onec
#include "T.h"
#define CHOICE 0
#pragma warning(disable:4996)


void Create()
{
	puts("Cоздание базы данных означает, что все предыдущие записи будут утеряны.\nВы уверены, что хотите продолжить? (Y/N)");
	char a;

	scanf("%c", &a);

	if (a == 'N')
		return;
	else if (a != 'Y')
	{
		puts("Не-не-не. Я так не играю\nЛибо N, либо Y, третьего не дано. Придётся всё начинать сначала.\n");
		return;
	}

	if (a == 'Y') {
		int i = 0;
		char c = 'Y';
		Team S = (Team)malloc((i + 1) * sizeof(struct Teamn));

		while (c == 'Y')
		{
			printf("Введите название клуба:\n");
			scanf("%s", &S[i].Club);

			printf("Введите название города: ");
			scanf("%s", &S[i].City);

			printf("Введите число очков: ");
			scanf("%d", &S[i].points);

			printf("Введите разницу мячей: ");
			scanf("%d", &S[i].balls);

			printf("Введите фамилию тренера: ");
			scanf("%s", &S[i].Surname);

			while (getchar() != '\n');

			printf("Продолжим мытарства? Y/N\n");
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