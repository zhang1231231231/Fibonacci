#include <iostream>

using namespace std;

template <int N>
class TemplateFibonacci
{
  public:
    enum
    {
        ret = TemplateFibonacci<N - 1>::ret + TemplateFibonacci<N - 2>::ret
    };
};

template <>
class TemplateFibonacci<1>
{
  public:
    enum
    {
        ret = 1
    };
};

template <>
class TemplateFibonacci<2>
{
  public:
    enum
    {
        ret = 2
    };
};

int fibonacci(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciNoRecursion(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    int a1 = 1;
    int a2 = 2;
    int sum;
    for (int i = 3; i <= n; i++)
    {
        sum = a1 + a2;
        a1 = a2;
        a2 = sum;
    }
    return sum;
}

int main()
{
    std::cout << fibonacci(10) << std::endl;
    std::cout << fibonacciNoRecursion(10) << std::endl;
    std::cout << TemplateFibonacci<10>::ret << std::endl;
}