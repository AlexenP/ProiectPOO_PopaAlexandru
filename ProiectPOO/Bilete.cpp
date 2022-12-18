#include "Bilete.h"


Bilete::Bilete() {
	id_bilet = 0;
	numeCumparator = "Necunoscut";
	pret = 0;
	categorie = "Necunoscuta";
}

Bilete::Bilete(int id_bilet, string numeCumparator, double pret, string categorie)
{
	this->id_bilet = id_bilet;
	this->numeCumparator = numeCumparator;
	this->pret = pret;
	this->categorie = categorie;
}

int Bilete::getIdBilet()
{
	return this->id_bilet;
}

void Bilete::setIdBilet(int id_bilet) 
{
	if (id_bilet>0)
		this->id_bilet = id_bilet;
}

string Bilete::getNumeCumparator() 
{
	return this->numeCumparator;
}

void Bilete::setNumeCumparator(string numeCumparator)
{
	if (isupper(numeCumparator[0]))
		this->numeCumparator = numeCumparator;
}

double Bilete::getPret()
{
	return this->pret;
}

void Bilete::setPret(double pret)
{
	if (pret >= 0)
		this->pret = pret;
}

string Bilete::getCategorie()
{
	return this->categorie;
}

void Bilete::setCategorie(string categorie)
{
	this->categorie = categorie;
}



void Bilete::reducereSfantulAndrei() 
{
	if (this->numeCumparator.find("Andrei") || this->numeCumparator.find("Andreea"))
	{
		this->pret = this->pret - 0.1 * this->pret;
	}
}

ostream& operator<<(ostream& out, Bilete b)
{
	out << "id_bilet: " << b.id_bilet << endl;
	out << "numeCumparator: " << b.numeCumparator << endl;
	out << "pret: " << b.pret << endl;
	out << "categorie: " << b.categorie << endl;
	return out;
}


istream& operator>>(istream& in, Bilete& b)
{
	cout << "id_bilet = ";
	in >> b.id_bilet;
	cout << "nume cumparator = ";
	in >> b.numeCumparator;
	cout << "pret = ";
	in >> b.pret;
	cout << "categorie = ";
	in >> b.categorie;
	return in;
}

Bilete Bilete::operator+(double pret)
{
	Bilete copie = *this;
	this->pret += pret;
	return copie;
}

Bilete::operator string() 
{
	return this->categorie;
}

void Bilete::biletulNorocos()
{
	if (getIdBilet() == 32)
	{
		setCategorie("VIP");
		setPret(0);
	}
}