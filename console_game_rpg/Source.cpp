#include <iostream>
#include <string>
#include <clocale>
#include"Student.h"

using namespace std;

string getTimeFromSlots(int slots) {
	int hours = 10 + (slots / 4);
	string hours_str = to_string(hours);
	int minutes = (slots % 4) * 15;
	string minutes_str = to_string(minutes);
	if (minutes == 0) {
		minutes_str = "00";
	}
	string time = "" + hours_str + ":" + minutes_str;
	return time;
}

int main()
{
	std::setlocale(LC_ALL, "pl-PL");
	string input;
	int usedSlots = 0;

	cout << "Wybierz imi� dla swego gracza:\n";
	cin >> input;
	Student student = Student(input);
	cout << student.getName() << "...";
	cout << "\n" << student.getName() << "...";
	cout << "\n" << student.getName() << "!!!\n";
	cout << "Powoli otwierasz oczy. Piekielnie boli Ci� g�owa.\nRozgl�dasz si� dooko�a. Le�ysz na trawniku, przed akademikiem.\nTw�j wsp�lokator widz�c, �e uda�o mu si� Ci� dobudzi�, odwraca si� i odchodzi, mrucz�c co� pod nosem.\n";
	cout << "'Dzie� jak co dzie�' - my�lisz. Jedyne co pami�tasz to 3 rzeczy:\n1) masz odda� po�ciel do prania i zap�aci� za pranie\n2) masz zadzwoni� do mamy, aby powiedzie� jej, �e u Ciebie wszystko w porz�dku\n3) najwa�niejsze - dzi� o 14:00 masz egzamin, a zaraz po nim musisz biec na poci�g do domu.\n";
	cout << "Jest godzina 10:00. W portfelu 10z�. Dramat...\n\n";
	cout << "********** GRA ROZPOCZ�TA! ***********\n\n";
	while (usedSlots < 16)
	{
		cout << "Jest godzina " << getTimeFromSlots(usedSlots) << "\n";
		cout << "Co zamierzasz teraz zrobi� ?\n";
		cout << "1) I�� do sklepu\n";
		cout << "2) Zadzwoni� do mamy\n";
		cout << "3) I�� do kumpla z s�siedniego akademika\n";
		cout << "4) I�� do pralni\n";
		cout << "4) I�� na uczelnie\n";
		cout << "5) Zacz�� p�aka�\n";
		cout << "6) I�� do swojego pokoju w akademiku\n";
		cout << "Wpisz numer akcji: ";
		cin >> input;
		if (input == "1") 
		{

			usedSlots++;
		}
		else if (input == "2") 
		{

			usedSlots++;
		}
		else if (input == "3")
		{

			usedSlots++;
		}
		else if (input == "4")
		{

			usedSlots++;
		}
		else if (input == "5")
		{

			usedSlots++;
		}
		else if (input == "6")
		{

			usedSlots++;
		}
		else
		{
			cout << "Nieprawid�owy numer...\n";
		}
	}
	return 0;
}
