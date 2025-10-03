// File: Unggas.cpp
#include "Unggas.h"

// Constructor
Unggas::Unggas(string n, int u, int b, Pemilik* p, double ps, string wb, bool bt) 
    : Hewan(n, u, b, p), panjangSayap(ps), warnaBulu(wb), bisaTerbang(bt) {}

// Implementasi Polymorphism
string Unggas::getSpesificInfo() const {
    stringstream ss;
    string statusTerbang = bisaTerbang ? "Ya" : "Tidak";
    ss << fixed << setprecision(2);
    ss << "Jenis: Unggas, P. Sayap: " << panjangSayap << " m, Warna Bulu: " << warnaBulu << ", Terbang: " << statusTerbang;
    return ss.str();
}
