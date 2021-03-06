
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
	if (in.fail())
	{
		if (buffer[0] > 0)
		{
			cout << "overflow of max string size " << endl;
		}
		return false;
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
	int shift = MAX_LEN;
	buffer[shift--] = 0;
	if (len == shift) return;
	for (int i = len; i >= 0; i--)
	{
		buffer[shift--] = buffer[i];
	}
	for (int i = 0; i <= shift; i++)
		buffer[i] = ' ';
}

int main()
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	char buffer[MAX_LEN + 1];
	//readLine(in, buffer);
	int i = 0;
	while (readLine(in, buffer))
	{
		if (i == 0)
		{
			out << buffer << endl;
			i++;
		}
		else if (i == 1)
		{
			centerLine(buffer);
			out << buffer << endl;
			i++;
		}
			else if (i == 2)
			{
				rightLine(buffer);
				out << buffer << endl;
				i = 0;
			}
	}
	return 0;
}