/* 	Arquivo criado com o objetivo de Desenvolver o projeto Integrado multidisciplinar do segundo semestre
	no curso de Analise e Desenvolvimento de Sistemas da Universidade Paulista - Campos Marqu�s
------------------------------------------------------------------------------------------------------------
	Data da Cria��o: 15/10/2019
	Autor: Arthur Andrassy
	Autor: Bruno Niemayer
	Autor: Fabiano Novais
	Autor: Guilherme M G de Oliveira
	Autor: Henrique da Silva Lima
------------------------------------------------------------------------------------------------------------
	Professor: Luis Fernando
	Disciplina: Linguagem C
------------------------------------------------------------------------------------------------------------
	Tela de Menu Principal
	Objetivo: Apresentar as fun��es de utiliza��o do sistema, para que os usu�rios possam navegar e efetuar
			  os procedimentos de trabalho.
*/

#include <stdio.h> 	//BIBLIOTECA PARA AS FUNCOES BASICAS
#include <stdlib.h> //BIBLIOTECA DE COMANDOS PARA O PROMPT
#include <locale.h>	//BIBLIOTECA PARA CARACTERES ESPECIAIS
#include <string.h>	//BIBLIOTECA DE CAMPO DE TEXTO
#include <conio.h> 	//BIBLIOTECA PARA FUN��ES ESPECIFICAS(GETCH)
#include <time.h>	//BIBLIOTECA PARA TRABALHAR COM DATAS E HORA

//ESTRUTURA PARA ARMAZENAR OS DADOS NAS VARIAVEIS
typedef struct login LOGIN;
struct login{
	char usuario[15]; 	//VARIAVEL QUE RECEBE O QUE O USUARIO DIGITA ATRIBUIDA AO NOME DE USUARIO
    char login[15]; 	//VARIAVEL QUE RECEBE O QUE O USUARIO DIGITA ATRIBUIDA A SENHA
    char senha[15]; 	//VARIAVEL PARA A COMPARACAO COM A OUTRA VARIAVEL DIGITADA ANTERIORMENTE
    char senhac[15]; 	//VARIAVEL PARA A COMPARACAO COM A OUTRA VARIAVEL DIGITADA ANTERIORMENTE
};

//ESTRUTURA PARA CLIENTE
typedef struct cliente CLIENTE;
struct cliente{
    char nome[30]; 		//VARIAVEL QUE RECEBE O NOME DO CLIENTE
    char endereco[50]; 	//VARIAVEL QUE RECEBE O ENDERECO DO CLIENTE
    char numero[6];	//VARIAVEL QUE RECEBE O NUMERO DA CASA DO CLIENTE
    char telefone[13];	//VARIAVEL QUE RECEBE O TELEFONE DO CLIENTE
};

//ESTRUTURA PARA PIZZA
typedef struct pizza PIZZA;
struct pizza{
	char sabor[30]; 	//VARIAVEL QUE RECEBE O SABOR DA PIZZA
	float valor; 		//VARIAVEL QUE RECEBE O VALOR DA PIZZA
};


//ESTRUTURA PARA BEBIDAS
typedef struct funcionario FUNCIONARIO;
struct funcionario{
	char nome[30];		//VARIAVEL QUE RECEBE O NOME DO FUNCIONARIO
	char cpf[11];		//VARIAVEL QUE RECEBE O CPF DO FUNCIONARIO
	int idade;		//VARIAVEL QUE RECEBE A IDADE DO FUNCIONARIO
	float salario;		//VARIAVEL QUE RECEBE O SALARIO DO FUNCIONARIO
};

//ESTRUTURA PARA BEBIDAS
typedef struct bebida BEBIDA;
struct bebida{
	char tipo[20];		//VARIAVEL QUE RECEBE O TIPO DE BEBIDA
	char marca[30];		//VARIAVEL QUE RECEBE A MARCA DA BEBIDA
	float valor;			//VARIAVEL QUE RECEBE O VALOR DA BEBIDA
};

//ESTRUTURA PARA PEDIDOS
typedef struct pedido PEDIDO;
struct pedido{
	char nomeCliente[30];		//VARIAVEL QUE RECEBE O NOME DO CLIENTE
	char enderecoCliente[50];	//VARIAVEL QUE RECEBE O ENDERECO DO CLIENTE
	char numeroCliente[6];		//VARIAVEL QUE RECEBE O NUMERO DO CLIENTE
	char telefoneCliente[13];	//VARIAVEL QUE RECEBE O TELEFONE DO CLIENTE
	char codigoPromocao[2];		//VARIAVEL QUE RECEBE O CODIGO DA PROMOCAO
	char saborPizza[30];		//VARIAVEL QUE RECEBE O SABOR DA PIZZA
	char tipoBebida[20];		//VARIAVEL QUE RECEBE O TIPO DE BEBIDA
	char marcaBebida[30];		//VARIAVEL QUE RECEBE A MARCA DA BEBIDA
	float valorPizza;			//VARIAVELS QUE RECEBE O VALOR DA PIZZA
	float valorBebida;			//VARIAVEL QUE RECEBE O VALOR DA BEBIDA
	float valorTotal;			//VARIAVEL QUE RECEBE O VALOR TOTAL DO PEDIDO
};

//ESTRUTURA PARA RECLAMACAO
typedef struct reclamacao RECLAMACAO;
struct reclamacao{
	char nome[30];		//VARIAVEL QUE RECEBE O NOME DO CLIENTE
	char telefone[15];	//VARIAVEL QUE RECEBE O TELEFONE DO CLIENTE
	char mensagem[120];	//VARIAVEL QUE RECEBE A MENSAGEM DO CLIENTE
};

//ESTRUTURA PARA SUGESTAO
typedef struct sugestao SUGESTAO;
struct sugestao{
	char nome[30];		//VARIAVEL QUE RECEBE O NOME DO CLIENTE
	char telefone[15];	//VARIAVEL QUE RECEBE O TELEFONE DO CLIENTE
	char mensagem[120];	//VARIAVEL QUE RECEBE A MENSAGEM DO CLIENTE
};

//ESTRUTURA PARA ELOGIO
typedef struct elogio ELOGIO;
struct elogio{
	char nome[30];		//VARIAVEL QUE RECEBE O NOME DO CLIENTE
	char telefone[15];	//VARIAVEL QUE RECEBE O TELEFONE DO CLIENTE
	char mensagem[120];	//VARIAVEL QUE RECEBE A MENSAGEM DO CLIENTE
};

