from KebunBinatang import KebunBinatang

def tampilkan_menu():
    """Menampilkan pilihan menu utama."""
    print("\n=============================================")
    print("         SISTEM MANAJEMEN KEBUN BINATANG     ")
    print("=============================================")
    print("1. Tampilkan Semua Data Hewan")
    print("2. Input Data Hewan Baru")
    print("3. Keluar")
    print("---------------------------------------------")

def run_menu(kebun: KebunBinatang):
    """Logika utama program (Menu)."""
    while True:
        tampilkan_menu()
        pilihan = input("Masukkan pilihan (1-3): ")

        if pilihan == '1':
            kebun.tampilkan_data_hewan()
        elif pilihan == '2':
            kebun.input_hewan_interaktif()
        elif pilihan == '3':
            print("Terima kasih telah menggunakan sistem. Sampai jumpa!")
            break
        else:
            print("Pilihan tidak valid. Silakan masukkan angka 1, 2, atau 3.")

if __name__ == "__main__":
    # Inisialisasi Kebun Binatang
    kebun = KebunBinatang("Taman Satwa Indah", "Kota Bandung")
    
    # Memanggil method internal: 
    kebun.seed_data_hewan() 

    # --- 2. JALANKAN MENU UTAMA ---
    run_menu(kebun)