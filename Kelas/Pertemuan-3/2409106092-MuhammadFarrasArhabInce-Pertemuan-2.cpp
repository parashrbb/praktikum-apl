#include <iostream>
using namespace std;

int main() {
// //1. Cara Mendeklarasi struct
//     struct Mahasiswa {
//         int nim;
//         string nama;
//         float nilai;
//         };
// // atau
//     // typedef struct {
//     //     int nim;
//     //     string nama;
//     //     float nilai;
//     //     } mahasiswa;
    

// // Untuk mendeklarasikan sebuah variabel mhs yang bertipe struct
    
//     // struct Mahasiswa mhs;
// // atau
//     Mahasiswa mhs;
//     mhs.nim = 92 ;
//     mhs.nama = "Paras";
//     mhs.nilai = 90;
        
//     cout << "NIM : " << mhs.nim << endl;
//     cout << "Nama : " << mhs.nama << endl;
//     cout << "Nilai Akhir : " << mhs.nilai << endl;
// }
    
    // typedef struct {
    //     int nim;
    //     string nama;
    //     } datamhs;
    //     struct datanilai {
    //     float nilai_uts;
    //     float nilai_uas;
    //     };
    //     typedef struct {
    //     datamhs mhs;
    //     struct datanilai nil;
    //     } nilai;
        
    //     nilai nilaimhs;
    //     nilaimhs.mhs.nim = 6054;
    //     nilaimhs.mhs.nama = "paras";
    //     nilaimhs.nil.nilai_uts = 60;
    //     nilaimhs.nil.nilai_uas = 60;
        
    //     cout << "NIM : " << nilaimhs.mhs.nim << endl;
    //     cout << "Nama : " << nilaimhs.mhs.nama << endl;
    //     cout << "Nilai UTS : " << nilaimhs.nil.nilai_uts << endl;
    //     cout << "Nilai UAS : " << nilaimhs.nil.nilai_uas << endl;

    // struct nestedmhs {
    //     string nama;
    //     int nim;
    // };

    // struct nestednilai {
    //     int nilai;
    //     string matkul;
    // };

    // struct datamhs{
    //     nestedmhs mhs;
    //     nestednilai nilai;
    // };

    // datamhs data;

    // data.mhs.nama = "Paras";
    // data.mhs.nim = 20;

    // cout << "Nama: " << data.mhs.nama << endl;

    struct data {
        int nim;
        string nama;
        int nilai;
    };

    data datamahasiswa[2];
    
    cout << "HALO MAHASISWA PERTAMA DI UNIVERSITAS KAMI!!\n";
    cout << "masukkan nim anda: ";
    cin >> datamahasiswa[0].nim;
    cout << "\nmasukkan nama anda: ";
    cin >> datamahasiswa[0].nama;
    cout << "\nmasukkan nilai anda (jujur): ";
    cin >> datamahasiswa[0].nilai;





}