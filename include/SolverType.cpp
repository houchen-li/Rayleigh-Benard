#include "SolverType.h"

SolverType::SolverType(void) { for (Uint i = 0; i<8; i++) data_[i]=0.0; };

SolverType::SolverType(const SolverType &_rhs)
{
	for (Uint i = 0; i<8; i++)
		data_[i] = _rhs.data_[i];
	solved_flag_ = _rhs.solved_flag_;
};

SolverType::~SolverType(void) {};

SolverType & SolverType::operator=(const SolverType &_rhs)
{
	for (Uint i = 0; i<8; i++)
		data_[i] = _rhs.data_[i];
	solved_flag_ = _rhs.solved_flag_;
	return *this;
};

void SolverType::solve(void)
{
	Matrix A(2, 2);
	boost::numeric::ublas::permutation_matrix<Real> pm(2);
	Vector x(2), dx(2);
	Real h = data_[8];
	Real tol = data_[9];
	x(0) = data_[1], x(1) = data_[2];

	if (!solved_flag_) {
		while (true) {
			dx(0) = -f(x(0), x(1)), dx(1) = 0.0;
			if (std::abs(dx(0)) < tol) break;
			A(0, 0) = (f(x(0)+h, x(1))-f(x(0)-h, x(1)))/(2.0*h), A(0, 1) = (f(x(0), x(1)+h)-f(x(0), x(1)-h))/(2.0*h);
			A(1, 0) = x(0)-x(1)/std::sqrt(3.0), A(1, 1) = -x(0)-x(1)/std::sqrt(3.0);	
			boost::numeric::ublas::lu_factorize(A, pm);
			boost::numeric::ublas::lu_substitute(A, pm, dx);
			x += dx;
		}
		data_[0] = x(0)*x(0) - x(1)*x(1) - 2.0*std::sqrt(3.0)/3.0*x(0)*x(1);
		data_[1] = x(0);
		data_[2] = x(1);
		
	}	
};

Real SolverType::q0(void) const
{
	return data_[0];
};

void SolverType::q1(Real _q1)
{
	data_[1] = _q1;
	solved_flag_ = false;
};

Real SolverType::q1(void) const
{
	return data_[1];
};

void SolverType::q2(Real _q2)
{
	data_[2] = _q2;
	solved_flag_ = false;
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
	_os << "tol\t" << _obj.data_[9] << "\n";
	return _os;
};

Real SolverType::f(Real _q1, Real _q2)
{
	Real q0 = _q1*_q1 - _q2*_q2 - 2.0*std::sqrt(3.0)/3.0*_q1*_q2;
	return ((_q1+std::sqrt(3.0)*_q2)*std::sinh(_q1)+(std::sqrt(3.0)*_q1-_q2)*std::sin(_q2))/(std::cosh(_q1)+std::cos(_q2))+q0*std::tan(q0/2);
	//return ((_q1+std::sqrt(3.0)*_q2)*std::sinh(_q1)-(std::sqrt(3.0)*_q1-_q2)*std::sin(_q2))/(std::cosh(_q1)-std::cos(_q2))-q0/std::tan(q0/2);
};
