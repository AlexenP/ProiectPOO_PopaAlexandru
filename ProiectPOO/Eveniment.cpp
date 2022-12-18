#include "Eveniment.h"

Eveniment::Eveniment() :denumire("Necunoscut")
{
	zi = 1;
	luna = 1;
	an = 2000;
	oraInceput = 7;
	oraSfarsit = 9;

	nrBilete = 0;
	bilete = nullptr;
}

Eveniment::Eveniment(const string denumireE, int zi, int luna, int an, int oraInceput, int oraSfarsit, int nrBilete, Bilete* bilete) :denumire(denumireE)
{
	if (zi >= 1 && zi <= 31)
		this->zi = zi;
	else this->zi = 1;

	if (luna <= 1 && luna <= 12)
		this->luna = luna;
	else this->luna = 1;

	if (an >= 1950 && an <= 2050)
		this->an = an;
	else this->an = 2000;

	if (oraInceput >= 0 && oraSfarsit <= 23)
		this->oraInceput = oraInceput;
	else this->oraInceput = 7;

	if (oraSfarsit >= 0 && oraSfarsit <= 23 && oraSfarsit > oraInceput)
		this->oraSfarsit = oraSfarsit;
	else this-> oraSfarsit = 9;

	if (nrBilete > 0)
		this->nrBilete = nrBilete;
	else this->nrBilete = 0;

	if (bilete != nullptr && nrBilete>0)
	{
		this->bilete = new Bilete[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->bilete[i] = bilete[i];
		}
	}

		
}

Eveniment::~Eveniment()
{
	if (bilete != nullptr)
		delete[] bilete;
	
}

int Eveniment::getZi()
{
	return zi;
}
int Eveniment::getLuna()
{
	return luna;
}
int Eveniment::getAn()
{
	return an;
}
int Eveniment::getOraInceput()
{
	return oraInceput;
}
int Eveniment::getOraSfarsit()
{
	return oraSfarsit;

}

int Eveniment::getNrBilete()
{
	return nrBilete;
}

Bilete* Eveniment::getBilete()
{
	if (bilete != nullptr && nrBilete != 0)
	{
		Bilete* copie = new Bilete[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			copie[i] = bilete[i];
		}
		return copie;
	}
	else return nullptr;
}

void Eveniment::setZi(int zi)
{
	if (zi >= 1 && zi <= 31)
		this->zi = zi;
	else this->zi = 1;
}
void Eveniment::setLuna(int luna)
{
	if (luna <= 1 && luna <= 12)
		this->luna = luna;
	else this->luna = 1;
}
void Eveniment::setAn(int an)
{
	if (an >= 1950 && an <= 2050)
		this->an = an;
	else this->an = 2000;
}
void Eveniment::setOraInceput(int oraInceput)
{
	if (oraInceput >= 0 && oraSfarsit <= 23)
		this->oraInceput = oraInceput;
	else this->oraInceput = 7;
}
void Eveniment::setOraSfarsit(int oraSfarsit)
{
	if (oraSfarsit >= 0 && oraSfarsit <= 23 && oraSfarsit > oraInceput)
		this->oraSfarsit = oraSfarsit;
	else this->oraSfarsit = 9;
}
	
void Eveniment::setNrBilete(int nrBilete)
{
	if (nrBilete > 0)
		this->nrBilete = nrBilete;
	else this->nrBilete = 0;
}

void Eveniment::setBilete(Bilete* bilete)
{
	if (bilete != nullptr && nrBilete > 0)
	{
		this->bilete = new Bilete[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->bilete[i] = bilete[i];
		}
	}
}

ostream& operator<<(ostream& out, Eveniment e)
{
	out << "denumire: " << e.denumire << endl;
	out << "zi: " << e.zi << endl;
	out << "luna: " << e.luna << endl;
	out << "an: " << e.an << endl;
	out << "oraInceput: " << e.oraInceput << endl;
	out << "oraSfarsit: " << e.oraSfarsit << endl;
	out << "numar bilete: " << e.nrBilete << endl;
	out << "biletele: " << endl << endl;
	if (e.bilete != nullptr)
	{
		for (int i = 0; i < e.nrBilete; i++)
		{
			out << e.bilete[i] << " ";
		}
	}
	return out;
}

/*
if (zi >= 1 && zi <= 31)
		this->zi = zi;
	else this->zi = 1;

	if (luna <= 1 && luna <= 12)
		this->luna = luna;
	else this->luna = 1;

	if (an >= 1950 && an <= 2050)
		this->an = an;
	else this->an = 2000;

	if (oraInceput >= 0 && oraSfarsit <= 23)
		this->oraInceput = oraInceput;
	else this->oraInceput = 7;

	if (oraSfarsit >= 0 && oraSfarsit <= 23 && oraSfarsit > oraInceput)
		this->oraSfarsit = oraSfarsit;
	else this-> oraSfarsit = 9;

	if (nrBilete > 0)
		this->nrBilete = nrBilete;
	else this->nrBilete = 0;

	if (bilete != nullptr && nrBilete>0)
	{
		this->bilete = new Bilete[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->bilete[i] = bilete[i];
		}
	}
*/
istream& operator>>(istream& in, Eveniment& e)
{
	cout << "zi: ";
	in >> e.zi;

	cout << "luna: ";
	in >> e.luna;
	
	cout << "an: ";
	in >> e.an;
	
	cout << "oraInceput: ";
	in >> e.oraInceput;
	
	cout << "oraSfarsit: ";
	in >> e.oraSfarsit;

	cout << "numar bilete: ";
	in >> e.nrBilete;

	cout << "biletele: ";
	if (e.bilete != nullptr) {
		delete[] e.bilete;
	}
	if (e.nrBilete > 0) {
		e.bilete = new Bilete[e.nrBilete];
		for (int i = 0; i < e.nrBilete; i++) {
			cout << "bilet " << i + 1 << ":";
			in >> e.bilete[i];
		}
	}
	else
	{
		e.nrBilete = 0;
		e.bilete = nullptr;
	}
	return in;
}

bool Eveniment::operator!()
{
	return bilete != nullptr;
}

Bilete Eveniment::operator[](int index)
{
	if (index >= 0 && index < nrBilete) {
		return bilete[index];
	}
	
}

int Eveniment::profitEveniment()
{
	int profit = 0;
	if (this->nrBilete > 0 && bilete != nullptr)
	{
		for (int i = 0; i < nrBilete; i++)
		{
			profit += bilete[i].getPret();
		}
	}
	profit /= 2;
	return profit;
}

void Eveniment::an2022()
{
	if (this->nrBilete > 0 && bilete != nullptr && getAn() ==2022)
	{
		for (int i = 0; i < nrBilete; i++)
		{
			int pretInitial = bilete[i].getPret();
			bilete[i].setPret(pretInitial + 0.1 * pretInitial);
		}
	}
}