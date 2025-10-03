#ifndef KEBUNBINATANG_H
#define KEBUNBINATANG_H

#include "Hewan.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class KebunBinatang {
private:
    string nama;
    string lokasi;
    vector<unique_ptr<Hewan>> listHewan; 

public:
    // Constructor Kosong
    KebunBinatang() : nama(""), lokasi("") {}
    
    // Constructor dengan Parameter
    KebunBinatang(string n, string l);

    // Destructor (default sudah cukup karena unique_ptr mengurus penghapusan)
    ~KebunBinatang() = default; 

    // --- Setter ---
    void setNama(string n) { this->nama = n; }
    void setLokasi(string l) { this->lokasi = l; }

    // --- Getter ---
    string getNama() const { return nama; }
    string getLokasi() const { return lokasi; }
    
    // NOTE: Getter listHewan mengembalikan referensi ke vector of unique_ptr
    const vector<unique_ptr<Hewan>>& getListHewan() const { return listHewan; }

    // Metode untuk menambah hewan (menerima unique_ptr untuk transfer kepemilikan)
    void tambahHewan(unique_ptr<Hewan> hewan);
    
    // Metode untuk membuat data awal (Mencerminkan Komposisi)
    void seedDataHewan(); 
    
    // Metode untuk menampilkan data dalam tabel dinamis
    void tampilkanDataHewan() const;
};

#endif // KEBUNBINATANG_H