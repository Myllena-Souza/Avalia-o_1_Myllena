#include <iostream>
#include <vector>

using namespace std;

class Paciente{
    
    string CPF;
    string DataNascimento;

    public:
    string Nome;
    vector<Paciente*> Pacientes;

    Paciente (string NOME, string _CPF, string DATANASCIMENTO){
        this -> Nome = NOME;
        this -> CPF = _CPF;
        this -> DataNascimento = DATANASCIMENTO;
    }

    string getCPF(){
        return this -> CPF;
    }
    
    void setCPF (string _CPF){
        this -> CPF = _CPF;
    }
    string getDataNascimento (){
       return this -> DataNascimento;
    }
    void setDataNascimento(string DATANASCIMENTO){
        this -> DataNascimento = DATANASCIMENTO;
    }
};
class Medico{

    string CRM;
    string Especialidade;
    
    public:
    string Nome;

    Medico(string NOME, string _CRM, string ESPECIALIDADE){
        this -> Nome =  NOME;
        this -> CRM = _CRM;
        this -> Especialidade = ESPECIALIDADE;
    }
    string getCRM (){
        return this -> CRM;
    }
    void setCRM (string _CRM){
        this -> CRM = _CRM;
    }
    string getEspecialidade(){
        return this -> Especialidade;
    }
    void setEspecialidade (string ESPECIALIDADE){
        this -> Especialidade = ESPECIALIDADE;
    }
    
};

class Principal{
    public:

    vector<Paciente*> Pacientes;

    int LocalizarCPF ( vector<Paciente*> _Pacientes, string CPF){
        int i=0;
            for(auto el : _Pacientes){
                if(el -> getCPF () == CPF){
                    return i;
                }
                i++;
            } return -1;
    }

    vector<Medico*> Medicos;

    int LocalizarCRM(vector<Medico*> _Medicos, string _CRM){
        int i=0;
                for(auto el : _Medicos){
                    if(el->getCRM() == _CRM){
                        return i;
                    }
                    i++;
                } return -1;
    }

