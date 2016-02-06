CORE_SRC_DIR=src/core
TESTS_SRC_DIR=src/tests
OBJ_DIR=obj

CLANG=clang
CFLAGS=
HEADFLAGS=-I$(CORE_SRC_DIR)/include -I$(TESTS_SRC_DIR)/include

CORE_C_SRC=$(CORE_SRC_DIR)/core.c
IO_C_SRC=$(CORE_SRC_DIR)/io.c

UNIT_TESTS_C_SRC=$(TESTS_SRC_DIR)/unit_tests.c
CORE_TESTS_C_SRC=$(TESTS_SRC_DIR)/core_tests.c
IO_TESTS_C_SRC=$(TESTS_SRC_DIR)/io_tests.c

CORE_H_SRC=$(CORE_SRC_DIR)/include/core.h
IO_H_SRC=$(CORE_SRC_DIR)/include/io.h

CORE_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/core_tests.h
IO_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/io_tests.h

LIBRARY_OBJ_FILES=$(OBJ_DIR)/core.o $(OBJ_DIR)/io.o

all: libimagic.a libimagictests

obj:
	mkdir -p $(OBJ_DIR)

core.o: obj $(CORE_C_SRC)
	$(CLANG) -c $(HEADFLAGS) $(CORE_C_SRC) -o $(OBJ_DIR)/$@ $(CFLAGS)

io.o: obj $(IO_C_SRC) $(CORE_H_SRC)
	$(CLANG) -c $(HEADFLAGS) $(IO_C_SRC) -o $(OBJ_DIR)/$@ $(CFLAGS)

libimagic.a: obj core.o io.o
	ar rcs $(OBJ_DIR)/$@ $(LIBRARY_OBJ_FILES)

core_tests.o: obj $(CORE_TESTS_C_SRC) $(CORE_H_SRC)
	$(CLANG) -c $(HEADFLAGS) $(CORE_TESTS_C_SRC) -o $(OBJ_DIR)/$@ $(CFLAGS)

io_tests.o: obj $(IO_TESTS_C_SRC) $(IO_H_SRC)
	$(CLANG) -c $(HEADFLAGS) $(IO_TESTS_C_SRC) -o $(OBJ_DIR)/$@ $(CFLAGS)

unit_tests.o: obj $(UNIT_TESTS_C_SRC) $(CORE_TESTS_H_SRC) $(IO_TESTS_H_SRC)
	$(CLANG) -c $(HEADFLAGS) $(UNIT_TESTS_C_SRC) -o $(OBJ_DIR)/$@ $(CFLAGS)

libimagictests: obj core.o io.o core_tests.o io_tests.o unit_tests.o
	$(CLANG) -o $(OBJ_DIR)/$@ $(OBJ_DIR)/*.o

runtests: libimagictests
	cp -R resources obj/ && cd $(OBJ_DIR) && ./libimagictests

clean:
	rm -rf $(OBJ_DIR)