#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

#include <string>
using namespace std;

class Investimento {
private:
    string tipo;          // Breve, medio, lungo termine
    double valore;        // Importo investito
    double rendimento;    // Guadagno o perdita previsto
    int durata;           // Durata in mesi
    int mesiPassati;      // Mesi trascorsi dall'inizio

public:
    Investimento(const string& tipo, double valore, double rendimento, int durata);
    void avanza(int mesi);       // Aggiorna lo stato in base al tempo
    double calcolaValore() const; // Calcola il valore attuale dell'investimento
    bool isTerminato() const;     // Verifica se l'investimento è completato

    // Getter
    string getTipo() const;
    double getValore() const;
    double getRendimento() const;
};

#endif

