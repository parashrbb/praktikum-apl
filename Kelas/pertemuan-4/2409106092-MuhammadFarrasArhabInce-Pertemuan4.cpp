#include <iostream>
using namespace std;

// // fungsi
// int hitung () {
//     //isi fungsi
// }

// //prosedur
// void cetak() {
//     //isi prosedur
// }


int hitung_luas (int a) {
    double luas = 3.14 * a * a;
    return luas;

}

int tambahan(int a, int b){
    double hitung = 12 + a + b;
    return hitung;
}

int luas (int a, int b){
    return a * b;
}

int luas (int a) {
    return a * a;
}

int faktorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * faktorial(n-1);
    }
}


int main () {
    cout << hitung_luas(5) << endl;
    cout << tambahan (2, 3) << endl;
    cout << "Luas persegi panjang: " << luas(4, 5) << endl;
    cout << "Luas persegi: " << luas(4) << endl;
    cout << faktorial(2) << endl;

}