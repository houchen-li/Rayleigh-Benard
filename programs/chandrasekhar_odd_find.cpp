#include <ctime>
#include "../include/def.h"
#include "../include/utils.h"
#include "../include/SolverType.h"

Real genR(Real _a);
Real genDerR(Real _a);

int main(void)
{
	Real a_low = 1.0, a_high = 7.0, a=(a_low+a_high)/2.0, Der_R_low, Der_R_high, Der_R, sec = 1e-6;
	Rayleigh_Benard::SolverType s;

	printLine('*');
	std::srand(std::time(0));

	while (a_high - a_low > sec) {
		Der_R_low = genDerR(a_low);
		Der_R_high = genDerR(a_high);
		Der_R = genDerR(a);
		if (Der_R > 0)
			a_high = a;
		else
			a_low = a;
		a = (a_low+a_high)/2.0;
	}
	
	do {
		s.a(a);
		s.h(1e-6);
		s.tol(1e-8);
		s.solve(Rayleigh_Benard::chandrasekhar_odd);
	} while (s.R() > 200000.0);

	std::cout << s << std::endl;
	printLine('*');

	return 0;
}

Real genR(Real _a)
{
	Rayleigh_Benard::SolverType s;
	do {
		s.a(_a);
		s.h(1e-6);
		s.tol(1e-8);
		s.solve(Rayleigh_Benard::chandrasekhar_odd);
	} while (s.R() > 200000.0);
	return s.R();
}

Real genDerR(Real _a)
{
	Real inv = 1e-6;
	return (genR(_a+inv)-genR(_a-inv))/(2.0*inv);
}
