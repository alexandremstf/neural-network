# Neural Network C++
Este código foi desenvolvido usando STL, para criar redes neurais básicas em c + + com poucas linhas de código. É um projeto de iniciação científica da Universidade Federal de Ouro Preto, que utiliza como base de aprendizado o algoritmo de backpropagation. Com este código pessoas com pouco conhecimento sobre redes neurais podem as implementar. Existem duas maneiras de criar uma rede neural nesta biblioteca, manual ou automática, veja os exemplos abaixo:

This code was developed using STL, to create basic neural networks in c ++ with few lines of code. It is a project of scientific initiation of the Federal University of Ouro Preto, that uses as learning base the backpropagation algorithm. With this library, people with little knowledge about neural networks can implement them. There are two ways to create a neural network in this library, either manually or automatically, see the examples below:

```c++
//MANUAL

#include "include/Network.hpp"
#include "include/Dataset.hpp"

int main(){

	Neural::Dataset data_learning;
		// loadInputOutputData(n_inputs, n_outputs, "local file");
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();

	Neural::Network neural_network(input, output);
		neural_network.setParameter(1000, 90, 0.05, 0.8, 6);
		neural_network.trainingClassification();
		neural_network.run();
}
```

```c++
//AUTOMATIC

#include "include/Network.hpp"
#include "include/Dataset.hpp"

int main(){

	Neural::Dataset data_learning;
		// loadInputOutputData(n_inputs, n_outputs, "local file");	
		data_learning.loadInputOutputData(4, 3, "database/iris.txt");

	vector<vector<double>> input = data_learning.getInput();
	vector<vector<double>> output = data_learning.getOutput();

	Neural::Network neural_network(input, output);
		neural_network.setParameter(1000, 90, 0.05);
		neural_network.autoTraining(20, 0.2);
		neural_network.run();
}
```

Os arquivos que este código interpreta, são arquivos .txt onde cada linha representa os valores referentes a uma amostra, e os valores de cada amostra são separados por espaços. Deve-se atentar também ao fato de que os valores iniciais da linha devem ser os de entrada da rede e somente depois de todos os valores de entrada, insere-se os valores de saída correspondente (isto para etapa de treinamento) no arquivo. 