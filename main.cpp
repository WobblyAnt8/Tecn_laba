#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int Exception(ifstream& inn)
{
	if (!inn.is_open())
	{
		cout << "���� �� ������.\n"; // ���� ���� �� ��������
		return 1;
	}
	else if (inn.peek() == EOF)
	{
		cout << "���� ������.\n"; // ���� ���� ������
		return 1;
	}
}

void work(ifstream& in)
{
	int flag = Exception(in);
	if (flag == 1)
		return;

	string word;//�����
	cout << "������� �����: ";

	string search;
	cin >> search;

	string line;//�����������
	stringstream ss;	//��������� �����
	int cnt;//�������

	while (getline(in, line)) //��������� �� �����������
	{
		stringstream tmp;//�����
		tmp << line;
		cnt = 0;
		while (tmp >> word) //��������� �� �����
		{
			if (word == search) //���� ����� �����
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

	io.close();//��������� ����										   
	system("pause");
}