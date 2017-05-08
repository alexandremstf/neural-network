#ifndef NEURALNETWORK_HPP_
#define NEURALNETWORK_HPP_

#include "Header.hpp"

class NeuralNetwork {

struct ForwardPropagation {
	vector<double> sum_input_weight;
	vector<double> sum_output_weigth;
	vector<double> sum_input_weight_ativation;
	vector<double> output;

	ForwardPropagation(){}
	ForwardPropagation(int size_input, int size_output) { 
		sum_input_weight.resize(size_input);
	    sum_output_weigth.resize(size_output);
    	fill(sum_input_weight.begin(), sum_input_weight.end(), 0);
		fill(sum_output_weigth.begin(), sum_output_weigth.end(), 0);
    }
	
}; 

struct BackPropagation {
	vector<double> delta_output_sum;
	vector<double> delta_input_sum;

	BackPropagation(){}
	BackPropagation(int size_input) { 
		delta_input_sum.resize(size_input);
    	fill(delta_input_sum.begin(), delta_input_sum.end(), 0);
    }
}; 

struct network {
	int epoch = 0;
	int hidden_layer = 0;
	double learning_rate = 0;
	vector<vector<double>> weight_input;
	vector<vector<double>> weight_output;
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

	ForwardPropagation forwardPropagation(vector<double>);
	void backPropagation(ForwardPropagation, vector<double>, vector<double>);

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