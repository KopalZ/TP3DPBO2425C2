from HewanDarat import HewanDarat
from HewanAir import HewanAir
from Pemilik import Pemilik

# Multiple Inheritance di Python: Inherit dari Darat dan Air
class HewanAmfibi(HewanDarat, HewanAir):
    def __init__(self, nama: str = "", umur: int = 0, berat: int = 0, pemilik: Pemilik = None,
                 jumlah_kaki: int = 0, jenis_kulit: str = "", jenis_bulu_darat: str = "",
                 jenis_air: str = "", panjang_tubuh: float = 0.0, kecepatan_renang: float = 0.0,
                 jenis_amfibi: str = "", beracun: bool = False):
        
        # Inisialisasi HewanDarat dan HewanAir
        HewanDarat.__init__(self, nama, umur, berat, pemilik, jumlah_kaki, jenis_kulit, jenis_bulu_darat)
        HewanAir.__init__(self, nama, umur, berat, pemilik, jenis_air, panjang_tubuh, kecepatan_renang)

        self.__jenis_amfibi = jenis_amfibi
        self.__beracun = beracun

    # Getter konvensional
    def get_jenis_amfibi(self) -> str:
        return self.__jenis_amfibi

    def get_beracun(self) -> bool:
        return self.__beracun

    # Setter konvensional
    def set_jenis_amfibi(self, ja: str):
        self.__jenis_amfibi = ja

    def set_beracun(self, r: bool):
        self.__beracun = r

    def get_spesific_info(self) -> str:
        status_racun = "Ya" if self.get_beracun() else "Tidak"
        
        # Menggunakan super() untuk mendapatkan info dari Darat dan Air
        info_darat = HewanDarat.get_spesific_info(self).replace("Jenis: Darat | ", "")
        info_air = HewanAir.get_spesific_info(self).replace("Jenis: Air | ", "")

        return (f"Jenis: Amfibi ({self.get_jenis_amfibi()}) | Beracun: {status_racun} | DARAT: {info_darat} | AIR: {info_air}")
