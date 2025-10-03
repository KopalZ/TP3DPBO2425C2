#ifndef HEWANAMFIBI_H
#define HEWANAMFIBI_H

#include "HewanDarat.h"
#include "HewanAir.h"
#include <sstream>
using namespace std;

// Multiple Inheritance
class HewanAmfibi : public HewanDarat, public HewanAir {
private:
    string jenisAmfibi;
    bool beracun;

public:
    // Default Constructor
    HewanAmfibi() : HewanDarat(), HewanAir(), jenisAmfibi(""), beracun(false) {}
    
    // Constructor dengan Parameter
    HewanAmfibi(string n, int u, int b, Pemilik* p,  int jk, string jklt, string jbl, string ja, double pt, double kr, string jamf, bool r);
        
    // --- Setter ---
    void setJenisAmfibi(string jamf) { this->jenisAmfibi = jamf; }
    void setBeracun(bool r) { this->beracun = r; }

    // --- Getter ---
    string getJenisAmfibi() const { return jenisAmfibi; }
    bool getBeracun() const { return beracun; }
    
    // Implementasi Polymorphism
    string getSpesificInfo() const override;
};

#endif // HEWANAMFIBI_H
