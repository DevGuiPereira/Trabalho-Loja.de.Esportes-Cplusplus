#include <iostream> // entrada de dados
#include <string> // para uso de strings dentro do programa
#include <vector> // serve para colocar os valores dentro de vetores
#include <locale.h>// serve para colocar s�mbolos na linguagem escrita, EX: �,~, �...
#include <stdlib.h>// serve para colocar os comandos de apagar a tela
#include <windows.h>// serve para colocar o timer no programa

using namespace std;

struct Pessoa {     //todas as vari�veis relacionadas a pessoas/cadrastar pessoar
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

struct Produto {     //todas as vari�veis relacionadas a produtos/cadrastar produtos
    string descricao;
    string modelo;
    string marca;
    string tamanho;
    string cor;
    float preco;
};

struct ItemProduto {      //todas as vari�veis relacionadas a produtos/cadrastar itemProduto
    Produto produto;
    string dataCompra;
    float valorCompra;
    string situacao;
};

struct Venda {     //todas as vari�veis relacionadas a venda/venda produto
    Produto produto;
    Pessoa cliente;
    float valorVenda;
    string dataVenda;
    string dataRecebimento;
    string situacao;
};

vector<Pessoa> pessoas;
vector<Produto> produtos;
vector<ItemProduto> itensProdutos;     // todos os vetores servem para armazenar as informa��es digitadas pelo usu�rio (como se fosse um banco de dados)
vector<Venda> vendas;

void cadastrarPessoa() {    //fun��o de cadastrar as pessoas
    Pessoa pessoa;
    
    cout << "Cadastro de Pessoas" << endl;      // � usado getline para guardar os dados digitados no lugar certo
    cout << "Nome: ";
    getline(cin, pessoa.nome);
    cout << "CPF: ";
    getline(cin, pessoa.cpf);
    cout << "Sexo: ";
    getline(cin, pessoa.sexo);
    cout << "Data de Nascimento: ";
    getline(cin, pessoa.dataNascimento);
    cout << "Endere�o: ";
    getline(cin, pessoa.endereco);
    cout << "Time Favorito: ";
    getline(cin, pessoa.timeFavorito);
    cout << "Sele��o Favorita: ";
    getline(cin, pessoa.selecaoFavorita);
    cout << "Gosta de Futebol (S/N): ";
    char resposta;
    cin >> resposta;
    pessoa.gostaFutebol = (resposta == 'S' || resposta == 's');
    cout << "Gosta de V�lei (S/N): ";
    cin >> resposta;
    pessoa.gostaVolei = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Basquete (S/N): ";
    cin >> resposta;
    pessoa.gostaBasquete = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Handbol (S/N): ";
    cin >> resposta;
    pessoa.gostaHandbol = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Nata��o (S/N): ";
    cin >> resposta;
    pessoa.gostaNatacao = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Ciclismo (S/N): ";
    cin >> resposta;
    pessoa.gostaCiclismo = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Atletismo (S/N): ";
    cin >> resposta;
    pessoa.gostaAtletismo = (resposta == 'S' || resposta == 's');
    cout << "Gosta de Muscula��o (S/N): ";
    cin >> resposta;
    pessoa.gostaMusculacao = (resposta == 'S' || resposta == 's');
    
    cin.ignore(); // Limpar o buffer do teclado
    
    pessoas.push_back(pessoa);    // salva os dados digitados e abaixo mostra uma mensagem de sucesso no cadastro
    cout << "Pessoa cadastrada com sucesso!" << endl;
	int tempodeespera = 4;
	Sleep(tempodeespera*1000);  // aqui fica um tempo de espera para visualiza��o do usu�rio
	system("cls");
}

void cadastrarProduto() {     //fun��o para cadastrar produtos
    Produto produto;
    
    cout << "Cadastro de Produtos" << endl;    // � usado getline para guardar os dados digitados no lugar certo
    cout << "Descri��o: ";
    getline(cin, produto.descricao);
    cout << "Modelo: ";
    getline(cin, produto.modelo);
    cout << "Marca: ";
    getline(cin, produto.marca);
    cout << "Tamanho: ";
    getline(cin, produto.tamanho);
    cout << "Cor: ";
    getline(cin, produto.cor);
    cout << "Pre�o: ";
    cin >> produto.preco;
    
    cin.ignore();    // Limpar o buffer do teclado
    
    produtos.push_back(produto);      // salva os dados digitados e abaixo mostra uma mensagem de sucesso no cadastro
    cout << "Produto cadastrado com sucesso!" << endl;
	int tempodeespera = 4;           // aqui fica um tempo de espera para visualiza��o do usu�rio
	Sleep(tempodeespera*1000);
	system("cls");
}

void cadastrarItemProduto() {       //fun��o de cadastrar item produto
    ItemProduto item;
    
    cout << "Cadastro de Itens de Produtos" << endl;
    
    // Selecionar um produto existente
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado. Cadastre um produto antes de cadastrar um item." << endl;    // exibe uma mensagem de erro quando o produto n�o est� cadastrado no sistema
        return;
    }
    
