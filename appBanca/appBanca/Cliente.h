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
    double saldo;               
    double debito;              
    double portafoglio;         
    vector<Investimento> investimenti;

public:
    Cliente(const string& nome, const string& cognome);
    void deposita(double importo);
    void preleva(double importo);
    void avanzaTempo(int mesi);
    void visualizzaStato() const;
    bool aggiungiInvestimento(const Investimento& inv);

    
    double getSaldo() const;
    double getDebito() const;
};

#endif

