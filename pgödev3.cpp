/****************************************************************************
**	SAKARYA UNIVERSITY
**	BILGISAYAR MUHENDISLIGI BOLUMU
**	PROGRAMLAMAYA GIRIS
**
**	ÖĞRENCI ADI......: MERT ESER MERAL
**	ÖĞRENCI NUMARASI.: G211210047
**	DERS GRUBU…………………: IO-A GRUBU
****************************************************************************/


#include <iostream>
#include <windows.h>
#include <string>

using namespace std;


class Karakter // renk degiskeni ve harf degiskenini tutan karakter sinifi
{ 
	public:

	char harf;
	int renk;
		
};


Karakter karakter2;// Karakter sinifindan karakter2 nesnesi.
class Katar //karakter ekleyip karakter cikarabilen,olusan sekli ekrana yazdiran fonksiyonlari barindiran Katar sinifi
{

	public:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);	//renkli cikti icin gerekli kod.
	enum RENKLER
{
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,

};
	
	char	DUZCIZGI = 205;
	char	SOLUSTKOSE = 201;
	char	SAGUSTKOSE = 187;
	char	DIKEYCIZGI = 186;
	char	ASAGIAYRAC = 203;
	char	SOLALTKOSE = 200;
	char	SAGALTKOSE = 188;
	char	YUKARIAYRAC = 202;
	
	

	void yazdir(int karakterSayisi,char dizi[],int renkDizi[]) //kutucuk seklini ve rastgele cekilen rastgele renkli harfi bastiran yazdir fonksiyonu.
	{
		cout << SOLUSTKOSE;
		for (int i = 0; i < karakterSayisi-1; i++) // kutucugun ust kismini olusturan for dongusu.
		{
			cout << DUZCIZGI << ASAGIAYRAC;
			
		}

		cout << DUZCIZGI << SAGUSTKOSE << endl;

		cout << DIKEYCIZGI;
		for (int i = 0; i < karakterSayisi; i++) //kutucugun orta kismini olusturan ve rastgele cekilen harfi bastiran dongu.
		{
			
			SetConsoleTextAttribute(h, renkDizi[i]);//random renk kodu.
			cout << dizi[i];
			
			SetConsoleTextAttribute(h, 7);//beyaz renk kodu.
			cout <<DIKEYCIZGI;
		}
			if (karakterSayisi == 0)  // Eleman sayisi 0 oldugunda bos kutu bastiran dongu.
			{
				cout <<" "<< DIKEYCIZGI;
			}
			cout <<  endl;

		cout << SOLALTKOSE;
		for (int i = 0; i < karakterSayisi - 1; i++) //kutucugun alt kismini olusturan dongu.
		{
			cout << DUZCIZGI << YUKARIAYRAC;

		}

		cout << DUZCIZGI << SAGALTKOSE << endl;




	}
	void KarakterEkle() //karakter ekleyen fonksiyon. Random renk ve random harf burada cekiliyor.
	{
		rnd = rand() % 26;
		karakter2.renk = RENKLER(rand() % 6) + 9;
		rndRenkler[elemanSayisi] = RENKLER(rand() % 6) + 9;
		karakter2.harf = rndKarakterler[elemanSayisi];
		karakter2.harf = alfabe[rnd];
		rndKarakterler[elemanSayisi] = alfabe[rnd];
		

		
		if (elemanSayisi >= 50) //eleman sayisi 50'den fazla olursa daha fazla ekleme yapilmasini engelleyen kosul.
		{
			SetConsoleTextAttribute(h, 12);//kirmizi renk kodu
			cout << "ekleme yapilamaz" << endl;
			SetConsoleTextAttribute(h, 7);//beyaz renk kodu
		}
		else //eleman sayisi 50'den az ise onceki durumu ve sonraki durumu ekrana yazdiran else blogu.
		{
			cout << "onceki durum" << "-" << " eleman sayisi: " << elemanSayisi << endl;
			yazdir(elemanSayisi, rndKarakterler,rndRenkler);
			elemanSayisi++;
		
			cout << "sonraki durum" << "-" << " eleman sayisi: " << elemanSayisi << endl;
			yazdir(elemanSayisi, rndKarakterler,rndRenkler);
		}
		
		

	}
	void KarakterCikar() //karakter cikaran fonksiyon
	{
		
		
		if (elemanSayisi <= 0) {//eleman sayisi 0 ve altinda oldugunda daha fazla cikartma yapilamadigini ekrana yazdiran if dongusu.
			SetConsoleTextAttribute(h, 12);
			cout << "Cikartma yapilamaz!" << endl;
			SetConsoleTextAttribute(h, 7);
		}

		else if (elemanSayisi > 0) //eleman sayisi 0'dan buyukse cikarma yapıp onceki ve sonraki durumu ekrana yazdiran dongu.
		{
			cout << "onceki durum" <<"-" << " eleman sayisi: " << elemanSayisi << endl;
			yazdir(elemanSayisi, rndKarakterler,rndRenkler);
			for (int i = 0; i < elemanSayisi; i++) 
			{
				if (i == elemanSayisi - 1) //eleman silindiginde rastgele cekilen karakterlerin oldugu diziden elemani silen dongu.
				{
					rndKarakterler[i] = '\0';
				}
				
				


			}
		
			elemanSayisi--;
			cout << "sonraki durum" << "-" << " eleman sayisi: " << elemanSayisi << endl;
			yazdir(elemanSayisi, rndKarakterler,rndRenkler);

		}
		
	}
	private://gerekli degiskenlerin, rastgele cekilen harflerin ve renklerin tutuldugu dizilerin bulundugu private kismi.
	int rnd = 0;
	int elemanSayisi = 0;
	char rndKarakterler[50];
	int rndRenkler[50];
	char alfabe[26]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

};



int main()
{
	
	srand(time(NULL));
	int secim;
	
	Katar karakter;//katar sinifindan karakter nesnesi.

	while (1) {//bu dongu true oldugu surece yani surekli donuyor.
		cout << "\nislem seciniz" << endl;
		cout << "1. karakter ekle" << endl;
		cout << "2. karakter cikar" << endl;
		cout << "3. Programdan cik" << endl;
		cin >> secim;

		if (secim == 1) //eger kullanici secim degerini 1 girerse bu kosula giriyor ve katar sinifindan karakter ekleyen fonksiyon cagriliyor.
		{

			karakter.KarakterEkle();
		}
		else if (secim == 2) //eger kullanici secim degerini 2 girerse bu kosula giriyor ve katar sinifinden karakter cikaran fonksiyon cagriliyor.
		{
			karakter.KarakterCikar();
		}
		else if (secim == 3) //eger kullanici secim degerini 3 girerse dongu break ile terk ediliyor.
		{
			break;
		}


	}





}

