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

int main() {
    // Inisialisasi array destinasi wisata
    Destinasi wisata[MAX_WISATA] = {
        {"Pulau Derawan", "Berau", "10-April-2025", "1500000", 50},
        {"Bukit Bangkirai", "Kukar", "20-Mei-2025", "750000", 30},
        {"Kepulauan Maratua", "Berau", "15-Juni-2025", "2000000", 25},
        {"Pantai Melawai", "Balikpapan", "5-Juli-2025", "500000", 40},
        {"Danau Labuan Cermin", "Biduk-biduk", "1-Agustus-2025", "1000000", 20}
    };
    int wisataCount = 5;

    Booking bookings[MAX_BOOKING];
    int bookingCount = 0;

    // Array akun untuk multiuser (admin & pengguna)
    Akun akun[MAX_AKUN] = {
        {"paras", "2010"},                         // Admin (default)
        {"Muhammad Farras Arhab Ince", "2409106092"} // Pengguna default
    };
    int Jumlahakun = 2;

    string exitMessage = "Program berhenti. Sampai Jumpa!";
    string loginFailedMessage = "Login Gagal. Coba Lagi";
    bool isRunning = true;

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

        if (opsi == 1) {
            string user, pass;
            int loginAttempt = 0;
            bool success = false;
            while (loginAttempt < 3 && !success) {
                cout << "\nNama: ";
                getline(cin, user);
                cout << "NIM: ";
                getline(cin, pass);
                for (int i = 0; i < Jumlahakun; i++) {
                    if (user == akun[i].nama && pass == akun[i].nim) {
                        success = true;
                        break;
                    }
                }
                if (!success) {
                    cout << loginFailedMessage << endl;
                    loginAttempt++;
                }
            }
            if (!success) {
                cout << "Anda gagal login 3 kali. Program berhenti.\n";
                return 0;
            }

            // Cek apakah akun yang login adalah admin
            if (user == akun[0].nama && pass == akun[0].nim) {
                // Menu Admin
                while (true) {
                    cout << "\n========== Menu Admin ==========\n";
                    cout << "1. Lihat Destinasi\n";
                    cout << "2. Tambah Destinasi\n";
                    cout << "3. Edit Destinasi\n";
                    cout << "4. Hapus Destinasi\n";
                    cout << "5. Logout\n";
                    cout << "================================\n";
                    cout << "Pilih opsi: ";
                    int optAdmin;
                    cin >> optAdmin;
                    cin.ignore();

                    if (optAdmin == 1) {
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
                    else if (optAdmin == 2) {
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
                    }
                    else if (optAdmin == 3) {
                        cout << "\nDaftar Destinasi:\n";
                        for (int i = 0; i < wisataCount; i++) {
                            cout << i + 1 << ". " << wisata[i].nama << "\n";
                        }
                        cout << "Nomor destinasi yang ingin diedit: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num >= 1 && num <= wisataCount) {
                            int idx = num - 1;
                            cout << "\nBagian yang ingin diedit:\n";
                            cout << "1. Destinasi\n";
                            cout << "2. Lokasi\n";
                            cout << "3. Tanggal\n";
                            cout << "4. Harga Tiket\n";
                            cout << "5. Stok Tiket\n";
                            cout << "Pilih opsi: ";
                            int editOpt;
                            cin >> editOpt;
                            cin.ignore();
                            if (editOpt >= 1 && editOpt <= 5) {
                                cout << "Masukkan data baru: ";
                                if (editOpt == 5) {
                                    cin >> wisata[idx].stok;
                                    cin.ignore();
                                } else {
                                    string dataBaru;
                                    getline(cin, dataBaru);
                                    if (editOpt == 1) wisata[idx].nama = dataBaru;
                                    else if (editOpt == 2) wisata[idx].lokasi = dataBaru;
                                    else if (editOpt == 3) wisata[idx].tanggal = dataBaru;
                                    else if (editOpt == 4) wisata[idx].harga = dataBaru;
                                }
                                cout << "Data berhasil diupdate.\n";
                            } else {
                                cout << "Opsi tidak valid.\n";
                            }
                        } else {
                            cout << "Nomor tidak valid.\n";
                        }
                    }
                    else if (optAdmin == 4) {
                        cout << "\nDaftar Destinasi:\n";
                        for (int i = 0; i < wisataCount; i++) {
                            cout << i + 1 << ". " << wisata[i].nama << "\n";
                        }
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
                    }
                    else if (optAdmin == 5) {
                        break;
                    }
                    else {
                        cout << "Opsi tidak valid.\n";
                    }
                }
            }
            else { // Menu Pengguna
                while (true) {
                    cout << "\n========== Menu Pengguna ==========\n";
                    cout << "1. Pesan Tiket Wisata\n";
                    cout << "2. Lihat Tiket yang Dipesan\n";
                    cout << "3. Batalkan Tiket Pesanan\n";
                    cout << "4. Logout\n";
                    cout << "=====================================\n";
                    cout << "Pilih opsi: ";
                    int opsiuser;
                    cin >> opsiuser;
                    cin.ignore();

                    if (opsiuser == 1) {
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

                        cout << "Nomor destinasi yang ingin dipesan: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num >= 1 && num <= wisataCount) {
                            int idx = num - 1;
                            cout << "Jumlah tiket yang ingin dipesan: ";
                            int jumlah;
                            cin >> jumlah;
                            cin.ignore();

                            if (jumlah <= wisata[idx].stok) {
                                bookings[bookingCount] = {wisata[idx].nama, wisata[idx].lokasi, wisata[idx].tanggal, wisata[idx].harga, jumlah};
                                bookingCount++;
                                wisata[idx].stok -= jumlah;
                                cout << "Tiket berhasil dipesan!\n";
                            } else {
                                cout << "Stok tiket tidak mencukupi.\n";
                            }
                        } else {
                            cout << "Nomor tidak valid.\n";
                        }
                    }
                    else if (opsiuser == 2) {
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
                    else if (opsiuser == 3) {
                        cout << "\nDaftar Tiket yang Dipesan:\n";
                        for (int i = 0; i < bookingCount; i++) {
                            cout << i + 1 << ". " << bookings[i].destinasi << " (" << bookings[i].jumlah << " tiket)\n";
                        }
                        cout << "Nomor pesanan yang ingin dibatalkan: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num >= 1 && num <= bookingCount) {
                            int idx = num - 1;
                            // Kembalikan stok
                            for (int j = 0; j < wisataCount; j++) {
                                if (wisata[j].nama == bookings[idx].destinasi) {
                                    wisata[j].stok += bookings[idx].jumlah;
                                    break;
                                }
                            }
                            // Hapus booking
                            for (int i = idx; i < bookingCount - 1; i++) {
                                bookings[i] = bookings[i + 1];
                            }
                            bookingCount--;
                            cout << "Pesanan berhasil dibatalkan.\n";
                        } else {
                            cout << "Nomor tidak valid.\n";
                        }
                    }
                    else if (opsiuser == 4) {
                        break;
                    }
                    else {
                        cout << "Opsi tidak valid.\n";
                    }
                }
            }
        }
        else if (opsi == 2) {
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
        else if (opsi == 3) {
            cout << exitMessage << endl;
            isRunning = false;
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}