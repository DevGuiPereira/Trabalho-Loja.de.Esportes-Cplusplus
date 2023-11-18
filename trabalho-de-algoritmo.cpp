#include <iostream> // entrada de dados
#include <string> // para uso de strings dentro do programa
#include <vector> // serve para colocar os valores dentro de vetores
#include <locale.h>// serve para colocar símbolos na linguagem escrita, EX: ç,~, ´...
#include <stdlib.h>// serve para colocar os comandos de apagar a tela
#include <windows.h>// serve para colocar o timer no programa

using namespace std;

struct Pessoa {     //todas as variáveis relacionadas a pessoas/cadrastar pessoar
    string nome;
    string cpf;
    string sexo;
    string dataNascimento;
    string endereco;
    string timeFavorito;
    string selecaoFavorita;
    bool gostaFutebol;
    bool gostaVolei;
    bool gostaBasquete;
    bool gostaHandbol;
    bool gostaNatacao;
    bool gostaCiclismo;
    bool gostaAtletismo;
    bool gostaMusculacao;
};

struct Produto {     //todas as variáveis relacionadas a produtos/cadrastar produtos
    string descricao;
    string modelo;
    string marca;
    string tamanho;
    string cor;
    float preco;
};

struct ItemProduto {      //todas as variáveis relacionadas a produtos/cadrastar itemProduto
    Produto produto;
    string dataCompra;
    float valorCompra;
    string situacao;
};

struct Venda {     //todas as variáveis relacionadas a venda/venda produto
    Produto produto;
    Pessoa cliente;
    float valorVenda;
    string dataVenda;
    string dataRecebimento;
    string situacao;
};

vector<Pessoa> pessoas;
vector<Produto> produtos;
vector<ItemProduto> itensProdutos;     // todos os vetores servem para armazenar as informações digitadas pelo usuário (como se fosse um banco de dados)
vector<Venda> vendas;

void cadastrarPessoa() {    //função de cadastrar as pessoas
    Pessoa pessoa;
    
    cout << "Cadastro de Pessoas" << endl;      // é usado getline para guardar os dados digitados no lugar certo
    cout << "Nome: ";
    getline(cin, pessoa.nome);
    cout << "CPF: ";
    getline(cin, pessoa.cpf);
    cout << "Sexo: ";
    getline(cin, pessoa.sexo);
    cout << "Data de Nascimento: ";
    getline(cin, pessoa.dataNascimento);
    cout << "Endereço: ";
    getline(cin, pessoa.endereco);
    cout << "Time Favorito: ";
    getline(cin, pessoa.timeFavorito);
    cout << "Seleção Favorita: ";
    getline(cin, pessoa.selecaoFavorita);
    cout << "Gosta de Futebol (S/N): ";
    char resposta;
    cin >> resposta;
    pessoa.gostaFutebol = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Vôlei (S/N): ";
    cin >> resposta;
    pessoa.gostaVolei = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Basquete (S/N): ";
    cin >> resposta;
    pessoa.gostaBasquete = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Handbol (S/N): ";
    cin >> resposta;
    pessoa.gostaHandbol = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Natação (S/N): ";
    cin >> resposta;
    pessoa.gostaNatacao = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Ciclismo (S/N): ";
    cin >> resposta;
    pessoa.gostaCiclismo = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Atletismo (S/N): ";
    cin >> resposta;
    pessoa.gostaAtletismo = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Musculação (S/N): ";
    cin >> resposta;
    pessoa.gostaMusculacao = (resposta == 'S' || resposta == 's');
    
    cin.ignore(); // Limpar o buffer do teclado
    
    pessoas.push_back(pessoa);    // salva os dados digitados e abaixo mostra uma mensagem de sucesso no cadastro
    cout << "Pessoa cadastrada com sucesso!" << endl;
	int tempodeespera = 4;
	Sleep(tempodeespera*1000);  // aqui fica um tempo de espera para visualização do usuário
	system("cls");
}

