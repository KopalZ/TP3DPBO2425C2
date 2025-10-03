#include "HewanAir.h"

// Constructor
HewanAir::HewanAir(string n, int u, int b, Pemilik* p, string ja, double pt, double kr) 
    : Hewan(n, u, b, p), jenisAir(ja), panjangTubuh(pt), kecepatanRenang(kr) {}
        
// Implementasi Polymorphism
string HewanAir::getSpesificInfo() const {
    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Jenis: Air, Air: " << jenisAir << ", P. Tubuh: " << panjangTubuh << " m, Kecepatan: " << kecepatanRenang << " km/jam";
    return ss.str();
}
