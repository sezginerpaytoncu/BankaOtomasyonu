#include<stdio.h>
#include<conio.h> //getch() fonksiyonu i�in kullan�lm��t�r.
#include<Windows.h> //Sleep() ve system("CLS") fonksiyonlar� i�in kullan�ld�
#include<string.h> //strcmp kar��la�t�rma fonksiyonu i�in kullan�ld�

struct HesapBilgileri{
	char ad[15];
	char soyad[20];
	char sifre[20];
	int bakiye;	
};

void HesapEkle(struct HesapBilgileri *);
void HesapGoster(struct HesapBilgileri *);
void VeritabaniOku(struct HesapBilgileri *);
void VeritabaniGuncelle(struct HesapBilgileri *);

void main(){ 
	int yatanPara,cekilenPara,gonderilenPara;
	int k; //switch-case yap�s� i�in tan�mlanm��t�r.
	int kontrol=0; //kullan�c� ad� ve �ifre kontrol edilmesinde, flag olarak kullan�lm��t�r
	int girilenAdminSifresi, adminSifresi=123123; //Admin �ifresi tan�mland�
	int cevap1; //Ana Men�'deki if-else yap�s� i�in tan�mlanm��t�r
	char cevap2; //do-while yap�s� i�in tan�mlanm��t�r
	int cevap3=0; //Ana men�'den direkt olarak ��k�� yapmak i�in(while d�ng�lerine girmemek i�in) tan�mlanm��t�r.
	struct HesapBilgileri hesap[50]; //50 tane hesap i�erecek
	int hesapNo; //giris yap�ld�ktan sonra kullan�c�n�n s�ra numaras�n� tutmak i�in tan�mlanm��t�r
	
	hesap[0].bakiye = -1; // ilk hesab�n bo� oldu�unu anlamak i�in bakiyesine -1 de�eri atand�. 
	VeritabaniOku(hesap);
	
	printf("\n\t\t\t ================SEZGIN BANK===================\n");	
	printf("\n\t\t\t =Banka Hesap Sistemi Programina Hos Geldiniz!=\n");
	
	for(;;){
		AnaMenu:
		printf("1.Giris Yap:\n2.Hesap Olustur\n3.Admin Girisi\n4.Cikis\n");
		scanf("%d", &cevap1);
		
		if(cevap1==1){
			break;
		}
		else if(cevap1==2){
				Sleep(1000);
				system("CLS");
				printf("Hesap Olusturma\n===============\n\n");
				HesapEkle(hesap);
				printf("\nKayit islemi tamamlandi. Ana menuye donmek icin bir tusa basiniz...");
				getch();
				system("CLS");
		}		
		else if(cevap1==3){
				Sleep(1000);
				system("CLS");
				
				printf("Lutfen admin sifresini giriniz: \n");
				scanf("%d", &girilenAdminSifresi);
				if(girilenAdminSifresi==adminSifresi){
					printf("\nAdmin Hesabi\n============\n\n");
					
					int secim;
					printf("1.Tum hesap bilgilerini gor\n2.Cikis\n");
					scanf("%d", &secim);
						switch(secim){
							case 1:
								//dosyadan bilgileri yazd�r
								HesapGoster(hesap);
								printf("\nCikmak icin bir tusa basiniz:");
								getch();
								system("CLS");							
								break;
							case 2:
								break;
							default:
								printf("\nHatali giris yaptiniz. Ana menuye donmek icin herhangi bir tusa basiniz...");
								getch();
								system("CLS");
								break;					
						}
				}
				else{
					printf("\nHatali giris yaptiniz. Ana menuye donmek icin herhangi bir tusa basiniz...");
					getch();
					system("CLS");
				}
		}
		else if(cevap1==4){
			//goto cikis;
			cevap3=1;
			break;			
		}
			

		else{
			printf("Hatali giris yaptiniz. Lutfen tekrar deneyiniz.");
			system("CLS");
		}
	}
		
	// for(;;) //Kullan�c� ad� giri�i i�in sonsuz d�ng� olu�turulmu�tur
	while(cevap3==0)	//Ana men�'de ��k�� se�imi yap�l�rsa, d�ng�lere girmeden direkt olarak program sonuna gidilmesi i�in while'a �evirildi.
	{
		Sleep(1000);
		system("CLS");
		printf("Kullanici Girisi\n================\n");
		printf("\n Adinizi ve Soyadinizi Giriniz:\n");
		int j;
		char adkontrol[20], soyadkontrol[20], sifrekontrol[20];
		scanf("%s %s", &adkontrol, &soyadkontrol);
		printf("Lutfen 4 haneli sifrenizi giriniz:\n");
		scanf("%s", &sifrekontrol);
		printf("%s %s %s\n", &adkontrol, &soyadkontrol, &sifrekontrol);	//Debug icin kulland�m...
		for(j=0;j<50;j++){ //Kullan�c�n Ad�, Soyad� ve �ifresi sorgulan�yor...
					
			char *ad=hesap[j].ad;
			char *soyad=hesap[j].soyad;
			char *sifre=hesap[j].sifre;
			printf("%s %s %s\n", hesap[j].ad, hesap[j].soyad, hesap[j].sifre);
				/*printf("Girilen deger: %s esit mi, veritabanindaki: %s\n", adkontrol[20], hesap[j].ad);
				printf("Girilen deger: %s esit mi, veritabanindaki: %s\n", soyadkontrol[20], hesap[j].soyad);
				printf("Girilen deger: %s esit mi, veritabanindaki: %s\n", sifrekontrol[20], hesap[j].sifre);*/
			getch();
			fflush(stdin);
			
			int a = strcmp(adkontrol, ad);
			int b = strcmp(soyadkontrol, soyad);
			int c = strcmp(sifrekontrol, sifre);
			
			/* Bu k�s�m �al��mad� neden???	
			int a = strcmp(adkontrol, hesap[j].ad);
			int b = strcmp(soyadkontrol, hesap[j].soyad);
			int c = strcmp(sifre, hesap[j].sifre);	*/
			
			if(a==0 && b==0 && c==0 ){
				kontrol=1;
				hesapNo=j;
				printf("Hesap no: %d, Hesap no'ya atanan J degeri: %d", hesapNo, j);
				getch();
				fflush(stdin);
				break;
			}
			else
				continue;
		}
		

		if(kontrol==0) //Kullan�c�n�n girmi� oldu�u kullan�c� ad�yla, sistemde kayitli kullan�c� ad�n�n uyu�mamas� halinde if komutu �al���r. 
		{ 	 
			printf("\n Yanlis Giris Yaptiniz.\n");
			printf(" Lutfen Tekrar Deneyiniz.\n");
			printf("\n Lutfen Bekleyiniz...");
			printf("\n");
			continue; //Tekrar kullanici girisi -for- d�ng�s�ne d�n
		}
         
		else //Kullan�c�n�n girmi� oldu�u kullan�c� ad�yla, sistemde kayitli kullan�c� ad�n�n uyu�mas� halinde else komutu �al���r.
		{   
			printf("\n Kullanici adi ve sifreniz dogrulanmaktadir...");
			Sleep(1500);
			system("CLS");
			printf("\n Kullanici adi ve sifresi dogrulandi...\n");
			Sleep(1500);
			system("CLS");
			break; //for d�ng�s�nden ��k�� sa�lanmaktad�r.
		}
	}
	
   	//for(;;) //Kullan�c� �ifresi do�ruland�ktan sonra Men� i�lemleri i�in sonsuz d�ng� olu�turulmu�tur.
   	while(cevap3==0)	//Ana men�'de ��k�� se�imi yap�l�rsa, d�ng�lere girmeden direkt olarak program sonuna gidilmesi i�in while'a �evirildi.
	{ 
			// Working With Structures --- Structures as Function Parameters konusu!!!			
			char *ad = hesap[hesapNo].ad;
			printf("\nHesap No: %d\n", hesapNo);
			char *soyad = hesap[hesapNo].soyad;
			char *sifre = hesap[hesapNo].sifre;
			int *bakiye = &(hesap[hesapNo].bakiye);
			//printf("\n %d - Ad:%s Soyad:%s Bakiye:%d\n", hesapNo, ad, soyad, bakiye);		//Debug i�in kullan�ld�.
			//printf("\n %d - Ad:%s Soyad:%s Bakiye:%d\n", hesapNo, ad, soyad, *bakiye);	//Debug i�in kullan�ld�.
			
			
			
		    do
		    {
				//Menu: //goto fonksiyonu i�in kullan�lm��t�r.
				printf("Sayin %s %s, Sezgin Bank\'a Hos Geldiniz...\n\n", ad, soyad);
				//printf("\n%s %s %d", ad, soyad, bakiye);
				printf(" ISLEM MENUSU\n");
				printf(" ============\n\n");
				printf(" 1-Hesap Bakiyesi Goruntuleme\n");
				printf(" 2-Hesaba Para Yatirma\n");
				printf(" 3-Hesaptan Para Cekme\n");
				printf(" 4-Para Gonderme\n");
				printf(" 5-Cikis\n");
				printf("\n Luften Rakam Girerek Yapacaginiz Islemi Seciniz (1/2/3/4/5): ");
				scanf("%d",&k);
				fflush(stdin);
				printf("\n");
				switch(k)
				{  					
					case 1: //Hesap bakiyesi g�r�nt�leme.
						system("CLS");
						printf("\n Hesap Bakiyesi Goruntuleme");
						printf("\n --------------------------");
						printf("\n\n Hesabinizda Bulunan Para: %d TL \n", hesap[hesapNo].bakiye);
						printf("\n\n");
						break;
	
					case 2: //Hesaba para yat�rma.
						system("CLS");
						printf("\n Hesaba Para Yatirma");
						printf("\n ===================");
						printf("\n\n Hesabiniza Yatacak Para Tutarini Giriniz:");
						scanf("%d",&yatanPara);
						//hesap[hesapNo].bakiye += yatanPara;
						*bakiye += yatanPara;
						VeritabaniGuncelle(hesap);
						printf(" Hesabiniza Yatan Para: %d TL \n\n", yatanPara);
						printf(" Hesabinizda Bulunan Para: %d TL \n", hesap[hesapNo].bakiye);
						printf("\n\n");
						break;
	
					case 3: //Hesaptan para �ekme.
						while(1)
						{	
							system("CLS");
							printf("\n Hesaptan Para Cekme");
							printf("\n ===================");
							printf("\n\n Hesabinizdan Cekilecek Para Tutarini Giriniz:");
							scanf("%d",&cekilenPara);
							if(cekilenPara<=hesap[hesapNo].bakiye)
							{ 
								hesap[hesapNo].bakiye-=cekilenPara;
								VeritabaniGuncelle(hesap);
								printf(" Hesabinizdan Cekilen Para: %d TL \n\n",cekilenPara);
								printf(" Hesabinizda Kalan Para: %d TL \n",hesap[hesapNo].bakiye);
								break;
							}
	
							else
							{ 
								printf("\n Bakiyeniz Yetersiz...\n\n");
								printf(" Hesabinizdan Cekilecek Para Tutarini Tekrar Giriniz.\n\n");
								Sleep(2000);
								continue;
							}
						}
						printf("\n\n");
						break;
	
					case 4: //Para g�nderme.
						while(1)
						{	
							system("CLS");
							printf("\n Para Gonderme");
							printf("\n =============");
							printf("\n\n Hesabinizdan Gonderilecek Para Tutarini Giriniz:");
							scanf("%d",&gonderilenPara);
							if(hesap[hesapNo].bakiye>=gonderilenPara)
							{ 
								hesap[hesapNo].bakiye-=gonderilenPara;
								VeritabaniGuncelle(hesap);
								printf(" Hesabinizdan Gonderilen Para Tutari: %d TL \n\n",gonderilenPara);
								printf(" Hesabinizda Kalan Para: %d TL \n",hesap[hesapNo].bakiye);
								break;
							}
							else 
							{   
								printf("\n");
								printf(" Bakiyeniz Yetersiz.\n\n");
								printf(" Hesabinizdan Gonderilecek Para Tutarini Tekrar Giriniz.\n");
								Sleep(2000);
								continue;
							}
	
						}
						printf("\n\n");
						break;
						
					case 5: //Banka sisteminden ��k�� yapma.
						system("CLS");
						printf("\n");
						printf("Cikis yapiliyor...\n\n");
						cevap2='H';  //Ba�ka i�lem yapmak istiyor musun? 'H': Hay�r
						break;
							       
					default: //Kullan�c�n�n 1-2-3-4-5 d���nda bir se�enek girmesi halide default yap�s� �al���r.
						system("CLS");
						printf("\n Boyle Bir Islem Secenegi Yoktur.\n");
						printf("\n");
						break;
				} 
			
				if(k==5) //d�ng�den, yani banka otomasyonundan ��kmak i�in kurulmu�tur.
					break;
				else{
					printf(" Baska Islem Yapmak Istiyor Musunuz? ( (E)vet - (H)ayir )");
					cevap2=getch(); //Kullan�c�n�n cevab� cevap de�i�kenine aktar�lmaktad�r.		
					system("CLS");
					printf("\n");
				}
			}while(cevap2=="E" || cevap2=="e"); // 'E' veya 'e' olmas� halinde men� ekrana gelecektir.
		if(cevap2=='H' || cevap2=='h') //'H' veya 'h' olmas� halinde d�ng�den ��k�lacak ve ��k�� i�lemi ger�ekle�ecektir.
			break;
	}
	
	system("CLS");
	printf("\n Cikis");
	printf("\n =====");
	printf("\n\n Banka Sistemi Programindan Cikis Yaptiniz.");
	printf("\n Banka Sistemi Programini Kullandiginiz Icin Tesekkur Ederiz.");
	Sleep(3000);
	system("CLS");
	printf("\n Programi Kapatmak Icin Bir Tusa Basiniz.");
	getch(); //Herhangi bir tu�a bas�ld���nda program kapanacakt�r.	
	return 0;
}


