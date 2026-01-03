#include <stdio.h>
#include <stdlib.h>

#define MAX_Q_SIZE 100 // Kuyruk boyutu

// --- 1. AÐAÇ DÜÐÜM YAPISI ---
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Düðüm oluþturma fonksiyonu
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// --- 2. PREORDER TRAVERSAL (Kök - Sol - Sað) ---
// Rekürsif (Kendi kendini çaðýran) yöntem
void printPreorder(struct Node* node) {
    if (node == NULL) return;

    printf("%d ", node->data);     // 1. Önce KÖK
    printPreorder(node->left);     // 2. Sonra SOL
    printPreorder(node->right);    // 3. Sonra SAÐ
}

// --- 3. LEVEL ORDER ÝÇÝN KUYRUK (QUEUE) YAPISI ---
// Level Order için "sýrada bekleyenleri" tutmamýz lazým
struct Node* queue[MAX_Q_SIZE];
int front = -1;
int rear = -1;

void enqueue(struct Node* node) {
    if (rear == MAX_Q_SIZE - 1) return; // Kuyruk dolu
    if (front == -1) front = 0;
    rear++;
    queue[rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL; // Kuyruk boþ
    struct Node* temp = queue[front];
    front++;
    return temp;
}

// --- 4. LEVEL ORDER TRAVERSAL (Katman Katman) ---
// Kuyruk kullanarak yukarýdan aþaðý, soldan saða tarama
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    // Önce kökü kuyruða at
    enqueue(root);

    while (front <= rear && front != -1) { // Kuyruk boþalana kadar dön
        // 1. Kuyruðun baþýndakini çýkar ve yazdýr
        struct Node* current = dequeue();
        printf("%d ", current->data);

        // 2. Sol çocuðu varsa kuyruða ekle
        if (current->left != NULL)
            enqueue(current->left);

        // 3. Sað çocuðu varsa kuyruða ekle
        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main() {
    /*
        Oluþturduðumuz Aðaç Görünümü:
              1        (Level 0)
            /   \
           2     3     (Level 1)
          / \   / \
         4   5 6   7   (Level 2)
    */

    struct Node* root = createNode(1);
    root->left        = createNode(2);
    root->right       = createNode(3);
    
    root->left->left  = createNode(4);
    root->left->right = createNode(5);
    
    root->right->left = createNode(6);
    root->right->right= createNode(7);

    printf("--- Agac Gezinti Yontemleri ---\n\n");

    // Preorder Testi
    printf("1. Preorder (Kok - Sol - Sag): ");
    printPreorder(root);
    printf("\n   (Aciklama: Kokten baslar, hep sola dalar)\n\n");

    // Level Order Testi
    // Kuyruk indekslerini sýfýrla (Main içinde tekrar çaðýrmak gerekirse diye)
    front = -1; rear = -1; 
    
    printf("2. Level Order (Breadth First): ");
    printLevelOrder(root);
    printf("\n   (Aciklama: Kat kat asagi iner. 1 -> 2,3 -> 4,5,6,7)\n");

    return 0;
}
