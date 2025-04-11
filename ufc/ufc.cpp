#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Lutador {

    private:

        string nome, nacionalidade, categoria;
        int idade, vitorias, derrotas, empates;
        float altura, peso;
        bool ativo;

    public:

        Lutador(string nome, string nac, string cat, int idade, int vit, int der, int emp, 
                float alt, float peso, bool ativo) {

            this->nome = nome;
            this->nacionalidade = nac;
            this->categoria = cat;
            this->idade = idade;
            this->vitorias = vit;
            this->derrotas = der;
            this->empates = emp;
            this->altura = alt;
            this->peso = peso;
            this->ativo = ativo;
        
        }

        ~Lutador() {
            cout << "Lutador deletado" << endl;
        }

        // Getters
        string getNome() const { return nome; }
        string getNacionalidade() const { return nacionalidade; }
        string getCategoria() const { return categoria; }
        int getIdade() const { return idade; }
        int getVitorias() const { return vitorias; }
        int getDerrotas() const { return derrotas; }
        int getEmpates() const { return empates; }
        float getAltura() const { return altura; }
        float getPeso() const { return peso; }
        bool getStatus() const { return ativo; }

        // Setters
        void setNome(const string& nome) { this->nome = nome; }
        void setNacionalidade(const string& nacionalidade) { this->nacionalidade = nacionalidade; }
        void setCategoria(const string& categoria) { this->categoria = categoria; }
        void setIdade(int idade) { this->idade = idade; }
        void setVitorias(int vitorias) { this->vitorias = vitorias; }
        void setDerrotas(int derrotas) { this->derrotas = derrotas; }
        void setEmpates(int empates) { this->empates = empates; }
        void setAltura(float altura) { this->altura = altura; }
        void setPeso(float peso) { this->peso = peso; }
        void setStatus(bool ativo) { this->ativo = ativo; }

        // Outros métodos
        void apresentar() {
            cout << "Lutador: " << nome << endl;
            cout << "Origem: " << nacionalidade << endl;
            cout << "Categoria: " << categoria << endl;
            cout << "Idade: " << idade << " anos" << endl;
            cout << "Altura: " << altura << " m" << endl;
            cout << "Peso: " << peso << " kg" << endl;
            cout << "V/D/E: " << vitorias << "/" << derrotas << "/" << empates << endl;
            cout << "Status: " << (ativo ? "Ativo" : "Inativo") << endl;
        }
    
        bool status() {
            return this->ativo;
        }
    
        void ganharLuta() {
            vitorias++;
        }
    
        void perderLuta() {
            derrotas++;
        }
    
        void empatarLuta() {
            empates++;
        }

};

class Luta {

    private:

        Lutador *desafiado, *desafiador;
        int rounds;
        bool aprovada;

    public:

        Luta(Lutador *desafiado, Lutador *desafiador, int rounds) {
            this->desafiado = desafiado;
            this->desafiador = desafiador;
            this->rounds = rounds;
            this->aprovada = false;

            marcarLuta();

            if (aprovada) {
                lutar();
            } else {
                return;
            }
            
        };

        ~Luta() {
            cout << "Luta destruída" << endl;
        }

        void setAprovacao(bool aprovada) {
            this->aprovada = aprovada;
        }

        void marcarLuta() {

            if ((desafiado->getCategoria() == desafiador->getCategoria()) && (desafiado->getStatus() && desafiador->getStatus())) {
                cout << "Luta marcada!" << endl;
                setAprovacao(true);
            } else {
                cout << "Luta negada!" << endl;
                setAprovacao(false);
            }

        }

        void lutar() {

            srand(time(NULL));

            int estado = rand() % 3;

            switch (estado) {

                case 0:
                    this->desafiado->ganharLuta();
                    this->desafiador->perderLuta();
                    cout << "Desafiado " << desafiado->getNome() << " venceu!" << endl;
                    break;
                case 1:
                    this->desafiador->ganharLuta();
                    this->desafiado->perderLuta();
                    cout << "Desafiador " << desafiador->getNome() << " venceu!" << endl;
                    break;
                case 2:
                    this->desafiado->empatarLuta();
                    this->desafiador->empatarLuta();
                    cout << "Empate!" << endl;
                    break;
                default:
                    break;

            }

        }

};

int main(void) {

    vector<Lutador *> lutadores;

    lutadores.push_back(new Lutador("Jon Jones", "EUA", "Peso-Pesado", 36, 27, 1, 0, 1.93, 112.0, true));
    lutadores.push_back(new Lutador("Islam Makhachev", "Rússia", "Peso-Leve", 32, 25, 1, 0, 1.78, 70.3, true));
    lutadores.push_back(new Lutador("Leon Edwards", "Jamaica", "Meio-Médio", 33, 21, 3, 0, 1.88, 77.1, true));
    lutadores.push_back(new Lutador("Anderson Silva", "Brasil", "Peso-Médio", 48, 34, 11, 0, 1.88, 84.0, false));
    lutadores.push_back(new Lutador("Georges St-Pierre", "Canadá", "Meio-Médio", 43, 26, 2, 0, 1.78, 77.1, false));

    for (Lutador *l : lutadores) {
        l->apresentar();
    }

    Luta *luta_1 = new Luta(lutadores.at(0), lutadores.at(1), 4);

    delete(luta_1);

    for (Lutador *l : lutadores) {
        delete(l);
    }

    return 0;
        
}