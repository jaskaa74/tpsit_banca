#include <iostream>
#include "Banca.h"
#include "Cliente.h"
#include "Investimento.h"

using namespace std;

int main() {
    Banca banca;

    Cliente cliente1("Mario", "Rossi");
    Cliente cliente2("Giulia", "Verdi");

    banca.aggiungiCliente(cliente1);
    banca.aggiungiCliente(cliente2);

    cout << "Stato iniziale dei clienti:" << endl;
    banca.mostraStatiClienti();

    cliente1.deposita(50);
    cliente1.aggiungiInvestimento(Investimento("Breve termine", 30, 0.05, 3));

    cliente2.deposita(100);
    cliente2.aggiungiInvestimento(Investimento("Lungo termine", 70, 0.1, 12));

    cout << "\nDopo operazioni iniziali:" << endl;
    banca.mostraStatiClienti();

    banca.avanzareTempo(1);

    cout << "\nDopo 1 mese:" << endl;
    banca.mostraStatiClienti();

    return 0;
}