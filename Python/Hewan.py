from abc import ABC, abstractmethod
from Pemilik import Pemilik

class Hewan(ABC):
    """Kelas abstrak dasar untuk semua jenis hewan. (Base Class)"""
    def __init__(self, nama: str = "", umur: int = 0, berat: int = 0, pemilik: Pemilik = None):
        self.__nama = nama
        self.__umur = umur
        self.__berat = berat
        self.__pemilik = pemilik 

    # Getter konvensional
    def get_nama(self) -> str:
        return self.__nama

    def get_umur(self) -> int:
        return self.__umur

    def get_berat(self) -> int:
        return self.__berat

    def get_pemilik(self) -> Pemilik:
        return self.__pemilik

    # Setter konvensional
    def set_nama(self, nama: str):
        self.__nama = nama

    def set_umur(self, umur: int):
        if umur >= 0:
            self.__umur = umur

    def set_berat(self, berat: int):
        if berat >= 0:
            self.__berat = berat

    def set_pemilik(self, pemilik: Pemilik):
        self.__pemilik = pemilik

    @abstractmethod
    def get_spesific_info(self) -> str:
        pass

    def get_info_dasar(self) -> str:
        return f"{self.__nama} | Umur: {self.__umur} th | Berat: {self.__berat} kg"
