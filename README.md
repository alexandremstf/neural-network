# Neural Network C++
This library was developed using STL, to create neural networks in c ++ with few lines of code. It is a project of scientific initiation of the Federal University of Ouro Preto. There are two ways to create a neural network in this library, both manual and automatic, see the examples below:

```c++
//MANUAL

#include "NeuralNetwork.hpp"

int main(){

	Data data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();
	
	NeuralNetwork neural_network(input, output);
		neural_network.setParameter(1000, 94, 0.05, 0.8, 6);
		neural_network.training();
		neural_network.run();
}
```

```c++
//AUTOMATIC

#include "NeuralNetwork.hpp"

int main(){

	Data data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();
	
	NeuralNetwork neural_network(input, output);
		neural_network.setParameter(1000, 94, 0.05);
		neural_network.autoTraining(20, 0.1);
		neural_network.run();
}
```

