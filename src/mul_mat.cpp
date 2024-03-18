#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
std::vector <std::vector<float>> mul_mat(const std::vector <std::vector<float>>& mat1, std::vector <std::vector<float>>& mat2) {
    std::vector <std::vector<float>> res(mat1.size(), std::vector<float>(mat2[0].size(),0.0));
    for (long unsigned int i = 0; i < mat1.size(); i++) {
        for (long unsigned int j = 0; j < mat2[0].size(); j++) {
            for (long unsigned int k = 0; k < mat1.size(); k++) {
                res[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    return res;
}

std::vector <std::vector<float>> mul_mat_opt(const std::vector <std::vector<float>>& mat1, std::vector <std::vector<float>>& mat2) {
    std::vector <std::vector<float>> res(mat1.size(), std::vector<float>(mat2[0].size(),0.0));
    for (long unsigned int i = 0; i < mat1.size(); i++) {
        for (long unsigned int k = 0; k < mat2.size(); k++) {
            for (long unsigned int j = 0; j < mat2[0].size(); j++) {
                res[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    return res;
}


void init_mat(std::vector <std::vector<float>>& mat) {
    for (long unsigned int i = 0; i < mat.size(); i++) {
        for (long unsigned int j = 0; j < mat[0].size(); j++) {
            mat[i][j] = i + j; 
        }
    }
}


int main(int nargs, char **args) {
    if (nargs != 5) {
        std::cout << "wrong usage" << std::endl;
    }
    std::vector <std::vector<float>> mat1(std::atoi(args[1]), std::vector <float>(std::atoi(args[2])));
    std::vector <std::vector<float>> mat2(std::atoi(args[3]), std::vector <float>(std::atoi(args[4])));
    init_mat(mat1);
    init_mat(mat2);
    // Start the timer
    auto start = std::chrono::steady_clock::now();
    
    mul_mat(mat1, mat2);
    // End the timer
    
    auto end = std::chrono::steady_clock::now();
    
    // Calculate the elapsed time
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    // Print the elapsed time
    std::cout << "ver 1 Elapsed time: " << elapsed.count() << " milliseconds" << std::endl;
    

    

    start = std::chrono::steady_clock::now();
    
    mul_mat_opt(mat1, mat2);
    // End the timer
    
    end = std::chrono::steady_clock::now();
    
    // Calculate the elapsed time
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    // Print the elapsed time
    std::cout << "ver 2 Elapsed time: " << elapsed.count() << " milliseconds" << std::endl;



}