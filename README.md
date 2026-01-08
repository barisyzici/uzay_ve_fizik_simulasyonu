Uzay ve Fizik Simülasyonu

Bu proje, Algoritmalar ve Programlama dersi kapsamında C dili kullanılarak geliştirilmiş bir fizik simülasyonu uygulamasıdır.
Program, farklı gezegenlerin yerçekimi ivmelerini kullanarak çeşitli fizik deneylerinin sonuçlarını hesaplamaktadır.
Bu proje bireysel olarak geliştirilmiştir. 

📌 Projenin Amacı

Fizikte sık kullanılan temel deneyleri C dili ile simüle etmek

Fonksiyon, pointer, dizi ve kontrol yapıları kullanımını pekiştirmek

Kullanıcıdan alınan girdilerle anlamlı ve birimli çıktılar üretmek

🧪 İçerilen Deneyler

Uygulamada aşağıdaki deneyler ayrı fonksiyonlar halinde gerçekleştirilmiştir:

Serbest Düşme Deneyi

Yukarı Atış Deneyi

Ağırlık Hesabı

Kütleçekimsel Potansiyel Enerji

Hidrostatik Basınç

Arşimet Kaldırma Kuvveti

Basit Sarkaç Periyodu

Sabit İp Gerilmesi

Asansörde Görünür Ağırlık

Her deney, Merkür’den Pluto’ya kadar farklı gezegenler için hesaplama yapmaktadır.

🌍 Gezegen Yerçekimi İvmeleri

Gezegenlerin yerçekimi ivmeleri bir dizi içinde tutulmuştur (m/s²):

Gezegen Yerçekimi
+Merkür 3.70
+Venüs 8.87
+Dünya 9.81
+Mars  3.71
+Jüpiter 24.79
+Satürn 10.44
+Uranüs 8.69
+Neptün	11.15
+Pluto	0.62

Dizi elemanlarına yalnızca pointer mantığıyla erişilmektedir.

⚙️ Teknik Özellikler

* Tüm deneyler ayrı fonksiyonlar olarak yazılmıştır

* Fonksiyonlara diziler pointer olarak gönderilmiştir

* Negatif girilen kütle, uzunluk, süre ve hacim değerleri
→ ternary operatörü kullanılarak mutlak değere çevrilmiştir

* Deneyler bir menü üzerinden tekrar tekrar seçilebilir

* -1 girildiğinde program güvenli şekilde sonlanır

* Tüm çıktılar birimleriyle birlikte ekrana yazdırılır


🖥️ Kullanım

Program başlatıldığında kullanıcıdan bilim insanının adı istenir

Deney menüsü ekrana gelir

İstenilen deney numarası girilerek hesaplama yapılır

Çıkış için -1 girilir

