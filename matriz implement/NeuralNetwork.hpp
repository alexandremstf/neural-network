#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

//#include <iostream>
//#include <stdio.h>
#include <vector>
#include <eigen3/Eigen/Dense>

#include "Data.hpp"

using namespace std;

class NeuralNetwork {

private:
	Data data;

	int data_size;
	int input_layer_size;
	int output_layer_size;
	int hidden_layer_size;

	int max_epoch;
	int percentage;
	double limit_error;
	double hit_percent;

	int epoch = 0;
	int cont = 0;
	bool loop = true;

	Eigen::MatrixXd input;
	Eigen::MatrixXd desired_output;
	vector<Eigen::MatrixXd> weight;
	
public:
	NeuralNetwork(int, int, int);
	void setNetworkPrecision();
	void neural();
	void test();
	void printResult();
	bool verify(Eigen::MatrixXd);
	static int doubleToInt(double);
	static double sigmoid(double);	
	static double sigmoidPrime(double);
	
};

#endif