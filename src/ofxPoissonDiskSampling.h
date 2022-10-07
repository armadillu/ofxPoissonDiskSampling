#ifndef OFXPOISSONDISKSAMPLING_H
#define OFXPOISSONDISKSAMPLING_H

#include "ofMain.h"

class ofxPoissonDiskSampling
{
public:
    /// samples points within the  range (0,w) with minimum distance `density / 2`
    // if `borders` is true, there are additional points at 0 and w. These are the last two points in the resulting vector.
    static vector<float> sample1D(float w, float density, bool borders = false);

    /// samples points within the box [(0,0), (w,h)] with minimum distance `density / 2`
    /// if `borders` is true, there are additional samples exactly on the boundary of the box
    /// in that case, the index of the first border pt in the result vector is written to `bordersStart`, unless it is NULL
	static vector<ofVec2f> sample2D(float w, float h, float density, bool borders = false,
									int *bordersStart = NULL, size_t seed = 0, int attempts = 30,
									function<float(std::vector<unsigned > &)> pixelValEval = [](std::vector<unsigned > &){return 1.0;}
									);

    /// samples points within the box [(0,0,0), (w,h,d)] with minimum distance `density / 2`
    /// if `borders` is true, there are additional samples exactly on the boundary of the box
    /// in that case, the index of the first border pt is written to `bordersStart`, unless it is NULL
    static vector<ofVec3f> sample3D(float w, float h, float d, float density, bool borders = false, int *bordersStart = NULL);

public:
    ofxPoissonDiskSampling() { ; }
    virtual ~ofxPoissonDiskSampling() { ; }
};

#endif // OFXPOISSONDISKSAMPLING_H
