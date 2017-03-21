#include "Data.hpp"

Data::Data(){

}

void Data::saveOutputLog(){
/*
    ofstream output;
    output.open("/home/directory");

    if(!output.is_open()){
        cout << "FALHA ARQUIVO" << endl;
    } else {
        output << to_save << endl;
    }

    output.close();
*/
}

/*
 * Load input and output in the same file
 */
void Data::loadInputOutputData(int n_inputs, int n_outputs, string file){
    
    ifstream input;
    input.open(file);

    if(!input.is_open()){
        cout << "FALHA ARQUIVO" << endl;
    } else {
        
        int n_rows = int(count(istreambuf_iterator<char>(input), istreambuf_iterator<char>(), '\n')) + 1;
        
        input.clear();
        input.seekg(0, input.beg);
        input_data.resize(n_rows, n_inputs);
        output_data.resize(n_rows, n_outputs);
        
        for (int i = 0; i < n_rows; i++){
            for (int j = 0; j < n_inputs; j++){
                input >> input_data(i, j);
            }
            for (int j = 0; j < n_outputs; j++){
                input >> output_data(i, j);
            }
        }
    }

    input.close();

    //cout << input_data << endl << endl;
    //cout << output_data << endl << endl;
}

void Data::loadTestData(int n_inputs, string file){
    
    ifstream input;
    input.open(file);

    if(!input.is_open()){
        cout << "FALHA ARQUIVO" << endl;
    } else {
        
        int n_rows = int(count(istreambuf_iterator<char>(input), istreambuf_iterator<char>(), '\n')) + 1;
        
        input.clear();
        input.seekg(0, input.beg);
        input_data.resize(n_rows, n_inputs);
        
        for (int i = 0; i < n_rows; i++){
            for (int j = 0; j < n_inputs; j++){
                input >> input_data(i, j);
            }
        }
    }

    input.close();

    //cout << input_data << endl << endl;
}

Eigen::MatrixXd Data::getInputData(){
    return input_data;
}

Eigen::MatrixXd Data::getOutputData(){
    return output_data;
}