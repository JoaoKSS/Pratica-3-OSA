#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <cstring>
using namespace std;

class Registro {
public:
    string nome;
    string sobrenome;
    string telefone;
    string nascimento;

    // Construtor
    Registro(string n = "", string s = "", string t = "", string d = "");

    // Método Pack para a representação com delimitadores
    string packDelimitado() const;

    // Método Unpack para a representação com delimitadores
    void unpackDelimitado(const string& str);

    // Método Pack para a representação binária com descritor de tamanho
    string packBinario() const;

    // Método Unpack para a representação binária com descritor de tamanho
    void unpackBinario(const string& str);
};

#endif
