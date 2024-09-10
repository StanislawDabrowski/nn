class InputNeuron :public Neuron
{
private:
	int* input;
public:
	InputNeuron(int* input);
	void set_input_pointer(int* input);
	void activate_neuron() override;
};