    void Gestao_Paciente (){

        int Opcao;

        do{
            cout << "Escolha uma opcao abaixo: " << endl;
            cout << "1- Incluir" << endl;
            cout << "2- Excluir" << endl;
            cout << "3- Alterar (somente pelo CPF)" << endl;
            cout << "4- Listar" << endl;
            cout << "5- Localizar (somente por CPF)" << endl;
            cout << "0- Voltar" << endl;
            cin >> Opcao;

            string auxNome, auxCPF, auxDataNascimento;
            if (Opcao==1){
                bool condicao = 0;

                cout << "Digite o nome: ";
                getline(cin >> ws, auxNome);
                do{
                    cout << "Digite o CPF com 11 digitos, no seguinte formato xxx.xxx.xxx-xx: ";

                    getline(cin >>ws, auxCPF);
                    if(auxCPF.length()!=11){
                    condicao = 0;
                    cout <<"Formato invalido, digite novamente." << endl;

                    }
                    else{
                    int posicao = LocalizarCPF (Pacientes, auxCPF);
                    if(posicao < 0){
                        condicao = 1;
                    }
                    else{
                        cout << "O CPF ja foi adicionado" << endl;
                            condicao = 0;
                    }

                    }

                }while(condicao == 0);

                cout << "Digite a data de nascimento no seguinte modelo DD MM AAAA: ";
                getline(cin >> ws, auxDataNascimento);

                Paciente *paciente = new Paciente(auxNome, auxCPF, auxDataNascimento);
                Pacientes.push_back(paciente);
            }
            else if (Opcao==2){
                    cout << "Digite o CPF que deseja excluir: " << endl;
                    getline(cin >> ws, auxCPF);

                    int posicao = LocalizarCPF(Pacientes, auxCPF);
                    if(posicao < 0)
                        cout << "Paciente não encontraddo" << endl;
                    else{
                        delete Pacientes [posicao];
                        Pacientes.erase(Pacientes.begin() + posicao);
                        cout << "O paciente foi excluido!" << endl; 
                    }
            }
            else if(Opcao==3){
                    int alterar = 0;
                    cout << "Informe o CPF do paciente que deseja modificar: " << endl;
                    getline(cin >> ws, auxCPF);

                    int posicao = LocalizarCPF(Pacientes, auxCPF);

                    if(posicao < 0)
                        cout << "Paciente não encontraddo" << endl;
                    else{

                        cout << "Estes são os dados atuais do CPF citado: " << endl;
                        cout << "Nome: " << Pacientes.at(posicao)-> Nome << endl;
                        cout << "Data de nascimento: " << Pacientes.at(posicao)-> getDataNascimento() << endl;
                        cout << "Selecione a opcao que deseja alterar" << endl;
                        cout << "1- Alterar Nome" << endl;
                        cout << "2- Alterar Data de nascimento" << endl;
                        cout << "3- Alterar ambos" << endl;
                        cout << "0- Voltar" << endl;
                        cin >> alterar;

                        if(alterar == 1){
                            cout << "Digite o novo nome do paciente: ";
                            getline(cin >> ws, Pacientes.at(posicao) -> Nome);

                        }else if(alterar == 2){
                            cout << "Digite a nova data de nacimento do paciente: ";
                            getline(cin >> ws, auxDataNascimento);
                            Pacientes.at(posicao) -> setDataNascimento(auxDataNascimento);
                        }
                        else if (alterar == 3){
                            cout << "Informe o novo nome do paciente: ";
                            getline(cin >> ws, Pacientes.at(posicao) -> Nome);
                            cout << "Informe a nova data de nascimento: ";
                            getline(cin >> ws, auxDataNascimento);
                            Pacientes.at(posicao) -> setDataNascimento(auxDataNascimento);
                        }
                        else if (alterar == 0){

                        }else{
                            cout << "Opcao Invalida!" << endl;
                        }
                    }
            }

            else if (Opcao == 4){
                for(auto el : Pacientes){
                    cout << el -> Nome << endl;
                    cout << el -> getCPF() << endl;
                    cout << el -> getDataNascimento() << endl;
                    cout << endl;
                }
            }

            else if (Opcao == 5){
                 cout << "Informe o CPF que deseja localizar: ";
                getline(cin >>ws, auxCPF);

                int posicao = LocalizarCPF(Pacientes, auxCPF);
                if(posicao <0)
                cout << "Paciente nao encontrado" << endl;
                else{
                    cout << Pacientes.at(posicao) -> Nome << endl;
                    cout << Pacientes.at(posicao) -> getDataNascimento() << endl;
                }
            }
            else if (Opcao == 0){
            }
            else{
                cout << "Opcao Invalida";
            }    
        }while (Opcao != 0);
    };

