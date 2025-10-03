public class Pemilik {
    // Atribut private
    private String nama;
    private String alamat;
    private String noTelepon;

    // Konstruktor
    public Pemilik(String nama, String alamat, String noTelepon) {
        this.nama = nama;
        this.alamat = alamat;
        this.noTelepon = noTelepon;
    }

    // Konstruktor default
    public Pemilik() {
        this("", "", "");
    }

    // Getter konvensional
    public String getNama() {
        return nama;
    }

    public String getAlamat() {
        return alamat;
    }

    public String getNoTelepon() {
        return noTelepon;
    }

    // Setter konvensional
    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setAlamat(String alamat) {
        this.alamat = alamat;
    }

    public void setNoTelepon(String noTelepon) {
        this.noTelepon = noTelepon;
    }

    //Mengembalikan informasi pemilik untuk ditampilkan di tabel.

    public String getInfoSingkat() {
        return nama + " (" + noTelepon + ")";
    }
}