#include "NeuralNetwork.hpp"
#include "Data.hpp"

int main(){

	Data data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();

	NeuralNetwork neural_network(input, output);
		neural_network.setParameter(1000, 90, 0.05, 0.8, 6);
		neural_network.training();
//neural_network.autoTraining(20, 0.2);
		neural_network.run();
}

// g++ main.cpp NeuralNetwork.cpp Data.cpp -o machineLearnig -std=c++11 -Wall -g