    void Gestao_Medico(){
        int Opcao;

        do{
        cout << "Escolha uma opcao abaixo: " << endl;
        cout << "1- Incluir" << endl;
        cout << "2- Excluir" << endl;
        cout << "3- Alterar (somente pelo CRM)" << endl;
        cout << "4- Listar" << endl;
        cout << "5- Localizar (somente por CRM)" << endl;
        cout << "0- Voltar" << endl;
        cin >> Opcao;

        string auxNome, auxCRM, auxEspecialidade;

        if (Opcao==1){
            bool condicao = 0;

            cout << "Digite o nome: ";
            getline(cin >> ws, auxNome);

            do{
                cout << "Digite o CRM: ";
                getline(cin >> ws, auxCRM);
                int posicao = LocalizarCRM(Medicos, auxCRM);
                        if(posicao < 0){
                            condicao = 1;
                        }
                        else{
                        cout << "O CRM já existe!" << endl;
                            condicao = 0;
                        }
            }while(condicao == 0);

            cout << "Informe a Especialidade: ";
            getline(cin >> ws, auxEspecialidade);

            Medico *medico = new Medico (auxNome, auxCRM, auxEspecialidade);

            Medicos.push_back(medico);
        }

        else if (Opcao == 2){
            cout << "Digite o CRM que deseja excluir: " << endl;
            getline(cin >> ws, auxCRM);

            int posicao = LocalizarCRM(Medicos, auxCRM);

            if(posicao < 0)
                cout << "Medico não encontraddo" << endl;
            else{
                delete Medicos [posicao];
            Medicos.erase(Medicos.begin() + posicao);
            cout << "O medico foi excluido!" << endl; 
            }
        }
        else if (Opcao == 3){
            int alterar = 0;

            cout << "Informe o CRM do medico que deseja modificar: " << endl;
            getline(cin >> ws, auxCRM);

            int posicao = LocalizarCRM(Medicos, auxCRM);

            if(posicao < 0)
                cout << "Medico não encontraddo" << endl;

            else{

                cout << "Estes são os dados atuais do CRM citado: " << endl;
                cout << "Nome: " << Medicos.at(posicao)-> Nome << endl;
                cout << "Data de nascimento: " << Medicos.at(posicao)-> getEspecialidade() << endl;
                cout << "Selecione a opcao que deseja alterar" << endl;
                cout << "1- Alterar Nome" << endl;
                cout << "2- Alterar Especialidade" << endl;
                cout << "3- Alterar ambos" << endl;
                cout << "0- Voltar" << endl;
                cin >> alterar;

                if(alterar == 1){

                    cout << "Digite o novo nome do paciente: ";
                    getline(cin >> ws, Medicos.at(posicao) -> Nome);

                }else if(alterar == 2){

                    cout << "Digite a nova Especialidade: ";
                    getline(cin >> ws, auxEspecialidade);
                    Medicos.at(posicao) -> setEspecialidade(auxEspecialidade);
                }
                else if (alterar == 3){

                    cout << "Informe o novo nome do medico: ";
                    getline(cin >> ws, Pacientes.at(posicao) -> Nome);
                    cout << "Informe a nova Especialidade: ";
                    getline(cin >> ws, auxEspecialidade);
                    Medicos.at(posicao) -> setEspecialidade(auxEspecialidade);
                }
                else if (alterar == 0){

                }else{
                    
                    cout << "Opcao Invalida!" << endl;
                }
            }   
        }

        else if (Opcao == 4){
            for (auto el : Medicos){
                cout << el -> Nome << endl;
                cout << el -> getCRM() << endl;
                cout << el -> getEspecialidade() << endl;
                cout << endl;
            }
        }

        else if (Opcao == 5){

            cout << "Informe o CRM do medico que deseja alterar: ";
            getline(cin >> ws, auxCRM);

            int posicao = LocalizarCRM(Medicos, auxCRM);
            if(posicao <0)
               cout << "Medico nao encontrado" << endl;
            else{
                cout << Medicos.at(posicao)-> Nome << endl;
                cout << Medicos.at(posicao)-> getEspecialidade() << endl;
            }   
        }
        else if (Opcao==0){
        }
        else{
            cout << "Opcao invalida! ";
        }
        }while(Opcao != 0);        
    };
    
};

int main(){
    int gestao;
    Principal Clinica_Medica_Sem_Dodoi;

do{
    cout << "_______CLINICA MEDICA SEM DODOI LTDA._______" << endl;
    cout << "Deseja acessar a gestao Pacientes ou Medicos?" << endl;
    cout << "1. Pacientes" << endl;
    cout << "2. Medicos" << endl;
    cout << "0. Encerrar programa" << endl;
    cin >> gestao; 

if (gestao == 1){
    Clinica_Medica_Sem_Dodoi.Gestao_Paciente();
}

else if (gestao == 2){
    Clinica_Medica_Sem_Dodoi.Gestao_Medico();
}
else if (gestao == 0){
    cout << "Programa Finalizado!";
}
else {
    cout << "Entrada Invalida." << endl;
}
}while(gestao != 0);
    return 0;
}