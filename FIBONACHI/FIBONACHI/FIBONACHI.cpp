// Фиббоначи комп ( посмотреть как можно искать через матрицы)
#include "pch.h"
#include <iostream>


using namespace std;
int main()
{
	int n = 0, pred = 0, current = 0, next = 1;
	cin >> n;
	while (next < n)
	{
		pred = current;
		current = next;
		next = current + pred;
	}
	//cout << pred << ' ' << current << ' ' << next << endl;
	int tmp = 0;
	while (pred > 0)
	{
		if (current - n <= 0)
		{
			cout << current << " ";
			n -= current;
		}
		else cout << '0' << " ";
		tmp = current;
		pred = current - pred;

		current = next - current;


		next = tmp;
		//cout << pred << ' ' << current << ' ' << next << endl;

	}
	return 0;
}