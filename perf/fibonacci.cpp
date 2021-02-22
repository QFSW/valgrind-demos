#include <chrono>
#include <iostream>

int fibonacci(int n)
{
    return n > 1
        ? fibonacci(n - 1) + fibonacci(n - 2)
        : n;
}

template <typename F>
std::chrono::duration<double> measure(F&& f, const size_t count = 1)
{
    const auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < count; i++)
    {
        f();
    }
    const auto finish = std::chrono::high_resolution_clock::now();

    return (finish - start) / count;
}

int main()
{
    auto time = measure([]{
        int result = fibonacci(30);
    });

    std::cout << time.count() << "s\n";
    return 0;
}