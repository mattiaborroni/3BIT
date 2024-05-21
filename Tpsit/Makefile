# Nome del compilatore
CXX = g++

# Opzioni del compilatore
CXXFLAGS = -Wall -Wextra -std=c++11

# Nome dell'eseguibile
TARGET = programma

# Directory per i file oggetto
OBJDIR = obj

# File sorgente
SRCS = main.cpp inizializza_campo.cpp premi.cpp pulisci.cpp scritta.cpp spara.cpp stampa_campo.cpp tabella_navi.cpp vittoria.cpp

# File oggetto (converti i file sorgente in file oggetto)
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Regola di default: compila il target
all: $(TARGET)

# Regola per creare l'eseguibile
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regola per creare i file oggetto
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regola per creare la directory dei file oggetto
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regola per pulire i file generati
clean:
	rm -f $(TARGET) $(OBJS)

# Regola per eseguire il programma
run: $(TARGET)
	./$(TARGET)

# Indica ai makefile di non considerare queste come regole vere
.PHONY: all clean run
