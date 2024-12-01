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

    void impostaParametri(const string& tipo) {
        if (tipo == "basso") {
            rendimento = 0.05;
            rischio = 0.10;
        }
        else if (tipo == "medio") {
            rendimento = 0.10;
            rischio = 0.20;
        }
        else if (tipo == "alto") {
            rendimento = 0.15;
            rischio = 0.30;
        }
        else {
            rendimento = 0.05;
            rischio = 0.10;
            this->tipo = "basso";
        }
    }

public:
    Investimento(const string& tipo, double valore, int durata)
        : tipo(tipo), valore(valore), durata(durata), mesiPassati(0) {
        impostaParametri(tipo);
    }

    void avanza(int mesi) { mesiPassati += mesi; }

    double calcolaGuadagno() const {
        if (mesiPassati >= durata) {
            double rendimentoMensile = rendimento / 12.0;
            double guadagno = valore;

            for (int i = 0; i < durata; i++) {
                guadagno *= (1 + rendimentoMensile);
            }

            guadagno -= valore * rischio;

            return guadagno > 0 ? guadagno : 0;
        }
        return 0;
    }

    bool isTerminato() const { return mesiPassati >= durata; }
    string getTipo() const { return tipo; }
    double getValore() const { return valore; }
    double getRendimento() const { return rendimento; }
};

#endif



