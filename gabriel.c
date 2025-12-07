typedef struct {
    int codigo;
    int codCliente;
    int numQuarto;
    int dias;
    float valorTotal;
    char status;   // A = ativa, F = finalizada
} Estadia;

int gerarCodigoEstadia(){
    FILE *f = fopen("estadias.dat", "rb");
    if(!f) return 1;

    Estadia e;
    int ultimo = 0;

    while(fread(&e, sizeof(Estadia), 1, f)){
        ultimo = e.codigo;
    }
    fclose(f);

    return ultimo + 1;
}

void cadastrarEstadia(){
    Estadia e;
    Cliente c;
    Quarto q;
    int achouCliente = 0, achouQuarto = 0;

    e.codigo = gerarCodigoEstadia();
    printf("Codigo da estadia: %d\n", e.codigo);

    printf("Codigo do cliente: ");
    scanf("%d", &e.codCliente);

    FILE *fc = fopen("clientes.dat", "rb");
    while(fread(&c, sizeof(Cliente), 1, fc)){
        if(c.codigo == e.codCliente){
            achouCliente = 1;
            break;
        }
    }
    fclose(fc);

    if(!achouCliente){
        printf("Cliente nao encontrado!\n");
        return;
    }

    printf("Numero do quarto: ");
    scanf("%d", &e.numQuarto);

    FILE *fq = fopen("quartos.dat", "rb");
    while(fread(&q, sizeof(Quarto), 1, fq)){
        if(q.numero == e.numQuarto){
            achouQuarto = 1;
            break;
        }
    }
    fclose(fq);

    if(!achouQuarto){
        printf("Quarto nao encontrado!\n");
        return;
    }

    if(q.status == 'O'){
        printf("Quarto ocupado!\n");
        return;
    }

    printf("Dias de estadia: ");
    scanf("%d", &e.dias);

    e.valorTotal = e.dias * q.valor;
    e.status = 'A';

    FILE *fe = fopen("estadias.dat", "ab");
    fwrite(&e, sizeof(Estadia), 1, fe);
    fclose(fe);

    fq = fopen("quartos.dat", "rb+");
    while(fread(&q, sizeof(Quarto), 1, fq)){
        if(q.numero == e.numQuarto){
            q.status = 'O';
            fseek(fq, -sizeof(Quarto), SEEK_CUR);
            fwrite(&q, sizeof(Quarto), 1, fq);
            break;
        }
    }
    fclose(fq);

    printf("Estadia cadastrada com sucesso!\n");
}

void finalizarEstadia(){
    int cod;
    Estadia e;
    Quarto q;
    int achou = 0;

    printf("Codigo da estadia: ");
    scanf("%d", &cod);

    FILE *fe = fopen("estadias.dat", "rb+");
    while(fread(&e, sizeof(Estadia), 1, fe)){
        if(e.codigo == cod && e.status == 'A'){
            achou = 1;
            e.status = 'F';
            fseek(fe, -sizeof(Estadia), SEEK_CUR);
            fwrite(&e, sizeof(Estadia), 1, fe);
            break;
        }
    }
    fclose(fe);

    if(!achou){
        printf("Estadia nao encontrada ou ja finalizada.\n");
        return;
    }

    FILE *fq = fopen("quartos.dat", "rb+");
    while(fread(&q, sizeof(Quarto), 1, fq)){
        if(q.numero == e.numQuarto){
            q.status = 'D';
            fseek(fq, -sizeof(Quarto), SEEK_CUR);
            fwrite(&q, sizeof(Quarto), 1, fq);
            break;
        }
    }
    fclose(fq);

    printf("Estadia finalizada com sucesso!\n");
}
void pesquisarCliente(){
    int cod;
    Cliente c;
    int achou = 0;

    printf("Codigo do cliente: ");
    scanf("%d", &cod);

    FILE *f = fopen("clientes.dat", "rb");
    while(fread(&c, sizeof(Cliente), 1, f)){
        if(c.codigo == cod){
            achou = 1;
            printf("\n--- Cliente encontrado ---\n");
            printf("Codigo: %d\n", c.codigo);
            printf("Nome: %s", c.nome);
            printf("Endereco: %s", c.endereco);
            printf("Telefone: %s", c.telefone);
            break;
        }
    }
    fclose(f);

    if(!achou)
        printf("Cliente nao encontrado!\n");
}
