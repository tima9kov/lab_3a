#pragma once
#include <malloc.h>

#define SIZE 80      //����� ����������
#define MAX_ITEMS 14 //������������ ���������� ��������� � �������

typedef char* Type;
typedef unsigned int key_t;

typedef struct
{
	int  busy;  // 0 - ������� ��������, 1 - ������, -1 - �������
	key_t  key; //���� ��������
	Type info;  //��������� �� ����������
}Item;

Item vector[MAX_ITEMS];

key_t hash_function(key_t k);
int insert(key_t k, Type input);
int search(key_t k);
int delete(key_t key);
void print_table();