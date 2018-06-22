#include "../include/SolverType.h"

Rayleigh_Benard::SolverType::SolverType(void)
{
	for (Uint i = 0; i<10; i++)
		data_[i] = 0.0;
};

Rayleigh_Benard::SolverType::SolverType(const SolverType &_rhs)
{
	for (Uint i = 0; i<10; i++)
		data_[i] = _rhs.data_[i];
};

Rayleigh_Benard::SolverType::~SolverType(void) {};

Rayleigh_Benard::SolverType & Rayleigh_Benard::SolverType::operator=(const SolverType &_rhs)
{
	for (Uint i = 0; i<10; i++)
		data_[i] = _rhs.data_[i];
	return *this;
};

void Rayleigh_Benard::SolverType::initialize(void)
{
	data_[3] = std::sqrt(3.0)+2.0*(Real)std::rand()/(Real)RAND_MAX;
	data_[4] = data_[0]/std::sqrt(data_[3]*data_[3]-1.0-2.0/std::sqrt(3.0)*data_[3]);
	data_[3] *= data_[4];
};

void Rayleigh_Benard::SolverType::solve(const Rayleigh_Benard::ModeType &e)
{
	Real a11, a12, a21, a22, b1, b2;
	Uint i;

	switch (e) {

		case 0:
			do {
				initialize();
				b1 = -rigid_temp_even(data_[3], data_[4]);
				b2 = -data_[3]*data_[3]+data_[4]*data_[4]+2.0/std::sqrt(3.0)*data_[3]*data_[4]+data_[0]*data_[0];
				for (i = 0; i < 20; i++) {
					a11 = (-rigid_temp_even(data_[3]+2.0*data_[8], data_[4])+8.0*rigid_temp_even(data_[3]+data_[8], data_[4])-8.0*rigid_temp_even(data_[3]-data_[8], data_[4])+rigid_temp_even(data_[3]-2.0*data_[8], data_[4]))/(12.0*data_[8]);
					a12 = (-rigid_temp_even(data_[3], data_[4]+2.0*data_[8])+8.0*rigid_temp_even(data_[3], data_[4]+data_[8])-8.0*rigid_temp_even(data_[3], data_[4]-data_[8])+rigid_temp_even(data_[3], data_[4]-2.0*data_[8]))/(12.0*data_[8]);
					a21 = 2.0*(data_[3]-data_[4]/std::sqrt(3.0));
					a22 = 2.0*(-data_[3]-data_[4]/std::sqrt(3.0));
					data_[3] += (a22*b1-a12*b2)/(a11*a22-a12*a21);
					data_[4] += (a11*b2-a21*b1)/(a11*a22-a12*a21);
					b1 = -rigid_temp_even(data_[3], data_[4]);
					b2 = -data_[3]*data_[3]+data_[4]*data_[4]+2.0/std::sqrt(3.0)*data_[3]*data_[4]+data_[0]*data_[0];
					if (std::sqrt(b1*b1+b2*b2) < data_[9]) break;
				}
			} while (i == 20);
			data_[2] = std::sqrt(-data_[3]*data_[3] + data_[4]*data_[4] + 2.0*std::sqrt(3.0)*data_[3]*data_[4]);
			b1 = -std::cos(data_[2]/2.0);
			b2 = data_[2]*std::sin(data_[2]/2.0);
			a11 = std::cosh(data_[3]/2.0)*std::cos(data_[4]/2.0);
			a12 = std::sinh(data_[3]/2.0)*std::sin(data_[4]/2.0);
			a21 = data_[3]*std::sinh(data_[3]/2.0)*std::cos(data_[4]/2.0)-data_[4]*std::cosh(data_[3]/2.0)*std::sin(data_[4]/2.0);
			a22 = data_[3]*std::cosh(data_[3]/2.0)*std::sin(data_[4]/2.0)+data_[4]*std::sinh(data_[3]/2.0)*std::cos(data_[4]/2.0);
			data_[5] = 1.0;
			data_[6] = (a22*b1-a12*b2)/(a11*a22-a12*a21);
			data_[7] = (a11*b2-a21*b1)/(a11*a22-a12*a21);
			data_[0] = std::sqrt(data_[3]*data_[3] - data_[4]*data_[4] - 2.0/std::sqrt(3.0)*data_[3]*data_[4]);
			data_[1] = 64/(3*std::sqrt(3.0))*data_[3]*data_[3]*data_[3]*data_[4]*data_[4]*data_[4]/(data_[0]*data_[0]);
			break;

		case 1:
			do {
				initialize();
				b1 = -rigid_heat_even(data_[3], data_[4]);
				b2 = -data_[3]*data_[3]+data_[4]*data_[4]+2.0/std::sqrt(3.0)*data_[3]*data_[4]+data_[0]*data_[0];
				for (i = 0; i < 20; i++) {
					a11 = (-rigid_heat_even(data_[3]+2.0*data_[8], data_[4])+8.0*rigid_heat_even(data_[3]+data_[8], data_[4])-8.0*rigid_heat_even(data_[3]-data_[8], data_[4])+rigid_heat_even(data_[3]-2.0*data_[8], data_[4]))/(12.0*data_[8]);
					a12 = (-rigid_heat_even(data_[3], data_[4]+2.0*data_[8])+8.0*rigid_heat_even(data_[3], data_[4]+data_[8])-8.0*rigid_heat_even(data_[3], data_[4]-data_[8])+rigid_heat_even(data_[3], data_[4]-2.0*data_[8]))/(12.0*data_[8]);
					a21 = 2.0*(data_[3]-data_[4]/std::sqrt(3.0));
					a22 = 2.0*(-data_[3]-data_[4]/std::sqrt(3.0));
					data_[3] += (a22*b1-a12*b2)/(a11*a22-a12*a21);
					data_[4] += (a11*b2-a21*b1)/(a11*a22-a12*a21);
					b1 = -rigid_heat_even(data_[3], data_[4]);
					b2 = -data_[3]*data_[3]+data_[4]*data_[4]+2.0/std::sqrt(3.0)*data_[3]*data_[4]+data_[0]*data_[0];
					if (std::sqrt(b1*b1+b2*b2) < data_[9]) break;
				}
			} while (i == 20);
			data_[2] = std::sqrt(-data_[3]*data_[3] + data_[4]*data_[4] + 2.0*std::sqrt(3.0)*data_[3]*data_[4]);
			b1 = -std::cos(data_[2]/2.0);
			b2 = data_[2]*std::sin(data_[2]/2.0);
			a11 = std::cosh(data_[3]/2.0)*std::cos(data_[4]/2.0);
			a12 = std::sinh(data_[3]/2.0)*std::sin(data_[4]/2.0);
			a21 = data_[3]*std::sinh(data_[3]/2.0)*std::cos(data_[4]/2.0)-data_[4]*std::cosh(data_[3]/2.0)*std::sin(data_[4]/2.0);
			a22 = data_[3]*std::cosh(data_[3]/2.0)*std::sin(data_[4]/2.0)+data_[4]*std::sinh(data_[3]/2.0)*std::cos(data_[4]/2.0);
			data_[5] = 1.0;
			data_[6] = (a22*b1-a12*b2)/(a11*a22-a12*a21);
			data_[7] = (a11*b2-a21*b1)/(a11*a22-a12*a21);
			data_[0] = std::sqrt(data_[3]*data_[3] - data_[4]*data_[4] - 2.0/std::sqrt(3.0)*data_[3]*data_[4]);
			data_[1] = 64/(3*std::sqrt(3.0))*data_[3]*data_[3]*data_[3]*data_[4]*data_[4]*data_[4]/(data_[0]*data_[0]);
			break;
	
		case 2:
			do {
				initialize();
				b1 = -free_heat_even(data_[3], data_[4]);
				b2 = -data_[3]*data_[3]+data_[4]*data_[4]+2.0/std::sqrt(3.0)*data_[3]*data_[4]+data_[0]*data_[0];
				for (i = 0; i < 20; i++) {
					a11 = (-free_heat_even(data_[3]+2.0*data_[8], data_[4])+8.0*free_heat_even(data_[3]+data_[8], data_[4])-8.0*free_heat_even(data_[3]-data_[8], data_[4])+free_heat_even(data_[3]-2.0*data_[8], data_[4]))/(12.0*data_[8]);
					a12 = (-free_heat_even(data_[3], data_[4]+2.0*data_[8])+8.0*free_heat_even(data_[3], data_[4]+data_[8])-8.0*free_heat_even(data_[3], data_[4]-data_[8])+free_heat_even(data_[3], data_[4]-2.0*data_[8]))/(12.0*data_[8]);
					a21 = 2.0*(data_[3]-data_[4]/std::sqrt(3.0));
					a22 = 2.0*(-data_[3]-data_[4]/std::sqrt(3.0));
					data_[3] += (a22*b1-a12*b2)/(a11*a22-a12*a21);
					data_[4] += (a11*b2-a21*b1)/(a11*a22-a12*a21);
					b1 = -free_heat_even(data_[3], data_[4]);
					b2 = -data_[3]*data_[3]+data_[4]*data_[4]+2.0/std::sqrt(3.0)*data_[3]*data_[4]+data_[0]*data_[0];
					if (std::sqrt(b1*b1+b2*b2) < data_[9]) break;
				}
			} while (i == 20);
			data_[2] = std::sqrt(-data_[3]*data_[3] + data_[4]*data_[4] + 2.0*std::sqrt(3.0)*data_[3]*data_[4]);
			b1 = -std::cos(data_[2]/2.0);
			b2 = data_[2]*std::sin(data_[2]/2.0);
			a11 = std::cosh(data_[3]/2.0)*std::cos(data_[4]/2.0);
			a12 = std::sinh(data_[3]/2.0)*std::sin(data_[4]/2.0);
			a21 = data_[3]*std::sinh(data_[3]/2.0)*std::cos(data_[4]/2.0)-data_[4]*std::cosh(data_[3]/2.0)*std::sin(data_[4]/2.0);
			a22 = data_[3]*std::cosh(data_[3]/2.0)*std::sin(data_[4]/2.0)+data_[4]*std::sinh(data_[3]/2.0)*std::cos(data_[4]/2.0);
			data_[5] = 1.0;
			data_[6] = (a22*b1-a12*b2)/(a11*a22-a12*a21);
			data_[7] = (a11*b2-a21*b1)/(a11*a22-a12*a21);
			data_[0] = std::sqrt(data_[3]*data_[3] - data_[4]*data_[4] - 2.0/std::sqrt(3.0)*data_[3]*data_[4]);
			data_[1] = 64/(3*std::sqrt(3.0))*data_[3]*data_[3]*data_[3]*data_[4]*data_[4]*data_[4]/(data_[0]*data_[0]);
			break;
	}
};

