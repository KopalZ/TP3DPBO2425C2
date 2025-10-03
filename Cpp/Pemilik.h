#ifndef PEMILIK_H
#define PEMILIK_H

#include <string>
using namespace std; 

class Pemilik {
private:
    string nama;
    string alamat;
    string noTelepon;

public:
    // Constructor Kosong (Default Constructor)
    Pemilik() : nama(""), alamat(""), noTelepon("") {}

    // Constructor dengan Parameter
    Pemilik(string n, string a, string t);
    
    // --- Setter ---
    void setNama(string n) {
        this->nama = n; 
    }
    void setAlamat(string a) {
        this->alamat = a; 
    }
    void setNoTelepon(string t) {
        this->noTelepon = t;
    }

    // --- Getter ---
    string getNama() const { return nama; }
    string getAlamat() const { return alamat; }
    string getNoTelepon() const { return noTelepon; }

    // Metode Tambahan
    string getInfoSingkat() const;
};

#endif // PEMILIK_H
