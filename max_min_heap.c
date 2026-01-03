#include <stdio.h>

#define MAX_SIZE 100 


typedef struct {
    int array[MAX_SIZE];
    int size;
} MaxHeap;

// Yardýmcý Fonksiyon: Ýki sayýnýn yerini deðiþtir
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ---> 1. HEAPIFY (Aþaðý Doðru Düzenleme) <---

void heapify(MaxHeap *heap, int i) {
    int largest = i;           
    int left = 2 * i + 1;      
    int right = 2 * i + 2;     
    
    
    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    
    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;


    if (largest != i) {
        swap(&heap->array[i], &heap->array[largest]);

        
        heapify(heap, largest);
    }
}

// ---> 2. INSERT (Ekleme ve Yukarý Doðru Düzenleme) <---
void insert(MaxHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Hata: Heap dolu!\n");
        return;
    }

    // 1. Elemaný dizinin en sonuna ekle
    int i = heap->size;
    heap->array[i] = value;
    heap->size++;

    // 2. Yukarý doðru (Bubble Up) düzeltme yap
    
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// ---> 3. EXTRACT MAX (Kökü Silme) <---
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0)
        return -1;

    if (heap->size == 1) {
        heap->size--;
        return heap->array[0];
    }

    // 1. Kökü (en büyüðü) al
    int root = heap->array[0];

    // 2. En son elemaný köke taþý
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    // 3. Yeni kökü aþaðý doðru (Bubble Down) düzelt
    heapify(heap, 0);

    return root;
}


void printHeap(MaxHeap *heap) {
    printf("Heap Dizisi: ");
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->array[i]);
    printf("\n");
}

int main() {
    MaxHeap heap;
    heap.size = 0;

    
    insert(&heap, 3);
    insert(&heap, 10);
    insert(&heap, 12);
    insert(&heap, 8);
    insert(&heap, 2);
    insert(&heap, 14);

    
    
    printHeap(&heap);

    // En büyüðü çekme
    printf("Silinen (Max): %d\n", extractMax(&heap));
    printHeap(&heap);

    printf("Silinen (Max): %d\n", extractMax(&heap));
    printHeap(&heap);

    return 0;
}
