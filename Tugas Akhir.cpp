#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<fstream>
#include<process.h>
using namespace std;

//------- DEKLARASI FUNGSI PROGRAM-------------//
void Login_Dosen();
void Dosen();
void Mahasiswa();
void main_menu();
void Lihat_Data_Mahasiswa();
void Lihat_Data_Mahasiswa_mhs();
int validasi_nim();
bool validasi_angka();

//------- DEKLARASI FUNGSI TAMPILAN-------------//
void cls();
void br(int line);
void tab(int tab);
void warna(int clr);
void selamat_datang();
void loadingbar();
void fullscreen();

//--------------DEKLARASI CLASS-----------------//
class MAHASISWA{
      private:
      char nama[50], nama_ayah[50], nama_ibu[50], tanggal[30], kelas[50], jkel, agama[20], kata[100], grade, grade2;
      string no_hp, no_absen, h_izin, h_sakit, h2_hadir;
      int nim, jml_sks;
      float nilai[8], rata_rata, poin, total_poin_sks, hasil_ip, poin_sks[8], sks[8]={2, 2, 2, 3, 2, 3, 3, 3};

//-------- FUNGSI HITUNG -----------//
      void hitung(){
        rata_rata=(nilai[0]+nilai[1]+nilai[2]+nilai[3]+nilai[4]+nilai[5]+nilai[6]+nilai[7])/8;
        if(rata_rata>=86){
           grade='A';
            br(1); tab(5); cout<<" GRADE MAHASISWA ADALAH : A";
            br(1); tab(5); cout<<" BERIKAN CATATAN : ";
            cin.ignore();
            cin.getline(kata,100);
            cls();

        }else if((rata_rata>=76)&&(rata_rata<=85)){
           grade='B';
            br(1); tab(5); cout<<" GRADE MAHASISWA ADALAH : B";
            br(1); tab(5); cout<<" BERIKAN CATATAN : ";
            cin.ignore();
            cin.getline(kata,100);
            cls();

        }else if((rata_rata>=56)&&(rata_rata<=75)){
           grade='C';
            br(1); tab(5); cout<<" GRADE MAHASISWA ADALAH : C";
            br(1); tab(5); cout<<" BERIKAN CATATAN : ";
            cin.ignore();
            cin.getline(kata,100);
            cls();

        }else if((rata_rata>=45)&&(rata_rata<=55)){
           grade='D';
            br(1); tab(5); cout<<" GRADE MAHASISWA ADALAH : D";
            br(1); tab(5); cout<<" BERIKAN CATATAN : ";
            cin.ignore();
            cin.getline(kata,100);
            cls();

        }else if(rata_rata<44){
           grade='E';
            br(1); tab(5); cout<<" GRADE MAHASISWA ADALAH : E";
            br(1); tab(5); cout<<" BERIKAN CATATAN : ";
            cin.ignore();
            cin.getline(kata,100);
            cls();

        }

//----------- HITUNG IP ---------------//
    for (int i = 0; i < 8; i++){
        if(nilai[i]>=80){
           grade2='A';
           poin=4;
        }else if((nilai[i]>=68)&&(nilai[i]<=79)){
           grade2='B';
           poin=3;
        }else if((nilai[i]>=56)&&(nilai[i]<=67)){
           grade2='C';
           poin=2;
        }else if((nilai[i]>=45)&&(nilai[i]<=55)){
           grade2='D';
           poin=1;
        }else if(nilai[i]<44){
           grade2='E';
           poin=0;
        }
         poin_sks[i]=sks[i]*poin;
     }
     //------ JUMLAH AMBIL SKS -----------//
        total_poin_sks=(poin_sks[0]+poin_sks[1]+poin_sks[2]+poin_sks[3]+poin_sks[4]+poin_sks[5]+poin_sks[6]+poin_sks[7]);
        hasil_ip=total_poin_sks/20;
        if (hasil_ip>=3.1){
            jml_sks = 24;
        }else if((hasil_ip>=2) && (hasil_ip<=3)){
            jml_sks = 22;
        }else if(hasil_ip<2){
            jml_sks = 18;
        }

    }

