#pragma once
#include <malloc.h>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

typedef char* Type;
typedef unsigned int key_t;

typedef struct
{
	int   busy;  // 0 - ������� ��������, 1 - ������, -1 - �������
	key_t  key; //���� ��������
	Type info;  //��������� �� ����������
}Item;

Item *vector;

void print_menu();
key_t hash_function(key_t k, int capacity);
int insert(key_t k, int capacity);
int search(key_t k, int capacity);
int delete_element(key_t key, int capacity);
void print_table(int capacity);