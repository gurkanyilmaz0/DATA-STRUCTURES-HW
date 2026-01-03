#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Array -> Tree Dönüþümü
struct Node* insertLevelOrder(int arr[], int n, int i) {
    struct Node* root = NULL;

    // Sýnýr kontrolü
    if (i < n) {
        root = newNode(arr[i]);

        
        root->left = insertLevelOrder(arr, n, 2 * i + 1);

        
        root->right = insertLevelOrder(arr, n, 2 * i + 2);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = insertLevelOrder(arr, n, 0);

    printf("InOrderr Ciktisi: ");
    inOrder(root);
    printf("\n");

    return 0;
}

