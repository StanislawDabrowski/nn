class OutputLayer :public Layer
{
private:
	std::vector<OutputNeuron*> neurons;
	Layer* previous_layer;
	std::vector<double> input_gradient;
	std::vector<bool>* true_labels;
public:
	OutputLayer(Layer* previous_layer, int number_of_neurons, std::vector<bool>* true_labels);
	void set_pointers(std::vector<std::vector<double*>> inputs, std::vector<bool>* true_labels);
	void set_true_labels_pointer(std::vector<bool>* true_labels);
	void softmax();
	void calculate_gradients();
	void activate_neurons() override;
	int number_of_neurons() override;
	double* pointer_to_neuron_data(int i) override;
	double neuron_gradient(int i) override;
	double neuron_weight(int i, int j) override;
	int which_layer() override;
};