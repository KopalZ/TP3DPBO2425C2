#include "HewanDarat.h"

// Constructor
HewanDarat::HewanDarat(string n, int u, int b, Pemilik* p, int jk, string jklt, string jbl) 
    : Hewan(n, u, b, p), jumlahKaki(jk), jenisKulit(jklt), jenisBulu(jbl) {}

// Implementasi Polymorphism
string HewanDarat::getSpesificInfo() const {
    stringstream ss;
    ss << "Jenis: Darat, Kaki: " << jumlahKaki << ", Kulit: " << jenisKulit << ", Bulu: " << jenisBulu;
    return ss.str();
}
