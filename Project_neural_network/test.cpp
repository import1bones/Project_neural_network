#include"Layer.h"
#include"Activation.h"
#include"Mode.h"
#include<iostream>
#include<string>
using std::string;
int main()
{
	Mode testMode;
	testMode.input = 10;
	testMode.learn_rate = 1e-6;
	std::vector<double> out;
	try
	{
		testMode.add(Layer(64, Activation::relu));
		testMode.add(Layer(32, Activation::relu));
		testMode.add(Layer(8, Activation::relu));
		testMode.add(Layer(2, Activation::relu));
		testMode.initalization();
		out = testMode.output({ 10,9,8,7,6,5,4,3,2,1 });
	}
	catch (string msg)
	{
		std::cout << msg << std::endl;
	}
	std::cout << out[0] << " " << out[1] << std::endl;
	return 0;
}	