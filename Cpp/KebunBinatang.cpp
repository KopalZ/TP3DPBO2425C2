#include "KebunBinatang.h"
#include "Pemilik.h"
#include "HewanDarat.h"
#include "HewanAir.h"
#include "Unggas.h"
#include "HewanAmfibi.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <memory> 

// Constructor
KebunBinatang::KebunBinatang(string n, string l) : nama(n), lokasi(l) {}

// Metode untuk menambah hewan (Menerima unique_ptr untuk transfer kepemilikan)
void KebunBinatang::tambahHewan(unique_ptr<Hewan> hewan) {
    listHewan.push_back(std::move(hewan)); 
}

// Metode untuk membuat data awal
void KebunBinatang::seedDataHewan() {
    // Objek Pemilik dibuat di stack, alamatnya (Agregasi) yang dilewatkan ke Hewan
    Pemilik* p1 = new Pemilik("Budi Santoso", "Jl. Mawar No. 1", "08123456789");
    Pemilik* p2 = new Pemilik("Siti Aisyah", "Komplek Anggrek Blok B", "08567890123");
    Pemilik* p3 = new Pemilik("Joko Widodo", "Jl. Merdeka Raya", "08765432100");

    // 1. Hewan Darat
    tambahHewan(make_unique<HewanDarat>("Gajah Sumatera", 15, 4000, p1, 4, "Tebal, Abu-abu", "Pendek"));
    
    // 2. Hewan Air
    tambahHewan(make_unique<HewanAir>("Hiu Putih", 8, 1100, p2, "Laut", 5.5, 56.0));
    
    // 3. Unggas
    tambahHewan(make_unique<Unggas>("Elang Jawa", 6, 4, p1, 1.8, "Cokelat Tua", true));
    
    // 4. Amfibi
    tambahHewan(make_unique<HewanAmfibi>("Kodok Beracun", 2, 0, p3, 4, "Lembab", "Tidak ada", "Dua Alam", 0.15, 5.0, "Kataksidae", true));
}


// Metode untuk menampilkan data dalam tabel dinamis
void KebunBinatang::tampilkanDataHewan() const {
    if (listHewan.empty()) {
        cout << "\n==============================================" << endl;
        cout << "|| TIDAK ADA DATA HEWAN DALAM KEKEBUN BINATANG ||" << endl;
        cout << "==============================================" << endl;
        return;
    }

    // Header yang akan digunakan
    vector<string> header = {"No.", "Nama Hewan", "Umur (th)", "Berat (kg)", "Pemilik", "Info Spesifik Hewan"};
    vector<int> colWidths(header.size());

    // 1. Inisialisasi Lebar Minimum (berdasarkan Header)
    for (size_t i = 0; i < header.size(); ++i) {
        colWidths[i] = header[i].length();
    }

    // Vektor untuk menyimpan data baris yang sudah diformat
    vector<vector<string>> dataRowsFormatted;

    // 2. Kumpulkan Data dan Hitung Lebar Maksimum
    for (size_t i = 0; i < listHewan.size(); ++i) {
        const Hewan* h = listHewan[i].get(); // Dapatkan raw pointer
        
        string umurStr = to_string(h->getUmur());
        string beratStr = to_string(h->getBerat());
        string pemilikInfo = (h->getPemilik() != nullptr) ? h->getPemilik()->getInfoSingkat() : "-";
        string spesifikInfo = h->getSpesificInfo();
        
        vector<string> row = {
            to_string(i + 1),
            h->getNama(),
            umurStr,
            beratStr,
            pemilikInfo,
            spesifikInfo
        };
        dataRowsFormatted.push_back(row);

        // Update lebar kolom maksimum
        for (size_t j = 0; j < header.size(); ++j) {
            colWidths[j] = max(colWidths[j], (int)row[j].length());
        }
    }
    
    // 3. Tambahkan Padding (2 spasi per kolom: 1 kiri + 1 kanan)
    for (int& w : colWidths) {
        w += 2;
    }

    // 4. Hitung Lebar Total dan Buat Separator Dinamis
    int totalWidth = 0;
    for (int w : colWidths) {
        totalWidth += w;
    }
    totalWidth += 1; // Untuk tanda '+' terakhir

    string separatorLine = "+";
    for (int w : colWidths) {
        separatorLine += string(w, '-') + "+";
    }

    cout << "\n" << string(totalWidth, '=') << endl;
    cout << setw(totalWidth / 2 + (nama.length() / 2 + lokasi.length() / 2) + 2) 
         << "DATA HEWAN DI " << nama << " - " << lokasi << endl;
    cout << string(totalWidth, '=') << endl;

    // 5. Cetak Header
    cout << separatorLine << endl;
    cout << "|";
    for (size_t i = 0; i < header.size(); ++i) {
        // Cetak dengan padding dan header center (untuk header, kita pakai left)
        cout << " " << left << setw(colWidths[i] - 2) << header[i] << " |";
    }
    cout << endl << separatorLine << endl;

    // 6. Cetak Data
    for (const auto& row : dataRowsFormatted) {
        cout << "|";
        for (size_t j = 0; j < row.size(); ++j) {
            // Cetak data dengan padding 
            cout << " " << left << setw(colWidths[j] - 2) << row[j] << " |";
        }
        cout << endl;
    }

    cout << separatorLine << endl;
    cout << "Total Hewan: " << listHewan.size() << endl;
    cout << string(totalWidth, '=') << endl;
}