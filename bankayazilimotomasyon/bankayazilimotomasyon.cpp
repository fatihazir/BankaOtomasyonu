#include <ctime>
#include <iostream>
#include <vector>
#include "Banka.h"
#include <string>
#include <clocale>
using namespace std;

Banka SuperBank;

int simdikiHesapNumarasi = 0;
int simdikiMusteriNumarasi = 0;

BireyselMusteri _bireyselMusteri;
TicariMusteri _ticariMusteri;

bool BireyselMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre);
void BireyselMusteriBilgileriAl(string& ad, string& soyad, string& telefon, string& eposta, string& tcno, int& sifre);
int main()
{
	setlocale(LC_ALL, "Turkish");
	
	while (true)
	{
		cout << "SuperBanka Ho� Geldiniz!\n Giri� Yapmak i�in 1 \n M��terimiz Olmak ��in 2 Yaz�n�z" << endl;
		int secilenDurum;
		string ad, soyad, telefon, eposta, tcno;
		int sifre = 0;
		cin >> secilenDurum;
		switch (secilenDurum)
		{
		case 1:
			break;
		case 2:
			cout << "Bireysel M��teri Olmak ��in 1 \n Ticari M��teri Olmak ��in 2 Giriniz";
			int secilenDurum2;
			cin >> secilenDurum;

			switch (secilenDurum)
			{
			case 1:
				cout << "Bilgileriniz Giriniz" << endl;
				BireyselMusteriBilgileriAl(ad, soyad, telefon, eposta, tcno, sifre);
				if (BireyselMusteriOlustur(ad, soyad, telefon, eposta, tcno, sifre))
				{
					cout << "Bilgileriniz" << endl;
					cout << _bireyselMusteri.BilgileriniGetir() << endl;
					
				}
				else
				{
					cout << "L�tfen bilgileri eksiksiz giriniz" << endl;
				}
				break;
			case 2:
				break;
			default:
				cout << "Hata" << endl;
				break;
			}
			break;
		default:
			cout << "Hata" << endl;
			break;
		}
	}
}

bool BireyselMusteriOlustur(string ad, string soyad, string telefon, string eposta, string tcno, int sifre)
{
	if (ad == "" || soyad == "" || telefon == "" || eposta == "" || tcno == "" || (sifre == 0 && std::to_string(sifre).length() != 4))
		return false;
	
	int musteriNo = SuperBank.YeniHesapNumarasi();
	BireyselMusteri yeniMusteri(ad, soyad, telefon, eposta, tcno, musteriNo, sifre);
	_bireyselMusteri = yeniMusteri;
	return true;
}

void BireyselMusteriBilgileriAl(string &ad, string &soyad, string &telefon, string &eposta, string &tcno, int &sifre)
{
	cout << "Ad�n�z: " << endl;
	cin >> ad;
	cout << "Soyad�n�z: " << endl;
	cin >> soyad;
	cout << "Telefon Numaran�z: " << endl;
	cin >> telefon;
	cout << "Eposta Adresiniz: " << endl;
	cin >> eposta;
	cout << "TC Kimlik Numaran�z: " << endl;
	cin >> tcno;
	cout << "�ifreniz (4 karakter uzunlu�unda olmal� ve sadece rakamlardan olu�mal�d�r): " << endl;
	cin >> sifre;
}