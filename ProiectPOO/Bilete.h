#pragma once
#include <iostream>
#include <string>
using namespace std;


/*
* constructor implicit si cu parametrii
* getteri
* setteri cu validari
* 2metode generice
* operatorii >> si <<
* cel putin 2 operatori supraincarcati (curs6) ! si 
*/
class Bilete
{
private:
	int id_bilet;
	string numeCumparator;
	double pret;
	string categorie;
public:
	Bilete();
	Bilete(int id_bilet, string numeCumparator, double pret, string categorie);
	int getIdBilet();
	void setIdBilet(int id_bilet);
	string getNumeCumparator();
	void setNumeCumparator(string numeCumparator);
	double getPret();
	void setPret(double pret);
	string getCategorie();
	void setCategorie(string categorie);
	
	void reducereSfantulAndrei(); // toti cumparatorii cu numele "Andrei"/"Andreea" vor avea o reducere a biletului cu 10%
	void biletulNorocos(); // biletul cu id-ul 32 va fi cel norocos: biletul se transforma intr-un bilet gratuit si pretul biletului va fi 0
	friend ostream& operator<<(ostream&, Bilete);
	friend istream& operator>>(istream&, Bilete&);
	Bilete operator+(double pret);
	explicit operator string(); // return categorie
};

