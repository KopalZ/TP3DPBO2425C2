#include "HewanAmfibi.h"

HewanAmfibi::HewanAmfibi(string n, int u, int b, Pemilik* p, int jk, string jklt, string jbl, string ja, double pt, double kr, string jamf, bool r) : Hewan(n, u, b, p), // PENTING: Memanggil constructor Hewan (Virtual Base Class)
      HewanDarat(n, u, b, p, jk, jklt, jbl), 
      HewanAir(n, u, b, p, ja, pt, kr), 
      jenisAmfibi(jamf), beracun(r) 
{}
        
// Implementasi Polymorphism
string HewanAmfibi::getSpesificInfo() const {
    stringstream ss;
    string statusRacun = beracun ? "Ya" : "Tidak";
    
    // Ambil info dari Darat dan Air
    string infoDarat = HewanDarat::getSpesificInfo();
    string infoAir = HewanAir::getSpesificInfo();
    
    // Membersihkan string info
    size_t posDarat = infoDarat.find("Darat, ");
    if (posDarat != string::npos) infoDarat.erase(0, posDarat + 7); 
    
    size_t posAir = infoAir.find("Air, ");
    if (posAir != string::npos) infoAir.erase(0, posAir + 5); 

    ss << "Jenis: Amfibi (" << jenisAmfibi << "), Beracun: " << statusRacun << " | Darat: " << infoDarat << " | Air: " << infoAir;
    return ss.str();
}
