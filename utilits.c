#include "utilits.h"
#include "hash_table.h"
#include <stdio.h>

void print_menu()
{
	printf("\n0 - exit, 1 - add element, 2 - delete element,3 - search, 4 - print table\n");
}	

int select_action(int choice)
{
	int condition = 0;
	printf("Your choice . . . ");
	while (1 != scanf("%d", &choice) || choice > 4 || choice < 0) {
		rewind(stdin);
		printf("\x1b[31mIncorrect input, try again\x1b[0m");
	}
	return choice;
}

int get_key(key_t k) {
	printf("Input key ");
	while (1 != scanf("%d", &k)) {
		rewind(stdin);
		printf("\x1b[31mIncorrect input, try again\x1b[0m");
	}
	return k;
}

void get_line(int i)
{
	char* str = NULL, c;
	int len = 1;
	str = (char*)malloc(sizeof(char));
	printf("input string: ");
	rewind(stdin);
	while ((c = getchar()) != '\n') {
		str[len - 1] = c;
		len++;
		str = (char*)realloc(str, len);
	}
	str[len - 1] = '\0';
	printf("%s (%d symbols)\n", str, len - 1);
	vector[i].info = (Type)malloc(len * sizeof(char));
	strcpy(vector[i].info, str);
	free(str);
}

int get_size() {
	int size = 0;
	printf("Input table size ... ");
	while (1 != scanf("%d", &size)) {
		rewind(stdin);
		printf("\x1b[31mIncorrect input, try again ... \x1b[0m");
	}
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