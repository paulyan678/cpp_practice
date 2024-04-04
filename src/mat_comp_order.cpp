#include <iostream> // For std::cout, std::cerr, std::endl
#include <vector> // For std::vector
#include <string> // For std::string
#include <map> // For std::map
#include <limits> // For std::numeric_limits
#include <utility> // For std::pair
#include <cstdlib> // For std::atoi

using namespace std;

map<pair<int, int>, pair<int, string>> memo;

pair <int, string> mat_mul_order(const vector <pair<int, int>>& dims, int i, int j) {
    pair <int, int> key {i, j};
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    if (i == j) {
        return {0, "M" + to_string(i)};
    }
    
    int res_ops = numeric_limits<int>::max();
    string res_order;
    for (int k = i; k < j; k++) {
        pair <int, string> left = mat_mul_order(dims, i, k);
        pair <int, string> right = mat_mul_order(dims, k + 1, j);
        int cur_ops = dims[i].first*dims[k].second*dims[j].second;
        int total_ops = cur_ops + left.first + right.first;
        if (total_ops < res_ops) {
            res_ops = total_ops;
            res_order = "(" + left.second + " x " + right.second + ")";
        }

    }
    memo[key] = {res_ops, res_order};
    return {res_ops, res_order};


}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc % 2 == 0) {
        cerr << "Usage: " << argv[0] << "<dim1> <dim2> ..." << endl;
    }
    
    vector<pair<int, int>> dims;
    for (int i = 1; i< argc; i+=2) {
        int dim1 = atoi(argv[i]);
        int dim2 = atoi(argv[i+1]);
        dims.push_back({dim1, dim2});
    }
    auto res = mat_mul_order(dims, 0, dims.size()-1);
    cout << "Minimum number of operations: " << res.first << endl;
    cout << "order of multiplication: " << res.second << endl;
    return 0;
}