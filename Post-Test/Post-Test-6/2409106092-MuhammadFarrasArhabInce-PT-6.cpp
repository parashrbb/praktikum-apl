#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX_WISATA 100
#define MAX_BOOKING 100
#define MAX_AKUN 100

typedef struct {
    string nama;
    string nim;
} Akun;

struct Destinasi {
    string nama;
    string lokasi;
    string tanggal;
    string harga;
    int stok;
};

struct Booking {
    string destinasi;
    string lokasi;
    string tanggal;
    string harga;
    int jumlah;
};

bool Login(int attempt, const int maxAttempt, Akun akun[], int Jumlahakun, string &user, string &pass) {
    if (attempt >= maxAttempt) {
        return false;
    }
    cout << "\nNama: ";
    getline(cin, user);
    cout << "NIM: ";
    getline(cin, pass);
    for (int i = 0; i < Jumlahakun; i++) {
        if (user == akun[i].nama && pass == akun[i].nim) {
            return true;
        }
    }
    cout << "Login Gagal. Coba Lagi" << endl;
    return Login(attempt + 1, maxAttempt, akun, Jumlahakun, user, pass);
}

void tampilkan(Destinasi wisata[], int wisataCount) {
    cout << "\n----- Daftar Destinasi Wisata -----\n";
    cout << "+----+----------------------+----------------+----------------------+------------+----------------+\n";
    cout << "| NO | Destinasi            | Lokasi         | Tanggal              | Harga      | Tiket Tersedia |\n";
    cout << "+----+----------------------+----------------+----------------------+------------+----------------+\n";
    for (int i = 0; i < wisataCount; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(20) << wisata[i].nama << " | "
             << setw(14) << wisata[i].lokasi << " | "
             << setw(20) << wisata[i].tanggal << " | "
             << setw(10) << wisata[i].harga << " | "
             << setw(14) << wisata[i].stok << " |\n";
    }
    cout << "+----+----------------------+----------------+----------------------+------------+----------------+\n";
}

void tampilkan(Booking bookings[], int bookingCount) {
    cout << "\n===== Tiket yang Dipesan =====\n";
    cout << "+----+----------------------+----------------+----------------------+------------+--------+\n";
    cout << "| NO | Destinasi            | Lokasi         | Tanggal              | Harga      | Jumlah |\n";
    cout << "+----+----------------------+----------------+----------------------+------------+--------+\n";
    for (int i = 0; i < bookingCount; i++) {
        cout << "| " << setw(2) << i + 1 << " | "
             << setw(20) << bookings[i].destinasi << " | "
             << setw(14) << bookings[i].lokasi << " | "
             << setw(20) << bookings[i].tanggal << " | "
             << setw(10) << bookings[i].harga << " | "
             << setw(6) << bookings[i].jumlah << " |\n";
    }
    cout << "+----+----------------------+----------------+----------------------+------------+--------+\n";
}

void tambahStok(Destinasi *d, int jumlah) {
    d->stok += jumlah;
}

void cetakBooking(Booking *b) {
    cout << "\n===== Detail Tiket Booking =====\n";
    cout << "Destinasi: " << b->destinasi << endl;
    cout << "Lokasi: " << b->lokasi << endl;
    cout << "Tanggal: " << b->tanggal << endl;
    cout << "Harga: Rp" << b->harga << endl;
    cout << "Jumlah Tiket: " << b->jumlah << endl;
}

void ListDestinasi(Destinasi wisata[], int wisataCount) {
    for (int i = 0; i < wisataCount; i++) {
        cout << i + 1 << ". " << wisata[i].nama << "\n";
    }
}

// Merge Sort Nama, Destinasi (Descending Z - A)
void mergeNamaDesc(Destinasi arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    Destinasi L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].nama > R[j].nama) arr[k++] = L[i++];
        else                     arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortNamaDesc(Destinasi arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortNamaDesc(arr, l, m);
        mergeSortNamaDesc(arr, m + 1, r);
        mergeNamaDesc(arr, l, m, r);
    }
}