void cadastrarProduto() {     //função para cadastrar produtos
    Produto produto;
    
    cout << "Cadastro de Produtos" << endl;    // é usado getline para guardar os dados digitados no lugar certo
    cout << "Descrição: ";
    getline(cin, produto.descricao);
    cout << "Modelo: ";
    getline(cin, produto.modelo);
    cout << "Marca: ";
    getline(cin, produto.marca);
    cout << "Tamanho: ";
    getline(cin, produto.tamanho);
    cout << "Cor: ";
    getline(cin, produto.cor);
    cout << "Preço: ";
    cin >> produto.preco;
    
    cin.ignore();    // Limpar o buffer do teclado
    
    produtos.push_back(produto);      // salva os dados digitados e abaixo mostra uma mensagem de sucesso no cadastro
    cout << "Produto cadastrado com sucesso!" << endl;
	int tempodeespera = 4;           // aqui fica um tempo de espera para visualização do usuário
	Sleep(tempodeespera*1000);
	system("cls");
}

void cadastrarItemProduto() {       //função de cadastrar item produto
    ItemProduto item;
    
    cout << "Cadastro de Itens de Produtos" << endl;
    
    // Selecionar um produto existente
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado. Cadastre um produto antes de cadastrar um item." << endl;    // exibe uma mensagem de erro quando o produto não está cadastrado no sistema
        return;
    }
    
    cout << "Produtos disponíveis:" << endl;          // aqui mostra a lista de produtos que estão cadastrados no sistema
    for (size_t i = 0; i < produtos.size(); i++) {
        cout << i+1 << ". " << produtos[i].descricao << endl;
    }
    
    int produtoIndex;
    cout << "Selecione o produto (digite o número): ";   // aqui serve para que o usuário digite o número do produto
    cin >> produtoIndex;
    
    if (produtoIndex < 1 || produtoIndex > produtos.size()) {    // aqui mostra uma mensagem de erro caso o número do produto não exista
        cout << "Produto selecionado inválido!" << endl;
        return;
    }
    
    item.produto = produtos[produtoIndex-1];
    
    cin.ignore(); // Limpar o buffer do teclado
    
    cout << "Data da compra: ";   // é usado getline para guardar os dados digitados no lugar certo
    getline(cin, item.dataCompra);
    cout << "Valor da compra: ";
    cin >> item.valorCompra;
    cin.ignore(); // Limpar o buffer do teclado
    cout << "Situação: ";
    getline(cin, item.situacao);
    
    itensProdutos.push_back(item);    // salva todos os dados digitados pelo usuário e exibe mensagem de sucesso no cadastro de item de produto
    cout << "Item cadastrado com sucesso!" << endl;
	int tempodeespera = 4;  // aqui fica um tempo de espera para visualização do usuário
	Sleep(tempodeespera*1000);
	system("cls");
}

void cadastrarVenda() {       //função de cadastrar as vendas
    Venda venda;
    
    cout << "Cadastro de Venda" << endl;
    
    // Selecionar um produto existente
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado. Cadastre um produto antes de cadastrar uma venda." << endl;  // exibe uma mensagem de erro quando o produto não está cadastrado no sistema
        return;
    }
    
    cout << "Produtos disponíveis:" << endl;
    for (size_t i = 0; i < produtos.size(); i++) {      // aqui mostra todos os produtos disponíveis para fazer o cadastro de venda no sistema
        cout << i+1 << ". " << produtos[i].descricao << endl;
    }
    
    int produtoIndex;
    cout << "Selecione o produto (digite o número): ";
    cin >> produtoIndex;
    
    if (produtoIndex < 1 || produtoIndex > produtos.size()) {   //aqui mostra a mensagem de erro caso o sistema não reconheça o produto
        cout << "Produto selecionado inválido!" << endl;
        return;
    }
    
    venda.produto = produtos[produtoIndex-1];
    
    cin.ignore(); // Limpar o buffer do teclado
    
    cout << "Cliente: ";        // é usado getline para guardar os dados digitados no lugar certo
    getline(cin, venda.cliente.nome);
    cout << "Valor da venda: ";
    cin >> venda.valorVenda;
    cin.ignore(); // Limpar o buffer do teclado
    cout << "Data da venda: ";
    getline(cin, venda.dataVenda);
    cout << "Data do recebimento: ";
    getline(cin, venda.dataRecebimento);
    cout << "Situação: ";
    getline(cin, venda.situacao);
    
    vendas.push_back(venda);   // salva todos os dados digitados pelo usuário e exibe mensagem de sucesso no cadastro de venda de produto
    cout << "Venda cadastrada com sucesso!" << endl;
    int tempodeespera = 4;  // aqui fica um tempo de espera para visualização do usuário
	Sleep(tempodeespera*1000);
	system("cls");
}

