#include <iostream>
#include <vector>

// Function to print the content of vec3
void printVec3(const std::vector<std::vector<int>>& vec3) {
    for (const auto& vec : vec3) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void modify_vec(std::vector <int>& vec) {
    for (long unsigned int i = 0; i < vec.size(); i++) {
        vec[i] = i;
    }
}
int main(int argc, char ** argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " vec1_size vec2_size" << std::endl;
        return 1;
    }

    int vec1_sz = std::atoi(argv[1]);
    int vec2_sz = std::atoi(argv[2]);
    
    std::vector<int> vec1(vec1_sz);
    std::vector<int> vec2(vec2_sz);
    
    std::vector<std::vector<int>> vec3;
    
    vec3.push_back(vec1);
    vec3.push_back(vec2);
    
    // Call the function to print the content of vec3
    printVec3(vec3);
    modify_vec(vec1);
    modify_vec(vec2);
    printVec3(vec3);
    return 0;
}
