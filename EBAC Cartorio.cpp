#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
    char arquivo[40]; 
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //$s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "A" significa arquivo
    fprintf(file,","); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //coletando informação do usúario
    scanf("%s",nome); //%s refere-se a string
    
    file = fopen (arquivo, "a"); //cria o arquivo e o"A" significa arquivo
    fprintf(file,nome); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "A" significa arquivo
    fprintf(file,","); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "A" significa arquivo
    fprintf(file,","); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usúario
    scanf ("%s", sobrenome); //%s refere-se a string
    
    file = fopen (arquivo, "a"); //cria o arquivo e o "A" significa arquivo
    fprintf(file, sobrenome); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "A" significa arquivo
    fprintf(file,","); //salva o valor da variavel 
    fclose(file); //fecha o arquivo
     
    printf("Digite o cargo a ser cadastrado: "); //coletando informação do usúario
    scanf("%s", cargo); //%s refere-se a string
    
    file = fopen(arquivo, "a"); //cria o arquivo e o "A" significa arquivo
    fprintf(file, cargo); //salva o valor da string 
    fclose(file); //fecha o arquivo
    
    system("pause");
    
}

int consulta() //função responsavel por consultar
{
    setlocale(LC_ALL,"portuguese_Brail.1252"); //Definindo a linguagem

    //inicio da criação de string/variáveis
	char cpf[40];
	char conteudo[300];
	//final da criação de string/variáveis
	
	printf("Digite o cpf a ser consultado:  " ); //coletando informação do usúario
	scanf("%s", cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); // cria o arquivo e o "R" significa ler
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!\n"); //coletando informação do usúario
	}
	
	while(fgets(conteudo, 300, file) != NULL)
	{
		printf("\nEssa sao as informacoes do usuario: "); //coletando informação do usúario
		printf("%s", conteudo); //%s refer-se a string 
		printf("\n\n"); // espaço
	}
	
	system("pause"); 
}

int deletar() //função responsavel por deletar
{
    //inicio da criação de string/variáveis
	char cpf[40];
	//final da criação de string/variáveis
	
	printf("Digite o cpf do usuario a ser deletado: "); //coletando informação do usúario
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); // excluir/remover o cpf
	
	FILE *file; //cria o arquivo
	file = fopen (cpf, "r"); //cria o arquivo e o "R" ler
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!.\n"); //coletando informação do usúario
		system("pause"); 
	}
	
}

int main() 
{
    int opcao=0; //Definindo as variáveis
    int x=1;
    
    for(x=1;x=1;)
    {
    	
    	system("cls");

        setlocale(LC_ALL,"portuguese_Brail.1252"); //Definindo a linguagem
	
	    printf("### Cartorio da EBAC ###\n\n"); //Inicio do menu
	    printf("escolha a opcao desejada do menu:");
	    printf ("\n\n\t1 - Registras seu nome\n\n");
	    printf ("\t2 - Consultar os nome\n\n");
	    printf ("\t3 - Deletar os nomes\n\n"); 
	    printf ("\t4 - sair do sistema\n\n");
    	printf ("Opcao: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escoçha do usuário
	
    	system("cls"); //responsavel por limpar a tela
	
	switch(opcao) //inicio da seleção do menu
	{
	    case 1:
		registro(); //chamada de funções
   		break;
   		
   		case 2:
   		consulta(); //chamada de consulta
   		break;
   		
   		case 3:
   		deletar(); //chamada de deletar
	 	break;
	 	
	 	case 4:
	 	printf("Obrigado por utilizar o sistema!");
		return 0;
		break;	
	 	
	 	default:
	 	printf("Essa opcao nao esta disponivel\n");
		system("pause");
		break;
	}   //fim da seleção
}
}

	