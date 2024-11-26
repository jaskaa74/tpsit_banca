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
    Cliente(const string& nome, const string& cognome)
        : nome(nome), cognome(cognome), saldo(0.0), debito(0.0), portafoglio(100.0) {};

    void deposita(double importo) {
        if (importo > portafoglio) {
            cout << "Fondi insufficienti nel portafoglio!" << endl;
            return;
        }
        portafoglio -= importo;
        saldo += importo;
        if (debito > 0) {
            double ripagato = min(debito, saldo);
            saldo -= ripagato;
            debito -= ripagato;
        }
    }
    void preleva(double importo) {
        if (importo > saldo) {
            cout << "Fondi insufficienti nel conto!" << endl;
            return;
        }
        saldo -= importo;
        portafoglio += importo;
    }

    void avanzaTempo(int mesi) {
        portafoglio += 100.0 * mesi; 
        for (auto& investimento : investimenti) {
            investimento.avanza(mesi);
        }
    }

    void visualizzaStato() const {
        cout << "Nome: " << nome << " " << cognome << endl;
        cout << "Saldo: " << saldo << " €, Debito: " << debito << " €" << endl;
        cout << "Portafoglio: " << portafoglio << " €" << endl;
        cout << "Investimenti attivi: " << investimenti.size() << endl;
    }

    bool aggiungiInvestimento(const Investimento& inv) {
        if (saldo < inv.getValore()) {
            cout << "Fondi insufficienti per effettuare l'investimento!" << endl;
            return false;
        }
        saldo -= inv.getValore();
        investimenti.push_back(inv);
        return true;
    }

    double getSaldo() const {
        return saldo;
    }

    double getDebito() const {
        return debito;
    }

};

#endif

