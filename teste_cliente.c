#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_NOME 500
#define MAX_TELEFONE 20
#define MAX_ENDERECO 50
#define MAX_PONTOS 2

time_t dataAtual; // Variável global para armazenar a data e hora atuais

struct Cliente {
    char nomecomp[MAX_NOME];
    char telefone[MAX_TELEFONE];
    char endereco[MAX_ENDERECO];
    int pagamento_dia;
    char pontos[MAX_PONTOS];
    char data_cadastro[20];
    char data_vencimento[20];
};

typedef struct Cliente Cliente;

void calcularDataVencimento(Cliente *cliente) {
    struct tm tm_cadastro;
    strptime(cliente->data_cadastro, "%Y-%m-%d %H:%M:%S", &tm_cadastro);

    // Adiciona 1 mês à data de cadastro
    tm_cadastro.tm_mon += 1;

    // Normaliza a data para corrigir possíveis transbordamentos
    mktime(&tm_cadastro);

    // Define o dia de pagamento
    tm_cadastro.tm_mday = cliente->pagamento_dia;

    // Calcula o tempo Unix para a data de vencimento
    time_t t_vencimento = mktime(&tm_cadastro);

    struct tm *tm_vencimento = localtime(&t_vencimento);

    // Formata a data de vencimento
    strftime(cliente->data_vencimento, sizeof(cliente->data_vencimento), "%d/%m/%Y", tm_vencimento);
}

void cadastrarCliente(Cliente *cliente) {
    setbuf(stdin, NULL);
    printf("Digite o nome completo: ");
    if (fgets(cliente->nomecomp, sizeof(cliente->nomecomp), stdin) == NULL) {
        perror("Erro ao ler nome completo");
        exit(1);
    }

    printf("Digite o telefone: ");
    if (fgets(cliente->telefone, sizeof(cliente->telefone), stdin) == NULL) {
        perror("Erro ao ler telefone");
        exit(1);
    }

    printf("Digite o endereço: ");
    if (fgets(cliente->endereco, sizeof(cliente->endereco), stdin) == NULL) {
        perror("Erro ao ler endereço");
        exit(1);
    }

    printf("Digite o dia de pagamento (número): ");
    if (scanf("%d", &cliente->pagamento_dia) != 1) {
        perror("Erro ao ler dia de pagamento");
        exit(1);
    }

    printf("Digite a quantidade de pontos: ");
    if (scanf("%s", cliente->pontos) != 1) {
        perror("Erro ao ler pontos");
        exit(1);
    }

    time(&dataAtual); // Atualiza a variável global dataAtual com a data e hora atuais
    struct tm *tm_info;
    tm_info = localtime(&dataAtual);
    strftime(cliente->data_cadastro, sizeof(cliente->data_cadastro), "%Y-%m-%d %H:%M:%S", tm_info);
    calcularDataVencimento(cliente);
}

void criarPastaCliente(const char *nomeCliente) {
    char pasta[100];
    snprintf(pasta, sizeof(pasta), "clientes/%s", nomeCliente);

    if (mkdir(pasta, 0777) == -1) {
        perror("Erro ao criar a pasta do cliente");
        exit(1);
    }
}

void salvarCliente(const char *nomeCliente, const Cliente *cliente) {
    char caminho[100];
    snprintf(caminho, sizeof(caminho), "clientes/%s/info.txt", nomeCliente);

    FILE *arq = fopen(caminho, "w");
    if (arq == NULL) {
        perror("Erro ao criar o arquivo do cliente");
        exit(1);
    }

    fprintf(arq, "Nome: %s", cliente->nomecomp);
    fprintf(arq, "Telefone: %s", cliente->telefone);
    fprintf(arq, "Endereço: %s", cliente->endereco);
    fprintf(arq, "Dia de Pagamento: %d\n", cliente->pagamento_dia);
    fprintf(arq, "Pontos: %s\n", cliente->pontos);
    fprintf(arq, "Data de Cadastro: %s\n", cliente->data_cadastro);
    fprintf(arq, "Data de Vencimento: %s", cliente->data_vencimento);

    fclose(arq);
}

void listarClientesPorDiaPagamento(int diaPagamento) {
    DIR *dir;
    struct dirent *ent;

    printf("\nClientes com dia de pagamento no dia %d:\n\n", diaPagamento);

    if ((dir = opendir("\nclientes")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR) {
                if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                    char nomeCliente[MAX_NOME];
                    snprintf(nomeCliente, sizeof(nomeCliente), "clientes/%s/info.txt", ent->d_name);
                    FILE *arq = fopen(nomeCliente, "r");

                    if (arq != NULL) {
                        char linha[500];

                        while (fgets(linha, sizeof(linha), arq)) {
                            if (strncmp(linha, "Dia de Pagamento: ", 18) == 0) {
                                int dia;
                                if (sscanf(&linha[18], "%d", &dia) == 1 && dia == diaPagamento) {
                                    printf("Cliente: %s\n", ent->d_name);
                                    break;
                                }
                            }
                        }

                        fclose(arq);
                    }
                }
            }
        }

        closedir(dir);
    }
}


