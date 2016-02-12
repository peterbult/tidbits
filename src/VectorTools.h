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

    

    // 
    // Compute r-th central moment of a (numeric) vector
    //
    template <typename it_type> 
        typename std::iterator_traits<it_type>::value_type
        central_moment( it_type first, it_type last, int rank )
    {
        // Safeguard: Check if rank is valid
        if ( rank < 0 ) throw std::invalid_argument("rank " + std::to_string(rank) + " < 0");
        // Shortcut return
        if ( rank == 0 ) return 1.0;
        // Compute average
        double avg = average( first, last );
        // Shortcut return
        if ( rank == 1 ) return avg;
        // Compute the rank > 1 central moment
        double mom = std::accumulate( first, last, 0.0, 
                [&](const double &r, double v) { return r+pow( v-avg, rank ); }
                ) / std::distance( first, last );
        // Return product
        return mom;
    }

    template <typename vec_type>
        typename vec_type::value_type
        central_moment( vec_type& vec, double rank )
    {
        return central_moment( std::begin(vec), std::end(vec), rank );
    }
    


    // 
    // Compute the skewness from its stat definition ( m3 / m2^(3/2) )
    //
    template <typename it_type> 
        typename std::iterator_traits<it_type>::value_type
        skewness( it_type first, it_type last )
    {
        double m3 = central_moment( first, last, 3 );
        double m2 = central_moment( first, last, 2 );

        return m3 / pow( m2, 1.5 );
    }

    template <typename vec_type>
        typename vec_type::value_type
        skewness( vec_type& vec )
    {
        return skewness( std::begin(vec), std::end(vec) );
    }
}