    cout << "Produtos dispon�veis:" << endl;          // aqui mostra a lista de produtos que est�o cadastrados no sistema
    for (size_t i = 0; i < produtos.size(); i++) {
        cout << i+1 << ". " << produtos[i].descricao << endl;
    }
    
    int produtoIndex;
    cout << "Selecione o produto (digite o n�mero): ";   // aqui serve para que o usu�rio digite o n�mero do produto
    cin >> produtoIndex;
    
    if (produtoIndex < 1 || produtoIndex > produtos.size()) {    // aqui mostra uma mensagem de erro caso o n�mero do produto n�o exista
        cout << "Produto selecionado inv�lido!" << endl;
        return;
    }
    
    item.produto = produtos[produtoIndex-1];
    
    cin.ignore(); // Limpar o buffer do teclado
    
    cout << "Data da compra: ";   // � usado getline para guardar os dados digitados no lugar certo
    getline(cin, item.dataCompra);
    cout << "Valor da compra: ";
    cin >> item.valorCompra;
    cin.ignore(); // Limpar o buffer do teclado
    cout << "Situa��o: ";
    getline(cin, item.situacao);
    
    itensProdutos.push_back(item);    // salva todos os dados digitados pelo usu�rio e exibe mensagem de sucesso no cadastro de item de produto
    cout << "Item cadastrado com sucesso!" << endl;
	int tempodeespera = 4;  // aqui fica um tempo de espera para visualiza��o do usu�rio
	Sleep(tempodeespera*1000);
	system("cls");
}

void cadastrarVenda() {       //fun��o de cadastrar as vendas
    Venda venda;
    
    cout << "Cadastro de Venda" << endl;
    
    // Selecionar um produto existente
    if (produtos.empty()) {
        cout << "Nenhum produto cadastrado. Cadastre um produto antes de cadastrar uma venda." << endl;  // exibe uma mensagem de erro quando o produto n�o est� cadastrado no sistema
        return;
    }
    
    cout << "Produtos dispon�veis:" << endl;
    for (size_t i = 0; i < produtos.size(); i++) {      // aqui mostra todos os produtos dispon�veis para fazer o cadastro de venda no sistema
        cout << i+1 << ". " << produtos[i].descricao << endl;
    }
    
    int produtoIndex;
    cout << "Selecione o produto (digite o n�mero): ";
    cin >> produtoIndex;
    
    if (produtoIndex < 1 || produtoIndex > produtos.size()) {   //aqui mostra a mensagem de erro caso o sistema n�o reconhe�a o produto
        cout << "Produto selecionado inv�lido!" << endl;
        return;
    }
    
    venda.produto = produtos[produtoIndex-1];
    
    cin.ignore(); // Limpar o buffer do teclado
    
    cout << "Cliente: ";        // � usado getline para guardar os dados digitados no lugar certo
    getline(cin, venda.cliente.nome);
    cout << "Valor da venda: ";
    cin >> venda.valorVenda;
    cin.ignore(); // Limpar o buffer do teclado
    cout << "Data da venda: ";
    getline(cin, venda.dataVenda);
    cout << "Data do recebimento: ";
    getline(cin, venda.dataRecebimento);
    cout << "Situa��o: ";
    getline(cin, venda.situacao);
    
    vendas.push_back(venda);   // salva todos os dados digitados pelo usu�rio e exibe mensagem de sucesso no cadastro de venda de produto
    cout << "Venda cadastrada com sucesso!" << endl;
    int tempodeespera = 4;  // aqui fica um tempo de espera para visualiza��o do usu�rio
	Sleep(tempodeespera*1000);
	system("cls");
}

