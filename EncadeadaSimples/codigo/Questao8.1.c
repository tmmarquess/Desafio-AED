#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Criando a Struct que armazena os dados de um produto
typedef struct produto
{
    char nome[30];
    char genero[30];
    float preco;
    int quantidade;
} produto;

// Criando a Struct que armazena uma lista de produtos
typedef struct ListaDeCompras
{
    produto produto;             // Armazena o produto
    struct ListaDeCompras *prox; // Aponta para o próximo produto da lista
} ListaDeCompras;

/* Função para criar a lista. É passado como parâmetro o primeiro
 *  produto a ser armazenado na lista. Essa função retorna um
 *  ponteiro do tipo ListaDeCompras com o primeiro valor inicializado.
 */
ListaDeCompras *criarItem(produto prod)
{
    ListaDeCompras *lista = (ListaDeCompras *)malloc(sizeof(ListaDeCompras));
    lista->produto = prod;
    lista->prox = NULL;
    return lista;
}

bool vazia(ListaDeCompras *primeiroItem)
{
    return primeiroItem == NULL;
}

/* Função para inserir um item no fim da lista, recebe como parâmetro o primeiro
 *  item da lista em que o produto será adicionado, e o produto a se adicionar
 */
void inserir(ListaDeCompras *primeiroItem, produto prod)
{

    if (vazia(primeiroItem))
    {
        printf("Lista nao iniciada!\n");
        return;
    }

    ListaDeCompras *novoItem = criarItem(prod);
    ListaDeCompras *atual = primeiroItem;

    while (atual->prox != NULL)
        atual = atual->prox;

    atual->prox = novoItem;
}

/* Função para inserir um item no início da lista, recebe como parâmetro o primeiro
 *  item da lista em que o produto será adicionado, e o produto a se adicionar
 */
ListaDeCompras *inserirNoInicio(ListaDeCompras *primeiroItem, produto prod)
{

    ListaDeCompras *novoItem = criarItem(prod);

    if (primeiroItem != NULL)
    {
        novoItem->prox = primeiroItem;
    }

    return novoItem;
}

/* Função para inserir um item no início da lista, recebe como parâmetro o primeiro
 *  item da lista em que o produto será adicionado, o produto a se adicionar e o
 *  o index em que se deseja adicionar o produto
 */
ListaDeCompras *inserirNoMeio(ListaDeCompras *primeiroItem, produto prod, int index)
{

    int qntDeItens = 0;
    ListaDeCompras *atual = primeiroItem;
    // Verifica a quantidade de itens na lista
    while (atual != NULL)
    {
        qntDeItens += 1;
        atual = atual->prox;
    }
    atual = primeiroItem;

    // Se o primeiro item for nulo, ele cria um novo item
    if (vazia(primeiroItem))
    {
        primeiroItem = criarItem(prod);
    }
    else
    {
        // Se o index for maior que a qnt de itens na lista, insere o item novo no final
        if (index >= qntDeItens)
        {
            inserir(primeiroItem, prod);
        }
        else
        {
            // se o index for igual a 0, insere o novo item no inicio
            if (index == 0)
            {
                primeiroItem = inserirNoInicio(primeiroItem, prod);
            }
            else
            {
                // Se o index não for negativo, ele insere na posição escolhida
                if (index > 0)
                {
                    ListaDeCompras *novoItem = criarItem(prod);

                    for (int i = 0; i < index - 1; i++)
                    {
                        atual = atual->prox;
                    }
                    novoItem->prox = atual->prox;
                    atual->prox = novoItem;
                }
            }
        }
    }
    return primeiroItem;
}

/* Função para retirar itens da lista, recebe como parâmetro o primeiro
 *  item da lista a se retirar o item, e o index do item a ser retirado
 */
ListaDeCompras *retirar(ListaDeCompras *primeiroItem, int index)
{

    if (vazia(primeiroItem))
    {
        return primeiroItem;
    }

    int qntDeItens = 0;
    ListaDeCompras *atual = primeiroItem;
    // Verifica a quantidade de itens na lista
    while (atual != NULL)
    {
        qntDeItens += 1;
        atual = atual->prox;
    }
    atual = primeiroItem;

    // verifica se o index a se retirar está contido na lista
    if (index < qntDeItens && index >= 0)
    {
        if (index == 0)
        {
            ListaDeCompras *aux = primeiroItem;
            primeiroItem = primeiroItem->prox;
            free(aux);
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                atual = atual->prox;
            }
            ListaDeCompras *aux = atual->prox;
            if (aux == NULL)
            {
                atual->prox = aux;
            }
            else
            {
                atual->prox = aux->prox;
            }
            free(aux);
        }
    }
    return primeiroItem;
}

// Imprime no console todos os itens cadastrados na lista recebida por parametro
void imprimeLista(ListaDeCompras *primeiroItem)
{
    if (primeiroItem == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        ListaDeCompras *atual = primeiroItem;
        while (atual != NULL)
        {
            printf("Nome: %s\n", atual->produto.nome);
            printf("Genero: %s\n", atual->produto.genero);
            printf("Quantidade: %d\n", atual->produto.quantidade);
            printf("Preco: %.2f\n", atual->produto.preco);
            printf("==========================================\n");

            atual = atual->prox;
        }
    }
}