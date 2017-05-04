#ifndef NEURALNETWORK_HPP_
#define NEURALNETWORK_HPP_

#include "Header.hpp"

class NeuralNetwork {

struct network {
  int epoch = 0;
  int hidden_layer = 0;
  double learning_rate = 0;
} ;

private:
	int input_layer_size;
	int output_layer_size;
	int hidden_layer_size;

	vector<vector<double>> input;
	vector<vector<double>> output;
	vector<vector<double>> weight_input;
	vector<vector<double>> weight_output;

	network best_network;

	int epoch;
	int correct_output;
	int hit_percent;

	int max_epoch;
	double desired_percent;
	double learning_rate;
	double error_tolerance;
		
public:
	NeuralNetwork();
	NeuralNetwork(vector<vector<double>>, vector<vector<double>>, int, int, double, double = 1, int = 1);

	void trainingNeuralNetwork();
	void automaticTrainingNeuralNetwork(int, double);
	void testingDataset(vector<vector<double>>);
	void initializeWeight();
	void hitRate(vector<double>, unsigned int);

	double sigmoid(double);	
	double sigmoidPrime(double);

	void setInput(vector<vector<double>>);
	void setOutput(vector<vector<double>>);
	void setMaxEpoch(int);
	void setDesiredPercent(int);
	void setHiddenLayerSize(int);
	void setLearningRate(double);
	void setErrorTolerance(double);

};

#endif