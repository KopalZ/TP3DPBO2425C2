from Hewan import Hewan
from Pemilik import Pemilik

class HewanDarat(Hewan):
    """Kelas turunan untuk Hewan Darat."""
    def __init__(self, nama: str = "", umur: int = 0, berat: int = 0, pemilik: Pemilik = None,
                 jumlah_kaki: int = 0, jenis_kulit: str = "", jenis_bulu: str = ""):
        super().__init__(nama, umur, berat, pemilik)  # Pewarisan
        self.__jumlah_kaki = jumlah_kaki
        self.__jenis_kulit = jenis_kulit
        self.__jenis_bulu = jenis_bulu

    # Getter konvensional
    def get_jumlah_kaki(self) -> int:
        return self.__jumlah_kaki

    def get_jenis_kulit(self) -> str:
        return self.__jenis_kulit

    def get_jenis_bulu(self) -> str:
        return self.__jenis_bulu

    # Setter konvensional
    def set_jumlah_kaki(self, jk: int):
        self.__jumlah_kaki = jk

    def set_jenis_kulit(self, jklt: str):
        self.__jenis_kulit = jklt

    def set_jenis_bulu(self, jbl: str):
        self.__jenis_bulu = jbl

    def get_spesific_info(self) -> str:
        """Implementasi Polymorphism."""
        return (f"Jenis: Darat | Kaki: {self.get_jumlah_kaki()} | Kulit: {self.get_jenis_kulit()} | Bulu: {self.get_jenis_bulu()}")
