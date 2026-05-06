#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
#include <vector>

class Astronauta {
public:
    std::string cpf;
    std::string nome;
    int idade;
    bool vida;
    bool disponibilidade;
    std::vector<int> voos;
};

extern std::vector<Astronauta> listaA;

void CADASTRAR_ASTRONAUTA(std::string cpf, int idade, std::string nome);
void LISTAR_MORTOS();

#endif