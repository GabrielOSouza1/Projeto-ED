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

void ler_participantes_de_arquivo(const string& nome_arquivo) {
    ifstream arquivo(nome_arquivo);
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo " << nome_arquivo << endl;
        return;
    }

    int id, ano;
    string nome, semestre, curso;
    while (arquivo >>  id >> nome >> semestre >> ano >> curso) {
        adicionar_participante(id, nome, semestre, ano, curso);
    }

    arquivo.close();
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
        cout << "Novo semestre: ";
        getline(cin, participante->semestre);
        cout << "Novo ano: ";
        cin >> participante->ano;
        cout << "Novo curso (DSM/SI/GE): ";
        cin >> participante->curso;
        cout << "Dados do participante atualizados com sucesso!" << endl;
    } else {
        cout << "Participante com ID " << id << " não encontrado." << endl;
    }
}

int main() {
    // Carregar os participantes do arquivo ao iniciar o programa
    ler_participantes_de_arquivo("participantes.txt");

    int opcao;
    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Adicionar participante" << endl;
        cout << "2. Mostrar participantes" << endl;
        cout << "3. Salvar participantes em arquivo" << endl; // Opção adicionada
        cout << "4. Editar dados de participante" << endl;
        cout << "5. Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        
        switch(opcao) {
            case 1: {
                int id, ano;
                string nome, semestre, curso;
                cout << "Qual seu ID: ";
                cin >> id;
                cout << "Qual seu nome: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Em qual semestre você está: ";
                getline(cin, semestre);
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
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while(opcao != 5);

    // Limpar a memória alocada para os participantes
    Participante* atual = inicio;
    while (atual != nullptr) {
        Participante* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }

    return 0;
}
