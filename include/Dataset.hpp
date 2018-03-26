#ifndef DATA_HPP_
#define DATA_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

namespace Neural{

class Dataset {

private:
    int n_inputs;
    int n_outputs;
    int n_rows;

    vector<vector<double>> input_data;
    vector<vector<double>> output_data;

public:
	Dataset();
    void saveOutputLog();
    void loadInputOutputData(int, int, string); // load input and output in same file

    void normalize(vector<vector<double>>);

    void printMatrix(vector<vector<double>> v);
    void printVector(vector<double> v);

    vector<vector<double>> getInput();
    vector<vector<double>> getOutput();
};

}

#endif