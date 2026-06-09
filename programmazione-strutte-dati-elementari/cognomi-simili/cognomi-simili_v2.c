#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TASKS 100

// Funzione helper per verificare la similitudine esatta in-place
bool sono_simili(const char *a, const char *b, int k) {
    // Verifica che i primi 'k' byte coincidano e che il byte all'indice 'k'
    // (ovvero il k+1-esimo carattere) sia diverso per evitare collisioni su N+1.
    return (strncmp(a, b, k) == 0) && (a[k] != b[k]);
}

int main(void) {
    FILE* fp = fopen("input.txt", "r");
    FILE* out = fopen("output2.txt", "w");
    
    if (fp == NULL || out == NULL) { 
        return 1; 
    }

    int K = 0; 
    char c1[50], c2[50], c3[50];

    for (unsigned i = 0; i < TASKS; i++) {
        if (fscanf(fp, "%d %s %s %s", &K, c1, c2, c3) != 4) {
            break; // Prevenzione su EOF o file malformati
        }

        // Valutazione indipendente degli archi del grafo di similitudine
        bool p12 = sono_simili(c1, c2, K);
        bool p13 = sono_simili(c1, c3, K);
        bool p23 = sono_simili(c2, c3, K);

        // Risoluzione delle collisioni non-transitive con ordine di priorità
        if (p12 && p13 && p23) {
            fprintf(out, "%s %s %s\n", c1, c2, c3);
        } else if (p12) {
            fprintf(out, "%s %s\n", c1, c2);
        } else if (p13) {
            fprintf(out, "%s %s\n", c1, c3);
        } else if (p23) {
            fprintf(out, "%s %s\n", c2, c3);
        } else {
            fprintf(out, "\n"); // Fallback se nessun cognome è simile
        }
    }

    fclose(fp);
    fclose(out);
    return 0; 
}


