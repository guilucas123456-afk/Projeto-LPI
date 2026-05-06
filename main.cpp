#include <iostream>
#include <string>
#include <vector>
#include "Astronauta.h"
#include "Voo.h"

using namespace std;

int main(){
    string comando;
    while(cin >> comando){
        if(comando == "FIM"){
            break;
        }
    
        else if(comando == "CADASTRAR_ASTRONAUTA"){
            string cpf, nome;
            int idade;

            cin >> cpf >> idade;
            getline(cin >> ws, nome);
        
            CADASTRAR_ASTRONAUTA(cpf, idade, nome);

            
        }

        else if(comando == "CADASTRAR_VOO"){
            int codigo;
            cin >> codigo;
            CADASTRAR_VOO(codigo);
           
        }

        else if(comando == "ADICIONAR_ASTRONAUTA"){
            string cpf;
            int codigo;
            
            cin >> cpf >> codigo;
            ADICIONAR_ASTRONAUTA(cpf, codigo);
        }

        else if(comando == "REMOVER_ASTRONAUTA"){
            string cpf;
            int codigo;

            cin >> cpf >> codigo;
            REMOVER_ASTRONAUTA(cpf, codigo);
           
        }

        else if(comando == "LANCAR_VOO"){
            int codigo;

            cin >> codigo;
            LANCAR_VOO(codigo);
            
        }

        else if(comando == "EXPLODIR_VOO"){
            int codigo;
            
            cin >> codigo;
            EXPLODIR_VOO(codigo);
        }

        else if(comando == "FINALIZAR_VOO"){
            int codigo;
            
            cin >> codigo;
            FINALIZAR_VOO(codigo);
        }

        else if(comando == "LISTAR_VOOS"){
            LISTAR_VOOS();
        }

        else if(comando == "LISTAR_MORTOS"){
            LISTAR_MORTOS();
        }

        else{
            cout << "Comando inválido." << endl;
        }
    }
    return 0;
}