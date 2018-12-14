// Majakovskii.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int MAX_LEN = 80;
ofstream out("out.txt");
bool readLine(ifstream& in, char* buffer)
{
	buffer[0] = 0;
	in.getline(buffer, MAX_LEN + 1);
	cout << buffer << endl;
	if (in.fail())
	{
		if (buffer[0] > 0)
		{
			cout << "overflow of max string size " << endl;
			return false;
		}
	}
	return true;
}

void centerLine(char* buffer)
{
	int len = strlen(buffer);
	int shift = (MAX_LEN - len) / 2;
	if (shift == 0)
		return;
	for (int i = len; i >= 0; i--)
		buffer[i + shift] = buffer[i];
	for (int i = 0; i < shift; i++)
		buffer[i] = ' ';
	
}

void rightLine(char* buffer)
{
	int len = strlen(buffer);
	cout << len << endl << buffer << endl;
	int j = MAX_LEN;
	buffer[j--] = 0;
	for (int i = len; i >= 0; i--)
	{
		cout << j << ' ' << i << ' ';
		buffer[j--] = buffer[i];
		buffer[i] = ' ';
	}
	for (int i = 0; i < MAX_LEN; i ++)
		cout << buffer[i] << endl;
}

int main()
{
	ifstream in("in.txt");
	//string text[MAX_LEN];
	char input[MAX_LEN + 1], buffer[MAX_LEN + 1];
	in.getline(input, MAX_LEN + 1);
	out << input << endl;
	cout << MAX_LEN << ' ' << strlen(input) << endl;
	for (int i = 0; i < MAX_LEN + 1; i++)
	{
		if (!(input[i] > 0)) 
		{
			input[i] = '_';
			cout << i << ' ';
		}
		buffer[i] = input[i];
	}
	cout << endl << strlen(buffer) << endl;
	rightLine(buffer);
	out << buffer;
	/*for (int i = 0; i < MAX_LEN; i++)
	{
		in.getline(buffer, MAX_LEN, '\n');
		while (readLine(in, buffer) && buffer[0]> 0)
			{
				if (i % 3 == 0)
				centerLine(buffer);
				//cout << buffer;
			}
		if (buffer[0] > 0)
			out << buffer << endl;
		//cout << buffer << endl;
	}*/
	
	//in.open("in.txt");
	//in.getline(buffer, MAX_LEN);
	//in >> buffer;
	//cout << buffer;
	//
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
