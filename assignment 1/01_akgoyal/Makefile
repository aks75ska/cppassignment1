all: akgoyal_exe

COMPVAR = g++-7.2.0

akgoyal_exe: akgoyal_cal.o AKGOYAL_OP.o
	$(COMPVAR) -o akgoyal_exe akgoyal_cal.o AKGOYAL_OP.o

akgoyal_cal.o: akgoyal_cal.cc AKGOYAL_OP.cc
	$(COMPVAR) -c akgoyal_cal.cc
	
AKGOYAL_OP.o: AKGOYAL_OP.h
	$(COMPVAR) -c AKGOYAL_OP.cc