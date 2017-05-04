#include "Header.hpp"

int main(){

	Data data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris_database_90.txt");
	Data data_test;
		data_test.loadInputOutputData(4, 0, "database/iris_database_test_60.txt");

	NeuralNetwork neural_network(4, 3, 8, 1000, 1, 0.05, 0.94);
		neural_network.setInput(data_learning.getInput());
		neural_network.setOutput(data_learning.getOutput());
		neural_network.trainingDataset();
		neural_network.testingDataset(data_test.getInput());
}
// g++ main.cpp NeuralNetwork.cpp Data.cpp Structs.cpp -o machineLearnig -std=c++11 -Wall -g