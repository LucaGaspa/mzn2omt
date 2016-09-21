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

#include "number.h"
#include <sstream>
#include <iomanip>

#include <iostream>

//-----------------------------------------------------------------------------
// Static Members
//-----------------------------------------------------------------------------


const DNumber DNumber::plus_inf(1, 0);
const DNumber DNumber::minus_inf(-1, 0);
const mpz_class DNumber::zero_(0);

const std::string minus_inf_repr = "(- 1000000000)"; // "-inf"
const std::string plus_inf_repr = "1000000000";      // "+inf"
const std::string indeterminate_repr = "(/ 0 0)";    // "0/0"
const std::string eps_repr = "(/ 1 1000000000)";     // "eps"

//-----------------------------------------------------------------------------
// Init/Deinit
//-----------------------------------------------------------------------------

DNumber::DNumber():
    val_(0), eps_(0)
{
    /* nothing to do */
};

DNumber::DNumber(std::string sv, std::string se)
{
    // NOTE: mpq_class supports floats in 'N/D' format only,
    // this tweak allows for using the 'N.DDDD' format
    int pos = sv.find('.');
    int len = sv.length();
    std::string den = "1";
    if (pos > 0) {
        sv.erase(pos, 1);
    }
    val_.set_str(sv, 10);
    if (pos > 0) {
        for (size_t i = 0; i < (len - pos - 1); ++i) den += "0";
        val_ /= mpq_class(den);
        val_.canonicalize();
    }
    // NOTE: unlikely, still possible
    pos = se.find('.');
    len = se.length();
    den = "1";
    if (pos > 0) {
        se.erase(pos, 1);
    }
    eps_.set_str(se, 10);
    if (pos > 0) {
        for (size_t i = 0; i < (len - pos - 1); ++i) den += "0";
        eps_ /= mpq_class(den);
        eps_.canonicalize();
    }
}

DNumber::DNumber(long nv, long dv, long ne, long de)
{
    val_ = mpq_class(nv, dv);
    eps_ = mpq_class(ne, de);
};

DNumber::DNumber(const DNumber &other):
    val_(other.val_), eps_(other.eps_)
{
    /* nothing to do */
};

DNumber & DNumber::operator=(const DNumber &other)
{
    if (this != &other) {
        val_ = other.val_;
        eps_ = other.eps_;
    }
    return *this;
};

    //------------------------------------
    // My constructor
    //------------------------------------
    
    DNumber::DNumber(int i){
        val_ = mpq_class(i, 1);
        eps_ = mpq_class(0, 1);
    }

    DNumber::DNumber(double d){
        std::ostringstream strs;
        strs << std::setprecision(64) << d;
        std::string nstr = strs.str();
        val_.set_str(nstr, 10);
        eps_.set_str("0", 10);
    }

    DNumber::DNumber(unsigned long l){
        val_ = mpq_class(l, 1);
        eps_ = mpq_class(0, 1);
    }

    DNumber::DNumber(mpq_class v,mpq_class e){
        val_ = v;
        eps_ = e;
    }
    //------------------------------------
    // My operator
    //------------------------------------

    DNumber & DNumber::operator+(const DNumber &other) const{
        DNumber* tmp = new DNumber(val_ + other.val_, eps_ + other.eps_);
        return *tmp;
    }
    DNumber & DNumber::operator+(const int other) const{
        DNumber* tmp = new DNumber(val_ + other, eps_);
        return *tmp;
    }
    DNumber & DNumber::operator-(const DNumber &other) const{
        DNumber* tmp = new DNumber(val_ - other.val_, eps_ - other.eps_);
        return *tmp;
    }
    DNumber & DNumber::operator-(const int other) const{
        DNumber* tmp = new DNumber(val_ - other, eps_);
        return *tmp;
    }
    bool DNumber::operator>(const DNumber &other) const{
        return compare(*this, other) > 0;
    }
    bool DNumber::operator<(const DNumber &other) const{
        return compare(*this, other) < 0;
    }
    bool DNumber::operator<=(const DNumber &other) const{
        return compare(*this, other) <= 0;
    }
    bool DNumber::operator ==(const DNumber &other) const{
        return compare(*this, other) == 0;
    }
    DNumber & DNumber::operator+=(const DNumber &other){
        if (this != &other) {
            val_ = val_ + other.val_;
            eps_ = eps_ + other.eps_;
        }
        return *this;
    }

    //------------------------------------

