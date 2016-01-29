// 
// main.cpp
// Test Convert tool
//
// Created by PM Bult on 23-01-2016
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#include <iostream>
#include <cmath>

#include "../../src/Convert.h"

bool test_string_to_number()
{
    // Define two strings
    std::string str1 = "3.14159";
    std::string str2 = "abd.edf";

    // Initialize two doubles
    double d1 = -1, d2 = -1;

    // Convert with validity check
    if ( !fromString<double>( str1, d1 ) )
        return false;

    if ( fromString<double>( str2, d2 ) )
        return false;

    // Test result
    if ( fabs( d1 - 3.14159 ) > 1e-6 ) return false;


    // Convert with inline variant
    d1 = fromString<double>( str1 );

    // Re-test result
    if ( fabs( d1 - 3.14159 ) > 1e-6 ) return false;

    return true;
}

bool test_number_to_string()
{
    // Define two numeric variables
    double d1 = 3.14159;
    float  f2 = 2.71828;

    // Initialize two strings
    std::string str1, str2;

    // Convert with validity check
    if ( !toString( d1, str1 ) )
        return false;

    if ( !toString( f2, str2 ) )
        return false;

    // Test result
    if ( str1.compare( "3.14159" ) != 0 ) return false;
    if ( str2.compare( "2.71828" ) != 0 ) return false;


    // Convert with the inline variant
    str1 = toString( d1 );
    str2 = toString( f2 );

    // Re-test result
    if ( str1.compare( "3.14159" ) != 0 ) return false;
    if ( str2.compare( "2.71828" ) != 0 ) return false;

    return true;
}

bool test_sto_int()
{
    // Define string
    std::string s1 = "65536";

    // Test string to int conversion
    try {
        auto val = sto<int>( s1 );
        
        if ( val != 65536 ) return false;
    }
    catch ( std::exception& e ) { return false; }

    // Test passed
    return true;
}

bool test_sto_long()
{
    // Define string
    std::string s = "486512389742563";

    // Test string to int conversion
    try {
        auto val = sto<long>( s );
        
        if ( val != 486512389742563 ) return false;
    }
    catch ( std::exception& e ) { return false; }

    // Test passed
    return true;
}

bool test_sto_float()
{
    // Define string
    std::string s1 = "65536";
    std::string s2 = "3.14159";

    // Test string to float conversion
    try {
        auto val1 = sto<float>( s1 );
        auto val2 = sto<float>( s2 );

        if ( fabs( val1 - 65536   ) > 1e-6 ) return false;
        if ( fabs( val2 - 3.14159 ) > 1e-6 ) return false;
    }
    catch ( std::exception& e ) { return false; }

    return true;
}

bool test_sto_double()
{
    // Define string
    std::string s = "2.71828";
    
    // Test string to double conversion
    try {
        auto val = sto<double>( s );

        if ( fabs( val - 2.71828 ) > 1e-6 ) return false;
    }
    catch ( std::exception& e ) { return false; }

    return true;
}

bool test_sto_bad_value()
{
    // Define string
    std::string s3 = "hello";

    // Test bad type conversion
    try {
        auto val = sto<int>( s3 );
        if ( fabs( val - 2.71828 ) > 1e-6 ) return false;
    }
    catch ( std::invalid_argument& e) { /* continue */ }
    catch ( std::exception& e ) { 
        std::cout << e.what() << std::endl;
        return false; 
    }

    return true;
}

bool test_sto_bad_range()
{
    // Define two numeric strings 
    std::string s1 = "65536";
    std::string s2 = "3.14159";
    std::string s3 = "2.71828";
    std::string s4 = "486512389742563";

    // Test bad range conversion
    try {
        int i4 = sto<int>( s4 );
    }
    catch (std::out_of_range& e) { /* continue */ }
    catch (std::exception& e)    { 
        //std::cout << std::endl;
        //std::cout << "caught error: " << e.what() << std::endl; 
        return false; 
    }

    return true;
}


int main(int argc, const char *argv[])
{
    std::cout << " > Testing string/value conversion" << std::endl;
    std::cout << std::boolalpha;

    // Testing stream-type conversion ( pre c++11 )
    std::cout << std::endl << " > Testing string stream conversion" << std::endl;
    std::cout << "Testing [ string->number  ] ... passed: " << test_string_to_number() << std::endl;
    std::cout << "Testing [ number->string  ] ... passed: " << test_number_to_string() << std::endl;

    // Testing direct conversion ( since c++11 )
    std::cout << std::endl << " > Testing direct conversion" << std::endl;
    std::cout << "Testing [ sto< int >      ] ... passed: " << test_sto_int() << std::endl;
    std::cout << "Testing [ sto< long >     ] ... passed: " << test_sto_long() << std::endl;
    std::cout << "Testing [ sto< float >    ] ... passed: " << test_sto_float() << std::endl;
    std::cout << "Testing [ sto< double >   ] ... passed: " << test_sto_double() << std::endl;
    std::cout << "Testing [ bad value sto<> ] ... passed: " << test_sto_bad_value() << std::endl;
    std::cout << "Testing [ bad range sto<> ] ... passed: " << test_sto_bad_range() << std::endl;

    return 0;
}

