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
	bool laundryDone = false;
	bool preparedToExam = false;
	bool mamaCalled = false;
	bool onUniversity = false;

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
		cout << "\nJest godzina " << getTimeFromSlots(usedSlots) << "\n";
		cout << "Co zamierzasz teraz zrobiæ ?\n";
		cout << "1) Iœæ do sklepu\n";
		cout << "2) Zadzwoniæ do mamy\n";
		cout << "3) Iœæ do kumpla z s¹siedniego akademika\n";
		cout << "4) Iœæ do pralni\n";
		cout << "5) Zacz¹æ p³akaæ\n";
		cout << "6) Iœæ do swojego pokoju w akademiku\n";
		cout << "7) Iœæ na egzamin, na uczelnie\n";
		cout << "Wpisz numer akcji: ";
		cin >> input;
		if (input == "1") 
		{
			cout << "W sklepie do zakupu s¹:\n";
			cout << "1) Piwo - 2,50z³\n";
			cout << "2) Do³adowanie do telefonu - 5z³\n";
			cout << "3) Kanapka z szynk¹ - 5z³\n";
			cout << "4) D³ugopis - 2z³\n";
			cin >> input;
			if (input == "1") 
			{
				if (student.getCash() >= 2.5)
				{
					student.setCash(student.getCash() - 2.5);
					//TODO add item Piwo to student items
				}
				else
				{
					cout << "Nie masz wystarczaj¹co pieniêdzy\n";
				}
				usedSlots++;
			}
			else if (input == "2")
			{
				if (student.getCash() >= 5.0)
				{
					student.setCash(student.getCash() - 5.0);
					student.setCashOnPhone(true);
					cout << "Do³adowujesz telefon!\n";
				}
				else
				{
					cout << "Nie masz wystarczaj¹co pieniêdzy\n";
				}
				usedSlots++;
			}
			else if (input == "3")
			{
				if (student.getCash() >= 5.0)
				{
					student.setCash(student.getCash() - 5.0);
					cout << "Kanapka kupiona";
					//TODO add item "kanapka" to student items
				}
				else
				{
					cout << "Nie masz wystarczaj¹co pieniêdzy\n";
				}
				usedSlots++;
			}
			else if (input == "4")
			{
				if (student.getCash() >= 2.0)
				{
					student.setCash(student.getCash() - 2.0);
					cout << "D³ugopis kupiony";
					//TODO add item "d³ugopis" to student items
				}
				else
				{
					cout << "Nie masz wystarczaj¹co pieniêdzy\n";
				}
				usedSlots++;
			}
			else
			{
				cout << "Nieprawid³owy numer...\n";
			}
		}
		else if (input == "2") 
		{
			if (student.getCashOnPhone()) {
				cout << "D³ugo rozmawiasz z mam¹ i przekonujesz j¹, ¿e radzisz sobie œwietnie\n";
				mamaCalled = true;
			}
			else {
				cout << "Na koncie nie masz ani grosza. Musisz najpierw do³adowaæ telefon.\n";
			}
			usedSlots++;
		}
		else if (input == "3")
		{
			cout << "Kumpel jest strasznie g³odny. Nakarmisz go ? (t/n)\n";
			cin >> input;
			if (input == "t") {
				if (student.hasItem("kanapka")) {
					cout << "Kumpel zjada pyszn¹ kanapke po czym oddaje Ci po¿yczone wczoraj 30z³.\n";
					student.setCash(student.getCash() + 30.0);
				}
				else {
					cout << "Nie masz go czym poczêstowaæ wiêc nawet nie wpuszcza Cie do pokoju.\n";
				}
			}
			else {
				cout << "Kumpel nie ma ochoty gadaæ, gdy jest taki g³odny.\n";
			}
			usedSlots++;
		}
		else if (input == "4")
		{
			if (student.hasItem("pranie")) {
				if (student.getCash() >= 20.0) {
					cout << "Oddajesz pranie do prania.Kosztuje Cie to 20z³.\n";
					student.setCash(student.getCash() - 20.0);
					laundryDone = true;
				}
				else {
					cout << "Nie masz wystarczaj¹co gotówki, aby zap³aciæ za pranie.\n";
				}
			}
			else {
				cout << "Nie wzi¹³eœ ze sob¹ prania. Zostawi³eœ je w pokoju.\n";
			}
			usedSlots++;
		}
		else if (input == "5")
		{
			cout << "P³aczesz d³ugo i g³oœno, u¿alaj¹c siê nad ciê¿kim losem studenta...\n";
			usedSlots++;
		}
		else if (input == "6")
		{
			cout << "Co chcesz zrobiæ w pokoju ?\n";
			cout << "1) Pozbieraæ i spakowaæ do plecaka brudne ciuchy do pralni.\n";
			cout << "2) Pouczyæ siê do egzaminu (30min).\n";
			cin >> input;
			if (input == "1") {
				cout << "Zbierasz i pakujesz brudne ciuchy do pralni.\n";
				//TODO add item "pranie"
				usedSlots++;
			}
			else if (input == "2") {
				cout << "Uczysz siê do egzaminu. Po pó³ godzinie nauki czujesz, ¿e umiesz na 3.0.\n";
				preparedToExam = true;
				usedSlots = usedSlots + 2;
			}
			else {
				cout << "Niepoprawny numer...\n";
			}
		}
		else if (input == "7")
		{
			if (student.hasItem("d³ugopis")) {
				onUniversity = true;
				while (onUniversity && (usedSlots < 16)) {
					cout << "\nJest godzina " << getTimeFromSlots(usedSlots) << "\n";
					cout << "Jest jeszcze troche czasu do egzaminu. Zostajesz na uczelni ?(t/n)\n";
					cin >> input;
					if (input == "n") {
						onUniversity = false;
					}
					usedSlots++;
				}
			}
			else {
				cout << "Na uczelni przypominasz sobie, ¿e nie masz przy sobie d³ugopisu wiêc wracasz na miasteczko studenckie.\n";
			}
			usedSlots++;
		}
		else
		{
			cout << "Nieprawid³owy numer...\n";
		}
	}

	if (onUniversity) {
		if (student.hasItem("d³ugopis")) {
			if (preparedToExam) {
				cout << "+ Zdajesz egzamin na wymarzone 3.0\n";
			}
			else {
				cout << "- Nie przygotowa³eœ siê do egzaminu. Oddajesz pust¹ kartkê.\n";
			}
		}
		else {
			cout << "- Przez brak d³ugopisu nie masz czym wype³niæ egzaminu.\n";
		}
	}
	else {
		cout << "- SpóŸniasz siê na egzamin...\n";
	}

	if (laundryDone) {
		cout << "+ Czyste i pachn¹ce pranie czekaæ bêdzie na Ciebie po powrocie na miasteczko\n";
	}
	else {
		cout << "- Œmierdz¹ce ciuchy dalej walaj¹ siê po ca³ym Twoim pokoju\n";
	}

	if (mamaCalled) {
		cout << "+ Mama wie, ¿e wszystko u Ciebie w porz¹dku\n";
	}
	else {
		cout << "- Mama jest wœciek³a, bo nie odezwa³eœ siê od tygodnia\n";
	}

	cout << "\n\n";
	if (onUniversity && student.hasItem("d³ugopis") && laundryDone && mamaCalled) {
		cout << "***********ZWYCIÊSTWO!!***********";
	}
	else {
		cout << "***********PORA¯KA!!***********";
	}

	cin >> input;

	return 0;
}
