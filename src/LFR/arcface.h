#ifndef ARCFACE_H
#define ARCFACE_H

#include <cmath>
#include <vector>
#include <string>
#include "include/ncnn/net.h"
#include <opencv2/highgui.hpp>

//Расчет схожести данных о лицах
float calcSimilar(std::vector<float> feature1, std::vector<float> feature2);

class Arcface
{

public:
	Arcface();
    ~Arcface();
    cv::Mat getFeature(cv::Mat img);

private:
    ncnn::Net net;

    const int feature_dim = 128;

	void normalize(std::vector<float> &feature);
};

#endif
