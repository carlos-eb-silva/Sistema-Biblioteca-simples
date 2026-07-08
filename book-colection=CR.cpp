// Projeto criado a partir de uma atividade em Sala de aula da Disciplina: Algoritimos e Lógica de Programação, ministrada pelo Professor: Prof. Matheus Vitor de Andrade Pedrosa.
// Autor: Carlos Eduardo Barbosa da Silva
// Data: 20/06/2025
// Descrição: Sistema de cadastro e emprestimo de livros simples de uma biblioteca. O sistema permite cadastrar livros, exibir o acervo, realizar emprestimos e devoluções, pesquisar livros e salvar os dados em um arquivo de texto para persistência.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct Book
{
    string Title, Author;
    int Year;
    bool status_loan = false;
};

// Os Protótipos das funções
void B_register(vector<Book> &Estante, int &cadastrados);
void Acerv(const vector<Book> &Estante, const int cadastrados);
void Loan(vector<Book> &Estante, const int cadadtrados);
void SearchBook(const vector<Book> &Estante, int cadastrados);

// Frotótipo das funções para mexer no arquivo .txt
void SaveDatabase(const vector<Book> &Estante); // Função para Salvar dados no database
void LoadDatabase(vector<Book> &Estante, int &cadastrados); // Função para carregar os dados

int main()
{
    int option;
    int cadastrados = 0; // Defini uma variavel dos cadastrados, então as passei como parametro da função.
    vector<Book> Estante;

    LoadDatabase(Estante, cadastrados);

    cout << "Ola! Bem vindo ao sistema de cadastro e emprestino da BCZM!\n" << endl;
    do{
    // Selecao de opcoes do usuario
    cout << "\nSelecione as seguintes opcoes: ";
    cout << "\n(1) Cadastrar Livro.\n(2) Exibir Acervo\n(3) Realizar emprestimo ou devolucao\n(4) Pesquisar Livro\n(5) Fechar" << endl;
    cin >> option;
    cin.ignore();

        switch(option){
    case 1:
        B_register(Estante, cadastrados);
        break;
    case 2:
        Acerv(Estante, cadastrados);
        break;
    case 3:
        Loan(Estante, cadastrados);
        break;
    case 4:
        SearchBook(Estante, cadastrados);
        break;
    case 5:
        cout << "Lembre-se: Literatura salva um pais!\n-----Fechando o Programa-----" << endl;
        break;
    default:
        cout << "Comando nao reconhecido" << endl;
        break;
        }
    } while(option != 5);

     SaveDatabase(Estante);
return 0;
}


// Função para registra
void B_register(vector<Book> &Estante, int &cadastrados){
    int numbers;

    cout << "\n[Registrador de Livros]\n";
    cout << "Escolha o numero de livros que deseja cadastar: ";
    cin >> numbers;
    cin.ignore();

    if (numbers <= 0){
        cout << "Valor invalido de livros.\n";
    } else if(numbers + cadastrados > 100){
        cout << "Nosso acervo ja possue " << cadastrados << " Livros cadastrados, nosso acervo comporta ate 100 livros.\n";
    } else {
        // O loop vai iterar apenas a quantidade de vezes que o usuário pediu agora
        for(int i = 0; i < numbers; i++){
            Book novoLivro; // variável temporária

            cout << "\nLivro " << cadastrados + i + 1 << endl;

            cout << "Titulo da obra: ";
            getline(cin, novoLivro.Title); // Lemos os dados para o livro temporário

            cout << "Autor: ";
            getline(cin, novoLivro.Author);

            cout << "Ano de lancamento: ";
            cin >> novoLivro.Year;
            cin.ignore();

            Estante.push_back(novoLivro);
        }
        // OBS: essa fução estava com um problema que ele buscava dados da
        cadastrados += numbers;

        
    }

}

