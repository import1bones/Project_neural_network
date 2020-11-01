#include "Layer.h"

Layer::Layer(int number, double(*activation)(double))
{
	this->activation = activation;
	weight.resize(number);
	bias.resize(number);
}
