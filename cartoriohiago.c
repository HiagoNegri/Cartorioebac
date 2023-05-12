#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int registro() //Função resposável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string, no caso para salvá-la

	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");   
	fprintf(file,",");   //edita o arquivo, no caso a fim de colocar uma virgula entre as informações
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
	
	printf("Digite o CPF a ser consultado: "); //coletando informação
	scanf("%s",cpf); //analisa a variável "cpf" refente à informação obtida
	
	FILE *file; 
	file = fopen(cpf,"r"); //le o cadastro encontrado com "r" sendo read
	
	if(file == NULL) //se não encontrar o cadastro...
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //...esta mensagem será exibida
	}
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto o arquivo existir...
	{
		printf("\nEssas são as informações do usuário: "); // a mensagem será exibida
		printf("%s",conteudo); //seguido das informações do cadastro, acessando com %s
		printf("\n\n"); //usando o comando \n\n para pular linhas 
 	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); 
	
	remove(cpf); //deleta o arquivo/cadastro
	
	FILE *file;
	file = fopen(cpf,"r"); // reprocura o cadastro

	if(file == NULL) ////se não encontrar o cadastro...
	{
		printf("O usuário não se encontra no sistema!.\n"); //...esta mensagem será exibida
		system("pause"); //comando para pausar a exibição sendo retomada apertando uma tecla
	}
	
}


int main()
		
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //Repetição
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
		
		printf("----> Cartório da EBAC <----\n\n"); //Início do menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opção: ");//Fim do menu

	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //resposnsavel por limpar a tela
		
		switch(opcao) //inicio da seleçãodo menu
	
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
			
			default: //Caso seja diferente das opções
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //fim da seleção
	
	}	
}