void Rayleigh_Benard::SolverType::a(Real _a)
{
	data_[0] = _a;
}

Real Rayleigh_Benard::SolverType::a(void) const
{
	return data_[0];
};

Real Rayleigh_Benard::SolverType::R(void) const
{
	return data_[1];
};


Real Rayleigh_Benard::SolverType::q0(void) const
{
	return data_[2];
};

Real Rayleigh_Benard::SolverType::q1(void) const
{
	return data_[3];
};

Real Rayleigh_Benard::SolverType::q2(void) const
{
	return data_[4];
};

Real Rayleigh_Benard::SolverType::A0(void) const
{
	return data_[5];
};

Real Rayleigh_Benard::SolverType::A1(void) const
{
	return data_[6];
};

Real Rayleigh_Benard::SolverType::A2(void) const
{
	return data_[7];
};

Real Rayleigh_Benard::SolverType::h(void) const
{
	return data_[8];
};

void Rayleigh_Benard::SolverType::h(Real _h)
{
	data_[8] = _h;
};

Real Rayleigh_Benard::SolverType::tol(void) const
{
	return data_[9];
};

void Rayleigh_Benard::SolverType::tol(Real _tol)
{
	data_[9] = _tol;
};

std::ostream & Rayleigh_Benard::operator<<(std::ostream &_os, const Rayleigh_Benard::SolverType &_obj)
{
	_os << "a\t" << _obj.data_[0] << "\n";
	_os << "R\t" << _obj.data_[1] << "\n";
	_os << "q0\t" << _obj.data_[2] << "\n";
	_os << "q1\t" << _obj.data_[3] << "\n";
	_os << "q2\t" << _obj.data_[4] << "\n";
	_os << "A0\t" << _obj.data_[5] << "\n";
	_os << "A1\t" << _obj.data_[6] << "\n";
	_os << "A2\t" << _obj.data_[7] << "\n";	
	_os << "h\t" << _obj.data_[8] << "\n";
	_os << "tol\t" << _obj.data_[9];
	return _os;
};

