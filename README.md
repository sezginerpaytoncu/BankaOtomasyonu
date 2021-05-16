# BankaOtomasyonu
C dili ile geliştirdiğim banka otomasyonu konsol uygulamasıdır. Uygulamayı çalıştırıp, yeni hesap oluşturulursa; projenin bulunduğu dosya dolu içerisinde Veritabanı.txt isimli dosya oluşturulur ve müşteri bilgileri bu dosyada tutulur.

1. Programın çalıştığı dosya dizininde "Veritabanı.txt" isminde bir text dosyası oluşturulur.
2. Müşteri bilgileri (ad, soyad, şifre ve bakiye) bu text dosyasının içerisinde tutulur.
3. Programda kullanıcı yaratılırsa text dosyası güncellenir. 
4. Kullanıcı girişi yapılırken Veritabanı.txt dosyası içerisindeki satırlar sorgulanır ve HesapBilgileri struct yapısında saklanır.
5. Girilen ad soyad ve şifre bilgileri struct yapısı ile karşılaştırılır. Doğru ise program menüsüne erişilir.
6. Buradan sonra yapılan para çekme, yatırma gibi işlemlerin sonunda Veritabanı.txt dosyası sürekli olarak güncellenir.
