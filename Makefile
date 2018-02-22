test: main.cpp include/utilities.hpp include/SolverType.h src/SolverType.cpp
	g++ -o test include/utilities.hpp include/SolverType.h main.cpp src/SolverType.cpp -lm
