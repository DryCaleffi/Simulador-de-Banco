#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 10

typedef struct {
    char nome[50];
    int conta;
    float saldo;
} Cliente;

Cliente clientes[MAX_CLIENTES];
int numClientes = 0;

void cadastrarCliente() {
    if (numClientes < MAX_CLIENTES) {
        printf("Digite o nome do cliente: ");
        scanf("%s", clientes[numClientes].nome);
        clientes[numClientes].conta = numClientes + 1;
        clientes[numClientes].saldo = 0.0;
        numClientes++;
        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Limite máximo de clientes atingido!\n");
    }
}

void depositar() {
    int conta;
    float valor;

    printf("Digite o número da conta: ");
    scanf("%d", &conta);

    if (conta > 0 && conta <= numClientes) {
        printf("Digite o valor a ser depositado: ");
        scanf("%f", &valor);
        clientes[conta - 1].saldo += valor;
        printf("Depósito realizado com sucesso! Saldo atual: %.2f\n", clientes[conta - 1].saldo);
    } else {
        printf("Conta inválida!\n");
    }
}

void sacar() {
    int conta;
    float valor;

    printf("Digite o número da conta: ");
    scanf("%d", &conta);

    if (conta > 0 && conta <= numClientes) {
        printf("Digite o valor a ser sacado: ");
        scanf("%f", &valor);

        if (clientes[conta - 1].saldo >= valor) {
            clientes[conta - 1].saldo -= valor;
            printf("Saque realizado com sucesso! Saldo atual: %.2f\n", clientes[conta - 1].saldo);
        } else {
            printf("Saldo insuficiente!\n");
        }
    } else {
        printf("Conta inválida!\n");
    }
}

void efetuarPix() {
    int contaOrigem, contaDestino;
    float valor;

    printf("Digite o número da conta de origem: ");
    scanf("%d", &contaOrigem);

    if (contaOrigem > 0 && contaOrigem <= numClientes) {
        printf("Digite o número da conta de destino: ");
        scanf("%d", &contaDestino);

        if (contaDestino > 0 && contaDestino <= numClientes) {
            printf("Digite o valor a ser transferido: ");
            scanf("%f", &valor);

            if (clientes[contaOrigem - 1].saldo >= valor) {
                clientes[contaOrigem - 1].saldo -= valor;
                clientes[contaDestino - 1].saldo += valor;
                printf("Transferência realizada com sucesso! Saldo atual da conta de origem: %.2f\n", clientes[contaOrigem - 1].saldo);
            } else {
                printf("Saldo insuficiente!\n");
            }
        } else {
            printf("Conta de destino inválida!\n");
        }
    } else {
        printf("Conta de origem inválida!\n");
    }
}

void consultarSaldo() {
    int escolha;
    printf("1. Consultar saldo de um cliente específico\n");
    printf("2. Consultar saldo de todas as contas cadastradas\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        int conta;
        printf("Digite o número da conta: ");
        scanf("%d", &conta);

        if (conta > 0 && conta <= numClientes) {
            printf("Saldo da conta %d: %.2f\n", conta, clientes[conta - 1].saldo);
        } else {
            printf("Conta inválida!\n");
        }
    } else if (escolha == 2) {
        for (int i = 0; i < numClientes; i++) {
            printf("Conta %d - Saldo: %.2f\n", i + 1, clientes[i].saldo);
        }
    } else {
        printf("Escolha inválida!\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n===== Menu Principal =====\n");
        printf("1. Sacar\n");
        printf("2. Depositar\n");
        printf("3. Efetuar Pix\n");
        printf("4. Cadastrar novo cliente\n");
        printf("5. Transferir dinheiro entre contas\n");
        printf("6. Consultar saldo\n");
        printf("0. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                sacar();
                break;
            case 2:
                depositar();
                break;
            case 3:
                efetuarPix();
                break;
            case 4:
                cadastrarCliente();
                break;
            case 5:
                // Transferir dinheiro entre contas
                // Implemente conforme sua necessidade
                break;
            case 6:
                consultarSaldo();
                break;
            case 0:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}