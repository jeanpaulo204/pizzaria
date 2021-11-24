#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<locale.h>

using namespace std;

/**
criando estrutura de Produto
*/

struct Produto {
    int codigo;
    char nome[50];
    char cpf[50];
    char pizza[50];
    float preco;
    int estoque;
};


/**
variavel do tipo constante para total de produtos que ser�o cadastrados
coloquei 5 para testes

*/
const int totalProd = 10;
//criando um vetor de structs do tamanho totalProd(vari�vel acima)
struct Produto prod[totalProd];
//definindo o indice do vetor
int indice = 0;
//variavel de controle de arquivo
FILE *pont_arq;

///fun��o cabe�alho que recebe um array de char para escrever esse texto
void cabecalho(char texto[]){
    system("cls");
    cout << "***** Pizzaria VivaLaVida *****\n";
    cout << "***** "<<texto<<" *****\n";
}

//m�todo que pergunta ao usu�rio as informa��es do produto
void cadastrar(){
    if(indice >= totalProd){
        cout << "N�o � poss�vel cadastrar mais Clientes!";
        system("pause");
        return;
    }
    int codigo;
    int vezes = 0;
    cabecalho("Cliente");
    cout << "Cadastrando o Cliente no indice "<< indice<<"\n";
    do {
        vezes = 0;
        cout << "Digite o c�digo: ";
        cin >> codigo;
        for(int i = 0; i<indice; i++){
            if(prod[i].codigo == codigo){
                vezes++;
            }
        }
        if(vezes > 0){
            cout << "C�digo inv�lido\n";
        }
    }while(vezes > 0);

    prod[indice].codigo = codigo;
    cout << "Digite o Nome: ";
    cin >> prod[indice].nome;

    cout << "Digite o Cpf Do Cliente: ";
    cin >> prod[indice].cpf;


    cout << "Pizza: Calabresa , Frango , Portuguesa: ";
    cin >> prod[indice].pizza;

    cout << "Digite O Pre�o: ";
    cin >> prod[indice].preco;


    cout << "Digite o Estoque: ";
    cin >> prod[indice].estoque;
}

void menu(){
    cabecalho("Menu de Op��es");
    cout << "1 - Cadastrar Cliente\n";
    cout << "2 - Imprimir dados dos produtos\n";
    cout << "3 - Exibir o estoque do produto por C�digo\n";
    cout << "4 - Imprimir nome dos desenvolvedores\n";
    cout << "5 - Alterar Produto\n";
    cout << "6 - Excluir Produto\n";
    cout << "7 - Gravar Banco de Dados\n";
    cout << "8 - Recuperar Banco de Dados\n";
    cout << "0 - Sair\n";
}

//fun��o que imprimi
void imprimir(){
    cabecalho("Impress�o dos produtos em tela!!");
    for(int i = 0; i < indice; i++){
        cout << prod[i].codigo<<" - "<<prod[i].nome<<"\n";
    }
    if(indice < 1){
        cout << "N�o existem produtos cadastrados!";
    }
    system("pause");
}

//fun��o que pergunta o c�digo e mostra o estoque
void exibeEstoque(){
    int codi;
    bool achou = false;
    cabecalho("Estoque do produto por C�digo");
    cout << "Digite o c�digo: ";
    cin >> codi;


//percorre todos os produtos verificando se o c�digo digitado � igual ao c�digo do produto
    for(int i = 0; i < totalProd; i++){
        if(codi == prod[i].codigo){
            //se caso for igual, achou recebe true e exibe o estoque
            cout << "Estoque do produto = "<<prod[i].estoque<<"\n";
            achou = true;
        }
    }
    if(!achou){
        cout << "Nenhum produto encontrado com o c�digo "<< codi<< "\n";
    }
    system("pause");
}

void sobre(){
    cabecalho("Sobre o desenvolvimento");
    cout << "Desenvolvimento com codigo em C++ - 2021\n";
    system("pause");
}

