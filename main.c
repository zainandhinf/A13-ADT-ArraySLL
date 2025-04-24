#include <stdio.h>
#include "arrsll.h"

int main() {

    int jumlahKota, choice, idx;
    char kota[MAX_NAME_LENGTH], warga[MAX_NAME_LENGTH];
    ArrayKota arr;
    
	printf("Masukkan jumlah maksimum kota: ");
    scanf("%d", &jumlahKota);
    getchar();

    initArrayKota(&arr, jumlahKota);
    
    do {
        printf("\nMenu:\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Warga\n");
        printf("3. Hapus Kota\n");
        printf("4. Hapus Warga\n");
        printf("5. Tampilkan Semua Data\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1: {
                printf("Nama Kota: ");
                fgets(kota, MAX_NAME_LENGTH, stdin);
                kota[strcspn(kota, "\n")] = '\0';
                addKota(&arr, kota);
                break;
            }
                
            case 2: {
                
                break;
            }
                
            case 3: {
                printf("Nama Kota yang akan dihapus: ");
                fgets(kota, MAX_NAME_LENGTH, stdin);
                kota[strcspn(kota, "\n")] = '\0';
                deleteKota(&arr, kota);
                break;
            }
                
            case 4: {
                
                break;
            }
                
            case 5: {
                displayAll(arr);
                break;
            }
            
            case 6: {
                printf("Program selesai.\n");
                break;
            }
			    
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 6);

    return 0;
}



