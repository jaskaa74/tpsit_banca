#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Investimento.h"

using namespace std;

class Cliente {
private:
    string nome;
    string cognome;
    double saldo;               // Saldo bancario
    double debito;              // Debiti accumulati
    double portafoglio;         // Denaro fuori dal conto
    vector<Investimento> investimenti;

public:
    Cliente(const string& nome, const string& cognome);
    void deposita(double importo);
    void preleva(double importo);
    void avanzaTempo(int mesi);
    void visualizzaStato() const;
    bool aggiungiInvestimento(const Investimento& inv);

    // Getter
    double getSaldo() const;
    double getDebito() const;
};

#endif

