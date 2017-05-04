#include "NeuralNetwork.hpp"
#include "Data.hpp"

int main(){
	NeuralNetwork n(4,3,8);
	n.neural();
	//n.printResult();
	//n.test();
}

//g++ main.cpp NeuralNetwork.cpp Data.cpp -o neuronio -std=c++11 -Wall -g