// Funcao para exibir o acervo
void Acerv(const vector<Book> &Estante, int cadastrados){
    cout << "\n[Exibindo Acervo]\n";

    if (cadastrados == 0){
        cout << "Nao ha algum livro em nosso acervo nesse instante.\n";
        return;
    }

    for(int j=0; j<cadastrados; j++){
        cout << " Livro n" << j+1 << endl;
        cout << "     TITULO: " << Estante[j].Title << endl;
        cout << "     AUTOR: " << Estante[j].Author << endl;
        cout << "     ANO DE PUB.: " << Estante[j].Year << endl;
        cout << "     STATUS: " << (Estante[j].status_loan ? "Indisponivel" : "Disponivel") << endl;
        cout << endl;
    }
}
// funcao para emprestimos
void Loan(vector<Book> &Estante, const int cadastrados) {
    int n; //livro
    char R; //resposta

    cout << "\n[Emprestimo ou Devolucao]\n";
    cout << "Qual livro deseja acessar? N: ";
    cin >> n;

    if (n <= 0 || n > cadastrados) {
        cout << "Esse livro nao existe em nosso acervo.\n";
        return;
    }

    cout << "\nLivro n" << n << endl;
    cout << "    TITULO: " << Estante[n - 1].Title << endl;
    cout << "    AUTOR: " << Estante[n - 1].Author << endl;
    cout << "    ANO DE PUB.: " << Estante[n - 1].Year << endl;
    cout << "    STATUS: " << (Estante[n - 1].status_loan ? "Indisponivel" : "Disponivel") << endl; // Descobri esse operador "?" pesquisando. otimiza mt

    // DEVOLUÇÃO
    if (Estante[n - 1].status_loan) {
        cout << "Este livro ja esta emprestado. Deseja realizar a devolucao? (s/n): ";
        cin >> R;
        if (R == 's' || R == 'S') {
            Estante[n - 1].status_loan = false;
            cout << "DEVOLUCAO REALIZADA COM SUCESSO!\n";
        } else {
            cout << "Operacao cancelada.\n";
        }
    } else { // EMPRESTIMO
        cout << "Deseja realizar o emprestimo? (s/n): ";
        cin >> R;
        if (R == 's' || R == 'S') {
            cout << "-------------------------\nTERMOS DE EMPRESTIMO\n-------------------------\n";
            cout << "1 - Concordo em realizar a Devolucao em ate 2 semanas.\n";
            cout << "CONCORDA COM OS TERMOS? (s/n): ";
            char Termos;
            cin >> Termos;

            if (Termos == 's' || Termos == 'S') {
                Estante[n - 1].status_loan = true;
                cout << "EMPRESTIMO REALIZADO COM SUCESSO!\n";
            } else if (Termos == 'n' || Termos == 'N'){
                cout << "Termos nao aceitos. Emprestimo cancelado.\n";
            } else { cout << "Operacao cancelada."; }
        }
    }
}
// Função para buscar livro
void SearchBook(const vector<Book> &Estante, const int cadastrados){
    string buscar_livro;
    bool Achoo = false;

    cout << "[Pesquisar Livros]" << endl;

    if (cadastrados == 0) {
        cout << "Ainda nao existe nenhum livro em nosso acervo.\n";
        return;
    }

    cout << "Digite o Nome do livro que deseja buscar: ";
getline(cin, buscar_livro);

    for(int k = 0; k < cadastrados; k++){
        if(buscar_livro == Estante[k].Title){
            cout << "\n--- Livro Encontrado ---" << endl;
            cout << "NUMERO DE ESTANTE: " << k+1 << endl;
            cout << "TITULO: " << Estante[k].Title << endl;
            cout << "AUTOR: " << Estante[k].Author << endl;
            cout << "ANO DE PUBLICACAO: " << Estante[k].Year << endl;
            cout << "STATUS: " << (Estante[k].status_loan ? "Emprestado" : "Disponivel") << endl;
            cout << "------------------------" << endl;
            Achoo = true;
            return;
        }
    }
    if (!Achoo){
        cout << "Nenhum livro com titulo '" << buscar_livro << "' foi achado em nosso Acervo." << endl;
    }
}

//--- FUNÇÕES DO DATABASE---

void SaveDatabase(const vector<Book> &Estante) {
    std::ofstream Database("database-biblioteca.txt");

    for (const Book &livro : Estante) {
        Database << livro.Title << "\n";
        Database << livro.Author << "\n";
        Database << livro.Year << "\n";
        Database << livro.status_loan << "\n";
        Database << "\n"; // separador
    }
    Database.close();
}

void LoadDatabase(vector<Book> &Estante, int &cadastrados) { // ← & adicionado
    std::ifstream Database("database-biblioteca.txt");

    if (!Database.is_open()) {
        cout << "Nenhum banco de dados encontrado. Iniciando vazio.\n";
        return;
    }

    Book livro; // é uma variável temporária do tipo Book  que será preenchida com os dados de cada livro lido e depois copiada para o vetor
    string linha; 

    while (getline(Database, livro.Title)) {
        if (livro.Title.empty()) continue; // ignora linhas em branco extras

        getline(Database, livro.Author);
        getline(Database, linha);
        livro.Year = std::stoi(linha); // o ano é uma variavel int, como o getline lê em string, ele não identifica. É dai que surgue esse std::stoi(linha). Ele converte o que estpa
        getline(Database, linha);
        livro.status_loan = (linha == "1");
        getline(Database, linha); // ele ignora a linha que eu coloquei de separação

        Estante.push_back(livro);
        cadastrados++;
    }
}