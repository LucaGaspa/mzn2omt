/* -*- C++ -*-
 *
 * This file is part of OptiMathSAT.
 *
 * OptiMathSAT is an extension of MathSAT 5 (http://mathsat.fbk.eu) and it is available
 * at the same conditions as MathSAT 5 (http://mathsat.fbk.eu/download.html):
 *
 * OptiMathSAT is copyrighted 2009-2016 by Fondazione Bruno Kessler, Trento, Italy,
 * University of Trento, Italy, and others. All rights reserved.
 *
 * OptiMathSAT is available for research and evaluation purposes only.
 * It can not be used in a commercial environment, particularly as part of a
 * commercial product, without written permission. OptiMathSAT is provided as is,
 * without any warranty.
 *
 * Please write to optimathsat@unitn.it for additional questions regarding licensing
 * OptiMathSAT or obtaining more up-to-date versions.
 *
 * Permission to use this file outside OptiMathSAT is granted only for
 * the mzn2omt project. Any use of these sources outside of this context is expressively
 * forbidden and subject to laws on copyright infrigement.
 *
 * Author: Patrick Trentin <patrick.trentin@unitn.it>
 */

#ifndef __NUMBER_H_INCLUDED__
#define __NUMBER_H_INCLUDED__
#include <gmpxx.h>
#include <string>

class DNumber {
public:
    DNumber();
    DNumber(std::string sv, std::string se = "");
    DNumber(long nv, long dv, long ne = 0, long de = 0);
    DNumber(const DNumber &other);
    DNumber & operator= (const DNumber &other);

    //------------------------------------
    // My constructor
    //------------------------------------

    DNumber(int i);
    DNumber(double d);
    DNumber(unsigned long l);
    DNumber(mpq_class v,mpq_class e);

    //------------------------------------
    // My operator
    //------------------------------------

    DNumber & operator+(const DNumber &other) const;
    DNumber & operator+(const int other) const;
    DNumber & operator-(const DNumber &other) const;
    DNumber & operator-(const int other) const;
    bool operator>(const DNumber &other) const;
    bool operator<(const DNumber &other) const;
    bool operator<=(const DNumber &other) const;
    bool operator ==(const DNumber &other) const;
    DNumber & operator+=(const DNumber &other);

    explicit operator bool() const;

    //------------------------------------

    virtual ~DNumber();

    bool is_inf() const;
    bool is_plus_inf() const;
    bool is_minus_inf() const;
    bool is_strict() const;

    static int compare(const DNumber &op1, const DNumber &op2);

    std::string to_str() const;
    std::string integral_repr() const;
    std::string epsilon_repr() const;

    static const DNumber plus_inf;
    static const DNumber minus_inf;

private:
    std::string mpq_to_smt2(const mpq_class &value) const;
    ///< returns SmtLibv2.0 representation of an mpq value,
    ///< NOTE: assumes the value is not infinite or indeterminate

    mpq_class val_;
    mpq_class eps_;

    static const mpz_class zero_;
};

#endif
