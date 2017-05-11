# Neural Network C++
This library was developed using STL, to create neural networks in c ++ with few lines of code. It is a project of scientific initiation of the Federal University of Ouro Preto, that uses as learning base the backpropagation algorithm. With this library, people with little knowledge about neural networks can implement them. There are two ways to create a neural network in this library, either manually or automatically, see the examples below:

Esta biblioteca foi desenvolvida usando STL, para criar redes neurais em c + + com poucas linhas de código. É um projeto de iniciação científica da Universidade Federal de Ouro Preto, que utiliza como base de aprendizado o algoritmo de backpropagation. Com esta biblioteca pessoas com pouco conhecimento sobre redes neurais podem as implementar. Existem duas maneiras de criar uma rede neural nesta biblioteca, manual ou automática, veja os exemplos abaixo:

```c++
//MANUAL

#include "include/Network.hpp"
#include "include/Dataset.hpp"

int main(){

	Neural::Dataset data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();

	Neural::Network neural_network(input, output);
		neural_network.setParameter(1000, 90, 0.05, 0.8, 6);
		neural_network.training();
		neural_network.run();
}
```

```c++
//AUTOMATIC

#include "include/Network.hpp"
#include "include/Dataset.hpp"

int main(){

	Neural::Dataset data_learning;
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();

	Neural::Network neural_network(input, output);
		neural_network.setParameter(1000, 90, 0.05);
		neural_network.autoTraining(20, 0.2);
		neural_network.run();
}
```

