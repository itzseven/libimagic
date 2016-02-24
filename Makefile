# Makefile to compile libimagic components


#	Required directories

CORE_SRC_DIR=src/core
TESTS_SRC_DIR=src/tests
OBJ_DIR=obj
BIN_DIR=bin

#	Compilers

GCC=gcc
CLANG=clang
CPL=$(CLANG)
XBUILD=xcodebuild

#	Compiler options

HEADER_SEARCH_PATHS_FLAG=-I$(CORE_SRC_DIR)/include -I$(TESTS_SRC_DIR)/include
CFLAGS=-O2 $(HEADER_SEARCH_PATHS_FLAG)

#	Library source files

CORE_C_SRC=$(CORE_SRC_DIR)/core.c
IO_C_SRC=$(CORE_SRC_DIR)/io.c
EDGE_C_SRC=$(CORE_SRC_DIR)/edge.c
LABELLING_C_SRC=$(CORE_SRC_DIR)/labelling.c
ARITHMETIC_C_SRC=$(CORE_SRC_DIR)/arithmetic.c
GEOMETRY_C_SRC=$(CORE_SRC_DIR)/geometry.c
CHARACTERIZATION_C_SRC=$(CORE_SRC_DIR)/characterization.c
MORPHO_C_SRC=$(CORE_SRC_DIR)/morpho.c

#	Library tests source files

UNIT_TESTS_C_SRC=$(TESTS_SRC_DIR)/unit_tests.c
CORE_TESTS_C_SRC=$(TESTS_SRC_DIR)/core_tests.c
IO_TESTS_C_SRC=$(TESTS_SRC_DIR)/io_tests.c
EDGE_TESTS_C_SRC=$(TESTS_SRC_DIR)/edge_tests.c
LABELLING_TESTS_C_SRC=$(TESTS_SRC_DIR)/labelling_tests.c
CHARACTERIZATION_TESTS_C_SRC=$(TESTS_SRC_DIR)/characterization_tests.c
MORPHO_TESTS_C_SRC=$(TESTS_SRC_DIR)/morpho_tests.c

#	Library header files

CORE_H_SRC=$(CORE_SRC_DIR)/include/core.h
IO_H_SRC=$(CORE_SRC_DIR)/include/io.h
EDGE_H_SRC=$(CORE_SRC_DIR)/include/edge.h
LABELLING_H_SRC=$(CORE_SRC_DIR)/include/labelling.h
ARITHMETIC_H_SRC=$(CORE_SRC_DIR)/include/arithmetic.h
GEOMETRY_H_SRC=$(CORE_SRC_DIR)/include/geometry.h
CHARACTERIZATION_H_SRC=$(CORE_SRC_DIR)/include/characterization.h
MORPHO_H_SRC=$(CORE_SRC_DIR)/include/morpho.h

#	Library tests header files

CORE_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/core_tests.h
IO_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/io_tests.h
EDGE_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/edge_tests.h
LABELLING_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/labelling_tests.h
CHARACTERIZATION_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/characterization_tests.h
MORPHO_TESTS_H_SRC=$(TESTS_SRC_DIR)/include/morpho_tests.h

#	Library object files

LIBRARY_OBJ_FILES=$(OBJ_DIR)/core.o $(OBJ_DIR)/io.o $(OBJ_DIR)/edge.o $(OBJ_DIR)/labelling.o $(OBJ_DIR)/arithmetic.o $(OBJ_DIR)/geometry.o $(OBJ_DIR)/characterization.o $(OBJ_DIR)/morpho.o

#	Product names

STATIC_LIB_STD_PNAME=libimagic_std.a
STATIC_LIB_OSX_PNAME=libimagic_osx.a
STATIC_LIB_IOS_PNAME=libimagic_ios.a

#all: libimagic.a libimagictests

#	Directories rules

obj:
	mkdir -p $(OBJ_DIR)

bin:
	mkdir -p $(BIN_DIR)

# # #

#	Platform-unspecific compilations

# # #

#	Library rules

