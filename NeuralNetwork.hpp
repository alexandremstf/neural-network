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

	int max_epoch;
	int correct_output;
	int hit_percent;
	double desired_percent;
	double learning_rate;
	double error_tolerance;
		
public:
	NeuralNetwork(vector<vector<double>>, vector<vector<double>>, int);
	NeuralNetwork(vector<vector<double>>, vector<vector<double>>, int, int, int, double, double);


	void trainingNeuralNetwork();
	void automaticTrainingNeuralNetwork();
	void testingDataset(vector<vector<double>>);
	void initializeWeight();
	void hitRate(vector<double>, unsigned int);

	double sigmoid(double);	
	double sigmoidPrime(double);

	void setInput(vector<vector<double>>);
	void setOutput(vector<vector<double>>);
};

#endif