// Bubble Sort Angka, Harga (Ascending 0 - 9)
void bubbleSortHargaAsc(Destinasi arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (stoi(arr[j].harga) > stoi(arr[j+1].harga)) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// Selection Sort Angka, Stok Tiket (Ascending 0 - 9)
void selectionSortStokAsc(Destinasi arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j].stok < arr[minIdx].stok) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

void MenuAdmin(Destinasi wisata[], int &wisataCount, Booking bookings[], int &bookingCount) {
    int optAdmin;
    while (true) {
        cout << "\n========== Menu Admin ==========\n";
        cout << "1. Lihat Destinasi\n";
        cout << "2. Tambah Destinasi\n";
        cout << "3. Edit Destinasi\n";
        cout << "4. Hapus Destinasi\n";
        cout << "5. Sortir Data\n";
        cout << "6. Logout\n";
        cout << "================================\n";
        cout << "Pilih opsi: ";
        cin >> optAdmin;
        cin.ignore();

        switch(optAdmin) {
            case 1:
                tampilkan(wisata, wisataCount);
                break;
            case 2:
    
                if (wisataCount < MAX_WISATA) {
                    cout << "\n=== Tambah Destinasi ===\n";
                    cout << "Destinasi: "; getline(cin, wisata[wisataCount].nama);
                    cout << "Lokasi: "; getline(cin, wisata[wisataCount].lokasi);
                    cout << "Tanggal: "; getline(cin, wisata[wisataCount].tanggal);
                    cout << "Harga Tiket: "; getline(cin, wisata[wisataCount].harga);
                    cout << "Stok Tiket: "; cin >> wisata[wisataCount].stok; cin.ignore();
                    wisataCount++;
                    cout << "\nDestinasi berhasil ditambahkan.\n";
                } else {
                    cout << "\nData destinasi penuh.\n";
                }
                break;
            case 3: {
    
                cout << "\nDaftar Destinasi:\n";
                ListDestinasi(wisata, wisataCount);
                cout << "Nomor destinasi yang ingin diedit: ";
                int num;
                cin >> num;
                cin.ignore();
                if (num >= 1 && num <= wisataCount) {
                    int indeks = num - 1;
                    cout << "\nBagian yang ingin diedit:\n";
                    cout << "1. Destinasi\n";
                    cout << "2. Lokasi\n";
                    cout << "3. Tanggal\n";
                    cout << "4. Harga Tiket\n";
                    cout << "5. Stok Tiket\n";
                    cout << "Pilih opsi: \n";
                    int editOpt;
                    cin >> editOpt;
                    cin.ignore();
                    if (editOpt >= 1 && editOpt <= 5) {
                        cout << "Masukkan data baru: ";
                        if (editOpt == 5) {
                            cin >> wisata[indeks].stok;
                            cin.ignore();
                        } else {
                            string dataBaru;
                            getline(cin, dataBaru);
                            if (editOpt == 1) wisata[indeks].nama = dataBaru;
                            else if (editOpt == 2) wisata[indeks].lokasi = dataBaru;
                            else if (editOpt == 3) wisata[indeks].tanggal = dataBaru;
                            else if (editOpt == 4) wisata[indeks].harga = dataBaru;
                        }
                        cout << "Data berhasil diupdate.\n";
                    } else {
                        cout << "Opsi tidak valid.\n";
                    }
                } else {
                    cout << "Nomor tidak valid.\n";
                }
                break;
            }
            case 4: {
    
                cout << "\nDaftar Destinasi:\n";
                ListDestinasi(wisata, wisataCount);
                cout << "Nomor destinasi yang ingin dihapus: ";
                int num;
                cin >> num;
                cin.ignore();
                if (num >= 1 && num <= wisataCount) {
                    for (int i = num - 1; i < wisataCount - 1; i++) {
                        wisata[i] = wisata[i + 1];
                    }
                    wisataCount--;
                    cout << "\nDestinasi berhasil dihapus.\n";
                } else {
                    cout << "Nomor tidak valid.\n";
                }
                break;
            }
            case 5: {
    
                cout << "\nData Yang Ingin Disortir:\n";
                cout << "1. Nama Destinasi (Z - A)\n";
                cout << "2. Harga Tiket (0 - 9)\n";
                cout << "3. Tiket Tersedia (0 - 9)\n";
                cout << "Pilih Data: ";
                int pildata;
                cin >> pildata;
                cin.ignore();
            
                switch (pildata) {
                    case 1:
            
                        mergeSortNamaDesc(wisata, 0, wisataCount - 1);
                        cout << "Berhasil sortir berdasarkan Nama (Z - A)\n";
                        tampilkan(wisata, wisataCount);
                        break;
                    case 2:
                        bubbleSortHargaAsc(wisata, wisataCount);
                        cout << "Berhasil sortir berdasarkan Harga (0 - 9)\n";
                        tampilkan(wisata, wisataCount);
                        break;
                    case 3:
                        selectionSortStokAsc(wisata, wisataCount);
                        cout << "Berhasil sortir berdasarkan Tiket Tersedia (0 - 9)\n";
                        tampilkan(wisata, wisataCount);
                        break;
                    default:
                        cout << "Opsi sorting tidak valid.\n";
                        break;
                }
                break;
            }     
            case 6:
                return;
            default:
                cout << "Opsi tidak valid.\n";
        }
    }
}

