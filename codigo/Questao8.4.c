#include "Questao8.1.c"

/* função que retorna o subtotal a ser pago a partir
*  dos itens da lista passada como parâmetro
*/
float getTotal(ListaDeCompras *primeiroItem){
    float total = 0;
    ListaDeCompras *atual = primeiroItem;
    while(atual != NULL){
        total += atual -> produto.preco * atual -> produto.quantidade;
        atual = atual -> prox;
    }

    return total;
}

int main(){

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

    //imprimindo na tela os itens adicionados acima
    imprimeLista(primeiroItem);

    // imprimindo na tela o total a ser pago com base na lista
    printf("Subtotal = %.2f\n", getTotal(primeiroItem));
}