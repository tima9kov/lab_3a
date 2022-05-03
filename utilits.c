#include "utilits.h"
#include "hash_table.h"
#include <stdio.h>

void print_menu()
{
	printf("\n0 - exit, 1 - add element, 2 - delete element,3 - search, 4 - print table\n");
}

int select_action(int choice)
{
	printf("Your choice . . . ");
	scanf("%d",&choice);
	return choice;
}

int get_key(key_t k) {
	printf("Input key");
	scanf("%d",&k);
	return k;
}

int get_size() {
	int size = 0;
	printf("Input table size ... ");
	scanf("%d",&size);
	return size;
}

void not_found()
{
	printf("\n\x1b[31m not found \x1b[0m\n");
}

void show_element(key_t key)
{
	printf("\n\x1b[32mElement was found     Index: %3d	 Info: %10s    \x1b[0m\n", vector[key].key, vector[key].info);
}

void duplicated_key()
{
	printf("\n\x1b[31m The key already exists \x1b[0m\n");
}

void full_table()
{
	printf("\n\x1b[31m The table is full \x1b[0m\n");
}