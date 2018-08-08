CXX=g++
CFLAGS=-O3

all: bin/rigid-temp-even bin/rigid-heat-even bin/free-heat-even

bin/rigid-temp-even: programs/rigid-temp-even.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/rigid-temp-even obj/def.o obj/utils.o obj/SolverType.o programs/rigid-temp-even.cpp -lm -lboost_program_options -O3 -lhdf5 -lhdf5_cpp

bin/rigid-heat-even: programs/rigid-heat-even.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/rigid-heat-even obj/def.o obj/utils.o obj/SolverType.o programs/rigid-heat-even.cpp -lm -lboost_program_options -O3 -lhdf5 -lhdf5_cpp

bin/free-heat-even: programs/free-heat-even.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/free-heat-even obj/def.o obj/utils.o obj/SolverType.o programs/free-heat-even.cpp -lm -lboost_program_options -O3 -lhdf5 -lhdf5_cpp

obj/def.o: src/def.cpp include/def.h
	$(CXX) -c -o obj/def.o src/def.cpp $(CFLAGS)

obj/utils.o: src/utils.cpp include/utils.h
	$(CXX) -c -o obj/utils.o src/utils.cpp $(CFLAGS)

obj/SolverType.o: src/SolverType.cpp include/SolverType.h
	$(CXX) -c -o obj/SolverType.o src/SolverType.cpp $(CFLAGS)

clean:
	rm -f obj/* bin/*
