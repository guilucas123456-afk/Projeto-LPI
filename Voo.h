#ifndef VOO_H
#define VOO_H

#include "Astronauta.h"
#include <string>
#include <vector>

class Voo{
public:
    int codigo;
    std::vector<std::string> cpfs;
    int estado;
};

extern std::vector<Voo> listaV;

void CADASTRAR_VOO(int codigo);
void ADICIONAR_ASTRONAUTA(std::string cpf, int codigo);
void REMOVER_ASTRONAUTA(std::string cpf, int codigo);
void LANCAR_VOO(int codigo);
void EXPLODIR_VOO(int codigo);
void FINALIZAR_VOO(int codigo);
void LISTAR_VOOS();

#endif