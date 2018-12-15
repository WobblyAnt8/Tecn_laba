#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int scan(string line, string search)
{
	int count = 0;
	while (line.find(search) != string::npos)
	{
		if(( line.find(search) == 0|| line[line.find(search) - 1] == ' ') && (line[line.find(search) + search.size()] == ' ' || line[line.find(search) + search.size()] == '\0'))
			count++;
		line.erase(line.find(search), search.size());
	}
	return count;
}

void work(ifstream& in)
{
	cout << "¬ведите слово: ";
	string search;
	cin >> search;
	string line;
	while (!in.eof()) 
	{
		getline(in, line);
		int c = scan(line, search);
		cout << line << ' ' << c << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	ifstream in;
	in.exceptions(ifstream::failbit);
	string name = "input.txt";
	try
	{
	    in.open(name);
		work(in);
		in.close();
	}
	catch (const ifstream::failure& exc)
	{
		cout << "ќшибка при открытии файла" << endl<< exc.what() << endl<<endl;
	}
	system("pause");
}