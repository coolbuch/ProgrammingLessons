// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;

void mergeSort(int arr[], int size)
{
	int i, j, lbi, rbi, mi, lb, mb, rb;
	for (i = 1; i < size; i *= 2)
	{
		for (j = 0; j < size - i; j += 2 * i)
		{
			lbi = 0;
			rbi = 0;
			lb = j;
			mb = j + i;
			rb = j + 2 * i;
			rb = (rb < size) ? rb : size;
			int* SortedBlock = new int[rb - lb];
			while (lb + lbi < mb && mb + rbi < rb)
			{
				if (arr[lb + lbi] < arr[mb + rbi])
				{
					SortedBlock[lbi + rbi] = arr[lb + lbi];
					lbi++;
				}
				else
				{
					SortedBlock[lbi + rbi] = arr[mb + rbi];
					rbi++;
				}
			}
			while (lb + lbi < mb)
			{
				SortedBlock[lbi + rbi] = arr[lb + lbi];
				lbi++;
			}
			while (mb + rbi < rb)
			{
				SortedBlock[lbi + rbi] = arr[mb + rbi];
				rbi++;
			}
			for (mi = 0; mi < lbi + rbi; mi++)
				arr[lb + mi] = SortedBlock[mi];
			delete SortedBlock;

		}
	}
}
void printArray(int arr[], int size, bool b) // b = true - нумерация
{
	for (int i = 0; i < size; i++)
	{
		if (b)
			cout << i << ". ";
		cout << arr[i] << endl;
	}
}
void findSame(int arr[], int size)
{
	int buf = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] == buf)
			arr[i - 1] = 0;
		else buf = arr[i];
	}
}
/*int intSqrt(int num)
{
	int b = num;
	int x = 1;
	unsigned long x1 = (int)(0.5 * (x + (int)(b / x)));
	int x2 = 0;
	while (x2 != x1) {
		x2 = x;
		x = x1;
		x1 = (int)(0.5 * (x + (int)(b / x)));
		cout << "intSqrt call: " << num << endl;
	}
	return x1;
}*/
bool isPrime(int num)
{
	int divider = 1;
	while (divider <= sqrt(num))
	{
		//cout << "isPrime call: " << num << endl;
		divider++;
		if (num % divider == 0)
		{
			
			return false;
		}
	}
	return true;
}

void checkErrors(int* arr, int size)
{
	int* r = new int[6], errNum = 0, buf = 0, corrected = 0;
	for (int i = 0; i < size; i++)
	{

		//if (arr[i] == 0)
		//{
		//	i += 2;
		//	continue;
		//}

		buf = arr[i];		
		if (!isPrime(arr[i]))
		{

			for (int j = 0; j < 6; j++)
			{
				r[j] = buf % 10;
				buf /= 10;

			}
			
			for (int j = 0; j < 6; j++)
			{
				r[j] = (9 + r[j]) % 10;
				int number = r[0] + r[1] * 1e1 + r[2] * 1e2 + r[3] * 1e3 + r[4] * 1e4 + r[5] * 1e5;
				if ((1e5 < number && number < 2e5 && isPrime(number)))
				{
					corrected = r[0] + r[1] * 1e1 + r[2] * 1e2 + r[3] * 1e3 + r[4] * 1e4 + r[5] * 1e5;
					errNum++;
				}
				r[j]++;
				r[j] %= 10;

			}

			if (errNum <= 1)
				arr[i] = corrected;
			else
			{
				arr[i] = r[0] + r[1] * 1e1 + r[2] * 1e2 + r[3] * 1e3 + r[4] * 1e4 + r[5] * 1e5;
				arr[i] = -arr[i];
			}
		}
		errNum = 0;
	}
	
}

void generateFile(int n, string filename /*Witout .format*/, int div)
{
	filename += ".txt";
	ofstream out(filename);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		out << rand() % div << endl;
	}
	out.close();
	//system("pause");
}

void simpleNumbers()
{
	const int n = 1000, primesCount = 100;
	// Ввод входного массива и массива простых чисел
	int arr[n];
	int primesArr[primesCount];
	ifstream in("1.txt");
	ifstream in1("input2.dat");
	ofstream out("output.txt");
	for (int i = 0; i < n; i++)
	{
		//if (i < primesCount)
		//{
		//	in >> primesArr[i];
		//	arr[i + 1000] = primesArr[i];
		//}
		in1 >> arr[i];
	}
	//mergeSort(arr, n);
	//printArray(arr, n, true);
	//findSame(arr, n);
	//printArray(arr, n, true);
	checkErrors(arr, n);
	//findSame(arr, n);
	//printArray(arr, n, true);
	int* r = new int[6];
	int buf = 0, corrected = 0, errNum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			out << -arr[i] << '*' << endl;
		}
		else if (arr[i] > 0) out << arr[i] << endl;
	}
}

void arrayTask()
{
	ifstream in("inputArray.txt");
	
	int n = 0;
	cout << "Enter n : ";
	cin >> n;
	int* arr = new int[n];
	int* cArr = new int[n];
	for (int i = 0; i < n; i++)
	{
		in >> arr[i];
		//cArr[i]
		for (int j = 0; j < i; j ++)
		{

		}
		
	}
	printArray(arr, n, true);
}

int main()
{
	//simpleNumbers();
	generateFile(100, "inputArray", 20);
	arrayTask();
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
