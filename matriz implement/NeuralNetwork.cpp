#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(int n_input_layer, int n_output_layer, int n_hidden_layer){
	input_layer_size = n_input_layer;
	output_layer_size = n_output_layer;
	hidden_layer_size = n_hidden_layer;

    limit_error = 0.1;
    hit_percent = 90;
    max_epoch = 2000;

    weight.resize(2);
	weight[0].resize(input_layer_size, hidden_layer_size);
	weight[1].resize(hidden_layer_size, output_layer_size);

    data.loadInputOutputData(input_layer_size, output_layer_size, "database/iris_database_90.txt");
    input = data.getInputData();
    desired_output = data.getOutputData();





    srand(1);
    for (int i = 0; i < input_layer_size; i++ ){
        for ( int j = 0; j < hidden_layer_size; j++ ){
            weight[0](i,j) = ((double) rand() / (RAND_MAX));
        }
    }

    for (int i = 0; i < hidden_layer_size; i++ ){
        for ( int j = 0; j < output_layer_size; j++ ){
            weight[1](i,j) = ((double) rand() / (RAND_MAX));
        }
    }






//    srand((unsigned int) time(0));
   // weight[0] = Eigen::MatrixXd::Random(input_layer_size, hidden_layer_size);
   // weight[1] = Eigen::MatrixXd::Random(hidden_layer_size, output_layer_size);
}

void NeuralNetwork::neural(){

    //while (loop && max_epoch > epoch) {


        Eigen::MatrixXd sum_input_weigth            = input * weight[0];

        Eigen::MatrixXd sum_input_weigth_sigmoid    = sum_input_weigth.unaryExpr(ptr_fun(sigmoid));
        
        Eigen::MatrixXd sum_hidden_weight           = sum_input_weigth_sigmoid * weight[1];

        Eigen::MatrixXd output                      = sum_hidden_weight.unaryExpr(ptr_fun(sigmoid));

        Eigen::MatrixXd delta_output_sum    = (desired_output - output).cwiseProduct(sum_hidden_weight.unaryExpr(ptr_fun(sigmoidPrime)));

        Eigen::MatrixXd delta_hidden_sum    = (delta_output_sum * weight[1].transpose()).cwiseProduct(sum_input_weigth.unaryExpr(ptr_fun(sigmoidPrime)));
            
        Eigen::MatrixXd delta_W1            = input.transpose() * delta_hidden_sum;
        cout << delta_W1 << endl << endl;
        
        Eigen::MatrixXd delta_W2            = sum_input_weigth_sigmoid.transpose() * delta_output_sum;

        weight[0] = weight[0] + delta_W1;
        weight[1] = weight[1] + delta_W2;

        loop = verify(output);
        epoch++;
    //}
}

void NeuralNetwork::test(){
    data.loadTestData(input_layer_size, "database/iris_database_test_60.txt");
    Eigen::MatrixXd input_test = data.getInputData();
    
    Eigen::MatrixXd sum_input_weigth            = input_test * weight[0];
    Eigen::MatrixXd sum_input_weigth_sigmoid    = sum_input_weigth.unaryExpr(ptr_fun(sigmoid));
    Eigen::MatrixXd sum_hidden_weight           = sum_input_weigth_sigmoid * weight[1];
    Eigen::MatrixXd output                      = sum_hidden_weight.unaryExpr(ptr_fun(sigmoid));
        
    //cout << output << endl << endl;
    
    for (int i = 0; i < output.rows(); i++){
        
        if (doubleToInt(output(i,0)) == 0 && doubleToInt(output(i,1)) == 0 && doubleToInt(output(i,2)) == 1){
            cout << "flor 1" << endl;
        } else if (doubleToInt(output(i,0)) == 0 && doubleToInt(output(i,1)) == 1 && doubleToInt(output(i,2)) == 0){
            cout << "flor  2" << endl;
        } else if (doubleToInt(output(i,0)) == 1 && doubleToInt(output(i,1)) == 0 && doubleToInt(output(i,2)) == 0){
            cout << "flor   3" << endl;
        } else {
            cout << "Indeterminado" << endl;
        }
    }
}

bool NeuralNetwork::verify(Eigen::MatrixXd out){
    Eigen::MatrixXd compare = out - desired_output;
    compare = compare.cwiseAbs();
    
    percentage = 0;
    for (int i = 0; i < compare.rows(); i++){
        for (int j = 0; j < output_layer_size; j++){
            if (compare(i,j) < limit_error){
                percentage++;
            }
        }
    }
    
    percentage = (percentage*100)/(compare.rows()*output_layer_size);
    
    cout << percentage << "%" << endl;

    if (percentage >= hit_percent){
        cont++;
        if (cont > 5){
            return false;
        } else {
            return true;
        }
    } else {
        return true;
    }
}

void NeuralNetwork::printResult(){
    cout << "Artificial Neural NeuralNetwork" << endl << endl;
    cout << "Número de épocas para " << percentage << "% de acertos: " << epoch << endl << endl;
}

double NeuralNetwork::sigmoid(double z){
    return 1/(1+exp(-z));
}	

double NeuralNetwork::sigmoidPrime(double z){
    return exp(-z) / ( pow(1+exp(-z),2) );
}

int NeuralNetwork::doubleToInt(double n){
    return round(n);
}