#include <iostream>

void exerciseOne()
{
    // a reference is as a constant pointer that is dereferenced each
    // time it is used, but cannot be manipulated in the same way a pointer can
    char *pointerToChar;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // an object is a contiguous region of storage; an lvalue is an expression that refers to an object
    int(&ref)[10] = array;
    std::cout << ref[0] << "\n";

    char *arrayOfStrings[] = {"Hello", "World", "!"};
    char **pointerToArrayOfStrings = arrayOfStrings;
    std::cout << pointerToArrayOfStrings[0] << "\n";

    char c = 'c';
    char *pointerToC = &c;
    char **pointToPointer = &pointerToC;

    const int one = 1;
    const int *pointerToConstant = &one;
    int const *constantPointer = &one;
}

void exerciseTwo()
{
    int *oddPointer = (int *)1;
    int *evenPointer = (int *)2;

    char *c1 = (char *)1;
    char *c2 = (char *)2;

    void *v1 = (void *)1;
    void *v2 = (void *)2;
}

void exerciseThree()
{
    typedef unsigned char u_char;
    typedef const unsigned char const_u_char;
    typedef int *int_p;
    typedef char **char_pp;
    typedef char **ar_char_p[];
    typedef int *seven_int_p[7];
    typedef seven_int_p *seven_int_pp;
    typedef seven_int_p *eight_sevent_int_p[8];
}

void swapUsingPointers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingReferences(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void exerciseFour()
{
    int a = 1;
    int b = 2;
    std::cout << "Initial values:\n";
    std::cout << "a: " << a << " b: " << b << "\n";

    std::cout << "Swapping using pointers:\n";
    swapUsingPointers(&a, &b);
    std::cout << "a: " << a << " b: " << b << "\n";

    std::cout << "Swapping using references:\n";
    swapUsingReferences(a, b);
    std::cout << "a: " << a << " b: " << b << "\n";
}

void exerciseFive()
{
    // The length of this string is 14 but the length of the
    // array itself is 15 to account for the terminator char.
    char str[] = "a short string";
    std::cout << sizeof(str) << "\n";
}

void f(char x)
{
    std::cout << x << "\n";
}

void g(char &x)
{
    std::cout << x << "\n";
}

/**
 * If the initialiser to a const T& is not an lvalue of type T,
 * Casting to a const T& is done as follows:
 *  1. The variable being assigned is cast to type T, if needed.
 *  2. A temporary variable created by the compiler stores the 
 *     result of the cast.
 *  3. The temp variable is used to initialise the const reference.
 * This means we don't have to use an lvalue, or even the same type,
 * when initialising const references.
 * 
 * Note: A temporary created to hold a reference initializer persists 
 * until the end of its reference’s scope.
 * 
 * The reason references to vars and references to constants are 
 * treated differently is because storing a temp value for the var 
 * initialiser  poses the risk of assigning to the soon-to-dissappear
 * temp when assigning to the variable. This problem does not exist
 * when referencing constants because they cannot be changed after
 * initialisation.
 * 
 **/
void h(const char &x)
{
    std::cout << x << "\n";
}

void exerciseSix()
{
    // The initializer for a const T& need not be an lvalue or even of type T
    f('a');

    // g('a'); This call is illegal because 'a' is not an lvalue

    h('a'); // This creates a temp variable because 'a' is not an lvalue

    f(49);

    // g(49); This call is illegal because 49 is not an lvalue

    h(49); // This creates a temp var because 49 is not an lvalue or type char

    f(3300); // implicit conversion from 'int' to 'char' changes value from 3300 to -28

    // g(3300); This call is illegal because 3300 is not an lvalue

    //  implicit conversion from 'int' to 'char' changes value from 3300 to -28
    h(3300); // This creates a temp var because 49 is not an lvalue or type char

    char c = 'a';
    f(c);
    g(c);
    h(c); // This does not create a temp value - c is of type char and an lvalue.

    unsigned char uc = 'u';
    f(uc);
    // g(uc); This is illegal because types don't match - con't initialise a char ref with uchar
    h(uc); // This will create a temp value because uc is not of type char.

    signed char sc = 's';
    f(sc);
    // g(sc); This is illegal because you can't initialise a non-const refernce with a different type (same as previous g)
    h(sc); // This will create a temp value because sc is not of type char.
}

int main(int argc, char const *argv[])
{
    exerciseOne();
    exerciseTwo();
    exerciseThree();
    exerciseFour();
    exerciseFive();
    exerciseSix();
    return 0;
}
