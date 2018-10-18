#include <boost/program_options.hpp>
#include <exception>
#include <H5Cpp.h>
#include "../include/def.h"
#include "../include/utils.h"
#include "../include/SolverType.h"

void parseArgv(int _argc, char *_argv[], Real &_a0, Real &_a1, Uint &_num, String &_file_name);
Real * linspace(Real _a0, Real _a1, Uint _num);
Real * genData(Real *_a, Uint _num, Rayleigh_Benard::SolverType &_s, const Rayleigh_Benard::ModeType &_flag);
void write2file(Real *_data, Uint _num, const String &_object_name, H5::H5File &_file);

int main(int argc, char *argv[])
{
	Real a0, a1, h = 1e-6, tol = 1e-8;
	Uint num, i;
	Real *a, *data;
	String file_name, dataset_names[8] = {"/rigid_temp_even", "/rigid_temp_odd", "/rigid_heat_even", "/rigid_heat_odd", "/free_temp_even", "/free_temp_odd", "/free_heat_even", "/free_heat_odd"};
	std::stringstream ss;
	Rayleigh_Benard::SolverType s;
	Rayleigh_Benard::ModeType modes[8] = {Rayleigh_Benard::rigid_temp_even, Rayleigh_Benard::rigid_temp_odd, Rayleigh_Benard::rigid_heat_even, Rayleigh_Benard::rigid_heat_odd, Rayleigh_Benard::free_temp_even, Rayleigh_Benard::free_temp_odd, Rayleigh_Benard::free_heat_even, Rayleigh_Benard::free_heat_odd};
	
	std::srand(std::time(0));
	try {
		parseArgv(argc, argv, a0, a1, num, file_name);
	} catch (std::exception &e) {
		return 1;
	}

	hsize_t dim[2] = {num, 8};
	H5::H5File file(file_name, H5F_ACC_TRUNC);
	H5::DataSet dataset;
	H5::DataSpace dataspace(2, dim);

	s.h(h);
	s.tol(tol);

	a = linspace(a0, a1, num);

	for (i = 0; i < 8; i++) {
		data = genData(a, num, s, modes[i]);
		dataset = file.createDataSet(dataset_names[i], H5::PredType::NATIVE_DOUBLE, dataspace);
		dataset.write(data, H5::PredType::NATIVE_DOUBLE);
		delete[] data;
	}
	delete[] a;
	
	a=nullptr;
	data=nullptr;

	file.close();

	return 0;
}

void parseArgv(int _argc, char *_argv[], Real &_a0, Real &_a1, Uint &_num, String &_file_name)
{
	boost::program_options::options_description desc("This program is used to calculate the eigen pertubation modes of Rayleigh-Benard system.\nThe allowed options are:");
	desc.add_options()
		("help,h", "produce help message")
		("mode_down,d", boost::program_options::value<Real>(&_a0), "mode number of down boundary")
		("mode_up,u", boost::program_options::value<Real>(&_a1), "mode number of up boundary")
		("num,n", boost::program_options::value<Uint>(&_num), "grid number of the mode numbers")
		("output,o", boost::program_options::value<String>(&_file_name)->default_value(String("data.h5")), "output file name")
	;

	boost::program_options::variables_map vm;
	boost::program_options::store(boost::program_options::parse_command_line(_argc, _argv, desc), vm);
	boost::program_options::notify(vm);

	if (vm.count("help")) {
		std::cout << desc;
		throw std::invalid_argument("help");
	}

	if (!vm.count("mode_down")) {
		std::cerr << "The down mode number a0 hasn't been set.\n";
		throw std::invalid_argument("mode_down");
	}

	if (!vm.count("mode_up")) {
		std::cerr << "The up mode number a1 hasn't been set.\n";
		throw std::invalid_argument("mode_up");
	}

	if (!vm.count("num")) {
		std::cerr << "The grid number of the mode numbers hasn't been set.\n";
		throw std::invalid_argument("num");
	}
}

Real * linspace(Real _a0, Real _a1, Uint _num)
{
	Real h = (_a1-_a0)/(_num-1);
	Real *arr = new Real [_num];
	Uint i;

	arr[0] = _a0;
	for (i = 1; i < _num; i++)
		arr[i] = arr[i-1]+h;

	return arr;
}

Real * genData(Real *_a, Uint _num, Rayleigh_Benard::SolverType &_s, const Rayleigh_Benard::ModeType &_flag)
{
	Real *data = new Real[_num*8];
	Uint i;

	for (i = 0; i < _num; i++) {
		_s.a(_a[i]);
		_s.solve(_flag);
		data[8*i] = _s.a();
		data[8*i+1] = _s.R();
		data[8*i+2] = _s.q0();
		data[8*i+3] = _s.q1();
		data[8*i+4] = _s.q2();
		data[8*i+5] = _s.A0();
		data[8*i+6] = _s.A1();
		data[8*i+7] = _s.A2();
	}

	return data;
}

