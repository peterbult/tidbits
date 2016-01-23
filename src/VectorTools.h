// 
// VectorTools.h
// Tidbits
//
// Created by PM Bult on 16-12-2013
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#pragma once
#include <numeric>
#include <cmath>

namespace vectool {
    //
    // Sum elements of a (numeric) vector
    //
    template <typename it_type>
        typename std::iterator_traits<it_type>::value_type
        sum( it_type first, it_type last)
        {
            return std::accumulate( first+1, last, *first );
        }

    template <typename vec_type>
        typename vec_type::value_type
        sum( vec_type& vec )
        {
            return sum( std::begin(vec), std::end(vec) );
        }
    


    //
    // Average elements of a (numeric) vector
    //
    template <typename it_type> 
        typename std::iterator_traits<it_type>::value_type
        average( it_type first, it_type last)
    {
        return sum(first, last) / std::distance( first, last );
    }

    template <typename vec_type>
        typename vec_type::value_type
        average( vec_type& vec )
    {
        return average( std::begin(vec), std::end(vec) );
    }



    // 
    // Compute standard deviation of a (numeric) vector
    //
    template <typename it_type> 
        typename std::iterator_traits<it_type>::value_type
        stddev( it_type first, it_type last)
    {
        double avg = average( first, last );
        double var = std::accumulate( first, last, 0.0, 
                [&](const double &r, double v) { return r+(v-avg)*(v-avg); }
                ) / std::distance( first, last );
        return sqrt( var );
    }

    template <typename vec_type>
        typename vec_type::value_type
        stddev( vec_type& vec )
    {
        return stddev( std::begin(vec), std::end(vec) );
    }

}

