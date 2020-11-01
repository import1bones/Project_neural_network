#pragma once
#include"Layer.h"
#include<string>
class Mode
{
private:
	std::vector<double> hideLayerCalculate(std::vector<double>, Layer);
	std::vector<Layer> mode;
	std::vector<double> tempForOutput;
	double lo = 0.0, hi = 1.0;
public:
	void add(Layer layer);
	void initalization();
	std::vector<double> output(std::vector<double>);
	void train(std::vector<double>);
	int input = 0;
	double learn_rate = 1e-4;
};
