#include <iostream>
#include <vector>
#include <algorithm>

int fact(int i, int limit = 0) {
    if (i == limit) return 1;
    return i * fact(i - 1, limit);
}
template <typename... Vars>
void fact_pack(Vars&... vars) {
    std::vector<int*> vector_vars = {&vars... };
    std::vector<int> results;
    std::sort(vector_vars.begin(), vector_vars.end(), [](int* lhs, int* rhs) {
        return *lhs < *rhs;
        });
    for (int i = 0; i < vector_vars.size(); ++i) {
        if (i == 0) {
            results.push_back(fact(*vector_vars[0]));
        }
        else {
            results.push_back(results[i - 1] * fact(*vector_vars[i], *vector_vars[i - 1]));
        }
    }
    for (int i = 0; i < vector_vars.size(); ++i) {
        *vector_vars[i] = results[i];
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    {
     //Вычисление числа сочетаний без повторений
    int k_fact = k;
    int n_fact = n;
    int n_k_fact = n - k;
      
    fact_pack(k_fact, n_fact, n_k_fact);
    std::cout << "Combinations without repetitions:" << n_fact / (n_k_fact * k_fact);
    }

    {
    //Вычисление числа сочетаний с повторениями
    int k_fact = k;
    int n_fact = n - 1;
    int n_k_fact = k + n - 1;

    fact_pack(k_fact, n_fact, n_k_fact);
    std::cout << "Combinations with repetitions:" << n_k_fact / (n_fact * k_fact);
    }
}
