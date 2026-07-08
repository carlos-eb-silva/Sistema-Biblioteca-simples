# 📚 Sistema de Gerenciamento de Acervo e Empréstimos — BCZM

![C++](https://img.shields.io/badge/Linguagem-C++11-blue?style=flat-square\&logo=c%2B%2B)
![IDE](https://img.shields.io/badge/IDE-Code::Blocks-orange?style=flat-square)
![Status](https://img.shields.io/badge/Status-Concluído-brightgreen?style=flat-square)
![Licença](https://img.shields.io/badge/Licença-Uso%20Acadêmico-lightgrey?style=flat-square)

Sistema de gerenciamento de biblioteca desenvolvido em **C++**, capaz de realizar o cadastro de livros, controle de empréstimos e devoluções, pesquisa por títulos e persistência de dados em arquivo texto.

O projeto foi desenvolvido como atividade da disciplina **Algoritmos e Lógica de Programação**, ministrada pelo **Prof. Matheus Vitor de Andrade Pedrosa (UFRN)**, e representa um dos primeiros projetos completos desenvolvidos durante minha graduação em Engenharia Elétrica.

Além de cumprir os requisitos da disciplina, este repositório documenta meu processo de aprendizado em programação, registrando a evolução da organização do código e da aplicação de conceitos fundamentais da linguagem C++.

---

# 📌 Sumário

* [Visão Geral](#-visão-geral)
* [Funcionalidades](#-funcionalidades)
* [Conceitos Técnicos Aplicados](#-conceitos-técnicos-aplicados)
* [Estrutura do Projeto](#-estrutura-do-projeto)
* [Estrutura do Banco de Dados](#-estrutura-do-banco-de-dados)
* [Como Compilar e Executar](#-como-compilar-e-executar)
* [Menu do Sistema](#-menu-do-sistema)
* [Limitações e Melhorias Futuras](#-limitações-e-melhorias-futuras)
* [Autor](#-autor)

---

# 🔍 Visão Geral

O programa simula a rotina operacional de uma biblioteca fictícia inspirada na **BCZM**, operando integralmente através de uma interface de linha de comando (CLI).

Durante sua execução, os livros são armazenados dinamicamente em memória utilizando `std::vector`, enquanto todas as alterações realizadas são persistidas automaticamente em um arquivo texto (`database-biblioteca.txt`), garantindo que o acervo permaneça salvo entre diferentes execuções do programa.

O sistema suporta até **100 livros cadastrados simultaneamente**.

---

# 🚀 Funcionalidades

O sistema implementa as seguintes funcionalidades:

* ➕ Cadastro individual ou em lote de livros;
* 📖 Exibição completa do acervo;
* 🔎 Pesquisa por título (busca exata);
* 📚 Controle de empréstimos e devoluções;
* 📄 Exibição e confirmação de um termo de empréstimo antes da retirada do livro;
* 🔄 Alteração automática do status da obra (Disponível / Emprestado);
* 💾 Persistência automática dos dados em arquivo texto.

Durante a inicialização do programa ocorre a leitura do banco de dados existente.

Ao finalizar a aplicação, todas as alterações são gravadas automaticamente.

---

# 🧠 Conceitos Técnicos Aplicados

Este projeto serviu para consolidar diversos conceitos introdutórios da linguagem C++, entre eles:

### Estruturas de Dados

* Modelagem utilizando `struct Book`;
* Vetores dinâmicos (`std::vector<Book>`).

### Programação Modular

* Organização do programa em funções;
* Prototipagem de funções;
* Separação da lógica de cada operação.

### Passagem de Parâmetros

* Passagem por valor;
* Passagem por referência (`&`);
* Alteração direta de objetos compartilhados entre funções.

### Manipulação de Arquivos

Utilização da biblioteca `<fstream>` através de:

* `std::ifstream`
* `std::ofstream`

para leitura e escrita permanente do banco de dados.

### Conversão de Dados

Uso de:

```cpp
std::stoi()
```

para conversão de dados lidos do arquivo texto.

### Estruturas de Controle

O fluxo principal da aplicação é organizado por meio de:

* `switch`
* `case`
* laços de repetição
* estruturas condicionais.

Também foram implementadas validações simples para reduzir erros de entrada do usuário.

> **Observação:** O código contém diversos comentários pessoais registrando dúvidas, descobertas e aprendizados durante o desenvolvimento. Eles foram mantidos intencionalmente como parte do histórico de evolução do projeto.

---

# 🗂️ Estrutura do Projeto

```text
Sistema-Biblioteca-simples/
│
├── book-colection=CR.cpp
├── database-biblioteca.txt
├── output/
└── README.md
```

---

# 📄 Estrutura do Banco de Dados

O arquivo `database-biblioteca.txt` armazena cada livro utilizando quatro linhas consecutivas, seguidas por uma linha em branco.

```text
Título
Autor
Ano
Status (0 ou 1)

```

Onde:

* `0` → Disponível
* `1` → Emprestado

Essa estrutura simples permite serializar e reconstruir facilmente o vetor de livros durante a execução do programa.

---

# ▶️ Como Compilar e Executar

É necessário possuir um compilador compatível com **C++11** ou superior.

Linux:

```bash
g++ -std=c++11 -o biblioteca "book-colection=CR.cpp"
./biblioteca
```

Windows (MinGW):

```bash
g++ -std=c++11 -o biblioteca.exe "book-colection=CR.cpp"
biblioteca.exe
```

> O arquivo `database-biblioteca.txt` deve permanecer no mesmo diretório do executável para que a persistência funcione corretamente.

---

# 📋 Menu do Sistema

```text
(1) Cadastrar Livro

(2) Exibir Acervo

(3) Realizar Empréstimo ou Devolução

(4) Pesquisar Livro

(5) Fechar Programa
```

---

# 🔧 Limitações e Melhorias Futuras

Embora funcional, o projeto possui algumas limitações que poderão ser corrigidas em versões futuras:

* Busca sensível a letras maiúsculas e minúsculas;
* Pesquisa apenas por correspondência exata;
* Ausência de um identificador único (ISBN);
* Validação limitada das entradas do usuário;
* Interface exclusivamente em linha de comando;
* Código concentrado em um único arquivo fonte.

Como evolução natural do projeto, pretendo realizar uma refatoração completa utilizando múltiplos arquivos, por exemplo:

```text
main.cpp
book.cpp
book.h
database.cpp
database.h
utils.cpp
utils.h
```

Essa reorganização tornará o código mais modular, reutilizável e próximo das boas práticas empregadas em projetos profissionais de C++.

---

# 👤 Autor

**Carlos Eduardo Barbosa da Silva**

Graduando em Engenharia Elétrica — UFRN

Técnico em Eletromecânica — IFRN

GitHub: **@carlos-eb-silva**

---

# 📄 Licença

Este projeto foi desenvolvido para fins acadêmicos e educacionais.

Seu código pode ser utilizado como material de estudo, desde que sejam mantidos os devidos créditos ao autor.
