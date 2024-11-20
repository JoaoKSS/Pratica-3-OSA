##############################################################################
# Exemplo de makefile para um projeto em linguagem C++ com diferentes tipos
# de representação de registros (Prática 03)
##############################################################################
# Arquivo principal: main.cpp
##############################################################################
#                       Arquivos auxiliares do projeto
##############################################################################
# Registro.cpp: depende de Registro.h
# Buffer.cpp: depende de Buffer.h e Registro.h
##############################################################################

# definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contem a função main, sem a extensao)
MAIN    := main
# objetos a serem gerados na compilação
OBJECTS := $(MAIN).o Registro.o Buffer.o

FLAGS   := -Wall -Wextra -std=c++17 -pedantic-errors
DEBUG   := -g
MATH    := -lm
CC      := g++

# ajustando alguns parâmetros/comandos ao sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
else
OUTPUTMAIN := $(MAIN).out
endif

# ponto de compilação principal
all: $(OUTPUTMAIN)
	@echo Compiling 'all' complete!

# gerando o arquivo executavel
$(OUTPUTMAIN): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)

# gerando o arquivo objeto da função principal... 
main.o: $(MAIN).cpp Registro.h Buffer.h
	$(CC) $(FLAGS) -c $(MAIN).cpp

# gerando o arquivo objeto Registro.o
Registro.o: Registro.cpp Registro.h
	$(CC) $(FLAGS) -c Registro.cpp

# gerando o arquivo objeto Buffer.o
Buffer.o: Buffer.cpp Buffer.h Registro.h
	$(CC) $(FLAGS) -c Buffer.cpp

clean:
ifeq ($(OS), Windows_NT)
	del /Q *.o
	del /Q $(OUTPUTMAIN)
else
	rm -rf *.o
	rm -rf $(OUTPUTMAIN)
endif
	@echo Cleanup complete!!!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'all' complete!!!
