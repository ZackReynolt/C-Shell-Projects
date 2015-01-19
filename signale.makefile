
all: signale signale_primzahlenberechnung signale_signalsendung

signale: signale.c
	gcc -o signale signale.c

signale_primzahlenberechnung: signale_primzahlenberechnung.c
	gcc -lm -o signale_primzahlenberechnung signale_primzahlenberechnung.c

signale_signalsendung: signale_signalsendung.c
	gcc -lm -o signale_signalsendung signale_signalsendung.c