      public:
//----------- FUNGSI INPUT --------------//
      void biodata()
       {
            br(1); tab(5); cout<<"|==============================================================|"; Sleep(200); warna(240);
            br(1); tab(5); cout<<"|                     ISI BIODATA MAHASISWA                    |"; Sleep(200); warna(224);
            br(1); tab(5); cout<<"|==============================================================|"; Sleep(200);
            br(1); tab(5); cout<<" NAMA MAHASISWA         : ";
            cin.ignore();
            cin.getline(nama,50);
            br(1); tab(5); cout<<" NAMA AYAH              : ";
            cin.getline(nama_ayah,50);
            br(1); tab(5); cout<<" NAMA IBU               : ";
            cin.getline(nama_ibu,50);
            tanggal:
            br(1); tab(5); cout<<" TANGGAL LAHIR(DD/MM/YY): ";
            cin.getline(tanggal,30);
            if(tanggal[2]=='/' && tanggal[5]=='/'){
            jeniskelamin:
            br(1); tab(5); cout<<" JENIS KELAMMIN P/L     : ";
            cin>>jkel;
            if(jkel=='P' || jkel=='p' || jkel=='L' || jkel=='l'){
            br(1); tab(5); cout<<" AGAMA                  : ";
            cin.ignore();
            cin.getline(agama,20);
            br(1); tab(5); cout<<" KELAS/OFFERING         : ";
            cin.getline(kelas,50);
            nomor:
            br(1); tab(5); cout<<" NOMOR HP               : ";
            cin>>no_hp;
            if (validasi_angka(no_hp) == 0) {
				br(1); tab(5); cout <<"NO HP Hanya Berisi Angka!!!"; Sleep(300);
                cls();
				cin.clear();
                fflush(stdin);
                goto nomor;
			}else{
            nim:
            br(1); tab(5); cout<<" NIM (4 Digit Terakhir) : ";
            cin>>nim;
            //nim != validasi_nim() &&
            if(nim>0){
            absen:
            br(1); tab(5); cout<<" NOMOR ABSEN            : ";
            cin>>no_absen;
            if (validasi_angka(no_absen) == 0) {
				br(1); tab(5); cout <<"NO Absen Hanya Berisi Angka!!!"; Sleep(300);
                cls();
				cin.clear();
                fflush(stdin);
                goto absen;
			}else{
            br(1); tab(5); cout<<"|----------------------JUMLAH KEHADIRAN-------------------------|";
            hadir:
            br(1); tab(5); cout<<" HADIR  : ";
            cin>>h2_hadir;
            if (validasi_angka(h2_hadir) == 0) {
				br(1); tab(5); cout <<"Jumlah Kehadiran Hanya Berisi Angka!!!"; Sleep(300);
                cls();
				cin.clear();
                fflush(stdin);
                goto hadir;
			}else{
            sakit:
            br(1); tab(5); cout<<" SAKIT  : ";
            cin>>h_sakit;
            if (validasi_angka(h_sakit) == 0) {
				br(1); tab(5); cout <<"Jumlah Sakit Hanya Berisi Angka!!!"; Sleep(300);
                cls();
				cin.clear();
                fflush(stdin);
                goto sakit;
			}else{
            izin:
            br(1); tab(5); cout<<" IZIN   : ";
            cin>>h_izin;
            if (validasi_angka(h_izin) == 0) {
				br(1); tab(5); cout <<"Jumlah Izin Hanya Berisi Angka!!!"; Sleep(300);
                cls();
				cin.clear();
                fflush(stdin);
                goto izin;
			}else{
                  cls();
                  br(1); tab(5); cout<<"|=======================================|";
                  br(1); tab(5); cout<<"|         INPUT NILAI MAHASISWA         |";
                  br(1); tab(5); cout<<"|=======================================|";
                    nilai0:
                  br(1); tab(5); cout<<" BAHASA INGGRIS PROFESI             : ";
                  cin>>nilai[0];
                  if(nilai[0]>0 && nilai[0]<=100){
                    nilai1:
                  br(1); tab(5); cout<<" KESELAMATAN DAN KESEHATAN KERJA    : ";
                  cin>>nilai[1];
                  if(nilai[1]>0 && nilai[1]<=100){
                    nilai2:
                  br(1); tab(5); cout<<" PENGANTAR TEKNOLOGI INFORMASI      : ";
                  cin>>nilai[2];
                  if(nilai[2]>0 && nilai[2]<=100){
                    nilai3:
                  br(1); tab(5); cout<<" DASAR PEMROGRAMAN KOMPUTER         : ";
                  cin>>nilai[3];
                  if(nilai[3]>0 && nilai[3]<=100){
                    nilai4:
                  br(1); tab(5); cout<<" MATEMATIKA DISKRIT                 : ";
                  cin>>nilai[4];
                  if(nilai[4]>0 && nilai[4]<=100){
                    nilai5:
                  br(1); tab(5); cout<<" ORGANISASI DAN ARSITEKTUR KOMPUTER : ";
                  cin>>nilai[5];
                  if(nilai[5]>0 && nilai[5]<=100){
                    nilai6:
                  br(1); tab(5); cout<<" PENDIDIKAN AGAMA                   : ";
                  cin>>nilai[6];
                  if(nilai[6]>0 && nilai[6]<=100){
                    nilai7:
                  br(1); tab(5); cout<<" PERKEMBANGAN PESERTA DIDIK         : ";
                  cin>>nilai[7];
                  if(nilai[7]>0 && nilai[7]<=100){

                  hitung();

                   }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai7;
                  }
                   }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai6;
                  }
                   }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai5;
                  }
                   }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai4;
                  }
                   }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai3;
                  }
                   }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai2;
                  }
                   }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai1;
                  }
                  }else{
                   br(1); tab(5); cout<<" NILAI TIDAK BOLEH NEGATIF ATAU LEBIH DARI 100!!!"; Sleep(300);
                   cls();
                   cin.clear();
                   fflush(stdin);
                   goto nilai0;
                  }

            }
            }
            }
            }

            }else{
                br(1); tab(5); cout<<" NIM ITU SUDAH DIGUNAKAN ATAU NIM TIDAK BOLEH NEGATIF "; Sleep(300);
                  cls();
                  cin.clear();
                  fflush(stdin);
                  goto nim;
            }
            }
            }else{
                br(1); tab(5); cout<<" MOHON INPUTKAN L/P!!! "; Sleep(300);
                  cls();
                  cin.clear();
                  fflush(stdin);
                  goto jeniskelamin;
            }
            }else{
                  br(1); tab(5); cout<<" MOHON INPUT TANGGAL LAHIR SESUAI FORMAT!!! "; Sleep(300);
                  cls();
                  cin.clear();
                  fflush(stdin);
                  goto tanggal;
            }
      }

