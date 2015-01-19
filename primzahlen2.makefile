
all: primzahlen2 primzahlen2_berechnung

primzahlen2: primzahlen2.c
	gcc -o primzahlen2 primzahlen2.c

primzahlen2_berechnung: primzahlen2_berechnung.c
	gcc -lm -o primzahlen2_berechnung primzahlen2_berechnung.c

