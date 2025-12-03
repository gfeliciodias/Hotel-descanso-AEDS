#include <stdio.h>
#include <string.h>

int main(){
    int op;

    //MENU

    //menu a ser impreco no terminal para informar as opcoes 
    do{
        printf("\n=== HOTEL DESCANSO GARANTIDO ===\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar funcionario\n");
        printf("3 - Cadastrar quarto\n");
        printf("4 - Cadastrar estadia\n");
        printf("5 - Baixar estadia\n");
        printf("6 - Pesquisar cliente\n");
        printf("7 - Pesquisar funcionario\n");
        printf("8 - Mostrar estadias de cliente\n");
        printf("9 - Pontos de fidelidade\n");
        printf("0 - Sair\nOpcao: ");

        scanf("%d", &op);

        //redirecionamento de acordo com a opcao que o usuario escolher 
        switch(op){
            //cadastrar novo cliente
            case 1: cadastrarCliente(); break;
            //cadastrar novo funcionario
            case 2: cadastrarFuncionario(); break;
            //cadastrar novo quarto
            case 3: cadastrarQuarto(); break;
            //cadastrar nova estadia
            case 4: cadastrarEstadia(); break;
            //finalizar estadia(dar baixa)
            case 5: finalizarEstadia(); break;
            //pesquisar cliente(quando já existente)
            case 6: pesquisarCliente(); break;
            //pesquisar funcionario(quando ja existente)
            case 7: pesquisarFuncionario(); break;
            //pesquisar estadia utilizando das de cliente
            case 8: estadiasPorCliente(); break;
            //verificar pontos de fidelidade(usando dados de cliente)
            case 9: pontosFidelidade(); break;
        }

    } while(op != 0);

    return 0;
}