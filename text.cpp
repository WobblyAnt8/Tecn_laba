#include "stdafx.h"
#include "text.h"

using namespace std;

text::text()
{
}

text::text(string & name)
{
	file.exceptions(ifstream::failbit);

	try
	{
		file.open(name);
		cout << "Input: ";
		cin >> word;
		fileParse();
		file.close();
	}
	catch (const ifstream::failure& exc)
	{
		cout << "Error! : " <<  exc.what() << endl << endl;
	}
}

void text::fileParse()
{
	while (!file.eof())
	{
		getline(file, line);
		lineCheck();
	}
}

void text::lineCheck()
{
	if (!buffer.empty())
	{
		string temp = line;
		line = buffer + temp;
		buffer.erase(buffer.begin(),buffer.end());
	}
	findDot();
}
void text::findDot()
{
	int idx;
	for (idx = 0; idx < line.size(); idx++)
	{
		if (line[idx] == '.' || line[idx] == '!' || line[idx] == '?')
			break;
	}
	if (idx != line.size() && !line.empty())
	{
		string temp = line.substr(0, ++idx);
		search(temp);
		cout << line.substr(0,++idx) << " (" << counter << ") "<<endl;
		line.erase(0, idx+2);
		if (!line.empty())
			findDot();
		else return;
	}
	else
		buffer+= line;
}

void text::search(string & sentence)
{
	for (counter = 0; isFind(sentence) ; counter++)
	{
			sentence.erase(sentence.find(word),word.size());
	}
}

bool text::isFind(string & sentence)
{
	int i = sentence.find(word);
	if ((i != string::npos) &&
		((i == 0 && checkEnd(i, sentence)) ||
		(checkEnd(i, sentence) && sentence[--i] == ' ')))
		return true;
	else if (i != string::npos) {
		while (sentence[i] != ' ')
		{
			sentence.erase(i, 1);
			i++;

		}
		isFind(sentence);
	}
	return false;
}

bool text::checkEnd(int i, string & sentence)
{
	if (sentence[i + word.size()] == ' ' ||
		sentence[i + word.size()] == '.' ||
		sentence[i + word.size()] == '?' ||
		sentence[i + word.size()] == '!')
		return true;
	return false;
}


text::~text()
{
}
