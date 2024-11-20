#include "Registro.h"
#include "Buffer.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // arquivo de entrada
    string arquivo_entrada = "dados.txt";

    // vetor para armazenar os registros
    vector<Registro> registros;

    // le o arquivo com registros delimitado
    ifstream arquivo (arquivo_entrada);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo: " << arquivo_entrada << endl;
        return 1;
    }

    Buffer buffer(arquivo_entrada);
    Registro reg;

    // le registros no formato delimitado
    while (buffer.lerRegistroDelimitado(arquivo, reg)) {
        registros.push_back(reg);
    }
    arquivo.close();

    // escreve os registros no formato delimitado
    ofstream arquivo_saida ("dados_delimitados.txt");
    if (!arquivo_saida) {
        cerr << "Erro ao abrir o arquivo para escrita: dados_delimitados.txt" << endl;
        return 1;
    }
    for (const auto& r : registros) {
        buffer.escreverRegistroDelimitado(arquivo_saida, r);
    }
    arquivo_saida.close();

    // escreve os registros no formato binário
    ofstream saida_binario ("dados_binarios.bin", ios::binary);
    if (!saida_binario) {
        cerr << "Erro ao abrir o arquivo para escrita: dados_binarios.bin" << endl;
        return 1;
    }
    for (const auto& r : registros) {
        buffer.escreverRegistroBinario(saida_binario, r);
    }
    saida_binario.close();

    cout << "concluído com sucesso!" << endl;

    return 0;
}
