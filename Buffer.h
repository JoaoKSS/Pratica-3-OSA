#ifndef BUFFER_H
#define BUFFER_H

#include <fstream>
#include "Registro.h"
using namespace std;

class Buffer {
public:
    string arquivo;

    Buffer(const string& nomeArquivo);

    // Leitura de registros no formato delimitado
    bool lerRegistroDelimitado(ifstream& in, Registro& reg);

    // Escrita de registros no formato delimitado
    bool escreverRegistroDelimitado(ofstream& out, const Registro& reg);

    // Leitura de registros no formato binário
    bool lerRegistroBinario(ifstream& in, Registro& reg);

    // Escrita de registros no formato binário
    bool escreverRegistroBinario(ofstream& out, const Registro& reg);
};

#endif
