#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string username, password;
    do {
        cout << "== SILAHKAN MASUK ==\n"
             << "Masukkan username: ";
        getline(cin, username); 
        cout << "Masukkan password: ";
        cin >> password;
        cin.ignore();

        if (username != "Muhammad Farras Arhab Ince" || password != "2409106092") {
            cout << "Login gagal! Coba lagi.\n";
        }
    } while (username != "Muhammad Farras Arhab Ince" || password != "2409106092");

    cout << "Login berhasil! Selamat datang, " << username << "!\n";
    
    int pilihan;
    do {
        cout << "\n== MENU UTAMA ==\n"
             << "1. Hitung Luas\n"
             << "2. Hitung Keliling\n"
             << "3. Hitung Volume\n"
             << "4. Keluar\n"
             << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            int pilihLuas;
            do {
                cout << "\n== HITUNG LUAS ==\n"
                     << "1. Persegi\n"
                     << "2. Persegi Panjang\n"
                     << "3. Lingkaran\n"
                     << "4. Segitiga\n"
                     << "5. Jajar Genjang\n"
                     << "6. Trapesium\n"
                     << "7. Belah Ketupat\n"
                     << "8. Kembali\n"
                     << "Pilih bangun datar: ";
                cin >> pilihLuas;

                if (pilihLuas == 1) {
                    double sisi;
                    cout << "Masukkan panjang sisi: ";
                    cin >> sisi;
                    cout << "Luas Persegi: " << sisi * sisi << endl;
                } else if (pilihLuas == 2) {
                    double panjang, lebar;
                    cout << "Masukkan panjang: ";
                    cin >> panjang;
                    cout << "Masukkan lebar: ";
                    cin >> lebar;
                    cout << "Luas Persegi Panjang: " << panjang * lebar << endl;
                } else if (pilihLuas == 3) {
                    double jariJari;
                    cout << "Masukkan jari-jari: ";
                    cin >> jariJari;
                    cout << "Luas Lingkaran: " << 3.14 * jariJari * jariJari << endl;
                } else if (pilihLuas == 4) {
                    double alas, tinggi;
                    cout << "Masukkan panjang alas: ";
                    cin >> alas;
                    cout << "Masukkan tinggi: ";
                    cin >> tinggi;
                    cout << "Luas Segitiga: " << 0.5 * alas * tinggi << endl; 
                } else if (pilihLuas == 5) {
                    double alas, tinggi;
                    cout << "Masukkan panjang alas: ";
                    cin >> alas;
                    cout << "Masukkan tinggi: ";
                    cin >> tinggi;
                    cout << "Luas Jajar Genjang: " << alas * tinggi << endl;
                } else if (pilihLuas == 6) {
                    double sisiatas, sisibawah, tinggi;
                    cout << "Masukkan sisi atas: ";
                    cin >> sisiatas;
                    cout << "Masukkan sisi bawah: ";
                    cin >> sisibawah;
                    cout << "Masukkan tinggi: ";
                    cin >> tinggi;
                    cout << "Luas Trapesium: " << 0.5 * (sisiatas + sisibawah) * tinggi  << endl;
                } else if (pilihLuas == 7) {
                    double diagonal1, diagonal2;
                    cout << "Masukkan diagonal 1: ";
                    cin >> diagonal1;
                    cout << "Masukkan diagonal 2: ";
                    cin >> diagonal2;
                    cout << "Luas Belah Ketupat: " << 0.5 * (diagonal1 * diagonal2) << endl;
                }
            } while (pilihLuas != 8);
        } else if (pilihan == 2) {
            int pilihKeliling;
            do {
                cout << "\n== HITUNG KELILING ==\n"
                     << "1. Persegi\n"
                     << "2. Persegi Panjang\n"
                     << "3. Lingkaran\n"
                     << "4. Segitiga\n"
                     << "5. Jajar Genjang\n"
                     << "6. Trapesium\n"
                     << "7. Belah Ketupat\n"
                     << "8. Kembali\n"
                     << "Pilih bangun datar: ";
                cin >> pilihKeliling;

                if (pilihKeliling == 1) {
                    double sisi;
                    cout << "Masukkan panjang sisi: ";
                    cin >> sisi;
                    cout << "Keliling Persegi: " << 4 * sisi << endl;
                } else if (pilihKeliling == 2) {
                    double panjang, lebar;
                    cout << "Masukkan panjang: ";
                    cin >> panjang;
                    cout << "Masukkan lebar: ";
                    cin >> lebar;
                    cout << "Keliling Persegi Panjang: " << 2 * (panjang + lebar) << endl;
                } else if (pilihKeliling == 3) {
                    double jariJari;
                    cout << "Masukkan jari-jari: ";
                    cin >> jariJari;
                    cout << "Keliling Lingkaran: " << 2 * 3.14 * jariJari << endl;
                } else if (pilihKeliling == 4) {
                    double sisi1, sisi2, sisi3;
                    cout << "Masukkan panjang sisi pertama: ";
                    cin >> sisi1;
                    cout << "Masukkan panjang sisi kedua: ";
                    cin >> sisi2;
                    cout << "Masukkan panjang sisi ketiga: ";
                    cin >> sisi3;
                    cout << "Keliling Segitiga: " << sisi1 + sisi2 + sisi3 << endl;
                } else if (pilihKeliling == 5) {
                    double sisi1, sisi2;
                    cout << "Masukkan panjang sisi pertama: ";
                    cin >> sisi1;
                    cout << "Masukkan Panjang sisi kedua: ";
                    cin >> sisi2;
                    cout << "Keliling Jajar Genjang: " << 2 * (sisi1 + sisi2) << endl;
                } else if (pilihKeliling == 6) {
                    double sisi1, sisi2, sisi3, sisi4;
                    cout << "Masukkan panjang sisi pertama: ";
                    cin >> sisi1;
                    cout << "Masukkan panjang sisi kedua: ";
                    cin >> sisi2;
                    cout << "Masukkan panjang sisi ketiga: ";
                    cin >> sisi3;
                    cout << "Masukkan panjang sisi keempat: ";
                    cin >> sisi4;
                    cout << "Keliling Trapesium: " << sisi1 + sisi2 + sisi3 + sisi4 << endl;  
                } else if (pilihKeliling == 7) {
                    double sisi;
                    cout << "Masukkan panjang sisi belah ketupat: ";
                    cin >> sisi;
                    cout << "Keliling Belah Ketupat: " << 4 * sisi << endl;
                }
            } while (pilihKeliling != 8);
        } else if (pilihan == 3) {
            int pilihVolume;
            do {
                cout << "\n== HITUNG VOLUME ==\n"
                     << "1. Kubus\n"
                     << "2. Balok\n"
                     << "3. Bola\n"
                     << "4. Kerucut\n"
                     << "5. Limas Segiempat\n"
                     << "6. Prisma Segitiga\n"
                     << "7. Tabung\n"
                     << "8. Kembali\n"
                     << "Pilih bangun ruang: ";
                cin >> pilihVolume;

                if (pilihVolume == 1) {
                    double sisi;
                    cout << "Masukkan panjang sisi: ";
                    cin >> sisi;
                    cout << "Volume Kubus: " << pow(sisi, 3) << endl;
                } else if (pilihVolume == 2) {
                    double panjang, lebar, tinggi;
                    cout << "Masukkan panjang: ";
                    cin >> panjang;
                    cout << "Masukkan lebar: ";
                    cin >> lebar;
                    cout << "Masukkan tinggi: ";
                    cin >> tinggi;
                    cout << "Volume Balok: " << panjang * lebar * tinggi << endl;
                } else if (pilihVolume == 3) {
                    double jariJari;
                    cout << "Masukkan jari-jari: ";
                    cin >> jariJari;
                    cout << "Volume Bola: " << (4.0 / 3.0) * 3.14 * pow(jariJari, 3) << endl;
                } else if (pilihVolume == 4) {
                    double jariJari, tinggi;
                    cout << "Masukkan jari-jari: ";
                    cin >> jariJari;
                    cout << "Masukkan tinggi: ";
                    cin >> tinggi;
                    cout << "Volume Kerucut: " << (1.0 / 3.0) * 3.14 * pow(jariJari, 2) * tinggi << endl;
                } else if (pilihVolume == 5) {
                    double panjang, lebar, tinggi;
                    cout << "Masukkan panjang alas: ";
                    cin >> panjang;
                    cout << "Masukkan lebar alas: ";
                    cin >> lebar;
                    cout << "Masukkan tinggi limas: ";
                    cin >> tinggi;
                    cout << "Volume Limas Segiempat: " << (1.0 / 3.0) * (panjang * lebar) * tinggi << endl;
                } else if (pilihVolume == 6) {
                    double alas, tinggiAlas, tinggiPrisma;
                    cout << "Masukkan panjang alas segitiga: ";
                    cin >> alas;
                    cout << "Masukkan tinggi alas segitiga: ";
                    cin >> tinggiAlas;
                    cout << "Masukkan tinggi prisma: ";
                    cin >> tinggiPrisma;
                    cout << "Volume Prisma Segitiga: " << (0.5 * alas * tinggiAlas) * tinggiPrisma << endl;
                } else if (pilihVolume == 7) {
                    double jariJari, tinggi;
                    cout << "Masukkan jari-jari alas: ";
                    cin >> jariJari;
                    cout << "Masukkan tinggi tabung: ";
                    cin >> tinggi;
                    cout << "Volume Tabung: " << 3.14 * pow(jariJari, 2) * tinggi << endl;
                }        
            } while (pilihVolume != 8);
        }
    } while (pilihan != 4);

    return 0;
}