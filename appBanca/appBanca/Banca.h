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

    void mostraStatiClienti() const {
        for (const auto& cliente : clienti) {
            cliente.visualizzaStato();
        }
    }
};

#endif

