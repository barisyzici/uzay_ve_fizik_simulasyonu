#include <stdio.h>  
#include <math.h>   
#include <string.h> 


#ifndef PI
#define PI 3.14159265358979323846
#endif

// Gezegen isimleri ve yercekimi ivmeleri (m/s^2)
// Merkur 0, Venus 1, Dunya 2, Mars 3, Jupiter 4, Saturn 5, Uranus 6, Neptun 7, Pluto 8 (Pluto opsiyonel)

int NUM_gezegenler = 9; 

// Cisim t saniye boyunca serbest düştüğünde kat ettiği mesafeyi hesapla
void serbest_dusme_deneyi(double *g, char **gezegenler, int n) {
    double t;
    printf("\n--- Serbest Dusme Deneyi ---\n");
    printf("Sure (s): ");
    if(scanf("%lf", &t)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    t = (t < 0) ? -t : t;
    printf("Girilen sure negatif ise mutlak deger alindi; suan t = %.4f s\n", t);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double h = 0.5 * gi * t * t;
        printf("%s: h = %.4f m\n", *(gezegenler + i), h);
    }
}

// Başlangıç hızıyla yukarı atılan cismin maksimum yüksekliğini hesapla
void yukari_atis_deneyi(double *g, char **gezegenler, int n){
    double v0;
    printf("\n--- Yukari Atis Deneyi ---\n");
    printf("Baslangic hizi (m/s): ");
    if(scanf("%lf", &v0)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    v0 = (v0 < 0) ? -v0 : v0;
    printf("(Girilen hiz negatif ise mutlak deger alindi; suan v0 = %.4f m/s)\n", v0);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double hmax = (v0 * v0) / (2.0 * gi);
        printf("%s: h_max = %.4f m\n", *(gezegenler + i), hmax);
    }
}

// Bir cismin farklı gezegenler üzerindeki ağırlığını hesapla
void agirlik_deneyi(double *g, char **gezegenler, int n){
    double m;
    printf("\n--- Agirlik Deneyi ---\n");
    printf("Kutle (kg): ");
    if(scanf("%lf", &m)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    m = (m < 0) ? -m : m;
    printf("(Girilen kutle negatif ise mutlak deger alindi; suan m = %.4f kg)\n", m);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double G = m * gi;
        printf("%s: G = %.4f N (kg*m/s^2)\n", *(gezegenler + i), G);
    }
}

