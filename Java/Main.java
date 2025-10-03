import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void tampilkanMenu() {
        System.out.println("\n=============================================");
        System.out.println("         SISTEM MANAJEMEN KEBUN BINATANG     ");
        System.out.println("=============================================");
        System.out.println("1. Tampilkan Semua Data Hewan");
        System.out.println("2. Input Data Hewan Baru");
        System.out.println("3. Keluar");
        System.out.println("---------------------------------------------");
    }

    //Meminta input data hewan baru dari user.
    public static void inputHewanInteraktif(KebunBinatang kebun) {
        System.out.println("\n--- Input Data Hewan Baru ---");

        // Pilih Tipe Hewan
        System.out.println("Pilih Tipe Hewan:");
        System.out.println("1. Hewan Darat (Mamalia/Reptil)");
        System.out.println("2. Hewan Air (Ikan/Paus)");
        System.out.println("3. Unggas (Burung/Ayam)");
        System.out.println("4. Amfibi (Katak/Salamander)");

        System.out.print("Pilihan (1-4): ");
        String tipe = scanner.nextLine();

        // Input Data Dasar
        System.out.print("Nama Hewan: ");
        String nama = scanner.nextLine();
        System.out.print("Umur (tahun): ");
        int umur = Integer.parseInt(scanner.nextLine());
        System.out.print("Berat (kg): ");
        int berat = Integer.parseInt(scanner.nextLine());

        // Input Data Pemilik (Agregasi)
        System.out.println("\n--- Input Data Pemilik ---");
        System.out.print("Nama Pemilik: ");
        String namaP = scanner.nextLine();
        System.out.print("Alamat Pemilik: ");
        String alamatP = scanner.nextLine();
        System.out.print("No. Telepon Pemilik: ");
        String telpP = scanner.nextLine();
        Pemilik pemilikBaru = new Pemilik(namaP, alamatP, telpP);

        Hewan hewanBaru = null;

        try {
            if (tipe.equals("1")) {
                System.out.print("Jumlah Kaki: ");
                int jk = Integer.parseInt(scanner.nextLine());
                System.out.print("Jenis Kulit: ");
                String jklt = scanner.nextLine();
                System.out.print("Jenis Bulu: ");
                String jbl = scanner.nextLine();
                hewanBaru = new HewanDarat(nama, umur, berat, pemilikBaru, jk, jklt, jbl);

            } else if (tipe.equals("2")) {
                System.out.print("Jenis Air (Tawar/Asin): ");
                String ja = scanner.nextLine();
                System.out.print("Panjang Tubuh (m): ");
                double pt = Double.parseDouble(scanner.nextLine());
                System.out.print("Kecepatan Renang (m/s): ");
                double kr = Double.parseDouble(scanner.nextLine());
                hewanBaru = new HewanAir(nama, umur, berat, pemilikBaru, ja, pt, kr);

            } else if (tipe.equals("3")) {
                System.out.print("Panjang Sayap (m): ");
                double ps = Double.parseDouble(scanner.nextLine());
                System.out.print("Warna Bulu: ");
                String wb = scanner.nextLine();
                System.out.print("Bisa Terbang? (y/n): ");
                boolean bt = scanner.nextLine().equalsIgnoreCase("y");
                hewanBaru = new Unggas(nama, umur, berat, pemilikBaru, ps, wb, bt);

            } else if (tipe.equals("4")) {
                // Data Darat
                System.out.print("Jumlah Kaki Darat: ");
                int jk = Integer.parseInt(scanner.nextLine());
                System.out.print("Jenis Kulit Darat: ");
                String jklt = scanner.nextLine();
                System.out.print("Jenis Bulu Darat: ");
                String jblDarat = scanner.nextLine();
                // Data Air
                System.out.print("Jenis Air (Tawar/Asin): ");
                String ja = scanner.nextLine();
                System.out.print("Panjang Tubuh (m): ");
                double pt = Double.parseDouble(scanner.nextLine());
                System.out.print("Kecepatan Renang (m/s): ");
                double kr = Double.parseDouble(scanner.nextLine());
                // Data Amfibi
                System.out.print("Jenis Amfibi (misal: Katak, Salamander): ");
                String jamf = scanner.nextLine();
                System.out.print("Apakah Beracun? (y/n): ");
                boolean beracun = scanner.nextLine().equalsIgnoreCase("y");

                hewanBaru = new HewanAmfibi(nama, umur, berat, pemilikBaru, jk, jklt, jblDarat, ja, pt, kr, jamf, beracun);

            } else {
                System.out.println("Pilihan tidak valid.");
                return;
            }

            if (hewanBaru != null) {
                kebun.tambahHewan(hewanBaru);
                System.out.println("\nSukses! " + nama + " (" + hewanBaru.getClass().getSimpleName() + ") berhasil ditambahkan ke Kebun Binatang.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Input angka tidak valid. Mohon ulangi.");
        }
    }

    public static void runMenu(KebunBinatang kebun) {
        String pilihan;
        while (true) {
            tampilkanMenu();
            System.out.print("Masukkan pilihan (1-3): ");
            pilihan = scanner.nextLine();

            if (pilihan.equals("1")) {
                kebun.tampilkanDataHewan();
            } else if (pilihan.equals("2")) {
                inputHewanInteraktif(kebun);
            } else if (pilihan.equals("3")) {
                System.out.println("Terima kasih telah menggunakan sistem. Sampai jumpa!");
                break;
            } else {
                System.out.println("Pilihan tidak valid. Silakan masukkan angka 1, 2, atau 3.");
            }
        }
    }

    public static void main(String[] args) {
        // Inisialisasi Pemilik (Agregasi)
        Pemilik pemilik1 = new Pemilik("Budi Santoso", "Jl. Mawar No. 1", "0812345678");
        Pemilik pemilik2 = new Pemilik("Siti Aisyah", "Jl. Kenanga No. 5", "0898765432");
        Pemilik pemilik3 = new Pemilik("Ahmad Wijaya", "Jl. Sudirman 10", "0877889900");
        
        // Inisialisasi Kebun Binatang
        KebunBinatang kebun = new KebunBinatang("Taman Satwa Indah", "Kota Bandung");
        
        // Menambahkan Hewan Darat
        kebun.tambahHewan(new HewanDarat("Gajah Sumatera", 15, 4500, pemilik1, 4, "Tebal", "Pendek"));
        // Menambahkan Unggas
        kebun.tambahHewan(new Unggas("Elang Jawa", 7, 5, pemilik2, 2.0, "Cokelat Emas", true));
        // Menambahkan Hewan Air
        kebun.tambahHewan(new HewanAir("Lumba-Lumba", 10, 200, pemilik3, "Asin", 2.5, 30.0));
        // Menambahkan Hewan Amfibi (dengan semua parameter)
        kebun.tambahHewan(new HewanAmfibi(
            "Katak Pohon", 1, 0, pemilik1, 
            4, "Lembab", "Tidak ada", // Darat data
            "Tawar", 0.08, 2.0,         // Air data
            "Katak", false              // Amfibi data
        ));

        // --- JALANKAN MENU UTAMA ---
        runMenu(kebun);
        
        // Tutup scanner setelah selesai
        scanner.close(); 
    }
}