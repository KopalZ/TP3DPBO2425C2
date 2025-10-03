// File: Unggas.h
#ifndef UNGGAS_H
#define UNGGAS_H

#include "Hewan.h"
#include <sstream>
#include <iomanip>
using namespace std;

class Unggas : public Hewan {
private:
    double panjangSayap;
    string warnaBulu;
    bool bisaTerbang;

public:
    // Default Constructor
    Unggas() : Hewan(), panjangSayap(0.0), warnaBulu(""), bisaTerbang(false) {}
    
    // Constructor dengan Parameter
    Unggas(string n, int u, int b, Pemilik* p, double ps, string wb, bool bt); // Menerima pointer

    // --- Setter ---
    void setPanjangSayap(double ps) { if (ps >= 0) this->panjangSayap = ps; }
    void setWarnaBulu(string wb) { this->warnaBulu = wb; }
    void setBisaTerbang(bool bt) { this->bisaTerbang = bt; }

    // --- Getter ---
    double getPanjangSayap() const { return panjangSayap; }
    string getWarnaBulu() const { return warnaBulu; }
    bool getBisaTerbang() const { return bisaTerbang; }
    
    // Implementasi Polymorphism
    string getSpesificInfo() const override;
};

#endif // UNGGAS_H