//----------------- FUNGSI DATA TAMPIL DAN CETAK ---------------//
      void tampilkan_data()
      {
            cls();
            char cetak, cetak2[50];
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|                        UNIVERSITAS NEGERI MALANG                         |";
            br(1); tab(5); cout<<"|                     FAKULTAS TEKNIK | TEKNIK ELEKTRO                     |";
            br(1); tab(5); cout<<"|                     SI PENDIDIKAN TEKNIK INFORMATIKA                     |";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|---------------------------  BIODATA MAHASISWA  --------------------------|";
            br(1); tab(5); cout<<"| NAMA MAHASISWA : "<<nama;
            br(1); tab(5); cout<<"| NIM            : 22053360"<<nim;
            br(1); tab(5); cout<<"| TANGGAL LAHIR  : "<<tanggal;
            br(1); tab(5); cout<<"| NAMA AYAH      : "<<nama_ayah;
            br(1); tab(5); cout<<"| NAMA IBU       : "<<nama_ibu;
            br(1); tab(5); cout<<"| JENIS KELAMIN  : "<<jkel;
            br(1); tab(5); cout<<"| AGAMA          : "<<agama;
            br(1); tab(5); cout<<"| NO HP          : "<<no_hp;
            br(1); tab(5); cout<<"| KELAS/OFFERING : "<<kelas;
            br(1); tab(5); cout<<"| NO_ABSEN       : "<<no_absen;
            br(1); tab(5); cout<<"| ------------------------ ABSEN KEHADIRAN MAHASISWA ----------------------|";
            br(1); tab(5); cout<<"| HADIR : "<<h2_hadir;
            br(1); tab(5); cout<<"| SAKIT : "<<h_sakit;
            br(1); tab(5); cout<<"| IZIN  : "<<h_izin;
            br(1); tab(5); cout<<"|**************************************************************************|";
            br(1); tab(5); cout<<"|                          NILAI AKADEMIK MAHASISWA                        |";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"| BAHASA INGGRIS PROFESI             : "<<nilai[0];
            br(1); tab(5); cout<<"| KESELAMATAN DAN KESEHATAN KERJA    : "<<nilai[1];
            br(1); tab(5); cout<<"| PENGANTAR TEKNOLOGI INFORMASI      : "<<nilai[2];
            br(1); tab(5); cout<<"| DASAR PEMROGRAMAN KOMPUTER         : "<<nilai[3];
            br(1); tab(5); cout<<"| MATEMATIKA DISKRIT                 : "<<nilai[4];
            br(1); tab(5); cout<<"| ORGANISASI DAN ARSITEKTUR KOMPUTER : "<<nilai[5];
            br(1); tab(5); cout<<"| PENDIDIKAN AGAMA                   : "<<nilai[6];
            br(1); tab(5); cout<<"| PERKEMBANGAN PESERTA DIDIK         : "<<nilai[7];
            br(1); tab(5); cout<<"|--------------------------------------------------------------------------|";
            br(1); tab(5); cout<<"| RATA-RATA : "<<rata_rata<<"\t\t"<<" GRADE : "<<grade<<"\t\t"<<" IP : "<<hasil_ip;
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|--------------------------------- CATATAN --------------------------------|";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"| "<<kata;
            br(1); tab(5); cout<<"| ";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|------------------ JUMLAH PENGAMBILAN SKS SEMESTER DEPAN -----------------|";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"| Anda Dapat Mengambil Maksimal "<<jml_sks<<" SKS di Semester 2";
            br(1); tab(5); cout<<"| ";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(2); tab(5); cout<<" APAKAH MAU DI CETAK? (Y/N) : "; cin>>cetak;
            if (cetak=='Y' || cetak=='y'){
                br(2); tab(5); cout<<" TULIS NAMA FILE : "; cin>>cetak2;
                ofstream cetak;
                cetak.open(strcat(cetak2,".txt"));
                cetak.close();
                cetak.open(cetak2, ios::app);
                cetak<<"|==========================================================================|\n";
                cetak<<"|                        UNIVERSITAS NEGERI MALANG                         |\n";
                cetak<<"|                     FAKULTAS TEKNIK | TEKNIK ELEKTRO                     |\n";
                cetak<<"|                     SI PENDIDIKAN TEKNIK INFORMATIKA                     |\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"|---------------------------  BIODATA MAHASISWA  --------------------------|\n";
                cetak<<"| NAMA MAHASISWA : "<<nama<<endl;
                cetak<<"| NIM            : 22053360"<<nim<<endl;
                cetak<<"| TANGGAL LAHIR  : "<<tanggal<<endl;
                cetak<<"| NAMA AYAH      : "<<nama_ayah<<endl;
                cetak<<"| NAMA IBU       : "<<nama_ibu<<endl;
                cetak<<"| JENIS KELAMIN  : "<<jkel<<endl;
                cetak<<"| AGAMA          : "<<agama<<endl;
                cetak<<"| NO HP          : "<<no_hp<<endl;
                cetak<<"| KELAS/OFFERING : "<<kelas<<endl;
                cetak<<"| NO_ABSEN       : "<<no_absen<<endl;
                cetak<<"| ------------------------ ABSEN KEHADIRAN MAHASISWA ----------------------|\n";
                cetak<<"| HADIR : "<<h2_hadir<<endl;
                cetak<<"| SAKIT : "<<h_sakit<<endl;
                cetak<<"| IZIN  : "<<h_izin<<endl;
                cetak<<"|**************************************************************************|\n";
                cetak<<"|                          NILAI AKADEMIK MAHASISWA                        |\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"| BAHASA INGGRIS PROFESI             : "<<nilai[0]<<endl;
                cetak<<"| KESELAMATAN DAN KESEHATAN KERJA    : "<<nilai[1]<<endl;
                cetak<<"| PENGANTAR TEKNOLOGI INFORMASI      : "<<nilai[2]<<endl;
                cetak<<"| DASAR PEMROGRAMAN KOMPUTER         : "<<nilai[3]<<endl;
                cetak<<"| MATEMATIKA DISKRIT                 : "<<nilai[4]<<endl;
                cetak<<"| ORGANISASI DAN ARSITEKTUR KOMPUTER : "<<nilai[5]<<endl;
                cetak<<"| PENDIDIKAN AGAMA                   : "<<nilai[6]<<endl;
                cetak<<"| PERKEMBANGAN PESERTA DIDIK         : "<<nilai[7]<<endl;
                cetak<<"|--------------------------------------------------------------------------|\n";
                cetak<<"| RATA-RATA : "<<rata_rata<<"\t\t"<<" GRADE : "<<grade<<"\t\t"<<" IP : "<<hasil_ip<<endl;
                cetak<<"|==========================================================================|\n";
                cetak<<"|--------------------------------- CATATAN --------------------------------|\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"| "<<kata<<endl;
                cetak<<"| "<<endl;
                cetak<<"|==========================================================================|\n";
                cetak<<"|------------------ JUMLAH PENGAMBILAN SKS SEMESTER DEPAN -----------------|\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"| Anda Dapat Mengambil Maksimal "<<jml_sks<<" SKS di Semester 2\n";
                cetak<<"| "<<endl;
                cetak<<"|==========================================================================|\n";
                cetak.close();
                Dosen();
            }else if(cetak=='n' || cetak=='N'){
                br(1); tab(5); cout<<" ANDA MEMILIH UNTUK TIDAK MENCETAK HALAMAN OTOMATIS AKAN KEMBALI";
                Sleep(500);
                getch();
                Dosen();
            }else{
                br(1); tab(5); cout<<" MOHON INPUT DATA DENGAN BENAR!!!";
                Sleep(500);
                getch();
                Dosen();
            }

      }

      void tampilkan_data_mhs()
      {
            cls();
            char cetak, cetak2[50];
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|                        UNIVERSITAS NEGERI MALANG                         |";
            br(1); tab(5); cout<<"|                     FAKULTAS TEKNIK | TEKNIK ELEKTRO                     |";
            br(1); tab(5); cout<<"|                     SI PENDIDIKAN TEKNIK INFORMATIKA                     |";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|---------------------------  BIODATA MAHASISWA  --------------------------|";
            br(1); tab(5); cout<<"| NAMA MAHASISWA : "<<nama;
            br(1); tab(5); cout<<"| NIM            : 22053360"<<nim;
            br(1); tab(5); cout<<"| TANGGAL LAHIR  : "<<tanggal;
            br(1); tab(5); cout<<"| NAMA AYAH      : "<<nama_ayah;
            br(1); tab(5); cout<<"| NAMA IBU       : "<<nama_ibu;
            br(1); tab(5); cout<<"| JENIS KELAMIN  : "<<jkel;
            br(1); tab(5); cout<<"| AGAMA          : "<<agama;
            br(1); tab(5); cout<<"| NO HP          : "<<no_hp;
            br(1); tab(5); cout<<"| KELAS/OFFERING : "<<kelas;
            br(1); tab(5); cout<<"| NO_ABSEN       : "<<no_absen;
            br(1); tab(5); cout<<"| ------------------------ ABSEN KEHADIRAN MAHASISWA ----------------------|";
            br(1); tab(5); cout<<"| HADIR : "<<h2_hadir;
            br(1); tab(5); cout<<"| SAKIT : "<<h_sakit;
            br(1); tab(5); cout<<"| IZIN  : "<<h_izin;
            br(1); tab(5); cout<<"|**************************************************************************|";
            br(1); tab(5); cout<<"|                          NILAI AKADEMIK MAHASISWA                        |";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"| BAHASA INGGRIS PROFESI             : "<<nilai[0];
            br(1); tab(5); cout<<"| KESELAMATAN DAN KESEHATAN KERJA    : "<<nilai[1];
            br(1); tab(5); cout<<"| PENGANTAR TEKNOLOGI INFORMASI      : "<<nilai[2];
            br(1); tab(5); cout<<"| DASAR PEMROGRAMAN KOMPUTER         : "<<nilai[3];
            br(1); tab(5); cout<<"| MATEMATIKA DISKRIT                 : "<<nilai[4];
            br(1); tab(5); cout<<"| ORGANISASI DAN ARSITEKTUR KOMPUTER : "<<nilai[5];
            br(1); tab(5); cout<<"| PENDIDIKAN AGAMA                   : "<<nilai[6];
            br(1); tab(5); cout<<"| PERKEMBANGAN PESERTA DIDIK         : "<<nilai[7];
            br(1); tab(5); cout<<"|--------------------------------------------------------------------------|";
            br(1); tab(5); cout<<"| RATA-RATA : "<<rata_rata<<"\t\t"<<" GRADE : "<<grade<<"\t\t"<<" IP : "<<hasil_ip;
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|--------------------------------- CATATAN --------------------------------|";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"| "<<kata;
            br(1); tab(5); cout<<"| ";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"|------------------ JUMLAH PENGAMBILAN SKS SEMESTER DEPAN -----------------|";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(1); tab(5); cout<<"| Anda Dapat Mengambil Maksimal "<<jml_sks<<" SKS di Semester 2";
            br(1); tab(5); cout<<"| ";
            br(1); tab(5); cout<<"|==========================================================================|";
            br(2); tab(5); cout<<" APAKAH MAU DI CETAK? (Y/N) : "; cin>>cetak;
            if (cetak=='Y' || cetak=='y'){
                br(2); tab(5); cout<<" TULIS NAMA FILE : "; cin>>cetak2;
                ofstream cetak;
                cetak.open(strcat(cetak2,".txt"));
                cetak.close();
                cetak.open(cetak2, ios::app);
                cetak<<"|==========================================================================|\n";
                cetak<<"|                        UNIVERSITAS NEGERI MALANG                         |\n";
                cetak<<"|                     FAKULTAS TEKNIK | TEKNIK ELEKTRO                     |\n";
                cetak<<"|                     SI PENDIDIKAN TEKNIK INFORMATIKA                     |\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"|---------------------------  BIODATA MAHASISWA  --------------------------|\n";
                cetak<<"| NAMA MAHASISWA : "<<nama<<endl;
                cetak<<"| NIM            : 22053360"<<nim<<endl;
                cetak<<"| TANGGAL LAHIR  : "<<tanggal<<endl;
                cetak<<"| NAMA AYAH      : "<<nama_ayah<<endl;
                cetak<<"| NAMA IBU       : "<<nama_ibu<<endl;
                cetak<<"| JENIS KELAMIN  : "<<jkel<<endl;
                cetak<<"| AGAMA          : "<<agama<<endl;
                cetak<<"| NO HP          : "<<no_hp<<endl;
                cetak<<"| KELAS/OFFERING : "<<kelas<<endl;
                cetak<<"| NO_ABSEN       : "<<no_absen<<endl;
                cetak<<"| ------------------------ ABSEN KEHADIRAN MAHASISWA ----------------------|\n";
                cetak<<"| HADIR : "<<h2_hadir<<endl;
                cetak<<"| SAKIT : "<<h_sakit<<endl;
                cetak<<"| IZIN  : "<<h_izin<<endl;
                cetak<<"|**************************************************************************|\n";
                cetak<<"|                          NILAI AKADEMIK MAHASISWA                        |\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"| BAHASA INGGRIS PROFESI             : "<<nilai[0]<<endl;
                cetak<<"| KESELAMATAN DAN KESEHATAN KERJA    : "<<nilai[1]<<endl;
                cetak<<"| PENGANTAR TEKNOLOGI INFORMASI      : "<<nilai[2]<<endl;
                cetak<<"| DASAR PEMROGRAMAN KOMPUTER         : "<<nilai[3]<<endl;
                cetak<<"| MATEMATIKA DISKRIT                 : "<<nilai[4]<<endl;
                cetak<<"| ORGANISASI DAN ARSITEKTUR KOMPUTER : "<<nilai[5]<<endl;
                cetak<<"| PENDIDIKAN AGAMA                   : "<<nilai[6]<<endl;
                cetak<<"| PERKEMBANGAN PESERTA DIDIK         : "<<nilai[7]<<endl;
                cetak<<"|--------------------------------------------------------------------------|\n";
                cetak<<"| RATA-RATA : "<<rata_rata<<"\t\t"<<" GRADE : "<<grade<<"\t\t"<<" IP : "<<hasil_ip<<endl;
                cetak<<"|==========================================================================|\n";
                cetak<<"|--------------------------------- CATATAN --------------------------------|\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"| "<<kata<<endl;
                cetak<<"| "<<endl;
                cetak<<"|==========================================================================|\n";
                cetak<<"|------------------ JUMLAH PENGAMBILAN SKS SEMESTER DEPAN -----------------|\n";
                cetak<<"|==========================================================================|\n";
                cetak<<"| Anda Dapat Mengambil Maksimal "<<jml_sks<<" SKS di Semester 2\n";
                cetak<<"| "<<endl;
                cetak<<"|==========================================================================|\n";
                cetak.close();
                Mahasiswa();
            }else if(cetak=='n' || cetak=='N'){
                br(1); tab(5); cout<<" ANDA MEMILIH UNTUK TIDAK MENCETAK HALAMAN OTOMATIS AKAN KEMBALI";
                Sleep(500);
                getch();
                Mahasiswa();
            }else{
                br(1); tab(5); cout<<" MOHON INPUT DATA DENGAN BENAR!!!";
                Sleep(500);
                getch();
                Mahasiswa();
            }

      }

      bool validasi_angka(const string& str){
	    return str.find_first_not_of("0123456789") == string::npos;
    }

