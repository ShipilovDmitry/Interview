void findDistinctive(vector<int>& array) {
    size_t insertIndex = 1;
    for(size_t i = 1; i < array.size(); ++i) {
        if(array[i - 1] != array[i]) {    
            array[insertIndex++] = array[i];
        }
    }
}


// На вход поступает набор случайных чисел.
// Необходимо найти и вернуть уникальные элементы без дублирований.
std::vector<int> findDistinctive(vector<int> const & array) {
    std::vector<int> res;
    res.reserve(vec.size());
    
    std::unordered_set<int> exist;
    for (const auto & cur : vec) {
        if (!exist.count(cur)) {
            res.push_back(cur);
            exist.insert(cur);
        }
    }
    
    return res;
}

// C++ ----------------
#include <iostream>

// На вход поступает набор случайных чисел.
// Необходимо найти и вернуть уникальные элементы без дублирований.
// Исходный порядок элементов важен.

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}

