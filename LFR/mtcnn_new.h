#ifndef MTCNN
#define MTCNN
#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "include/ncnn/net.h"

struct Bbox
{
	float score;
	int x1;
	int y1;
	int x2;
	int y2;
	float area;
	bool exist;
	float ppoint[10];
	float regreCoord[4];
};

struct orderScore
{
	float score;
	int oriOrder;
};

//класс, отвечающий за распознавание с использованием NCNN
class mtcnn
{
public:
	mtcnn();
	void detect(ncnn::Mat& img_, std::vector<Bbox>& finalBbox);
private:
	void generateBbox(ncnn::Mat score, ncnn::Mat location, std::vector<Bbox>& boundingBox_, std::vector<orderScore>& bboxScore_, float scale);
	void nms(std::vector<Bbox> &boundingBox_, std::vector<orderScore> &bboxScore_, const float overlap_threshold, std::string modelname="Union");
	void refineAndSquareBbox(std::vector<Bbox> &vecBbox, const int &height, const int &width);

	ncnn::Net Pnet, Rnet, Onet;
	ncnn::Mat img;

	const float nms_threshold[3] = {0.5, 0.7, 0.7};
	const float threshold[3] = {0.6, 0.6, 0.6};
	const float mean_vals[3] = {127.5, 127.5, 127.5};
	const float norm_vals[3] = {0.0078125, 0.0078125, 0.0078125};
	std::vector<Bbox> firstBbox_, secondBbox_,thirdBbox_;
	std::vector<orderScore> firstOrderScore_, secondBboxScore_, thirdBboxScore_;
	int img_w, img_h;
};
#endif //MTCNN
