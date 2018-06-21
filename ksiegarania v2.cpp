#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <fstream>

using namespace std;
int cenazapis;
int ilosczapis;
int zarobek;
class ksiazka
{
	private:
	char* autor,*tytul,*wydawca;
	float* cena;
	int* ilosc;
	public:
	ksiazka()
	{
		autor = new char[20];
		tytul = new char[20];
		wydawca = new char[20];
		cena = new float;
		ilosc = new int;

		}
        void dane();
        void edycja();
        void pokaz();
        int search(char[], char[]);
        void kup();
};


void ksiazka::dane()
{	cin.ignore();
	cout << "\n Podaj autora: "; cin.getline(autor, 20);
	cout << "Podaj tytul: "; cin.getline(tytul, 20);
	cout << "Podaj wydawace: "; cin.getline(wydawca, 20);
	cout << "Podaj cene: "; cin >> *cena;
	cout << "Podaj ilosc: "; cin >> *ilosc;
	}
void ksiazka::edycja()
{	cout << "\n Podaj autora: "; cin.getline(autor, 20);
	cout << "Podaj tytul: "; cin.getline(tytul, 20);
	cout << "Podaj wydawace: "; cin.getline(wydawca, 20);
	cout << "Podaj cene: "; cin >> *cena;
	cout << "Podaj ilosc: "; cin >> *ilosc;
	}
void ksiazka::pokaz()
{   cout << "\nAutor Name: " << autor;
	cout << "\nTytul Name: " << tytul;
	cout << "\nWydawca Name: " << wydawca;
	cout << "\nCena: " << *cena;
	cout << "\nDostepna ilosc: " << *ilosc;
}
int ksiazka::search(char akup[20], char tkup[20]  )
{
	if (strcmp(tkup, tytul) == 0 && strcmp(akup, autor) == 0)
		return 1;
	else return 0;
}
void ksiazka::kup()
{
	int count;

	cout << "\n Podaj liczbe ksiazki do kupienia: ";
	cin >> ilosczapis;
	if (ilosczapis <= *ilosc)
	{
		*ilosc = *ilosc - ilosczapis;
		cout << "\nKsiazki kupione pomyslnie";
		cout << "\nKwota:  " << (*cena) * ilosczapis;
        cenazapis = (*cena) * ilosczapis;
        zarobek = zarobek + cenazapis;
	}

	else
		cout << "\nBrak takiej ilosci ";
}
int main()
{
	ksiazka* B[20];
	int i = 0, r, t, wyborr;


	char autorpodany[20], tytulpodany[20];
	while (1)
	{
		cout << "\n\n\t\tMENU"
		<<"\n----------------------------------"
		<< "\n1. Dodaj nowa ksiazke "
		<< "\n2. Kup ksiazke"
		<< "\n3. Szukaj ksiazke"
		<< "\n4. Edytuj ksiazke"
		<< "\n5. Wyjdz"
		<< "\n\nPodaj swoj wybor: ";
		cin >> wyborr;

		switch (wyborr)
		{
			case 1:
				B[i] = new ksiazka;
				B[i]->dane();
				i++; break;

			case 2:
				cin.ignore();
				cout << "\nPodaj autora ksiazki: "; cin.getline(autorpodany, 20);
				cout << "Podaj tytul ksiazki: "; cin.getline(tytulpodany, 20);
				for (t = 0; t < i; t++)
				{
					if (B[t]->search(autorpodany, tytulpodany))
					{
						B[t]->kup();

                        fstream plik;
						plik.open("Paragon.txt",ios::out);
                        plik<<"KUPIONO: "<<ilosczapis<<endl;
                       // plik<<ilosczapis<<endl;
                        plik<<"ZAPLACONO: "<<cenazapis<<endl;
                        plik<<"Zysk z calego dnia:"<<zarobek<<endl;
						//plik<<cena<<endl;
						plik.close();

						break;
					}
				}
				if (t == 1)
					cout << "\nTej ksiazki nie ma w ksiegarni";

				break;
			case 3:
				cin.ignore();
				cout << "\nPodaj autora ksiazki: "; cin.getline(autorpodany, 20);
				cout << "Podaj tytul ksiazki: "; cin.getline(tytulpodany, 20);

				for (t = 0; t < i; t++)
				{
					if (B[t]->search(autorpodany, tytulpodany))
					{
						cout << "\n Ksiazka zostala znaleziona ";
						B[t]->pokaz();
						break;
					}
				}
				if (t == i)
					cout << "\nTej ksiazki nie ma w ksiegarni";
				break;

			case 4:
				cin.ignore();
				cout << "\nPodaj autora ksiazki: "; cin.getline(autorpodany, 20);
				cout << "Podaj tytul ksiazki: "; cin.getline(tytulpodany, 20);

				for (t = 0; t < i; t++)
				{
					if (B[t]->search(autorpodany, tytulpodany))
					{
						cout << "\nNie znaleziono";
						B[t]->edycja();
						break;
					}
				}
				if (t == i)
					cout << "\nTej ksiazki nie ma w ksiegarni";
				break;

			case 5: exit(0);
			default: cout << "\nZly wybor";

		}
	}
	return 0;
}
