#include "Buffer.h"

Buffer::Buffer(const string& nomeArquivo) : arquivo(nomeArquivo) {}

bool Buffer::lerRegistroDelimitado(ifstream& in, Registro& reg) {
    string linha;
    if (getline(in, linha)) {
        reg.unpackDelimitado(linha);
        return true;
    }
    return false;
}

bool Buffer::escreverRegistroDelimitado(ofstream& out, const Registro& reg) {
    string registro = reg.packDelimitado();
    out << registro << "\n";
    return out.good();
}

bool Buffer::lerRegistroBinario(ifstream& in, Registro& reg) {
    uint32_t tamanho;
    if (!in.read(reinterpret_cast<char*>(&tamanho), sizeof(uint32_t))) {
        return false;  // caso falha ao ler o descritor de tamanho
    }
    string buffer(sizeof(uint32_t), '\0');
    in.read(&buffer[0], sizeof(uint32_t));
    if (in.eof()) return false;
    
    memcpy(&tamanho, &buffer[0], sizeof(uint32_t));

    buffer.resize(tamanho);
    in.read(&buffer[0], tamanho);
    reg.unpackBinario(buffer);
    return true;
}

bool Buffer::escreverRegistroBinario(ofstream& out, const Registro& reg) {
    string registro = reg.packBinario();
    out.write(registro.c_str(), registro.size());
    return out.good();
}
