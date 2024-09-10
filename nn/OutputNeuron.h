class OutputNeuron :public Neuron
{
private:
	std::vector<double*> inputs;
public:
	OutputNeuron(std::vector<double*> input);
	void set_inputs_pointers(std::vector<double*>);
};