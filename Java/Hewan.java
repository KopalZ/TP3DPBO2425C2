public abstract class Hewan {
    // Atribut private
    private String nama;
    private int umur;
    private int berat;
    // Agregasi: Objek Pemilik
    private Pemilik pemilik;

    // Konstruktor
    public Hewan(String nama, int umur, int berat, Pemilik pemilik) {
        this.nama = nama;
        this.umur = umur;
        this.berat = berat;
        this.pemilik = pemilik;
    }

    // Konstruktor default
    public Hewan() {
        this("", 0, 0, null);
    }

    // Getter konvensional
    public String getNama() {
        return nama;
    }

    public int getUmur() {
        return umur;
    }

    public int getBerat() {
        return berat;
    }

    public Pemilik getPemilik() {
        return pemilik;
    }

    // Setter konvensional
    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setUmur(int umur) {
        if (umur >= 0) {
            this.umur = umur;
        }
    }

    public void setBerat(int berat) {
        if (berat >= 0) {
            this.berat = berat;
        }
    }

    public void setPemilik(Pemilik pemilik) {
        this.pemilik = pemilik;
    }

    public abstract String getSpesificInfo();

    public String getInfoDasar() {
        return nama + " | Umur: " + umur + " th | Berat: " + berat + " kg";
    }
}