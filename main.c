//�������� �.� �20-�02
//
//������� 5 
//�������� ��������� ��� ������ � ������������ ��������, ������������ ������������� ���������, �� �������� ���������.
//������������ ������� ������������ ��������; ������ ������� ������� ����� ��������� ��������� :
//struct Item {
//	int busy;		/* ������� ��������� ��������	*/
//	int key;		/* ���� ��������				*/
//	char* info;	/* ��������� �� ����������		*/
//};
//
//������������ ������ ������� ���������(��� ������� ������������� ������� ������� ������������ ��������� � ��������, const int SIZE = ...;).
//��� ������� � ��������� ������� ������������ ������� �����������.
//������������� ��������� �������� :
//-	��������� ������ �������� � ������� ��� �������, ��� � ������� �� ����� ���� ���� ��������� � ����������� �������; ���� ��� ��������� ������
//�������� ��������� ����� ��������, �� ����� ������ ���� �������� ��������� �� ������;
//-	�������� �� ������� ��������, ��������� ����� ������;
//-	����� �������� �� ��������� �����.����������� ������ ������ ���� ����� ������� �������, ���������� ��������� �������.���� �������� ������� �
//������� �����������, ������� �� ����� ��������� �� ������;
//-	����� ����������� ������� �� �����.
//����������� ��� �������� ��������� :
//a)	� ���� �������, � ����������, ����������� � �������� �������, �������� � �������� ������;
//b)	� ���� �������, � ����������, ����������� � �������� �������, �������� �� ������� ������(������������ �������� ���� ������������� �������).
//��� �������� ����������� � ��������, ����������� � �������� ������.������� ����������� �� �����(��� ��������� � ������ ���) � ������ ������ ������ 
//� ������������ � ���� � ����� ������ ������.����������, ����������� � �������� �������, ������������ � ���� ����� �� ��� ���������� �������� ���������
//� �������.��� ����� �������� �� ������� �� ���������.

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "hash_table.h"
#include "messages.h"

int main()
{
	int i;
	insert(1, "a");
	insert(11, "ab");
	insert(21, "abc");
	insert(23, "abcd");
	print_table();
	system("pause");
	system("CLS");

	i = delete_element(21);
	printf("%d\n\n", i);

	print_table();
	system("pause");
	system("CLS");
	i = search(21);
	printf("%d", i);
	return 0;
}