struct Node {
    string variable;
    double value;
};

class UnionFind {
private:
    // x = root[x].variable * root[x].value
    unordered_map<string, Node> root;
    unordered_map<string, int> rank;

public:
    UnionFind(vector<vector<string>> equations) {
        for (int i = 0; i < equations.size(); i++) {
            root[equations[i][0]] = {equations[i][0], 1};
            root[equations[i][1]] = {equations[i][1], 1};
        }
    }

    Node find(string x) {
        if (root[x].variable.empty()) { // represent undefined
            return root[x];
        }

        if (x != root[x].variable) { // x is not the root node
            // root[x].variable = p.variable * p.value
            Node p = find(root[x].variable);

            // x = p.variable * p.value*root[x].value
            root[x].variable = p.variable;
            root[x].value *= p.value;
        }

        return root[x];
    }

    void unionSet(string x, string y, double value) {
        // x/y = value
        Node rootX = find(x); // x = rootX.variable * rootX.value
        Node rootY = find(y); // y = rootY.variable * rootY.value

        // rootX.variable * rootX.value = rootY.variable * rootY.value * value

        if (rootX.variable != rootY.variable) {
            if (rank[rootX.variable] > rank[rootY.variable]) {
                root[rootY.variable].variable = rootX.variable;

                // rootY.variable = rootX.variable *
                // rootX.value/rootY.value/value
                root[rootY.variable].value = rootX.value / rootY.value / value;
            } else if (rank[rootX.variable] < rank[rootY.variable]) {
                root[rootX.variable].variable = rootY.variable;

                // rootX.variable = rootY.variable *
                // rootY.value/rootX.value*value
                root[rootX.variable].value = rootY.value / rootX.value * value;
            } else {
                root[rootY.variable].variable = rootX.variable;
                rank[rootX.variable] += 1;

                // rootY.variable = rootX.variable *
                // rootX.value/rootY.value/value
                root[rootY.variable].value = rootX.value / rootY.value / value;
            }
        }
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();

        UnionFind uf(equations);

        for (int i = 0; i < n; i++) {
            uf.unionSet(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> answers;
        for (int i = 0; i < queries.size(); i++) {
            Node rootC = uf.find(queries[i][0]);
            Node rootD = uf.find(queries[i][1]);

            if (rootC.variable.empty() || rootD.variable.empty() ||
                rootC.variable != rootD.variable) {
                answers.push_back(-1);
            } else {
                answers.push_back(rootC.value / rootD.value);
            }
        }

        return answers;
    }
};
