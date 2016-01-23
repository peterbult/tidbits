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

#include "../../src/Segmenter.h"


bool test_segmenter()
{
    std::cout << std::endl;

    // Define a vector
    std::vector<double> vec(20);

    // Fill the vector
    for ( int i = 0; i < vec.size(); ++i ) vec[i] = i+1;

    // Segment the vector in 5 pieces of equal length
    for ( auto &segment : Segmenter( vec, 5 ) ) {

        std::cout << "Segment #x" << std::endl;

        for (int i = 0; i < segment.size(); ++i) {
            std::cout << segment[i] << std::endl;
        }
    }

    std::cout << std::endl;
    
    // All tests passed
    return true;
}

bool test_value_segmenter() 
{
    std::cout << std::endl;

    // Define a vector
    std::vector<double> vec(20);

    // Fill the vector
    for ( int i = 0; i < vec.size(); ++i ) vec[i] = 3+0.1*i;

    // Segment the vector in pieces that span a VALUE of 0.45 
    for ( auto &segment : SegmenterValue( vec, 0.45 ) ) {

        std::cout << "Segment #x" << std::endl;
        
        for (int i = 0; i < segment.size(); ++i) {
            std::cout << segment[i] << std::endl;
        }
    }
    
    std::cout << std::endl;

    // All tests passed
    return true;    
}

int main(int argc, const char *argv[])
{
    std::cout << " > Testing Segmenter" << std::endl;
    std::cout << std::boolalpha << std::endl;

    // Test assert function
    std::cout << "Testing [    segmenter()    ] ... passed: " << test_segmenter() << std::endl;

    // Test assert function
    std::cout << "Testing [ value_segmenter() ] ... passed: " << test_value_segmenter() << std::endl;

    
    return 0;
}

