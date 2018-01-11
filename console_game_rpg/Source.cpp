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
		cout << "\nJest godzina " << getTimeFromSlots(usedSlots) << "\n";
		cout << "Co zamierzasz teraz zrobi� ?\n";
		cout << "1) I�� do sklepu\n";
		cout << "2) Zadzwoni� do mamy\n";
		cout << "3) I�� do kumpla z s�siedniego akademika\n";
		cout << "4) I�� do pralni\n";
		cout << "5) Zacz�� p�aka�\n";
		cout << "6) I�� do swojego pokoju w akademiku\n";
		cout << "7) I�� na egzamin, na uczelnie\n";
		cout << "Wpisz numer akcji: ";
		cin >> input;
		if (input == "1") 
		{
			cout << "W sklepie do zakupu s�:\n";
			cout << "1) Piwo - 2,50z�\n";
			cout << "2) Do�adowanie do telefonu - 5z�\n";
			cout << "3) Kanapka z szynk� - 5z�\n";
			cout << "4) D�ugopis - 2z�\n";
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
					cout << "Nie masz wystarczaj�co pieni�dzy\n";
				}
				usedSlots++;
			}
			else if (input == "2")
			{
				if (student.getCash() >= 5.0)
				{
					student.setCash(student.getCash() - 5.0);
					student.setCashOnPhone(true);
					cout << "Do�adowujesz telefon!\n";
				}
				else
				{
					cout << "Nie masz wystarczaj�co pieni�dzy\n";
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
					cout << "Nie masz wystarczaj�co pieni�dzy\n";
				}
				usedSlots++;
			}
			else if (input == "4")
			{
				if (student.getCash() >= 2.0)
				{
					student.setCash(student.getCash() - 2.0);
					cout << "D�ugopis kupiony";
					//TODO add item "d�ugopis" to student items
				}
				else
				{
					cout << "Nie masz wystarczaj�co pieni�dzy\n";
				}
				usedSlots++;
			}
			else
			{
				cout << "Nieprawid�owy numer...\n";
			}
		}
		else if (input == "2") 
		{
			if (student.getCashOnPhone()) {
				cout << "D�ugo rozmawiasz z mam� i przekonujesz j�, �e radzisz sobie �wietnie\n";
				mamaCalled = true;
			}
			else {
				cout << "Na koncie nie masz ani grosza. Musisz najpierw do�adowa� telefon.\n";
			}
			usedSlots++;
		}
		else if (input == "3")
		{
			cout << "Kumpel jest strasznie g�odny. Nakarmisz go ? (t/n)\n";
			cin >> input;
			if (input == "t") {
				if (student.hasItem("kanapka")) {
					cout << "Kumpel zjada pyszn� kanapke po czym oddaje Ci po�yczone wczoraj 30z�.\n";
					student.setCash(student.getCash() + 30.0);
				}
				else {
					cout << "Nie masz go czym pocz�stowa� wi�c nawet nie wpuszcza Cie do pokoju.\n";
				}
			}
			else {
				cout << "Kumpel nie ma ochoty gada�, gdy jest taki g�odny.\n";
			}
			usedSlots++;
		}
		else if (input == "4")
		{
			if (student.hasItem("pranie")) {
				if (student.getCash() >= 20.0) {
					cout << "Oddajesz pranie do prania.Kosztuje Cie to 20z�.\n";
					student.setCash(student.getCash() - 20.0);
					laundryDone = true;
				}
				else {
					cout << "Nie masz wystarczaj�co got�wki, aby zap�aci� za pranie.\n";
				}
			}
			else {
				cout << "Nie wzi��e� ze sob� prania. Zostawi�e� je w pokoju.\n";
			}
			usedSlots++;
		}
		else if (input == "5")
		{
			cout << "P�aczesz d�ugo i g�o�no, u�alaj�c si� nad ci�kim losem studenta...\n";
			usedSlots++;
		}
		else if (input == "6")
		{
			cout << "Co chcesz zrobi� w pokoju ?\n";
			cout << "1) Pozbiera� i spakowa� do plecaka brudne ciuchy do pralni.\n";
			cout << "2) Pouczy� si� do egzaminu (30min).\n";
			cin >> input;
			if (input == "1") {
				cout << "Zbierasz i pakujesz brudne ciuchy do pralni.\n";
				//TODO add item "pranie"
				usedSlots++;
			}
			else if (input == "2") {
				cout << "Uczysz si� do egzaminu. Po p� godzinie nauki czujesz, �e umiesz na 3.0.\n";
				preparedToExam = true;
				usedSlots = usedSlots + 2;
			}
			else {
				cout << "Niepoprawny numer...\n";
			}
		}
		else if (input == "7")
		{
			if (student.hasItem("d�ugopis")) {
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
				cout << "Na uczelni przypominasz sobie, �e nie masz przy sobie d�ugopisu wi�c wracasz na miasteczko studenckie.\n";
			}
			usedSlots++;
		}
		else
		{
			cout << "Nieprawid�owy numer...\n";
		}
	}

	if (onUniversity) {
		if (student.hasItem("d�ugopis")) {
			if (preparedToExam) {
				cout << "+ Zdajesz egzamin na wymarzone 3.0\n";
			}
			else {
				cout << "- Nie przygotowa�e� si� do egzaminu. Oddajesz pust� kartk�.\n";
			}
		}
		else {
			cout << "- Przez brak d�ugopisu nie masz czym wype�ni� egzaminu.\n";
		}
	}
	else {
		cout << "- Sp�niasz si� na egzamin...\n";
	}

	if (laundryDone) {
		cout << "+ Czyste i pachn�ce pranie czeka� b�dzie na Ciebie po powrocie na miasteczko\n";
	}
	else {
		cout << "- �mierdz�ce ciuchy dalej walaj� si� po ca�ym Twoim pokoju\n";
	}

	if (mamaCalled) {
		cout << "+ Mama wie, �e wszystko u Ciebie w porz�dku\n";
	}
	else {
		cout << "- Mama jest w�ciek�a, bo nie odezwa�e� si� od tygodnia\n";
	}

	cout << "\n\n";
	if (onUniversity && student.hasItem("d�ugopis") && laundryDone && mamaCalled) {
		cout << "***********ZWYCI�STWO!!***********";
	}
	else {
		cout << "***********PORA�KA!!***********";
	}

	cin >> input;

	return 0;
}
