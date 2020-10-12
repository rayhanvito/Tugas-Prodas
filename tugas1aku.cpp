/*Program Satu*/
/*Membuat program billing warnet*/
/*Rayhan Vito Gustiansyah*/
/*20051397042*/

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int harga;
int ulang = 0;

struct{
    int jam;
    int menit;
    int detik;
}awal, akhir, selisih;

void hitungHarga(){
    int hargaPerjam = 5000;
    int hargaPermenit = 5000/60;
    int hargaPerDetik = 5000/3600;

    harga = (hargaPerjam * selisih.jam) + (hargaPermenit * selisih.menit) + (hargaPerDetik * selisih.detik);
}

void inputanPertama(){
    cout <<"-----Program Billing Warnet----- \n";
    cout <<"-------------------------------- \n";
    cout <<"\nMasukkan Waktu Awal\n";
    cout <<"Jam : ";
    cin >> awal.jam;
    cout <<"Menit : ";
    cin >> awal.menit;
    cout <<"Detik : ";
    cin >> awal.detik;
}

void inputanKedua(){
    cout <<"\nMasukkan Waktu Akhir\n";
    cout <<"Jam : ";
    cin >> akhir.jam;
    cout <<"Menit : ";
    cin >> akhir.menit;
    cout <<"Detik : ";
    cin >> akhir.detik;
}

void cekInputanPertama(){
    if (awal.jam > 24 || awal.menit > 60 || awal.detik > 60){
        cout <<"Inputan tidak sesuai! \nApakah Anda ingin mengulangi menginputkan data? \n1. Ya\n2. Tidak\n";
        cout <<"Pilihan : ";
        cin >> ulang;
        if(ulang != 1){
            ExitProcess(1);
        }else{
            system("cls");
            inputanPertama();
        }

    }
}

void cekInputanKedua(){
    if (akhir.jam > 24 || akhir.menit > 60 || akhir.detik > 60){
        cout <<"Inputan tidak sesuai! \nApakah Anda ingin mengulangi menginputkan data? \n1. Ya\n2. Tidak\n";
        cout <<"Pilihan : ";
        cin >> ulang;
        if(ulang != 1){
            ExitProcess(0);
        }else{
            system("cls");
            inputanPertama();
        }

    }
}



int main()
{

    do{
        inputanPertama();
        cekInputanPertama();
        inputanKedua();
        cekInputanKedua();

        //Menghitung Selisih Detik
        if(akhir.detik - awal.detik < 0){
            selisih.detik = (60 + akhir.detik) - awal.detik;
            akhir.menit;
        } else {
            selisih.detik = akhir.detik - awal.detik;
        }

        //Menghitung Selisih Menit
        if(akhir.menit - awal.menit < 0){
            selisih.menit = (60 + akhir.menit) - awal.menit;
            akhir.jam;
            selisih.jam = akhir.jam - awal.jam - 1;
        } else {
            selisih.menit = akhir.menit - awal.menit;
            selisih.jam = akhir.jam - awal.jam;
        }

        cout <<"\n-------Lama Penggunaan--------- \n";
        cout <<"Jam   : "<<selisih.jam<<" Jam\n";
        cout <<"Menit : "<<selisih.menit<<" Menit\n";
        cout <<"Detik : "<<selisih.detik<<" Detik\n";

        hitungHarga();

        cout <<"\n------Biaya yang Dibayar------- \n";
        cout <<"Total : Rp."<<harga<<"\n";
        cout <<endl;
        cout <<"Apakah anda ingin menginputkan data lagi?\n1. Ya\n2. Tidak\n";
        cout <<"Pilihan : ";
        cin >> ulang;
        system("cls");
    }while (ulang == 1);

    return 0;
}

