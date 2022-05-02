#pragma once
#include <malloc.h>

#define SIZE 80      //длина информации
#define MAX_ITEMS 14 //максимальное количество элементов в таблице

typedef char* Type;
typedef unsigned int key_t;

typedef struct
{
	int  busy;  // 0 - позиция свободна, 1 - занята, -1 - удалена
	key_t  key; //ключ элемента
	Type info;  //указатель на информацию
}Item;

Item vector[MAX_ITEMS];

key_t hash_function(key_t k);
int insert(key_t k, Type input);
int search(key_t k);
int delete(key_t key);
void print_table();