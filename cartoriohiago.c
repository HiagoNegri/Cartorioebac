#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro() //Fun��o respos�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string, no caso para salv�-la

	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");   
	fprintf(file,",");   //edita o arquivo, no caso a fim de colocar uma virgula entre as informa��es
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //acessa e altera o arquivo criado no banco de dados 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); // colocando uma virgula entre os dados cadastrados
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //acessa e altera o arquivo criado no banco de dados 
	fprintf(file,sobrenome);
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //acessa e altera o arquivo criado no banco de dados 
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o
	scanf("%s",cpf); //analisa a vari�vel "cpf" refente � informa��o obtida
	
	FILE *file; 
	file = fopen(cpf,"r"); //le o cadastro encontrado com "r" sendo read
	
	if(file == NULL) //se n�o encontrar o cadastro...
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //...esta mensagem ser� exibida
	}
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto o arquivo existir...
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // a mensagem ser� exibida
		printf("%s",conteudo); //seguido das informa��es do cadastro, acessando com %s
		printf("\n\n"); //usando o comando \n\n para pular linhas 
 	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); 
	
	remove(cpf); //deleta o arquivo/cadastro
	
	FILE *file;
	file = fopen(cpf,"r"); // reprocura o cadastro

	if(file == NULL) ////se n�o encontrar o cadastro...
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //...esta mensagem ser� exibida
		system("pause"); //comando para pausar a exibi��o sendo retomada apertando uma tecla
	}
	
}


int main()
		
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //Repeti��o
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
		
		printf("----> Cart�rio da EBAC <----\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Op��o: ");//Fim do menu

	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //resposnsavel por limpar a tela
		
		switch(opcao) //inicio da sele��odo menu
	
		{
			case 1: //Abre as "chaves" do case
			registro();
			break; //Fecha as "chaves do case"
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: //Caso seja diferente das op��es
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //fim da sele��o
	
	}	
}
