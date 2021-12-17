#pragma once

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


#include "Creation.h"
#include "Output.h"
#include "Adding.h"
#include "Search.h"
#include "Remove.h"
#include "Edit.h"
#include "Sort.h"

void Menu()
{
	puts("Нажмите 'Enter', чтобы начать работать с базой данных");

	while (1)
	{
		while (getchar() != '\n');

		puts("\n\n\t\t\tMenu:\n1)Создание базы данных\n\n"
			"2)Добавление элементов в базу данных\n\n3)Удаление элементов из базы данных\n\n"
			"4)Поиск по базе\n\n5)Редактирование элементов в базе данных\n\n6)Сортировать базу данных по заданному полю\n\n"
			"7)Вывод базы данных\n\n0)Выход\n\n\n");

		char c;

		scanf("%c", &c);

		while (getchar() != '\n');

		switch (c)
		{
		case '0':
			return;

		case '1':
			Create();
			break;

		case '2':
			Add();
			break;
		case '3':
			Remove();
			break;
		case '4':
			Find();
			break;
		case '5':
			Edit();
			break;
		case '6':
			Sort();
			break;
		case '7':
			Output();
			break;

		default:
			break;
		}
	}
}