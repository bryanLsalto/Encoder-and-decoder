OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


program.exe: program.o
	g++ -o program.exe  *.o $(OPCIONS)

program.o:
	g++ -c *.cc $(OPCIONS)

doxy:
	doxygen Doxyfile && zip -r html.zip html


archivo:
	tar -cvf practica.tar *.cc *.hh Makefile html.zip jp_bryan.leonardo.salto.zip

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar
	rm -f html.zip



