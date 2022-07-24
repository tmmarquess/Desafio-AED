#include "Questao8.1.c"

// divide a lista em outras a partir do gênero 
void separarPorGenero(ListaDeCompras *primeiroItem)
{
    // Verificando a quantidade de itens na lista
    int qntDeItens = 0;
    ListaDeCompras *atual = primeiroItem;
    while (atual != NULL)
    {
        qntDeItens += 1;
        atual = atual -> prox;
    }
    atual = primeiroItem;

    // Index da lista de generos
    int index = 0;
    // Criando o ponteiro da lista de generos para alocar dinamicamente o tamanho
    char **generos = NULL;
    // booleano pra controlar inserção dentro da lista de generos
    bool jaIncluido = false;

    //percorre todos os itens da lista de compras
    while (atual != NULL)
    {
        // percorre todos os itens da lista de generos
        for (int i = 0; i < index; i++)
        {
            // verifica se o genero ja está incluido na lista de generos
            if (!strcmp(atual -> produto.genero, generos[i]))
            {
                jaIncluido = true;
            }
        }
        // Se não tiver incluido, inclui o genero na lista de generos
        if (!jaIncluido)
        {
            if(generos == NULL){ //se a lista ainda não existe, cria ela
                generos = malloc(sizeof(char*));
            }else{
                generos = realloc(generos, sizeof(char*) * (index + 1));
            }
            generos[index] = malloc(sizeof(char) * 30); // aloca o tamanho da String
            strcpy(generos[index], atual -> produto.genero);
            index += 1; // incrementa o index da lista
        }
        jaIncluido = false;
        atual = atual -> prox;
    }
    atual = primeiroItem;

    // cria um vetor com as listas separadas
    ListaDeCompras **separadas = (ListaDeCompras**) malloc(sizeof(ListaDeCompras) * index);
    bool isFirst = true; //verifica se é o primeiro elemento adicionado na lista
    //percorre todos os gêneros
    for (int i = 0; i < index; i++)
    {
        // percorre a lista de produtos
        while (atual != NULL)
        {
            // verifica se o item da lista corresponde ao genero do index
            if (!strcmp(atual -> produto.genero, generos[i]))
            {
                if(isFirst){ // se for o primeiro item daquele genero, cria a lista
                    separadas[i] = criarItem(atual -> produto);
                    isFirst = false;
                }else{// se não for o primeiro item, apenas insere na lista
                    inserir(separadas[i], atual -> produto);
                }
            }
            atual = atual -> prox;
        }
        isFirst = true;
        atual = primeiroItem;
    }

    //percorre as listas separadas por genero
    for (int i = 0; i < index; i++)
    {
        printf("\nLista de %s:\n", generos[i]);
        atual = separadas[i];
        // percorre a lista do genero atual e imprime os itens dela
        while(atual != NULL)
        {
            printf("Nome: %s\n", atual -> produto.nome);
            printf("Genero: %s\n", atual -> produto.genero);
            printf("Quantidade: %d\n", atual -> produto.quantidade);
            printf("Preco: %.2f\n", atual -> produto.preco);
            printf("==========================================\n");

            atual = atual -> prox;
        }
    }
}

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

        if(i == 0){
            lista = criarItem(temporario);
        }else{
            inserir(lista, temporario);
        }
    }
    // imprime as listas separadas por gênero
    printf("\n");
    separarPorGenero(lista);
}