#include "Locatie.h"
int Locatie::numarMaximLocuri = 200;

Locatie::Locatie()
{
	numarRanduriTotale = 0;
	nrZone = 0;
	numeLocatie = nullptr;
	locuriPerZone = nullptr;
}

Locatie::Locatie(char* numeLocatie, int numarRanduriTotale, int nrZone, CodificareScaune* LocuriPerZone)
{
	this->numeLocatie = new char[strlen(numeLocatie)+1];
	strcpy_s(this->numeLocatie, strlen(numeLocatie) + 1, numeLocatie);
	this->numarRanduriTotale = numarRanduriTotale;
	if (nrZone < 0) {
		this->nrZone = 0;
	}
	else this->nrZone = nrZone;
	if (locuriPerZone != nullptr)
	{
		this->locuriPerZone = new CodificareScaune[nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->locuriPerZone[i] = locuriPerZone[i];
		}
	}

}

Locatie::~Locatie()
{
	if(locuriPerZone !=nullptr)
		delete[] locuriPerZone;
	if (numeLocatie != nullptr)
		delete[] numeLocatie;
}


int Locatie::getNumarMaximLocuri()
{
	return numarMaximLocuri;
}

void Locatie::setNumarMaximLocuri(int numarMaximLocuri)
{
	Locatie::numarMaximLocuri = numarMaximLocuri;
}

int Locatie::getNumarRanduriTotale()
{
	return numarRanduriTotale;
}

void Locatie::setNumarRanduriTotale(int numarRanduriTotale)
{
	if (numarRanduriTotale > 0)
		this->numarRanduriTotale = numarRanduriTotale;
	else this->numarRanduriTotale = 0;
}

int Locatie::getNrZone()
{
	return this->nrZone;
}

void Locatie::setMrZone(int nrZone)
{
	if (nrZone > 0)
		this->nrZone = nrZone;
	else this->nrZone = 0;
}

CodificareScaune* Locatie::getLocuriPerZone()
{
	if (locuriPerZone != nullptr && getNrZone() != 0)
	{
		CodificareScaune* copie = new CodificareScaune[nrZone];
		for (int i = 0; i < getNumarRanduriTotale(); i++)
		{
			copie[i] = locuriPerZone[i];
		}
		return copie;
	}
	else return nullptr;
}

void Locatie::setLocuriPerZone(CodificareScaune* locuriPerZone)
{
	if (locuriPerZone != nullptr && nrZone != 0)
	{
		if (this->locuriPerZone != nullptr)
		{
			delete[] this->locuriPerZone;
		}
		this->locuriPerZone = new CodificareScaune[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			this->locuriPerZone[i] = locuriPerZone[i];
		}
	}
}

string Locatie::getNumeLocatie() {
	return this->numeLocatie;
}

void Locatie::setNumeLocatie(const char* numeLocatie) {
	if (numeLocatie != nullptr)
	{
		delete[] this->numeLocatie;
	}

	this->numeLocatie = new char[strlen(numeLocatie)+1];
	strcpy_s(this->numeLocatie, strlen(numeLocatie) + 1, numeLocatie);
}

ostream& operator<<(ostream& out, Locatie l)
{
	out << "nume Locatie: " << l.numeLocatie;
	out << "numarRanduriTotale: " << l.numarRanduriTotale;
	out << "numar zone: " << l.nrZone;
	out << "Locuri per zone: ";
	if (l.locuriPerZone != nullptr) 
	{
		for (int i = 0; i < l.nrZone; i++)
		{
			out << l.locuriPerZone[i] << " ";
		}
	}
	return out;
}

istream& operator>>(istream& in, Locatie& l)
{
	cout << "nume Locatie = ";
	in >> l.numeLocatie;
	cout << "numarRanduriTotale = ";
	in >> l.numarRanduriTotale;
	cout << "numar zone = ";
	in >> l.nrZone;
	if (l.locuriPerZone != nullptr) {
		delete[] l.locuriPerZone;
	}
	if (l.nrZone > 0)
	{
		l.locuriPerZone = new CodificareScaune[l.nrZone];
		for (int i = 0; i < l.nrZone; i++) {
			cout << "zona numarul " << i + 1 << ":";
			in >> l.locuriPerZone[i];
		}
	}
	else
	{
		l.nrZone = 0;
		l.locuriPerZone = nullptr;
	}
	return in;
}

Locatie Locatie::operator+(int nrRanduri)
{
	Locatie copie = *this;
	if (numarLocuriOcupate() < numarMaximLocuri)
		copie.numarRanduriTotale += nrRanduri;
	return copie;
}

Locatie Locatie::operator++()
{
	if (numarLocuriOcupate() < numarMaximLocuri)
		this->numarRanduriTotale++;
	return *this;
}

void Locatie::extindere()
{
	if (nrZone >= 3 && numarLocuriOcupate() < numarMaximLocuri)
		this->numarRanduriTotale++;
}

int Locatie::numarLocuriOcupate()
{
	int total = 0;
	if (this->locuriPerZone != nullptr)
	{
		for (int i = 0; i < this->nrZone; i++) 
		{
			int locuriCategorie = this->locuriPerZone[i].numarLocuriTotale();
			total += locuriCategorie;
		}
	}
	return total;
}