//--------------- FUNGSI DATA LIST TAMPIL -------------//
      void tampilkan_semua_data(){
            br(1); tab(2); cout<<"\t NAMA : "<<nama<<"\t"<<"NIM : 22053360"<<nim<<"\t"<<"KELAS : "<<kelas<<"\t";
            cout<<"RATA-RATA : "<<rata_rata<<"\t"<<"GRADE : "<<grade<<"\n";
            br(1); tab(3); cout<<"|-------------------------------------------------------------------------------------------------|";
      }

//---------- DEKLARASI FUNGSI DIMANA DIA MASIH TERMASUK DARI ANGGOTA CLASS MAHASISWA -------------//
      friend void cari();
      friend void cari_mhs();
      friend void edit();
      friend void hapus();
      friend void urutkan_rata2();
      friend void urutkan_rata2_mhs();
      friend void urutkan_nilai_tertinggi();
      friend int validasi_nim();
};


//----------------- FUNGSI DESAIN DAN ANIMASI ----------------//
//--------- ANIMASI SELAMAT DATANG -------------//
void selamat_datang(){
	warna(224);
	char welcome[50]="SELAMAT DATANG";
	char welcome2[50]=" DI";
	char welcome3[50]=" E-RAPOR MAHASISWA PTI 2022 SEMESTER 1";
	char welcome4[50]=" By: Mohammad Bagus N.C";
	br(5); tab(6); //printf("\n\n\n\n\n\t\t\t");
	for(int wlc=0; wlc<strlen(welcome);wlc++){

		printf(" %c",welcome[wlc]);
		Sleep(100);
	}
	warna(224);
	br(2); tab(7);
	for(int wlc2=0; wlc2<strlen(welcome2) ;wlc2++){

		printf(" %c",welcome2[wlc2]);
		Sleep(100);
	}
	warna(224);
	// printf("\n\n\n\t\ ");
    br(3); tab(3);
	for(int wlc3=0; wlc3<strlen(welcome3) ;wlc3++){
		if(welcome3[wlc3]!='D'){

			printf(" %c",welcome3[wlc3]);
		}
		else{

			printf(" %c",welcome3[wlc3]);
		}

		Sleep(100);
	}
	warna(224);
	// printf("\n\n\n\n\t\t ");
    br(4); tab(5);
	for(int wlc3=0; wlc3<strlen(welcome4) ;wlc3++){
		if(welcome4[wlc3]!='A' && welcome4[wlc3]!='E'){

			printf(" %c",welcome4[wlc3]);
		}
		else{

			printf(" %c",welcome4[wlc3]);
		}
		Sleep(100);
	}
	warna(224);

}