// Cismin belirli yükseklikteki potansiyel enerjisini hesapla
void kutlecekimsel_potansiyel(double *g, char **gezegenler, int n){
    double m, h;
    printf("\n--- Kutlecekimsel Potansiyel Enerji Deneyi ---\n");
    printf("Kutle (kg): "); if(scanf("%lf", &m)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    printf("Yukseklik (m): "); if(scanf("%lf", &h)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    m = (m < 0) ? -m : m; h = (h < 0) ? -h : h;
    printf("(Negatif degerler mutlak deger olarak alindi; m=%.4f kg, h=%.4f m)\n", m, h);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double Ep = m * gi * h;
        printf("%s: Ep = %.4f J (joule)\n", *(gezegenler + i), Ep);
    }
}

// Sıvı içinde belirli derinlikteki basıncı hesapla
void hidrostataik_basinc_deneyi(double *g, char **gezegenler, int n){
    double rho, h;
    printf("\n--- Hidrostatik Basinc Deneyi ---\n");
    printf("Sivinin birim hacim kutlesi (rho, kg/m^3): "); if(scanf("%lf", &rho)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    printf("Derinlik (m): "); if(scanf("%lf", &h)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    rho = (rho < 0) ? -rho : rho; h = (h < 0) ? -h : h;
    printf("(Negatif degerler mutlak deger olarak alindi; rho=%.4f kg/m^3, h=%.4f m)\n", rho, h);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double P = rho * gi * h;
        printf("%s: P = %.4f Pa (N/m^2)\n", *(gezegenler + i), P);
    }
}

// Sıvıya daldırılan cismin üzerinde etkiyen kaldırma kuvvetini hesapla
void arsimet_deneyi(double *g, char **gezegenler, int n){
    double rho, V;
    printf("\n--- Arsimet Kaldirma Kuvveti Deneyi ---\n");
    printf("Sivinin birim hacim kutlesi (rho, kg/m^3): "); if(scanf("%lf", &rho)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    printf("Cismin batan hacmi (V, m^3): "); if(scanf("%lf", &V)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    rho = (rho < 0) ? -rho : rho; V = (V < 0) ? -V : V;
    printf("(Negatif degerler mutlak deger alindi; rho=%.4f kg/m^3, V=%.4f m^3)\n", rho, V);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double Fk = rho * gi * V;
        printf("%s: F_kaldirma = %.4f N\n", *(gezegenler + i), Fk);
    }
}

// Basit sarkaçın periyodunu (titreşim süresini) hesapla
void basit_sarkac(double *g, char **gezegenler, int n){
    double L;
    printf("\n--- Basit Sarkac Periyodu Deneyi ---\n");
    printf("Sarkac uzunlugu (m): "); if(scanf("%lf", &L)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    L = (L < 0) ? -L : L;
    printf("(Uzunluk negatif ise mutlak deger alindi; L=%.4f m)\n", L);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double T = 2.0 * PI * sqrt(L / gi);
        printf("%s: T = %.4f s\n", *(gezegenler + i), T);
    }
}

// İp ile asılı cisme etki eden gerilme kuvvetini hesapla
void sabit_ip_gerilmesi_deneyi(double *g, char **gezegenler, int n){
    double m;
    printf("\n--- Sabit Ip Gerilmesi Deneyi ---\n");
    printf("Cismin kutlesi (kg): "); if(scanf("%lf", &m)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    m = (m < 0) ? -m : m;
    printf("(Negatif kutle girildiyse mutlak deger alindi; m=%.4f kg)\n", m);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double Tension = m * gi;
        printf("%s: Ip gerilmesi T = %.4f N\n", *(gezegenler + i), Tension);
    }
}

// Asansördeki cismin hissettiği görünür ağırlığını hesapla
void asansor_deneyi(double *g, char **gezegenler, int n){
    double a, m;       // a: ivme, m: kütle
    int choice;        // Hareket yönü seçimi
    printf("\n--- Asansor Deneyi ---\n");
    printf("Cismin kutlesi (kg): "); if(scanf("%lf", &m)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    m = (m < 0) ? -m : m;
    printf("Asansorun ivmesinin buyuklugu (m/s^2, a >= 0 girin): "); if(scanf("%lf", &a)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    a = (a < 0) ? -a : a;
    printf("Ivmelenme durumu seciniz:\n");
    printf("1) Yukari dogru ivmeleniyor \n");
    printf("2) Asagi dogru ivmeleniyor \n");
    printf("3) Yukari dogru yavasliyor \n");
    printf("4) Asagi dogru yavasliyor \n");
    printf("Seciminiz (1-4): "); if(scanf("%d", &choice)!=1){ printf("Gecersiz giris.\n"); while(getchar()!= '\n'); return; }
    printf("(Negatif girisler mutlak deger alindi; m=%.4f kg, a=%.4f m/s^2)\n", m, a);
    printf("Sonuclar (her gezegen icin):\n");
    for(int i=0;i<n;i++){
        double gi = *(g + i);
        double N;
        if(choice==1 || choice==4){

            N = m * (gi + a);
        } else if(choice==2 || choice==3){

            N = m * (gi - a);
        } else {
            printf("Gecersiz durum secildi. Varsayilan: no change.\n");
            N = m * gi;
        }
        printf("%s: Etkin agirlik N = %.4f N\n", *(gezegenler + i), N);
    }
}

// Deney menüsünü ekrana yazdır
void menu_yazdir(){
    printf("\n==== Uzay Simulasyonu: Deney Listesi ====\n");
    printf("1. Serbest Dusme Deneyi\n");
    printf("2. Yukari Atis Deneyi\n");
    printf("3. Agirlik Deneyi\n");
    printf("4. Kutlecekimsel Potansiyel Enerji Deneyi\n");
    printf("5. Hidrostatik Basinc Deneyi\n");
    printf("6. Arsimet Kaldirma Kuvveti Deneyi\n");
    printf("7. Basit Sarkac Periyodu Deneyi\n");
    printf("8. Sabit Ip Gerilmesi Deneyi\n");
    printf("9. Asansor Deneyi\n");
    printf("-1. Cikis\n");
    printf("Seciminiz: ");
}

int main(){
    // Her gezegenin yüzey yerçekimi ivmesi (m/s^2)
    double gravities_local[9] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15, 0.62};

    // Gezegen isimleri
    char *gezegenler_local[9] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun", "Pluto"};

    // İşaretçiler tanımla
    double *grav = gravities_local;
    char **gezegenler = gezegenler_local;


    // Kullanıcı adını al
    char bilim_insani[100];
    printf("Uzay Simulasyonuna Hosgeldiniz!\n");
    printf("Bilim insaninin adi: ");

    // Geçersiz giriş durumunda varsayılan ad kullan
    if(scanf("%99s", bilim_insani)!=1){ strcpy(bilim_insani, "Bilinmiyor"); }
    printf("Merhaba %s. Yapmak istediginiz deneyleri seciniz.\n", bilim_insani);

    // Ana menü döngüsü
    int choice = 0;
    while(1){
        menu_yazdir();
        if(scanf("%d", &choice)!=1){ printf("Gecersiz giris. Lutfen bir sayi giriniz.\n"); while(getchar() != '\n'); continue; }
        if(choice == -1){ printf("Program sonlandiriliyor. Tesekkurler %s.\n", bilim_insani); break; }
        switch(choice){
            case 1: serbest_dusme_deneyi(grav, gezegenler, NUM_gezegenler); break;
            case 2: yukari_atis_deneyi(grav, gezegenler, NUM_gezegenler); break;
            case 3: agirlik_deneyi(grav, gezegenler, NUM_gezegenler); break;
            case 4: kutlecekimsel_potansiyel(grav, gezegenler, NUM_gezegenler); break;
            case 5: hidrostataik_basinc_deneyi(grav, gezegenler, NUM_gezegenler); break;
            case 6: arsimet_deneyi(grav, gezegenler, NUM_gezegenler); break;
            case 7: basit_sarkac(grav, gezegenler, NUM_gezegenler); break;
            case 8: sabit_ip_gerilmesi_deneyi(grav, gezegenler, NUM_gezegenler); break;
            case 9: asansor_deneyi(grav, gezegenler, NUM_gezegenler); break;
            default:
                printf("Gecersiz secim. Lutfen menudeki sayilardan birini tiklayiniz veya -1 ile cikis yapiniz.\n");
        }
    }
    return 0;
}
