import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class KebunBinatang {
    private String nama;
    private String lokasi;
    private List<Hewan> listHewan; 

    public KebunBinatang(String nama, String lokasi) {
        this.nama = nama;
        this.lokasi = lokasi;
        this.listHewan = new ArrayList<>();
    }
    
    public String getNama() { return nama; }
    public String getLokasi() { return lokasi; }
    public List<Hewan> getListHewan() { return listHewan; }

    public void setNama(String nama) { this.nama = nama; }
    public void setLokasi(String lokasi) { this.lokasi = lokasi; }

    public void tambahHewan(Hewan hewan) {
        listHewan.add(hewan);
    }

    //Menampilkan semua data hewan dalam format tabel yang lebar kolomnya dinamis.

    public void tampilkanDataHewan() {
        if (listHewan.isEmpty()) {
            System.out.println("\n=============================================");
            System.out.println("Belum ada data hewan yang tersimpan.");
            System.out.println("=============================================");
            return;
        }

        // 1. Definisikan Header
        String[] headers = {"No", "Nama", "Umur (th)", "Berat (kg)", "Pemilik", "Spesifikasi"};
        int numCols = headers.length;
        List<String[]> dataRows = new ArrayList<>();
        
        // Inisialisasi lebar kolom (minimal sebesar panjang header)
        int[] colWidths = new int[numCols];
        for (int i = 0; i < numCols; i++) {
            colWidths[i] = headers[i].length();
        }

        // 2. Kumpulkan Data Baris dan Hitung Lebar Maksimum
        for (int i = 0; i < listHewan.size(); i++) {
            Hewan hewan = listHewan.get(i);
            String namaPemilik = (hewan.getPemilik() != null) ? hewan.getPemilik().getInfoSingkat() : "-";

            String[] row = new String[] {
                String.valueOf(i + 1),
                hewan.getNama(),
                String.valueOf(hewan.getUmur()),
                String.valueOf(hewan.getBerat()),
                namaPemilik,
                hewan.getSpesificInfo() 
            };
            dataRows.add(row);
            
            // Update lebar kolom maksimum
            for (int j = 0; j < numCols; j++) {
                if (row[j].length() > colWidths[j]) {
                    colWidths[j] = row[j].length();
                }
            }
        }
        
        // Tambahkan padding sebesar 2 (1 spasi di kiri, 1 spasi di kanan)
        for (int i = 0; i < numCols; i++) {
            colWidths[i] += 2;
        }

        // 3. Fungsi untuk mencetak baris pembatas
        String separatorLine = "+";
        for (int width : colWidths) {
            separatorLine += String.join("", Collections.nCopies(width, "-")) + "+";
        }

        // 4. Cetak Judul Tabel
        System.out.println("\n======== DATA HEWAN DI " + nama.toUpperCase() + " (" + lokasi.toUpperCase() + ") ========");
        
        // 5. Cetak Header
        System.out.println(separatorLine);
        String headerFormat = "";
        String[] headerCells = new String[numCols];
        for (int i = 0; i < numCols; i++) {
            // Lebar format = lebar kolom dikurangi 2 (untuk spasi padding di cetak)
            headerFormat += "| %-" + (colWidths[i] - 2) + "s "; 
            headerCells[i] = headers[i];
        }
        headerFormat += "|"; // Tutup format
        
        // Cetak Header (menggunakan System.out.printf)
        System.out.printf(headerFormat + "%n", (Object[]) headerCells);
        System.out.println(separatorLine);

        // 6. Cetak Data
        for (String[] row : dataRows) {
            String rowFormat = "";
            String[] rowCells = new String[numCols];
            
            for (int i = 0; i < numCols; i++) {
                // Gunakan format yang sama seperti header
                rowFormat += "| %-" + (colWidths[i] - 2) + "s "; 
                rowCells[i] = row[i];
            }
            rowFormat += "|"; // Tutup format
            
            // Cetak Baris Data (menggunakan System.out.printf)
            System.out.printf(rowFormat + "%n", (Object[]) rowCells);
        }
        
        System.out.println(separatorLine);
    }
    
}