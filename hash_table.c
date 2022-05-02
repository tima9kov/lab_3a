#include "hash_table.h"

key_t hash_function(key_t key)
{
	return key % MAX_ITEMS;
}

//���������: 0 - ���� ������� ������� � �������
//			-1 - ���� � ������� ���� ������� � �������� ������  
//			-2 - ���� � ������� ��� ���������� �����
int insert(key_t k, Type input)
{
	int start = 0, i = 0, h = 1; //start - �������� ������� �������, h - ��� �������������
	start = i = hash_function(k);
	while (vector[i].busy > 0) //������� ������
	{
		//������� � �������� ������ ���� � �������
		if (vector[i].key == k)
			return -1; 
		i = (i + h) % MAX_ITEMS;		
		//��������� � �������� �������
		if (i == start)
			return -2;
	}
	//���� ��, �� ��������� ������ ��������
	vector[i].key  = k;
	vector[i].busy = 1;
	vector[i].info = input;
	return 0;
}

//����� �������� � �������
//���������: -1 - ��� �������� ��������
int search(key_t k)
{
	int start = 0, i = 0, h = 1; //start - �������� ������� �������, h - ��� �������������
	start = i = hash_function(k);
	while (vector[i].busy >= 0) //������� ������
	{
		if (vector[i].busy > 0 && vector[i].key == k)
			return i;
		i = (i + h) % MAX_ITEMS;
		//��������� � �������� �������
		if (i == start)
			break;
	}
	return -1;
}

int delete_element(key_t k) {    // �������� ������ ��� ���������, �.�. ������ ������������ ����� ���. �������� �������.
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
