// 
// main.cpp
// Test Vector tools
//
// Created by PM Bult on 23-01-2016
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#include <iostream>
#include <vector>
#include <valarray>
#include <deque>

#include "../../src/VectorTools.h"


bool test_sum()
{
    // Define a numeric vector
    std::vector<double> vec1 = { 1.5, 2.5, 6.0, 10.0 };

    // Evaluate sum
    //double sum1 = vectool::sum<double>( vec1 );
    double sum1 = vectool::sum( vec1 );

    // Evaluate parial sum
    double sum2 = vectool::sum( vec1.begin(), vec1.begin()+3 );

    // Test results (by fussy compare)
    if ( fabs( sum1 - 20.0) > 1e-6 ) return false;
    if ( fabs( sum2 - 10.0) > 1e-6 ) return false;
    
    // All tests passed
    return true;
}

bool test_average()
{
    // Define a numeric vector
    std::valarray<double> vec1 = { 1.5, 2.5, 6.0, 10.0 };

    // Evaluate sum
    double avg1 = vectool::average( vec1 );

    // Evaluate parial sum
    double avg2 = vectool::average( std::begin(vec1), std::begin(vec1)+3 );

    // Test results (by fussy compare)
    if ( fabs( avg1 - 20.0/4.0) > 1e-6 ) return false;
    if ( fabs( avg2 - 10.0/3.0) > 1e-6 ) return false;
    
    // All tests passed
    return true;
}

bool test_stddev()
{
    // Define a numeric vector
    //std::vector<double> vec1 = { 1.5, 2.5, 6.0, 10.0 };
    std::deque<double> vec1 = { 1.5, 2.5, 6.0, 10.0 };

    // Evaluate sum
    //double sum1 = vectool::sum<double>( vec1 );
    double dev1 = vectool::stddev( vec1 );

    // Evaluate parial sum
    double dev2 = vectool::stddev( vec1.begin(), vec1.begin()+3 );

    // Test results (by fussy compare)
    if ( fabs( dev1 - 3.3354160160) > 1e-6 ) return false;
    if ( fabs( dev2 - 1.9293061505) > 1e-6 ) return false;
    
    // All tests passed
    return true;
}

bool test_central_moment()
{
    // Define a numeric vector
    std::vector<double> vec1 = { 1.5, 2.5, 6.0, 10.0 };

    // Evaluate 3rd central moment
    double mom3_a = vectool::central_moment( vec1, 3 );

    // Evaluate parial moment
    double mom3_b = vectool::central_moment( vec1.begin(), vec1.begin()+3, 3 );

    // Test results (by fussy compare)
    if ( fabs( mom3_a - 16.87500) > 1e-5 ) return false;
    if ( fabs( mom3_b -  4.07407) > 1e-5 ) return false;
    
    // All tests passed
    return true;
}

bool test_skewness()
{
    // Define a numeric vector
    std::vector<double> vec1 = { 1.5, 2.5, 6.0, 10.0 };

    // Evaluate 3rd central moment
    double sk1 = vectool::skewness( vec1 );

    // Evaluate parial moment
    double sk2 = vectool::skewness( vec1.begin(), vec1.begin()+3 );

    // Test results (by fussy compare)
    if ( fabs( sk1 - 0.454772) > 1e-6 ) return false;
    if ( fabs( sk2 - 0.567317) > 1e-6 ) return false;
    
    // All tests passed
    return true;
}

int main(int argc, const char *argv[])
{
    std::cout << " > Testing vector tools" << std::endl;
    std::cout << std::boolalpha << std::endl;

    // Test assert function
    std::cout << "Testing [    sum()    ] ... passed: " << test_sum() << std::endl;

    // Test assert function
    std::cout << "Testing [  average()  ] ... passed: " << test_average() << std::endl;

    // Test assert function
    std::cout << "Testing [   stddev()  ] ... passed: " << test_stddev() << std::endl;
    
    // Test assert function
    std::cout << "Testing [   moment()  ] ... passed: " << test_central_moment() << std::endl;
    
    // Test assert function
    std::cout << "Testing [  skewness() ] ... passed: " << test_skewness() << std::endl;

    return 0;
}

