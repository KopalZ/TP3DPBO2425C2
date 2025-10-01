# Janji
Saya Naufal Zahid dengan NIM 2405787 mengerjakan TP 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

# Diagram


# Penjelasan Desain dan Flow Code
Untuk desainnya disini saya membuat 3 buah class dengan konsep multilevel inheritance :
1. Class AlatElektronik (Parent Class)
  - Atribut :
    - IdProduk
    - Nama
    - Harga
    - Stok
    - Foto_Produk
2. Class PerangkatAudioVisual (child dari AlatElektronik)
  - Mewarisi semua atribut dari AlatElektronik
  - Tambahan atribut :
      - Tipe
      - Merk
      - Daya
3. Class Speaker (child dari PerangkatAudioVisual)
  - Mewarisi semua atribut dari AlatElektronik dan PerangkatAudioVisual
  - Tambahan atribut :
      - JenisSpeaker
      - FrekuensiRespon
      - Impedansi

dan untuk flow codenya :
## versi Cpp, Java, Python
1. Inisialisasi Data dummy
  - membuat 5 data dummy
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
    
## versi PHP
- Menampilkan Data yang ada dengan tabel
- Bisa Menambahkan Data

# Dokumentasi Program Berhasil Berjalan
 ## Cpp


 ## Java


 ## Python


 ## PHP
 
