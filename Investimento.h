#ifndef INVESTIMENTO_H
#define INVESTIMENTO_H

#include <string>
using namespace std;

class Investimento {
private:
    string tipo;          
    double valore;        
    double rendimento;    
    int durata;           
    int mesiPassati;      

public:
    Investimento(const string& tipo, double valore, double rendimento, int durata);
    void avanza(int mesi);       
    double calcolaValore() const; 
    bool isTerminato() const;     

    
    string getTipo() const;
    double getValore() const;
    double getRendimento() const;
};

#endif