//---------- ANIMASI LOADING --------//
void loadingbar(void){

	for (int i=15;i<=100;i+=5){

		cls();

		// printf("\n\n\n\n\n\n\n\t\t\t\t");
        br(7); tab(7);
		printf("%d %% Loading...\n\n\t\t\t\t",i);

		printf("");

		tab(1); for (int j=0; j<i;j+=2){

			warna(160+j);
			printf(" ");
			warna(224);

		}
		Sleep(100);
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(100);
		}

	}

}

//------- FUNGSI BARIS BARU --------//
void br(int line){
	for(int i=0; i<line;i++){
		printf("\n");
	}
}

//------- FUNGSI TAB -------------//
void tab(int tab){

	for(int i=0; i<tab;i++){
		printf("\t");
	}

}

//--------- FUNGSI CLEAR SCREEN -----//
void cls(){
	system("cls");
}


//------------------------ FUNGSI TAMPILAN PERTAMA ------------//
void main_menu()
{
	cls();
    int mainmenu;
    start:
	br(1); tab(5); cout<<"|=================================================|"; Sleep(200); warna(78);
    br(1); tab(5); cout<<"|       APLIKASI E-RAPOR MAHASISWA PTI 2022       |"; Sleep(200); warna(224);
    br(1); tab(5); cout<<"|=================================================|"; Sleep(200);
    br(1); tab(5); cout<<"|             Selamat Datang di E-RAPOR           |"; Sleep(200);
    br(1); tab(5); cout<<"|Temukan Kemudahan Dalam Mengelola Nilai Mahasiswa|"; Sleep(200);
    br(1); tab(5); cout<<"|=================================================|"; br(2); Sleep(200);
    br(2); tab(5); cout<<">> 1. Masuk Sebagai DOSEN"; Sleep(200);
	br(2); tab(5); cout<<">> 2. Masuk Sebagai MAHASISWA"; Sleep(200);
	br(2); tab(5); cout<<">> 3. Keluar";  Sleep(200);
	br(2); tab(5); cout<<"++ Masukkan Pilihan : "; Sleep(200);
    fflush(stdin);
    cin>>mainmenu;
		if(mainmenu == 1){
			Login_Dosen();

		}else if( mainmenu == 2){
			Mahasiswa();

		}else if(mainmenu==3){
			cls();
            br(1); tab(5); cout<<"---- TERIMAKASIH SUDAH MENCOBA E-RAPOR PTI 2022 ----"; Sleep(200);
            br(1); tab(5); cout<<"-------- By : Mohammad Bagus Nur Cahyo --------"; Sleep(200);
			Sleep(1000);
            getch();
			exit(1);

		}else{
            br(1); tab(5); cout<<" MOHON PILIH MENU DENGAN BENAR!!!";
            Sleep(1000);
            cin.clear();
            cls();
            goto start;

    }



}

