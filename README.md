# Janji
Saya Naufal Zahid dengan NIM 2405787 mengerjakan TP 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

# Diagram
<img width="751" height="834" alt="_tp 3 drawio" src="https://github.com/user-attachments/assets/d13746a9-6d23-40d5-91a7-6a9999118552" />

# Penjelasan Desain dan Flow Code
Untuk desainnya disini saya membuat 7 buah class dengan konsep Hierarchial, Multiple, dan Hybrid Inheritance :
1. Class Hewan (Parent Class)
  - Atribut :
    - Nama
    - Umur
    - Berat
  - Method :
      - GetSpecificInfo (Override): memberikan detail spesifik jenis hewan
      - GetInfoDasar : Mengembalikan info dasar hewan (Nama, Umur, Berat).
2. Class HewanDarat (child dari Hewan)
  - Mewarisi semua atribut dari Hewan
  - Tambahan atribut :
      - JumlahKaki
      - JenisKulit
      - JenisBulu
  - Method :
      - GetSpecificInfo (Override dari Hewan): memberikan detail spesifik jenis hewan ddarat
3. Class HewanAir (child dari Hewan)
  - Mewarisi semua atribut dari Hewan
  - Tambahan atribut :
      - JenisAir
      - PanjangTubuh
      - KecepatanRenang
  - Method :
      - GetSpecificInfo (Override dari Hewan): memberikan detail spesifik jenis hewan air
4. Class Unggas (child dari Hewan)
  - Mewarisi semua atribut dari Hewan
  - Tambahan atribut :
      - PanjangSayap
      - WarnaBulu
      - BisaTerbang
  - Method :
      - GetSpecificInfo (Override dari Hewan): memberikan detail spesifik jenis hewan Unggas
5. Class HewanAmfibi (child dari HewanDarat dan HewanAir)
  - Mewarisi semua atribut dari Hewan, HewanDarat dan HewanAir
  - Tambahan atribut :
      - JenisAmfibi
      - Boolean
  - Method :
      - GetSpecificInfo (Override dari Hewan): memberikan detail spesifik jenis hewan
6. Class Pemilik (Memiliki Hubungan Agregasi dengan Hewan)
  - Data Hewan Akan tetap ada meski class pemilik dihapus
  - Atribut :
      - Nama
      - Alamat
      - NoTelepon
  - Method :
    - GetinfoSingkat : untuk mengembalikan ringkasan nama dan nomor telepon pemilik
7. Class KebunBinatang (Composite dengan Hewan)
  - Mewarisi semua atribut dari Hewan
  - Tambahan atribut :
      - JenisAir
      - PanjangTubuh
      - KecepatanRenang
  - Method :
      - TampilkanHewan : Menampilkan seluruh koleksi hewan dalam format tabel
      - TambahHewan : Menambahkan Hewan Ke objek list
dan untuk flow codenya :
## versi Cpp, Java, Python
1. Inisialisasi Data dummy
  - membuat data dummy
  - disimpan di dalam list
2. Menu Utama
  - program memasuki while loop dengan pilihan switch case berupa angka 1/2/3
  - menu yang tersedia ada : tambah(1), tampil(2), keluar(3)
3. Tambah Produk
  - Program meminta input semua atribut
  - datanya akan digunakan untuk membuat objek baru
  - objek akan dimasukkan kedalam list
4. Tampilkan Produk
  - program membaca semua objek yang ada di list
  - objek dipanggil menggunakan getter
  - data akan ditampilkan dalam bentuk tabel dinamis
5. Keluar Program 
  - Program akan berhenti
    

# Dokumentasi Program Berhasil Berjalan
 ## Cpp
<img width="1714" height="480" alt="image" src="https://github.com/user-attachments/assets/213fadbe-320b-4a38-b64a-4a2e2a972598" />

 ## Java
<img width="1870" height="452" alt="image" src="https://github.com/user-attachments/assets/76d5dc3a-b05c-422a-befc-2f578f2194b2" />

 ## Python
<img width="1403" height="365" alt="image" src="https://github.com/user-attachments/assets/265f097d-7e56-433b-b217-30e7d003a8c6" />
