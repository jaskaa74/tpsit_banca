#ifndef BANCA_H
#define BANCA_H

#include <vector>
#include "Cliente.h"

using namespace std;

class Banca {
private:
    vector<Cliente> clienti;

public:
    void aggiungiCliente(const Cliente& cliente);
    void avanzareTempo(int mesi);
    void mostraStatiClienti() const;
};

#endif

