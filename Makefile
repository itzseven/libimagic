CLANG=clang
CFLAGS=-W
HEADFLAGS=-Isrc/core/include -Isrc/tests/include
OBJ=obj
LIBRARY_OBJ_FILES=$(OBJ)/core.o $(OBJ)/io.o

all:libimagic.a libimagictests

core.o: src/core/core.c
	$(CLANG) -c $(HEADFLAGS) $< -o $(OBJ)/$@ $(CFLAGS)

io.o: src/core/io.c src/core/include/core.h
	$(CLANG) -c $(HEADFLAGS) $< -o $(OBJ)/$@ $(CFLAGS)

libimagic.a: core.o io.o
	ar rcs $(OBJ)/$@ $(LIBRARY_OBJ_FILES)

core_tests.o: src/tests/core_tests.c src/core/include/core.h
	$(CLANG) -c $(HEADFLAGS) $< -o $(OBJ)/$@ $(CFLAGS)

io_tests.o: src/tests/io_tests.c src/core/include/io.h
	$(CLANG) -c $(HEADFLAGS) $< -o $(OBJ)/$@ $(CFLAGS)

unit_tests.o: src/tests/unit_tests.c src/tests/include/core_tests.h src/tests/include/io_tests.h
	$(CLANG) -c $(HEADFLAGS) $< -o $(OBJ)/$@ $(CFLAGS)

libimagictests: core.o io.o core_tests.o io_tests.o unit_tests.o
	$(CLANG) -o $(OBJ)/$@ $(OBJ)/*.o

clean:
	rm obj/*.o
	rm obj/*.a