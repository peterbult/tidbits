// 
// Segmenter.h
// Vector Segmenter
//
// Created by PM Bult on 03-06-2015
// Copyright (c) P.M. Bult. All rights reserved.
//
// Version 1.0
//

#pragma once
#include <vector>
#include <algorithm>

// 
// VectorBlock class
//
// A VectorBlock is a low level container for
// an iterator pair. This pair points to a start-
// and end-point in a vector.
//
class VectorBlock {
    public:
        VectorBlock( 
                std::vector<double>::iterator begin, 
                std::vector<double>::iterator end )
            : mBegin(begin), mEnd(end) { }
        
        std::vector<double>::iterator& begin() { return mBegin; }
        std::vector<double>::iterator& end()   { return mEnd;   }
        
        double& operator[](int x) { return *(mBegin+x); };

        unsigned size() { return std::distance( mBegin, mEnd ); }

    private:
        std::vector<double>::iterator mBegin;
        std::vector<double>::iterator mEnd;
};

// Default segmenter: based on number of segments
class Segmenter {
    public:
        Segmenter() { }
        Segmenter( std::vector<double>&, int );
        virtual ~Segmenter() { }

        std::vector<VectorBlock>::iterator begin() { return mData.begin(); }
        std::vector<VectorBlock>::iterator end() { return mData.end(); }

        VectorBlock& operator[](int x) { return mData[x]; }

        unsigned size() { return mData.size(); }

    protected:
        std::vector<VectorBlock> mData;
};

Segmenter::Segmenter( std::vector<double>& vec, int segments )
{
    if ( segments < 1 ) throw "error: Segmenter: invalid number of segments";
    if ( segments == 1 ) {
        mData.emplace_back( vec.begin(), vec.end() );
    } else {
        int segment_size = vec.size() / segments;
        for (int i = 0; i < segments; ++i) {
            mData.emplace_back( 
                    vec.begin()+i*segment_size, 
                    vec.begin()+i*segment_size+segment_size );
        }
    }
    return;
}


// Segmenter based on a fixed segment size
class SegmenterFixed : public Segmenter {
    public:
        SegmenterFixed( std::vector<double>&, int );
};

SegmenterFixed::SegmenterFixed( std::vector<double> &vec, int segment_size )
{
    if ( segment_size < 1 ) throw "error: SegmenterFixed: invalid segment size";
    if ( segment_size >= vec.size() ) {
        return; // empty segmenter
    } else {
        int segments = vec.size() / segment_size;
        for (int i = 0; i < segments; ++i) {
            mData.emplace_back( 
                    vec.begin()+i*segment_size, 
                    vec.begin()+i*segment_size+segment_size );
        }
    }
    return;
}


// Segmenter based on dynamic value
class SegmenterDynamic : public Segmenter {
    public:
        SegmenterDynamic( std::vector<double>&, double );
};

SegmenterDynamic::SegmenterDynamic( std::vector<double>& vec, double duration )
{
    if ( vec.size() < 1 ) throw "error: SegmenterDynamic: invalid segment size";

    // Adjust duration
    int num = (vec.back() - vec.front() ) / duration;
    if ( num == 0 ) num += 1;
    double adjusted = (vec.back() - vec.front()) / double(num);

    // Segment
    double ul = vec.front() + adjusted;
    std::vector<double>::iterator it1, it2;
    it1 = vec.begin();
    for (int i = 0; i < vec.size(); ++i) {
        if ( vec[i] > ul ) {
            it2 = vec.begin() + i;
            mData.emplace_back( it1, it2 );
            it1 = it2+1;
            ul += adjusted;
        }
    }

    // Add the trailing block if needed
    it2 = vec.end();
    if ( std::distance(it1,it2) > 0.5*adjusted)
        mData.emplace_back( it1, it2 );
}

// Segmenter based on value
class SegmenterValue : public Segmenter {
    public:
        SegmenterValue( std::vector<double>&, double );
};

SegmenterValue::SegmenterValue( std::vector<double>& vec, double duration )
{
    if ( vec.size() < 1 ) throw "error: SegmenterValue: invalid segment size";
    if ( vec.back() - vec.front() < duration ) 
        return; // empty segmenter
    else {
        double ul = vec.front() + duration;
        std::vector<double>::iterator it1, it2;
        it1 = vec.begin();
        for (int i = 0; i < vec.size(); ++i) {
            if ( vec[i] > ul ) {
                it2 = vec.begin() + i;
                mData.emplace_back( it1, it2 );
                it1 = it2+1;
                ul += duration;
            }
        }
    }
}

