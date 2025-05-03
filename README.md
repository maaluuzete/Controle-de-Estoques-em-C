# Controle de Estoques em C
Feito com base no exercício [Controle de Estoques em C](https://neps.academy/br/course/alocacao-dinamica-e-arquivos/lesson/controle-de-estoques-em-c), do [Neps Academy](https://neps.academy/). Um sistema simples, desenvolvido em linguagem C, que permite gerenciar um estoque básico de produtos diretamente via terminal. Com esse programa, é possível adicionar, remover e listar itens de forma prática, utilizando arquivos para armazenar os dados.

## Demonstração
Quando executado, o software exibe o seguinte menu no terminal:
```
================================
   Controle de Estoque
================================
Selecione uma opção:
1. Adicionar Item
2. Remover Item
3. Listar Estoque
4. Sair
Opção:
```
Por exemplo, se o usuário escolher a opcão 1, ele irá ser guiado para adicionar um novo produto, este item é adicionado ao `estoque.txt`.
```
Digite o nome do item: Caneta
Digite a quantidade: 50
Item adicionado com sucesso!
```

## Instalação e Pré-requisitos
Para compilar e executar a calculadora em C, é necessário ter o compilador GCC (GNU Compiler Collection) instalado em seu sistema. Abaixo, estão as instruções resumidas para os principais sistemas operacionais:
- **Windows**
  - Baixe o MinGW-w64:
  Acesse a página oficial do MinGW-w64 e baixe o instalador apropriado para o seu sistema: [MinGW-w64](https://www.mingw-w64.org)
  Abra o prompt de comando e digite `gcc --version` para verificar se o compilador GCC está instalado corretamente.
- **Linux**
  - Abra um terminal e execute os seguintes comandos:
```
// Para Debian/Ubuntu, com o apt:
sudo apt-get update
sudo apt-get install gcc

// Para Arch Linux:
sudo pacman -S gcc
```
## Estrutura do Projeto
Este projeto possui a seguinte estrutura:   

```
    Controledeestoque/  
    │── controledeestoqueemc/
    │   └── main.c
    │   └── estoque.txt
    │── LICENSE 
    │── README.md  
    
```
* `controledeestoqueemc` contém a `main.c` que contém o código fonte do estoque, e o arquivo `estoque.txt` utilizado para manter os dados dos itens registrados.
* `assets` contém todos os arquivos de mídia ou de informação usados no projeto.
* Este arquivo é o próprio `README.md`. Ele tem informações sobre o projeto.
* `LICENSE` contém toda a licença do projeto.
## Licença
Esse projeto está licenciado sob a licença MIT. Para mais detalhes, acesse o arquivo [LICENSE](https://github.com/maaluuzete/Controle-de-Estoques-em-C?tab=MIT-1-ov-file) desse repositório.
