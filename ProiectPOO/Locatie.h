#pragma once
#include <iostream>
#include <string>
#include "CodificareScaune.h"

using namespace std;
class Locatie
{
private:
	static int numarMaximLocuri;
	char* numeLocatie;
	int numarRanduriTotale;
	int nrZone;
	CodificareScaune* locuriPerZone; //toate categoriile impreuna cu localizarea lor in sala
public:
	Locatie();
	Locatie(char* numeLocatie,int numarRanduriTotale, int nrZone, CodificareScaune* LocuriPerZone);
	~Locatie();
	static int getNumarMaximLocuri();
	static void setNumarMaximLocuri(int numarMaximLocuri);
	string getNumeLocatie();
	void setNumeLocatie(const char* numeLocatie);
	int getNumarRanduriTotale();
	void setNumarRanduriTotale(int numarRanduriTotale);
	int getNrZone();
	void setMrZone(int nrZone);
	CodificareScaune* getLocuriPerZone();
	void setLocuriPerZone(CodificareScaune* nrLocuriPerZone);
	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);
	Locatie operator+(int nrRanduri);
	Locatie operator++();
	void extindere();//daca sunt mai mult de 3 zone, atunci numarRanduriTotale va creste cu o unitate
	int numarLocuriOcupate();// se calculeaza suma totala a numarul de locuri actuale

};

