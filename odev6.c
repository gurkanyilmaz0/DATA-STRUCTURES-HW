#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// 1. TRAVERSAL (Gezinme)/

void printList(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    printf("Liste: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Baþa dönene kadar devam et
    
    printf("(Basa dondu)\n");
}

// 2. ARAYA EKLEME

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) return;

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// 3. SÝLME (Biraz daha karmaþýktýr)

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    // Durum 1: Listede sadece tek düðüm var ve o silinecekse
    if (*head_ref == del && (*head_ref)->next == *head_ref) {
        *head_ref = NULL;
        free(del);
        return;
    }

    
    struct Node* last = *head_ref;
    
    
    while (last->next != del) {
        last = last->next;
    }
    
    last->next = del->next;

    
    if (*head_ref == del) {
        *head_ref = last->next; 
    }

    free(del);
}

int main() {
    // ---> LÝSTEYÝ OLUÞTURMA (Manuel) <---
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    
    
    head->next = head; 

    // ---> EKLEME <---
    
    insertAfter(head, 20);
    
    
    insertAfter(head->next, 30);

    printf("Olusturulan ");
    printList(head); 
	
	   // ---> SÝLME TESTÝ <---
    
    printf("Bas dugum (10) siliniyor...\n");
    deleteNode(&head, head);

    printList(head); 

    return 0;
}

