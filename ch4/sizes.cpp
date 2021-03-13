#include <iostream>

int main()
{
    enum Suits
    {
        Spades,
        Clubs,
        Hearts,
        Diamonds
    };

    int x = 1;
    char c = 'c';
    long l = 123;
    char *str = "Abcdef";

    std::cout << sizeof(x) << "\n";
    std::cout << sizeof(c) << "\n";
    std::cout << sizeof(l) << "\n";
    std::cout << sizeof(str[0]) << "\n";
    std::cout << sizeof(str) << "\n";
    std::cout << sizeof(Suits::Spades);
}
