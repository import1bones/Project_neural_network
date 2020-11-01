#include "Activation.h"

double Activation::relu(double input)
{
    if (input - 0.0 < 1e-13)
    {
        return 0.0;
    }
    else
    {
        return input;
    }
}

double Activation::tanh(double input)
{
    double ez = powl(expl(1), input);
    double emz = powl(expl(1), -1 * input);
    return (ez - emz) / (ez + emz);
}

double Activation::sigmoid(double input)
{
    return 1.0 / (expl(-1.0 * input) + 1);
}
