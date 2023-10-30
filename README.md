# fact_pack

Пакетное вычисление позволяет оптимизировать скорость вычисления факториала в формулах

```
int main() {
    int n, k;
    std::cin >> n >> k;

    {
        //Вычисление числа сочетаний без повторений
        int k_fact = k;
        int n_fact = n;
        int n_k_fact = n - k;

        //Переменные заменяются на результаты вычислений
        fact_pack(k_fact, n_fact, n_k_fact);

        std::cout << "Combinations without repetitions:" << n_fact / (n_k_fact * k_fact) << std::endl;
    }
}
```