void MenuPengguna(Destinasi wisata[], int &wisataCount, Booking bookings[], int &bookingCount) {
    int opsiuser;
    while (true) {
        cout << "\n========== Menu Pengguna ==========\n";
        cout << "1. Lihat Destinasi\n";
        cout << "2. Pesan Tiket Wisata\n";
        cout << "3. Lihat Tiket yang Dipesan\n";
        cout << "4. Batalkan Tiket Pesanan\n";
        cout << "5. Sortir Data\n";
        cout << "6. Logout\n";
        cout << "=====================================\n";
        cout << "Pilih opsi: \n";
        cin >> opsiuser;
        cin.ignore();

        switch(opsiuser) {
            case 1:
                tampilkan(wisata, wisataCount);
                break;
            case 2: {
    
                tampilkan(wisata, wisataCount);
                cout << "Nomor destinasi yang ingin dipesan: ";
                int num;
                cin >> num;
                cin.ignore();
                if (num >= 1 && num <= wisataCount) {
                    Destinasi *dipilih = &wisata[num - 1];
                    cout << "Jumlah tiket yang ingin dipesan: ";
                    int jumlah;
                    cin >> jumlah;
                    cin.ignore();
                    if (jumlah <= dipilih->stok) {
                        bookings[bookingCount] = {dipilih->nama, dipilih->lokasi, dipilih->tanggal, dipilih->harga, jumlah};
                        bookingCount++;
                        dipilih->stok -= jumlah;
                        cout << "Tiket berhasil dipesan!\n";
                    } else {
                        cout << "Stok tiket tidak mencukupi.\n";
                    }
                } else {
                    cout << "Nomor tidak valid.\n";
                }
                break;
            }
            case 3:
                tampilkan(bookings, bookingCount);
                break;
            case 4: {
                cout << "\nDaftar Tiket yang Dipesan:\n";
                tampilkan(bookings, bookingCount);
                cout << "Nomor pesanan yang ingin dibatalkan: ";
                int num;
                cin >> num;
                cin.ignore();
                if (num >= 1 && num <= bookingCount) {
                    int indeks = num - 1;
                    for (int j = 0; j < wisataCount; j++) {
                        if (wisata[j].nama == bookings[indeks].destinasi) {
                            tambahStok(&wisata[j], bookings[indeks].jumlah);
                            break;
                        }
                    }
                    cetakBooking(&bookings[indeks]);
                    for (int i = indeks; i < bookingCount - 1; i++) {
                        bookings[i] = bookings[i + 1];
                    }
                    bookingCount--;
                    cout << "Pesanan berhasil dibatalkan.\n";
                } else {
                    cout << "Nomor tidak valid.\n";
                }
                break;
            }
            case 5: {
    
                cout << "\nData Yang Ingin Disortir:\n";
                cout << "1. Nama Destinasi (Z - A)\n";
                cout << "2. Harga Tiket (0 - 9)\n";
                cout << "3. Tiket Tersedia (0 - 9)\n";
                cout << "Pilih Data: ";
                int pildata;
                cin >> pildata;
                cin.ignore();
            
                switch (pildata) {
                    case 1:
                        mergeSortNamaDesc(wisata, 0, wisataCount - 1);
                        cout << "Berhasil sortir berdasarkan Nama (Z - A)\n";
                        tampilkan(wisata, wisataCount);
                        break;
                    case 2:
                        bubbleSortHargaAsc(wisata, wisataCount);
                        cout << "Berhasil sortir berdasarkan Harga (0 - 9)\n";
                        tampilkan(wisata, wisataCount);
                        break;
                    case 3:
                        selectionSortStokAsc(wisata, wisataCount);
                        cout << "Berhasil sortir berdasarkan Tiket Tersedia (0 - 9)\n";
                        tampilkan(wisata, wisataCount);
                        break;
                    default:
                        cout << "Opsi sorting tidak valid.\n";
                        break;
                }
                break;
            }            
            case 6:
    
                return;
            default:
                cout << "Opsi tidak valid.\n";
        }
    }
}

