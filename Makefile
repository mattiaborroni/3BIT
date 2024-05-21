# Definisce il compilatore
CC=g++

# Opzioni di compilazione
CFLAGS=-Iinclude

# Nome del file eseguibile
TARGET=Battaglia_navale_3BIT

# Regola per costruire l'eseguibile
$(TARGET): main.o librerie.o
	$(CC) -o $(TARGET) main.o librerie.o

# Regola per compilare main.c
main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

# Regola per compilare librerie.c
librerie.o: src/librerie.cpp include/librerie.h
	$(CC) $(CFLAGS) -c src/librerie.cpp

# Pulisce i file oggetto e l'eseguibile
clean:
	rm -f *.o $(TARGET)