void alterar(){
    int codi;
    bool achou = false;
    cabecalho("Altera��o de Produto");
    cout << "Digite o c�digo: ";
    cin >> codi;
//percorre todos os produtos verificando se o c�digo digitado � igual ao c�digo do produto
    for(int i = 0; i < totalProd; i++){
        if(codi == prod[i].codigo){
            //se caso for igual, achou recebe true e exibe os dados do produto
            //e pergunta o novo nome do produto
            //e altera o indice = i, pois foi o indice que encontrou o c�digo
            cout << "Codigo "<<prod[i].codigo<<"\n";
            cout << "Nome "<<prod[i].nome<<"\n";
            cout << "CPF "<<prod[i].cpf<<"\n";
            cout << "Pizza "<<prod[i].pizza<<"\n";
            cout << "Pre�o "<<prod[i].preco<<"\n";
            cout << "Estoque "<<prod[i].estoque<<"\n";
            cout << "Digite os dados para alterar o nome\n";
            cout << "Nome: ";
            cin >> prod[i].nome;
            achou = true;
        }
    }
    if(!achou){
        cout << "Nenhum produto encontrado com o c�digo "<< codi<< "\n";
    }
    system("pause");
}

void excluir(){
    int codi;
    bool achou = false;
    char confirma;
    cabecalho("Exclus�o de Produto");
    cout << "Digite o c�digo: ";
    cin >> codi;
//percorre todos os produtos verificando se o c�digo digitado � igual ao c�digo do produto
    for(int i = 0; i < totalProd; i++){
        if(codi == prod[i].codigo){
            //se caso for igual, achou recebe true e exibe os dados do produto
            //e exibe as informa��es do produto e pergunta se deseja realmente excluir
            //se for confirmado, o programa vai substituindo as informa��es do vetor da frente para o de tr�s
            //assim excluindo as informa��es do produto selecionado
            cout << "Codigo "<<prod[i].codigo<<"\n";
            cout << "Nome "<<prod[i].nome<<"\n";
            cout << "CPF "<<prod[i].cpf<<"\n";
            cout << "Pizza "<<prod[i].pizza<<"\n";
            cout << "Pre�o "<<prod[i].preco<<"\n";
            cout << "Estoque "<<prod[i].estoque<<"\n";
            cout << "Deseja realmente excluir (s/n)\n";
            cin >> confirma;
            switch(confirma){
                case 's':
                    for(int j = i; j < indice-1; j++){
                        prod[j] = prod[j+1];
                    }
                    indice--;
                    break;
            }
            achou = true;
        }
    }
    if(!achou){
        cout << "Nenhum produto encontrado com o c�digo "<< codi<< "\n";
    }
    system("pause");
}

/*
abre um arquivo para grava��o ou leitura
recebe o nome do arquivo, e o tipo de leitura
*/
void abrirArquivo(char nome[], char tipo[]){
    pont_arq = fopen(nome, tipo);
    if(pont_arq == NULL){
        cout << "Erro ao abrir arquivo!\n";
    }
}

void gravarArquivoProduto(){
    //comando para abrir o arquivo em modo de grava��o
    abrirArquivo("bdProduto.txt", "w");
    for(int i = 0; i < indice; i++){
        //gravando registros
        fwrite(&prod[i], sizeof(struct Produto), 1, pont_arq);
    }
    fclose(pont_arq);//fechando o arquivo
    cout << "Arquivo gravado com sucesso!\n";
    system("pause");
}

void lerArquivoProduto(){
    abrirArquivo("bdProduto.txt", "r");
    int contador = 0;
    do{
        Produto produto;
        size_t r = fread(&produto, sizeof(struct Produto), 1, pont_arq);
        if(r < 1){
            break;//caso o retorno de r seja falso ou nulo para a estrutura de repeti��o
        }else{
            prod[contador++] = produto;
        }

    }while(!feof(pont_arq));//at� que existam registros
    fclose(pont_arq);//fechando arquivo
    indice = contador;//indice recebe o tanto de produtos lidos
    cout << "Arquivo recuperado com sucesso!\n";
    system("pause");
}

void gravarTodosArquivos(){
    gravarArquivoProduto();
    //gravarArquivoMedico();
}
void recuperarTodosArquivos(){
    lerArquivoProduto();
    //lerArquivoMedico();
}

int main(){
    int opcao;
    setlocale(LC_ALL, "");
    do {
        menu();
        cin >> opcao;
        switch(opcao){
        case 1:
            cadastrar();
            if(indice < totalProd){
                indice++;
            }
            break;
        case 2:
            imprimir();
            break;
        case 3:
            exibeEstoque();
            break;
        case 4:
            sobre();
            break;
        case 5:
            alterar();
            break;
        case 6:
            excluir();
            break;
        case 7:
            gravarTodosArquivos();
            break;
        case 8:
            recuperarTodosArquivos();
            break;
        case 0:
            cout << "Obrigado pela preferencia!\n";
            break;
        default:
            cout << "Op��o inv�lida!";
            system("pause");
            break;
        }
    }while(opcao != 0);


    return 0;
}
