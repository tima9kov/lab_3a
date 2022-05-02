#include "hash_table.h"

key_t hash_function(key_t key)
{
	return key % MAX_ITEMS;
}

//Результат: 0 - если элемент включен в таблицу
//			-1 - если в таблице есть элемент с заданным ключом  
//			-2 - если в таблице нет свободного места
int insert(key_t k, Type input)
{
	int start = 0, i = 0, h = 1; //start - исходная позиция таблицы, h - шаг перемешивания
	start = i = hash_function(k);
	while (vector[i].busy > 0) //позиция занята
	{
		//элемент с заданным ключом есть в таблице
		if (vector[i].key == k)
			return -1; 
		i = (i + h) % MAX_ITEMS;		
		//вернулись в исходную позицию
		if (i == start)
			return -2;
	}
	//если ок, то занесение нового элемента
	vector[i].key  = k;
	vector[i].busy = 1;
	vector[i].info = input;
	return 0;
}

//поиск элемента в таблице
//Результат: -1 - нет искомого элемента
int search(key_t k)
{
	int start = 0, i = 0, h = 1; //start - исходная позиция таблицы, h - шаг перемешивания
	start = i = hash_function(k);
	while (vector[i].busy >= 0) //позиция занята
	{
		if (vector[i].busy > 0 && vector[i].key == k)
			return i;
		i = (i + h) % MAX_ITEMS;
		//вернулись в исходную позицию
		if (i == start)
			break;
	}
	return -1;
}

int delete_element(key_t k) {    // пометить запись как удаленную, т.к. нельзя перемешивать после физ. удаления записей.
	int i;
	i = search(k);
	if (i > 0) {
		/*free(vector[i].info);*/
		vector[i].info = NULL;
		vector[i].busy = -1;
		i = 0;
	}
	return i;
}

void print_table()
{
	int i;
	printf("      KEY        busy            INFO         \n");
	for (i = 0; i < MAX_ITEMS; i++)
	{
		printf("\n      %3d       %3d          %10s    \n", vector[i].key, vector[i].busy, vector[i].info);		
	}
}
