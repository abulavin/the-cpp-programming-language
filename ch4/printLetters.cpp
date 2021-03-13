#include <iostream>

int main(int argc, char const *argv[])
{
    for (int i = 97; i < 123; ++i)
    {
        std::cout << char(i);
        std::cout << ", ";
        std::cout << i;
        std::cout << "\n";
    }
    for (int i = 48; i < 58; ++i)
    {
        std::cout << char(i);
        std::cout << ", ";
        std::cout << i;
        std::cout << "\n";
    }
    return 0;
}
