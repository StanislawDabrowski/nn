#include "includes.h"



OutputLayer::OutputLayer(Layer* previous_layer, int number_of_neurons, std::vector<bool>* true_labels)
{
	this->true_labels = true_labels;
	unsigned int neurons_number = previous_layer->number_of_neurons() + number_of_neurons;
	this->previous_layer = previous_layer;
	input_gradient.resize(number_of_neurons);
	for (int i = 0; i < number_of_neurons; i++)
	{
		std::vector<double*> input;
		neurons.push_back(new OutputNeuron(input));
	}
}
void OutputLayer::set_pointers(std::vector<std::vector<double*>> inputs, std::vector<bool>* true_labels)
{
	set_true_labels_pointer(true_labels);
	for (int i = 0; i < inputs.size(); i++)
		neurons[i]->set_inputs_pointers(inputs[i]);
}
void OutputLayer::set_true_labels_pointer(std::vector<bool>* true_labels)
{
	this->true_labels = true_labels;
}
void OutputLayer::softmax()
{
	double sum = 0;
	for (int i = 0; i < previous_layer->number_of_neurons(); i++)
	{
		neurons[i]->data = exp(*previous_layer->pointer_to_neuron_data(i));
		sum += neurons[i]->data;
	}
	for (int i = 0; i < neurons.size(); i++)
		neurons[i]->data /= sum;
}
void OutputLayer::calculate_gradients()
{
	for (int i = 0; i < neurons.size(); i++)
	{
		input_gradient[i] = neurons[i]->data - true_labels->at(i);
		cout << neurons[i]->data << " - " << true_labels->at(i) << " = " << neurons[i]->data - true_labels->at(i) << endl;
	}
	cout << endl;
}
void OutputLayer::activate_neurons()
{
	softmax();
}
int OutputLayer::number_of_neurons()
{
	return neurons.size();
}
double* OutputLayer::pointer_to_neuron_data(int i)
{
	return &neurons[i]->data;
}
double OutputLayer::neuron_gradient(int i)
{
	return input_gradient[i];
}
double OutputLayer::neuron_weight(int i, int j)
{
	return 1;
}
int OutputLayer::which_layer()
{
	return 3;
}