void listarProdutosPorPreco(float preco) {          //fun��o de listar os produtos
    cout << "Produtos com pre�o igual a " << preco << ":" << endl;
    
    bool found = false;

	for (vector<Produto>::const_iterator it = produtos.begin(); it != produtos.end(); ++it) {  // aqui serve para puxar as informa��es digitadas dentro da vector produto
	    const Produto& produto = *it;
	    if (produto.preco == preco) {     // mostra a rela��o de produtos conforme o pre�o digitado pelo usu�rio
	        cout << "Descri��o: " << produto.descricao << endl;
	        cout << "Modelo: " << produto.modelo << endl;
	        cout << "Marca: " << produto.marca << endl;
	        cout << "Tamanho: " << produto.tamanho << endl;
	        cout << "Cor: " << produto.cor << endl;
	        cout << "Pre�o: " << produto.preco << endl;
	        found = true;
	    }
	}
	
	if (!found) {
	    cout << "Nenhum produto encontrado com preco igual a " << preco << endl;    // exibe mensagem de erro caso o pre�o de produto n�o exista no sistema
	}
	int tempodeespera = 4;  // aqui fica um tempo de espera para visualiza��o do usu�rio
	Sleep(tempodeespera*1000);
	system("cls");
}

void listarUltimasVendas(int numVendas) {      //fun��o de listas as �ltimas vendas
    cout << "Ultimas " << numVendas << " vendas:" << endl;
    
    int startIndex = vendas.size() - numVendas;
    if (startIndex < 0) {
        startIndex = 0;
    }
    
    for (int i = startIndex; i < vendas.size(); i++) {      // aqui serve para listar todas as informa��es dos produtos vendidos
        const Venda& venda = vendas[i];
        cout << "Produto: " << venda.produto.descricao << endl;
        cout << "Cliente: " << venda.cliente.nome << endl;
        cout << "Valor da venda: " << venda.valorVenda << endl;
        cout << "Data da venda: " << venda.dataVenda << endl;
        cout << "Data do recebimento: " << venda.dataRecebimento << endl;
        cout << "Situa��o: " << venda.situacao << endl;
        cout << endl;
    }
    int tempodeespera = 4;  // aqui fica um tempo de espera para visualiza��o do usu�rio
	Sleep(tempodeespera*1000);
	system("cls");
}

int main() {      //int main para mostrar o menus e executar as fun��es acima
    int opcao;
    setlocale(LC_ALL,"portuguese");
    
    do {
        cout << "Menu de Op��es" << endl;
        cout << "1. Cadastro de Pessoas" << endl;
        cout << "2. Cadastro de Produtos" << endl;
        cout << "3. Cadastro de Itens de Produtos" << endl;
        cout << "4. Cadastro de Venda" << endl;
        cout << "5. Listagem de produtos com determinado pre�o" << endl;
        cout << "6. Listagem das �ltimas vendas" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;
        cin.ignore(); // Limpar o buffer do teclado
        cout << endl;
        
        switch (opcao) {    // aqui vai chamar uma das fun��es acima, conforme op��o do usu�rio
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
                cout << "Digite o pre�o: ";
                cin >> preco;
                listarProdutosPorPreco(preco);
                break;
            case 6:
                int numVendas;
                cout << "Digite o n�mero de vendas: ";
                cin >> numVendas;
                listarUltimasVendas(numVendas);
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Op��o inv�lida!" << endl;
                break;
        }

        cout << endl;
       
	   // Serve para limpar o que j� foi feito para que come�e denovo o programa ou saia dele
	    int tempodeespera = 1;  // aqui fica um tempo de espera para visualiza��o do usu�rio
	    Sleep(tempodeespera*1000);
	    system("cls");    //comando de limpar a tela
        
    } while (opcao != 0);
    
    return 0;
}
