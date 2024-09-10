class NeuralNetwork
{
public:
	InputLayer* input_layer;
	std::vector<HiddenLayer*> hidden_layers;
	OutputLayer* output_layer;
	double learning_rate;
	NeuralNetwork(unsigned int number_of_input_neurons, std::vector<unsigned int> number_of_hidden_neurons, unsigned int number_of_output_neurons, std::vector<int*> input, std::vector<bool>* true_labels, double learning_rate);
	~NeuralNetwork();
	void set_ponters(std::vector<int*> input_inputs, std::vector<std::vector<double*>> hidden_inputs, std::vector<std::vector<double*>> output_inputs, std::vector<bool>* true_labels);
	void back_propagation();
	void forward_propagation();
	void calculate_gradients();
	void update_weights();
};