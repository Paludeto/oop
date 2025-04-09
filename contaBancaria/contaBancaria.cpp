#include <iostream>

using namespace std;

enum tipoConta {
    CC,
    CP
};

class ContaBancaria {

    protected:
    
        tipoConta tipo;

    private:

        string proprietario;
        float saldo;
        bool status;
    
    public:

        int numConta;

        ~ContaBancaria() {
            cout << "Conta deletada" << endl;
        }

        ContaBancaria(int numConta, string prop, tipoConta tipo) {
    
            this->tipo = tipo;
            this->proprietario = prop;
            this->numConta = numConta;
            abrirConta(tipo);

        }

        void abrirConta(tipoConta tipo) {
            
            if (tipo == CC) {
                this->saldo = 150.00;
            } else {
                this->saldo = 50.00;
            }
            
            this->status = true;

            cout << "Conta aberta!" << endl;
            cout << "Número: " << this->numConta << endl;
            cout << "Proprietário: " << this->proprietario << endl;
            cout << "Saldo: " << this->saldo << endl;

            if (this->tipo == CC) {
                cout << "Tipo: " << "CC" << endl;
            } else {
                cout << "Tipo: " << "CP" << endl;
            }
            
        }

        void fecharConta() {
            
            if (this->saldo < 0) {
                cout << "Conta devendo, não pode ser fechada" << endl;
                return;
            }
            
            sacar(this->saldo);
            this->status = false;
            cout << "Conta fechada" << endl;

        }

        void depositar(float dinheiro) {

            if (this->status) {
                this->saldo += dinheiro;
                cout << "R$ " << this->saldo  << endl;
            } else {
                cout << "Conta fechada" << endl;
                return;
            }

        }

        void sacar(float dinheiro) {

            if (this->saldo < dinheiro) {
                cout << "Saldo insuficiente" << endl;
            } else {
                this->saldo -= dinheiro;
                cout << "R$ " << this->saldo  << endl;
            }

        }

        void pagarMensalidade() {

            if (this->tipo == CP) {
                this->saldo -= 20.00;
            } else {
                this->saldo -= 12.00;
            }

            cout << "R$ " << this->saldo  << endl;
        
        }

};

int main(void) {

    ContaBancaria *moises = new ContaBancaria(123456, "Moises", CP);
    ContaBancaria *luzia = new ContaBancaria(678910, "Luzia", CC);

    moises->depositar(300);
    luzia->depositar(500);

    luzia->sacar(50);
    moises->depositar(50);

    delete(luzia);
    delete(moises);

    return 0;

}