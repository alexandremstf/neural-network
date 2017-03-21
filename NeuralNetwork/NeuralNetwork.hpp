#ifndef NEURALNETWORK_HPP_
#define NEURALNETWORK_HPP_

#include "Header.hpp"

class NeuralNetwork {

private:
	int input_layer_size;
	int output_layer_size;
	int hidden_layer_size;

	vector<vector<double>> input;
	vector<vector<double>> output;
	vector<vector<double>> weight_input;
	vector<vector<double>> weight_output;
	
	double learning_rate;

	int max_epoch;
	int percentage;
	double limit_error;
	double hit_percent;

	int epoch = 0;
	int cont = 0;
	
public:
	NeuralNetwork(int, int);
	NeuralNetwork(int, int, int);

	void trainingDataset();
	void testingDataset(vector<vector<double>>);
	void initializeWeight();

	double sigmoid(double);	
	double sigmoidPrime(double);

	void setInput(vector<vector<double>>);
	void setOutput(vector<vector<double>>);
};

#endif