Real Rayleigh_Benard::SolverType::rigid_temp_even(Real _q1, Real _q2)
{
	Real q0 = std::sqrt(-_q1*_q1 + _q2*_q2 + 2.0*std::sqrt(3.0)*_q1*_q2);
	return ((_q1+std::sqrt(3.0)*_q2)*std::sinh(_q1)+(std::sqrt(3.0)*_q1-_q2)*std::sin(_q2))/(std::cosh(_q1)+std::cos(_q2))+q0*std::tan(q0/2.0);
};

Real Rayleigh_Benard::SolverType::rigid_heat_even(Real _q1, Real _q2)
{
	Real q0 = std::sqrt(-_q1*_q1 + _q2*_q2 + 2.0*std::sqrt(3.0)*_q1*_q2);
	return (_q1*_q1+_q2*_q2)*(std::cosh(_q1)-std::cos(_q2))/((_q1-std::sqrt(3.0)*_q2)*std::sinh(_q1)-(std::sqrt(3.0)*_q1+_q2)*std::sin(_q2))+q0*std::tan(q0/2.0);
};

Real Rayleigh_Benard::SolverType::free_heat_even(Real _q1, Real _q2)
{
	Real q0 = std::sqrt(-_q1*_q1 + _q2*_q2 + 2.0*std::sqrt(3.0)*_q1*_q2);
	return 2.0*(_q1*std::sinh(_q1)-_q2*std::sin(_q2))/(std::cosh(_q1)+std::(_q2))-q0*std::tan(q0/2.0);
}
