from Hewan import Hewan
from Pemilik import Pemilik

class HewanAir(Hewan):
    """Kelas turunan untuk Hewan Air."""
    def __init__(self, nama: str = "", umur: int = 0, berat: int = 0, pemilik: Pemilik = None,
                 jenis_air: str = "", panjang_tubuh: float = 0.0, kecepatan_renang: float = 0.0):
        super().__init__(nama, umur, berat, pemilik)  # Pewarisan
        self.__jenis_air = jenis_air
        self.__panjang_tubuh = panjang_tubuh
        self.__kecepatan_renang = kecepatan_renang

    # Getter konvensional
    def get_jenis_air(self) -> str:
        return self.__jenis_air

    def get_panjang_tubuh(self) -> float:
        return self.__panjang_tubuh

    def get_kecepatan_renang(self) -> float:
        return self.__kecepatan_renang

    # Setter konvensional
    def set_jenis_air(self, ja: str):
        self.__jenis_air = ja

    def set_panjang_tubuh(self, pt: float):
        self.__panjang_tubuh = pt

    def set_kecepatan_renang(self, kr: float):
        self.__kecepatan_renang = kr

    def get_spesific_info(self) -> str:
        """Implementasi Polymorphism."""
        return (f"Jenis: Air | Habitat: {self.get_jenis_air()} | Pjg Tubuh: {self.get_panjang_tubuh()} m | Kecepatan: {self.get_kecepatan_renang()} m/s")
