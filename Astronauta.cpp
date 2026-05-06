#include "Astronauta.h"
#include <iostream>

using namespace std;

vector<Astronauta> listaA;

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