OBJECTS = Objects/
EXECUTABLES = Executables/
HEADERS = Headers/
HEAD = -I $(HEADERS)
CLASSES = Classes/
COMPIL = g++
TEST = Test/Test
FORME = Forme1-3/

.SILENT:

Test4: $(TEST)4.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Pixel.o $(OBJECTS)Ligne.o 
		echo Creation Test4
		$(COMPIL) $(TEST)4.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Pixel.o $(OBJECTS)Ligne.o -o $(EXECUTABLES)Test4 $(HEAD)

Test3: $(TEST)3.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o
		echo Creation Test3
		$(COMPIL) $(TEST)3.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o -o $(EXECUTABLES)Test3 $(HEAD)
		
Test2: $(TEST)2.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o
		echo Creation Test2
		$(COMPIL) $(TEST)2.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o $(HEAD)$(FORME) $(HEAD) -o $(EXECUTABLES)Test2
		
Test1: $(TEST)1.cpp $(OBJECTS)Couleur.o
		echo Creation Test1
		$(COMPIL) $(TEST)1.cpp $(OBJECTS)Couleur.o -o $(EXECUTABLES)Test1 $(HEAD)



$(OBJECTS)Pixel.o: $(CLASSES)Pixel.cpp $(HEADERS)Pixel.h
		echo creation Pixel.o
		$(COMPIL) $(CLASSES)Pixel.cpp -c $(HEAD) -o $(OBJECTS)Pixel.o	

$(OBJECTS)Ligne.o: $(CLASSES)Ligne.cpp $(HEADERS)Ligne.h
		echo creation Ligne.o
		$(COMPIL) $(CLASSES)Ligne.cpp -c $(HEAD) -o $(OBJECTS)Ligne.o

$(OBJECTS)Couleur.o: $(CLASSES)Couleur.cpp $(HEADERS)Couleur.h
		echo creation Couleur.o
		$(COMPIL) $(CLASSES)Couleur.cpp -c $(HEAD) -o $(OBJECTS)Couleur.o
		
$(OBJECTS)Point.o: $(CLASSES)Point.cpp $(HEADERS)Point.h
		echo creation Point.o
		$(COMPIL) $(CLASSES)Point.cpp -c $(HEAD) -o $(OBJECTS)Point.o
		
$(OBJECTS)Forme.o: $(CLASSES)Forme.cpp $(HEADERS)Forme.h
		echo creation Forme.o
		$(COMPIL) $(CLASSES)Forme.cpp -c $(HEAD) -o $(OBJECTS)Forme.o
	
$(OBJECTS)oldForme.o: $(CLASSES)$(FORME)Forme.cpp $(HEADERS)$(FORME)Forme.h
		echo creation oldForme.o
		$(COMPIL) $(CLASSES)$(FORME)Forme.cpp -c $(HEAD)$(FORME) $(HEAD) -o $(OBJECTS)oldForme.o
		
		
clean:
		rm $(OBJECTS)*.o
		
E: 
	./Executables/Test4

