#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>
#define SIL system("CLS");// bundan sonra system("cls");kullanacagım her yere sil yazarsam da aynı şey olur.
int N = 0;//Asagida her fonksiyon icin ayrı ayrı N degeri tenımlamamak icin başta tanımlarsak direk bu degere ulaşabiliriz.
struct dogumtarihi
{
	char gun[10];
	char ay[10];
	char yil[10];
};
struct adres
{
	char il[100];
	char mahalle[100];
	char sokak[100];
	char numara[100];
	char epostaadresi[100];
};
struct Rehber
{
	char Isim[100];
	char Soyad[100];
	char evtelefonu[100];
	char ceptelefonu[100];
	char istelefonu[100];
	struct adres adresler;
	struct dogumtarihi dogum;
}KisiBilgileri[BUFSIZ];

void menu();//MENÜ YAPMA FONKSİYONU.
void kisiEkle    (struct Rehber KisiBilgileri[BUFSIZ]);//KİŞİ EKLEME FONKSİYONU.
void arama       (struct Rehber KisiBilgileri[BUFSIZ]);//MENUDE ARAMA İÇİN YAPILAN FONKSİYON.
void ekranaYazdir(struct Rehber KisiBilgileri[BUFSIZ],int sayac);//EKRANA GORUNTULEMEK İÇİN YAZILAN FONKSİYON.
void txtYaz      (struct Rehber KisiBilgileri[BUFSIZ]);//DOSYA İÇİNE YAZMAK İÇİN YAPTIĞIM FONKSİYON.
void guncelle    (struct Rehber KisiBilgileri[BUFSIZ]);//GUNCELLEME YAPMAK İÇİN YAPILAN FONKSİYON.
void silme       (struct Rehber KisiBilgileri[BUFSIZ]);//SİLME İŞLEMİ YAPMAK İÇİN YAPILAN FONKSİYON.

