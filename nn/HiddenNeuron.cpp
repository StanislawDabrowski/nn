#include "includes.h"



HiddenNeuron::HiddenNeuron(std::vector<double*> inputs, std::vector<double> weights, double bias)
	:Neuron()
{
	this->inputs = inputs;
	this->weights = weights;
	this->bias = bias;
	this->weighted_sum = 0;
}
void HiddenNeuron::set_inputs_poiners(std::vector<double*> inputs)
{
	this->inputs = inputs;
}
void HiddenNeuron::activate_neuron()
{
	//ReLU
	double sum = bias;
	for (int i = 0; i < inputs.size(); i++)
		sum += *inputs[i] * weights[i];
	weighted_sum = sum;
	if (sum > 0)
		data = sum;
	else
		data = 0;
}