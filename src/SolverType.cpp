#include "../include/SolverType.h"

SolverType::SolverType(void)
{
	for (Uint i = 0; i<10; i++)
		data_[i] = 0.0;
	solved_flag_ = false;
};

SolverType::SolverType(const SolverType &_rhs)
{
	for (Uint i = 0; i<10; i++)
		data_[i] = _rhs.data_[i];
	solved_flag_ = _rhs.solved_flag_;
};

SolverType::~SolverType(void) {};

SolverType & SolverType::operator=(const SolverType &_rhs)
{
	for (Uint i = 0; i<10; i++)
		data_[i] = _rhs.data_[i];
	solved_flag_ = _rhs.solved_flag_;
	return *this;
};

void SolverType::initialize(void)
{
	data_[1] = std::sqrt(3.0)+2.0*(Real)std::rand()/(Real)RAND_MAX;
	data_[2] = data_[6]/std::sqrt(data_[1]*data_[1]-1.0-2.0/std::sqrt(3.0)*data_[1]);
	data_[1] *= data_[2];
};

void SolverType::solve(void)
{
	Real a11, a12, a21, a22, b1, b2;
	Uint i;

	if (!solved_flag_) {
		do {
			initialize();
			for (i = 0; i < 20; i++) {
				b1 = -f(data_[1], data_[2]);
				if (std::abs(b1) < data_[9]) break;
				a11 = (f(data_[1]+data_[8], data_[2])-f(data_[1]-data_[8], data_[2]))/(2.0*data_[8]);
				a12 = (f(data_[1], data_[2]+data_[8])-f(data_[1], data_[2]-data_[8]))/(2.0*data_[8]);
				a21 = data_[1]-data_[2]/std::sqrt(3.0);
				a22 = -data_[2]-data_[1]/std::sqrt(3.0);
				data_[1] += a22*b1/(a11*a22-a12*a21);
				data_[2] += -a21*b1/(a11*a22-a12*a21);
			}
		} while (i == 20);
		
		data_[0] = std::sqrt(-data_[1]*data_[1] + data_[2]*data_[2] + 2.0*std::sqrt(3.0)*data_[1]*data_[2]);

		b1 = -std::cos(data_[0]/2.0);
		b2 = data_[0]*std::sin(data_[0]/2.0);
		a11 = std::cosh(data_[1]/2.0)*std::cos(data_[2]/2.0);
		a12 = std::sinh(data_[1]/2.0)*std::sin(data_[2]/2.0);
		a21 = data_[1]*std::sinh(data_[1]/2.0)*std::cos(data_[2]/2.0)-data_[2]*std::cosh(data_[1]/2.0)*std::sin(data_[2]/2.0);
		a22 = data_[1]*std::cosh(data_[1]/2.0)*std::sin(data_[2]/2.0)+data_[2]*std::sinh(data_[1]/2.0)*std::cos(data_[2]/2.0);
	
		data_[3] = 1.0;
		data_[4] = (a22*b1-a12*b2)/(a11*a22-a12*a21);
		data_[5] = (a11*b2-a21*b1)/(a11*a22-a12*a21);

		data_[6] = std::sqrt(data_[1]*data_[1] - data_[2]*data_[2] - 2.0/std::sqrt(3.0)*data_[1]*data_[2]);
		data_[7] = 64/(3*std::sqrt(3.0))*data_[1]*data_[1]*data_[1]*data_[2]*data_[2]*data_[2]/(data_[6]*data_[6]);

		solved_flag_ = true;
	}	
};

Real SolverType::q0(void) const
{
	return data_[0];
};

Real SolverType::q1(void) const
{
	return data_[1];
};

Real SolverType::q2(void) const
{
	return data_[2];
};

Real SolverType::A0(void) const
{
	return data_[3];
};

Real SolverType::A1(void) const
{
	return data_[4];
};

Real SolverType::A2(void) const
{
	return data_[5];
};

void SolverType::a(Real _a)
{
	data_[6] = _a;
	solved_flag_ = false;
}

Real SolverType::a(void) const
{
	return data_[6];
};

Real SolverType::R(void) const
{
	return data_[7];
};

Real SolverType::h(void) const
{
	return data_[8];
};

void SolverType::h(Real _h)
{
	data_[8] = _h;
	solved_flag_ = false;
};

Real SolverType::tol(void) const
{
	return data_[9];
};

void SolverType::tol(Real _tol)
{
	data_[9] = _tol;
	solved_flag_ = false;
};

std::ostream & operator<<(std::ostream &_os, const SolverType &_obj)
{
	_os << "q0\t" << _obj.data_[0] << "\n";
	_os << "q1\t" << _obj.data_[1] << "\n";
	_os << "q2\t" << _obj.data_[2] << "\n";
	_os << "A0\t" << _obj.data_[3] << "\n";
	_os << "A1\t" << _obj.data_[4] << "\n";
	_os << "A2\t" << _obj.data_[5] << "\n";
	_os << "a\t" << _obj.data_[6] << "\n";
	_os << "R\t" << _obj.data_[7] << "\n";
	_os << "h\t" << _obj.data_[8] << "\n";
	_os << "tol\t" << _obj.data_[9];
	return _os;
};

Real SolverType::f(Real _q1, Real _q2)
{
	Real q0 = std::sqrt(-_q1*_q1 + _q2*_q2 + 2.0*std::sqrt(3.0)*_q1*_q2);
	return ((_q1+std::sqrt(3.0)*_q2)*std::sinh(_q1)+(std::sqrt(3.0)*_q1-_q2)*std::sin(_q2))/(std::cosh(_q1)+std::cos(_q2))+q0*std::tan(q0/2.0);
	//return ((_q1+std::sqrt(3.0)*_q2)*std::sinh(_q1)-(std::sqrt(3.0)*_q1-_q2)*std::sin(_q2))/(std::cosh(_q1)-std::cos(_q2))-q0/std::tan(q0/2);
};
