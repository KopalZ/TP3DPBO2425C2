public class HewanDarat extends Hewan {
    private int jumlahKaki;
    private String jenisKulit;
    private String jenisBulu;

    // Konstruktor
    public HewanDarat(String nama, int umur, int berat, Pemilik pemilik, int jumlahKaki, String jenisKulit, String jenisBulu) {
        super(nama, umur, berat, pemilik); // Pewarisan (memanggil konstruktor kelas induk)
        this.jumlahKaki = jumlahKaki;
        this.jenisKulit = jenisKulit;
        this.jenisBulu = jenisBulu;
    }

    // Konstruktor default
    public HewanDarat() {
        this("", 0, 0, null, 0, "", "");
    }

    // Getter konvensional
    public int getJumlahKaki() {
        return jumlahKaki;
    }

    public String getJenisKulit() {
        return jenisKulit;
    }

    public String getJenisBulu() {
        return jenisBulu;
    }

    // Setter konvensional
    public void setJumlahKaki(int jumlahKaki) {
        this.jumlahKaki = jumlahKaki;
    }

    public void setJenisKulit(String jenisKulit) {
        this.jenisKulit = jenisKulit;
    }

    public void setJenisBulu(String jenisBulu) {
        this.jenisBulu = jenisBulu;
    }


     //Implementasi Polymorphism.
    @Override
    public String getSpesificInfo() {
        return "Jenis: Darat | Kaki: " + getJumlahKaki() + " | Kulit: " + getJenisKulit() + " | Bulu: " + getJenisBulu();
    }
}