#include <iostream>
using namespace std;


// NOTE!!!!!
//* untuk mengambil value dari variable
//& untuk mengambil address dari variable


// struct Address{
//     string kota;
//     string provinsi;
//     string negara;
//     };

// int main() {
//     // deklarasi variabel dengan struct
//     Address address1, address2;
//     // mengisi value address1
//     address1.kota = "Samarinda";
//     address1.provinsi = "Kalimantan Timur";
//     address1.negara = "Indonesia";
//     // mengcopy value address1 ke address2
//     address2 = address1;
//     // mengganti property kota dari samarinda ke ikn
//     address2.kota = "ikn";
//     // value address1
//     cout << address1.kota <<endl;
//     // value address2
//     cout << address2.kota;
//     return 0;
// }


// int main() {
//     // * untuk mengambil value dari variable
//     // & untuk mengambil address dari variable
//     int a = 10;
//     int *b = &a;

//     cout << "alamat dari variable a: " << &a << endl;

//     cout << a;
// }


// void cekNilai (int arr[100]) {
//     cout << "elemen pertama adalah: " << arr[0] << endl;
// }

// int main () {
//     int array [100] = {1,2,3};
//     cekNilai(array);
// }

// void cekNilai (int *arr) {
//     cout << "elemen pertama adalah: " << arr[0] << endl;
// }

// int main () {
//     int array [100] = {1,2,3};
//     cekNilai(array);
// }


// int ubahNilai(int a, int b){
//     return a = b;
// }

// int main () {
//     int a,b;
//     a=5;
//     b=20;

//     ubahNilai( a, b );
//     cout << a;

//     return 0;
// }


// int ubahNilai(int &a, int b){
//     return a = b;
// }

// int main () {
//     int a,b;
//     a=5;
//     b=20;

//     ubahNilai( a, b );
//     cout << a;

//     return 0;
// }


// int ubahNilai(int *a, int b){
//     return *a = b;
// }

// int main () {
//     int a,b;
//     a=5;
//     b=20;

//     ubahNilai( &a, b );
//     cout << a;

//     return 0;
// }