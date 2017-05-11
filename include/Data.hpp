#ifndef DATA_HPP_
#define DATA_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

namespace neural{

class Data {

private:
    int n_inputs;
    int n_outputs;
    int n_rows;

    vector<vector<double>> input_data;
    vector<vector<double>> output_data;

public:
	Data();
    void saveOutputLog();
    void loadInputOutputData(int, int, string); // load input and output in same file
    
    void printInput();
    void printOutput();

    vector<vector<double>> getInput();
    vector<vector<double>> getOutput();
};

}

#endif