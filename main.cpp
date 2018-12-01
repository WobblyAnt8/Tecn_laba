#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int Exception(ifstream& inn)
{
	if (!inn.is_open())
	{
		cout << "Файл не открыт.\n"; // если файл не открылся
		return 1;
	}
	else if (inn.peek() == EOF)
	{
		cout << "Файл пустой.\n"; // если файл пустой
		return 1;
	}
}

void work(ifstream& in)
{
	int flag = Exception(in);
	if (flag == 1)
		return;

	string word;//слово
	cout << "Введите слово: ";

	string search;
	cin >> search;

	string line;//предложение
	stringstream ss;	//строковый поток
	int cnt;//счётчик

	while (getline(in, line)) //считываем по предложению
	{
		stringstream tmp;//буфер
		tmp << line;
		cnt = 0;
		while (tmp >> word) //разбиваем на слова
		{
			if (word == search) //если нашли слово
			{
				++cnt;
			}
		}
		ss << line << ' ' << cnt << '\n';
	}
	cout << ss.str();
}


int main()
{
	setlocale(LC_ALL, "");
	ifstream io("input.txt");

	work(io);

	io.close();//закрываем файл										   
	system("pause");
}