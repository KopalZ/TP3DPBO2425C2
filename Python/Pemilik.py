class Pemilik:
    """Kelas untuk merepresentasikan Pemilik Hewan."""
    def __init__(self, nama: str = "", alamat: str = "", no_telepon: str = ""):
        # Atribut private
        self.__nama = nama
        self.__alamat = alamat
        self.__no_telepon = no_telepon

    # Getter konvensional
    def get_nama(self) -> str:
        return self.__nama

    def get_alamat(self) -> str:
        return self.__alamat

    def get_no_telepon(self) -> str:
        return self.__no_telepon

    # Setter konvensional
    def set_nama(self, nama: str):
        self.__nama = nama

    def set_alamat(self, alamat: str):
        self.__alamat = alamat

    def set_no_telepon(self, no_telepon: str):
        self.__no_telepon = no_telepon

    def get_info_singkat(self) -> str:
        """Mengembalikan informasi pemilik untuk ditampilkan di tabel."""
        return f"{self.__nama} ({self.__no_telepon})"
