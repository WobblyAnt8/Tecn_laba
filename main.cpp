// laba2Sl.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "text.h"

void printMenu();

int main()
{
	string name[5] = { "text1.txt","text2.txt","text3.txt","text4.txt","text5.txt" };
	printMenu();
	while (true)
	{
		switch (getchar())
		{
		case '1':
		{
			text a(name[0]);
			printMenu();
			break;
		}
		case '2':
		{
			text b(name[1]);
			printMenu();
			break;
		}
		case '3':
		{
			text c(name[2]);
			printMenu();
			break;
		}
		case '4':
		{
			text d(name[3]);
			printMenu();
			break;
		}
		case '5':
		{
			text e(name[4]);
			printMenu();
			break;
		}
		case '6':

			cout << "Exit." << endl;
			exit(EXIT_SUCCESS);
		}

	}

	return 0;
}

void printMenu() {
	cout <<endl<< "Choose file for programm:\n" 
		<< "1. Sentences are separated, each sentence has its own line." << endl 
		<< "2. Sentences end of sentence may be on next line." << endl
		<< "3. Sentences consist of one-letter words; may be put in one line." << endl 
		<< "4. All offers are put in one line; may consist of identical letters." << endl 
		<< "5. File is empty." << endl 
		<< "6. Exit." << endl;
}