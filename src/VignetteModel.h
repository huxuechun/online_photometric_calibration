//
//  VignetteModel.h
//  OnlineCalibration
//
//  Created by Paul on 16.11.17.
//  Copyright (c) 2017 Paul Bergmann. All rights reserved.
//
//  Commented
//

#ifndef __OnlineCalibration__VignetteModel__
#define __OnlineCalibration__VignetteModel__

#include "StandardIncludes.h"

#include "math.h"

/**
 * Stores vignetting model parameters and provides functionality to 
 * apply / remove vignetting
 */

class VignetteModel
{
    
public:
    
    /**
     * Initialize vignette model
     * @param v1,v2,v3 parameters of polynomial vignetting model v(r) = 1 + v1*r^2 + v2*r^4 + v3*r^6
     * @param image_width,image_height dimensions of the input images
     */
    VignetteModel(double v1,double v2,double v3,int image_width,int image_height);
    
    /**
     * Calculate a radius value between [0,1] for a given point location
     */
    double getNormalizedRadius(cv::Point2f xy_location);
    
    /**
     * Calculate vignette factor for a given point location based on the current vignette estimate
     */
    double getVignetteFactor(cv::Point2f xy_location);
    
    /**
     * Calculate vignette factor for a given normalize radius based on the current vignette estimate
     */
    double getVignetteFactor(double norm_radius);
    
    /**
     * Return current vignette estimate parameter vector
     */
    std::vector<double> getVignetteEstimate()
    {
        std::vector<double> result;
        result.push_back(m_v1);
        result.push_back(m_v2);
        result.push_back(m_v3);
        return result;
    }
    
    /**
     * Overwrite vignette estimate parameters
     */
    void setVignetteParameters(std::vector<double> vignette_model);
    
private:
    
    /**
     * Parameter values of the vignette model
     */
    double m_v1;
    double m_v2;
    double m_v3;
    
    /**
     * Input image dimensions
     */
    int m_image_width;
    int m_image_height;
    
    /**
     * Maximum pixel radius in image coordinates (used for normalization of radius to [0,1])
     */
    double m_max_radius;
};

#endif /* defined(__OnlineCalibration__VignetteModel__) */