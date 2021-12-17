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
	puts("������� 'Enter', ����� ������ �������� � ����� ������");

	while (1)
	{
		while (getchar() != '\n');

		puts("\n\n\t\t\tMenu:\n1)�������� ���� ������\n\n"
			"2)���������� ��������� � ���� ������\n\n3)�������� ��������� �� ���� ������\n\n"
			"4)����� �� ����\n\n5)�������������� ��������� � ���� ������\n\n6)����������� ���� ������ �� ��������� ����\n\n"
			"7)����� ���� ������\n\n0)�����\n\n\n");

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