//------------- FUNGSI TAMBAH --------------//
void fungsi_tambah()
{
     MAHASISWA s;
     ofstream f("Data_Mahasiswa.dat",ios::binary|ios::app);
     s.biodata();
     f.write((char*)&s,sizeof(s));
     f.close();
}

int validasi_nim(){
    MAHASISWA s;
    int nim2;
    ifstream f("Data_Mahasiswa.dat");
    while(f.read((char*)&s,sizeof(s)))
         {
             nim2=s.nim;
             return nim2;
         }
    f.close();
}
//---------------- FUNGSI CARI -------------//
void cari()
{
      MAHASISWA s;
     ifstream f("Data_Mahasiswa.dat");
     int nm,flag=0;
     if(!f){
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         cls();
         Dosen();
     }else{
         br(2); tab(5); cout<<"MASUKKAN NIM MAHASISWA (4 Digit Terakhir) : "; Sleep(200);
         cin>>nm;
         cls();
         while(f.read((char*)&s,sizeof(s)))
         {
             if(nm==s.nim)
             {
                 flag=1;
                 s.tampilkan_data();
             }
         }
         if(flag==0)
         {
             br(2); tab(5); cout<<"DATA TIDAK DITEMUKAN!!!"; Sleep(200);
             getch();
             cls();
             Dosen();
         }
     }
     f.close();
}

//---------- MENU MAHASISWA --------------//
void cari_mhs()
{
      MAHASISWA s;
     ifstream f("Data_Mahasiswa.dat");
     int nm,flag=0;
     if(!f){
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         cls();
         Mahasiswa();
     }else{
         br(2); tab(5); cout<<"MASUKKAN NIM MAHASISWA (4 Digit Terakhir) : "; Sleep(200);
         cin>>nm;
         cls();
         while(f.read((char*)&s,sizeof(s)))
         {
             if(nm==s.nim)
             {
                 flag=1;
                 s.tampilkan_data_mhs();
             }
         }
         if(flag==0)
         {
             br(2); tab(5); cout<<"DATA TIDAK DITEMUKAN!!!"; Sleep(200);
             getch();
             cls();
             Mahasiswa();
         }
     }
     f.close();
}

//------------ FUNGSI HAPUS ----------//

void hapus()
{
     MAHASISWA s;
     start:
     ifstream f1("Data_Mahasiswa.dat");
     ofstream f2("Temp.dat",ios::binary);
     int n,cr=0;
     if(!f1)
     {
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         cls();
         cin.clear();
         Dosen();
     }else{
         br(2); tab(5); cout<<"MASUKKAN NIM MAHASISWA (4 Digit Terakhir) : "; Sleep(200);
         fflush(stdin);
         cin>>n;
         cls();
         while(f1.read((char*)&s,sizeof(s)))
         {
             if(n!=s.nim)
             {
                 f2.write((char*)&s,sizeof(s));
                 cr=1;
             }
         }
         if(cr==0){
             br(2); tab(5); cout<<"DATA TIDAK DITEMUKAN!!!"; Sleep(200);
             getch();
             cls();
             Dosen();
         }
         else{
             br(2); tab(5); cout<<"DATA MAHASISWA BERHASIL DI HAPUS..."; Sleep(200);
             cls();
             //Dosen();
         }
     }
     f1.close();
     f2.close();
     getch();
     remove("Data_Mahasiswa.dat"); Sleep(400);
     rename("Temp.dat","Data_Mahasiswa.dat");
     Sleep(400);
     Dosen();
}


//----------------- FUNGSI TAMPILAN SEMUA DATA-------------//
void tampil_semua_data()
{
     MAHASISWA s;
     ifstream f("Data_Mahasiswa.dat");
     if(!f)
     {
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         cls();
         Dosen();
     }else
     {
        br(1); tab(5); cout<<"|=============================================================|";
        br(1); tab(5); cout<<"|                  DAFTAR SEMUA MAHASISWA                     |";
        br(1); tab(5); cout<<"|=============================================================|";
         while(f.read((char*)&s,sizeof(s)))
         {
             s.tampilkan_semua_data();
         }
         getch();
         Dosen();
     }
     f.close();
}

void tampil_semua_data_mhs()
{
     MAHASISWA s;
     ifstream f("Data_Mahasiswa.dat");
     if(!f)
     {
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         cls();
         Mahasiswa();
     }else
     {
        br(1); tab(5); cout<<"|=============================================================|";
        br(1); tab(5); cout<<"|                  DAFTAR SEMUA MAHASISWA                     |";
        br(1); tab(5); cout<<"|=============================================================|";
         while(f.read((char*)&s,sizeof(s)))
         {
             s.tampilkan_semua_data();
         }
         getch();
         Mahasiswa();
     }
     f.close();
}

//----------- FUNGSI MENGURUTKAN BERDASARKAN RATA-RATA -------------//
void urutkan_rata2()
{
     MAHASISWA s,t[100],temp;
     ifstream f("Data_Mahasiswa.dat");
     int n=0;
     if(!f){
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         Lihat_Data_Mahasiswa();

     }else{
             while(f.read((char*)&s,sizeof(s))){
                 t[n++]=s;
             }
         f.close();

         for(int i=0;i< n; i++)
         {
             for(int j=0;j<n-1;j++)
             {
                 if(t[j].rata_rata<t[j+1].rata_rata)
                 {
                     temp=t[j];
                     t[j]=t[j+1];
                     t[j+1]=temp;
                 }
             }
         }
//------------------------- TAMPILAN --------------------------//
         cls();
         br(1); tab(4); cout<<"|=============================================================================|";
         br(1); tab(4); cout<<"|   DAFTAR DATA DIURUTKAN BERDASARKAN RATA-RATA DARI YANG TERTINGGI           |";
         br(1); tab(4); cout<<"|=============================================================================|";
         for(int i=0;i<n;i++){
             t[i].tampilkan_semua_data();
         }
         getch();
         Lihat_Data_Mahasiswa();
     }
}

