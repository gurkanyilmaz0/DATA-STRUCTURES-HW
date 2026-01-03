#include <stdio.h>

int main() {
    // 1. ADIM: Ýçinde bol sýfýr olan Sparse (Seyrek) Matrisimizi tanýmlayalým
    // 4 Satýr, 5 Sütunluk bir örnek
    int sparseMatrix[4][5] = {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    // 2. ADIM: 0 olmayan eleman sayýsýný bulalým
    int size = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    // 3. ADIM: Yeni matrisimizi oluþturalým
    // 3 satýr olacak:
    // 0. Satýr -> Orijinal Satýr Ýndeksi
    // 1. Satýr -> Orijinal Sütun Ýndeksi
    // 2. Satýr -> Deðer
    int compactMatrix[3][size];

    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;  // Satýr bilgisi
                compactMatrix[1][k] = j;  // Sütun bilgisi
                compactMatrix[2][k] = sparseMatrix[i][j]; // Deðer
                k++;
            }
        }
    }

    // 4. ADIM: Sonucu ekrana yazdýralým
    printf("Sparse Matrix Temsili (Satir | Sutun | Deger):\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Satir: %d | Sutun: %d | Deger: %d \n",
                compactMatrix[0][i], compactMatrix[1][i], compactMatrix[2][i]);
    }

    return 0;
}
