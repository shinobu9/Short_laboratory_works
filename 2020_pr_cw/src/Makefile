CC=g++
FLAG=

all: bimped clean

bimped: editor.o printInfoHelp.o saveFile.o checker.o argumentHandler.o tasks.o processing.o
	$(CC) $(FLAG) editor.o printInfoHelp.o saveFile.o checker.o argumentHandler.o tasks.o processing.o -o bimped

editor.o: editor.cpp structures.hpp printInfoHelp.hpp tasks.hpp saveFile.hpp checker.hpp argumentHandler.hpp processing.hpp
	$(CC) $(FLAG) -c editor.cpp

printInfoHelp.o: printInfoHelp.cpp printInfoHelp.hpp
	$(CC) $(FLAG) -c printInfoHelp.cpp

saveFile.o: saveFile.cpp saveFile.hpp
	$(CC) $(FLAG) -c saveFile.cpp

checker.o: checker.cpp checker.hpp
	$(CC) $(FLAG) -c checker.cpp

argumentHandler.o: argumentHandler.cpp argumentHandler.hpp checker.hpp
	$(CC) $(FLAG) -c argumentHandler.cpp

tasks.o: tasks.cpp tasks.hpp saveFile.hpp
	$(CC) $(FLAG) -c tasks.cpp

processing.o: processing.cpp processing.hpp tasks.hpp checker.hpp saveFile.hpp
	$(CC) $(FLAG) -c processing.cpp

clean:
	rm -f *.o
