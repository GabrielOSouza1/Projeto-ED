#include <iostream>
#include <string>
#include <vector>
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
    private: // declarando o vectir como private para apenas os métodos da classe poderem acessa-lo e modifica-lo, ou seja nenhum codigo fora da classe pode mexer.
    vector<Participante> participantes; //é usado para armazenar todos os participantes adicionados à turma. permitindo que a classe mantenha uma lista dinâmica de participantes, que podem ser adicionados e removidos conforme necessário.


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
};