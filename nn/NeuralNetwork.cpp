#include "includes.h"



NeuralNetwork::NeuralNetwork(unsigned int number_of_input_neurons, std::vector<unsigned int> number_of_hidden_neurons, unsigned int number_of_output_neurons, std::vector<int*> input, std::vector<bool>* true_labels, double learning_rate)
{
	//this->true_labels = true_labels;
	this->learning_rate = learning_rate;
	input_layer = new InputLayer(input, number_of_input_neurons);
	if (number_of_hidden_neurons.size() > 1)
		hidden_layers.push_back(new HiddenLayer(input_layer, number_of_hidden_neurons[0], number_of_hidden_neurons[1]));
	else
		hidden_layers.push_back(new HiddenLayer(input_layer, number_of_hidden_neurons[0], number_of_output_neurons));
	for (int i = 1; i < number_of_hidden_neurons.size(); i++)
	{
		if (i < number_of_hidden_neurons.size() - 1)
			hidden_layers.push_back(new HiddenLayer(hidden_layers[i - 1], number_of_hidden_neurons[i], number_of_hidden_neurons[i + 1]));
		else
			hidden_layers.push_back(new HiddenLayer(hidden_layers[i - 1], number_of_hidden_neurons[i], number_of_output_neurons));
	}
	for (int i = 0; i < hidden_layers.size() - 1; i++)
	{
		hidden_layers[i]->set_next_layer(hidden_layers[i + 1]);
	}
	output_layer = new OutputLayer(hidden_layers.back(), number_of_output_neurons, true_labels);
	hidden_layers[hidden_layers.size() - 1]->set_next_layer(output_layer);
}
NeuralNetwork::~NeuralNetwork()
{
	delete input_layer;
	delete output_layer;
	for (int i = 0; i < hidden_layers.size(); i++)
		delete hidden_layers[i];
}
void NeuralNetwork::set_ponters(std::vector<int*> input_inputs, std::vector<std::vector<double*>> hidden_inputs, std::vector<std::vector<double*>> output_inputs, std::vector<bool>* true_labels)
{
	input_layer->set_pointers(input_inputs);
	for (int i = 0; i < hidden_layers.size(); i++)
		hidden_layers[i]->set_pointers(hidden_inputs);
	output_layer->set_pointers(output_inputs, true_labels);
}
void NeuralNetwork::back_propagation()
{
	calculate_gradients();
	update_weights();
}
void NeuralNetwork::forward_propagation()
{
	input_layer->activate_neurons();
	for (int i = 0; i < hidden_layers.size(); i++)
		hidden_layers[i]->activate_neurons();
	output_layer->activate_neurons();
}
void NeuralNetwork::calculate_gradients()
{
	output_layer->calculate_gradients();
	for (int i = hidden_layers.size() - 1; i >= 0; i--)
	{
		hidden_layers[i]->calculate_gradients();
	}
}
void NeuralNetwork::update_weights()
{
	for (int i = 0; i < hidden_layers.size(); i++)
		hidden_layers[i]->update_weights(learning_rate);
}

int maint()
{


	return 0;
}