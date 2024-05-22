# COMPITO PROGETTO FINALE TPSIT

Realizzazione di una battaglia navale in linguaggio c++


Classe 3BIT

MEMBRI DEL GRUPPO
* BORRONI MATTIA
* SINIGAGLIA ALESSANDRO
* BALDUCCI FRANCESCO
* RUFFINO CRISTIAN

GIOCO DELLA BATTAGLIA NAVALE
============================

Questo manuale ti permette di compilare e giocare alla meravigliosa Battaglia Navale

Ogni informazione la troverai qui.......

### Prerequisiti

*Questo programma è stato preparato per Ubuntu Linux, ma è stato testato anche su Windows.

Necessarie per la compilazione le librerie g++ installate ed il comando make.

----

## Creazione del programma

Grazie alla presenza del Makefile la compilazione del programma sarà molto semplice, ecco i passi da seguire per poter giocare:

* Apri il terminale
* clona il repository
* entrare ( se gia non si e dentro) alla cartella "3BIT-BATTAGLIA-NAVALE"
* digitare semplicemente 
```bash
make
```

Se come immaginiamo tutto è andato a buon fine nella cartella troverete un file chiamato Battaglia_navale_3BIT

Per far partire il gioco digitate
```bash
  make run
```

----
# ISTRUZIONI DI GIOCO


## 1. Regole Base

Il gioco consiste nel colpire ed affondare le 5 navi nemiche posizionate su una griglia di 9x9.
Per affondare una nave basta un colpo a segno.
Vince chi per primo colpisce turre e 5 le navi


## 2. Schermate iniziali

Il gioco inizia con 3 schermate iniziali

* la prima è puramente grafica , per proseguire premere enter 2 volte
* la seconda mostra i 2 campi di baglia affiancati , il nosto (quello di sinistra) e quello dell'aversario ( destra )
* la terza schermata invita finalmente ad inserire le navi nella sequenza dalla più grossa alla più piccola.

## 3. Inserimento delle navi

Si ricorda che le navi da inserire sono 5 con le seguenti dimensioni:

* 1 nave lunghezza 5
* 1 nave lunghezza 4
* 2 navi lunghezza 3
* 1 nave lunghezza 2


Le coordinate vanno indicate come unico inserimento LetteraNumero per esempio `A3` ed identificano l'inizio della nave.
Nella domanda successiva viene richiesto l'orientamento della nave , inserire `0` per orizzontale oppure `1` per verticale.

Ad ogni inserimento il programma verifica se la nave è posizionabile ed in caso affermativo inserisce la nave in griglia marcandola con il suo numero reltivo, nel caso in cui le coordinate siano incompatibile comparirà il messaggio
```bash
coordinate non compatibili per inserimento nave
Premere ENTER per proseguire
```
Terminato l'inserimento delle 5 navi il computer inserisce le sue navi ed inizia la sfida vera e proprio.

### 4 Fase di sfida

A turno il giocatore ed il computer indicano le coordinate di tiro.

La tabella sottostante il campo di gara riporta il resoconto delle navi colpite e di quelle ancora da colpire.

dopo ogni tiro abbiamo la risposta se il nostro colpo e quello del computer sono andati a segno oppure no

**Basta un solo colpo per affondare una nave **

### 5 Vittoria

Il gioco termina quando uno dei due giocatori colpisce tutte le navi dell'avversario e termina con una supensa schermata.


### Contatti

Per ogni problema ............ (sperando non ce ne siano)

[Mattia Borroni](mattia.borroni.2007@gmail.com)