DNumber::~DNumber()
{
    /* nothing to do */
};

//-----------------------------------------------------------------------------
// Public Interface
//-----------------------------------------------------------------------------

bool DNumber::is_inf() const
{
    return 0 == cmp(zero_, val_.get_den());
};

bool DNumber::is_plus_inf() const
{
    return is_inf()
           && 0 < cmp(val_.get_num(), zero_);
};

bool DNumber::is_minus_inf() const
{
    return is_inf()
           && 0 > cmp(val_.get_num(), zero_);
};

bool DNumber::is_strict() const
{
    return !is_inf() &&
           0 != cmp(zero_, eps_.get_num());
};

int DNumber::compare(const DNumber &op1, const DNumber &op2)
{
    int ret;
    if (op1.is_inf()) {
        if (op2.is_inf()) {
            if ((op1.is_plus_inf() && op2.is_plus_inf())
                    || (op1.is_minus_inf() && op2.is_minus_inf())) {
                ret = 0;
            } else {
                ret = cmp(op1.val_, op2.val_);
            }
        } else {
            ret = cmp(op1.val_.get_num(), DNumber::zero_);
        }
    } else if (op2.is_inf()) {
        ret = cmp(DNumber::zero_, op2.val_.get_num());
    } else {
        ret = cmp(op1.val_, op2.val_);
        if (ret == 0) {
            ret = cmp(op1.eps_, op2.eps_);
        }
    }
    return ret;
};

std::string DNumber::to_str() const
{
    std::stringstream ss;
    if (is_inf()) {
        if (is_plus_inf()) {
            ss << plus_inf_repr;
        } else if (is_minus_inf()) {
            ss << minus_inf_repr;
        } else {
            ss << indeterminate_repr;
        }
    } else {
        // NOTE: only when you are sure that epsilon part *can* be ignored,
        // then use 'integral_repr()' instead of 'to_str()'
        int ret = cmp(eps_, zero_);
        if (ret < 0) ss << "(- ";
        if (ret > 0) ss << "(+ ";
        ss << mpq_to_smt2(val_);
        if (ret < 0) ss << eps_repr << ")";
        if (ret > 0) ss << eps_repr << ")";
    }
    return ss.str();
};

std::string DNumber::integral_repr() const
{
    std::stringstream ss;
    if (is_inf()) {
        if (is_plus_inf()) {
            ss << plus_inf_repr;
        } if (is_minus_inf()) {
            ss << minus_inf_repr;
        } else {
            ss << indeterminate_repr;
        }
    } else {
        ss << mpq_to_smt2(val_);
    }
    return ss.str();
};

std::string DNumber::epsilon_repr() const
{
    std::stringstream ss;
    int ret = cmp(eps_, zero_);
    if (ret < 0) ss << "(- " << eps_repr << ")";
    if (ret > 0) ss << eps_repr;
    return ss.str();
};

std::string DNumber::mpq_to_smt2(const mpq_class &value) const
{
    static mpz_class one(1);
    const mpz_class &den = value.get_den();
    if (cmp(den, one) == 0) {
        return value.get_str(10);
    } else {
        std::stringstream ss;
        ss << "(/ ";
        ss << value.get_num().get_str(10);
        ss << " ";
        ss << den.get_str(10);
        ss << ")";
        return ss.str();
    }
};

//-----------------------------------------------------------------------------
// Private Help Functions
//-----------------------------------------------------------------------------

