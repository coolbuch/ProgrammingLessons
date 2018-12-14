// Majakovskii.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

const int MAX_LEN = 80;
bool readLine(ifstream& in, char* buffer)
{
	buffer[0] = 0;
	in.getline(buffer, MAX_LEN + 1, '\n');
	//if (in.fail())
	//{
	//	if (buffer[0] > 0)
	//	{
	//		cout << "overflow of max string size " << endl;
	//		return false;
	//	}
	//}
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

int main()
{
	ifstream in("out.txt");
	char buffer[MAX_LEN + 1];
	in.open("out.txt");
	while (readLine(in, buffer))
	{
		centerLine(buffer);
		cout << buffer;
	}
	return 0;
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
