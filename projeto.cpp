#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Astronauta{
public:
    string cpf;
    string nome;
    int idade;
    bool vida;
    bool disponibilidade;
    vector<int> voos;
};

vector<Astronauta> listaA;

class Voo{
public:
    int codigo;
    vector<string> cpfs;
    int estado;
};

vector<Voo> listaV;

void CADASTRAR_ASTRONAUTA(string cpf, int idade, string nome){
    for(int i=0; i<listaA.size(); i++){
        if(listaA[i].cpf == cpf){
            cout << "Já existe um astronauta cadastrado com esse CPF." << endl;
            return;
        }
    }

    Astronauta x;
    x.cpf = cpf;
    x.nome = nome;
    x.idade = idade;
    x.vida = true;
    x.disponibilidade = true;
    listaA.push_back(x);
    cout << "Astronauta " << nome << " cadastrado" << endl;
}

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

void LISTAR_MORTOS(){
    cout << "\n----------- Lista de astronautas falecidos -----------" << endl;
    for(int i=0; i<listaA.size(); i++){
        if(listaA[i].vida == false){
            cout << "Nome: " << listaA[i].nome << endl;
            cout << "CPF: " << listaA[i].cpf << endl;
            cout << "Voos participados: ";
            for(int j=0; j<listaA[i].voos.size(); j++){
                cout << listaA[i].voos[j] << " ";
            }
            cout << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
}

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