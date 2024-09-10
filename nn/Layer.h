class Layer
{
public:
	virtual void activate_neurons();
	virtual int number_of_neurons();
	virtual double* pointer_to_neuron_data(int i);
	virtual double neuron_gradient(int i);
	virtual double neuron_weight(int i, int j);
	virtual int which_layer();
};