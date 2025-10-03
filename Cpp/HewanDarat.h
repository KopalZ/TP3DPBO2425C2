#ifndef HEWANDARAT_H
#define HEWANDARAT_H

#include "Hewan.h"
#include <sstream>
using namespace std;

class HewanDarat : public virtual Hewan { 
private:
    int jumlahKaki;
    string jenisKulit;
    string jenisBulu;

public:
    // Default Constructor
    HewanDarat() : Hewan(), jumlahKaki(0), jenisKulit(""), jenisBulu("") {}
    
    // Constructor dengan Parameter
    HewanDarat(string n, int u, int b, Pemilik* p, int jk, string jklt, string jbl);

    // --- Setter ---
    void setJumlahKaki(int jk) { if (jk >= 0) this->jumlahKaki = jk; }
    void setJenisKulit(string jklt) { this->jenisKulit = jklt; }
    void setJenisBulu(string jbl) { this->jenisBulu = jbl; }

    // --- Getter ---
    int getJumlahKaki() const { return jumlahKaki; }
    string getJenisKulit() const { return jenisKulit; }
    string getJenisBulu() const { return jenisBulu; }

    // Implementasi Polymorphism
    string getSpesificInfo() const override;
};

#endif // HEWANDARAT_H
