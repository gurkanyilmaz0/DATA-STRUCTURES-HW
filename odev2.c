#include <stdio.h>

/*
1. Tower of Hanoi Nedir?
Matematiksel bir zeka oyunudur. Elimizde 3 tane çubuk (A, B, C) ve farklý boyutlarda diskler vardýr.

Amaç: A çubuðundaki disklerin tamamýný, sýralarýný bozmadan C çubuðuna taþýmaktýr.

Kurallar:

Her hamlede sadece 1 disk yerinden oynatýlabilir.

Büyük disk, küçük diskin üzerine asla konulamaz
 */

// Hanoi Fonksiyonu
// n: Disk sayýsý
// kaynak: Baþlangýç çubuðu (Source)
// yardimci: Ara çubuk (Auxiliary)
// hedef: Gideceði çubuk (Destination)
void towerOfHanoi(int n, char kaynak, char yardimci, char hedef) {
    
    // Base Case: Eðer sadece 1 disk varsa direkt hedefe koy
    if (n == 1) {
        printf("Disk 1, %c cubugundan %c cubuguna tasindi.\n", kaynak, hedef);
        return;
    }

    // ADIM 1: En alttaki büyük disk hariç, üstteki (n-1) diski
    // Kaynak'tan Yardýmcý'ya taþý (Hedef'i geçici olarak kullan).
    towerOfHanoi(n - 1, kaynak, hedef, yardimci);

    // ADIM 2: En büyük diski (n. disk) Kaynak'tan Hedef'e taþý.
    printf("Disk %d, %c cubugundan %c cubuguna tasindi.\n", n, kaynak, hedef);

    // ADIM 3: Yardýmcý çubuktaki (n-1) diski Hedef'e taþý 
    // (Kaynak'ý geçici olarak kullan).
    towerOfHanoi(n - 1, yardimci, kaynak, hedef);
}

int main() {
    int diskSayisi = 3; // Ýstersen bu sayýyý deðiþtirebilirsin (3 veya 4 idealdir)

    printf("Hanoi Kuleleri Cozumu (%d Disk icin):\n", diskSayisi);
    printf("--------------------------------------\n");

    // A: Kaynak, B: Yardýmcý, C: Hedef
    towerOfHanoi(diskSayisi, 'A', 'B', 'C');

    return 0;
}
