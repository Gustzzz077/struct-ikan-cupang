#include <stdio.h>
#include <string.h>

// Struct untuk menyimpan data ikan cupang
struct Cupang {
    char nama[50];
    int umur;              // dalam minggu
    int kesehatan;         // 0-100
    int mood;              // 0-100
};

void tampilkanStatus(struct Cupang ikan) {
    printf("\n===== STATUS IKAN CUPANG =====\n");
    printf("Nama       : %s\n", ikan.nama);
    printf("Umur       : %d minggu\n", ikan.umur);
    printf("Kesehatan  : %d/100\n", ikan.kesehatan);
    printf("Mood       : %d/100\n", ikan.mood);

    if (ikan.kesehatan >= 80)
        printf("Kondisi    : Sehat\n");
    else if (ikan.kesehatan >= 50)
        printf("Kondisi    : Kurang Sehat\n");
    else
        printf("Kondisi    : Sakit\n");
}

void beriMakan(struct Cupang *ikan) {
    printf("\n>> Memberi makan %s...\n", ikan->nama);
    ikan->kesehatan += 10;
    ikan->mood += 5;
    if (ikan->kesehatan > 100) ikan->kesehatan = 100;
    if (ikan->mood > 100) ikan->mood = 100;
    printf("Makan selesai. %s terlihat lebih sehat!\n", ikan->nama);
}

void gantiAir(struct Cupang *ikan) {
    printf("\n>> Mengganti air untuk %s...\n", ikan->nama);
    ikan->kesehatan += 5;
    ikan->mood += 10;
    if (ikan->kesehatan > 100) ikan->kesehatan = 100;
    if (ikan->mood > 100) ikan->mood = 100;
    printf("Air bersih! %s tampak senang!\n", ikan->nama);
}

void hariBerlalu(struct Cupang *ikan) {
    ikan->kesehatan -= 10;
    ikan->mood -= 10;
    if (ikan->kesehatan < 0) ikan->kesehatan = 0;
    if (ikan->mood < 0) ikan->mood = 0;
}

int main() {
    struct Cupang ikan;
    int pilihan;
    int hari = 1;

    printf("=== Simulasi Perawatan Ikan Cupang ===\n");
    printf("Masukkan nama ikan cupang: ");
    fgets(ikan.nama, sizeof(ikan.nama), stdin);
    strtok(ikan.nama, "\n");  // Menghapus newline
    printf("Masukkan umur ikan (minggu): ");
    scanf("%d", &ikan.umur);

    ikan.kesehatan = 80;
    ikan.mood = 80;

    while (1) {
        printf("\n--- Hari ke-%d ---\n", hari);
        printf("Menu:\n");
        printf("1. Beri Makan\n");
        printf("2. Ganti Air\n");
        printf("3. Lihat Status\n");
        printf("4. Keluar\n");
        printf("Pilih tindakan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                beriMakan(&ikan);
                break;
            case 2:
                gantiAir(&ikan);
                break;
            case 3:
                tampilkanStatus(ikan);
                break;
            case 4:
                printf("Keluar dari simulasi. Sampai jumpa!\n");
                return 0;
            default:
                printf("Pilihan tidak valid.\n");
        }

        hariBerlalu(&ikan);
        hari++;
    }

    return 0;
}