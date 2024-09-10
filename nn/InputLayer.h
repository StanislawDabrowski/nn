class InputLayer :public Layer
{
private:
	std::vector<InputNeuron*> neurons;
public:
	InputLayer(std::vector<int*> input, int number_of_neurons);
	~InputLayer();
	void set_pointers(std::vector<int*> inputs);
	void activate_neurons() override;
	int number_of_neurons() override;
	double* pointer_to_neuron_data(int i) override;
	int which_layer() override;
};