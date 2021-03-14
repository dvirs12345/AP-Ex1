#Author - Dvir Sadon
CXX=clang++-9 
CXXFLAGS=-std=c++2a -Wno-potentially-evaluated-expression

DOCUMENTS=Document.cpp Document.h 
EDITORS=Editor.cpp Editor.h
OBJECTS=Document.o Editor.o main.o

all: Document.o Editor.o main.o myEditor

myEditor: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o myEditor

Document.o: $(DOCUMENTS)
	$(CXX) $(CXXFLAGS) -c Document.cpp  

Editor.o: $(EDITORS)
	$(CXX) $(CXXFLAGS) -c Editor.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp 

clean:
	rm -f *.o *.gch myEditor