core.o: obj $(CORE_C_SRC)
	$(CPL) -c $(CORE_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@ 

io.o: obj $(IO_C_SRC) $(CORE_H_SRC)
	$(CPL) -c $(IO_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

edge.o: obj $(EDGE_C_SRC) $(CORE_H_SRC)
	$(CPL) -c $(EDGE_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

labelling.o: obj $(LABELLING_C_SRC) $(CORE_H_SRC)
	$(CPL) -c $(LABELLING_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

arithmetic.o: obj $(ARITHMETIC_C_SRC) $(CORE_H_SRC)
	$(CPL) -c $(ARITHMETIC_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

geometry.o: obj $(GEOMETRY_C_SRC)
	$(CPL) -c $(GEOMETRY_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

characterization.o: obj $(CHARACTERIZATION_C_SRC) $(LABELLING_H_SRC) $(GEOMETRY_H_SRC)
	$(CPL) -c $(CHARACTERIZATION_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

morpho.o: obj $(MORPHO_C_SRC) $(CORE_H_SRC)
	$(CPL) -c $(MORPHO_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

libimagic.a: obj bin core.o io.o edge.o labelling.o arithmetic.o geometry.o characterization.o morpho.o
	ar rcs $(BIN_DIR)/$(STATIC_LIB_STD_PNAME) $(LIBRARY_OBJ_FILES)

#	Library tests rules

core_tests.o: obj $(CORE_TESTS_C_SRC) $(CORE_H_SRC)
	$(CPL) -c $(CORE_TESTS_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

io_tests.o: obj $(IO_TESTS_C_SRC) $(IO_H_SRC)
	$(CPL) -c $(IO_TESTS_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

edge_tests.o: obj $(EDGE_TESTS_C_SRC) $(EDGE_H_SRC)
	$(CPL) -c $(EDGE_TESTS_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

labelling_tests.o: obj $(LABELLING_TESTS_C_SRC) $(LABELLING_H_SRC) $(ARITHMETIC_H_SRC)
	$(CPL) -c $(LABELLING_TESTS_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

characterization_tests.o: obj $(CHARACTERIZATION_TESTS_C_SRC) $(CHARACTERIZATION_H_SRC) $(ARITHMETIC_H_SRC)
	$(CPL) -c $(CHARACTERIZATION_TESTS_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

morpho_tests.o: obj $(MORPHO_TESTS_C_SRC) $(MORPHO_H_SRC) $(ARITHMETIC_H_SRC)
	$(CPL) -c $(MORPHO_TESTS_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

unit_tests.o: obj $(UNIT_TESTS_C_SRC) $(CORE_TESTS_H_SRC) $(IO_TESTS_H_SRC) $(EDGE_TESTS_H_SRC) $(CHARACTERIZATION_TESTS_H_SRC) $(MORPHO_TESTS_H_SRC)
	$(CPL) -c $(UNIT_TESTS_C_SRC) $(CFLAGS) -o $(OBJ_DIR)/$@

libimagictests: obj libimagic.a core_tests.o io_tests.o edge_tests.o labelling_tests.o characterization_tests.o morpho_tests.o unit_tests.o
	$(CPL) $(OBJ_DIR)/*_tests.o $(BIN_DIR)/$(STATIC_LIB_STD_PNAME) -o $(BIN_DIR)/$@

# # #

# Platform-specific compilations

#

PROJECT_ROOT=.
PROJECT=$(PROJECT_ROOT)/imagic.xcodeproj

# Mac OS X

libosx-static.a: bin
	$(XBUILD) -project $(PROJECT) -target OSX -sdk macosx -configuration Release clean build > /dev/null && cp build/Release/libOSX.a $(BIN_DIR)/$(STATIC_LIB_OSX_PNAME)


# iOS (iphoneos + iphonesimulator)

IOS_ARCHS_SIM="i386 x86_64"
IOS_ARCHS="armv7 armv7s arm64"

libiossim.a:
	$(XBUILD) ARCHS=$(IOS_ARCHS_SIM) ONLY_ACTIVE_ARCH=NO -project $(PROJECT) -target iOS-Simulator -sdk iphonesimulator -configuration Release clean build > /dev/null

libiosdev.a:
	$(XBUILD) ARCHS=$(IOS_ARCHS) ONLY_ACTIVE_ARCH=NO -project $(PROJECT) -target iOS -sdk iphoneos -configuration Release clean build > /dev/null

libimagic_iphoneos.a: bin libiossim.a libiosdev.a
	lipo -create -output $(BIN_DIR)/$(STATIC_LIB_IOS_PNAME) build/Release-iphoneos/libiOS.a build/Release-iphonesimulator/libiOS-Simulator.a


# # #

#	General rules

#

.PHONY: resources headers

all: library tests

tests: libimagictests

library: libimagic.a libosx-static.a libimagic_iphoneos.a headers

headers:
	cp -R $(CORE_SRC_DIR)/include $(BIN_DIR)/

resources:
	cp -R resources $(BIN_DIR)/

# Run the unit tests

runtests: libimagictests resources
	cd $(BIN_DIR)/ && ./libimagictests

objclean:
	rm -rf $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) && rm -rf $(BIN_DIR) && rm -rf build

#

#