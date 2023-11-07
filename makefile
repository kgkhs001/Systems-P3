all: ctest tester

ctest: ctest.o mystring.o
	gcc ctest.o mystring.o -o ctest

ctest.o: ctest.c mystring.h
	gcc -c ctest.c
	
tester: tester.o structs.o mystring.o
	gcc tester.o structs.o mystring.o -o tester

tester.o: tester.c structs.h mystring.h
	gcc -c tester.c

structs.o: structs.c structs.h
	gcc -c structs.c
	

mystring.o: mystring.c mystring.h
	gcc -c mystring.c

docs:
	doxygen
	cp html/. ~/public_html/cs2303_hw03 -p -r


clean: 
	rm -f mystring.o ctest.o structs.o tester.o ctest tester
