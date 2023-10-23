#include <iostream>
#include <vector>

using namespace std;

class Paciente{
    
    string CPF;
    string DataNascimento;

    public:
    string Nome;

    Paciente (string NOME, string _CPF, string DATANASCIMENTO){
        this -> Nome = NOME;
        this -> CPF = _CPF;
        this -> DataNascimento = DATANASCIMENTO;
    }

    // ACESSANDO OS PRIVADOS GETS E SETS

    string getCPF(){
        return this -> CPF;
    }
    // VOID NÃO RETORNA A NADA
    void setCPF (string _CPF){
        this -> CPF = _CPF;
    }
    string getDataNascimento (){
       return this -> DataNascimento;
    }
    void setDataNascimento(){
        this -> DataNascimento;
    }


};

int main (){

}