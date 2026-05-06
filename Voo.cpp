#include "Voo.h"
#include "Astronauta.h"
#include <iostream>

using namespace std;

vector<Voo> listaV;

void CADASTRAR_VOO(int codigo){
    for(int i=0; i<listaV.size(); i++){
        if(listaV[i].codigo == codigo){
            cout << "Já existe um voo cadastrado com esse código." << endl;
            return;
        }
    }

    Voo x;
    x.codigo = codigo;
    x.estado = 0;
    listaV.push_back(x);
    cout << "Voo " << codigo << " cadastrado" << endl;
}

void ADICIONAR_ASTRONAUTA(string cpf, int codigo){
    int contA = 0;
    int contB = 0;
    int posA, posV;

    for(int i=0; i<listaA.size(); i++){
       if(listaA[i].cpf == cpf){
            posA = i;
            contA++;
            break;
       }
    }

    for(int j=0; j<listaV.size(); j++){
        if(listaV[j].codigo == codigo){
            posV = j;
            contB++;
            break;
        }
    }

   if(contA == 0){
        cout << "Astronauta com CPF " << cpf << " não cadastrado."<< endl; 
        return;
   }
   if(contB == 0){
        cout << "Voo com código " << codigo << " não cadastrado." << endl; 
        return;
   }
   if(listaA[posA].vida != true){
        cout << "Astronauta com CPF " << cpf << " sem vida." << endl; 
        return;
   }
   if(listaV[posV].estado != 0){
        cout << "Voo com código " << codigo << " não planejado." << endl; 
        return;
   }

   for(int k=0; k<listaV[posV].cpfs.size(); k++){
        if(listaV[posV].cpfs[k] == cpf){
            cout << "Astronauta com cpf " << cpf << " ja esta nesse voo." << endl;
            return;
        }
   }
   
   listaV[posV].cpfs.push_back(cpf);

   cout << "Astronauta com CPF: " << cpf << " adicionado ao voo " << codigo << endl;
}

void REMOVER_ASTRONAUTA(string cpf, int codigo){
    int contA = 0;
    int contB = 0;
    int contC = 0;
    int posA, posV;


    for(int i=0; i<listaA.size(); i++){
       if(listaA[i].cpf == cpf){
            posA = i;
            contA++;
            break;
       }
    }

    for(int j=0; j<listaV.size(); j++){
        if(listaV[j].codigo == codigo){
            posV = j;
            contB++;
            break;
        }
    }

   if(contA == 0){
        cout << "Astronauta com CPF "<< cpf << " não cadastrado."<< endl; 
        return;
   }
   if(contB == 0){
        cout << "Voo com código " << codigo << " não cadastrado." << endl; 
        return;
   }

   for(int k=0; k<listaV[posV].cpfs.size(); k++){
        if(listaV[posV].cpfs[k] == cpf){
            contC++;
            break;
        }
    }

    if(listaA[posA].vida != true){
        cout << "Astronauta com CPF " << cpf << " sem vida." << endl; 
        return;
   }
   if(listaV[posV].estado != 0){
        cout << "Voo com código " << codigo << " não planejado." << endl; 
        return;
   }
    
    if(contC == 0){
        cout << "Astronauta com CPF "<< cpf << " não esta nesse voo."<< endl; 
        return;
    }

    for(int l=0; l<listaV[posV].cpfs.size(); l++){
        if(listaV[posV].cpfs[l] == cpf){
            listaV[posV].cpfs.erase(listaV[posV].cpfs.begin() + l);
            break;
        }
    }

    cout << "Astronauta com CPF: " << cpf << " removido do voo " << codigo << endl;
}

void LANCAR_VOO(int codigo){
    int contB = 0;
    int posV;

    for(int i=0; i<listaV.size(); i++){
        if(listaV[i].codigo == codigo){
            posV = i;
            contB++;
            break;
        }
    }

   if(contB == 0){
        cout << "Voo com código " << codigo << " não cadastrado." << endl; 
        return;
   }

   if(listaV[posV].estado != 0){
        cout << "Voo com código " << codigo << " não planejado." << endl; 
        return;
   }

   if(listaV[posV].cpfs.size() == 0){
        cout << "Voo com código " << codigo << " não possui tripulantes."<< endl;
        return;
   }

   for(int j=0; j<listaV[posV].cpfs.size(); j++){
        string cpf = listaV[posV].cpfs[j];
        for(int l=0; l<listaA.size(); l++){
            if(listaA[l].cpf == cpf){
                if(listaA[l].disponibilidade != true){
                    cout << "Astronauta com cpf " << cpf << " não está disponível.";
                    return;
                }
                if(listaA[l].vida != true){
                    cout << "Astronauta com cpf " << cpf << " sem vida.";
                    return;
                }
                break;
            }
        }
   }

   for(int j=0; j<listaV[posV].cpfs.size(); j++){
        string cpf = listaV[posV].cpfs[j];
        for(int l=0; l<listaA.size(); l++){
            if(listaA[l].cpf == cpf){
                listaA[l].disponibilidade = false;
                listaA[l].voos.push_back(codigo);
                break;
            }
        }
   }
   
   listaV[posV].estado = 1;
   cout << "Voo " << codigo << " lançado." << endl;
}

