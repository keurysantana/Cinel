// Conceitos Básicos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

//#include <iostream>
#include <stdio.h>    //diretiva para inclusão da biblioteca padrao do C (funções de input, output e erros)
//n pular tinha /t espaço tab
//funcao principal do programa
int main()
{
	printf("Ola! Este e o primeiro programa em linguagem C...");
	//declaração das variáveis
	int x;
	//declaração e inicialização de variável
	int y = 0;

	//declaração múltipla de vavriáveis do mesmo tipo
	int a = 0, b= 0, c =0;
	//atribuição de valores a variáveis
	x = 10;
	a = x + y;
	printf("\n\t O valor de a = %d", a);
	printf("Digite um valor inteiro: ");
	scanf_s("%d", &y);
	a = x + y;
	printf("\n\t O valor de a = %d", a);

}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
