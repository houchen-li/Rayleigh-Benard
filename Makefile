CXX=icpc
CFLAGS=-O3

all: bin/Rayleigh-Benard-chandrasekhar-even bin/Rayleigh-Benard-chandrasekhar-odd bin/Rayleigh-Benard-hurle-even programs/Rayleigh-Benard-hurle-odd

bin/Rayleigh-Benard-chandrasekhar-even: programs/Rayleigh-Benard-chandrasekhar-even.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/Rayleigh-Benard-chandrasekhar-even obj/def.o obj/utils.o obj/SolverType.o programs/Rayleigh-Benard-chandrasekhar-even.cpp -lm -lboost_program_options -O3

bin/Rayleigh-Benard-chandrasekhar-odd: programs/Rayleigh-Benard-chandrasekhar-odd.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/Rayleigh-Benard-chandrasekhar-odd obj/def.o obj/utils.o obj/SolverType.o programs/Rayleigh-Benard-chandrasekhar-odd.cpp -lm -lboost_program_options -O3

bin/Rayleigh-Benard-hurle-even: programs/Rayleigh-Benard-hurle-even.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/Rayleigh-Benard-hurle-even obj/def.o obj/utils.o obj/SolverType.o programs/Rayleigh-Benard-hurle-even.cpp -lm -lboost_program_options -O3

programs/Rayleigh-Benard-hurle-odd: programs/Rayleigh-Benard-hurle-odd.cpp obj/def.o obj/utils.o obj/SolverType.o
	$(CXX) -o bin/Rayleigh-Benard-hurle-odd obj/def.o obj/utils.o obj/SolverType.o programs/Rayleigh-Benard-hurle-odd.cpp -lm -lboost_program_options -O3

obj/def.o: src/def.cpp include/def.h
	$(CXX) -c -o obj/def.o src/def.cpp $(CFLAGS)

obj/utils.o: src/utils.cpp include/utils.h
	$(CXX) -c -o obj/utils.o src/utils.cpp $(CFLAGS)

obj/SolverType.o: src/SolverType.cpp include/SolverType.h
	$(CXX) -c -o obj/SolverType.o src/SolverType.cpp $(CFLAGS)

clean:
	rm -f obj/* bin/*
