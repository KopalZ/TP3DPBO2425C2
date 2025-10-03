#include "Pemilik.h"

// Constructor
Pemilik::Pemilik(string n, string a, string t) : nama(n), alamat(a), noTelepon(t) {}

string Pemilik::getInfoSingkat() const {
    return "Nama: " + nama + ", Telp: " + noTelepon;
}
