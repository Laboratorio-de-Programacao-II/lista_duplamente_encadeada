#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Primeiro->Ant = NULL;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    TipoApontador Aux = (TipoApontador)malloc(sizeof(TipoCelula));
    Aux->Item = x;
    Aux->Prox = NULL;
    Aux->Ant = Lista->Ultimo;
    Lista->Ultimo->Prox = Aux;
    Lista->Ultimo = Aux;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item) {
    if (Lista == NULL || Vazia(*Lista) || p == NULL || p == Lista->Primeiro) {
        printf("Erro: posicao invalida\n");
        return;
    }

    *Item = p->Item;

    if (p->Ant != NULL) {
        p->Ant->Prox = p->Prox;
    }

    if (p->Prox != NULL) {
        p->Prox->Ant = p->Ant;
    } else {
        Lista->Ultimo = p->Ant;
    }

    free(p);
}

void Imprime(TipoLista Lista) {
    TipoApontador Aux = Lista.Primeiro->Prox;
    while (Aux != NULL) {
        printf("%d\n", Aux->Item.Chave);
        Aux = Aux->Prox;
    }
}

void Inverte(TipoLista *Lista) {
    if (Lista == NULL || Vazia(*Lista) || Lista->Primeiro->Prox->Prox == NULL) {
        return;
    }

    TipoApontador atual = Lista->Primeiro->Prox;
    TipoApontador temp = NULL;
    TipoApontador antigoPrimeiro = Lista->Primeiro->Prox;

    while (atual != NULL) {
        temp = atual->Ant;
        atual->Ant = atual->Prox;
        atual->Prox = temp;
        atual = atual->Ant; 
    }

    if (temp != NULL && temp->Ant != NULL) {
        Lista->Primeiro->Prox = temp->Ant;
        Lista->Primeiro->Prox->Ant = Lista->Primeiro;
    }

    Lista->Ultimo = antigoPrimeiro;
    if (Lista->Ultimo != NULL) {
        Lista->Ultimo->Prox = NULL;
    }
}
