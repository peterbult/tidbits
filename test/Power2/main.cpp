// 
// main.cpp
// Test PowerOf2 functions
//
// Created by PM Bult on 23-01-2016
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#include <iostream>

#include "../../src/Tools.h"


bool test_function()
{
    // Define two integers
    int x1 = 8192;  // A power of 2
    int x2 = 8190;  // Not a power of 2

    // Evaluate function
    bool x1_state = isPowerOf2( x1 );
    bool x2_state = isPowerOf2( x2 );

    // Evaluate results
    if ( x1_state == false ) return false;
    if ( x2_state == true  ) return false;

    // All tests passed
    return true;
}

bool test_assert()
{
    // Define two integers
    int x1 = 8192;  // A power of 2
    int x2 = 8190;  // Not a power of 2

    // Evaluate function for x1
    //   This should not throw an exception...
    try { assertPowerOf2( x1 ); }
    catch (const char* e) {
        std::cout << " * Caught exception: " << e << std::endl;
        return false;
    }


    // Evaluate for x2
    //   This should throw an exception
    try { 
        assertPowerOf2( x2 );
        return false;
    }
    catch (const char* e) {
        //std::cout << " * Caught exception: " << e << std::endl;
    }

    // All tests passed
    return true;
}

int main(int argc, const char *argv[])
{
    std::cout << " > Testing [ PowerOf2 ] functions" << std::endl;
    std::cout << std::boolalpha << std::endl;

    // Test direct function
    std::cout << "Testing [   isPowerOf2()   ] ... passed: " << test_function() << std::endl;

    // Test assert function
    std::cout << "Testing [ assertPowerOf2() ] ... passed: " << test_assert() << std::endl;
    
    return 0;
}

