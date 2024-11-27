#include <iostream>
#include "Banca.h"
#include "Cliente.h"
#include "Investimento.h"

using namespace std;

int main() {
    Banca banca;
    int scelta = -1;

    cout << "Benvenuto nell'app della Banca!\n";

    while (scelta != 0) {
        cout << "\nMenu principale:\n";
        cout << "1. Aggiungi un nuovo cliente\n";
        cout << "2. Deposita denaro\n";
        cout << "3. Preleva denaro\n";
        cout << "4. Effettua un investimento\n";
        cout << "5. Avanza nel tempo\n";
        cout << "6. Mostra lo stato di tutti i clienti\n";
        cout << "0. Esci\n";
        cout << "Scegli un'opzione: ";
        cin >> scelta;

        switch (scelta) {
        case 1: {
            string nome, cognome;
            cout << "Inserisci il nome del cliente: ";
            cin >> nome;
            cout << "Inserisci il cognome del cliente: ";
            cin >> cognome;
            banca.aggiungiCliente(Cliente(nome, cognome));
            cout << "Cliente aggiunto con successo!\n";
            break;
        }
        case 2: {
            int indice;
            double importo;
            cout << "Seleziona il cliente (0 per il primo, 1 per il secondo, ecc.): ";
            cin >> indice;
            if (indice < 0 || indice >= banca.numeroClienti()) {
                cout << "Cliente non valido.\n";
                break;
            }
            cout << "Inserisci l'importo da depositare: ";
            cin >> importo;
            banca.getCliente(indice).deposita(importo);
            break;
        }
        case 3: {
            int indice;
            double importo;
            cout << "Seleziona il cliente (0 per il primo, 1 per il secondo, ecc.): ";
            cin >> indice;
            if (indice < 0 || indice >= banca.numeroClienti()) {
                cout << "Cliente non valido.\n";
                break;
            }
            cout << "Inserisci l'importo da prelevare: ";
            cin >> importo;
            banca.getCliente(indice).preleva(importo);
            break;
        }
        case 4: {
            int indice;
            double valore;
            int durata;
            string tipo;

            cout << "Seleziona il cliente (0 per il primo, 1 per il secondo, ecc.): ";
            cin >> indice;
            if (indice < 0 || indice >= banca.numeroClienti()) {
                cout << "Cliente non valido.\n";
                break;
            }
            cout << "Inserisci il tipo di investimento (basso/medio/alto): ";
            cin >> tipo;
            cout << "Inserisci il valore dell'investimento: ";
            cin >> valore;
            cout << "Inserisci la durata in mesi: ";
            cin >> durata;
            Investimento nuovoInvestimento(tipo, valore, durata);
            if (banca.getCliente(indice).aggiungiInvestimento(nuovoInvestimento)) {
                cout << "Investimento aggiunto con successo!\n";
            }
            else {
                cout << "Fondi insufficienti per l'investimento.\n";
            }
            break;
        }

        case 5: {
            int mesi;
            cout << "Inserisci il numero di mesi da avanzare: ";
            cin >> mesi;

            banca.avanzareTempo(mesi);

            int indice;
            cout << "Seleziona il cliente per vedere gli investimenti: ";
            cin >> indice;

            Cliente& cliente = banca.getCliente(indice);

            cout << "Guadagni da investimenti del cliente:\n";
            for (auto& inv : cliente.getInvestimenti()) {
                cout << "Investimento tipo: " << inv.getTipo()
                    << " Guadagno: " << inv.calcolaGuadagno() << " €\n";
            }

            cout << "Il tempo è avanzato di " << mesi << " mesi.\n";
            break;
        }
        case 6: {
            cout << "\nStato di tutti i clienti:\n";
            banca.mostraStatiClienti();
            break;
        }
        case 0:
            cout << "Uscita dall'app. Arrivederci!\n";
            break;
        default:
            cout << "Scelta non valida. Riprova.\n";
        }
    }

    return 0;
}
