#pragma once
#include <string>
#include "Hesap.h"

using namespace std;
class BireyselMusteri
{
protected:
	int MusteriNo;
	int Sifre;
	string Ad;
	string Soyad;
	string Telefon;
	string Eposta;
	string TCNO;

public:
	BireyselMusteri(string ad, string soyad, string telefon, string eposta, string tc, int musteriNo, int sifre);
	BireyselMusteri(int musteriNo, int sifre);
	BireyselMusteri(); // ticaride bilgi g�ncelleme ve ctor i�inde varsay�lan yok hatasi verdigi i�in ekledim.
	virtual string BilgileriniGetir();
	virtual string BilgiGuncelle(string ad, string soyad, string telefon, string eposta, string tc);
	string TCNOGetir() { return this->TCNO; }
	virtual string ParaCek(int tutar);
	virtual string ParaYatir(int tutar);
	~BireyselMusteri();
};
