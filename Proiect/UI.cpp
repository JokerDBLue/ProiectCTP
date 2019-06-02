#include "UI.h"
#include <ctime>


UI::UI()
{
}

string UI::citesteLinia()
{
	cout << "Dati linia dorita: ";
	char s[30];
	cin >> s;
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
	while (strlen(s) != 9)
	{
		cout << "Cod: ";
		cin >> s;
	}
	return s;
}

string UI::citesteCodspate()
{
	cout << "Codspate: ";
	char s[30];
	cin >> s;
	while (strlen(s) != 3)
	{
		cout << "Codspate: ";
		cin >> s;
	}
	return s;
}

string UI::datiInceput()
{
	cout << "Statie de inceput: ";
	char s[30];
	cin.ignore();
	cin.getline(s, sizeof s);
	return s;
}

string UI::datiSfarsit()
{
	cout << "Statie de sfarsit: ";
	char s[30];
	cin.getline(s, sizeof s);
	return s;
}

string UI::datiZiua()
{
	cout << "Ziua dorita 'L-V'(luni pana vineri) sau 'S-D'(sambata si duminica) sau 'auto'(pentru ziua curenta)\n";
	char s[30];
	cin >> s;
	while ((strcmp(s, "L-V") != 0) && (strcmp(s, "S-D") != 0) && (strcmp(s, "auto") != 0))
	{
		cout << "Ziua dorita 'L-V'(luni pana vineri) sau 'S-D'(sambata si duminica) sau 'auto'(pentru ziua curenta)\n";
		cin >> s;
	}
	return s;
}

int UI::datiNrBilet()
{
	cout << "Nr de ordine al biletului: ";
	int nr;
	while (!(cin >> nr)) {
		cin.ignore();
		cin.clear();
		cout << "Nr de ordine al biletului: ";
	}
	return nr;
}

int UI::datiCantNoua()
{
	cout << "Dati cantitatea noua: ";
	int nr;
	while (!(cin >> nr)) {
		cin.ignore();
		cin.clear();
		cout << "Dati cantitatea noua: ";
	}
	return nr;
}

int UI::datiTipBilet()
{
	cout << "Zona pentru care doriti biletul: ";
	int z;
	while (!(cin >> z)) {
		cin.ignore();
		cin.clear();
		cout << "Zona pentru care doriti biletul: ";
	}
	return z;
}

int UI::datiCantBilete()
{
	int c;
	cout << "Dati numarul de bilete dorite: ";
	while (!(cin >> c)) {
		cin.ignore();
		cin.clear();
		cout << "Dati numarul de bilete dorite: ";
	}
	return c;
}

void UI::clearScreen()
{
	string com;
	while (com != "inapoi")
	{
		cout << "Scrieti 'inapoi' pentu a merge la meniul principal\n";
		com = datiComanda();
	}
}

void UI::citesteDatele()
{
	c.ReadUseri("useri.txt");
	c.readBilete("bilete.txt");
	c.readAutobuze("30.txt");
	c.readAutobuze("30W.txt");
	c.readAutobuze("M31.txt");
	c.readAutobuze("24.txt");
	c.readAutobuze("24B.txt");
}

void UI::login()
{
}


void UI::infoBilete()
{
	cout << c.bileteValabile();
}

void UI::cumparaturi(int nrUser)
{
	string com;
	while (com != "menu")
	{
		system("CLS");
		cout << "Scrieti 'adauga' pentru a adauga in cos\n";
		cout << "Scrieti 'sterge' pentru a sterge un element din cos\n";
		cout << "Scrieti 'schimba' pentru a schimba cantitatea unui element din cos\n";
		cout << "Scrieti 'finalizare' pentru a finaliza comanda\n";
		cout << "Scrieti 'menu' pentru a iesi\n";
		cout << "Cosul de cumparaturi\n";
		cout << c.getCos(nrUser) << endl;
		com = datiComanda();
		if (com == "adauga")
		{
			int zona;
			int cant;
			zona = datiTipBilet();
			cant = datiCantBilete();
			try {
				c.cumparareBilete(cant, nrUser, zona);
			}
			catch(exception& e)
			{
				cout << e.what();
			}
		}
		else
			if (com == "sterge")
			{
				int nrBilet;
				nrBilet = datiNrBilet();
				try {
					c.stergeBilet(nrUser, nrBilet);
				}
				catch(exception& e){
					cout << e.what();
				}
			}
			else
				if (com == "schimba")
				{
					int nrBilet;
					int newCant;
					nrBilet = datiNrBilet();
					newCant = datiCantNoua();
					try {
						c.schimbaCant(nrUser, nrBilet, newCant);
					}
					catch(exception& e){
						cout << e.what();
					}
				}
				else
					if (com == "finalizare")
					{
						string cod, codspate;
						cod = citesteCod();
						codspate = citesteCodspate();
						int rez = c.finalizarePlata(cod, codspate, nrUser);
						if (rez == 0)
						{
							cout << "Plata a fost facuta cu succes\n";
							c.WriteRegister("useri.txt");
						}
						else
							if (rez == 1)
							{
								cout << "Datele introduse nu sunt corecte\n";
							}
							else
								if (rez == 2)
								{
									cout << "Nu aveti destui bani in contul bancar\n";
								}
						clearScreen();
					}
	}
}

