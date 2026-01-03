#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Harf/Rakam kontrolü için (isalnum)
#include <string.h>

#define MAX 100

// --- STACK (YIÐIN) YAPISI ---
// C dilinde hazir Stack olmadigi icin kendimiz basitce tanimliyoruz
char stack[MAX];
int top = -1;

// Stack'e eleman ekleme
void push(char x) {
    if (top >= MAX - 1) {
        printf("Stack dolu!\n");
    } else {
        stack[++top] = x;
    }
}

// Stack'ten eleman çýkarma
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Stack'in tepesindeki elemana bakma (silmeden)
char peek() {
    if (top == -1) return -1;
    return stack[top];
}

// --- ÖNCELÝK KONTROLÜ (Precedence) ---
// Ýþlem önceliði: * ve / (2 puan), + ve - (1 puan)
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// --- SHUNTING YARD ALGORÝTMASI ---
void infixToPostfix(char* exp) {
    printf("Infix Ifade: %s\n", exp);
    printf("Postfix Sonuc: ");
    
    char *e;
    
    // String'in baþýndan sonuna kadar tek tek geziyoruz
    for (e = exp; *e != '\0'; e++) {
        
        // 1. Eðer gelen karakter bir harf veya rakamsa direkt yazdýr
        if (isalnum(*e)) {
            printf("%c", *e);
        }
        // 2. Eðer '(' geldiyse stack'e at
        else if (*e == '(') {
            push(*e);
        }
        // 3. Eðer ')' geldiyse, '(' görene kadar stack'tekileri boþalt ve yazdýr
        else if (*e == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            pop(); // '(' iþaretini de stackten at ama yazdýrma
        }
        // 4. Eðer bir iþlem operatörü (+ - * /) geldiyse
        else {
            // Stack'teki operatörün önceliði benimkinden büyükse, onu çýkar ve yazdýr
            while (top != -1 && precedence(peek()) >= precedence(*e)) {
                printf("%c", pop());
            }
            // Sonra kendimi stack'e ekle
            push(*e);
        }
    }
    
    // Döngü bitti, Stack'te kalanlarý sýrayla çýkar ve yazdýr
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    // Test edilecek ifade: A + B * C
    // Beklenen sonuc: A B C * +
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    // Daha basit test icin: "A+B*C" yazabilirsin.

    printf("--- Shunting Yard Algoritmasi (Infix -> Postfix) ---\n\n");
    
    infixToPostfix(expression);

    return 0;
}
