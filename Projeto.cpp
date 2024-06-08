#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Participante {
    int id;
    string nome;
    string semestre;
    int ano;
    string curso;
    Participante* proximo;
};

Participante* inicio = nullptr;

void adicionar_participante(int id, string nome, string semestre, int ano, string curso) {
    Participante* novo_participante = new Participante;
    novo_participante->id = id;
    novo_participante->nome = nome;
    novo_participante->semestre = semestre;
    novo_participante->ano = ano;
    novo_participante->curso = curso;
    novo_participante->proximo = nullptr;

    if (inicio == nullptr) {
        inicio = novo_participante;
    } else {
        Participante* atual = inicio;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = novo_participante;
    }
}

void mostrar_participantes() {
    cout << "Lista de participantes do café:" << endl;
    Participante* atual = inicio;
    if (atual == nullptr) {
        cout << "Nenhum participante cadastrado." << endl;
    } else {
        while (atual != nullptr) {
            cout << "ID: " << atual->id << endl
                 << "Nome: " << atual->nome << endl
                 << "Semestre: " << atual->semestre << endl
                 << "Ano ingressante: " << atual->ano << endl
                 << "Curso: " << atual->curso << endl << endl;
            atual = atual->proximo;
        }
    }
}

void salvar_participantes_em_arquivo(const string& nome_arquivo) {
    ofstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita: " << nome_arquivo << endl;
        return;
    }

    Participante* atual = inicio;
    while (atual != nullptr) {
        arquivo << atual->id << "|" << atual->nome << "|" << atual->semestre << "|"
                << atual->ano << "|" << atual->curso << endl;
        atual = atual->proximo;
    }

    arquivo.close();
}

Participante* buscar_id(int id) {
    Participante* atual = inicio;
    while (atual != nullptr) {
        if (atual->id == id) {
            return atual;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

void editar_dados(int id) {
    Participante* participante = buscar_id(id);
    if (participante != nullptr) {
        cout << "Editar dados do participante com ID " << id << endl;
        cout << "Novo nome: ";
        cin.ignore();
        getline(cin, participante->nome);
        cin >> participante->nome
        cout << "Novo semestre: ";
        getline(cin, participante->semestre);
        cin >> participante->semestre;
        cout << "Novo ano: ";
        cin >> participante->ano;
        cout << "Novo curso (DSM/SI/GE): ";
        cin >> participante->curso;
        cout << "Dados do participante atualizados com sucesso!" << endl;
    } else {
        cout << "Participante com ID " << id << " não encontrado." << endl;
    }
}

struct Contribuicao {
    int id;
    int mes;
    int ano;
    double valor;
    Contribuicao* proximo;
};

Contribuicao* inicio_contribuicoes = nullptr;

void adicionar_contribuicao(int id, int mes, int ano, double valor) {
    Participante* participante = buscar_id(id);
    if (participante == nullptr) {
        cout << "Participante com ID " << id << " não encontrado. Contribuição não cadastrada." << endl;
        return;
    }

    Contribuicao* nova_contribuicao = new Contribuicao;
    nova_contribuicao->id = id;
    nova_contribuicao->mes = mes;
    nova_contribuicao->ano = ano;
    nova_contribuicao->valor = valor;
    nova_contribuicao->proximo = nullptr;

    if (inicio_contribuicoes == nullptr) {
        inicio_contribuicoes = nova_contribuicao;
    } else {
        Contribuicao* atual = inicio_contribuicoes;
        while (atual->proximo != nullptr) {
            atual = atual->proximo;
        }
        atual->proximo = nova_contribuicao;
    }

    cout << "Contribuição adicionada com sucesso!" << endl;
}

void cadastrar_contribuicao() {
    int id, mes, ano;
    double valor;
    cout << "ID do participante: ";
    cin >> id;
    cout << "Mês da contribuição (1-12): ";
    cin >> mes;
    cout << "Ano da contribuição (>= 2024): ";
    cin >> ano;
    cout << "Valor da contribuição: ";
    cin >> valor;

    adicionar_contribuicao(id, mes, ano, valor);
}

void salvar_contribuicoes_em_arquivo(const string& nome_arquivo) {
    ofstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para escrita: " << nome_arquivo << endl;
        return;
    }

    Contribuicao* atual = inicio_contribuicoes;
    while (atual != nullptr) {
        arquivo << atual->id << "|" << atual->mes << "|" << atual->ano << "|"
                << atual->valor << endl;
        atual = atual->proximo;
    }

    arquivo.close();
}

int main() {
    

    int opcao;
    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar participante" << endl;
        cout << "2. Mostrar participantes" << endl;
        cout << "3. Salvar participantes em arquivo" << endl; 
        cout << "4. Editar dados de participante" << endl;
        cout << "5. Cadastrar contribuição" << endl; // Nova opção no menu
        cout << "6. Salvar contribuições em arquivo" << endl; // Nova opção no menu
        cout << "7. Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        cin.ignore();
        
        switch(opcao) {
            case 1: {
                int id, ano;
                string nome, semestre, curso;
                cout << "Qual seu ID: ";
                cin >> id;
                cout << "Qual seu nome: ";
                cin.ignore();
                cin >> nome;
                cout << "Em qual semestre você está: ";
                cin >> semestre;
                cout << "Em qual ano você entrou: ";
                cin >> ano;
                cout << "Qual curso você está cursando (DSM/GE/SI): ";
                cin >> curso;
                adicionar_participante(id, nome, semestre, ano, curso);
                cout << "Participante adicionado com sucesso!" << endl;
                break;
            }
            case 2:
                mostrar_participantes();
                break;
            case 3: {
                salvar_participantes_em_arquivo("participantes.txt");
                cout << "Participantes salvos em arquivo." << endl;
                break;
            }
             case 4: {
                int id;
                cout << "ID do participante a ser editado: ";
                cin >> id;
                editar_dados(id);
                break;
            }
            case 5:
                cadastrar_contribuicao(); // Chama a função para cadastrar contribuição
                break;
            case 6: {
                salvar_contribuicoes_em_arquivo("contribuintes.txt");
                cout << "Contribuições salvas em arquivo." << endl;
                break;
            }
            case 7: {
                cout << "Saindo..." << endl;
                break;
            }
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while(opcao != 7);

    
    Participante* atual = inicio;
    while (atual != nullptr) {
        Participante* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    
    Contribuicao* atual_contribuicao = inicio_contribuicoes;
    while (atual_contribuicao != nullptr) {
        Contribuicao* proxima = atual_contribuicao->proximo;
        delete atual_contribuicao;
        atual_contribuicao = proxima;
    }

    return 0;
}