void EXPLODIR_VOO(int codigo){
    int contB = 0;
    int posV;

    for(int j=0; j<listaV.size(); j++){
        if(listaV[j].codigo == codigo){
            posV = j;
            contB++;
            break;
        }
    }
    
    if(contB == 0){
        cout << "Voo com código " << codigo << " não cadastrado." << endl; 
        return;
   }

   if(listaV[posV].estado != 1){
        cout << "Voo com codigo " << codigo << " não está em curso (não pode ser explodido)" << endl;
        return;
   }

   for(int i=0; i<listaV[posV].cpfs.size(); i++){
        string cpf = listaV[posV].cpfs[i];
        for(int j=0; j<listaA.size(); j++){
            if(listaA[j].cpf == cpf){
                listaA[j].vida = false;
                listaA[j].disponibilidade = false;
                break;
            }
        }
   }
   listaV[posV].estado = 3;

   cout << "Voo " << codigo << " explodido." << endl;
}

void FINALIZAR_VOO(int codigo){
    int contB = 0;
    int posV;

    for(int j=0; j<listaV.size(); j++){
        if(listaV[j].codigo == codigo){
            posV = j;
            contB++;
            break;
        }
    }
    
    if(contB == 0){
        cout << "Voo com código " << codigo << " não cadastrado." << endl; 
        return;
   }

   if(listaV[posV].estado != 1){
        cout << "Voo com codigo " << codigo << " não está em curso (não pode ser finalizado)" << endl;
        return;
   }

   for(int i=0; i<listaV[posV].cpfs.size(); i++){
        string cpf = listaV[posV].cpfs[i];
        for(int j=0; j<listaA.size(); j++){
            if(listaA[j].cpf == cpf){
                listaA[j].disponibilidade = true;
                break;
            }
        }
   }
   listaV[posV].estado = 2;

   cout << "Voo " << codigo << " finalizado com sucesso" << endl;
}

void LISTAR_VOOS(){
    if (listaV.size() == 0) {
        cout << "Nenhum voo cadastrado ate o momento." << endl;
        return;
    }

    bool planejado = false;
    bool curso = false;
    bool sucesso = false;
    bool explosao = false;

    for (int i = 0; i < listaV.size(); i++) {
        if(listaV[i].estado == 0){
            if(planejado != true){
                cout << "\n------ Voos planejados ------" << endl;
                planejado = true;
            }

            cout << "Voo: " << listaV[i].codigo << endl;
            cout << "Passageiros: " << endl;

            for(int j=0; j<listaV[i].cpfs.size(); j++){
                string cpf = listaV[i].cpfs[j];
                for(int l=0; l<listaA.size(); l++){
                    if(listaA[l].cpf == cpf){
                        cout << listaA[l].nome << " - " << "CPF: " << cpf << endl;
                        break;
                    }
                }
            }
            cout << "-----------------------------" << endl;
        }  
    }

    for (int i = 0; i < listaV.size(); i++) {
        if(listaV[i].estado == 1){
            if(curso != true){
                cout << "\n------ Voos em curso ------" << endl;
                curso = true;
            }

            cout << "Voo: " << listaV[i].codigo << endl;
            cout << "Passageiros: " << endl;

            for(int j=0; j<listaV[i].cpfs.size(); j++){
                string cpf = listaV[i].cpfs[j];
                for(int l=0; l<listaA.size(); l++){
                    if(listaA[l].cpf == cpf){
                        cout << listaA[l].nome << " - " << "CPF: " << cpf << endl;
                        break;
                    }
                }
            }
            cout << "-------------------------------" << endl;
        }  
    }

    for (int i = 0; i < listaV.size(); i++) {
        if(listaV[i].estado == 2){
            if(sucesso != true){
                cout << "\n------ Voos finalizados com sucesso ------" << endl;
                sucesso = true;
            }

            cout << "Voo: " << listaV[i].codigo << endl;
            cout << "Passageiros: " << endl;

            for(int j=0; j<listaV[i].cpfs.size(); j++){
                string cpf = listaV[i].cpfs[j];
                for(int l=0; l<listaA.size(); l++){
                    if(listaA[l].cpf == cpf){
                        cout << listaA[l].nome << " - " << "CPF: " << cpf << endl;
                        break;
                    }
                }
            }
            cout << "------------------------------------------" << endl;
        }  
    }

    for (int i = 0; i < listaV.size(); i++) {
        if(listaV[i].estado == 3){
            if(explosao != true){
                cout << "\n------ Voos finalizados com explosão ------" << endl;
                explosao = true;
            }

            cout << "Voo: " << listaV[i].codigo << endl;
            cout << "Passageiros: " << endl;

            for(int j=0; j<listaV[i].cpfs.size(); j++){
                string cpf = listaV[i].cpfs[j];
                for(int l=0; l<listaA.size(); l++){
                    if(listaA[l].cpf == cpf){
                        cout << listaA[l].nome << " - " <<"CPF: " << cpf << endl;
                        break;
                    }
                }
            }
            cout << "-------------------------------------------" << endl;
        }  
    }
}