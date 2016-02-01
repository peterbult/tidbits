//
//  Convert.h
//  Custom Tools
//
//  Created by Peter on 20-11-09.
//  Copyright 2009 P.M. Bult. All rights reserved.
//
//  Version 1.1
//

#pragma once
#include <iostream>
#include <sstream>

// Inline variant, no validity check
template <class T>
std::string toString(T number) {
	std::stringstream strs;
	strs << number;
	return strs.str();
}
// Stored variant, with validity check
template <class T>
bool toString(const T& val, std::string &str) {
    std::stringstream strs;
    if ( !(strs << val).fail() ) {
        str = strs.str();
        return true;
    } else
        return false;
}

// Inline variant, no validity check
template <class T>
T fromString(const std::string& str) {
    std::istringstream iss(str);
    T number;
    iss >> std::dec >> number;
    return number;
}
// Stored variant, with validity check
template <class T>
bool fromString(const std::string& str, T &val) {
    std::istringstream iss(str);
    return !(iss >> std::dec >> val).fail();
}

namespace {
    // Define template access
    template<class T> T sto( std::string s );

    // Integer type specializations
    template<> int       sto<int      >( std::string s ) { return std::stoi( s ); }
    template<> long      sto<long     >( std::string s ) { return std::stol( s ); }
    template<> long long sto<long long>( std::string s ) { return std::stoll( s ); }

    // Unsigned type specializations
    template<> unsigned long        sto<unsigned long       >( std::string s ) { return std::stoul( s ); }
    template<> unsigned long long   sto<unsigned long long  >( std::string s ) { return std::stoul( s ); }

    // Floating-point specializations
    template<> float       sto<float      >( std::string s ) { return std::stof( s ); }
    template<> double      sto<double     >( std::string s ) { return std::stod( s ); }
    template<> long double sto<long double>( std::string s ) { return std::stold( s ); }

    // String type safeguard
    template<> std::string sto<std::string>( std::string s ) { return s; }
}

