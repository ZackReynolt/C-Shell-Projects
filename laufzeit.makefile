
all: laufzeit laufzeit_primzahlenberechnung signale_signalsendung

laufzeit: laufzeit.c
	gcc -o laufzeit laufzeit.c

laufzeit_primzahlenberechnung: laufzeit_primzahlenberechnung.c
	gcc -lm -o laufzeit_primzahlenberechnung laufzeit_primzahlenberechnung.c

signale_signalsendung: signale_signalsendung.c
	gcc -lm -o signale_signalsendung signale_signalsendung.c

