#pragma once
#include <string>
#include "BireyselMusteri.h"
#include "TicariMusteri.h"
#include "Islem.h"
#include <vector>

using namespace  std;
class Hesap
{
protected:
	int MusteriNumarasi;
	int HesapNumarasi;
	int HesapTutari;
	int IslemTutari;
	string Sifre;
	friend ostream& operator<<(ostream& os, Hesap hesap);
	vector <Islem> Islemler;

public:
	Hesap(int musteriNumarasi, int hesapNumarasi);
	virtual string ParaGirisi(int tutar);
	int HesapNumarasiAl() { return this->HesapNumarasi; }
	int HesapTutariAl() { return this->HesapTutari; }
	int MusteriNumarasiAl() { return this->MusteriNumarasi; }
	virtual bool ParaCikisi(int tutar);
	string TarihlereGoreIslemleriGetir(struct tm tarih1, struct tm tarih2);
	string HesapBilgileriGetir();
	string TakmaHesapAdi = "";
	Hesap() {};
};
