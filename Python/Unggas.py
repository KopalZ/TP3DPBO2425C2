from Hewan import Hewan
from Pemilik import Pemilik

class Unggas(Hewan):
    """Kelas turunan untuk Unggas."""
    def __init__(self, nama: str = "", umur: int = 0, berat: int = 0, pemilik: Pemilik = None, panjang_sayap: float = 0.0, warna_bulu: str = "", bisa_terbang: bool = False):
        super().__init__(nama, umur, berat, pemilik)  # Pewarisan
        self.__panjang_sayap = panjang_sayap
        self.__warna_bulu = warna_bulu
        self.__bisa_terbang = bisa_terbang

    # Getter konvensional
    def get_panjang_sayap(self) -> float:
        return self.__panjang_sayap

    def get_warna_bulu(self) -> str:
        return self.__warna_bulu

    def get_bisa_terbang(self) -> bool:
        return self.__bisa_terbang

    # Setter konvensional
    def set_panjang_sayap(self, ps: float):
        self.__panjang_sayap = ps

    def set_warna_bulu(self, wb: str):
        self.__warna_bulu = wb

    def set_bisa_terbang(self, bt: bool):
        self.__bisa_terbang = bt

    def get_spesific_info(self) -> str:
        """Implementasi Polymorphism."""
        status_terbang = "Ya" if self.get_bisa_terbang() else "Tidak"
        return (f"Jenis: Unggas | Sayap: {self.get_panjang_sayap()} m | Bulu: {self.get_warna_bulu()} | Terbang: {status_terbang}")