//ESTRUTURA PARA PROMOCOES
typedef struct promocao PROMOCAO;
struct promocao{
	char codigoPromocao[2];	//VARIAVEL QUE RECEBE O CODIGO DAS PROMOCOES
	char saborPizza[30];	//VARIAVEL QUE RECEBE O SABOR DA PIZZA
	char marcaBebida[30];	//VARIAVEL QUE RECEBE A MARCA DA BEBIDA
	float valorTotal;	//VARIAVEL QUE RECEBE O VALOR TOTAL
};

//FUN��ES DO SISTEMA
void cabecalho(void);
void entrarSistema(void);
void menuCadastro(void);
void menuConsulta(void);
void menuReclamacao(void);

//CADASTROS
void cadastraCliente(void);
void cadastraPizza(void);
void cadastraFuncionario(void);
void cadastraBebida(void);
void cadastraPedido(void);
void cadastraReclamacao(void);
void cadastraSugestao(void);
void cadastraElogio(void);
void cadastraPromocao(void);

//CONSULTAS
void consultaCliente(void);
void consultaPizza(void);
void consultaFuncionario(void);
void consultaBebida(void);
void consultaReclamacao(void);
void consultaSugestao(void);
void consultaElogio(void);
void consultaPedido(void);
void consultaPromocao(void);

//VARIAVEIS GLOBAIS
char sair;				//VARIAVEL QUE EFETUA O LOGON NO SISTEMA

int main(void){
	//CONFIGURA��O DE COR PADR�O DO CONSOLE
	system("color B0");

	//ESTRUTURA LOGIN
	struct login logar;

	//COMANDO PARA ACEITAR CARACTER ESPECIAL EM PT-BR
    setlocale(LC_ALL, "Portuguese");

	//VARIAVEIS DE SISTEMA
	int escolha;		//VARIAVEL DE ACESSO AO MENU
	int entrar = 1;		//VARIAVEL DE TRATAMENTO DE ERRO AO LOGAR

	//FUN��O DO CABECALHO
	cabecalho();

	//SOLICITACAO DE CADASTRO DE CADASTRO DE USUARIO
    printf(" POR GENTILEZA INFORME O NOME DO USUARIO.: \n");
    printf(" 		");
    //ARMAZENANDO O CAMPO DIGITADO NA VARIAVEL
	scanf("%s", &logar.usuario);
	getchar();

	//SENHA
	//SOLICITACAO DE CADASTRO DE CADASTRO DA SENHA
    printf(" POR GENTILEZA INFORME A SENHA DO USUARIO.: \n");
    printf(" 		");
    //ARMAZENANDO O CAMPO DIGITADO NA VARIAVEL
	scanf("%s", &logar.senha);
    getchar();
    //LIMPAR A TELA
    system("CLS");

    //LOOP PARA MANTER O CONSOLE EM EXECUCAO
	do{
	    do{
	    	system("CLS");
	        //ACESSO AO SISTEMA
	        cabecalho();

			//USUARIO
			//SOLICITACAO DE CADASTRO DE CADASTRO DE USUARIO
	        printf("    INFORME O SEU USUARIO: \n");
	        printf(" 		");
	        //ARMAZENANDO O CAMPO DIGITADO NA VARIAVEL
			scanf("%s", &logar.login);
            getchar();

	        //SENHA
	        //SOLICITACAO DE CADASTRO DE CADASTRO DE SENHA
			printf("    INFORME A SENHA: \n");
			printf(" 	 	");
	        //ARMAZENANDO O CAMPO DIGITADO NA VARIAVEL
			scanf("%s", &logar.senhac);
            getchar();
	        //LIMPAR A TELA
	        system("CLS");

	        //CONDICAO PARA ACESSO AO SISTEMA
	        /*
	            STRCMP = FUNCAO DA BIBLIOTECA STRING.H QUE REALIZA A COMPARACAO ENTRE DUAS VARIAVEIS DO TIPO STRING,
	            CASO ELAS SEJAM IGUAIS A 0 HABILITA O ACESSO AO SISTEMA, CASO CONTRARIO REINICIA A SOLICITACAO DAS INFORMACOES DE LOGIN
	        */
	        if (strcmp(logar.usuario, logar.login) == 0 && strcmp(logar.senha, logar.senhac) == 0 )
	        {
	        	cabecalho();
	            printf("\n");
				printf(" 	LOGIN EFETUADO COM SUCESSO !! \n");
	            printf("\n");
	            system("PAUSE");

	            //LA�O QUE CRIA O MENU
			    do{
			    	system("CLS");
			        cabecalho();
			        printf("   	O QUE VOC� DESEJA REALIZAR? \n");
			        printf("\n");
			        printf(" 	1 - CADASTRAR \n");
			        printf(" 	2 - CONSULTAR \n");
			        printf(" 	3 - RECLAMA��ES E/OU SUGEST�ES \n");
			        printf(" 	0 - PARA SAIR DO SISTEMA \n");
					printf("\n");
					printf("   ");
					//ARMAZENANDO ESCOLHA DO USUARIO
			        scanf("%i", &escolha);
					getchar();


					switch(escolha){
						//FUN��O DE CADASTRO
						case 1:
							//CARREGANDO FUN��O
							menuCadastro();
						break;

						//FUN��O DE CONSULTA
						case 2:
							//CARREGANDO FUN��O
							menuConsulta();
						break;

						//FUN��O DE RECLAMA��ES
						case 3:
							//CARREGANDO FUN��O
							menuReclamacao();
						break;

						//CONDICAO DE SAIDA DO SISTEMA
						default:
							system("CLS");
							cabecalho();
							printf("\n\n");
							printf(" OP��O INVALIDA, POR GENTILEZA ESCOLHA NOVAMENTE... \n");
							system("PAUSE");
						break;

						case 0:
							system("CLS");
							cabecalho();
							printf("\n\n");
							printf(" OBRIGADO POR UTILIZAR O NOSSO SISTEMA \n");
							system("EXIT");
						break;
					}

					//VARIAVEL QUE EFETUA DESLOGA DO SISTEMA
					entrar = 0;

					//SAIR DO LOOP DE EXECU��O DO SISTEMA
				} while(escolha != 0);
	        }
	        else
	        {
	        	cabecalho();
	            printf("USU�RIO OU SENHA INCORRETOS \n");
	            printf("POR GENTILEZA INFORME NOVAMENTE OS DADOS \n\n");
	            system("PAUSE");
	        }

			//CONDI��O PARA SAIDA DO SISTEMA
		}while(entrar != 0);

		//CONDICAO PARA A "SAIDA" DO LACO E ENTRADA NO SISTEMA
   	}while(strcmp(logar.usuario, logar.login) != 0 && strcmp(logar.senha, logar.senhac) != 0);

    return 0;
}


