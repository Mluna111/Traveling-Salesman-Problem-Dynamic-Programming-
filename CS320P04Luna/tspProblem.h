#ifndef tspProblem_h
#define tspProblem_h

class tspProblem {
private:

    vector<vector<int>> gTable;
    vector<vector<unsigned int>> pathTable;
    bitset<32> S;
    tuple<int, vector<string>> solution;

    unsigned int gCost(unsigned int i, bitset<32>& S, Graph& g)
    {
        if (S.none()) return g.getEdgeCost(i, 0);
        if (gTable[i][S.to_ulong()] >= 0)return gTable[i][S.to_ulong()];

        unsigned int nVertices = g.getNumVertices();
        unsigned int costThru_j;
        unsigned int min_j;
        bitset<32> min_S;

        unsigned int answer = INT_MAX;
        bool min_j_found = false;
        for (unsigned j = 1; j < nVertices; j++)
        {
            if (S.test(j)) {
                min_S = S;
                min_S.reset(j);
                costThru_j = g.getEdgeCost(i, j) + gCost(j, min_S, g);

                if (costThru_j < answer) {
                    min_j_found = true;
                    answer = costThru_j;
                    min_j = j;
                }
            }
        }

        if (min_j_found) {
            gTable[min_j][S.to_ulong()] = answer;
            pathTable[i][S.to_ulong()] = min_j;
        }
        return answer;
    }

    void print() {
        if (get<0>(solution) == INT_MAX)
        {
            cout << "No Hamiltonian Cycle";
        }
        else {
            cout << "[" << get<0>(solution) << ", <";
            size_t it;
            for (it = 0; it < get<1>(solution).size(); it++)
            {
                cout << get<1>(solution)[it];
                if (it != get<1>(solution).size() - 1)
                    cout << ",";
            }
            cout << ">]";
        }
    }

public:

    tuple<int, vector<string>> solve(Graph& g)
    {
        vector<int> v_temp;
        vector<unsigned> v_pathTemp;
        unsigned int nVertices = g.getNumVertices();
        unsigned int minCost = 0;
        for (unsigned int i = 0; i < nVertices; i++)
        {
            v_temp.resize(static_cast<int>(pow(2, nVertices)));
            v_temp.assign(v_temp.size(), -1);
            gTable.push_back(v_temp);
            v_pathTemp.resize(static_cast<int>(pow(2, nVertices)));
            v_pathTemp.assign(v_pathTemp.size(), -1);
            pathTable.push_back(v_pathTemp);
        }

        for (size_t i = 0; i < nVertices; i++)
        {
            S.set(i);
        }
        minCost = gCost(0, S.reset(0), g);
        get<0>(solution) = minCost;

        S.reset(0);
        size_t index = 0;
        if (minCost != INT_MAX) {

            get<1>(solution).push_back(g.getVertexName(0));
            do {
                index = pathTable[index][S.to_ulong()];
                get<1>(solution).push_back(g.getVertexName(index));
                S.reset(index);

            } while (S.to_ulong() != 0);
        }

        print();
        return solution;
    }//end solve member function

}; //end tsp class
#endif