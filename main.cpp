#include "Header.hpp"

int main(){

	Data data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris_database_150.txt");
	Data data_test;
		data_test.loadInputOutputData(4, 0, "database/iris_database_test_150.txt");

	NeuralNetwork neural_network(data_learning.getInput(), data_learning.getOutput(), 3, 10000, 95, 1, 0.05);
		neural_network.testingDataset(data_test.getInput());
}
// g++ main.cpp NeuralNetwork.cpp Data.cpp Structs.cpp -o machineLearnig -std=c++11 -Wall -g