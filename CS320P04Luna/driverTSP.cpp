#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include "graph.h"
#include "tspProblem.h"

using namespace std;

int main() {

    string fileN;
        Graph test;
        ifstream inputFile;
        cout << "Enter file name: ";
        cin >> fileN;
        inputFile.open(fileN); // The name of the file you set up.
        if (!inputFile.is_open()) {
            cout << "File failed to open.";
        }
        else {
            test.read(inputFile);
            inputFile.close();

            tspProblem p;
            p.solve(test);
            cout << endl;
        }

    }