void RegisterAkun(Akun akun[], int &Jumlahakun) {
    if (Jumlahakun < MAX_AKUN) {
        cout << "\n=== Register Akun Baru ===\n";
        cout << "Masukkan Username: ";
        getline(cin, akun[Jumlahakun].nama);
        cout << "Masukkan NIM: ";
        getline(cin, akun[Jumlahakun].nim);
        Jumlahakun++;
        cout << "Register berhasil! Silakan login kembali." << endl;
    } else {
        cout << "Kapasitas akun penuh." << endl;
    }
}

void mainMenu(Destinasi wisata[], int &wisataCount, Booking bookings[], int &bookingCount, Akun akun[], int &Jumlahakun) {
    bool isRunning = true;
    string exitMessage = "Program berhenti. Sampai Jumpa!";
    while (isRunning) {
        cout << "\n============================================\n";
        cout << "          HALO SELAMAT DATANG!\n";
        cout << "        Pemesanan Tiket Wisata\n";
        cout << "============================================\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Exit\n";
        cout << "============================================\n";
        cout << "Pilih opsi: ";
        int opsi;
        cin >> opsi;
        cin.ignore();

        switch(opsi) {
            case 1: {
    
                string user, pass;
                bool success = Login(0, 3, akun, Jumlahakun, user, pass);
                if (!success) {
                    cout << "Anda gagal login 3 kali. Program berhenti.\n";
                    return;
                }
    
                if (user == akun[0].nama && pass == akun[0].nim)
                    MenuAdmin(wisata, wisataCount, bookings, bookingCount);
                else
                    MenuPengguna(wisata, wisataCount, bookings, bookingCount);
                break;
            }
            case 2:
      
                RegisterAkun(akun, Jumlahakun);
                break;
            case 3:
                cout << exitMessage << endl;
                isRunning = false;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }
}

int main() {
    Destinasi wisata[MAX_WISATA] = {
        {"Pulau Derawan", "Berau", "10-April-2025", "1500000", 50},
        {"Bukit Bangkirai", "Kukar", "20-Mei-2025", "750000", 30},
        {"Kepulauan Maratua", "Berau", "15-Juni-2025", "2000000", 25},
        {"Pantai Melawai", "Balikpapan", "5-Juli-2025", "500000", 40},
        {"Danau Labuan Cermin", "Biduk-biduk", "1-Agustus-2025", "1000000", 20},
        {"Pulau Kumala", "Timbau", "4-Juli-2025", "30000", 100},
        {"Pulau Paus", "Tenggarong", "20-Oktober-2025", "1000", 80},
        {"Ladaya", "Mangkurawang", "2-Oktober-2025", "60000", 50},
        {"Taman Pintar", "Danau Aji", "5-November-2025", "10000", 90},
    };
    int wisataCount = 9;

    Booking bookings[MAX_BOOKING];
    int bookingCount = 0;

    Akun akun[MAX_AKUN] = {
        {"paras", "2010"},
        {"a", "1"}
    };
    int Jumlahakun = 2;

    mainMenu(wisata, wisataCount, bookings, bookingCount, akun, Jumlahakun);
    return 0;
}