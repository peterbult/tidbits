//
// main.cpp
// Test String tools
//
// Created by PM Bult on 23-01-2016
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#include <iostream>

#include "../../src/StringTools.h"


bool test_split_extension()
{
    // Define a string
    std::string path = "this/is/a.file.dat";

    // Split the string on the file extension
    auto split = splitExtension( path );

    // Test results
    if ( split.first.compare("this/is/a.file") != 0 ) return false;
    if ( split.second.compare(".dat")          != 0 ) return false;

    // All tests passed
    return true;
}

bool test_bad_split_extension()
{
    // Define a string
    std::string path = "this/is/a/dotless-file";

    // Split the string on the file extension
    auto split = splitExtension( path );

    // Test results
    if ( split.first.compare("this/is/a/dotless-file") != 0    ) return false;
    if ( split.second.empty()                          != true ) return false;

    // All tests passed
    return true;
}

bool test_case_insensitive_compare()
{
    // Define a string
    std::string str = "DataFile";

    // Split the string on the file extension
    int r1 = string_case_insensitive_compare( str, "data" );
    int r2 = string_case_insensitive_compare( str, "datafile" );
    int r3 = string_case_insensitive_compare( str, "DataFile" );
    int r4 = string_case_insensitive_compare( str, "DataFileSystem" );

    // Test results
    if ( r1 <= 0 ) return false;
    if ( r2 != 0 ) return false;
    if ( r3 != 0 ) return false;
    if ( r4 >= 0 ) return false;

    // All tests passed
    return true;
}

bool test_split()
{
    // Define a string
    std::string str = "this/is/a/file/path.dat";

    // Split the file path
    auto path = split(str, '/');

    // Test result size
    if ( path.size() != 5 ) return false;

    // Test result elements
    if ( path[0].compare("this")     != 0 ) return false;
    if ( path[1].compare("is")       != 0 ) return false;
    if ( path[2].compare("a")        != 0 ) return false;
    if ( path[3].compare("file")     != 0 ) return false;
    if ( path[4].compare("path.dat") != 0 ) return false;

    // All tests passed
    return true;
}



int main(int argc, const char *argv[])
{
    std::cout << " > Testing string tools" << std::endl;
    std::cout << std::boolalpha << std::endl;

    // Test assert function
    std::cout << "Testing [          split()           ] ... passed: " << test_split() << std::endl;

    // Test  split extension
    std::cout << "Testing [      splitExtension()      ] ... passed: " << test_split_extension() << std::endl;

    // Test  split extension
    std::cout << "Testing [    bad splitExtension()    ] ... passed: " << test_bad_split_extension() << std::endl;

    // Test assert function
    std::cout << "Testing [ case_insensitive_compare() ] ... passed: " << test_case_insensitive_compare() << std::endl;

    return 0;
}
