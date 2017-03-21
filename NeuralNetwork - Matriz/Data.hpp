#ifndef DATA_H_
#define DATA_H_

#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>

using namespace std;

class Data {

private:
	Eigen::MatrixXd input_data;
    Eigen::MatrixXd output_data;

public:
	Data();
    void saveOutputLog();
    void loadInputOutputData(int, int, string);
    void loadTestData(int, string);
    Eigen::MatrixXd getInputData();
    Eigen::MatrixXd getOutputData();
    
};

#endif