/* ------------------------------------------------------------------------------ */
						// FUN��O ESTETICA DO CABECALHO //
/* ------------------------------------------------------------------------------ */
void cabecalho(){
	printf("   ------------------------------------- \n");
	printf("   ------------------------------------- \n");
	printf("   ------- PIZZARIA * ASTERISCO  ------- \n");
	printf("   ------------------------------------- \n");
	printf("   ------------------------------------- \n");
    printf("\n");
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE MENU CADASTRO //
/* ------------------------------------------------------------------------------ */
void menuCadastro(){
	//VARIAVEIS LOCAIS
	int escolhaMenu;
	int sairMenu;

	//LA�O PARA MANTER O USUARIO NO SUBMENU
	do{
		//LIMPAR A TELA
		system("CLS");

		//FUN��O DO CABECALHO
		cabecalho();

		//INTERA��O
        printf("\n");
		printf(" POR GENTILEZA ESCOLHA O QUE VOC� DESEJA CADASTRAR \n");
		printf("\n");
		printf(" 	1 - CLIENTE \n");
		printf(" 	2 - PIZZA \n");
		printf(" 	3 - FUNCIONARIO \n");
		printf(" 	4 - BEBIDAS \n");
		printf(" 	5 - PEDIDO \n");
		printf("	6 - PROMO��O \n");
		printf("\n");
		printf(" 0 - PARA VOLTAR AO MENU ANTERIOR \n");
		printf(" ");
		scanf("%i", &escolhaMenu);
        getchar();

		//LA�O DE ESCOLHA DAS OP��ES
		switch(escolhaMenu){
			//CADASTRO DE CLIENTES
			case 1:
				cadastraCliente();
			break;

			//CADASTRO DE PIZZAS
			case 2:
				cadastraPizza();
			break;

			//CADASTRO DE FUNCIONARIOS
			case 3:
				cadastraFuncionario();
			break;

			//CADASTRO DE BEBIDAS
			case 4:
				cadastraBebida();
			break;
			
			//CADASTRO DE PEDIDOS
			case 5:
				cadastraPedido();
			break;
			
			//CADASTRO DE PROMOCAO
			case 6:
				cadastraPromocao();
			break;

			//OP��O DIFERENTE DAS INFORMADAS NO MENU
			default:
				system("CLS");

				//FUN��O DO CABECALHO
				cabecalho();

				printf("\n\n");
				printf(" OP��O INVALIDA, POR GENTILEZA ESCOLHA NOVAMENTE... \n");
				system("PAUSE");

				//CHAMADA DA FUN��O PARA RETORNAR ESCOLHA
				menuCadastro();
			break;

			//SAIDA DO MENU
			case 0:
				sairMenu = 0;
			break;
		}

	//CONDI��O PARA SAIR DO LA�O
	}while(sairMenu != 0);
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE MENU CONSULTA //
/* ------------------------------------------------------------------------------ */
void menuConsulta(){
	//VARIAVEIS LOCAIS
	int escolha;
	int sair;

	do{
		//LIMPAR A TELA
		system("CLS");

		//FUNCAO DO CABECALHO
		cabecalho();

		//ITERA��O DA FUNCAO
        printf("\n");
		printf("POR GENTILEZA ESCOLHA A INFORMA��O QUE VOC� DESEJA CONSULTAR \n");
		printf("\n");
		//ARMAZENANDO ESCOLHA DO USUARIO
		printf("	1 - CLIENTE \n");
		printf("	2 - PIZZAS \n");
		printf("	3 - FUNCION�RIOS \n");
		printf("	4 - BEBIDAS \n");
		printf("	5 - PEDIDOS \n");
		//printf("	6 - PROMO��O \n");
		printf("\n");
		printf("  0 - PARA VOLTAR AO MENU ANTERIOR \n");
		scanf("%i", &escolha);
        getchar();

		//LOOP PARA CONSULTA
		switch(escolha){
			//CONSULTA CLIENTE
			case 1:
				//LIMPAR A TELA
				system("CLS");
				consultaCliente();
				printf("\n\n");
				//PAUSA A EXECU��O
				system("PAUSE");
			break;

			//CONSULTA PIZZA
			case 2:
				//LIMPAR A TELA
				system("CLS");
				consultaPizza();
				printf("\n\n");
				//PAUSA A EXECU��O
				system("PAUSE");
			break;

			//CONSULTA FUNCIONARIO
			case 3:
				//LIMPAR A TELA
				system("CLS");
				consultaFuncionario();
				printf("\n\n");
				//PAUSA A EXECU��O
				system("PAUSE");
			break;

			//CONSULTA BEBIDAS
			case 4:
				//LIMPAR A TELA
				system("CLS");
				consultaBebida();
				printf("\n\n");
				//PAUSA A EXECU��O
				system("PAUSE");
			break;

			//CONSULTA PEDIDOS
			case 5:
				//LIMPAR A TELA
				system("CLS");
				consultaPedido();
				printf("\n\n");
				//PAUSA A EXECU��O
				system("PAUSE");
			break;
			
			//CONSULTA PROMOCAO
			/*case 6:
				//LIMPA A TELA
				system("CLS");
				consultaPromocao();
				printf("\n\n");
				//PAUSA A EXECU��O
				system("PAUSE");
			break;*/

			//OP��O DIFERENTE DAS INFORMADAS NO MENU
			default:
				system("CLS");

				//FUNCAO DO CABECALHO
				cabecalho();

				printf("\n\n");
				printf(" OP��O INVALIDA, POR GENTILEZA ESCOLHA NOVAMENTE... \n");
				system("PAUSE");

				//CHAMADA DA FUN��O PARA RETORNAR ESCOLHA
				menuConsulta();
			break;

			//SAIDA DO MENU
			case 0:
				sair = 0;
			break;
		}


	}while(sair != 0);
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE MENU RECLAMA��ES //
/* ------------------------------------------------------------------------------ */
void menuReclamacao(){
	//VARIAVEIS LOCAIS
	int escolha = 0;
	int sair;

	do{
		//LIMPAR A TELA
		system("CLS");

		//FUNCAO DO CABECALHO
		cabecalho();

		//ITERA��O DA FUNCAO
        printf("\n");
		printf("  POR GENTILEZA ESCOLHA A OP��O QUE DESEJA \n");
		printf("\n");
		//ARMAZENANDO ESCOLHA DO USUARIO
		printf("	======== CADASTROS ======== \n");
		printf("	1 - CADASTRAR RECLAMA��ES \n");
		printf("	2 - CADASTRAR SUGEST�ES \n");
		printf("	3 - CADASTRAR ELOGIOS \n");
		printf("\n");
		printf("	======== CONSULTAS ======== \n");
		printf("	4 - CONSULTAR RECLAMA��ES \n");
		printf("	5 - CADASTRAR SUGEST�ES \n");
		//printf("	6 - CADASTRAR ELOGIOS \n");
		printf("	======== VOLTAR ======== \n");
		printf("   0 - PARA VOLTAR AO MENU ANTERIOR \n");
		scanf("%i", &escolha);
        getchar();

		//LOOP PARA CADASTRO
		switch(escolha){
			//CADASTRO DE RECLAMA��O
			case 1:
			    cadastraReclamacao();
			break;

			//CADASTRO DE SUGEST�ES
			case 2:
				cadastraSugestao();
            break;

			//CADASTRO DE ELOGIO
			case 3:
				cadastraElogio();
				break;

			//CONSULTA DE RECLAMA��ES
			case 4:
			    //LIMPAR A TELA
				system("CLS");
				consultaReclamacao();
				printf("\n\n");
                //PAUSA A EXECU��O
				system("PAUSE");
			break;

			//CONSULTA DE SUGEST�ES
			case 5:
			    //LIMPAR A TELA
			    system("CLS");
				consultaSugestao();
				printf("\n\n");
                //PAUSA A EXECU��O
				system("PAUSE");
			break;

			//CONSULTA DE ELOGIOS
			/*case 6:
			    //LIMPAR A TELA
			    system("CLS");
				consultaElogio();
				printf("\n\n");
                //PAUSA A EXECU��O
				system("PAUSE");
			break;*/

			//OP��O DIFERENTE DAS INFORMADAS NO MENU
			default:
			    //LIMPAR A TELA
				system("CLS");

				//FUNCAO DO CABECALHO
				cabecalho();

				printf("\n\n");
				printf(" OP��O INVALIDA, POR GENTILEZA ESCOLHA NOVAMENTE... \n");
				system("PAUSE");

				//CHAMADA DA FUN��O PARA RETORNAR ESCOLHA
				menuReclamacao();
			break;

			//SAIDA DO MENU
			case 0:
				sair = 0;
			break;
		}
	}while(sair != 0);
}


/*** ==================================================================================== ****/
							// 	FUN��ES DE CADASTRO //
/*** ==================================================================================== ****/


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE CLIENTE //
/* ------------------------------------------------------------------------------ */
void cadastraCliente(){
	//CHAMANDO ESTRUTURA
	CLIENTE cadastro;

	//PONTEIRO DE ARQUIVO PARA O ARQUIVO
	FILE * arquivoTexto;
	//APONTAR O PONTEIRO PARA UM ARQUIVO NA PASTA
	arquivoTexto = (fopen("cliente.txt", "ab"));

	//LA�O PARA MULTIPLUS CADASTROS
	do{
		//LIMPAR A TELA DO CONSOLE
		system("CLS");
		//DESCARREGANDO O BUFFER
		fflush(stdin);

		//FUNCAO CABECALHO
		cabecalho();

		//ITERACAO
		printf("\n VOC� SELECIONOU A OP��O PARA CADASTRAR UM NOVO CLIENTE");
		printf("\n POR GENTILEZA INFORME OS DADOS SOLICITADOS:");
		printf("\n\n");

		//CAMPO PARA O NOME DO CLIENTE
		fflush(stdin);
		printf(" INFORME O NOME DO CLIENTE.: ");
		printf(" ");
        gets(cadastro.nome);

		//CAMPO PARA O ENDERECO DO CLIENTE
		printf(" INFORME O ENDERECO DO CLIENTE.: ");
		printf(" ");
        gets(cadastro.endereco);

		//CAMPO PARA O NUMERO DO CLIENTE
		printf(" INFORME O NUMERO DA RESID�NCIA DO CLIENTE.: ");
		printf(" ");
        gets(cadastro.numero);

		//CAMPO PARA O TELEFONE DO CLIENTE
		fflush(stdin);
		printf(" INFORME O TELEFONE DO CLIENTE.: ");
		printf(" ");
        gets(cadastro.telefone);

        //SALVANDO DADOS NO ARQUIVO
		fwrite(&cadastro, sizeof(CLIENTE), 1, arquivoTexto);

		//DESCARREGANDO O BUFFER
		fflush(stdin);
		//VERIFICA��O PARA CADASTRO DE NOVO CLIENTE
		printf("\n DESEJA CADASTRAR UM NOVO CLIENTE ?? \n");
		printf(" S - SIM ou N - N�O \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
        getchar();
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS

	//FECHA O ARQUIVO TXT
    fclose(arquivoTexto);
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE PIZZAS //
/* ------------------------------------------------------------------------------ */
void cadastraPizza(){
	//CHAMANDO ESTRUTURA
	PIZZA cadastro;

	//PONTEIRO DE ARQUIVO PARA O ARQUIVO
	FILE * arquivoTexto;
	//APONTAR O PONTEIRO PARA UM ARQUIVO NA PASTA
	arquivoTexto = (fopen("pizzas.txt", "ab"));

	//LA�O PARA MULTIPLUS CADASTROS
	do{
		//LIMPAR A TELA DO CONSOLE
		system("CLS");
		//DESCARREGANDO O BUFFER
		fflush(stdin);

		//FUNCAO CABECALHO
		cabecalho();

		//ITERACAO
		printf("\n VOC� SELECIONOU A OP��O PARA CADASTRAR UMA NOVA PIZZA");
		printf("\n POR GENTILEZA INFORME OS DADOS SOLICITADOS:");
		printf("\n\n");

		//CAMPO PARA O SABOR DA PIZZA
		fflush(stdin);
		printf(" INFORME O SABOR DA PIZZA.: ");
		printf(" ");
        gets(cadastro.sabor);

		//CAMPO PARA O VAOR DA PIZZA
		printf(" INFORME O VALOR DA PIZZA.: ");
		printf(" ");
        scanf("%f", &cadastro.valor);

		/*
		fflush(stdin);
        printf(" INFORME A QUANTIDADE PARA SER ARMAZENADA EM ESTOQUE");
        printf(" ");
        scanf("%i", &cadastro.qtdPizza);
		*/

        //SALVANDO DADOS NO ARQUIVO
		fwrite(&cadastro, sizeof(PIZZA), 1, arquivoTexto);

		//DESCARREGANDO O BUFFER
		fflush(stdin);
		//VERIFICA��O PARA CADASTRO DE NOVO SABOR
		printf("\n DESEJA CADASTRAR UM NOVO SABOR ? \n");
		printf(" S - SIM ou N - N�O \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
		getchar();
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS

	//FECHA O ARQUIVO TXT
    fclose(arquivoTexto);

}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE FUNCIONARIO //
/* ------------------------------------------------------------------------------ */
void cadastraFuncionario(){
	//UTILIZANDO A ESTRUTURA
	FUNCIONARIO colaborador;


	//TRATAR ERRO DE INSER��O DE CARACTERES A MAIS NOS CAMPOS

	//PONTEIRO DE ARQUIVO PARA O ARQUIVO
	FILE * arquivoTexto;
	//APONTAR O PONTEIRO PARA UM ARQUIVO NA PASTA
	arquivoTexto = (fopen("funcionarios.txt", "ab"));

	//LA�O PARA MULTIPLUS CADASTROS
	do{
		//LIMPAR A TELA DO CONSOLE
		system("CLS");
		//DESCARREGANDO O BUFFER
		fflush(stdin);

		//FUNCAO CABECALHO
		cabecalho();

		//ITERACAO
		printf("\n VOC� SELECIONOU A OP��O PARA CADASTRAR UM NOVO FUNCIONARIO");
		printf("\n POR GENTILEZA INFORME OS DADOS SOLICITADOS:");
		printf("\n\n");

		//CAMPO PARA ARMAZENAR O NOME DO FUNCIONARIO
		fflush(stdin);
		printf(" NOME DO FUNCIONARIO.: ");
		printf("");
        gets(colaborador.nome);

		//CAMPO PARA ARMAZENAR O CPF DO FUNCIONARIO
		printf(" INFORME O CPF DO COLABORADOR.: ");
		printf("");
        gets(colaborador.cpf);

        //CAMPO PARA ARMAZENAR A IDADE DO FUNCIONARIO
        printf(" INFORME A IDADE DO FUNCIONARIO.: ");
        printf("");
        scanf("%i", &colaborador.idade);

        //CAMPO PARA ARMAZENAR O SALARIO DO FUNCIONARIO
        printf(" INFORME O SALARIO DO FUNCIONARIO.: ");
        printf("");
        scanf("%f", &colaborador.salario);

        //SALVANDO DADOS NO ARQUIVO
		fwrite(&colaborador, sizeof(FUNCIONARIO), 1, arquivoTexto);

		//DESCARREGANDO O BUFFER
		fflush(stdin);
		//VERIFICA��O PARA CADASTRO DE NOVO CLIENTE
		printf("\n DESEJA CADASTRAR UM NOVO FUNCIONARIO ?? \n");
		printf(" S - SIM ou N - N�O \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
		getchar();
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS

	//FECHA O ARQUIVO TXT
    fclose(arquivoTexto);
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE BEBIDAS //
/* ------------------------------------------------------------------------------ */
void cadastraBebida(){
	//CHAMANDO ESTRUTURA
	BEBIDA bebidas;

	//PONTEIRO DE ARQUIVO PARA O ARQUIVO
	FILE * arquivoTexto;
	//APONTAR O PONTEIRO PARA UM ARQUIVO NA PASTA
	arquivoTexto = (fopen("bebidas.txt", "ab"));

	//LA�O PARA MULTIPLUS CADASTROS
	do{
		//LIMPAR A TELA DO CONSOLE
		system("CLS");
		//DESCARREGANDO O BUFFER
		fflush(stdin);

		//FUNCAO CABECALHO
		cabecalho();

		//ITERACAO
		printf("\n VOC� SELECIONOU A OP��O PARA CADASTRAR UMA NOVA BEBIDA");
		printf("\n POR GENTILEZA INFORME OS DADOS SOLICITADOS:");
		printf("\n\n");

		//CAMPO PARA O SABOR DA BEBIDA
		fflush(stdin);
		printf(" INFORME O TIPO DA BEBIDA.: ");
		printf("");
        gets(bebidas.tipo);

        //CAMPO PARA O SABOR DA BEBIDA
		printf(" INFORME A MARCA DA BEBIDA.: ");
		printf("");
        gets(bebidas.marca);

		//CAMPO PARA O ENDERECO DO CLIENTE
		printf(" INFORME O VALOR QUE SERA COBRADO.: ");
		printf("");
        scanf("%f", &bebidas.valor);

        //SALVANDO DADOS NO ARQUIVO
        fwrite(&bebidas, sizeof(BEBIDA), 1, arquivoTexto);

		//DESCARREGANDO O BUFFER
		fflush(stdin);
		//VERIFICA��O PARA CADASTRO DE NOVO CLIENTE
		printf("\n DESEJA CADASTRAR UMA NOVA BEBIDA ?? \n");
		printf(" S - SIM ou N - N�O \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
		getchar();
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS

	//FECHA O ARQUIVO TXT
    fclose(arquivoTexto);
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE PEDIDO //
/* ------------------------------------------------------------------------------ */
void cadastraPedido(){

	do{

	//UTILIZANDO A ESTRUTURA
	CLIENTE cliente;
	PIZZA pizzas;
	BEBIDA bebida;
	PEDIDO pedido;
	PROMOCAO promocao;

	//PONTEIROS PARA ARQUIVOS
	FILE * arquivoTexto;
	FILE * arquivoTexto1;
	FILE * arquivoTexto2;
	FILE * arquivoTexto3;

	//VARIAVEIS LOCAIS
	char nome[30];
	char pizza[15];
	char bebid[15];
	char codigoPromocao[2];
	int qtdBebidas;
	int qtdPizzas;
    char escolha;
    

	//ABRIR ARQUIVOS PARA LEITURA
	arquivoTexto = (fopen("cliente.txt", "rb"));
	arquivoTexto1 = (fopen("pizzas.txt", "rb"));
    arquivoTexto2 = (fopen("bebidas.txt","rb"));
	//ABRIR ARQUIVO PARA ESCRITA
	arquivoTexto3 = (fopen("pedidos.txt", "a"));
	
	system("CLS");
	cabecalho();	
    printf("VOC� SELECIONOU A OP��O DE CADATRO DE PEDIDOS\n\n");
    
	
	//ESCOLHA CADASTRO POR PROMO��O OU NORMAL
	if(escolha == 'S' || escolha == 's'){
		if(arquivoTexto == NULL){
			printf("ARQUIVO N�O ENCONTRADO... \n");
		}
		else{
			system("CLS");
			cabecalho();
			fflush(stdin);
			printf("INFORME O NOME DO CLIENTE.: ");
			fflush(stdin);
			gets(nome);
	
	        while(fread(&cliente, sizeof(CLIENTE), 1, arquivoTexto) == 1) {
	
	            if(strstr(nome, cliente.nome ) !=NULL){
					
					printf("\n NOME.: %s \n", cliente.nome);
					strcpy(pedido.nomeCliente, cliente.nome);
					
					printf("ENDERE�O.: %s \n", cliente.endereco);
					strcpy(pedido.enderecoCliente, cliente.endereco);
					
					printf("NUMERO DA RESID�NCIA.: %s \n", cliente.numero);
					strcpy(pedido.numeroCliente, cliente.numero);
					
					printf("TELEFONE.: %s \n", cliente.telefone);
					strcpy(pedido.telefoneCliente, cliente.telefone);
				}
				
				
				
		        fwrite(&pedido, sizeof(PEDIDO), 1, arquivoTexto3);
			}	
		}
	}
	//CADASTRO PEDIDO NORMAL
	else{
		if(arquivoTexto == NULL){
			printf("ARQUIVO N�O ENCONTRADO... \n");
		}
	
		else {
			system("CLS");
			cabecalho();
			fflush(stdin);
			printf("INFORME O NOME DO CLIENTE.: ");
			fflush(stdin);
			gets(nome);
	
	        while(fread(&cliente, sizeof(CLIENTE), 1, arquivoTexto) == 1) {
	
	            if(strstr(nome, cliente.nome ) !=NULL){
					
					printf("\nNOME.: %s \n", cliente.nome);
					strcpy(pedido.nomeCliente, cliente.nome);
					
					printf("ENDERE�O.: %s \n", cliente.endereco);
					strcpy(pedido.enderecoCliente, cliente.endereco);
					
					printf("NUMERO DA RESID�NCIA.: %s \n", cliente.numero);
					strcpy(pedido.numeroCliente, cliente.numero);
					
					printf("TELEFONE.: %s \n", cliente.telefone);
					strcpy(pedido.telefoneCliente, cliente.telefone);
				}
	        }
	
		    if(arquivoTexto1 == NULL){
		        printf("ARQUIVO N�O ENCONTRADO... \n");
			}
		    else{
		        printf("\nINFORME O SABOR DA PIZZA.: ");
		        fflush(stdin);
		        gets(pizza);
		        printf("\nQUANTAS PIZZAS DE %s DESEJA?? ", pizza);
		        scanf("%i",&qtdPizzas);
		
		        while(fread(&pizzas, sizeof(PIZZA), 1, arquivoTexto1) == 1) {
		            if(strstr(pizza, pizzas.sabor) != NULL){
		               
					    printf("\nSABOR.: %s\n", pizzas.sabor);
		                strcpy(pedido.saborPizza, pizzas.sabor);
		                
						printf("VALOR.: R$ %.2f\n", pizzas.valor*qtdPizzas);
		                pedido.valorPizza = pizzas.valor*qtdPizzas;
		            }
		        }
		    }
		
		    if(arquivoTexto2 == NULL){
		    printf("ARQUIVO N�O ENCONTRADO... \n");
			}
			else {
				printf("\nINFORME A MARCA DA BEBIDA.: ");
				fflush(stdin);
				gets(bebid);
		        printf("\nQUANTOS(AS) %s DESEJA?? ", bebid);
		        scanf("%i",&qtdBebidas);
		
		        while(fread(&bebida, sizeof(BEBIDA), 1, arquivoTexto2) == 1) {
		            if(strstr(bebid, bebida.marca) !=NULL){
		               
					    printf("\nTIPO.: %s\n", bebida.tipo);
		                strcpy(pedido.tipoBebida, bebida.tipo);
		            
						printf("MARCA.: %s\n", bebida.marca);
		            	strcpy(pedido.marcaBebida, bebida.marca);
		            
						printf("VALOR.: R$ %.2f \n", bebida.valor*qtdBebidas);
		            	pedido.valorBebida = bebida.valor*qtdBebidas;
		            }
		        }
			}
			
		   	pedido.valorTotal = pizzas.valor*qtdPizzas + bebida.valor*qtdBebidas;
			printf("\nO VALOR TOTAL DO PEDIDO �.: R$ %.2f\n",pedido.valorTotal);	
			
		    fwrite(&pedido, sizeof(PEDIDO), 1, arquivoTexto3);
		}
	}
	
	

    //DESCARREGANDO O BUFFER
	fflush(stdin);
	//VERIFICA��O PARA CADASTRO DE NOVO CLIENTE
	printf("\n DESEJA CADASTRAR UM NOVO PEDIDO ?? \n");
	printf(" S - SIM ou N - N�O \n");
	//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
	scanf("%c", &sair);
	getchar();
	
	fclose(arquivoTexto);
	fclose(arquivoTexto1);
	fclose(arquivoTexto2);
    fclose(arquivoTexto3);
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE RECLAMACOES //
/* ------------------------------------------------------------------------------ */
void cadastraReclamacao(){
	//UTILIZANDO A ESTRUTURA
	RECLAMACAO reclamacoes;

	//PONTEIRO DE ARQUIVO PARA O ARQUIVO
	FILE * arquivoTexto;

	//APONTAR O PONTEIRO PARA UM ARQUIVO NA PASTA
	arquivoTexto = (fopen("reclamacoes.txt", "ab"));

	//LOOP QUE MANTEM USU�RIO NO MENU DE RECLAMA��ES
	do{

		system("CLS");

		//FUNCAO CABECALHO
		cabecalho();

		//ITERACAO
		printf("POR GENTILEZA INFORME OS DADOS SOLICITADOS PARA REGISTRARMOS A SUA RECLAMACAO \n");
		//CAMPO PARA ARMAZENAR O NOME DO CLIENTE
		fflush(stdin);
		printf(" INFORME O SEU NOME.: ");
		printf("");
        gets(reclamacoes.nome);

        //CAMPO PARA ARMAZENAR O TELEFONE DO CLIENTE
		printf(" INFORME O SEU TELEFONE.: ");
		printf("");
        gets(reclamacoes.telefone);

        //CAMPO PARA ARMAZENAR A MENSAGEM DO CLIENTE
		printf(" INFORME A SUA RECLAMA��O.: ");
		printf("");
        gets(reclamacoes.mensagem);

		//SALVANDO DADOS NO ARQUIVO
        fwrite(&reclamacoes, sizeof(RECLAMACAO), 1, arquivoTexto);

        printf(" \nA SUA RECLAMA��O FOI REGISTRADA, SENTIMOS MUITO PELO PROBLEMA E FAREMOS DE TUDO PARA MELHORARMOS. \n");
        //LOOP PARA MULTIPLAS RECLAMA��ES
	    //OPCAO PARA VOLTAR MENUS
		printf("\nDESEJA VOLTAR AO MENU ANTERIOR ?? \n");
		printf(" S - SIM ou N - N�O \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
		getchar();

	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE SUGEST�ES //
/* ------------------------------------------------------------------------------ */

void cadastraSugestao(){
	//UTILIZANDO A ESTRUTURA
	SUGESTAO sugestoes;

	//PONTEIRO DE ARQUIVO PARA O ARQUIVO
	FILE * arquivoTexto;

	//APONTAR O PONTEIRO PARA UM ARQUIVO NA PASTA
	arquivoTexto = (fopen("sugestoes.txt", "ab"));

	//LOOP QUE MANTEM USU�RIO NO MENU DE RECLAMA��ES
	do{

		system("CLS");

		//FUNCAO CABECALHO
		cabecalho();

    	//ITERACAO
		printf("POR GENTILEZA INFORME OS DADOS SOLICITADOS PARA REGISTRARMOS A SUA SUGEST�O \n");
		//CAMPO PARA ARMAZENAR O NOME DO CLIENTE
		fflush(stdin);
		printf(" INFORME O SEU NOME.: ");
		printf("");
        gets(sugestoes.nome);

        //CAMPO PARA ARMAZENAR O TELEFONE DO CLIENTE
		printf(" INFORME O SEU TELEFONE.: ");
		printf("");
        gets(sugestoes.telefone);

        //CAMPO PARA ARMAZENAR A MENSAGEM DO CLIENTE
		printf(" INFORME A SUA SUGEST�O.: ");
		printf("");
        gets(sugestoes.mensagem);

		//SALVANDO DADOS NO ARQUIVO
        fwrite(&sugestoes, sizeof(SUGESTAO), 1, arquivoTexto);

        printf(" \nA SUA SUGEST�O FOI REGISTRADA. A SUA OPINI�O � MUITO RELEVANTE PARA N�S. \n");
        //LOOP PARA MULTIPLAS RECLAMA��ES
		printf("\n DESEJA VOLTAR AO MENU ANTERIOR ?? \n");
		printf(" S - SIM ou N - N�O(VOLTAR AO MENU PRINCIPAL) \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
		getchar();
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE ELOGIOS //
/* ------------------------------------------------------------------------------ */
void cadastraElogio(){
	//UTILIZANDO A ESTRUTURA
	ELOGIO elogios;

	//PONTEIRO DE ARQUIVO PARA O ARQUIVO
	FILE * arquivoTexto;

	//APONTAR O PONTEIRO PARA UM ARQUIVO NA PASTA
	arquivoTexto = (fopen("elogios.txt", "ab"));

	//LOOP QUE MANTEM USU�RIO NO MENU DE RECLAMA��ES
	do{

		system("CLS");

		//FUNCAO CABECALHO
		cabecalho();

		//ITERACAO
		printf("POR GENTILEZA INFORME OS DADOS SOLICITADOS PARA REGISTRARMOS O SEU ELOGIO \n");
		//CAMPO PARA ARMAZENAR O NOME DO CLIENTE
		fflush(stdin);
		printf(" INFORME O SEU NOME.: ");
		printf("");
        gets(elogios.nome);

        //CAMPO PARA ARMAZENAR O TELEFONE DO CLIENTE
		printf(" INFORME O SEU TELEFONE.: ");
		printf("");
        gets(elogios.telefone);

        //CAMPO PARA ARMAZENAR A MENSAGEM DO CLIENTE
		printf(" INFORME O SEU ELOGIO.: ");
		printf("");
        gets(elogios.mensagem);


		//SALVANDO DADOS NO ARQUIVO
        fwrite(&elogios, sizeof(ELOGIO), 1, arquivoTexto);


        printf(" \nO SEU ELOGIO FOI REGISTRADO. OBRIGADO, VOLTE SEMPRE!!. \n");
        //LOOP PARA MULTIPLAS RECLAMA��ES
		printf("\n DESEJA CADASTRAR UM NOVO ELOGIO ?? \n");
		printf(" S - SIM ou N - N�O \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
		getchar();
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CADASTRO DE PROMO��ES //
/* ------------------------------------------------------------------------------ */

void cadastraPromocao(){
	//UTILIZANDO A ESTRUTURA
	PROMOCAO promocao;
	
	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("promocao.txt", "ab");
	
	//LOOP QUE MANTEM USU�RIO NO CADASTRO DE PROMOCAO
	do{

		system("CLS");

		//FUNCAO CABECALHO
		cabecalho();

		//ITERACAO
		printf("POR GENTILEZA INFORME AS INFORMA��ES DA NOVA PROMO��O \n");
		//CAMPO PARA ARMAZENAR O CODIGO DA PROMOCAO
		fflush(stdin);
		
	
		//CAMPO PARA ARMAZENAR O VALOR DA PROMOCAO
		printf(" INFORME O NUMERO DA PROMO��O.: ");
		printf("");
        gets(promocao.codigoPromocao);
		
        //CAMPO PARA ARMAZENAR A PIZZA DA PROMOCAO
		printf(" INFORME O SABOR DA PIZZA.: ");
		printf("");
        gets(promocao.saborPizza);

        //CAMPO PARA ARMAZENAR A BEBIDA DA PROMOCAO
		printf(" INFORME A MARCA DA BEBIDA.: ");
		printf("");
        gets(promocao.marcaBebida);

		//CAMPO PARA ARMAZENAR O VALOR DA PROMOCAO
		printf(" INFORME O VALOR TOTAL DA PROMO��O.: ");
		printf("");
        scanf("%f", &promocao.valorTotal);
		
		fflush(stdin);
		//SALVANDO DADOS NO ARQUIVO
        fwrite(&promocao, sizeof(PROMOCAO), 1, arquivoTexto);
	

        printf(" \n A PROMO��O FOI REGISTRADA COM SUCESSO. \n");
        //LOOP PARA MULTIPLAS RECLAMA��ES
		printf("\n DESEJA CADASTRAR UMA NOVA PROMO��O ?? \n");
		printf(" S - SIM ou N - N�O \n");
		//ARAMAZENAR OP��O DO USUARIO NA VARIAVEL
		scanf("%c", &sair);
		getchar();
	}while(sair != 'N' && sair != 'n'); //CONDI��O PARA SAIR DOS CADASTROS

}
	
	

/*** ==================================================================================== ****/
							//	FUN��ES DE CONSULTA	 //
/*** ==================================================================================== ****/


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE CLIENTE //
/* ------------------------------------------------------------------------------ */
void consultaCliente(){
	//VARIAVEL LOCAL
	CLIENTE cliente;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("cliente.txt", "rb");
	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&cliente, sizeof(CLIENTE), 1 ,arquivoTexto) == 1){
			printf("\nNOME.: %s \n", cliente.nome);
			printf("ENDERECO.: %s \n", cliente.endereco);
			printf("NUMERO.: %s \n", cliente.numero);
			printf("TELEFONE.: %s \n", cliente.telefone);
		}
	}

	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE PIZZAS //
/* ------------------------------------------------------------------------------ */
void consultaPizza(){
	//VARIAVEL LOCAL
	PIZZA pizzas;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("pizzas.txt", "rb");

	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&pizzas, sizeof(PIZZA), 1 ,arquivoTexto) == 1){
			printf("\n	SABOR.: %s \n", pizzas.sabor);
			printf("	VALOR.: R$ %.2f \n", pizzas.valor);
		}
	}
	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE FUNCIONARIO //
/* ------------------------------------------------------------------------------ */
void consultaFuncionario(){
	//VARIAVEL LOCAL
	FUNCIONARIO colaborador;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("funcionarios.txt", "rb");

	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&colaborador, sizeof(FUNCIONARIO), 1 ,arquivoTexto) == 1){
			printf("\n	NOME.: %s \n", colaborador.nome);
			printf("	CPF.: %s \n", colaborador.cpf);
			printf("	IDADE.: %i \n", colaborador.idade);
			printf("	SALARIO.: R$ %.2f \n", colaborador.salario);
		}
	}

	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE BEBIDAS //
/* ------------------------------------------------------------------------------ */
void consultaBebida(){
	//VARIAVEL LOCAL
	BEBIDA bebidas;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("bebidas.txt", "rb");

	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&bebidas, sizeof(BEBIDA), 1 ,arquivoTexto) == 1){
			printf("\n	TIPO.: %s \n", bebidas.tipo);
			printf("	MARCA.: %s \n", bebidas.marca);
			printf("	VALOR.: R$ %.2f \n", bebidas.valor);
		}
	}

	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE RECLAMA��ES //
/* ------------------------------------------------------------------------------ */
void consultaReclamacao(){
	//VARIAVEL LOCAL
	RECLAMACAO reclamacoes;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("reclamacoes.txt", "rb");

	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&reclamacoes, sizeof(RECLAMACAO), 1 ,arquivoTexto) == 1){
			printf("	\nNOME DO CLIENTE.: %s", reclamacoes.nome);
			printf("	TELEFONE DO CLIENTE.: %s", reclamacoes.telefone);
			printf("	RECLAMA��O.: %s\n", reclamacoes.mensagem);
		}
	}
	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE SUGEST�ES //
/* ------------------------------------------------------------------------------ */
void consultaSugestao(){
	//VARIAVEL LOCAL
	SUGESTAO sugestoes;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("sugestoes.txt", "rb");

	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&sugestoes, sizeof(SUGESTAO), 1 ,arquivoTexto) == 1){
			printf("	\nNOME DO CLIENTE.: %s", sugestoes.nome);
			printf("	TELEFONE DO CLIENTE.: %s", sugestoes.telefone);
			printf("	SUGEST�O.: %s\n", sugestoes.mensagem);
		}
	}

	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE ELOGIOS //
/* ------------------------------------------------------------------------------ */
void consultaElogio(){
	//VARIAVEL LOCAL
	ELOGIO elogios;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("elogios.txt", "rb");

	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&elogios, sizeof(ELOGIO), 1 ,arquivoTexto) == 1){
			printf("	\nNOME DO CLIENTE.: %s", elogios.nome);
			printf("	TELEFONE DO CLIENTE.: %s", elogios.telefone);
			printf("	ELOGIO.: %s\n", elogios.mensagem);
		}
	}

	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}

/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE PEDIDOS //
/* ------------------------------------------------------------------------------ */
void consultaPedido(){
	//VARIAVEL LOCAL
	PEDIDO pedidos;
	PIZZA pizzas;
	BEBIDA bebida;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("pedidos.txt", "rb");
	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&pedidos, sizeof(PEDIDO), 1 ,arquivoTexto) == 1){
			printf("\n   NOME DO CLIENTE.: %s \n", pedidos.nomeCliente);
			printf("   ENDERECO DO CLIENTE.: %s \n", pedidos.enderecoCliente);
			printf("   NUMERO DO CLIENTE.: %s \n", pedidos.numeroCliente);
			printf("   TELEFONE DO CLIENTE.: %s \n", pedidos.telefoneCliente);
			printf("   A PIZZA DO CLIENTE �.: %s \n", pedidos.saborPizza);
			printf("   O VALOR DA PIZZA � DE.: R$ %.2f \n", pedidos.valorPizza);
			printf("   O TIPO DE BEBIDA �.: %s \n", pedidos.tipoBebida);
			printf("   A MARCA DA BEBIDA PEDIDA PELO CLIENTE �.: %s \n", pedidos.marcaBebida);
			printf("   O VALOR DA BEBIDA � DE.: R$ %.2f \n", pedidos.valorBebida);
			printf("   O VALOR TOTAL DO PEDIDO � DE.: R$ %.2f \n", pedidos.valorTotal);
		}
	}


	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}


/* ------------------------------------------------------------------------------ */
						// FUN��O DE CONSULTA DE PROMOCOES //
/* ------------------------------------------------------------------------------ */
void consultaPromocao(){
	//VARIAVEL LOCAL
	PROMOCAO promocao;

	//ABRIR ARQUIVO TEXTO
	FILE * arquivoTexto;
	arquivoTexto = fopen("promocao.txt", "rb");

	//FUNCAO CABECALHO
	cabecalho();

	//CONDI��O PARA VERIFICAR ERROS DE ABERTURA DO ARQUIVO
	if(arquivoTexto == NULL){
		system("CLS");
		printf("O ARQUIVO N�O FOI ENCONTRADO... \n");
		printf("POR GENTILEZA VERIFIQUE SE FOI REALIZADO O CADASTRO CORRETAMENTE. \n");
		printf("EM CASO DE OUTROS PROBLEMAS CONTATE O ADMINISTRADOR DO SISTEMA.");
	}
	else{
		//LACO PARA LEITURA DE UM ARQUIVO CASO ELE SEJA DIFERENTE DE NULO
		while(fread(&promocao, sizeof(PROMOCAO), 1 ,arquivoTexto) == 1){
			printf("\n	O CODIGO DA PROMO��O �.: %s \n", promocao.codigoPromocao);
			printf("	O SABOR DA PIZZA �.: %s \n", promocao.saborPizza);
			printf("	A BEBIDA �.: %s \n", promocao.marcaBebida);
			printf("	O VALOR DA PROMOCAO �.: %.2f \n", promocao.valorTotal);
		}
	}

	//FECHA ARQUIVO TEXTO
	fclose(arquivoTexto);
}
