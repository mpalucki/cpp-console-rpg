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

	cout << "Wybierz imiê dla swego gracza:\n";
	cin >> input;
	Student student = Student(input);
	cout << student.getName() << "...";
	cout << "\n" << student.getName() << "...";
	cout << "\n" << student.getName() << "!!!\n";
	cout << "Powoli otwierasz oczy. Piekielnie boli Ciê g³owa.\nRozgl¹dasz siê dooko³a. Le¿ysz na trawniku, przed akademikiem.\nTwój wspó³lokator widz¹c, ¿e uda³o mu siê Ciê dobudziæ, odwraca siê i odchodzi, mrucz¹c coœ pod nosem.\n";
	cout << "'Dzieñ jak co dzieñ' - myœlisz. Jedyne co pamiêtasz to 3 rzeczy:\n1) masz oddaæ poœciel do prania i zap³aciæ za pranie\n2) masz zadzwoniæ do mamy, aby powiedzieæ jej, ¿e u Ciebie wszystko w porz¹dku\n3) najwa¿niejsze - dziœ o 14:00 masz egzamin, a zaraz po nim musisz biec na poci¹g do domu.\n";
	cout << "Jest godzina 10:00. W portfelu 10z³. Dramat...\n\n";
	cout << "********** GRA ROZPOCZÊTA! ***********\n\n";
	while (usedSlots < 16)
	{
		cout << "Jest godzina " << getTimeFromSlots(usedSlots) << "\n";
		cout << "Co zamierzasz teraz zrobiæ ?\n";
		cout << "1) Iœæ do sklepu\n";
		cout << "2) Zadzwoniæ do mamy\n";
		cout << "3) Iœæ do kumpla z s¹siedniego akademika\n";
		cout << "4) Iœæ do pralni\n";
		cout << "4) Iœæ na uczelnie\n";
		cout << "5) Zacz¹æ p³akaæ\n";
		cout << "6) Iœæ do swojego pokoju w akademiku\n";
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
			cout << "Nieprawid³owy numer...\n";
		}
	}
	return 0;
}
