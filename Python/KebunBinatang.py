from Hewan import Hewan
from Pemilik import Pemilik
from HewanDarat import HewanDarat
from HewanAir import HewanAir
from Unggas import Unggas
from HewanAmfibi import HewanAmfibi

class KebunBinatang:
    def __init__(self, nama: str = "Kebun Binatang Default", lokasi: str = "Lokasi Tidak Diketahui"):
        self.__nama = nama
        self.__lokasi = lokasi
        self.__list_hewan = [] # Array of Object

    def get_nama(self) -> str:
        return self.__nama

    def get_lokasi(self) -> str:
        return self.__lokasi

    def get_list_hewan(self) -> list:
        return self.__list_hewan

    def set_nama(self, nama: str):
        self.__nama = nama

    def set_lokasi(self, lokasi: str):
        self.__lokasi = lokasi

    def tambah_hewan(self, hewan: Hewan):
        self.__list_hewan.append(hewan)
        
    def seed_data_hewan(self):
        pemilik1 = Pemilik("Budi Santoso", "Jl. Mawar No. 1", "0812345678")
        pemilik2 = Pemilik("Siti Aisyah", "Jl. Kenanga No. 5", "0898765432")
        pemilik3 = Pemilik("Ahmad Wijaya", "Jl. Sudirman 10", "0877889900")
        
        # Pembuatan objek Hewan dilakukan di sini (dalam method kelas KebunBinatang)
        
        # 1. Hewan Darat
        hewan_darat = HewanDarat("Gajah Sumatera", 15, 4500, pemilik1, 4, "Tebal", "Pendek")
        self.tambah_hewan(hewan_darat)
        
        # 2. Unggas
        hewan_unggas = Unggas("Elang Jawa", 7, 5, pemilik2, 2.0, "Cokelat Emas", True)
        self.tambah_hewan(hewan_unggas)
        
        # 3. Hewan Air
        hewan_air = HewanAir("Lumba-Lumba", 10, 200, pemilik3, "Asin", 2.5, 30.0)
        self.tambah_hewan(hewan_air)
        
        # 4. Hewan Amfibi
        hewan_amfibi = HewanAmfibi(
            nama="Katak Pohon", 
            umur=1, 
            berat=0, 
            pemilik=pemilik1, 
            jumlah_kaki=4, 
            jenis_kulit="Lembab", 
            jenis_bulu_darat="Tidak ada",
            jenis_air="Tawar", 
            panjang_tubuh=0.08, 
            kecepatan_renang=2.0,
            jenis_amfibi="Katak", 
            beracun=False
        )
        self.tambah_hewan(hewan_amfibi)
    
    def tampilkan_data_hewan(self):
        """Menampilkan semua data hewan dalam format tabel dinamis."""
        if not self.__list_hewan:
            print("\n=============================================")
            print("Belum ada data hewan yang tersimpan.")
            print("=============================================")
            return

        # 1. Tentukan lebar kolom maksimum
        headers = ["No", "Nama", "Umur (th)", "Berat (kg)", "Pemilik", "Spesifikasi"]
        data_rows = []
        
        # Kumpulkan data baris dan hitung lebar maksimum
        col_widths = [len(h) for h in headers]

        for i, hewan in enumerate(self.__list_hewan):
            row = [
                str(i + 1),
                hewan.get_nama(), 
                str(hewan.get_umur()), 
                str(hewan.get_berat()), 
                hewan.get_pemilik().get_info_singkat() if hewan.get_pemilik() else "-",
                hewan.get_spesific_info()
            ]
            data_rows.append(row)
            
            # Update lebar kolom maksimum
            for j, cell in enumerate(row):
                if len(cell) > col_widths[j]:
                    col_widths[j] = len(cell)
        
        # Tambahkan sedikit padding
        col_widths = [w + 2 for w in col_widths]

        # 2. Fungsi untuk mencetak baris pembatas
        def print_separator():
            print("+" + "+".join(["-" * w for w in col_widths]) + "+")

        # 3. Cetak Judul Tabel
        print(f"\n======== DATA HEWAN DI {self.get_nama().upper()} ({self.get_lokasi().upper()}) ========")
        print_separator()

        # 4. Cetak Header
        header_line = "| " + " | ".join(
            h.ljust(col_widths[i] - 2) for i, h in enumerate(headers)
        ) + " |"
        print(header_line)
        print_separator()

        # 5. Cetak Data
        for row in data_rows:
            row_line = "| " + " | ".join(
                row[i].ljust(col_widths[i] - 2) for i in range(len(headers))
            ) + " |"
            print(row_line)
        
        print_separator()

    def input_hewan_interaktif(self):
        """Meminta input data hewan baru dari user (Pembuatan objek di sini mendukung Komposisi)."""
        print("\n--- Input Data Hewan Baru ---")
        
        # Pilih Tipe Hewan
        print("Pilih Tipe Hewan:")
        print("1. Hewan Darat (Mamalia/Reptil)")
        print("2. Hewan Air (Ikan/Paus)")
        print("3. Unggas (Burung/Ayam)")
        print("4. Amfibi (Katak/Salamander)")
        
        tipe = input("Pilihan (1-4): ")
        
        # Input Data Dasar
        nama = input("Nama Hewan: ")
        umur = int(input("Umur (tahun): "))
        berat = int(input("Berat (kg): "))
        
        # Input Data Pemilik (Agregasi)
        print("\n--- Input Data Pemilik ---")
        nama_p = input("Nama Pemilik: ")
        alamat_p = input("Alamat Pemilik: ")
        telp_p = input("No. Telepon Pemilik: ")
        pemilik_baru = Pemilik(nama_p, alamat_p, telp_p)

        hewan_baru = None

        if tipe == '1':
            jk = int(input("Jumlah Kaki: "))
            jklt = input("Jenis Kulit: ")
            jbl = input("Jenis Bulu: ")
            hewan_baru = HewanDarat(nama, umur, berat, pemilik_baru, jk, jklt, jbl)
        
        elif tipe == '2':
            ja = input("Jenis Air (Tawar/Asin): ")
            pt = float(input("Panjang Tubuh (m): "))
            kr = float(input("Kecepatan Renang (m/s): "))
            hewan_baru = HewanAir(nama, umur, berat, pemilik_baru, ja, pt, kr)

        elif tipe == '3':
            ps = float(input("Panjang Sayap (m): "))
            wb = input("Warna Bulu: ")
            bt = input("Bisa Terbang? (y/n): ").lower() == 'y'
            hewan_baru = Unggas(nama, umur, berat, pemilik_baru, ps, wb, bt)
            
        elif tipe == '4':
            # Data Darat
            jk = int(input("Jumlah Kaki Darat: "))
            jklt = input("Jenis Kulit Darat: ")
            jbl_darat = input("Jenis Bulu Darat: ")
            # Data Air
            ja = input("Jenis Air (Tawar/Asin): ")
            pt = float(input("Panjang Tubuh (m): "))
            kr = float(input("Kecepatan Renang (m/s): "))
            # Data Amfibi
            jamf = input("Jenis Amfibi (misal: Katak, Salamander): ")
            beracun = input("Apakah Beracun? (y/n): ").lower() == 'y'

            hewan_baru = HewanAmfibi(nama, umur, berat, pemilik_baru, jk, jklt, jbl_darat, ja, pt, kr, jamf, beracun)
        
        else:
            print("Pilihan tidak valid.")
            return

        if hewan_baru:
            self.tambah_hewan(hewan_baru)
            print(f"\nSukses! {nama} ({type(hewan_baru).__name__}) berhasil ditambahkan ke Kebun Binatang.")