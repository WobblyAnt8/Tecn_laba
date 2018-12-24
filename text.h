#pragma once
#include "stdafx.h"
using namespace std;
class text
{
	ifstream file;
	string line;
	int counter;
	string buffer;
	string word;

public:
	text();
	text(string& name);
	void fileParse();
	void lineCheck();
	void findDot();
	void search(string& sentence);
	bool isFind(string& sentence);
	bool checkEnd(int i, string& sentence);
	~text();
};

