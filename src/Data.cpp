#include "../include/Data.hpp"

namespace neural {

Data::Data(){
}

void Data::saveOutputLog(){
}

/*
 * Load input and output in the same file
 */
void Data::loadInputOutputData(int n_input, int n_output, string file){
    
    n_inputs = n_input;
    n_outputs = n_output;

    ifstream input;
        input.open(file);
    double data;

    if(!input.is_open()){
        cout << "FALHA ARQUIVO" << endl;
    } else {
        
        n_rows = int(count(istreambuf_iterator<char>(input), istreambuf_iterator<char>(), '\n')) + 1;
        
        input.clear();
        input.seekg(0, input.beg);

        input_data.resize(n_rows);
        output_data.resize(n_rows);

        for (int i = 0; i < n_rows; i++){
            for (int j = 0; j < n_inputs; j++){
                input >> data;
                input_data[i].push_back(data);
            }
            
            for (int j = 0; j < n_outputs; j++){
                input >> data;
                output_data[i].push_back(data);
            }
        }
    }

    input.close();
}

vector<vector<double>> Data::getInput(){
    return input_data;
}

vector<vector<double>> Data::getOutput(){
    return output_data;
}

}