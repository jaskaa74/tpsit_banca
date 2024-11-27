#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

#include <string>
using namespace std;

class Investimento {
private:
    string tipo;
    double valore;
    double rendimento;
    double rischio;
    int durata;
    int mesiPassati;

public:
    Investimento(const string& tipo, double valore, int durata) {
        this->valore = valore;
        this->durata = durata;
        this->mesiPassati = 0;
        this->tipo = tipo;

        if (tipo == "basso") {
            this->rendimento = 0.05;   
            this->rischio = 0.10;      
        }
        else if (tipo == "medio") {
            this->rendimento = 0.10;   
            this->rischio = 0.20;      
        }
        else if (tipo == "alto") {
            this->rendimento = 0.15;   
            this->rischio = 0.30;      
        }
        else {
            this->rendimento = 0.05;
            this->rischio = 0.10;
        }
    }

    void avanza(int mesi) {
        mesiPassati += mesi;
    }

    double calcolaGuadagno() {
        if (mesiPassati >= durata) {
            double guadagno = valore * (1 + rendimento - rischio);
            return guadagno > 0 ? guadagno : 0;
        }
        return valore;
    }

    bool isTerminato() const {
        return mesiPassati >= durata;
    }

    string getTipo() const {
        return tipo;
    }

    double getValore() const {
        return valore;
    }

    double getRendimento() const {
        return rendimento;
    }
};

#endif


