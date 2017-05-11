# Neural Network C++
This Library was developed using STL, to create neural networks in c++ with few lines of code. There are two modes to create a neural network in this library, manual and automatic, see the examples bellow:

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

