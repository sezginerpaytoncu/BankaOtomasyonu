#include<stdio.h>
#include<conio.h> //getch() fonksiyonu için kullanılmıştır.
#include<Windows.h> //Sleep() ve system("CLS") fonksiyonları için kullanıldı
#include<string.h> //strcmp karşılaştırma fonksiyonu için kullanıldı

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
	int k; //switch-case yapısı için tanımlanmıştır.
	int kontrol=0; //kullanıcı adı ve şifre kontrol edilmesinde, flag olarak kullanılmıştır
	int girilenAdminSifresi, adminSifresi=123123; //Admin şifresi tanımlandı
	int cevap1; //Ana Menü'deki if-else yapısı için tanımlanmıştır
	char cevap2; //do-while yapısı için tanımlanmıştır
	int cevap3=0; //Ana menü'den direkt olarak çıkış yapmak için(while döngülerine girmemek için) tanımlanmıştır.
	struct HesapBilgileri hesap[50]; //program max. 50 tane hesap içerecek
	int hesapNo; //giris yapıldıktan sonra kullanıcının sıra numarasını tutmak için tanımlanmıştır
	
	hesap[0].bakiye = -1; // ilk hesabın boş olduğunu anlamak için bakiyesine -1 değeri atandı. 
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
								//dosyadan bilgileri yazdır
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
		
	// for(;;) //Kullanıcı adı girişi için sonsuz döngü oluşturulmuştur
	while(cevap3==0)	//Ana menü'de çıkış seçimi yapılırsa, döngülere girmeden direkt olarak program sonuna gidilmesi için while'a çevirildi.
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
		printf("%s %s %s\n", &adkontrol, &soyadkontrol, &sifrekontrol);	//Debug icin kullandım...
		for(j=0;j<50;j++){ //Kullanıcın Adı, Soyadı ve Şifresi sorgulanıyor...
					
			char *ad=hesap[j].ad;
			char *soyad=hesap[j].soyad;
			char *sifre=hesap[j].sifre;
			//printf("%s %s %s\n", hesap[j].ad, hesap[j].soyad, hesap[j].sifre);
			getch();
			fflush(stdin);
			
			int a = strcmp(adkontrol, ad);
			int b = strcmp(soyadkontrol, soyad);
			int c = strcmp(sifrekontrol, sifre);
			
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
		

		if(kontrol==0) //Kullanıcının girmiş olduğu kullanıcı adıyla, sistemde kayitli kullanıcı adının uyuşmaması halinde if komutu çalışır. 
		{ 	 
			printf("\n Yanlis Giris Yaptiniz.\n");
			printf(" Lutfen Tekrar Deneyiniz.\n");
			printf("\n Lutfen Bekleyiniz...");
			printf("\n");
			continue; //Tekrar kullanici girisi -for- döngüsüne dön
		}
         
		else //Kullanıcının girmiş olduğu kullanıcı adıyla, sistemde kayitli kullanıcı adının uyuşması halinde else komutu çalışır.
		{   
			printf("\n Kullanici adi ve sifreniz dogrulanmaktadir...");
			Sleep(1500);
			system("CLS");
			printf("\n Kullanici adi ve sifresi dogrulandi...\n");
			Sleep(1500);
			system("CLS");
			break; //for döngüsünden çıkış sağlanmaktadır.
		}
	}
	
   	//for(;;) //Kullanıcı şifresi doğrulandıktan sonra Menü işlemleri için sonsuz döngü oluşturulmuştur.
   	while(cevap3==0)	//Ana menü'de çıkış seçimi yapılırsa, döngülere girmeden direkt olarak program sonuna gidilmesi için while'a çevirildi.
	{ 		
			char *ad = hesap[hesapNo].ad;
			printf("\nHesap No: %d\n", hesapNo);
			char *soyad = hesap[hesapNo].soyad;
			char *sifre = hesap[hesapNo].sifre;
			int *bakiye = &(hesap[hesapNo].bakiye);	
			
		    do
		    {
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
	
					case 2: //Hesaba para yatırma.
						system("CLS");
						printf("\n Hesaba Para Yatirma");
						printf("\n ===================");
						printf("\n\n Hesabiniza Yatacak Para Tutarini Giriniz:");
						scanf("%d",&yatanPara);
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
						
					case 5: //Banka sisteminden çıkış yapma.
						system("CLS");
						printf("\n");
						printf("Cikis yapiliyor...\n\n");
						cevap2='H';  //Başka işlem yapmak istiyor musun? 'H': Hayır
						break;
							       
					default: //Kullanıcının 1-2-3-4-5 dışında bir seçenek girmesi halinde default yapısı çalışır.
						system("CLS");
						printf("\n Boyle Bir Islem Secenegi Yoktur.\n");
						printf("\n");
						break;
				} 
			
				if(k==5) //döngüden, yani banka otomasyonundan çıkmak için kurulmuştur.
					break;
				else{
					printf(" Baska Islem Yapmak Istiyor Musunuz? ( (E)vet - (H)ayir )");
					cevap2=getch(); //Kullanıcının cevabı cevap2 değişkenine aktarılmaktadır.		
					system("CLS");
					printf("\n");
				}
			}while(cevap2=="E" || cevap2=="e"); // 'E' veya 'e' olması halinde menü ekrana gelecektir.
		if(cevap2=='H' || cevap2=='h') //'H' veya 'h' olması halinde döngüden çıkılacak ve çıkış işlemi gerçekleşecektir.
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
	getch();
	return 0;
}


//Admin hesabıyla giriş yapıldığında; Programın başında VeritabaniOku fonksiyonu ile hafızaya alınan tüm hesap bilgilerini konsola yazdırmak için tanımlandı
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

//BankaVeritabani.txt dosyasına yeni hesap bilgileri girişi yapmak için tanımlandı
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

/*Programın açılışında, BankaVeritabani.txt'de kayıtlı olan tüm hesapları okumak için tanımlandı.End of file görene kadar okuyor. Son elemanı bitirdiğinde en son hesap numarasının 
bir ilerisine(yani henüz boş olan bakiye değerini -1 atıyor. Yani HesapEkle çalıştırılırsa, hesap struct'ının hangi index'ine tanımlama yapılacağı belirlenmiş oluyor.*/
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

/*Bakiye bilgisini değiştirecek bir işlem yapıldıktan sonra veri güncellemek için; hafızadaki tüm bilgileri, Veritabani.txt dosyasını yeniden açıp yazmak için tanımlandı*/
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

