#include <limits.h>
#include <malloc.h>
#include "arrsll.h"

// Modul

// Modul untuk inisialisai array
void initArrayKota(ArrayKota *arr, int capacity)
{
	int i;
	
    arr->data = (Kota*)malloc(capacity * sizeof(Kota));
    arr->capacity = capacity;
    arr->count = 0;
    
    for (i = 0; i < capacity; i++) {
        arr->data[i].kt = Nil;
        arr->data[i].p = Nil;
    }
}

// Modul untuk menambah node kota
void addKota(ArrayKota *arr, const char *namaKota)
{
	int i;
	
	if (arr->count >= arr->capacity) {
        printf("Array kota penuh!\n");
        return;
    }
    
    for (i = 0; i < arr->count; i++) {
        if (arr->data[i].kt && strcmp(arr->data[i].kt, namaKota) == 0) {
            printf("Kota %s sudah ada!\n", namaKota);
            return;
        }
    }
    
    arr->data[arr->count].kt = strdup(namaKota);
    if (!arr->data[arr->count].kt) {
        printf("Alokasi memori gagal!\n");
        return;
    }
    
    arr->data[arr->count].p = Nil;
    arr->count++;
    printf("Kota %s berhasil ditambahkan\n", namaKota);
}

// Modul untuk menghapus node kota
void deleteKota(ArrayKota *arr, const char *namaKota)
{
	int idx, i;
	
	idx = findKota(arr, namaKota);
    if (idx == -1) {
        printf("Kota %s tidak ditemukan!\n", namaKota);
        return;
    }
    
    DelAll((List*)&arr->data[idx].p);
    
    free(arr->data[idx].kt);
    
    for (i = idx; i < arr->count - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    
    arr->count--;
    arr->data[arr->count].kt = Nil;
    arr->data[arr->count].p = Nil;
    printf("Kota %s berhasil dihapus\n", namaKota);
}

// Modul untuk menambah node warga
void addWarga(Kota *kota, const char *namaWarga);

// Modul untuk menambah node warga
void deleteWarga(Kota *kota, const char *namaWarga);

// Modul untuk mencari kota
boolean findKota(ArrayKota *arr, const char *namaKota)
{
	int i;
    for (i = 0; i < arr->count; i++) {
        if (arr->data[i].kt && strcmp(arr->data[i].kt, namaKota) == 0) {
            return true;
        }
    }
    return false;
}

// Modul untuk menampilkan linked list
void displayAll(ArrayKota arr) 
{
    int i;
    addresswg current;
    
    if (arr.count == 0) {
        printf("Daftar Kota Kosong\n");
        return;
    }
    
    printf("\nDaftar Kota dan Warga:\n");
    for (i = 0; i < arr.count; i++) {
        printf("%s -> ", arr.data[i].kt);
        
        current = arr.data[i].p;
        if (current == Nil) {
            printf("NIL\n");
        } else {
            while (current != Nil) {
                printf("%s", current->nm);
                current = current->q;
                printf(current ? " -> " : " -> NIL\n");
            }
        }
    }
}

// End Modul
