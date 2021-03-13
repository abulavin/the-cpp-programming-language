#include <iostream>
#include <limits>

int main(int argc, char const *argv[])
{

    std::cout << std::numeric_limits<char>::max() << ", " << std::numeric_limits<char>::min() << "\n";
    std::cout << std::numeric_limits<short>::max() << ", " << std::numeric_limits<short>::min() << "\n";
    std::cout << std::numeric_limits<int>::max() << ", " << std::numeric_limits<int>::min() << "\n";
    std::cout << std::numeric_limits<long int>::max() << ", " << std::numeric_limits<long int>::min() << "\n";
    std::cout << std::numeric_limits<float>::max() << ", " << std::numeric_limits<float>::min() << "\n";
    std::cout << std::numeric_limits<double>::max() << ", " << std::numeric_limits<double>::min() << "\n";
    std::cout << std::numeric_limits<long double>::max() << ", " << std::numeric_limits<long double>::min() << "\n";
    std::cout << std::numeric_limits<unsigned>::max() << ", " << std::numeric_limits<unsigned>::min();
    return 0;
}

