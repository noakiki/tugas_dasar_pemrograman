#include <stdio.h>
#include <stdlib.h>
#include "database.h"

int main(){
    int jumlah_akun = 1;
    profil *user = (profil *) malloc(jumlah_akun* sizeof(profil));
    printf("masukkan nama user: ");
    scanf("%s", user[0].nama_user);
    printf("%s\n", user[0].nama_user);
    printf("masukkan password: ");
    scanf("%s", user[0].password);
    printf("%s\n", user[0].password);
    user[0].ID = jumlah_akun;

    int jumlah_produk = 1;
    produk *jualan = (produk*) malloc (jumlah_produk * sizeof(produk));
    printf("masukkan nama produk: ");
    scanf("%s", jualan[0].nama_produk);
    printf("%s\n", jualan[0].nama_produk);
    printf("masukkan deskripsi produk: ");
    getchar();
    fgets(jualan[0].deskripsi,sizeof(jualan[0].deskripsi), stdin);
    printf("%s\n", jualan[0].deskripsi);
    printf("masukkan harga produk: ");
    scanf("%d", &jualan[0].harga);
    printf("%d", jualan[0].harga);

    return 0;
}