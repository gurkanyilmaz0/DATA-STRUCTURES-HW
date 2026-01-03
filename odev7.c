#include <stdio.h>

#define KAPASITE 100 

// 1. TRAVERSAL (Gezinme ve Yazdýrma)
void printArray(int arr[], int size) {
    printf("Dizi (%d eleman): ", size);
    for (int i = 0; i < size; i++) {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

// 2. ARAYA EKLEME (Insertion)

void insertAt(int arr[], int *size, int index, int val) {
    // Kapasite kontrolü/
    if (*size >= KAPASITE) {
        printf("Hata: Dizi dolu!\n");
        return;
    }
    
    if (index < 0 || index > *size) {
        printf("Hata: Gecersiz indeks!\n");
        return;
    }

    
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    
    arr[index] = val;

    
    (*size)++;
}

// 3. SÝLME (Deletion)

void deleteAt(int arr[], int *size, int index) {
    
    if (index < 0 || index >= *size) {
        printf("Hata: Gecersiz indeks veya dizi bos!\n");
        return;
    }

    
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    
    (*size)--;
}

int main() {
    int arr[KAPASITE] = {10, 20, 30, 40, 50}; 
    int size = 5; 

    printArray(arr, size); 

    // ---> EKLEME TESTÝ <---
    
    printf("\n>> 2. indekse '99' ekleniyor...\n");
    insertAt(arr, &size, 2, 99);
    printArray(arr, size);

    // ---> SÝLME TESTÝ <---
    
    printf("\n>> 0. indeks (Bas) siliniyor...\n");
    deleteAt(arr, &size, 0);
    printArray(arr, size);

    return 0;
}

