#include "includes.h"



OutputNeuron::OutputNeuron(std::vector<double*> input)
	:Neuron()
{
	this->inputs = input;
}
void OutputNeuron::set_inputs_pointers(std::vector<double*>)
{
	this->inputs = inputs;
}