#include "Header.hpp"

int main(){

	Data data;
		data.loadInputOutputData(4, 3, "database/iris_database_90.txt");
	Data data_test;
		data_test.loadInputOutputData(4, 0, "database/iris_database_test_60.txt");

	NeuralNetwork neural_network(4,3,8);
		neural_network.setInput(data.getInput());
		neural_network.setOutput(data.getOutput());
		neural_network.trainingDataset();
		neural_network.testingDataset(data_test.getInput());
}
// g++ main.cpp NeuralNetwork.cpp Data.cpp Structs.cpp -o machineLearnig -std=c++11 -Wall -g