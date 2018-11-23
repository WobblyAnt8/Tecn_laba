#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void enter(string word, int cword);	 //ôóíêöèÿ äëÿ âûâîäà
void work(ifstream& in); //ôóíêöèÿ äëÿ ðàáîòû ñ ôàéëîì   

int main()
{
	setlocale(LC_ALL, "");
	ifstream io("input.txt");

	work(io);

	io.close();//çàêðûâàåì ôàéë										   
	system("pause>>void");
}

void enter(string word, int cword)
{
	cout << "count = " << cword << '\n';
	cout << word;// âûâîäèì ïðåäëîæåíèå
}

void work(ifstream& in)
{
	string line;//ñëîâî
	stringstream ss;	//ñòðîêîâûé ïîòîê
	int maxlen = -1; //ìàêñèìàëüíîå çíà÷åíèå
	int cnt = 1;//ñ÷¸ò÷èê 1 òàê êàê îäíî ñëîâî âñåãäà åñòü
	while (in >> line) {//ñ÷èòûâàåì ïî ïðåäëîæåíèþ
		int o = line.length();
		//åñëè áîëüøå ïðåäûäóùåãî
		if (o > maxlen) {
			maxlen = o;
			cnt = 1;
			ss.str(std::string());//î÷èùàåì
			ss << line;
		}
		//åñëè äëíà ðàâíà ìàêñèìàëüíîé
		else if (o == maxlen && ss.str() == line) {
			++cnt;
		}

	}
	enter(ss.str(), cnt);
}