void main()   //MAIN
{
	FILE *rehber;//Dosya tanımlama islemi
	rehber = fopen("Rehber.txt","r");//dosya acma işlemi
	char secim;
	char cikis = 'h';//programin kapanmamasi icin
	if (rehber == NULL)
	{
		printf("Dosya Bulunamadi...\n");
	}
	else
	{
		while (!feof(rehber))//dosyanın sonuna gelene kadar 
		{
			fscanf(rehber,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
				&KisiBilgileri[N].Isim,
				&KisiBilgileri[N].Soyad,
				&KisiBilgileri[N].evtelefonu,
				&KisiBilgileri[N].ceptelefonu,
				&KisiBilgileri[N].istelefonu,
				&KisiBilgileri[N].adresler.il,
				&KisiBilgileri[N].adresler.mahalle,
				&KisiBilgileri[N].adresler.sokak,
				&KisiBilgileri[N].adresler.numara,
				&KisiBilgileri[N].adresler.epostaadresi,
				&KisiBilgileri[N].dogum.gun,
				&KisiBilgileri[N].dogum.ay,
				&KisiBilgileri[N].dogum.yil);
			N++;
		}
		fclose(rehber);//rehbberi kapama.
	}
	do
	{
		SIL
		menu();
		char devamET = 'h';
		char switch_on;
		switch_on = getch();
		switch (switch_on)//switch case ile menu yapımı
		{
		case '1':/// KISI EKLE ///
			do
			{
				kisiEkle(KisiBilgileri);
				printf("Kisi Eklemeye devam edecekmisiniz? [e]\n");
				devamET = tolower(getch());//cevabi kucuk harfe cevirme
				txtYaz(KisiBilgileri);
			} while (devamET == 'e');
			continue;
		case '2':/// GORUNTULE ///
			for (int i = 0; i < N; i++)
			{
				ekranaYazdir(KisiBilgileri,i);
				getch();//kaldirirsan hepsini tek seferde gosterir
			}			
			printf("\nMenuye donmek icin bir tusa basin\n");
			getch();
			continue;
		case '3':/// ARAMA ///
			arama(KisiBilgileri);
			printf("\nMenuye donmek icin bir tusa basin\n");
			getch();
			continue;
		case '4':/// GUNCELLE ///
			guncelle(KisiBilgileri);
			txtYaz(KisiBilgileri);
			printf("Guncellemeye devam edecekmisiniz? [e]\n");
			devamET = tolower(getch());
			printf("\nMenuye donmek icin bir tusa basin\n");
			getch();
			continue;
		case '5':/// SIL ///
			silme(KisiBilgileri);
			txtYaz(KisiBilgileri);
			printf("Kisi silmeye devam edecekmisiniz? [e]\n");
			devamET = tolower(getch());
			printf("Menuye donmek icin bir tusa basin\n");
			getch();
			continue;
		case '6':/// cikis ///
			char cik[] = "rehberden cikiyorsunuz";
			for (int i = 0; i < 23; i++)
			{
				printf("%c",cik[i]);
				Sleep(200);//animasyonla rehberden cikiyorsunuz yazdırırken kac saniyede olacağını belirleme
			}
			cikis = 'e';
			break;
		}
	} while (cikis == 'h');
}
void menu()//menu yapimi
{
	printf("\n\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260");
	printf("\n\260\260                      //\\\\               \260");
	printf("\n\260\260 1.Ekle              //  \\\\              \260");
	printf("\n\260\260                    //    \\\\             \260");
	printf("\n\260\260 2.Goruntule       //      \\\\	           \260");
	printf("\n\260\260                  //TELEFON \\\\	   \260");
	printf("\n\260\260 3.Ara           //REHBERİNE \\\\          \260"); 
	printf("\n\260\260                //            \\\\	   \260");
	printf("\n\260\260 4-Guncelle    //              \\\\        \260");
	printf("\n\260\260              //                \\\\       \260");
	printf("\n\260\260 5-Sil       //   HOSGELDİNİZ    \\\\	   \260");
	printf("\n\260\260            //                    \\\\     \260");
	printf("\n\260\260 6-Cikis     -----------------------     \260");
	printf("\n\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260\260"); 
	printf("\n\n");
	printf("Lutfen bir secenek giriniz..\n\n");
}
void ekranaYazdir(struct Rehber KisiBilgileri[BUFSIZ],int sayac)
{
	printf("\n** %2d **************\n",sayac+1);
	printf("    ADI : %s\n",KisiBilgileri[sayac].Isim);
	printf("SOY ADI : %s\n",KisiBilgileri[sayac].Soyad);
	printf("EV TEL NO  : %s\n",KisiBilgileri[sayac].evtelefonu);
	printf("CEP TEL NO:%s \n",KisiBilgileri[sayac].ceptelefonu);
	printf("Is TEL NO: %s\n",KisiBilgileri[sayac].istelefonu);
	printf("ADRESLER....\n");
	printf("İL:%s\n",KisiBilgileri[sayac].adresler.il);
	printf("MAHALLE:%s\n",KisiBilgileri[sayac].adresler.mahalle);
	printf("SOKAK:%s\n",KisiBilgileri[sayac].adresler.sokak);
	printf("Numara:%s\n",KisiBilgileri[sayac].adresler.numara);
	printf("E-POSTA ADRESİ:%s\n",KisiBilgileri[sayac].adresler.epostaadresi);
	printf("Dogum tarihi Gun:%s\n",KisiBilgileri[sayac].dogum.gun);
	printf("Dogum tarihi Ay:%s\n",KisiBilgileri[sayac].dogum.ay);
	printf("Dogum tarihi Yil:%s\n",KisiBilgileri[sayac].dogum.yil);
}
void kisiEkle    (struct Rehber KisiBilgileri[BUFSIZ])
{
	printf("Lutfen Kisi Bilgilerini Kucuk Harflerle Giriniz\n");
	printf("ISIM         \t: ");
	flushall();
	gets(KisiBilgileri[N].Isim);
	printf("SOYISIM      \t: ");
	flushall();
	gets(KisiBilgileri[N].Soyad);
	printf("EV  TEL NO   \t: ");
	flushall();
	gets(KisiBilgileri[N].evtelefonu);
	printf("CEP TEL NO   \t: ");
	flushall();
	gets(KisiBilgileri[N].ceptelefonu);
	printf("IS TEL NO   \t: ");
	flushall();
	gets(KisiBilgileri[N].istelefonu);
	printf("IL   \t: ");
	flushall();
	gets(KisiBilgileri[N].adresler.il);
	printf("MAHALLE   \t: ");
	flushall();
	gets(KisiBilgileri[N].adresler.mahalle);
	printf("SOKAK   \t: ");
	flushall();
	gets(KisiBilgileri[N].adresler.sokak);
	printf("NUMARA  \t: ");
	flushall();
	gets(KisiBilgileri[N].adresler.numara);
	printf("E-POSTA ADRESI   \t: ");
	flushall();
	gets(KisiBilgileri[N].adresler.epostaadresi);
	printf("Dogum tarihi gun   \t: ");
	flushall();
	gets(KisiBilgileri[N].dogum.gun);
	printf("Dogum tarihi ay   \t: ");
	flushall();
	gets(KisiBilgileri[N].dogum.ay);
	printf("Dogum tarihi yil   \t: ");
	flushall();
	gets(KisiBilgileri[N].dogum.yil);

	N++;
}
void guncelle    (struct Rehber KisiBilgileri[BUFSIZ])
{
	int guncellenecekKisininNumarasi;
	int sec;//Guncellenecek bilginin numarasidir.
	for (int i = 0; i < N; i++)
	{
		ekranaYazdir(KisiBilgileri,i);
	}
	printf("-----Guncellemek istediginiz kisinin numarasini giriniz:---\n");
	scanf("%d",&guncellenecekKisininNumarasi);
	guncellenecekKisininNumarasi--;
	SIL
	ekranaYazdir(KisiBilgileri,guncellenecekKisininNumarasi);

	printf("1. Ad\n");
	printf("2. Soyad\n");
	printf("3. EvtEL_\n");
	printf("4. Ceptel\n");
	printf("5. Istel\n");
	printf("6. IL\n");
	printf("7. Mahalle\n");
	printf("8. Sokak\n");
	printf("9. Numara\n");
	printf("10. Epostaadresi\n");
	printf("11. Dogum tarihi Gun\n");
	printf("12. Dogum tarihi Ay \n");
	printf("13. Dogum tarihi Yil \n");
	printf("Hangisini guncellmek istiyor isiniz?");
	scanf("%d",&sec);//bu seceneklere gore kisinin neyinin degiseceğini belirleriz
	if (sec == 1)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].Isim);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].Isim);//boylelikle yeni bilgi eski bilgi yerine gecer.
	}
	else if (sec == 2)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].Soyad);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].Soyad);
	}
	else if (sec == 3)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].evtelefonu);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].evtelefonu);
	}
	else if (sec == 4)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].ceptelefonu);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].ceptelefonu);
	}
	else if (sec == 5)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].istelefonu);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].istelefonu);
	}
	else if (sec == 6)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].adresler.il);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].adresler.il);
	}
	else if (sec == 7)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].adresler.mahalle);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].adresler.mahalle);
	}
	else if (sec == 8)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].adresler.sokak);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].adresler.sokak);
	}
	else if (sec == 9)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].adresler.numara);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].adresler.numara);
	}
	else if (sec == 10)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].adresler.epostaadresi);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].adresler.epostaadresi);
	}
	else if (sec == 11)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].dogum.gun);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].dogum.gun);
	}
	else if (sec == 12)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].dogum.ay);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].dogum.ay);
	}
	else if (sec == 13)
	{
		printf("Eski Bilgi : %s\n",KisiBilgileri[guncellenecekKisininNumarasi].dogum.yil);
		printf("Yeni Bilgi : ");flushall; 
		scanf("%s",KisiBilgileri[guncellenecekKisininNumarasi].dogum.yil);
	}
}
void arama       (struct Rehber KisiBilgileri[BUFSIZ])
{
	SIL
	char aranacakisim[BUFSIZ];
	char yanit = 'e';
	char secenek=0;
	do
	{
		printf("Isme gore arama icin 1 i \nSoy isme gore arama yapmak icin 2'a basiniz..\n");
		secenek = getch();
		char Bayrak='H';
		if(secenek== '1')
		{
			printf("\n Aradiginiz Kisinin Adini Giriniz..\n");
			flushall();
			gets(aranacakisim);
			for ( int i = 0; i <= N; i++ )
			{
				if (strcmp(KisiBilgileri[i].Isim,aranacakisim) == 0)//teker teker kontrol etmede strcmp kullanırız
				{
					ekranaYazdir(KisiBilgileri,i);
					Bayrak='E';
				}
			}
			if (Bayrak=='H')
			{
				printf(" Aradiginiz Kisi Bulunamadi!..\n");
			}
		}
		else if(secenek=='2')
		{
			printf("\n Aradiginiz Kisinin Soy Adini Giriniz..\n");
			flushall();
			gets(aranacakisim);
			for ( int i = 0; i <= N; i++ )
			{
				if (strcmp(KisiBilgileri[i].Soyad,aranacakisim) == 0)
				{
					ekranaYazdir(KisiBilgileri,i);
					Bayrak='E';
				}
			}
			if (Bayrak=='H')
			{
				printf(" Aradiginiz Kisi Bulunamadi!..\n");
			}
		}
		printf(" Aramaya Devam Etmek Istiyor musunuz ? < Evet >\n");
		yanit = tolower(getch());
	}while(yanit == 'e');
}
void silme       (struct Rehber KisiBilgileri[BUFSIZ])
{
	int silinenecekKisininNumarasi = 0;
	char silEmin;
	int sec;//Silinellenecek bilginin numarasidir.
	for (int i = 0; i < N; i++)
	{
		ekranaYazdir(KisiBilgileri,i);
	}
	printf("Silmek istediginiz kisinin numarasini giriniz lutfen\n");
	scanf("%d",&silinenecekKisininNumarasi);
	SIL
		silinenecekKisininNumarasi--;
	ekranaYazdir(KisiBilgileri,silinenecekKisininNumarasi);
	printf("\nBu kisinin dogru kisi olduguna emin misiniz?");
	silEmin = tolower(getch());
	if (silEmin == 'e')
	{
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].Isim, KisiBilgileri[N-1].Isim);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].Soyad,KisiBilgileri[N-1].Soyad);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].evtelefonu,KisiBilgileri[N-1].evtelefonu);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].istelefonu,KisiBilgileri[N-1].istelefonu);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].ceptelefonu,KisiBilgileri[N-1].ceptelefonu);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].adresler.il,KisiBilgileri[N-1].adresler.il);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].adresler.mahalle,KisiBilgileri[N-1].adresler.mahalle);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].adresler.sokak,KisiBilgileri[N-1].adresler.sokak);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].adresler.numara,KisiBilgileri[N-1].adresler.numara);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].adresler.epostaadresi,KisiBilgileri[N-1].adresler.epostaadresi);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].dogum.gun,KisiBilgileri[N-1].dogum.gun);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].dogum.ay,KisiBilgileri[N-1].dogum.ay);
		strcpy(KisiBilgileri[silinenecekKisininNumarasi].dogum.yil,KisiBilgileri[N-1].dogum.yil);
		N--;
	}
}
void txtYaz      (struct Rehber KisiBilgileri[BUFSIZ])
{
	FILE *rehber;//dosya acma
	rehber = fopen("Rehber.txt","w");//dsyaya yazma
	if (rehber == NULL)
	{
		printf("DOsya bulunamadi\n");
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			//fprintfler ile dosyaya yazma
			fprintf(rehber,"%s\t",KisiBilgileri[i].Isim);
			fprintf(rehber,"%s\t",KisiBilgileri[i].Soyad);
			fprintf(rehber,"%s\t",KisiBilgileri[i].evtelefonu);
			fprintf(rehber,"%s\t",KisiBilgileri[i].ceptelefonu);
			fprintf(rehber,"%s\t",KisiBilgileri[i].istelefonu);
			fprintf(rehber,"%s\t",KisiBilgileri[i].adresler.il);
			fprintf(rehber,"%s\t",KisiBilgileri[i].adresler.mahalle);
			fprintf(rehber,"%s\t",KisiBilgileri[i].adresler.sokak);
			fprintf(rehber,"%s\t",KisiBilgileri[i].adresler.numara);
			fprintf(rehber,"%s\t",KisiBilgileri[i].adresler.epostaadresi);
			fprintf(rehber,"%s\t",KisiBilgileri[i].dogum.gun);
			fprintf(rehber,"%s\t",KisiBilgileri[i].dogum.ay);
			fprintf(rehber,"%s\n",KisiBilgileri[i].dogum.yil);
		}
	}
	fclose(rehber);//dosyayı kapama
}