void listarClientes() {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    if ((dir = opendir("clientes")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_DIR) {
                if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                    count++;
                    printf("\n%d - Cliente: %s", count, ent->d_name);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Erro ao listar clientes");
        exit(1);
    }
}

void mostrarDadosCliente(const char *nomeCliente) {
    char caminho[100];
    snprintf(caminho, sizeof(caminho), "clientes/%s/info.txt", nomeCliente);

    FILE *arq = fopen(caminho, "r");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo do cliente");
        return;
    }

    char linha[500];
    printf("\n");
    while (fgets(linha, sizeof(linha), arq)) {
        printf("%s", linha);
    }
    printf("\n\n");

    fclose(arq);
}

void renovarCliente(const char *nomeCliente) {
    char caminho[100];
    snprintf(caminho, sizeof(caminho), "clientes/%s/info.txt", nomeCliente);

    FILE *arq = fopen(caminho, "r+");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo do cliente");
        return;
    }

    Cliente cliente;
    char linha[500];
    bool encontrou = false;

    while (fgets(linha, sizeof(linha), arq)) {
        if (strncmp(linha, "Data de Vencimento: ", 19) == 0) {
            encontrou = true;
            // Obter a data de vencimento atual
            struct tm tm_vencimento;
            strptime(&linha[20], "%d/%m/%Y", &tm_vencimento);

            printf("Digite a nova data de vencimento (dd/mm/yyyy): ");
            char novaData[20];
            if (scanf("%s", novaData) != 1) {
                perror("Erro ao ler a nova data de vencimento");
                exit(1);
            }

            // Converter a nova data em uma estrutura tm
            strptime(novaData, "%d/%m/%Y", &tm_vencimento);

            // Atualizar a linha da Data de Vencimento
            strftime(cliente.data_vencimento, sizeof(cliente.data_vencimento), "%d/%m/%Y", &tm_vencimento);
            fseek(arq, -strlen(linha), SEEK_CUR);
            fprintf(arq, "Data de Vencimento: %s\n", cliente.data_vencimento);
            break;
        }
    }

    if (!encontrou) {
        printf("Data de vencimento não encontrada no arquivo.\n");
    }

    fclose(arq);
}

int main() {
    mkdir("clientes", 0777);

    int selecao;

    while (true) {
        printf("1 - Cadastro\n2 - Mostrar clientes e seus dados\n3 - Renovar manualmente\n4 - Vencimentos\n5 - Sair\nSelecione uma opção: ");
        if (scanf("%d", &selecao) != 1) {
            perror("Erro ao ler a seleção");
            exit(1);
        }

        switch (selecao) {
            case 1: {
                Cliente cliente;
                cadastrarCliente(&cliente);
                criarPastaCliente(cliente.nomecomp);
                salvarCliente(cliente.nomecomp, &cliente);
                printf("Cliente Cadastrado com Sucesso\n\n");
                break;
            }
            case 2: {
                listarClientes();
                int numeroCliente;
                printf("\nDigite o número do cliente que deseja ver: ");
                if (scanf("%d", &numeroCliente) != 1) {
                    perror("Erro ao ler o número do cliente");
                    exit(1);
                }

                DIR *dir;
                struct dirent *ent;
                int count = 0;
                char nomeClienteSelecionado[MAX_NOME];

                if ((dir = opendir("clientes")) != NULL) {
                    while ((ent = readdir(dir)) != NULL) {
                        if (ent->d_type == DT_DIR) {
                            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                                count++;
                                if (count == numeroCliente) {
                                    strncpy(nomeClienteSelecionado, ent->d_name, sizeof(nomeClienteSelecionado));
                                }
                            }
                        }
                    }
                    closedir(dir);
                }

                if (numeroCliente >= 1 && numeroCliente <= count) {
                    mostrarDadosCliente(nomeClienteSelecionado);
                } else {
                    printf("Número de cliente inválido.\n");
                }
                break;
            }
            case 3: {
                listarClientes();
                int numeroCliente;
                printf("Digite o número do cliente que deseja renovar manualmente: ");
                if (scanf("%d", &numeroCliente) != 1) {
                    perror("Erro ao ler o número do cliente");
                    exit(1);
                }

                DIR *dir;
                struct dirent *ent;
                int count = 0;
                char nomeClienteSelecionado[MAX_NOME];

                if ((dir = opendir("clientes")) != NULL) {
                    while ((ent = readdir(dir)) != NULL) {
                        if (ent->d_type == DT_DIR) {
                            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                                count++;
                                if (count == numeroCliente) {
                                    strncpy(nomeClienteSelecionado, ent->d_name, sizeof(nomeClienteSelecionado));
                                }
                            }
                        }
                    }
                    closedir(dir);
                }

                if (numeroCliente >= 1 && numeroCliente <= count) {
                    renovarCliente(nomeClienteSelecionado);
                    printf("Cliente renovado com sucesso.\n\n");
                } else {
                    printf("Número de cliente inválido.\n");
                }
                break;
            }
            case 4: {
                int diaPagamento;
                printf("Digite o dia de pagamento (05, 10, 15, 20, 25 ou 30): ");
                if (scanf("%d", &diaPagamento) != 1) {
                    perror("Erro ao ler o dia de pagamento");
                    exit(1);
                }
                listarClientesPorDiaPagamento(diaPagamento);
                break;
            }
            case 5:
                return 0;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    }

    return 0;
}
