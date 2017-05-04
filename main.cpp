#include "Header.hpp"

int main(){

	Data data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris_database_90.txt");
	Data data_test;
		data_test.loadInputOutputData(4, 0, "database/iris_database_test_60.txt");

	NeuralNetwork neural_network(data_learning.getInput(), data_learning.getOutput(), 1000, 94, 0.05);
		neural_network.automaticTrainingNeuralNetwork(15, 0.1);
		neural_network.testingDataset(data_test.getInput());
	
}
// g++ main.cpp NeuralNetwork.cpp Data.cpp Structs.cpp -o machineLearnig -std=c++11 -Wall -g