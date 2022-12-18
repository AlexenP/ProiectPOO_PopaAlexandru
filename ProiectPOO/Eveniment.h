#pragma once
#include <iostream>
#include <string>
#include "Bilete.h"


using namespace std;

class Eveniment
{
private:
	const string denumire;
	int zi;
	int luna;
	int an;
	int oraInceput;
	int oraSfarsit;
	int nrBilete;
	Bilete* bilete; // retine biletele pentru eveniment
	
public:
	Eveniment();
	Eveniment(const string denumire, int zi, int luna, int an, int oraInceput, int oraSfarsit, int nrBilete, Bilete* bilete);
	~Eveniment();
	int getZi();
	int getLuna();
	int getAn();
	int getOraInceput();
	int getOraSfarsit();
	int getNrBilete();
	Bilete* getBilete();
	void setZi(int zi);
	void setLuna(int luna);
	void setAn(int an);
	void setOraInceput(int oraInceput);
	void setOraSfarsit(int oraSfarsit);
	void setNrBilete(int nrBilete);
	void setBilete(Bilete* bilete);
	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
	bool operator!();
	Bilete operator[](int index);
	int profitEveniment(); // determinati profitul evenimentului in conditiile in care 50% din pretul biletului reprezinta profitul dintr-un bilet
	void an2022(); //anul 2022 a avut o inflatie record, astfel preturile biletelor din anul 2022 va creste cu 10%
};