//Admin hesab�yla giri� yap�ld���nda; Program�n ba��nda VeritabaniOku fonksiyonu ile haf�zaya al�nan t�m hesap bilgilerini konsola yazd�rmak i�in tan�mland�
void HesapGoster(struct HesapBilgileri *hesap){
	int i;
	printf("    \t    AD\t\t     SOYAD\t    SIFRE\t  BAKIYE");
	printf("\n    --------------------------------------------------------------------------------\n");
	for(i=0;i<50;i++){
		if(hesap[i].bakiye == -1)
			break;
		printf("%d - %10s%20s%15s%15d\n", i+1, hesap[i].ad, hesap[i].soyad, hesap[i].sifre, hesap[i].bakiye);
	}
}

//BankaVeritabani.txt dosyas�na yeni hesap bilgileri giri�i yapmak i�in tan�mland�
void HesapEkle(struct HesapBilgileri *hesap){
	FILE *HedefDosya = fopen("BankaVeritabani.txt", "a+");
	int i;
	for(i=0;i<50;i++){
		if(hesap[i].bakiye == -1)
			break;
		}
	printf("Kisinin adi:");
	scanf("%s", hesap[i].ad);
	printf("Kisinin soyadi:");
	scanf("%s", hesap[i].soyad);
	printf("Lutfen 4 haneli bir sifre giriniz:");
	scanf("%s", hesap[i].sifre);
	hesap[i].bakiye = 0;
	hesap[i+1].bakiye = -1;
	fprintf(HedefDosya, "%15s%20s%15s%15d\n", hesap[i].ad, hesap[i].soyad, hesap[i].sifre, hesap[i].bakiye);	
	printf("Hesap basariyla olusturulmustur.\n");	
	fclose(HedefDosya);
}

