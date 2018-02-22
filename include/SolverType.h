#pragma once
#ifndef __SOLVERTYPE_H__
#define __SOLVERTYPE_H__

#include <iostream>
#include <cmath>
#include "utilities.hpp"

class SolverType
{
public:
	SolverType(void);
	SolverType(const SolverType &_rhs);
	~SolverType(void);
	SolverType & operator=(const SolverType &_rhs);
	void initialize(void);
	void solve(void);
	Real q0(void) const;
	Real q1(void) const;
	Real q2(void) const;
	Real A0(void) const;
	Real A1(void) const;
	Real A2(void) const;
	void a(Real _a);
	Real a(void) const;
	Real R(void) const;
	Real h(void) const;
	void h(Real _h);
	Real tol(void) const;
	void tol(Real _tol);
	friend std::ostream & operator<<(std::ostream &_os, const SolverType &_obj);
private:
	Real f(Real _q1, Real _q2);
	Real data_[10];
	Bool solved_flag_;
};

std::ostream & operator<<(std::ostream &_os, const SolverType &_obj);

#endif
