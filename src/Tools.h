// 
// Tools.h
// Tidbits
//
// Created by PM Bult on 16-12-2013
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#pragma once
#include <numeric>
#include <vector>
#include <cmath>

namespace {
    inline bool isPowerOf2( unsigned int x )
    {
        return ((x != 0) && !(x & (x - 1)));
    }
    
    inline void assertPowerOf2( unsigned int x )
    {
        if ( isPowerOf2( x ) )  // True
            return; 
        else                    // False
            throw "error: value is not a power of 2";
    }
}

namespace CT {
    //template <class T> T sum(typename std::vector<T>& c)
    //{
        //return CT::sum( begin(c), end(c) );
    //}
    template <class T> T sum(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last)
    {
        return std::accumulate( first+1, last, *first );
    }
    template <class T> T average(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last )
    {
        return sum<double>(first, last) / std::distance( first, last );
    }
    template <class T> T stddev(typename std::vector<T>::iterator first, typename std::vector<T>::iterator last )
    {
        double avg = average<double>( first, last );
        double var = std::accumulate( first, last, 0.0, 
                [&](const double &r, double v) { return r+(v-avg)*(v-avg); }
                ) / std::distance( first, last );
        return sqrt( var );
        //return sum<double>(first, last) / std::distance( first, last );
    }

}

