#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

#include <string>
using namespace std;

class Investimento {
private:
    string tipo;          
    double valore;        
    double rendimento;    
    int durata;           
    int mesiPassati;      

public:
    Investimento(const string& tipo, double valore, double rendimento, int durata)
        : tipo(tipo), valore(valore), rendimento(rendimento), durata(durata), mesiPassati(0) {};

    void avanza(int mesi) {
        mesiPassati += mesi;
    }

    double calcolaValore() const {
        if (mesiPassati >= durata) {
            return valore + (valore * rendimento);
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

