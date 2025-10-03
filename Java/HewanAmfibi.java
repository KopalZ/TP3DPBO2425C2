public class HewanAmfibi extends Hewan {
    // Atribut spesifik Amfibi
    private String jenisAmfibi;
    private boolean beracun;
    
    // Atribut dari HewanDarat (diulang)
    private int jumlahKaki;
    private String jenisKulit;
    private String jenisBuluDarat;

    // Atribut dari HewanAir (diulang)
    private String jenisAir;
    private double panjangTubuh;
    private double kecepatanRenang;

    // Konstruktor
    public HewanAmfibi(String nama, int umur, int berat, Pemilik pemilik,
                       int jumlahKaki, String jenisKulit, String jenisBuluDarat,
                       String jenisAir, double panjangTubuh, double kecepatanRenang,
                       String jenisAmfibi, boolean beracun) {
        super(nama, umur, berat, pemilik); // Pewarisan
        
        // Inisialisasi atribut Darat
        this.jumlahKaki = jumlahKaki;
        this.jenisKulit = jenisKulit;
        this.jenisBuluDarat = jenisBuluDarat;
        
        // Inisialisasi atribut Air
        this.jenisAir = jenisAir;
        this.panjangTubuh = panjangTubuh;
        this.kecepatanRenang = kecepatanRenang;
        
        // Inisialisasi atribut Amfibi
        this.jenisAmfibi = jenisAmfibi;
        this.beracun = beracun;
    }
    
    // Konstruktor default
    public HewanAmfibi() {
        this("", 0, 0, null, 0, "", "", "", 0.0, 0.0, "", false);
    }
    
    // Getter & Setter Amfibi
    public String getJenisAmfibi() {
        return jenisAmfibi;
    }
    
    public boolean isBeracun() {
        return beracun;
    }
    
    public void setJenisAmfibi(String jenisAmfibi) {
        this.jenisAmfibi = jenisAmfibi;
    }
    
    public void setBeracun(boolean beracun) {
        this.beracun = beracun;
    }

    public int getJumlahKaki() {
        return jumlahKaki;
    }

    public String getJenisAir() {
        return jenisAir;
    }
    
    //Implementasi Polymorphism untuk Amfibi (menggabungkan info Darat dan Air).
    @Override
    public String getSpesificInfo() {
        String statusRacun = isBeracun() ? "Ya" : "Tidak";
        
        // Mensimulasikan info Darat (tanpa inheritance)
        String infoDarat = "Kaki: " + jumlahKaki + " | Kulit: " + jenisKulit + " | Bulu: " + jenisBuluDarat;
        
        // Mensimulasikan info Air (tanpa inheritance)
        String infoAir = "Habitat: " + jenisAir + " | Pjg Tubuh: " + panjangTubuh + " m | Kecepatan: " + kecepatanRenang + " m/s";

        return "Jenis: Amfibi (" + jenisAmfibi + ") | Beracun: " + statusRacun + " | DARAT: " + infoDarat + " | AIR: " + infoAir;
    }
}