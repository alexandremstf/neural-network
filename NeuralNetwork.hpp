#ifndef NEURALNETWORK_HPP_
#define NEURALNETWORK_HPP_

#include "Header.hpp"

class NeuralNetwork {

struct network {
	int epoch = 0;
	int hidden_layer = 0;
	double learning_rate = 0;
	vector<vector<double>> weight_input;
	vector<vector<double>> weight_output;
} ;

private:

vector<vector<double>> neural_test;


	int input_layer_size;
	int output_layer_size;
	int hidden_layer_size;

	vector<vector<double>> input;
	vector<vector<double>> output;
	vector<vector<double>> weight_input;
	vector<vector<double>> weight_output;

	network best_network;

	int epoch;
	int max_epoch;

	int correct_output;
	int hit_percent;

	double desired_percent;
	double learning_rate;
	double error_tolerance;
		
public:
	NeuralNetwork();
	NeuralNetwork(vector<vector<double>>, vector<vector<double>>);

	void trainingNeuralNetwork();
	void autoTrainingNeuralNetwork(int, double);
	void initializeWeight();
	void hitPercent(vector<double>, unsigned int);
	
	vector<vector<double>> runNeuralNetwork(vector<vector<double>>);

	double sigmoid(double);	
	double sigmoidPrime(double);

	void setInput(vector<vector<double>>);
	void setOutput(vector<vector<double>>);
	void setMaxEpoch(int);
	void setDesiredPercent(int);
	void setHiddenLayerSize(int);
	void setLearningRate(double);
	void setErrorTolerance(double);
	void setTrainingParameter(int, int, double, double = 1, int = 1);
};

#endif