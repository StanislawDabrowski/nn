class HiddenLayer : public Layer
{
private:
	std::vector<HiddenNeuron*> neurons;
	Layer* previous_layer;
	Layer* next_layer;
	std::vector<double> input_gradients;
public:
	HiddenLayer(Layer* previous_layer, int number_of_neurons, int number_of_next_layer_neurons);
	~HiddenLayer();
	void set_pointers(std::vector<std::vector<double*>> inputs);
	void calculate_gradients();
	void activate_neurons() override;
	void update_weights(double learning_rate);
	int number_of_neurons() override;
	double* pointer_to_neuron_data(int i) override;
	void set_next_layer(Layer* next_layer);
	double neuron_gradient(int i) override;
	double neuron_weight(int i, int j) override;
	int which_layer() override;
};