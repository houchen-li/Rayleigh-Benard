#include <ctime>
#include <cstdlib>
#include "include/utilities.hpp"
#include "include/SolverType.h"

int main(int argc, char *argv[])
{	
	SolverType s;
	std::srand(std::time(nullptr));
	Real r = std::sqrt(3.0)+2.0*(Real)std::rand()/(Real)RAND_MAX;

	Real a = 4, c = a/std::sqrt(r*r-1.0-2.0/std::sqrt(3.0)*r), h = 1e-8, tol = 1e-6;
	Real q1 = c*r, q2 = c;
	s.q1(q1);
	s.q2(q2);
	s.h(h);
	s.tol(tol);
	s.solve();
	std::cout << s << std::endl;
	return 0;
}
