#include <stdio.h>

#define V 6 

// ---> DFS ALGORÝTMASI <---

void DFS(int startNode, int visited[], int graph[][V]) {
    // 1. Þu anki düðümü ziyaret edildi olarak iþaretle ve yazdýr
    visited[startNode] = 1;
    printf("%d ", startNode);

    // 2. Tüm diðer düðümleri kontrol et
    for (int i = 0; i < V; i++) {
        
        if (graph[startNode][i] == 1 && !visited[i]) {
            DFS(i, visited, graph); 
        }
    }
}

// ---> CLUSTER BULMA FONKSÝYONU <---
void findClusters(int graph[][V]) {
    
    int visited[V] = {0}; 
    int clusterCount = 0;

    printf("Graph Icerisindeki Kumeler (Clusters):\n");
    printf("--------------------------------------\n");

    // Tüm düðümleri tek tek kontrol et
    for (int i = 0; i < V; i++) {
        
        if (visited[i] == 0) {
            clusterCount++;
            printf("Kume %d: { ", clusterCount);
            
            // Bu düðüme baðlý her þeyi bul ve iþaretle
            DFS(i, visited, graph);
            
            printf("}\n");
        }
    }
    
    printf("--------------------------------------\n");
    printf("Toplam Kume Sayisi: %d\n", clusterCount);
}

int main() {
    
    
    int graph[V][V] = {
     
        {0, 1, 1, 0, 0, 0}, 
        {1, 0, 1, 0, 0, 0}, 
        {1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0}  
    };

    findClusters(graph);

    return 0;
}