/*Program�n a��l���nda, BankaVeritabani.txt'de kay�tl� olan t�m hesaplar� okumak i�in tan�mland�.End of file g�rene kadar okuyor. Son eleman� bitirdi�inde en son hesap numaras�n�n 
bir ilerisine(yani hen�z bo� olan bakiye de�erini -1 at�yor. Yani HesapEkle �al��t�r�l�rsa, hesap struct'�n�n hangi index'ine tan�mlama yap�laca�� belirlenmi� oluyor.*/
void VeritabaniOku(struct HesapBilgileri *hesap){
	FILE *HedefDosya = fopen("BankaVeritabani.txt", "r+");
	if(HedefDosya == NULL)
		return;
	
	int i;
	for(i=0;i<50;i++){
		fscanf(HedefDosya, "%s %s %s %d\n", hesap[i].ad, hesap[i].soyad, hesap[i].sifre, &(hesap[i].bakiye));
		if(feof(HedefDosya)!=0)
			break;
		}
	hesap[i+1].bakiye = -1;
	fclose(HedefDosya);
}

/*Bakiye bilgisini de�i�tirecek bir i�lem yap�ld�ktan sonra veri g�ncellemek i�in; haf�zadaki t�m bilgileri, Veritabani.txt dosyas�n� yeniden a��p yazmak i�in tan�mland�*/
void VeritabaniGuncelle(struct HesapBilgileri *hesap){
	FILE *HedefDosya = fopen("BankaVeritabani.txt", "w");
	int a;
	for(a=0;a<50;a++){
	if(hesap[a].bakiye != -1)
		fprintf(HedefDosya, "%s%20s%15s%15d\n", hesap[a].ad, hesap[a].soyad, hesap[a].sifre, hesap[a].bakiye);	
	else
		break;
	}
	fclose(HedefDosya);
	VeritabaniOku(hesap);
}

