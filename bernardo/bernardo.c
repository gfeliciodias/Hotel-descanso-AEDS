#include <stdio.h>
#include <string.h>

typedef struct {
    int codigo;
    char nome[50];
    char endereco[80];
    char telefone[20];
} Cliente;

typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
    char cargo[30];
    float salario;
} Funcionario;

typedef struct {
    int numero;
    int capacidade;
    float valor;
    char status;
} Quarto;

int gerarCodigoCliente(){
    FILE *f = fopen("clientes.dat", "rb");
    if(!f) return 1;
    Cliente c;
    int ultimo = 0;
    while(fread(&c, sizeof(Cliente), 1, f)){
        ultimo = c.codigo;
    }
    fclose(f);
    return ultimo + 1;
}

int gerarCodigoFuncionario(){
    FILE *f = fopen("funcionarios.dat", "rb");
    if(!f) return 1;
    Funcionario x;
    int ultimo = 0;
    while(fread(&x, sizeof(Funcionario), 1, f)){
        ultimo = x.codigo;
    }
    fclose(f);
    return ultimo + 1;
}

void cadastrarCliente(){
    Cliente c;
    c.codigo = gerarCodigoCliente();

    printf("Codigo: %d\n", c.codigo);
    getchar();
    printf("Nome: ");
    fgets(c.nome, 50, stdin);
    printf("Endereco: ");
    fgets(c.endereco, 80, stdin);
    printf("Telefone: ");
    fgets(c.telefone, 20, stdin);

    FILE *f = fopen("clientes.dat", "ab");
    fwrite(&c, sizeof(Cliente), 1, f);
    fclose(f);

    printf("Cliente cadastrado!\n");
}

void cadastrarFuncionario(){
    Funcionario f;
    f.codigo = gerarCodigoFuncionario();

    printf("Codigo: %d\n", f.codigo);
    getchar();
    printf("Nome: ");
    fgets(f.nome, 50, stdin);
    printf("Telefone: ");
    fgets(f.telefone, 20, stdin);
    printf("Cargo: ");
    fgets(f.cargo, 30, stdin);
    printf("Salario: ");
    scanf("%f", &f.salario);

    FILE *arq = fopen("funcionarios.dat", "ab");
    fwrite(&f, sizeof(Funcionario), 1, arq);
    fclose(arq);

    printf("Funcionario cadastrado!\n");
}

void cadastrarQuarto(){
    Quarto q;

    printf("Numero do quarto: ");
    scanf("%d", &q.numero);

    printf("Capacidade: ");
    scanf("%d", &q.capacidade);

    printf("Valor diaria: ");
    scanf("%f", &q.valor);

    q.status = 'D';

    FILE *fq = fopen("quartos.dat", "ab");
    fwrite(&q, sizeof(Quarto), 1, fq);
    fclose(fq);

    printf("Quarto cadastrado!\n");
}
