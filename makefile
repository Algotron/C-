OBJECTS = Objects/
EXECUTABLES = Executables/
HEADERS = Headers/
HEAD = -I $(HEADERS)
CLASSES = Classes/
COMPIL = g++
TEST = Test/Test
FORME = Forme1-3/

.SILENT:

ALL : Test1 Test2 Test3 Test4 Test5 Test6 Test7 Test8

Test8: $(TEST)8.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)Pixel.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o $(OBJECTS)ListeBase.o $(OBJECTS)Liste.o $(OBJECTS)ListeTriee.o $(OBJECTS)Iterateur.o $(OBJECTS)SmartPointer.o
		echo Creation Test8
		$(COMPIL) $(TEST)8.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Pixel.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o $(OBJECTS)ListeBase.o $(OBJECTS)Liste.o $(OBJECTS)ListeTriee.o $(OBJECTS)Iterateur.o $(OBJECTS)SmartPointer.o -o $(EXECUTABLES)Test8 $(HEAD)

Test7: $(TEST)7.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)Pixel.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o $(OBJECTS)ListeBase.o $(OBJECTS)Liste.o $(OBJECTS)ListeTriee.o $(OBJECTS)Iterateur.o
		echo Creation Test7
		$(COMPIL) $(TEST)7.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Pixel.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o $(OBJECTS)ListeBase.o $(OBJECTS)Liste.o $(OBJECTS)ListeTriee.o $(OBJECTS)Iterateur.o -o $(EXECUTABLES)Test7 $(HEAD)

Test6: $(TEST)6.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)Pixel.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o $(OBJECTS)ListeBase.o $(OBJECTS)Liste.o $(OBJECTS)ListeTriee.o $(OBJECTS)Iterateur.o
		echo Creation Test6
		$(COMPIL) $(TEST)6.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Pixel.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o $(OBJECTS)ListeBase.o $(OBJECTS)Liste.o $(OBJECTS)ListeTriee.o $(OBJECTS)Iterateur.o -o $(EXECUTABLES)Test6 $(HEAD)

Test5: $(TEST)5.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o  $(OBJECTS)Pixel.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o
		echo Creation Test5
		$(COMPIL) $(TEST)5.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Pixel.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o -o $(EXECUTABLES)Test5 $(HEAD)

Test4: $(TEST)4.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)Pixel.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o
		echo Creation Test4
		$(COMPIL) $(TEST)4.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)Forme.o $(OBJECTS)Pixel.o $(OBJECTS)Ligne.o $(OBJECTS)Rectangle.o $(OBJECTS)BaseException.o $(OBJECTS)InvalidColorException.o -o $(EXECUTABLES)Test4 $(HEAD) $(HEAD)



Test3: $(TEST)3.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o $(OBJECTS)InvalidColorException.o $(OBJECTS)BaseException.o
		echo Creation Test3
		$(COMPIL) $(TEST)3.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o $(OBJECTS)InvalidColorException.o $(OBJECTS)BaseException.o -o $(EXECUTABLES)Test3 $(HEAD)
		
		
		
Test2: $(TEST)2.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o $(OBJECTS)InvalidColorException.o $(OBJECTS)BaseException.o
		echo Creation Test2
		$(COMPIL) $(TEST)2.cpp $(OBJECTS)Couleur.o $(OBJECTS)Point.o $(OBJECTS)oldForme.o $(OBJECTS)InvalidColorException.o $(OBJECTS)BaseException.o $(HEAD)$(FORME) $(HEAD) -o $(EXECUTABLES)Test2
		
		
		
Test1: $(TEST)1.cpp $(OBJECTS)Couleur.o $(OBJECTS)InvalidColorException.o $(OBJECTS)BaseException.o
		echo Creation Test1
		$(COMPIL) $(TEST)1.cpp $(OBJECTS)Couleur.o $(OBJECTS)InvalidColorException.o $(OBJECTS)BaseException.o -o $(EXECUTABLES)Test1 $(HEAD)



$(OBJECTS)SmartPointer.o: $(CLASSES)SmartPointer.cpp $(HEADERS)SmartPointer.h
		echo creation SmartPointer.o
		$(COMPIL) $(CLASSES)SmartPointer.cpp -c $(HEAD) -o $(OBJECTS)SmartPointer.o

$(OBJECTS)Iterateur.o: $(CLASSES)Iterateur.cpp $(HEADERS)Iterateur.h
		echo creation Iterateur.o
		$(COMPIL) $(CLASSES)Iterateur.cpp -c $(HEAD) -o $(OBJECTS)Iterateur.o
		
$(OBJECTS)ListeBase.o: $(CLASSES)ListeBase.cpp $(HEADERS)ListeBase.h
		echo creation ListeBase.o
		$(COMPIL) $(CLASSES)ListeBase.cpp -c $(HEAD) -o $(OBJECTS)ListeBase.o
		
$(OBJECTS)Liste.o: $(CLASSES)Liste.cpp $(HEADERS)Liste.h
		echo creation Liste.o
		$(COMPIL) $(CLASSES)Liste.cpp -c $(HEAD) -o $(OBJECTS)Liste.o
		
$(OBJECTS)ListeTriee.o: $(CLASSES)ListeTriee.cpp $(HEADERS)ListeTriee.h
		echo creation ListeTriee.o
		$(COMPIL) $(CLASSES)ListeTriee.cpp -c $(HEAD) -o $(OBJECTS)ListeTriee.o

$(OBJECTS)InvalidColorException.o: $(CLASSES)InvalidColorException.cpp $(HEADERS)InvalidColorException.h
		echo creation InvalidColorException.o
		$(COMPIL) $(CLASSES)InvalidColorException.cpp -c $(HEAD) -o $(OBJECTS)InvalidColorException.o

$(OBJECTS)BaseException.o: $(CLASSES)BaseException.cpp $(HEADERS)BaseException.h
		echo creation BaseException.o
		$(COMPIL) $(CLASSES)BaseException.cpp -c $(HEAD) -o $(OBJECTS)BaseException.o

$(OBJECTS)Pixel.o: $(CLASSES)Pixel.cpp $(HEADERS)Pixel.h
		echo creation Pixel.o
		$(COMPIL) $(CLASSES)Pixel.cpp -c $(HEAD) -o $(OBJECTS)Pixel.o	

$(OBJECTS)Rectangle.o: $(CLASSES)Rectangle.cpp $(HEADERS)Rectangle.h
		echo creation Rectangle.o
		$(COMPIL) $(CLASSES)Rectangle.cpp -c $(HEAD) -o $(OBJECTS)Rectangle.o

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
		
		
1: 
	./Executables/Test1		
		
2: 
	./Executables/Test2
	
3: 
	./Executables/Test3	
		
4: 
	./Executables/Test4		
			
5: 
	./Executables/Test5
	
6: 
	./Executables/Test6
	
7: 
	./Executables/Test7
	
8: 
	./Executables/Test8


