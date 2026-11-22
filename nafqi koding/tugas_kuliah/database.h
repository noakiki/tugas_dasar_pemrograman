typedef struct{
    char nama_mahasiswa[10];
    char NIM[10];
    float IPK;
}mahasiswa;

typedef struct{
	char nama_matkul[10];
	int SKS;
}Matkul;

typedef struct{
    mahasiswa mhs;
    Matkul *mkl;
    int jumlah_matkul;
}KRS;
