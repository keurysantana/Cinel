// JogoForca.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

//Protótipos

void desenharForca(int boneco);
void carregarPalavras();
void jogarSozinho();
void desenharPalavra(string palavra, char letras[]);
void jogarDuplas();
bool jogar(string palavra);

string palavras[7];

int main()
{
    SetConsoleOutputCP(1252);
    carregarPalavras();
    int modoJogo;
    cout << "\n\t---BEM VINDO AO JOGO DA FORCA-----" << endl;
    cout << "\n\t Primeiro escolha se gostaria de Jogar Sozinho ou Jogar em dupla" << endl;
    cout << "\n\tPara jogar sozinho digite 1 para jogar em dupla digite 2" << endl;
    cout << "\n\tDigite o número correspondente a opção desejada: " << endl;
    cin >> modoJogo;

    if (modoJogo == 1)
    {
        cout << "\n\tVocê escolheu jogar sozinho. Vamos começar o jogo! " << endl;
        jogarSozinho();
    }
    else if (modoJogo == 2)
    {
        cout << "\n\tVocê escolheu jogar em dupla. Vamos começar o jogo!" << endl;
        jogarDuplas();
    }
    else
        cout << "\n\tOpção Inválida, tente novamente.";

}

void desenharForca(int boneco) 
{
    cout << "-------" ;
    cout << "\n\t |   ";
    if(boneco >=1)  cout << "O"; 
    cout << "\n\t |  ";
    if (boneco >=2) cout << "/";
    if (boneco >=3) cout << "|";
    if (boneco >=4) cout << "\\" ;
    cout << "\n\t |  ";
    if (boneco >=5) cout << "/";
    if (boneco >=6) cout << " \\";

}

void carregarPalavras() {
    ifstream fread;     
    string str;         
    fread.open("C:\\Users\\keury\\Desktop\\EFA\\LinguagemC\\JogoForca\\frutas.txt");

    if (fread.fail()) {
        cout << "\n\tErro na abertura do ficheiro para leitura!" << endl;
        exit(1);
    }
    else {
        int i = 0;
        while (getline(fread, str))
        {
            palavras[i] = str;
            i++;
        }
        fread.close();  
    }

}

void jogarSozinho() 
{
    srand(time(0));
    int numPalavra = (rand() % 7) + 1;
    string palavra = palavras[numPalavra];
    jogar(palavra);
}

void desenharPalavra(string palavra, char letras[])
{
    cout << "\n\t";
    for (char letra: palavra) {
        if (strchr(letras, letra)) {
            cout << " " << letra;
        }
        else {
            cout << " _";
        }
    }
}

bool jogar(string palavra) 
{
    string letrasRestantes = palavra;
    int erros = 0;
    bool acertou = false;
    char letras[26];
    int indice = 0;
    while (erros < 6 && !acertou)
    {
        cout << "\n\t";
        desenharForca(erros);
        desenharPalavra(palavra, letras);
        cout << "\n\t";
        cout << "\n\tDigite a letra que você acha que tem na palavra: " << endl;
        cin >> letras[indice];
        if (palavra.find(letras[indice]) != string::npos) //ver se o caractere está na string
        {
            //remove as letras da palavra
            size_t pos;
            while ((pos = letrasRestantes.find(letras[indice])) != string::npos) {
                letrasRestantes.erase(pos, 1);
            }
            acertou = letrasRestantes.length() == 0;
        }
        else {
            erros++;
        }
        indice++;
    }
    if (erros >= 6) {
        desenharForca(erros);
        cout << "\n\tGame Over!";
        return false;
    }
    else if (acertou) {
        cout << "\n\tParabéns, você ganhou!";
        return true;
    }
}

void jogarDuplas() 
{
    string palavra;
    int score1 = 0, score2 = 0;
    cout << "\n\tJogador 1 Digite a palavra: ";
    cin >> palavra;
    system("cls");
    if (jogar(palavra))
        score1+=10;
    cout << "\n\tJogar 2 Digite a palavra: ";
    cin >> palavra;
    system("cls");
    if (jogar(palavra))
        score2+=10;
    
    ofstream fwrite;
    fwrite.open("C:\\Users\\keury\\Desktop\\EFA\\LinguagemC\\JogoForca\\pontuacaoFinal.txt");
    fwrite << "\n\tScore1 " << score1;
    fwrite << "\n\tScore2 " << score2;
    fwrite.close();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
