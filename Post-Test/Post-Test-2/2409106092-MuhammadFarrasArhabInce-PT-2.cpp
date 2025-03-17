#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_WISATA 100
#define INFO 5
#define MAX_BOOKING 100

int main() {
    // Data destinasi wisata: {destinasi, lokasi, tanggal, harga, stok}
    string wisata[MAX_WISATA][INFO] = {
        {"Pulau Derawan", "Berau", "10-April-2025", "1500000", "50"},
        {"Bukit Bangkirai", "Kukar", "20-Mei-2025", "750000", "30"},
        {"Kepulauan Maratua", "Berau", "15-Juni-2025", "2000000", "25"},
        {"Pantai Melawai", "Balikpapan", "5-Juli-2025", "500000", "40"},
        {"Danau Labuan Cermin", "Biduk-biduk", "1-Agustus-2025", "1000000", "20"}
    };
    int wisataCount = 5;

    string bookings[MAX_BOOKING][INFO];
    int bookingCount = 0;

    string usernames[2] = {"paras", "Muhammad Farras Arhab Ince"};
    string passwords[2] = {"2010", "2409106092"};
    string katakata[2] = {"Program berhenti. Sampai Jumpa!", "Login Gagal. Coba Lagi"};

    int loginAttempt = 0;
    bool isRunning = true;

    while (isRunning) {
        cout << "\n============================================\n";
        cout << "          HALO SELAMAT DATANG!\n";
        cout << "        Pemesanan Tiket Wisata\n";
        cout << "============================================\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "============================================\n";
        cout << "Pilih opsi: ";
        int opsi;
        cin >> opsi;
        cin.ignore();

        if (opsi == 1) {
            string user, pass;
            loginAttempt = 0;
            bool success = false;
            while (loginAttempt < 3 && !success) {
                cout << "\nUsername: ";
                getline(cin, user);
                cout << "Password: ";
                getline(cin, pass);

                for (int i = 0; i < 2; i++) {
                    if (user == usernames[i] && pass == passwords[i]) {
                        success = true;
                        break;
                    }
                }
                if (!success) {
                    cout << katakata[1];
                    loginAttempt++;
                }
            }
            if (!success) {
                cout << "Anda gagal login 3 kali. Program berhenti.\n";
                return 0;
            }

            if (user == usernames[0] && pass == passwords [0]) {
                // Admin Menu
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
                                 << setw(20) << wisata[i][0] << " | "
                                 << setw(14) << wisata[i][1] << " | "
                                 << setw(20) << wisata[i][2] << " | "
                                 << setw(10) << wisata[i][3] << " | "
                                 << setw(14) << wisata[i][4] << " |\n";
                        }
                        cout << "+----+----------------------+----------------+----------------------+------------+----------------+\n";
                    }
                    else if (optAdmin == 2) {
                        if (wisataCount < MAX_WISATA) {
                            cout << "\n=== Tambah Destinasi ===\n";
                            cout << "Destinasi: "; getline(cin, wisata[wisataCount][0]);
                            cout << "Lokasi: "; getline(cin, wisata[wisataCount][1]);
                            cout << "Tanggal: "; getline(cin, wisata[wisataCount][2]);
                            cout << "Harga Tiket: "; getline(cin, wisata[wisataCount][3]);
                            cout << "Stok Tiket: "; getline(cin, wisata[wisataCount][4]);
                            wisataCount++;
                            cout << "\nDestinasi berhasil ditambahkan.\n";
                        } else {
                            cout << "\nData destinasi penuh.\n";
                        }
                    }
                    else if (optAdmin == 3) {
                        cout << "\nDaftar Destinasi:\n";
                        for (int i = 0; i < wisataCount; i++) {
                            cout << i + 1 << ". " << wisata[i][0] << "\n";
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
                                getline(cin, wisata[idx][editOpt - 1]);
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
                            cout << i + 1 << ". " << wisata[i][0] << "\n";
                        }
                        cout << "Nomor destinasi yang ingin dihapus: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num >= 1 && num <= wisataCount) {
                            for (int i = num - 1; i < wisataCount - 1; i++) {
                                for (int j = 0; j < INFO; j++) {
                                    wisata[i][j] = wisata[i + 1][j];
                                }
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
                }
            }
            else if (user == usernames[1] && pass == passwords[1]) {
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
                                 << setw(20) << wisata[i][0] << " | "
                                 << setw(14) << wisata[i][1] << " | "
                                 << setw(20) << wisata[i][2] << " | "
                                 << setw(10) << wisata[i][3] << " | "
                                 << setw(14) << wisata[i][4] << " |\n";
                        }
                        cout << "+----+----------------------+----------------+----------------------+------------+----------------+\n";
                    
                        cout << "\nMasukkan nomor destinasi: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num >= 1 && num <= wisataCount) {
                            int idx = num - 1;
                            int stok = stoi(wisata[idx][4]);
                            cout << "Masukkan jumlah tiket yang ingin dipesan: ";
                            int jumlah;
                            cin >> jumlah;
                            cin.ignore();
                            if (jumlah > 0 && jumlah <= stok) {
                                bool found = false;
                                for (int i = 0; i < bookingCount; i++) {
                                    if (bookings[i][0] == wisata[idx][0]) { 
                                        bookings[i][5] = to_string(stoi(bookings[i][5]) + jumlah); // Tambah jumlah tiket
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) {
                                    for (int j = 0; j < INFO; j++) {
                                        bookings[bookingCount][j] = wisata[idx][j];
                                    }
                                    bookings[bookingCount][5] = to_string(jumlah); // Tambahkan jumlah tiket
                                    bookingCount++;
                                }
                                wisata[idx][4] = to_string(stok - jumlah);
                                cout << "Tiket berhasil dipesan.\n";
                            } else {
                                cout << "Jumlah tiket tidak valid atau stok tidak mencukupi.\n";
                            }
                        } else {
                            cout << "Nomor destinasi tidak valid.\n";
                        }
                    }
                    else if (opsiuser == 2) {
                        if (bookingCount > 0) {
                            cout << "\n----- Tiket yang Dipesan -----\n";
                            cout << "+----+----------------------+----------------+----------------------+------------+--------+\n";
                            cout << "| NO | Destinasi            | Lokasi         | Tanggal              | Harga      | Jumlah |\n";
                            cout << "+----+----------------------+----------------+----------------------+------------+--------+\n";
                            for (int i = 0; i < bookingCount; i++) {
                                cout << "| " << setw(2) << i + 1 << " | "
                                     << setw(20) << bookings[i][0] << " | "
                                     << setw(14) << bookings[i][1] << " | "
                                     << setw(20) << bookings[i][2] << " | "
                                     << setw(10) << bookings[i][3] << " | "
                                     << setw(6) << bookings[i][5] << " |\n"; // Menampilkan jumlah tiket
                            }
                            cout << "+----+----------------------+----------------+----------------------+------------+--------+\n";
                        } else {
                            cout << "\nBelum ada tiket yang dipesan.\n";
                        }
                    }                    
                    else if (opsiuser == 3) {
                        if (bookingCount > 0) {
                            cout << "\nNomor tiket yang ingin dibatalkan: ";
                            int del;
                            cin >> del;
                            cin.ignore();
                            if (del >= 1 && del <= bookingCount) {
                                bookingCount--;
                                for (int i = del - 1; i < bookingCount; i++) {
                                    for (int j = 0; j < INFO; j++) {
                                        bookings[i][j] = bookings[i + 1][j];
                                    }
                                }
                                cout << "Tiket berhasil dibatalkan.\n";
                            } else {
                                cout << "Nomor tidak valid.\n";
                            }
                        } else {
                            cout << "\nBelum ada tiket yang dipesan.\n";
                        }
                    }
                    else if (opsiuser == 4) {
                        break;
                    }
                }
            }
        } else if (opsi == 2) {
            isRunning = false;
        }
    }
    cout << katakata[0];
    return 0;
}