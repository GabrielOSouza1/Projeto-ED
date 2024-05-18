#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>


using namespace std;


// aqui estou criando uma struct para armazenar os dados do participante
struct Participante
{
    int id;
    string nome;
    string semestre;
    int ano;
    string curso;
};

// criar um classe para gerenciar a turma do café

class TurmaDoCafe{
private:
    list<Participante> participantes; //é usado para armazenar todos os participantes adicionados à turma. permitindo que a classe mantenha uma lista dinâmica de participantes, que podem ser adicionados e removidos conforme necessário.


public: 

// adicionar participante 
    void adicionar_participante(int id, string nome, string semestre, int ano, string curso) /* Esta linha define a assinatura do método */ {
        Participante novo_participante = {id, nome, semestre, ano, curso}; // Esta é uma variável que criEI para armazenar as informações do participante que queremos adicionar à turma, como uma ficha em branco
        participantes.push_back(novo_participante); // estou dizendo que a ficha preenchida com os dados do novo participante sera adicionada ao final da lista
    }

    void mostrar_participantes() {
        cout << "lista de participantes do cafézin!!";
            for(const auto& participante : participantes) /* Este é um loop que percorre todos os participantes na lista */ {
                cout << "ID: " << participante.id << endl << "Nome: " << participante.nome << endl << "Semestre: " << participante.semestre << endl << "Ano ingressante: " << participante.ano << endl << "Curso: " << endl;
            }
    }

    Participante* buscar_id(int id) {
        for(auto& participante : participantes){
            if (participante.id == id) //  verifica se o id do participante atual é igual ao id fornecido como parâmetro
            {
            return &participante;
            }
            
        }
        return nullptr;

        // se ele econtrar um participante ele retorna um pornteiro para esse participante, caso contrario retorna nullptr para indicar que o participante não foi encontrado.
    }

    // inserindo código para editar os dados dos participantes, meno o ID

   
    // Método para editar dados do participante (exceto o ID)
    void editar_dados(int id) {
        Participante* participante = buscar_id(id);
        if (participante) {
            cout << "Editar dados do participante com ID " << id << endl;
            cout << "Nome: ";
            cin >>  participante->nome;
            cout << "Semestre: ";
            cin >> participante->semestre;
            cout << "Ano: ";
            cin >> participante->ano;
            cout << "Curso DSM/SI/GE: ";
            cin >> participante->curso;
            cout << "Dados do participante atualizados com sucesso!" << endl;
        } else {
            cout << "Participante com ID " << id << " não encontrado." << endl;
        }
    }

        
};

 int main() {
    TurmaDoCafe turma_cafe;
     // Função para inserir novos participantes
        auto inserir_participante = [&turma_cafe]() {
            cout << "Inserir novo louco por café" << endl;
            int id;
            string nome, semestre, curso;
            int ano;
            cout << "Qual seu id: ";
            cin >> id;
            cin.ignore(); 
            cout << "Qual seu nome (pode ser so o primeiro)";
            cin >> nome;
            cout << "Em qual semestre você está?: ";
            cin >> semestre;
            cout << "em qual ano você entrou: ";
            cin >> ano;
            cout << "Qual curso você está cursando DSM/GE/SI";
            cin >> curso;
            turma_cafe.adicionar_participante(id, nome, semestre, ano, curso);
            cout << "Participante adicionado com sucesso!" << endl;



        };

        //Função para editar participantes
        auto editar_dados = [&turma_cafe](){
            cout << "Editar dados!!" << endl;
            int id;
           cout << "ID do participante a ser editado: ";
            cin >> id;
            cin.ignore(); // Limpar o buffer do teclado
            turma_cafe.editar_dados(id);
        };
 };