void listarProdutosPorPreco(float preco) {          //função de listar os produtos
    cout << "Produtos com preço igual a " << preco << ":" << endl;
    
    bool found = false;

	for (vector<Produto>::const_iterator it = produtos.begin(); it != produtos.end(); ++it) {  // aqui serve para puxar as informações digitadas dentro da vector produto
	    const Produto& produto = *it;
	    if (produto.preco == preco) {     // mostra a relação de produtos conforme o preço digitado pelo usuário
	        cout << "Descrição: " << produto.descricao << endl;
	        cout << "Modelo: " << produto.modelo << endl;
	        cout << "Marca: " << produto.marca << endl;
	        cout << "Tamanho: " << produto.tamanho << endl;
	        cout << "Cor: " << produto.cor << endl;
	        cout << "Preço: " << produto.preco << endl;
	        found = true;
	    }
	}
	
	if (!found) {
	    cout << "Nenhum produto encontrado com preco igual a " << preco << endl;    // exibe mensagem de erro caso o preço de produto não exista no sistema
	}
	int tempodeespera = 4;  // aqui fica um tempo de espera para visualização do usuário
	Sleep(tempodeespera*1000);
	system("cls");
}

void listarUltimasVendas(int numVendas) {      //função de listas as últimas vendas
    cout << "Ultimas " << numVendas << " vendas:" << endl;
    
    int startIndex = vendas.size() - numVendas;
    if (startIndex < 0) {
        startIndex = 0;
    }
    
    for (int i = startIndex; i < vendas.size(); i++) {      // aqui serve para listar todas as informações dos produtos vendidos
        const Venda& venda = vendas[i];
        cout << "Produto: " << venda.produto.descricao << endl;
        cout << "Cliente: " << venda.cliente.nome << endl;
        cout << "Valor da venda: " << venda.valorVenda << endl;
        cout << "Data da venda: " << venda.dataVenda << endl;
        cout << "Data do recebimento: " << venda.dataRecebimento << endl;
        cout << "Situação: " << venda.situacao << endl;
        cout << endl;
    }
    int tempodeespera = 4;  // aqui fica um tempo de espera para visualização do usuário
	Sleep(tempodeespera*1000);
	system("cls");
}

int main() {      //int main para mostrar o menus e executar as funções acima
    int opcao;
    setlocale(LC_ALL,"portuguese");
    
    do {
        cout << "Menu de Opções" << endl;
        cout << "1. Cadastro de Pessoas" << endl;
        cout << "2. Cadastro de Produtos" << endl;
        cout << "3. Cadastro de Itens de Produtos" << endl;
        cout << "4. Cadastro de Venda" << endl;
        cout << "5. Listagem de produtos com determinado preço" << endl;
        cout << "6. Listagem das últimas vendas" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); // Limpar o buffer do teclado
        cout << endl;
        
        switch (opcao) {    // aqui vai chamar uma das funções acima, conforme opção do usuário
            case 1:
                cadastrarPessoa();
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                cadastrarItemProduto();
                break;
            case 4:
                cadastrarVenda();
                break;
            case 5:
                float preco;
                cout << "Digite o preço: ";
                cin >> preco;
                listarProdutosPorPreco(preco);
                break;
            case 6:
                int numVendas;
                cout << "Digite o número de vendas: ";
                cin >> numVendas;
                listarUltimasVendas(numVendas);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }

        cout << endl;
       
	   // Serve para limpar o que já foi feito para que começe denovo o programa ou saia dele
	    int tempodeespera = 1;  // aqui fica um tempo de espera para visualização do usuário
	    Sleep(tempodeespera*1000);
	    system("cls");    //comando de limpar a tela
        
    } while (opcao != 0);
    
    return 0;
}
