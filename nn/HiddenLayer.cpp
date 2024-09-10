#include "includes.h"



HiddenLayer::HiddenLayer(Layer* previous_layer, int number_of_neurons, int number_of_next_layer_neurons)
{
	this->previous_layer = previous_layer;
	this->next_layer = nullptr;
	input_gradients.resize(number_of_neurons);
	int previous_layer_size = previous_layer->number_of_neurons();
	int neurons_number = previous_layer_size + number_of_neurons;
	for (int i = 0; i < number_of_neurons; i++)
	{
		std::vector<double*> input;
		std::vector<double> wagi;
		for (int j = 0; j < previous_layer_size; j++)
		{
			input.push_back(previous_layer->pointer_to_neuron_data(j));
			wagi.push_back(static_cast<double>(static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) - 0.5);
			cout << wagi[j] << " ";
		}
		neurons.push_back(new HiddenNeuron(input, wagi, static_cast<double>(rand()) / RAND_MAX - 0.5));
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
HiddenLayer::~HiddenLayer()
{
	for (int i = 0; i < neurons.size(); i++)
	{
		delete neurons[i];
	}
}
void HiddenLayer::set_pointers(std::vector<std::vector<double*>> inputs)
{
	for (int i = 0; i < inputs.size(); i++)
		neurons[i]->set_inputs_poiners(inputs[i]);
}
void HiddenLayer::calculate_gradients()
{
	for (int i = 0; i < neurons.size(); i++)
	{
		if (neurons[i]->weighted_sum > 0)
		{
			double sum = 0;
			for (int j = 0; j < next_layer->number_of_neurons(); j++)
			{
				sum += next_layer->neuron_gradient(j) * next_layer->neuron_weight(j, i);
			}
			input_gradients[i] = sum;
		}
		else
			input_gradients[i] = 0;
	}
}
void HiddenLayer::activate_neurons()
{
	for (int i = 0; i < neurons.size(); i++)
	{
		neurons[i]->activate_neuron();
	}
}
void HiddenLayer::update_weights(double learning_rate)
{
	for (int i = 0; i < neurons.size(); i++)
	{
		for (int j = 0; j < neurons[i]->weights.size(); j++)
			neurons[i]->weights[j] += learning_rate * input_gradients[i] * *neurons[i]->inputs[j];
	}
}
int HiddenLayer::number_of_neurons()
{
	return neurons.size();
}
double* HiddenLayer::pointer_to_neuron_data(int i)
{
	return &neurons[i]->data;
}
void HiddenLayer::set_next_layer(Layer* next_layer)
{
	this->next_layer = next_layer;
}
double HiddenLayer::neuron_gradient(int i)
{
	return input_gradients[i];
}
double HiddenLayer::neuron_weight(int i, int j)
{
	return neurons[i]->weights[j];
}
int HiddenLayer::which_layer()
{
	return 2;
}

