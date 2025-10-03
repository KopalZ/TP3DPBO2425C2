#ifndef HEWANAIR_H
#define HEWANAIR_H

#include "Hewan.h"
#include <sstream>
#include <iomanip>
using namespace std;

class HewanAir : public virtual Hewan {
private:
    string jenisAir;
    double panjangTubuh;
    double kecepatanRenang;

public:
    // Default Constructor
    HewanAir() : Hewan(), jenisAir(""), panjangTubuh(0.0), kecepatanRenang(0.0) {}
    
    // Constructor dengan Parameter
    HewanAir(string n, int u, int b, Pemilik* p, string ja, double pt, double kr);

    // --- Setter ---
    void setJenisAir(string ja) { 
        this->jenisAir = ja; 
    }
    void setPanjangTubuh(double pt) { 
        if (pt >= 0) this->panjangTubuh = pt; 
    }
    void setKecepatanRenang(double kr) { 
        if (kr >= 0) this->kecepatanRenang = kr; 
    }

    // --- Getter ---
    string getJenisAir() const { return jenisAir; }
    double getPanjangTubuh() const { return panjangTubuh; }
    double getKecepatanRenang() const { return kecepatanRenang; }
    
    // Implementasi Polymorphism
    string getSpesificInfo() const override;
};

#endif // HEWANAIR_H
