#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// 1. TRAVERSAL (Gezinme ve Yazdýrma)
void printList(struct Node* node) {
    printf("Liste: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// 2. ARAYA EKLEME (Verilen düðümden sonrasýna ekler)
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("Hata: Onceki dugum NULL olamaz.\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    // Baðlantýlarý ayarla
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    // Eðer yeni düðümden sonra eleman varsa, onun 'prev'ini güncelle
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

// 3. SÝLME (Adresi verilen düðümü siler)
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
        return;

    // Silinecek düðüm baþ (head) ise
    if (*head_ref == del)
        *head_ref = del->next;

    // Silinecek düðüm son deðilse
    if (del->next != NULL)
        del->next->prev = del->prev;

    // Silinecek düðüm ilk deðilse
    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

int main() {
    // ---> LÝSTEYÝ OLUÞTURMA (Manuel) <---
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;

    
    insertAfter(head, 20); 
    insertAfter(head->next, 30);
    printf("Olusturulan ");
    printList(head); 

    // ---> SÝLME TESTÝ <---
    
    deleteNode(&head, head->next);

    printf("Silme Sonrasi ");
    printList(head);

    return 0;
}
