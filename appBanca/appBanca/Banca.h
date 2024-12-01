#ifndef BANCA_H
#define BANCA_H

#include <vector>
#include "Cliente.h"

using namespace std;

class Banca {
private:
    vector<Cliente> clienti;

public:
    void aggiungiCliente(const Cliente& cliente) {
        clienti.push_back(cliente);
    }

    void avanzareTempo(int mesi) {
        for (auto& cliente : clienti) {
            cliente.avanzaTempo(mesi);
        }
    }

    void mostraStatoDopoAvanzamento() const {
        for (const auto& cliente : clienti) {
            cout << "\nStato aggiornato del cliente " << cliente.getNome() << " " << cliente.getCognome() << ":\n";
            cliente.visualizzaStato(); 
        }
    }

    void mostraStatiClienti() const {
        for (const auto& cliente : clienti) {
            cliente.visualizzaStato();
        }
    }

    Cliente& getCliente(int indice) {
        if (indice < 0 || indice >= clienti.size()) {
            throw out_of_range("Indice cliente non valido!");
        }
        return clienti[indice];
    }

    int numeroClienti() const {
        return clienti.size();
    }
};

#endif

