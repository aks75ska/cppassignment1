all: akgoyal_exe

COMPVAR = g++-7.2.0

akgoyal_exe: akgoyal_agency.o akgoyal_team.o akgoyal_player.o
	$(COMPVAR) -o akgoyal_exe akgoyal_agency.o akgoyal_team.o akgoyal_player.o

akgoyal_agency.o: akgoyal_agency.cc akgoyal_agency.h
	$(COMPVAR) -c akgoyal_agency.cc
	
akgoyal_team.o: akgoyal_team.cc akgoyal_team.h
	$(COMPVAR) -c akgoyal_team.cc
	
akgoyal_player.o: akgoyal_player.cc akgoyal_player.h
	$(COMPVAR) -c akgoyal_player.cc