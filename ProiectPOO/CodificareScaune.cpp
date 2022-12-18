#include "CodificareScaune.h"

CodificareScaune::CodificareScaune()
{
	numeCategorie = "";
	numarRanduri = 0;
	randInceput = 0;
	locuriScaune = nullptr;
}

CodificareScaune::CodificareScaune(string numeCategorie, int numarRanduri, int randInceput, int** locuriScaune)
{
	this->numeCategorie = numeCategorie;

	if (randInceput > 0)
	{
		this->randInceput = randInceput;
	} else this->randInceput = 0;
	
	
	if (numarRanduri > 0 && locuriScaune != nullptr)
	{
		this->numarRanduri = numarRanduri;
		this->locuriScaune = new int* [numarRanduri];
		for (int i = 0; i < numarRanduri; i++)
		{
			this->locuriScaune[i] = new int[3];
		}
		for (int i = 0; i < numarRanduri; i++)
			for (int j = 0; j < 3; j++)
				this->locuriScaune[i][j] = locuriScaune[i][j];
	}
}

CodificareScaune::~CodificareScaune()
{
	if (locuriScaune != nullptr) 
	{
		for (int i = 0; i < this->numarRanduri; i++)
			delete[] locuriScaune[i];
		delete[] locuriScaune;
	}
}

string CodificareScaune::getNumeCategorie()
{
	return this->numeCategorie;
}


int** CodificareScaune::getLocuriScaune()
{
	if (this->locuriScaune != nullptr)
	{
		int** copie = new int* [this->numarRanduri];
		for (int i = 0; i < numarRanduri; i++)
		{
			copie[i] = new int[3];
		}
		for (int i = 0; i < numarRanduri; i++)
			for (int j = 0; j < 3; j++)
				copie[i][j] = locuriScaune[i][j];
		return copie;
	}
	else return nullptr;
}

void CodificareScaune::setLocuriScaune(int** locuriScaune)
{
	if (this->numarRanduri > 0 && locuriScaune != nullptr)
	{
		for (int i = 0; i < numarRanduri; i++)
			for (int j = 0; j < 3; j++)
				this->locuriScaune[i][j] = locuriScaune[i][j];
	}
}
int CodificareScaune::getNumarRanduri()
{
	return this->numarRanduri;
}

int CodificareScaune::getRandInceput()
{
	return this->randInceput;
}

void CodificareScaune::setNumeCategorie(string numeCategorie)
{
	this->numeCategorie = numeCategorie;
}

void CodificareScaune::setNumarRanduri(int numarRanduri)
{
	if (numarRanduri > 0)
	{
		this->numarRanduri = numarRanduri;
	}
	else this->numarRanduri = 0;
}

void CodificareScaune::setRandInceput(int randInceput)
{
	if (randInceput > 0)
	{
		this->randInceput = randInceput;
	}
	else this->randInceput = 0;
}



CodificareScaune& CodificareScaune:: operator=(const CodificareScaune& c)
{
	if (locuriScaune != nullptr)
	{
		for (int i = 0; i < this->numarRanduri; i++)
			delete locuriScaune[i];
		delete[] locuriScaune;
	}
	this->numeCategorie = c.numeCategorie;

	if (randInceput > 0)
	{
		this->randInceput = c.randInceput;
	}
	else this->randInceput = 0;


	if (numarRanduri > 0 && locuriScaune != nullptr)
	{
		this->numarRanduri = c.numarRanduri;
		this->locuriScaune = new int* [c.numarRanduri];
		for (int i = 0; i < c.numarRanduri; i++)
		{
			this->locuriScaune[i] = new int[3];
		}
		for (int i = 0; i < c.numarRanduri; i++)
			for (int j = 0; j < 3; j++)
				this->locuriScaune[i][j] = c.locuriScaune[i][j];
	}
	return *this;
}

bool CodificareScaune::operator!()
{
	return locuriScaune != nullptr;
}

istream& operator>>(istream& in, CodificareScaune& c)
{
	cout << "numeCategorie = ";
	in >> c.numeCategorie;
	cout << "numarRanduri = ";
	if (c.numarRanduri > 0)
		in >> c.numarRanduri;
	else c.numarRanduri = 0;

	cout << "randInceput = ";
	if (c.randInceput > 0)
		in >> c.randInceput;
	else c.randInceput = 0;

	if (c.locuriScaune != nullptr)
	{
		for (int i = 0; i < c.numarRanduri; i++)
			delete c.locuriScaune[i];
		delete[] c.locuriScaune;
	}
	if (c.numarRanduri > 0)
	{
		cout << "Seteaza locurile pe scaune din categoria respectiva" << endl;

		c.locuriScaune = new int* [c.numarRanduri];
		for (int i = 0; i < c.numarRanduri; i++)
		{
			c.locuriScaune[i] = new int[3];
		}
		int auxRandInceput = c.randInceput;
		for (int i = 0; i < c.numarRanduri; i++)
		{
			//for (int j = 0; j < 3; j++)
			c.locuriScaune[i][0] = auxRandInceput;
			cout << "Coloana minima de pe randul "<< auxRandInceput<<": ";
			in >> c.locuriScaune[i][1];
			cout << "Coloana maxima de pe randul " << auxRandInceput << ": ";
			in >> c.locuriScaune[i][2];
			auxRandInceput++;
		}
			
		
	}
	else 
	{
		cout << "Locurile pe scaune nu pot fi setate" << endl;
		c.locuriScaune = nullptr;
	}
	return in;
}

ostream& operator<<(ostream& out, CodificareScaune c)
{
	out << "numeCategorie: "<<c.numeCategorie<<endl;
	out << "numarRanduri: " << c.numarRanduri << endl;
	out << "randInceput: " << c.randInceput << endl;
	
	if (c.locuriScaune != nullptr && c.numarRanduri > 0)
	{
		out << "Locuri Scaune:" << endl;
		for (int i = 0; i < c.numarRanduri; i++)
		{
			out << "Numar rand: " << c.locuriScaune[i][0] << "\t";
			out << "Coloana minima: " << c.locuriScaune[i][1] << "\t";
			out << "Coloana maxima: " << c.locuriScaune[i][2] << endl;
		}
	}
	else out << "Nu exista locuriScaune" << endl;
	return out;
}

int CodificareScaune::numarLocuriTotale()
{
	int totalLocuri = 0;
	int** locuriScaune = getLocuriScaune();
	for (int i = 0; i < getNumarRanduri(); i++)
	{
		for (int j = 0; j < 3; j++) 
		{
			int totalRand = locuriScaune[i][2] - locuriScaune[i][1] + 1;
			totalLocuri += totalRand;
		}
	}
	return totalLocuri;
}

bool CodificareScaune::categoriePremium(CodificareScaune c)
{
	if (c.numarLocuriTotale() <= 5)
		return true;
	return false;
}