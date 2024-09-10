class HiddenNeuron :public Neuron
{
public:
	double bias;
	std::vector<double*> inputs;
	std::vector<double> weights;
	double weighted_sum;
	HiddenNeuron(std::vector<double*> inputs, std::vector<double> weights, double bias);
	void set_inputs_poiners(std::vector<double*> inputs);
	void activate_neuron() override;
};