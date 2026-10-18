package controle.altura;

import java.util.Scanner;

public class ControleDeAltura {
    public static class Registro {
        String nome;
        float altura;
    }

    public static void menu() {
        System.out.println("\n======MENU======\n");
        System.out.println("1.Cadastrar os 15 registros.\n");
        System.out.println("2.Apresentar os registros das pessoas com 1.50 m ou menores.\n");
        System.out.println("3.Apresentar os registros das pessoas maiores que 1.50 m.\n");
        System.out.println("4.Apresentar os registros das pessoas com mais de 1.50 m e menos de 2.0 m.\n");
        System.out.println("5.Apresentar todos os registros com a média extraída detodas as alturas armazenadas.\n");
        System.out.println("6.Sair do programa.\n");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Registro[] cadastro = new Registro[15];

        double soma = 0, mediaDeTodasAsAlturas = 0;
        int opcao, cadastrado = 0;
        int i;



        do {
            menu();
            System.out.println("\n\nEscolha uma opção: ");
            opcao = scanner.nextInt();
            scanner.nextLine();


            switch (opcao) {
                case 1:
                    soma = 0;

                    System.out.println("\nCadastro a seguir:\n");
                    for(i = 0; i < 15; i++){
                        cadastro[i] = new Registro();
                        System.out.println("Cadastro "+(i + 1));

                        System.out.println("\nNome: ");
                        cadastro[i].nome = scanner.nextLine();

                        System.out.println("\nAltura: ");
                        cadastro[i].altura = scanner.nextFloat();
                        scanner.nextLine();
                    }

                    for(i = 0; i < 15; i++){
                        soma += cadastro[i].altura;
                    }
                        mediaDeTodasAsAlturas = soma / 15.0;

                    cadastrado = 1;
                    break;

                case 2:
                    if(cadastrado == 0){
                        System.out.println("Cadastre os alunos primeiro!\n");

                        break;
                    }

                    for (i = 0; i < 15; i++){
                        if (cadastro[i].altura <= 1.50){
                            System.out.println("Nome: "+cadastro[i].nome);
                            System.out.println("Altura: "+cadastro[i].altura);
                        }
                    }
                    break;

                case 3:
                    if(cadastrado == 0){
                        System.out.println("Cadastre os alunos primeiro!\n");

                        break;
                    }

                    for (i = 0; i < 15; i++){
                        if (cadastro[i].altura > 1.50){
                            System.out.println("Nome: "+cadastro[i].nome);
                            System.out.println("Altura: "+cadastro[i].altura);
                        }
                    }

                    break;

                case 4:
                    if(cadastrado == 0){
                        System.out.println("Cadastre os alunos primeiro!\n");

                        break;
                    }

                    for (i = 0; i < 15; i++){
                        if (cadastro[i].altura > 1.50 && cadastro[i].altura < 2.00){
                            System.out.println("Nome: "+cadastro[i].nome);
                            System.out.println("Altura: "+cadastro[i].altura);
                        }
                    }

                    break;

                case 5:
                    if(cadastrado == 0){
                        System.out.println("Cadastre os alunos primeiro!\n");

                        break;
                    }

                    for (i = 0; i < 15; i++){
                        System.out.println("\nNome: "+ cadastro[i].nome);
                        System.out.println("Altura: "+ cadastro[i].altura);
                    }
                    System.out.println("MÉDIA DE TODAS AS ALTURAS: "+mediaDeTodasAsAlturas);

                    break;

                case 6:
                    System.out.println("\nSaindo...");

                    break;

                default:
                    System.out.println("\nOpção inválida!\n");
                    break;

            }
        } while (opcao != 6);
    }
}
