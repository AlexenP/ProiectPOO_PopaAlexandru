#pragma once
#include <iostream>

// TODO: operator=
using namespace std;
class CodificareScaune
{
private:
	string numeCategorie;//categorie A-1, B-2
	int numarRanduri;
	int randInceput;
	int** locuriScaune;// rand, coloana-minima, coloana-maxima - localizarea categoriei in sala
public:
	CodificareScaune();
	CodificareScaune(string numeCategorie, int numar_randuri, int rand_de_inceput, int** locuriScaune);
	~CodificareScaune();
	string getNumeCategorie();
	void setNumeCategorie(string numeCategorie);
	int getNumarRanduri();
	void setNumarRanduri(int numarRanduri);
	int getRandInceput();
	void setRandInceput(int randInceput);
	int** getLocuriScaune();
	void setLocuriScaune(int** locuriScaune);
	CodificareScaune& operator=(const CodificareScaune& c);
	bool operator!();
	friend ostream& operator<<(ostream&, CodificareScaune);
	friend istream& operator>>(istream&, CodificareScaune&);
	// 2 metode generice
	int numarLocuriTotale(); //cate locuri sunt in total
	bool categoriePremium(CodificareScaune c); //daca numarul total de locuri este <=5 atunci functia va returna true
};

