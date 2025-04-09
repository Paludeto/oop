#include <iostream>
#include <vector>

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

    for (Lutador *l : lutadores) {
        delete(l);
    }

    return 0;
        
}