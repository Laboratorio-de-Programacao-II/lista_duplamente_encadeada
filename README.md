## Enunciado

O repositório contém a estrutura de uma lista **duplamente encadeada** com célula cabeça em C, organizada em três arquivos:

- `lista.h` — declaração dos tipos e assinaturas de todas as funções
- `lista.c` — implementação das funções (todas a implementar)
- `main.c` — programa principal que lê comandos e testa a lista

A diferença fundamental em relação à lista simplesmente encadeada é que cada célula possui dois ponteiros: `Prox` (próximo) e `Ant` (anterior), permitindo percorrer a lista nos dois sentidos.

```
 cab       nó1           nó2           nó3
┌────┐   ┌──────────┐   ┌──────────┐   ┌──────────┐
│NULL│◄──│Ant  Prox │◄──│Ant  Prox │◄──│Ant  Prox │──► NULL
│    │──►│    10    │──►│    20    │──►│    30    │
└────┘   └──────────┘   └──────────┘   └──────────┘
```

Sua tarefa é implementar **todas** as funções em `lista.c`:

```c
void FLVazia(TipoLista *Lista);
int  Vazia(TipoLista Lista);
void Insere(TipoItem x, TipoLista *Lista);
void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item);
void Imprime(TipoLista Lista);
void Inverte(TipoLista *Lista);
```

### Descrição das funções

**`FLVazia`** — Aloca a célula cabeça e inicializa `Primeiro` e `Ultimo` apontando para ela. Os ponteiros `Ant` e `Prox` da cabeça devem ser `NULL`.

**`Vazia`** — Retorna 1 se a lista não possui elementos reais, isto é, se `Primeiro == Ultimo`.

**`Insere`** — Insere `x` no final da lista. A nova célula deve ter seu `Ant` apontando para o atual `Ultimo` e `Prox` igual a `NULL`. Atualize `Ultimo`.

**`Retira`** — Remove o nó apontado diretamente por `p` da lista e devolve seu item em `*Item`. Como cada nó conhece seu anterior (`p->Ant`), não é necessário percorrer a lista — a operação é O(1). Atualize `Ultimo` se o nó removido for o último.

**`Imprime`** — Percorre a lista a partir do primeiro nó real (após a cabeça) e imprime cada elemento em uma linha.

**`Inverte`** — Inverte a ordem dos elementos no próprio encadeamento, trocando os ponteiros `Ant` e `Prox` de cada nó real. Reconecte a cabeça ao novo primeiro elemento e atualize `Ultimo`.

---

### Questões de análise

Considere `n` o número de elementos na lista.

1. Qual a complexidade de `Retira` na lista duplamente encadeada? Compare com `Retira` na lista simplesmente encadeada do laboratório anterior e explique a diferença.
2. Qual a complexidade de `Inverte`? Justifique.
3. A lista duplamente encadeada usa mais memória por elemento do que a simplesmente encadeada. Quanto a mais (em bytes) por nó, considerando ponteiros de 8 bytes? Em que situações esse custo é justificado?


### Entrada

A entrada é uma sequência de comandos, um por linha, lidos até o fim do arquivo:

| Comando | Argumento | Ação |
| :------ | :-------- | :--- |
| `i X`   | inteiro X | Insere X no final da lista |
| `r X`   | inteiro X | Busca X na lista e o retira |
| `inv`   | —         | Inverte a lista |
| `imp`   | —         | Imprime todos os elementos |

### Saída

Apenas os comandos `r` e `imp` produzem saída:

- `r X` imprime `retirado: X\n` se encontrado, ou `nao encontrado: X\n` caso contrário.
- `imp` imprime cada elemento em uma linha separada, na ordem em que estão na lista.

### Exemplos de entrada e saída

| Entrada | Saída |
| :--- | :--- |
| i 10<br>i 20<br>i 30<br>imp | 10<br>20<br>30 |
| i 10<br>i 20<br>i 30<br>r 10<br>imp<br>r 30<br>imp | retirado: 10<br>20<br>30<br>retirado: 30<br>20 |
| i 1<br>i 2<br>i 3<br>i 4<br>i 5<br>inv<br>imp | 5<br>4<br>3<br>2<br>1 |

---

### Arquivos editáveis (edição de outros arquivos resultará em nota 0)
- `lista.c`

### Notas
- Você pode usar qualquer ferramenta offline do computador para editar e compilar seu código
- Não é permitido acessar qualquer página ou ferramenta de Inteligência Artificial para realizar o exercício
- Compile com `make` e teste com `make test`
