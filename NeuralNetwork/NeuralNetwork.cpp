#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(int n_input_layer, int n_output_layer){
	//Automatic
}

// number of inputs - number of outputs - number of hidden layers - maximum number of epochs - learning rate - error tolerance
NeuralNetwork::NeuralNetwork(int n_input_layer, int n_output_layer, int n_hidden_layer_size, int m_epoch, double l_rate, double e_tolerance){
	input_layer_size = n_input_layer;
	output_layer_size = n_output_layer;
	hidden_layer_size = n_hidden_layer_size;
    max_epoch = m_epoch;
	learning_rate = l_rate;
	error_tolerance = e_tolerance;

    weight_input.resize(input_layer_size);
    weight_output.resize(hidden_layer_size);
}

void NeuralNetwork::trainingDataset(){
    initializeWeight();
    
    for (int epoch = 0; epoch < max_epoch; epoch++) {
        for (unsigned int row = 0; row < input.size(); row++){

    //FORWARD PROPAGATION
        // somatório dos produtos entre, entrada e peso das entradas em cada neurônio da camada oculta
            vector<double> sum_input_weigth(hidden_layer_size, 0.0);
            for (int i = 0; i < hidden_layer_size; i++ ){
                for (int j = 0; j < input_layer_size; j++ ){
                    sum_input_weigth[i] += input[row][j] * weight_input[j][i];
                }
            }

        // aplica função de ativação, em cada somatório encontrado, ou em cada neurônio da camada oculta  (sigmoid)
            vector<double> neural_input;
            for (int i = 0; i < hidden_layer_size; i++ ){
                neural_input.push_back(sigmoid(sum_input_weigth[i]));
            }

        // somatório dos produtos entre, o somatório dos neurônios na camada oculta e o peso das saídas
            vector<double> sum_output_weigth(output_layer_size, 0.0);
            for (int i = 0; i < output_layer_size; i++ ){
                for (int j = 0; j < hidden_layer_size; j++ ){
                    sum_output_weigth[i] += neural_input[j] * weight_output[j][i];
                }
            }

        // aplica função de ativação em cada somatório encontrado, ou em cada nerônio da camada de saída (sigmoidPrime), saída da rede neural
            vector<double> neural_output;
            for (int i = 0; i < output_layer_size; i++ ){
                neural_output.push_back(sigmoid(sum_output_weigth[i]));
            }


    //BACK PROPAGATION
        // erro entre a saída esperada e a calculada, multiplicado pela taxa de mudança da função de ativação no somatório de saída (derivada)
            vector<double> delta_output_sum;
            for (int i = 0; i < output_layer_size; i++ ){
                delta_output_sum.push_back((output[row][i] - neural_output[i]) * sigmoidPrime(sum_output_weigth[i]));
            }

        // relação dos erros das saídas com a saída, multiplicado pela taxa de mudança da função de ativação no somatório da camada oculta (derivada)
            vector<double> delta_input_sum(hidden_layer_size, 0.0);
            for (int i = 0; i < hidden_layer_size; i++ ){
                for (int j = 0; j < output_layer_size; j++ ){
                    delta_input_sum[i] += delta_output_sum[j] * weight_output[i][j];
                }
                delta_input_sum[i] *= sigmoidPrime(sum_input_weigth[i]);
            }

        // corrigindo os valores dos pesos de saída
            for (unsigned int i = 0; i < weight_output.size(); i++){
                for (unsigned int j = 0; j < weight_output[i].size(); j++){
                    weight_output[i][j] += delta_output_sum[j] * neural_input[i] * learning_rate;
                }        
            }
        
        // corrigindo os valores dos pesos de entrada
            for (unsigned int i = 0; i < weight_input.size(); i++){
                for (unsigned int j = 0; j < weight_input[i].size(); j++){
                    weight_input[i][j] += delta_input_sum[j] * input[row][i] * learning_rate;
                }        
            }
            
            hitRate(neural_output, row);
        }
        cout << hit_percent << "\t" << epoch << endl;
    }    
}

void NeuralNetwork::hitRate(vector<double> neural_output, unsigned int row){
    if (row == input.size() - 1){
        hit_percent = (correct_output * 100) / (output.size() * output_layer_size);
        correct_output = 0;
    } else {
        for (int i = 0; i < output_layer_size; i++ ){
            if (neural_output[i] - output[row][i] < error_tolerance){
                correct_output++;
            }
        }
    }
}

void NeuralNetwork::initializeWeight(){
    srand((unsigned int) time(0));
    
    for (unsigned int i = 0; i < weight_input.size(); i++ ){
        for ( int j = 0; j < hidden_layer_size; j++ ){
            weight_input[i].push_back(((double) rand() / (RAND_MAX)));
        }
    }

    for (unsigned int i = 0; i < weight_output.size(); i++ ){
        for ( int j = 0; j < output_layer_size; j++ ){
            weight_output[i].push_back(((double) rand() / (RAND_MAX)));
        }
    }
    correct_output = 0;
}

double NeuralNetwork::sigmoid(double z){
    return 1/(1+exp(-z));
}	

double NeuralNetwork::sigmoidPrime(double z){
    return exp(-z) / ( pow(1+exp(-z),2) );
}

void NeuralNetwork::setInput(vector<vector<double>> input_data){
    input = input_data;
}

void NeuralNetwork::setOutput(vector<vector<double>> output_data){
    output = output_data;    
}


void NeuralNetwork::testingDataset(vector<vector<double>> input_test){
    for (unsigned int row = 0; row < input_test.size(); row++){
    
    //FORWARD PROPAGATION
    // somatório dos produtos entre, entrada e peso das entradas em cada neurônio da camada oculta
        vector<double> sum_input_weigth(hidden_layer_size, 0.0);
        for (int i = 0; i < hidden_layer_size; i++ ){
            for (int j = 0; j < input_layer_size; j++ ){
                sum_input_weigth[i] += input_test[row][j] * weight_input[j][i];
            }
        }

    // aplica função de ativação, em cada somatório encontrado, ou em cada neurônio da camada oculta  (sigmoid)
        vector<double> neural_input;
        for (int i = 0; i < hidden_layer_size; i++ ){
            neural_input.push_back(sigmoid(sum_input_weigth[i]));
        }

    // somatório dos produtos entre, o somatório dos neurônios na camada oculta e o peso das saídas
        vector<double> sum_output_weigth(output_layer_size, 0.0);
        for (int i = 0; i < output_layer_size; i++ ){
            for (int j = 0; j < hidden_layer_size; j++ ){
                sum_output_weigth[i] += neural_input[j] * weight_output[j][i];
            }
        }

    // aplica função de ativação em cada somatório encontrado, ou em cada nerônio da camada de saída (sigmoidPrime), saída da rede neural
        vector<double> neural_output;
        for (int i = 0; i < output_layer_size; i++ ){
            neural_output.push_back(sigmoid(sum_output_weigth[i]));
        }

        Struct::printVector(neural_output);
    }   
    cout << endl;
}