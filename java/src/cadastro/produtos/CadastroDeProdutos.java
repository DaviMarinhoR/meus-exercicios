package cadastro.produtos;

import java.util.Scanner;

public class CadastroDeProdutos {
    public static class CadastroProdutos {
        int codigo;
        String nome;
        double preco;
    }

    public static void menu() {
        System.out.println("\n=====MENU=====\n");
        System.out.println("1.Cadastrar os 20 produtos.\n");
        System.out.println("2.Classificar os registros por código.\n");
        System.out.println("3.Pesquisar por um produto.\n");
        System.out.println("4.Apresentar, de forma ordenada, os registros dos produtos com preço acima de R$ 100,00\n");
        System.out.println("5.Apresentar, de forma ordenada, os registros dos produtos com preço entre R$ 50,00 e R$ 100,00.\n");
        System.out.println("6.Apresentar, de forma ordenada, os registros dos produtos com preço abaixo de R$ 50,00\n");
        System.out.println("7.Apresentar todos os registros e informar o preço médio dos produtos cadastrados.\n");
        System.out.println("8.Sair do programa.\n");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        CadastroProdutos[] cadastro = new CadastroProdutos[20];
        CadastroProdutos aux;

        int i, j;
        int opcao, pesquisa;
        int cadastrado = 0, ordenado = 0;
        int inicio, meio = 0, fim, encontrou;
        int achouRegistro;
        double precoMedio = 0, somaPrecos;

        do {
            menu();
            System.out.println("Escolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine();
            switch (opcao) {

                case 1:
                    somaPrecos = 0;
                    for (i = 0; i < 20; i++) {
                        cadastro[i] = new CadastroProdutos();
                        System.out.println("CADASTRO " + (i + 1));

                        System.out.println("Código: ");
                        cadastro[i].codigo = scanner.nextInt();
                        scanner.nextLine();

                        System.out.println("Nome: ");
                        cadastro[i].nome = scanner.nextLine();

                        System.out.println("Preço: ");
                        cadastro[i].preco = scanner.nextDouble();
                        scanner.nextLine();
                    }

                    for (i = 0; i < 20; i++) {
                        somaPrecos += cadastro[i].preco;
                    }
                    precoMedio = somaPrecos / 20.0;

                    cadastrado = 1;
                    ordenado = 0;
                    break;

                case 2:
                    if (cadastrado == 0) {
                        System.out.println("\nCadastre os produtos primeiro!.\n");

                        break;
                    }

                    for (i = 0; i < 19; i++) {
                        for (j = i + 1; j < 20; j++) {
                            if (cadastro[i].codigo > cadastro[j].codigo) {
                                aux = cadastro[i];
                                cadastro[i] = cadastro[j];
                                cadastro[j] = aux;
                            }
                        }
                    }
                    System.out.println("\nOrdenação concluída.!\n");
                    ordenado = 1;

                    break;

                case 3:
                    if (cadastrado == 0) {
                        System.out.println("\nCadastre os produtos primeiro!.\n");

                        break;
                    }

                    if (ordenado == 0) {
                        System.out.println("\nUtilize a opção 2 para ordenar os registros.!\n");

                        break;
                    }

                    System.out.println("Pesquise por um produto (código): ");
                    pesquisa = scanner.nextInt();
                    scanner.nextLine();

                    encontrou = 0;
                    inicio = 0;
                    fim = 19;

                    while (inicio <= fim) {
                        meio = (inicio + fim) / 2;

                        if (cadastro[meio].codigo == pesquisa) {
                            encontrou = 1;

                            break;

                        } else if (pesquisa < cadastro[meio].codigo) {
                            fim = meio - 1;

                        } else {
                            inicio = meio + 1;
                        }
                    }

                    if (encontrou == 1) {
                        System.out.println("\nCódigo: " + cadastro[meio].codigo);
                        System.out.println("\nNome: " + cadastro[meio].nome);
                        System.out.println("\nPreço: " + cadastro[meio].preco);
                    } else {
                        System.out.println("\nProduto não encontrado entre os registros.\n");
                    }

                    break;

                case 4:
                    if (cadastrado == 0) {
                        System.out.println("\nCadastre os produtos primeiro!.\n");

                        break;
                    }
                    if (ordenado == 0) {
                        System.out.println("\nUtilize a opção 2 para ordenar os registros.\n");

                        break;
                    }
                    achouRegistro = 0;

                    for (i = 0; i < 20; i++) {
                        if (cadastro[i].preco > 100.0) {
                            System.out.println("Código: " + cadastro[i].codigo);
                            System.out.println("Nome: " + cadastro[i].nome);
                            System.out.println("Preço: " + cadastro[i].preco);
                            achouRegistro = 1;
                        }
                    }
                    if (achouRegistro == 0) {
                        System.out.println("\nSem registros.\n");
                    }

                    break;

                case 5:
                    if (cadastrado == 0) {
                        System.out.println("\nCadastre os produtos primeiro!.\n");

                        break;
                    }
                    if (ordenado == 0) {
                        System.out.println("\nUtilize a opção 2 para ordenar os registros.\n");

                        break;
                    }

                    achouRegistro = 0;

                    for (i = 0; i < 20; i++) {
                        if (cadastro[i].preco >= 50.0 && cadastro[i].preco <= 100.0) {
                            System.out.println("Código: " + cadastro[i].codigo);
                            System.out.println("Nome: " + cadastro[i].nome);
                            System.out.println("Preço: " + cadastro[i].preco);
                            achouRegistro = 1;
                        }
                    }
                    if (achouRegistro == 0) {
                        System.out.println("\nSem registros.\n");
                    }

                    break;

                case 6:
                    if (cadastrado == 0) {
                        System.out.println("\nCadastre os produtos primeiro!.\n");

                        break;
                    }
                    if (ordenado == 0) {
                        System.out.println("\nUtilize a opção 2 para ordenar os registros.\n");

                        break;
                    }

                    achouRegistro = 0;

                    for (i = 0; i < 20; i++) {
                        if (cadastro[i].preco < 50.0) {
                            System.out.println("Código: " + cadastro[i].codigo);
                            System.out.println("Nome: " + cadastro[i].nome);
                            System.out.println("Preço: " + cadastro[i].preco);
                            achouRegistro = 1;
                        }
                    }
                    if (achouRegistro == 0) {
                        System.out.println("\nSem registros.\n");
                    }

                    break;

                case 7:
                    if (cadastrado == 0) {
                        System.out.println("\nCadastre os produtos primeiro!.\n");

                        break;
                    }

                    for (i = 0; i < 20; i++) {
                        System.out.println("\nCADASTRO " + (i + 1));
                        System.out.println("\nCódigo: " + cadastro[i].codigo);
                        System.out.println("\nNome: " + cadastro[i].nome);
                        System.out.println("\nPreço: " + cadastro[i].preco);
                    }

                    System.out.println("\nMÉDIA DO PREÇO DOS PRODUTOS: " + precoMedio);

                    break;

                case 8:
                    System.out.println("\nSaindo...\n");

                    break;

                default:
                    System.out.println("\nOpção inválida!\n");

                    break;
            }


        } while (opcao != 8);
    }
}