void UI::optiuniUtilizator()
{
	cout << "Scrieti 'linie' pentru a cauta o linie " << endl;
	cout << "Scrieti 'statii' pentru a cauta autobuzele care merg de la o stati la alta" << endl;
	cout << "Scrieti 'bilete' pentru a cauta biletele valabile " << endl;
	cout << "Scrieti 'inventar' pentru a va putea vedea biletele " << endl;
	cout << "Scrieti 'cumparaturi' pentru a putea cumpara " << endl;
	cout << "Scrieti 'logout' pentru a va deloga" << endl;
}

void UI::optiuni()
{
	cout << "Scrieti 'linie' pentru a cauta o linie " << endl;
	cout << "Scrieti 'statii' pentru a cauta autobuzele care merg de la o stati la alta" << endl;
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
		system("CLS");
		optiuniUtilizator();
		com = datiComanda();
		if (com == "linie")
		{
			string linie;
			linie = citesteLinia();
			try {
				cout << c.cuatareLinie(linie);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			clearScreen();
		}
		else
			if (com == "statii")
			{
				string inceput, sfarsit, ziua;
				inceput = datiInceput();
				sfarsit = datiSfarsit();
				ziua = datiZiua();
				if (ziua == "auto") {
					time_t rawtime;
					tm * timeinfo;
					time(&rawtime);
					timeinfo = localtime(&rawtime);
					int wday = timeinfo->tm_wday;
					if ((wday > 0) && (wday <= 5))
						ziua = "L-V";
					else
						ziua = "S-D";
				}
				try {
					cout << c.cautareAuto(inceput, sfarsit, ziua);
				}
				catch (exception& e)
				{
					cout << e.what();
				}
				clearScreen();
			}
			else
				if (com == "bilete")
				{
					infoBilete();
					clearScreen();
				}
				else
					if (com == "inventar")
					{
						cout << c.vizualizireInventar(nrUser);
						clearScreen();
					}
					else
						if (com == "cumparaturi")
						{
							cumparaturi(nrUser);
						}
	}
}

void UI::comanda()
{
	citesteDatele();
	string com = "";
	while (com != "exit")
	{
		system("CLS");
		optiuni();
		com = datiComanda();
		if (com == "linie")
		{
			string linie;
			linie = citesteLinia();
			try {
				cout << c.cuatareLinie(linie);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			clearScreen();
		}
		else
		if (com == "statii")
		{
			string inceput, sfarsit, ziua;
			inceput = datiInceput();
			sfarsit = datiSfarsit();
			ziua = datiZiua();
			if (ziua == "auto") {
				time_t rawtime;
				tm * timeinfo;
				time(&rawtime);
				timeinfo = localtime(&rawtime);
				int wday = timeinfo->tm_wday;
				if ((wday > 0) && (wday <= 5))
					ziua = "L-V";
				else
					ziua = "S-D";
			}
			try {
				cout << c.cautareAuto(inceput, sfarsit, ziua);
			}
			catch (exception& e)
			{
				cout << e.what();
			}
			clearScreen();
		}
		else
			if (com == "bilete")
			{
				infoBilete();
				clearScreen();
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
					{
						cout << "User inexistent! :(" << endl;
						clearScreen();
					}
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
						try {
							c.Register(user, parola, cod, codspate, "useri.txt");
						}catch (exception& e)
						{
							cout << e.what();
						}
						clearScreen();
					}
	}
}

UI::~UI()
{
}
