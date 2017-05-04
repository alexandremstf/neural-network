#include "Structs.hpp"

namespace Struct {
        
    void printMatrix(vector<vector<double>> v){
        for (unsigned int i = 0; i < v.size(); i++){
            for (unsigned int j = 0; j < v[i].size(); j++){
                cout << v[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printVector(vector<double> v){
        for (unsigned int i = 0; i < v.size(); i++){
            cout << round(v[i]) << "\t";
        }
        cout << endl;
    }
}