#pragma once
#include<random>
#include<time.h>
#include<vector>
class Layer
{
private:
	
public:
	double (*activation)(double);
	Layer(int number, double (*activation)(double));
	std::vector<std::vector<double>> weight;
	std::vector<double> bias;
};

