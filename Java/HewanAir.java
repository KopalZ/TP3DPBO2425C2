public class HewanAir extends Hewan {
    private String jenisAir;
    private double panjangTubuh;
    private double kecepatanRenang;

    // Konstruktor
    public HewanAir(String nama, int umur, int berat, Pemilik pemilik,
                    String jenisAir, double panjangTubuh, double kecepatanRenang) {
        super(nama, umur, berat, pemilik); // Pewarisan
        this.jenisAir = jenisAir;
        this.panjangTubuh = panjangTubuh;
        this.kecepatanRenang = kecepatanRenang;
    }

    // Konstruktor default
    public HewanAir() {
        this("", 0, 0, null, "", 0.0, 0.0);
    }

    // Getter konvensional
    public String getJenisAir() {
        return jenisAir;
    }

    public double getPanjangTubuh() {
        return panjangTubuh;
    }

    public double getKecepatanRenang() {
        return kecepatanRenang;
    }

    // Setter konvensional
    public void setJenisAir(String jenisAir) {
        this.jenisAir = jenisAir;
    }

    public void setPanjangTubuh(double panjangTubuh) {
        this.panjangTubuh = panjangTubuh;
    }

    public void setKecepatanRenang(double kecepatanRenang) {
        this.kecepatanRenang = kecepatanRenang;
    }

    @Override
    public String getSpesificInfo() {
        return "Jenis: Air | Habitat: " + getJenisAir() + " | Pjg Tubuh: " + panjangTubuh + " m | Kecepatan: " + kecepatanRenang + " m/s";
    }
}