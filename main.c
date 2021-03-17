#include<stdio.h>
#include<conio.h> //getch() fonksiyonu için kullanýlmýþtýr.
#include<Windows.h> //Sleep() ve system("CLS") fonksiyonlarý için kullanýldý
#include<string.h> //strcmp karþýlaþtýrma fonksiyonu için kullanýldý

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
	int k; //switch-case yapýsý için tanýmlanmýþtýr.
	int kontrol=0; //kullanýcý adý ve þifre kontrol edilmesinde, flag olarak kullanýlmýþtýr
	int girilenAdminSifresi, adminSifresi=123123; //Admin þifresi tanýmlandý
	int cevap1; //Ana Menü'deki if-else yapýsý için tanýmlanmýþtýr
	char cevap2; //do-while yapýsý için tanýmlanmýþtýr
	int cevap3=0; //Ana menü'den direkt olarak çýkýþ yapmak için(while döngülerine girmemek için) tanýmlanmýþtýr.
	struct HesapBilgileri hesap[50]; //50 tane hesap içerecek
	int hesapNo; //giris yapýldýktan sonra kullanýcýnýn sýra numarasýný tutmak için tanýmlanmýþtýr
	
	hesap[0].bakiye = -1; // ilk hesabýn boþ olduðunu anlamak için bakiyesine -1 deðeri atandý. 
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
								//dosyadan bilgileri yazdýr
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
		
	// for(;;) //Kullanýcý adý giriþi için sonsuz döngü oluþturulmuþtur
	while(cevap3==0)	//Ana menü'de çýkýþ seçimi yapýlýrsa, döngülere girmeden direkt olarak program sonuna gidilmesi için while'a çevirildi.
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
		printf("%s %s %s\n", &adkontrol, &soyadkontrol, &sifrekontrol);	//Debug icin kullandým...
		for(j=0;j<50;j++){ //Kullanýcýn Adý, Soyadý ve Þifresi sorgulanýyor...
					
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
			
			/* Bu kýsým çalýþmadý neden???	
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
		

		if(kontrol==0) //Kullanýcýnýn girmiþ olduðu kullanýcý adýyla, sistemde kayitli kullanýcý adýnýn uyuþmamasý halinde if komutu çalýþýr. 
		{ 	 
			printf("\n Yanlis Giris Yaptiniz.\n");
			printf(" Lutfen Tekrar Deneyiniz.\n");
			printf("\n Lutfen Bekleyiniz...");
			printf("\n");
			continue; //Tekrar kullanici girisi -for- döngüsüne dön
		}
         
		else //Kullanýcýnýn girmiþ olduðu kullanýcý adýyla, sistemde kayitli kullanýcý adýnýn uyuþmasý halinde else komutu çalýþýr.
		{   
			printf("\n Kullanici adi ve sifreniz dogrulanmaktadir...");
			Sleep(1500);
			system("CLS");
			printf("\n Kullanici adi ve sifresi dogrulandi...\n");
			Sleep(1500);
			system("CLS");
			break; //for döngüsünden çýkýþ saðlanmaktadýr.
		}
	}
	
   	//for(;;) //Kullanýcý þifresi doðrulandýktan sonra Menü iþlemleri için sonsuz döngü oluþturulmuþtur.
   	while(cevap3==0)	//Ana menü'de çýkýþ seçimi yapýlýrsa, döngülere girmeden direkt olarak program sonuna gidilmesi için while'a çevirildi.
	{ 
			// Working With Structures --- Structures as Function Parameters konusu!!!			
			char *ad = hesap[hesapNo].ad;
			printf("\nHesap No: %d\n", hesapNo);
			char *soyad = hesap[hesapNo].soyad;
			char *sifre = hesap[hesapNo].sifre;
			int *bakiye = &(hesap[hesapNo].bakiye);
			//printf("\n %d - Ad:%s Soyad:%s Bakiye:%d\n", hesapNo, ad, soyad, bakiye);		//Debug için kullanýldý.
			//printf("\n %d - Ad:%s Soyad:%s Bakiye:%d\n", hesapNo, ad, soyad, *bakiye);	//Debug için kullanýldý.
			
			
			
		    do
		    {
				//Menu: //goto fonksiyonu için kullanýlmýþtýr.
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
					case 1: //Hesap bakiyesi görüntüleme.
						system("CLS");
						printf("\n Hesap Bakiyesi Goruntuleme");
						printf("\n --------------------------");
						printf("\n\n Hesabinizda Bulunan Para: %d TL \n", hesap[hesapNo].bakiye);
						printf("\n\n");
						break;
	
					case 2: //Hesaba para yatýrma.
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
	
					case 3: //Hesaptan para çekme.
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
	
					case 4: //Para gönderme.
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
						
					case 5: //Banka sisteminden çýkýþ yapma.
						system("CLS");
						printf("\n");
						printf("Cikis yapiliyor...\n\n");
						cevap2='H';  //Baþka iþlem yapmak istiyor musun? 'H': Hayýr
						break;
							       
					default: //Kullanýcýnýn 1-2-3-4-5 dýþýnda bir seçenek girmesi halide default yapýsý çalýþýr.
						system("CLS");
						printf("\n Boyle Bir Islem Secenegi Yoktur.\n");
						printf("\n");
						break;
				} 
			
				if(k==5) //döngüden, yani banka otomasyonundan çýkmak için kurulmuþtur.
					break;
				else{
					printf(" Baska Islem Yapmak Istiyor Musunuz? ( (E)vet - (H)ayir )");
					cevap2=getch(); //Kullanýcýnýn cevabý cevap deðiþkenine aktarýlmaktadýr.		
					system("CLS");
					printf("\n");
				}
			}while(cevap2=="E" || cevap2=="e"); // 'E' veya 'e' olmasý halinde menü ekrana gelecektir.
		if(cevap2=='H' || cevap2=='h') //'H' veya 'h' olmasý halinde döngüden çýkýlacak ve çýkýþ iþlemi gerçekleþecektir.
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
	getch(); //Herhangi bir tuþa basýldýðýnda program kapanacaktýr.	
	return 0;
}


//Admin hesabýyla giriþ yapýldýðýnda; Programýn baþýnda VeritabaniOku fonksiyonu ile hafýzaya alýnan tüm hesap bilgilerini konsola yazdýrmak için tanýmlandý
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

//BankaVeritabani.txt dosyasýna yeni hesap bilgileri giriþi yapmak için tanýmlandý
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

/*Programýn açýlýþýnda, BankaVeritabani.txt'de kayýtlý olan tüm hesaplarý okumak için tanýmlandý.End of file görene kadar okuyor. Son elemaný bitirdiðinde en son hesap numarasýnýn 
bir ilerisine(yani henüz boþ olan bakiye deðerini -1 atýyor. Yani HesapEkle çalýþtýrýlýrsa, hesap struct'ýnýn hangi index'ine tanýmlama yapýlacaðý belirlenmiþ oluyor.*/
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

/*Bakiye bilgisini deðiþtirecek bir iþlem yapýldýktan sonra veri güncellemek için; hafýzadaki tüm bilgileri, Veritabani.txt dosyasýný yeniden açýp yazmak için tanýmlandý*/
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

