public class Unggas extends Hewan {
    private double panjangSayap;
    private String warnaBulu;
    private boolean bisaTerbang;

    // Konstruktor
    public Unggas(String nama, int umur, int berat, Pemilik pemilik, double panjangSayap, String warnaBulu, boolean bisaTerbang) {
        super(nama, umur, berat, pemilik); // Pewarisan
        this.panjangSayap = panjangSayap;
        this.warnaBulu = warnaBulu;
        this.bisaTerbang = bisaTerbang;
    }

    // Konstruktor default
    public Unggas() {
        this("", 0, 0, null, 0.0, "", false);
    }

    // Getter konvensional
    public double getPanjangSayap() {
        return panjangSayap;
    }

    public String getColorBulu() {
        return warnaBulu;
    }

    public boolean isBisaTerbang() {
        return bisaTerbang;
    }

    // Setter konvensional
    public void setPanjangSayap(double panjangSayap) {
        this.panjangSayap = panjangSayap;
    }

    public void setColorBulu(String warnaBulu) {
        this.warnaBulu = warnaBulu;
    }

    public void setBisaTerbang(boolean bisaTerbang) {
        this.bisaTerbang = bisaTerbang;
    }

    // Implementasi Polymorphism.
    @Override
    public String getSpesificInfo() {
        String statusTerbang = bisaTerbang ? "Ya" : "Tidak";
        return "Jenis: Unggas | Sayap: " + panjangSayap + " m | Bulu: " + warnaBulu + " | Terbang: " + statusTerbang;
    }
}