void urutkan_rata2_mhs()
{
     MAHASISWA s,t[100],temp;
     ifstream f("Data_Mahasiswa.dat");
     int n=0;
     if(!f){
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         Lihat_Data_Mahasiswa_mhs();

     }else{
             while(f.read((char*)&s,sizeof(s))){
                 t[n++]=s;
             }
         f.close();

         for(int i=0;i< n; i++)
         {
             for(int j=0;j<n-1;j++)
             {
                 if(t[j].rata_rata<t[j+1].rata_rata)
                 {
                     temp=t[j];
                     t[j]=t[j+1];
                     t[j+1]=temp;
                 }
             }
         }
//------------------------- TAMPILAN --------------------------//
         cls();
         br(1); tab(4); cout<<"|=============================================================================|";
         br(1); tab(4); cout<<"|   DAFTAR DATA DIURUTKAN BERDASARKAN RATA-RATA DARI YANG TERTINGGI           |";
         br(1); tab(4); cout<<"|=============================================================================|";
         for(int i=0;i<n;i++){
             t[i].tampilkan_semua_data();
         }
         getch();
         Lihat_Data_Mahasiswa_mhs();
     }
}

//----------- FUNGSI MENGURUTKAN BERDASARKAN NILAI TERTINGGI SETIAP MATKUL ---------//
void urutkan_nilai_tertinggi()
{
     MAHASISWA s,t[100],temp;
     start:
     ifstream f("Data_Mahasiswa.dat");
     int x,y,n=0;
     char ch[25];
     if(!f){
         br(2); tab(5); cout<<"FILE TIDAK DITEMUKAN!!!"; Sleep(200);
         getch();
         Lihat_Data_Mahasiswa();
     }else{
         {
             while(f.read((char*)&s,sizeof(s)))
             {
                 t[n++]=s;
             }
         }
         f.close();
         br(1); tab(5); cout<<"|=======================================|";
         br(1); tab(5); cout<<"|          PILIH MATA KULIAH            |";
         br(1); tab(5); cout<<"|=======================================|";
         br(1); tab(5); cout<<"| 1. BAHASA INGGRIS PROFESI             |";
         br(1); tab(5); cout<<"| 2. KESELAMATAN DAN KESEHATAN KERJA    |";
         br(1); tab(5); cout<<"| 3. PENGANTAR TEKNOLOGI INFORMASI      |";
         br(1); tab(5); cout<<"| 4. DASAR PEMROGRAMAN KOMPUTER         |";
         br(1); tab(5); cout<<"| 5. MATEMATIKA DISKRIT                 |";
         br(1); tab(5); cout<<"| 6. ORGANISASI DAN ARSITEKTUR KOMPUTER |";
         br(1); tab(5); cout<<"| 7. PENDIDIKAN AGAMA                   |";
         br(1); tab(5); cout<<"| 8. PERKEMBANGAN PESERTA DIDIK         |";
         br(1); tab(5); cout<<"|=======================================|";
         br(2); tab(5); cout<<"PILIH : ";
         fflush(stdin);
         cin>>y;
         cls();
         if(y<9){
         x=y-1;

         for(int i=0;i<n;i++){
             for(int j=0;j<n-1;j++){
                 if(t[j].nilai[x]<t[j+1].nilai[x]){
                     temp=t[j];
                     t[j]=t[j+1];
                     t[j+1]=temp;
                 }
             }
         }

//------------------------ TAMPILAN -----------------------//
         br(1); tab(5); cout<<"|------------------------------------------------------------|";
         br(1); tab(5); cout<<"|      NO  "<<"\t"<<"NILAI"<<"\t\t"<<"NAMA        ";
         br(1); tab(5); cout<<"|------------------------------------------------------------|";
         for(int i=0;i<5;++i){
             br(1); tab(6); cout<<i+1<<". "; tab(1);
             cout<<t[i].nilai[x]<<"\t\t"<<t[i].nama;
             cout<<endl;
         }
         br(3);
         getch();
         Lihat_Data_Mahasiswa();
     }else{
        br(2); tab(5); cout<<"MOHON MEMILIH MENU DENGAN BENAR!!!"; Sleep(200);
        getch();
        cls();
        cin.clear();
        goto start;
     }
 }
}

//--------------- TAMPILAN MENGURUTKAN DATA -----------//
void Lihat_Data_Mahasiswa()
{
     int n;
     cls();
     start:
     br(1); tab(5); cout<<"|===========================================================|"; Sleep(200); warna(240);
     br(1); tab(5); cout<<"|                 DAFTAR MENU DI LIHAT NILAI                |"; Sleep(200); warna(224);
     br(1); tab(5); cout<<"|===========================================================|"; Sleep(200);
     br(1); tab(5); cout<<" 1. LIHAT DATA MAHASISWA BERDASARKAN RATA-RATA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 2. LIHAT BERDASARKAN NILAI TERTINGGI PADA SETIAP MATKUL"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 3. KEMBALI"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 4. KELUAR DARI PROGRAM"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" PILIH : "; Sleep(200);
     fflush(stdin);
     cin>>n;
     switch(n)
     {
              case 1:
                    cls();
                    urutkan_rata2_mhs();
                    break;
              case 2:
                    cls();
                    urutkan_nilai_tertinggi();
                    break;
              case 3:
                    cls();
                    Dosen();
                    break;
              case 4:
                    cls();
                    br(1); tab(5); cout<<"---- TERIMAKASIH SUDAH MENCOBA E-RAPOR PTI 2022 ----"; Sleep(200);
                    br(1); tab(5); cout<<"-------- By : Mohammad Bagus Nur Cahyo --------"; Sleep(200);
                    Sleep(1000);
                    getch();
                    exit(1);
                    break;
              default:
			        br(2); tab(5); cout<<"MOHON MEMILIH MENU DENGAN BENAR!!!"; Sleep(200);
                    cls();
                    cin.clear();
                    goto start;

     }
}

