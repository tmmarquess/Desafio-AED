#include "Questao8.1.c"

/* Função para imprimir os itens da lista (passada por parâmetro)
 *  que são compraveis com o valor recebido por parâmetro também
 */
void maisBaratosQue(ListaDeCompras *primeiroItem, float valor)
{
    ListaDeCompras *atual = primeiroItem;
    while (atual != NULL)
    {
        if (atual->produto.preco <= valor)
        {
            printf("Nome: %s\n", atual->produto.nome);
            printf("Genero: %s\n", atual->produto.genero);
            printf("Quantidade: %d\n", atual->produto.quantidade);
            printf("Preco: %.2f\n", atual->produto.preco);
            printf("==========================================\n");
        }
        atual = atual->prox;
    }
}

int main()
{
    // Adicionando um produto novo
    produto prodNovo;
    strcpy(prodNovo.nome, "Queijo");
    strcpy(prodNovo.genero, "Laticinio");
    prodNovo.preco = 3.50;
    prodNovo.quantidade = 1;

    // Criando a Lista e iniciando ela
    ListaDeCompras *primeiroItem;
    primeiroItem = criarItem(prodNovo);

    // Adicionando um produto novo
    strcpy(prodNovo.nome, "Laranja");
    strcpy(prodNovo.genero, "Frutas");
    prodNovo.preco = 5;
    prodNovo.quantidade = 10;

    inserir(primeiroItem, prodNovo);

    // Adicionando um produto novo
    strcpy(prodNovo.nome, "Maca");
    strcpy(prodNovo.genero, "Frutas");
    prodNovo.preco = 7;
    prodNovo.quantidade = 10;

    inserir(primeiroItem, prodNovo);

    // Adicionando um produto novo
    strcpy(prodNovo.nome, "Paprica");
    strcpy(prodNovo.genero, "temperos");
    prodNovo.preco = 1;
    prodNovo.quantidade = 3;

    inserir(primeiroItem, prodNovo);

    // imprimindo na tela os produtos mais baratos que o valor do parâmetro
    maisBaratosQue(primeiroItem, 6);
}