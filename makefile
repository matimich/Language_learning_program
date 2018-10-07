Learn.out: main.o interface.o File_Operation.o File_Operation_Sec.o
	g++ -o Learn_language main.o interface.o FileOperation.o File_Operation_Sec.o
main.o: main.cpp
	g++ -c -Wall -pedantic main.cpp
interface.o: interface.cpp interface.hpp
	g++ -c -Wall -pedantic interface.cpp
File_Operation.o: FileOperation.cpp FileOperation.hpp
	g++ -c -Wall -pedantic FileOperation.cpp
File_Operation_Sec.o: File_Operation_Sec.cpp File_Operation_Sec.hpp
	g++ -c -Wall -pedantic File_Operation_Sec.cpp
