.SILENT:
UTILE=./Classes


OBJS= Data1D.o Data2D.o EtudeStatDescriptive.o EtudeStat1D.o EtudeStat2D.o\
	 DataSource.o DataSourceSerieDiscrete.o DataSourceSerieContinue.o\
	DataSourceSerie2D.o Echantillon.o Liste.o ListeTriee.o Iterateur.o BaseException.o Exception.o \
	

GCC=g++ -m64 -Wall -I $(UTILE) 

PROGRAMS= Applic Test1#Data1D Data2D EtudeStatDescriptive EtudeStat1D EtudeStat2D\
	 DataSource DataSourceSerieDiscrete DataSourceSerieContinue\
	DataSourceSerie2D Echantillon Liste ListeTriee Iterateur Exception \
	

all: $(PROGRAMS)

Applic:	Applic.cpp $(OBJS)
	echo Creation de Applic
	$(GCC) -o Applic Applic.cpp $(OBJS)  

EtudeStatDescriptive.o:	$(UTILE)/EtudeStatDescriptive.cpp $(UTILE)/EtudeStatDescriptive.h
	echo Creation de EtudeStatDescriptive.o
	$(GCC) $(UTILE)/EtudeStatDescriptive.cpp -c

BaseException.o:	$(UTILE)/BaseException.cpp $(UTILE)/BaseException.h
	echo Creation de BaseException.o
	$(GCC) $(UTILE)/BaseException.cpp -c

Exception.o:	$(UTILE)/Exception.cpp $(UTILE)/Exception.h
	echo Creation de Exception.o
	$(GCC) $(UTILE)/Exception.cpp -c
	
EtudeStat1D.o:	$(UTILE)/EtudeStat1D.cpp $(UTILE)/EtudeStat1D.h
	echo Creation de EtudeStat1D.o
	$(GCC) $(UTILE)/EtudeStat1D.cpp -c
		
EtudeStat2D.o:	$(UTILE)/EtudeStat2D.cpp $(UTILE)/EtudeStat2D.h
	echo Creation de EtudeStat2D.o
	$(GCC) $(UTILE)/EtudeStat2D.cpp -c
	
Echantillon.o:	$(UTILE)/Echantillon.cpp $(UTILE)/Echantillon.h
	echo Creation de Echantillon.o
	$(GCC) $(UTILE)/Echantillon.cpp -c

Data1D.o:	$(UTILE)/Data1D.cpp $(UTILE)/Data1D.h
	echo Creation de Data1D.o
	$(GCC) $(UTILE)/Data1D.cpp -c
		
Data2D.o:	$(UTILE)/Data2D.cpp $(UTILE)/Data2D.h
	echo Creation de Data2D.o
	$(GCC) $(UTILE)/Data2D.cpp -c
	
DataSource.o:	$(UTILE)/DataSource.cpp $(UTILE)/DataSource.h
	echo Creation de DataSource.o
	$(GCC) $(UTILE)/DataSource.cpp -c

DataSourceSerieDiscrete.o:	$(UTILE)/DataSourceSerieDiscrete.cpp $(UTILE)/DataSourceSerieDiscrete.h
	echo Creation de DataSourceSerieDiscrete.o
	$(GCC) $(UTILE)/DataSourceSerieDiscrete.cpp -c

DataSourceSerieContinue.o:	$(UTILE)/DataSourceSerieContinue.cpp $(UTILE)/DataSourceSerieContinue.h
	echo Creation de DataSourceSerieContinue.o
	$(GCC) $(UTILE)/DataSourceSerieContinue.cpp -c
	
DataSourceSerie2D.o:	$(UTILE)/DataSourceSerie2D.cpp $(UTILE)/DataSourceSerie2D.h
	echo Creation de DataSourceSerie2D.o
	$(GCC) $(UTILE)/DataSourceSerie2D.cpp -c
		
Liste.o:	$(UTILE)/Liste.cpp $(UTILE)/Liste.h
	echo Creation de Liste.o
	$(GCC) $(UTILE)/Liste.cpp -c

ListeTriee.o:	$(UTILE)/ListeTriee.cpp $(UTILE)/ListeTriee.h
	echo Creation de ListeTriee.o
	$(GCC) $(UTILE)/ListeTriee.cpp -c
	
Iterateur.o:	$(UTILE)/Iterateur.cpp $(UTILE)/Iterateur.h
	echo Creation de Iterateur.o ...
	$(GCC) -c $(UTILE)/Iterateur.cpp

# Test unitaires

Test1:	$(UTILE)/Test/Test1.cpp $(OBJS)
		echo Creation de Test1 
		$(GCC) $(UTILE)/Test/Test1.cpp $(OBJS) -o Test1
		echo Creation de Test1 réussie

# Utilitaires

clean:
	echo Nettoyage des objets et programmes...
	rm -f $(OBJS)
	rm -f $(PROGRAMS)

clobber:
	echo Nettoyage des programmes...
	rm -f $(PROGRAMS)

