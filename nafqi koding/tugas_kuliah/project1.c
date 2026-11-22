#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <string.h>

int jumlah_akun = 1;


void mata_kuliah(KRS *user, int k){
	FILE *krs = fopen("krs.txt", "a");
	FILE *file = fopen("matkul.txt", "a");
	user[k].jumlah_matkul = user[k].jumlah_matkul + 1;
	user[k].mkl= realloc(user[k].mkl, user[k].jumlah_matkul * sizeof(Matkul));	
	int c = user[k].jumlah_matkul - 1;
	printf("masukkan nama mata kuliah: ");
	scanf("%s", user[k].mkl[c].nama_matkul);
	printf("masukkan jumlah SKS: ");
	scanf("%d", &user[k].mkl[c].SKS);
	fprintf(file, "%s\n%d\n", user[k].mkl[c].nama_matkul, user[k].mkl[c].SKS);
	fprintf(krs, "NIM: %s\nmata kuliah: %s\njumlah SKS: %d\n",user[k].mhs.NIM, user[k].mkl[c].nama_matkul, user[k].mkl[c].SKS);
	fclose(krs);
	fclose(file);
}

void daftar(KRS *user, int k){
	FILE *file = fopen("mahasiswa.txt", "a");
	printf("masukkan nama mahasiswa: ");
    	scanf("%s", user[k].mhs.nama_mahasiswa);
    	printf("masukkan NIM: ");
    	scanf("%s", user[k].mhs.NIM);
	printf("masukkan IPK: ");
	scanf("%f", &user[k].mhs.IPK);
	user[k].jumlah_matkul = 0;
	user[k].mkl = calloc(user[k].jumlah_matkul, sizeof(Matkul));
	jumlah_akun = jumlah_akun +1;
	fprintf(file, "%s %s %f\n", user[k].mhs.nama_mahasiswa, user[k].mhs.NIM, user[k].mhs.IPK);
	fclose(file);
	
}

void beranda(KRS *user, int k){
	while(1){
		int opsi;
		printf("1.cek mata kuliah\n2.daftar mata kuliah\n3.keluar\nopsi: ");
		scanf("%d", &opsi);
		if(opsi == 1){
			if(user[k].jumlah_matkul == 0){
				printf("belum ada mata kuliah\n");
				mata_kuliah(user, k);
			}else{
				for(int i = user[k].jumlah_matkul - 1; i >= 0; i--){
					printf("nama mata kuliah: %s\njumlah SKS: %d\n", user[k].mkl[i].nama_matkul, user[k].mkl[i].SKS);
				}
			}
		}else if(opsi == 2){
			mata_kuliah(user, k);
		}else{
			break;
		}
	}
}

int main(){
	KRS *a = (KRS *) calloc(jumlah_akun, sizeof(KRS));
	FILE *mahasiswa = fopen("mahasiswa.txt", "r");
	char isi[100];
	if(mahasiswa != NULL){
		while( fgets(isi, sizeof(isi), mahasiswa) != NULL){
			isi[strcspn(isi, "\n")] = 0;
			sscanf(isi, "%s %s %f", a[jumlah_akun - 1].mhs.nama_mahasiswa, a[jumlah_akun - 1].mhs.NIM, &a[jumlah_akun - 1].mhs.IPK);
			a[jumlah_akun-1].jumlah_matkul = 0;
			a[jumlah_akun-1].mkl = calloc(a[jumlah_akun-1].jumlah_matkul, sizeof(Matkul));
			jumlah_akun = jumlah_akun + 1;
			a = (KRS* ) realloc(a, jumlah_akun * sizeof(KRS));
		}
	}
	fclose(mahasiswa);
	int posisi;
	FILE *krs = fopen("krs.txt", "r");
	if(krs != NULL){
		while( fgets(isi, sizeof(isi), krs) != NULL){
			isi[strcspn(isi, "\n")] = 0;
			if(strncmp(isi,"NIM: ",5)==0){
				for(int i = jumlah_akun - 1; i >= 0; i--){
					if(strcmp(isi+5, a[i].mhs.NIM) == 0){
						posisi = i;
						break;
					}
				}
			}else if(strncmp(isi, "mata kuliah: ", 13)==0){
				a[posisi].jumlah_matkul++;
				a[posisi].mkl = realloc(a[posisi].mkl, a[posisi].jumlah_matkul * sizeof(Matkul));
				strcpy(a[posisi].mkl[a[posisi].jumlah_matkul - 1].nama_matkul, isi+13);
			}else if(strncmp(isi, "jumlah SKS: ", 12)==0){
				a[posisi].mkl[a[posisi].jumlah_matkul - 1].SKS= atoi(isi+12);
			}
		}
	}
	fclose(krs);
	while(1){
		int menu;
		char nama[10];
		char NIM[10];
		printf("menu\n1.login\n2.register\n3.keluar\n");
		printf("opsi: ");
		scanf("%d",&menu);
		if(menu == 1){
			if(a[0].mhs.IPK == 0 || strcmp(a[0].mhs.nama_mahasiswa, "\0") ==0){
				int s = jumlah_akun - 1;
				printf("belum ada akun terdaftar\n");
				daftar(a, s);
				a = realloc(a, jumlah_akun * sizeof(KRS));
			}else{
				printf("masukkan username: ");
				scanf("%s", nama);
				printf("masukkan NIM: ");
				scanf("%s", NIM);
				for(int i = jumlah_akun - 1; i >= 0; i--){
					if(strcmp(nama, a[i].mhs.nama_mahasiswa) == 0 && strcmp(NIM, a[i].mhs.NIM) == 0){
						printf("halo %s\n", a[i].mhs.nama_mahasiswa);
						beranda(a, i);
						break;
					}
				}
			}
		}else if(menu == 2){
			int s = jumlah_akun - 1;
			daftar(a, s);
			a = realloc(a, jumlah_akun * sizeof(KRS));
		}else{
			break;
		}
	}

    return 0;
}