//------------- UNTUK MAHASISWA --------//
void Lihat_Data_Mahasiswa_mhs()
{
     int n;
     cls();
     start:
     br(1); tab(5); cout<<"|===========================================================|"; Sleep(200); warna(240);
     br(1); tab(5); cout<<"|                 DAFTAR MENU DI LIHAT NILAI                |"; Sleep(200); warna(224);
     br(1); tab(5); cout<<"|===========================================================|"; Sleep(200);
     br(1); tab(5); cout<<" 1. LIHAT DATA MAHASISWA BERDASARKAN RATA-RATA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 2. LIHAT BERDASARKAN NILAI TERTINGGI PADA SETIAP MATKUL"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 3. KEMBALI"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 4. KELUAR DARI PROGRAM"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" PILIH : "; Sleep(200);
     fflush(stdin);
     cin>>n;
     switch(n)
     {
              case 1:
                    cls();
                    urutkan_rata2_mhs();
                    break;
              case 2:
                    cls();
                    urutkan_nilai_tertinggi();
                    break;
              case 3:
                    cls();
                    Mahasiswa();
                    break;
              case 4:
                    cls();
                    br(1); tab(5); cout<<"---- TERIMAKASIH SUDAH MENCOBA E-RAPOR PTI 2022 ----"; Sleep(200);
                    br(1); tab(5); cout<<"-------- By : Mohammad Bagus Nur Cahyo --------"; Sleep(200);
                    Sleep(1000);
                    getch();
                    exit(1);
                    break;
              default:
			        br(2); tab(5); cout<<"MOHON MEMILIH MENU DENGAN BENAR!!!"; Sleep(200);
                    cls();
                    cin.clear();
                    goto start;

     }
}

//----------- HALAMAN MAHASISWA ----------//
void Mahasiswa()
{
      MAHASISWA s;
     cls();
     int n;
     start:
     br(1); tab(5); cout<<"|=========================================|"; Sleep(200); warna(240);
     br(1); tab(5); cout<<"|     DAFTAR MENU DI HALAMAN MAHASISWA    |"; Sleep(200); warna(224);
     br(1); tab(5); cout<<"|=========================================|"; Sleep(200);
     br(1); tab(5); cout<<" 1. CETAK RAPOR MAHASISWA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 2. LIHAT BERDASARKAN PERINGKAT"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 3. KEMBALI KE MENU UTAMA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 4. KELUAR DARI PROGRAM"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" PILIH: "; Sleep(200);
     fflush(stdin);
     cin>>n;
     switch(n){
        case 1:
            cls();
            cari_mhs();
            break;
        case 2:
            Lihat_Data_Mahasiswa_mhs();
            break;
        case 3:
            main_menu();
            break;
        case 4:
            cls();
            br(1); tab(5); cout<<"---- TERIMAKASIH SUDAH MENCOBA E-RAPOR PTI 2022 ----"; Sleep(200);
            br(1); tab(5); cout<<"-------- By : Mohammad Bagus Nur Cahyo --------"; Sleep(200);
            Sleep(1000);
            getch();
            exit(1);
            break;
        default:
        br(2); tab(5); cout<<"MOHON MEMILIH MENU DENGAN BENAR!!!"; Sleep(200);
        cls();
        cin.clear();
        goto start;
     }
}

//----------- HALAMAN DOSEN -------------//
void Dosen()
{
     int n;
     start:
     cls();
     br(1); tab(5); cout<<"|=====================================|"; Sleep(200); warna(240);
     br(1); tab(5); cout<<"|     DAFTAR MENU DI HALAMAN DOSEN    |"; Sleep(200); warna(224);
     br(1); tab(5); cout<<"|=====================================|"; Sleep(200);
     br(1); tab(5); cout<<" 1. TAMBAH DATA MAHASISWA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 2. CETAK RAPOR MAHASISWA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 3. HAPUS DATA MAHASISWA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 4. LIHAT SEMUA DATA MAHASISWA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 5. LIHAT BERDASARKAN PERINGKAT"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 6. KEMBALI KE MENU UTAMA"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" 7. KELUAR DARI PROGRAM"<<"\n"; Sleep(200);
     br(1); tab(5); cout<<" PILIH: ";
     fflush(stdin);
     cin>>n;
     switch(n)
     {
            case 1:
                    cls();
                    fungsi_tambah();
                    cls();
                    break;
            case 2:
                    cls();
                    cari();
                    break;
            case 3:
                    cls();
                    hapus();
                    break;
            case 4:
                    cls();
                  tampil_semua_data();
                    break;
            case 5:
                    cls();
                  Lihat_Data_Mahasiswa();
                    break;
            case 6:
                    cls();
			  		main_menu();
                    break;
            case 7:
                    cls();
                    br(1); tab(5); cout<<"---- TERIMAKASIH SUDAH MENCOBA E-RAPOR PTI 2022 ----"; Sleep(200);
                    br(1); tab(5); cout<<"-------- By : Mohammad Bagus Nur Cahyo --------"; Sleep(200);
                    Sleep(1000);
                    getch();
                    exit(1);
                    break;
              default:
			  		br(2); tab(5); cout<<"MOHON MEMILIH MENU DENGAN BENAR!!!"; Sleep(200);
                    cls();
                    cin.clear();
                    goto start;
     }
     goto start;
}

//--------- FUNGSI LOGIN DOSEN -----------//
void Login_Dosen()
{
     cls();
     char pass[7];
     pass[6]='\0';
     int t=0;
     start:
     br(2); tab(5); cout<<"MASUKKAN PASSWORD: "; Sleep(200);
     for(int i=0;i<6;++i){
             pass[i]=getch();
             cout<<"*";
     }
     br(3);
     if(strcmp(pass,"qwerty")==0){
         br(2); tab(5); cout<<"--- Selamat Anda Berhasil Masuk ke Halaman DOSEN ---"; Sleep(200);
         Sleep(1000);
         cls();
		 Dosen();
     }
     else{
         if(t==3){
             br(2); tab(5); cout<<"!!!KATA SANDI YANG ANDA MASUKKAN SALAH LEBIH DARI 3 KALI!!!."; Sleep(200);
             getch();
             cls();
             main_menu();
         }
         br(2); tab(5); cout<<"KATA SANDI YANG ANDA MASUKKAN SALAH, ULANG???"; Sleep(200);
         ++t;
         Sleep(1000);
         cls();
         goto start;
     }
}

//------------- FUNGSI MAIN -----------//
int main(){
    fullscreen();
    //loadingbar();
    cls();
    //selamat_datang();
    Sleep(300);
    cls();
	main_menu();
	//Dosen();
	getch();
	return 0;


}


void fullscreen(){
keybd_event(VK_MENU,0x38,0,0);
keybd_event(VK_RETURN,0x1c,0,0);
keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void warna(int clr){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);
}
