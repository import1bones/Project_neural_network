#include "Mode.h"
using std::vector;

vector<double> Mode::hideLayerCalculate(vector<double> inputData, Layer layer)
{
	if (layer.weight[0].size() == 0)
	{
		throw(__FILE__, __LINE__,
			"ERROR: mode is not initalization");
	}
	if (inputData.size() != layer.weight[0].size())
	{
		throw(__FILE__, __LINE__,
			"ERROR: inputData's size is not equal with layer");
	}
	vector<double> outputData(layer.weight.size());
	for (int i = 0; i < layer.weight.size(); ++i)
	{
		for (int j = 0; j < inputData.size(); ++j)
		{
			outputData[i] += (inputData[j] * layer.weight[i][j]);
		}
		outputData[i] += layer.bias[i];
	}
	for (int i = 0; i < outputData.size(); ++i)
	{
		outputData[i] = layer.activation(outputData[i]);
	}
	return outputData;
}

void Mode::add(Layer layer)
{
	mode.push_back(layer);
	srand(static_cast<unsigned int>(time(NULL)));
}

void Mode::initalization()
{
	int inputSize = input;
	for (auto& x : mode)
	{
		for (auto& w : x.weight)
		{
			w.resize(inputSize);
			for (auto& nums : w)
			{
				nums = (lo + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (hi - lo))));
			}
			random_shuffle(w.begin(), w.end());
		}
		random_shuffle(x.weight.begin(), x.weight.end());
		for (auto& nums : x.bias)
		{
			nums = (-10.0 + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (10.0 - (-10.0)))));
		}
		random_shuffle(x.bias.begin(), x.bias.end());
		inputSize = x.weight.size();
	}
}

std::vector<double> Mode::output(std::vector<double> inputData)
{
	if (mode.size() == 0)
	{
		throw(__FILE__ , __LINE__ ,
			"ERROR: mode is not initalization");
	}
	if (mode[0].weight[0].size() != input)
	{
		throw(__FILE__, __LINE__,
			"ERROR: inputData's size is not equal with mode's input");
	}
	tempForOutput = hideLayerCalculate(inputData, mode[0]);
	for (int i = 1; i < mode.size(); ++i)
	{
		tempForOutput= hideLayerCalculate(tempForOutput, mode[i]);
	}
	return tempForOutput;
}

void Mode::train(std::vector<double> loss)
{
	if (mode.size() == 0)
	{
		throw(__FILE__, __LINE__,
			"ERROR: mode is not initalization");
	}
	if (loss.size() != mode.back().weight.size())
	{
		throw(__FILE__, __LINE__, 
			"ERROR: loss's size is not equal with output's size");
	}
}
