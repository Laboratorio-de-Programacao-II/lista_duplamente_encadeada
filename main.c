#include <stdio.h>
#include <string.h>
#include "lista.h"

int main() {
    TipoLista lista;
    FLVazia(&lista);

    char cmd[10];
    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "i") == 0) {
            TipoItem item;
            scanf("%d", &item.Chave);
            Insere(item, &lista);

        } else if (strcmp(cmd, "r") == 0) {
            int chave;
            scanf("%d", &chave);
            TipoApontador p = lista.Primeiro->Prox;
            while (p != NULL && p->Item.Chave != chave)
                p = p->Prox;
            if (p == NULL) {
                printf("nao encontrado: %d\n", chave);
            } else {
                TipoItem item;
                Retira(p, &lista, &item);
                printf("retirado: %d\n", item.Chave);
            }

        } else if (strcmp(cmd, "inv") == 0) {
            Inverte(&lista);

        } else if (strcmp(cmd, "imp") == 0) {
            Imprime(lista);
        }
    }

    return 0;
}
