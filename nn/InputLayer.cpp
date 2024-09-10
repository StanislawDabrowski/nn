#include "includes.h"


InputLayer::InputLayer(std::vector<int*> input, int number_of_neurons)
{
	for (int i = 0; i < number_of_neurons; i++)
	{
		neurons.push_back(new InputNeuron(input[i]));
	}
}
InputLayer::~InputLayer()
{
	for (int i = 0; i < neurons.size(); i++)
	{
		delete neurons[i];
	}
}
void InputLayer::set_pointers(std::vector<int*> inputs)
{
	for (int i = 0; i < inputs.size(); i++)
		neurons[i]->set_input_pointer(inputs[i]);
}
void InputLayer::activate_neurons()
{
	for (int i = 0; i < neurons.size(); i++)
	{
		neurons[i]->activate_neuron();
	}
}
int InputLayer::number_of_neurons()
{
	return neurons.size();
}
double* InputLayer::pointer_to_neuron_data(int i)
{
	return &neurons[i]->data;
}
int InputLayer::which_layer()
{
	return 1;
}