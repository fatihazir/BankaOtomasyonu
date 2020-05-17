#include "Hesap.h"
#include <iostream>
#include "ctime"
#include "Islem.h"

using namespace std;

string Hesap::ParaGirisi(int tutar) {
	this->HesapTutari += tutar;
	time_t now = time(0);
	Islem islem(now, "Para Yat�rma", tutar);
	Islemler.push_back(islem);
	return "yatirildi";
}
bool Hesap::ParaCikisi(int tutar) {
	if (this->HesapTutari < tutar)
		return false;

	this->HesapTutari -= tutar;
	time_t now = time(0);
	Islem islem(now, "Para Cekme", tutar);
	Islemler.push_back(islem);

	return true;
}
string Hesap::HesapBilgileriGetir() {
	string temp;

	if (this->TakmaHesapAdi != "")
	{
		temp += "Takma hesap ad� : " + this->TakmaHesapAdi + "\n";
	}

	temp += "Hesap bilgileriniz : \nMusteri no: " +
		to_string(this->MusteriNumarasi) +
		"\nHesap numarasi: " + to_string(this->HesapNumarasi) +
		"\nHesap tutari: " + to_string(this->HesapTutari);

	return temp;
}

ostream& operator<<(ostream& os, const time_t dt)
{
	os << std::to_string(dt);
	return os;
}

string Hesap::TarihlereGoreIslemleriGetir(time_t tarih1, time_t tarih2)
{
	string islemler = "";
	for (int i = 0; i < Islemler.size(); i++)
	{
		if (Islemler[i].milliseconds >= tarih1 && Islemler[i].milliseconds <= tarih2)
			islemler += Islemler[i].IslemBilgileriniDondur();
	}
	return islemler;
}


Hesap::Hesap(int musteriNumarasi, int hesapNumarasi) {
	this->HesapTutari = 0;
	this->MusteriNumarasi = musteriNumarasi;
	this->HesapNumarasi = hesapNumarasi;
	this->TakmaHesapAdi = "";
}