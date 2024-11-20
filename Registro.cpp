#include "Registro.h"
#include <sstream>
#include <iomanip>
#include <cstring>

Registro::Registro(string n, string s, string t, string d) 
    : nome(n), sobrenome(s), telefone(t), nascimento(d) {}

string Registro::packDelimitado() const {
    stringstream ss;
    ss << nome << "|" << sobrenome << "|" << telefone << "|" << nascimento;
    return ss.str();
}

void Registro::unpackDelimitado(const string& str) {
    stringstream ss(str);
    getline(ss, nome, '|');
    getline(ss, sobrenome, '|');
    getline(ss, telefone, '|');
    getline(ss, nascimento, '|');
}

string Registro::packBinario() const {
    stringstream ss;
    string registro = nome + "|" + sobrenome + "|" + telefone + "|" + nascimento;
    // string registro = nome + sobrenome + telefone + nascimento;
    uint32_t tamanho = registro.size();
    ss.write(reinterpret_cast<const char*>(&tamanho), sizeof(tamanho));
    ss.write(registro.c_str(), tamanho);
    return ss.str();
}

void Registro::unpackBinario(const string& str) {
    uint32_t tamanho;
    memcpy(&tamanho, str.c_str(), sizeof(tamanho));
    string dados = str.substr(sizeof(tamanho), tamanho);
    unpackDelimitado(dados);  // Reaproveita a função de delimitadores
}
