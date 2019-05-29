#include "UI.h"



UI::UI()
{
}

string UI::citesteLinia()
{
	cout << "Dati linia dorita: ";
	char s[30];
	cin >> s;
	while ((strcmp(s, "M31") != 0) && (strcmp(s, "M30") != 0))
	{
		cout << "Linia nu exista, va rugam sa introduceti alta linie: ";
		cin >> s;
	}
	return s;
}

string UI::datiComanda()
{
	cout << "Comanda este: ";
	char s[30];
	cin >> s;
	return s;
}

string UI::citesteUser()
{
	cout << "Username: ";
	char s[30];
	cin >> s;
	return s;
}

string UI::citesteParola()
{
	cout << "Parola: ";
	char s[30];
	cin >> s;
	return s;
}

string UI::citesteCod()
{
	cout << "Cod: ";
	char s[30];
	cin >> s;
	return s;
}

string UI::citesteCodspate()
{
	cout << "Codspate: ";
	char s[30];
	cin >> s;
	return s;
}

void UI::citesteDatele()
{
	c.ReadUseri();
	c.readBilete("bilete.txt");
	c.readAutobuze("M30.txt");
	c.readAutobuze("M31.txt");
}

void UI::login()
{
}


void UI::infoBilete()
{
	cout << c.bileteValabile();
}

void UI::optiuniUtilizator()
{
	cout << "Scrieti 'linie' pentru a cauta o linie " << endl;
	cout << "Scrieti 'bilete' pentru a cauta biletele valabile " << endl;
	cout << "Scrieti 'inventar' pentru a va putea vedea biletele " << endl;
	cout << "Scrieti 'cumparaturi' pentru a putea cumpara " << endl;
	cout << "Scrieti 'logout' pentru a va deloga" << endl;
	cout << "Scrieti 'exit' pentru a iesi " << endl;
}

void UI::optiuni()
{
	cout << "Scrieti 'linie' pentru a cauta o linie " << endl;
	cout << "Scrieti 'bilete' pentru a cauta biletele valabile " << endl;
	cout << "Scrieti 'login' pentru a va loga" << endl;
	cout << "Scrieti 'register' pentru a va creea un cont" << endl;
	cout << "Scrieti 'exit' pentru a iesi " << endl;
}

void UI::comandaUtilizator(int nrUser)
{
	cout << "Bine ati venit!!! :)" << endl;
	string com = "";
	while ((com != "exit") && (com != "logout"))
	{
		optiuniUtilizator();
		com = datiComanda();
		if (com == "cautare linie")
		{
			string linie;
			linie = citesteLinia();
			cout << c.cuatareLinie(linie);
		}
		else
			if (com == "bilete")
			{
				infoBilete();
			}
			else
				if (com == "inventar")
				{
					cout << c.vizualizireInventar(nrUser);
				}
	}
}

void UI::comanda()
{
	citesteDatele();
	string com = "";
	while (com != "exit")
	{
		optiuni();
		com = datiComanda();
		if (com == "linie")
		{
			string linie;
			linie = citesteLinia();
			cout << c.cuatareLinie(linie);
		}
		else
			if (com == "bilete")
			{
				infoBilete();
			}
			else
				if (com == "login")
				{
					string user, parola;
					user = citesteUser();
					parola = citesteParola();
					int d = c.VerifyLogin(user, parola);
					if (d != -1)
						comandaUtilizator(d);
					else
						cout << "User inexistent! :(" << endl;
				}
				else
					if (com == "register")
					{
						string user, parola, cod, codspate;
						float balans = 0;
						user = citesteUser();
						parola = citesteParola();
						cod = citesteCod();
						codspate = citesteCodspate();
						c.Register(user,parola,cod,codspate);
					}
	}
}

UI::~UI()
{
}
