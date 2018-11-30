// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <locale.h>
using namespace std;

int func(int x, int d)
{
	if (x >= '0' && x <= '9')
		d = x - '0'; // '0'...'9' => 0...9
	else if (x >= 'a' && x <= 'z')
		d = 10 + x - 'a'; // 'a'...'z' => 10...35
	else if (x >= 'A' && x <= 'Z')
		d = 10 + x - 'A' + 27; // 'A'...'Z' => 36...62
	else if (x == 'б' || (x >= 'г' && x <= 'д') || (x >= 'ё' && x <= 'ж') || (x >= 'и' && x <= 'й')
		|| (x >= 'ц' && x <= 'я') || x == 'л' || x == 'п' || x == 'ф')
		d = 10 + x - 'а'; // => 63...82
	char c = d;
	cout << "d = " << '"' << c << '"' << endl;
	return d;
}

int main(void)
{
	setlocale(LC_ALL, "Russian");
	cout << "Перевод целых чисел из p-ичной с-мы в 10-ную" << endl;
	// таблица символов
	char c;
	for (int i = 0; i < 256; i++)
	{
		c = i;
		cout << i + 1 << ':' << '"' << c << '"' << ' ';
	}
	int p;
	do
	{
		cout << "Введите основание системы p (2...62): ";
		cin >> p;
	} while (p < 2 || p>82);
	const int MAX_LEN = 30; // Максимальная длина числа
	cout << "Введите число (не более " << MAX_LEN << " знаков): ";
	char x[MAX_LEN + 1];
	// Первый раз для пропуска уже введенного перевода строки
	cin.getline(x, 1, '\n');
	// Второй раз собственно ввод
	cin.getline(x, MAX_LEN + 1, '\n');
	int n = 0; // Число в 10-ной системе
	for (int i = 0; x[i] != 0; i++)
		// Перебор знаков числа до нуль-символа
	{
		n *= p;
		int d = -1; // Цифра
		d = func(x[i], d);
		cout << x[i] << " ";
		if (d < 0 || d > p) // Проверка корректности
		{
			cout << "Цифра " << x[i] << " некорректна" << endl;
			return 0;
		}
		n += d;	
	}
	cout << "Число в десятичной системе: " << n << endl;
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
