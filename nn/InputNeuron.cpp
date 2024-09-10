#include "includes.h"

InputNeuron::InputNeuron(int* input)
	:Neuron()
{
	this->input = input;
}
void InputNeuron::set_input_pointer(int* input)
{
	this->input = input;
}
void InputNeuron::activate_neuron()
{
	data = *input;
}