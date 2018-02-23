#include <ctime>
#include <boost/program_options.hpp>
#include <exception>
#include "../include/def.h"
#include "../include/utils.h"
#include "../include/SolverType.h"

void parseArgv(int _argc, char *_argv[], Real &_new_a);

int main(int argc, char *argv[])
{
	Real new_a, new_h = 1e-6, new_tol = 1e-8;
	Rayleigh_Benard::SolverType s;

	printLine('*');
	std::srand(std::time(0));
	try {
		parseArgv(argc, argv, new_a);
	} catch (std::exception &e) {
		printLine('*');
		return 1;
	}
	s.a(new_a);
	s.h(new_h);
	s.tol(new_tol);
	s.solve(Rayleigh_Benard::chandrasekhar_even);
	std::cout << s << std::endl;
	printLine('*');

	return 0;
}

void parseArgv(int _argc, char *_argv[], Real &_new_a)
{
	boost::program_options::options_description desc("This program is used to calculate the eigen pertubation modes of Rayleigh-Benard system.\nThe allowed options are:");
	desc.add_options()
		("help,h", "produce help message")
		("mode,a", boost::program_options::value<Real>(&_new_a), "mode number")
	;

	boost::program_options::variables_map vm;
	boost::program_options::store(boost::program_options::parse_command_line(_argc, _argv, desc), vm);
	boost::program_options::notify(vm);

	if (vm.count("help")) {
		std::cout << desc;
		throw std::invalid_argument("help");
	}

	if (!vm.count("mode")) {
		std::cerr << "The mode number a hasn't been set.\n";
		throw std::invalid_argument("mode");
	}
}
