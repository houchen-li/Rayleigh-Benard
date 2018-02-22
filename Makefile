CXX=icpc
CFLAGS=-O3

Rayleigh-Benard-2-odd: main.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o Rayleigh-Benard-2-odd obj/def.o obj/utils.o obj/SolverType.o main.cpp -lm -lboost_program_options -O3

obj/def.o: src/def.cpp include/def.h
	$(CXX) -c -o obj/def.o src/def.cpp $(CFLAGS)

obj/utils.o: src/utils.cpp include/utils.h
	$(CXX) -c -o obj/utils.o src/utils.cpp $(CFLAGS)

obj/SolverType.o: src/SolverType.cpp include/SolverType.h
	$(CXX) -c -o obj/SolverType.o src/SolverType.cpp $(CFLAGS)

clean:
	rm -f obj/* Rayleigh-Benard-2-odd
