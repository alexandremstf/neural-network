#include "Header.hpp"

int main(){

	Data data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();

	NeuralNetwork neural_network(input, output);
	
		neural_network.setTrainingParameter(1000, 94, 0.05, 1, 6);
		neural_network.trainingNeuralNetwork();

}

// g++ main.cpp NeuralNetwork.cpp Data.cpp Structs.cpp -o machineLearnig -std=c++11 -Wall -g