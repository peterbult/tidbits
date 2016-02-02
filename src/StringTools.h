//
// StringTools.h
// Tidbits
//
// Created by PM Bult on 16-12-2013
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#pragma once
#include <vector>
#include <sstream>

namespace {
    std::pair<std::string,std::string> splitExtension( std::string filename )
    {
        // (Reverse) Find the position of the dot
        size_t pos_dot = filename.find_last_of('.');

        // If no dot is found: return an empty extension
        if (pos_dot == std::string::npos)
            return std::make_pair( filename, std::string() );

        // Otherwise split the string on the dot
        std::string basename    = filename.substr(0, pos_dot);
        std::string extension   = filename.substr(pos_dot);

        // And return as pair
        return std::make_pair( basename, extension );
    }

    int string_case_insensitive_compare( std::string s1, std::string s2 )
    {
        // Test on size first (to prevent needless case conversion)
        if ( s1.size() != s2.size() ) return s1.size() - s2.size();

        // Convert both strings to lower case
        std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

        // Run regular string compare
        return s1.compare(s2);
    }

    //std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    // Generic base split function with output argument
    void split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        //return elems;
    }

    // Specialized split function with return output
    std::vector<std::string> split(const std::string &s, char delim = ' ') {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }

}
