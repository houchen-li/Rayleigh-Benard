CXX=g++
CFLAGS=-O3

all: bin/genModeFactors

bin/genModeFactors: programs/genModeFactors.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/genModeFactors obj/def.o obj/utils.o obj/SolverType.o programs/genModeFactors.cpp -lm -lboost_program_options -O3 -lhdf5 -lhdf5_cpp

obj/def.o: src/def.cpp include/def.h
	$(CXX) -c -o obj/def.o src/def.cpp $(CFLAGS)

obj/utils.o: src/utils.cpp include/utils.h
	$(CXX) -c -o obj/utils.o src/utils.cpp $(CFLAGS)

obj/SolverType.o: src/SolverType.cpp include/SolverType.h
	$(CXX) -c -o obj/SolverType.o src/SolverType.cpp $(CFLAGS)

clean:
	rm -f obj/* bin/*
