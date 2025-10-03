#include <iostream>
#include <string>
#include <limits>
#include <memory>
#include "Pemilik.h"
#include "KebunBinatang.h"
#include "HewanDarat.h"
#include "HewanAir.h"
#include "Unggas.h"
#include "HewanAmfibi.h"

using namespace std;

// Utility untuk membersihkan buffer input C++
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi Input Hewan Baru (Tetap di Main.cpp karena menangani I/O)
void inputHewan(KebunBinatang& kebun) {
    int pilihanJenis;
    
    cout << "\n--- INPUT DATA HEWAN BARU ---" << endl;
    cout << "1. Hewan Darat" << endl;
    cout << "2. Hewan Air" << endl;
    cout << "3. Unggas" << endl;
    cout << "4. Hewan Amfibi" << endl;
    
    // ... (Logika input pilihanJenis, nama, umur, berat tetap sama) ...
    while (true) {
        cout << "Pilih jenis hewan (1-4): ";
        if (cin >> pilihanJenis && pilihanJenis >= 1 && pilihanJenis <= 4) {
            clearInputBuffer();
            break;
        } else {
            cout << "Pilihan tidak valid. Masukkan angka 1 sampai 4." << endl;
            cin.clear();
            clearInputBuffer();
        }
    }
    
    string nama, namaPemilik, alamatPemilik, noTeleponPemilik;
    int umur, berat;
    
    cout << "\n--- Data Umum Hewan ---" << endl;
    cout << "Nama Hewan: "; 
    getline(cin, nama);

    while (true) {
        cout << "Umur (tahun): ";
        if (cin >> umur && umur >= 0) {
            break;
        } else {
            cout << "Umur harus berupa angka non-negatif." << endl;
            cin.clear();
            clearInputBuffer();
        }
    }
    
    while (true) {
        cout << "Berat (kg): ";
        if (cin >> berat && berat >= 0) {
            clearInputBuffer();
            break;
        } else {
            cout << "Berat harus berupa angka non-negatif." << endl;
            cin.clear();
            clearInputBuffer();
        }
    }
    
    // --- Data Pemilik (Agregasi) ---
    cout << "\n--- Data Pemilik (Agregasi) ---" << endl;
    cout << "Nama Pemilik: "; 
    getline(cin, namaPemilik);
    cout << "Alamat Pemilik: "; 
    getline(cin, alamatPemilik);
    cout << "Nomor Telepon Pemilik: "; 
    getline(cin, noTeleponPemilik);
    
    // Pemilik tetap Agregasi, dialokasikan di heap
    Pemilik* pemilikBaru = new Pemilik(namaPemilik, alamatPemilik, noTeleponPemilik);
    
    unique_ptr<Hewan> hewanBaru = nullptr; // Menggunakan unique_ptr
    
    if (pilihanJenis == 1) {
        // Hewan Darat
        int jumlahKaki;
        string jenisKulit, jenisBulu;
        cout << "\n--- Data Spesifik Hewan Darat ---" << endl;
        while (true) {
            cout << "Jumlah Kaki: ";
            if (cin >> jumlahKaki && jumlahKaki >= 0) {
                clearInputBuffer();
                break;
            } else {
                cout << "Jumlah Kaki harus berupa angka non-negatif." << endl;
                cin.clear();
                clearInputBuffer();
            }
        }
        cout << "Jenis Kulit: "; getline(cin, jenisKulit);
        cout << "Jenis Bulu: "; getline(cin, jenisBulu);
        
        // Pembuatan objek menggunakan make_unique
        hewanBaru = make_unique<HewanDarat>(nama, umur, berat, pemilikBaru, jumlahKaki, jenisKulit, jenisBulu);
        
    } else if (pilihanJenis == 2) {
        // Hewan Air
        string jenisAir;
        double panjangTubuh, kecepatanRenang;
        cout << "\n--- Data Spesifik Hewan Air ---" << endl;
        cout << "Jenis Air (Tawar/Laut): "; getline(cin, jenisAir);
        
        // ... (Logika input panjangTubuh, kecepatanRenang) ...
        while (true) {
            cout << "Panjang Tubuh (meter): ";
            if (cin >> panjangTubuh && panjangTubuh >= 0) {
                break;
            } else {
                cout << "Panjang Tubuh harus berupa angka non-negatif." << endl;
                cin.clear();
                clearInputBuffer();
            }
        }
        while (true) {
            cout << "Kecepatan Renang (km/jam): ";
            if (cin >> kecepatanRenang && kecepatanRenang >= 0) {
                clearInputBuffer();
                break;
            } else {
                cout << "Kecepatan Renang harus berupa angka non-negatif." << endl;
                cin.clear();
                clearInputBuffer();
            }
        }
        
        hewanBaru = make_unique<HewanAir>(nama, umur, berat, pemilikBaru, jenisAir, panjangTubuh, kecepatanRenang);
        
    } else if (pilihanJenis == 3) {
        // Unggas
        double panjangSayap;
        string warnaBulu, bisaTerbangStr;
        bool bisaTerbang;
        cout << "\n--- Data Spesifik Unggas ---" << endl;
        // ... (Logika input panjangSayap, warnaBulu, bisaTerbang) ...
        while (true) {
            cout << "Panjang Sayap (meter): ";
            if (cin >> panjangSayap && panjangSayap >= 0) {
                clearInputBuffer();
                break;
            } else {
                cout << "Panjang Sayap harus berupa angka non-negatif." << endl;
                cin.clear();
                clearInputBuffer();
            }
        }
        cout << "Warna Bulu: "; getline(cin, warnaBulu);
        while (true) {
            cout << "Bisa Terbang (Ya/Tidak): "; getline(cin, bisaTerbangStr);
            if (bisaTerbangStr == "Ya" || bisaTerbangStr == "ya" || bisaTerbangStr == "y") {
                bisaTerbang = true;
                break;
            } else if (bisaTerbangStr == "Tidak" || bisaTerbangStr == "tidak" || bisaTerbangStr == "t") {
                bisaTerbang = false;
                break;
            } else {
                cout << "Pilihan tidak valid. Masukkan 'Ya' atau 'Tidak'." << endl;
            }
        }
        
        hewanBaru = make_unique<Unggas>(nama, umur, berat, pemilikBaru, panjangSayap, warnaBulu, bisaTerbang);
        
    } else if (pilihanJenis == 4) {
        // Hewan Amfibi
        int jumlahKaki;
        string jenisKulit, jenisBuluDarat;
        string jenisAir;
        double panjangTubuh, kecepatanRenang;
        string jenisAmfibi, beracunStr;
        bool beracun;
        
        cout << "\n--- Data Spesifik Hewan Amfibi ---" << endl;
        // Data Darat
        while (true) {
            cout << "Jumlah Kaki (Darat): ";
            if (cin >> jumlahKaki && jumlahKaki >= 0) {
                clearInputBuffer();
                break;
            } else {
                cout << "Jumlah Kaki harus berupa angka non-negatif." << endl;
                cin.clear();
                clearInputBuffer();
            }
        }
        cout << "Jenis Kulit (Darat): "; getline(cin, jenisKulit);
        cout << "Jenis Bulu (Darat, e.g., tidak berbulu): "; getline(cin, jenisBuluDarat);
        
        // Data Air
        cout << "Jenis Air (Amfibi): "; getline(cin, jenisAir);
        while (true) {
            cout << "Panjang Tubuh (meter, Amfibi): ";
            if (cin >> panjangTubuh && panjangTubuh >= 0) {
                break;
            } else {
                cout << "Panjang Tubuh harus berupa angka non-negatif." << endl;
                cin.clear();
                clearInputBuffer();
            }
        }
        while (true) {
            cout << "Kecepatan Renang (km/jam, Amfibi): ";
            if (cin >> kecepatanRenang && kecepatanRenang >= 0) {
                clearInputBuffer();
                break;
            } else {
                cout << "Kecepatan Renang harus berupa angka non-negatif." << endl;
                cin.clear();
                clearInputBuffer();
            }
        }
        
        // Data Amfibi Spesifik
        cout << "Jenis Amfibi: "; getline(cin, jenisAmfibi);
        while (true) {
            cout << "Beracun (Ya/Tidak): "; getline(cin, beracunStr);
            if (beracunStr == "Ya" || beracunStr == "ya" || beracunStr == "y") {
                beracun = true;
                break;
            } else if (beracunStr == "Tidak" || beracunStr == "tidak" || beracunStr == "t") {
                beracun = false;
                break;
            } else {
                cout << "Pilihan tidak valid. Masukkan 'Ya' atau 'Tidak'." << endl;
            }
        }
        
        hewanBaru = make_unique<HewanAmfibi>(nama, umur, berat, pemilikBaru, jumlahKaki, jenisKulit, jenisBuluDarat, jenisAir, panjangTubuh, kecepatanRenang, jenisAmfibi, beracun);
    }
    
    if (hewanBaru) {
        // Panggil tambahHewan dan Pindahkan kepemilikan
        kebun.tambahHewan(std::move(hewanBaru));
        cout << "\n[SUKSES] Hewan '" << nama << "' berhasil ditambahkan ke Kebun Binatang." << endl;
    } else {
        // Jika pembuatan hewan gagal, PemilikBaru yang dialokasikan harus dihapus.
        delete pemilikBaru;
        cout << "\n[GAGAL] Pembuatan hewan dibatalkan atau jenis tidak valid." << endl;
    }
}

// Fungsi utama
int main() {
    // Inisialisasi Kebun Binatang
    KebunBinatang kebun("Gemini Zoo", "Jakarta");
    
    // PANGGIL METHOD SEED DATA
    kebun.seedDataHewan(); 
    string pilihan;
    while (true) {
        cout << "\n==============================================" << endl;
        cout << "Sistem Informasi " << kebun.getNama() << " - " << kebun.getLokasi() << endl;
        cout << "==============================================" << endl;
        cout << "1. Tampilkan Semua Data Hewan (Tabel Dinamis)" << endl;
        cout << "2. Input Data Hewan Baru" << endl;
        cout << "3. Keluar Program" << endl;
        cout << "----------------------------------------------" << endl;
        
        cout << "Masukkan pilihan (1-3): ";
        cin >> pilihan;
        clearInputBuffer(); 

        if (pilihan == "1") {
            kebun.tampilkanDataHewan();
        } else if (pilihan == "2") {
            inputHewan(kebun);
        } else if (pilihan == "3") {
            cout << "\nTerima kasih telah menggunakan sistem ini. Sampai jumpa!" << endl;
            break;
        } else {
            cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}