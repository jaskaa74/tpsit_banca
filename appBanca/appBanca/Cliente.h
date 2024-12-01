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
        : nome(nome), cognome(cognome), saldo(0.0), debito(0.0), portafoglio(100.0) {}

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
        for (auto it = investimenti.begin(); it != investimenti.end();) {
            it->avanza(mesi);

            if (it->isTerminato()) {
                double guadagno = it->calcolaGuadagno();
                saldo += it->getValore() + guadagno;
                cout << "Investimento completato: Guadagno di " << guadagno << " € e capitale di " << it->getValore() << " € restituito.\n";

                it = investimenti.erase(it);
            }
            else {
                ++it;
            }
        }
    }

    void visualizzaStato() const {
        cout << "Nome: " << nome << " " << cognome << endl;
        cout << "Saldo: " << saldo << " €, Debito: " << debito << " €" << endl;
        cout << "Portafoglio: " << portafoglio << " €" << endl;
        cout << "Investimenti attivi: " << investimenti.size() << endl;
        for (const auto& investimento : investimenti) {
            if (investimento.isTerminato()) {
                cout << "Investimento completato: "
                    << investimento.getTipo() << " - Guadagno: "
                    << investimento.calcolaGuadagno() << " €\n";
            }
            else {
                cout << "Investimento in corso: " << investimento.getTipo() << endl;
            }
        }
        cout << endl;
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

    void aggiungiDebito(double importo) { debito += importo; }

    vector<Investimento>& getInvestimenti() { return investimenti; }

    double getSaldo() const { return saldo; }
    double getDebito() const { return debito; }
    string getNome() const { return nome; }
    string getCognome() const { return cognome; }
};

#endif
