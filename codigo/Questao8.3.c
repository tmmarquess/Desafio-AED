#include "Questao8.1.c"

int main()
{
    // Criando a lista e iniciando ela com o tamanho definido pelo usuário
    ListaDeCompras *lista;
    int tamanho;
    printf("Quantos produtos voce deseja na lista de compras? \n");
    scanf("%d", &tamanho);

    //iteração para adicionar a quantidade de itens solicitadas pelo usuário
    produto temporario;
    char temp[30];
    float preco;
    int qnt;
    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o nome do produto %d: ", i + 1);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados
        scanf("%s", temporario.nome);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados

        printf("Digite o genero do produto %d: ", i + 1);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados
        scanf("%s", temporario.genero);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados

        printf("Digite o preco unitario do produto %d: ", i + 1);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados
        scanf("%f", &temporario.preco);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados

        printf("Digite a quantidade que ira levar do produto %d: ", i + 1);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados
        scanf("%d", &temporario.quantidade);
        fflush(stdin); // limpando o buffer do teclado antes de ler dados

        if(i == 0){ // se for o primeiro item da lista, criamos ela
            lista = criarItem(temporario);
        }else{// se não for o primeiro item, adicionamos a lista
            inserir(lista, temporario);
        }
    }
    //Imprimindo na tela os produtos adicionados pelo usuário
    printf("\n");
    imprimeLista(lista);
}