#include "hash_table.h"
#include <stdio.h>
#include "utilits.h"
#include <string.h>

key_t hash_function(key_t key, int capacity)
{
	return key % capacity;
}

void init_table(int capacity)
{
	vector = (Item*)malloc(capacity * sizeof(Item));
	for (int i = 0; i < capacity; i++)
	{
		vector[i].busy = 0;
		vector[i].key = 0;
		vector[i].info = NULL;
	}
}

//����� �������� � �������
//���������: -1 - ��� �������� ��������
int search(key_t k, int capacity)
{
	int start = 0, i = 0, h = 1; //start - �������� ������� �������, h - ��� �������������
	start = i = hash_function(k, capacity);
	while (vector[i].busy >= 0) //������� ������
	{
		if (vector[i].busy > 0 && vector[i].key == k)
			return i;
		i = (i + h) % capacity;
		//��������� � �������� �������
		if (i == start)
			break;
	}
	return -1;
}

//���������: 0 - ���� ������� ������� � �������
//			-1 - ���� � ������� ���� ������� � �������� ������  
//			-2 - ���� � ������� ��� ���������� �����
int insert(key_t k, int capacity)
{
	int start = 0, i = 0, h = 1; //start - �������� ������� �������, h - ��� �������������
	start = i = hash_function(k, capacity);

		while (vector[i].busy > 0) //������� ������
		{
			if (vector[i].key == k)
				return -1;
			i = (i + h) % capacity;

			//��������� � �������� �������
			if (i == start)
				return -2;
		}
	
	//���� ��, �� ��������� ������ ��������
	vector[i].key = k;
	vector[i].busy = 1;
	char buf[81];
	int len = 0, n = 0;
	
	//n = scanf("%80[^\n]", buf);
	scanf("%s", &buf);
	
	len = strlen(buf);
	printf("%d", len);
	vector[i].info = (Type)malloc(len * sizeof(char));
	strcpy(vector[i].info, buf);
	//vector[i].info = getline(vector[i].info);
	return 0;
}

// �������� ������ ��� ���������, �.�. ������ ������������ ����� ���. �������� �������.
int delete_element(key_t k, int capacity) {   
	int i;
	i = search(k, capacity);
	if (i > 0) {
		vector[i].info = NULL;
		vector[i].busy = -1;
		free(vector[i].info);
		i = 0;
	}
	return i;
}

void print_table(int capacity)
{
	int i;
	system("cls");
	printf("KEY	 busy	      INFO\n");
	for (i = 0; i < capacity; i++)
	{
		printf("\n%3d	%3d	  %10s ", vector[i].key, vector[i].busy, vector[i].info);
	}
}
