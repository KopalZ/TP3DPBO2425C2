#ifndef HEWAN_H
#define HEWAN_H

#include <string>
#include "Pemilik.h"
using namespace std;

class Hewan {
private:
    string nama;
    int umur;
    int berat;
    Pemilik* pemilik;

public:
    // Constructor Kosong (Default Constructor)
    Hewan() : nama(""), umur(0), berat(0), pemilik(nullptr) {}

    // Constructor dengan Parameter
    Hewan(string n, int u, int b, Pemilik* p); // Menerima pointer
        
    // Virtual Destructor
    virtual ~Hewan() {}

    // --- Setter (IMPLEMENTASI INLINE) ---
    void setNama(string n) { this->nama = n; }
    void setUmur(int u) { if (u >= 0) this->umur = u; }
    void setBerat(int b) { if (b >= 0) this->berat = b; }
    void setPemilik(Pemilik* p) { this->pemilik = p; } // Menerima pointer

    // --- Getter ---
    string getNama() const { return nama; }
    int getUmur() const { return umur; }
    int getBerat() const { return berat; }
    Pemilik* getPemilik() const { return pemilik; } // Mengembalikan pointer
    
    // Metode virtual murni (Polymorphism)
    virtual string getSpesificInfo() const = 0;
};

#endif // HEWAN_H
