#include "include/Network.hpp"
#include "include/Dataset.hpp"

int main(){

	Neural::Dataset data_learning;
		data_learning.loadInputOutputData(2, 0, "database/test.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();

	Neural::Network neural_network(input, output);
		neural_network.setParameter(100, 80, 0.05, 0.8, 6);
		//neural_network.trainingTemporal();
		//neural_network.trainingClassification();
		neural_network.autoTraining(10, 0.1);
		//neural_network.run();
}

// g++ main.cpp src/Network.cpp src/Dataset.cpp -o machineLearnig -std=c++11 -Wall -g