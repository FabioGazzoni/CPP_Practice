/**
 * Examples of ParamType:
 * - [A] It's a reference or pointer, but not a universal reference. ❌️ copy | ✅️ presevere const | ❌️ presevere l/r value
 * - [B] It's a universal refrence.                                  ❌️ copy | ✅️ presevere const | ✅️ presevere l/r value
 * - [C] It's neither a pointer nor a reference.                     ✅️ copy | ❌️ presevere const | ❌️ presevere l/r value
 * - [D] Function arguments decay
 *
 * Then has a example with as Array arguments decay
 */

#include <iostream>
#include <array>

using namespace std;

template <typename T>
void A(T &param) // void A(ParamType param)
{
    return;
}

void case_A()
{
    int x = 27;        // x is an int
    const int cx = x;  // cx is a const int
    const int &rx = x; // rx is a reference to x as a const int

    A(x);  // T is int, param's type is int&
    A(cx); // T is const int, param's type is const int&
    A(rx); // T is const int, param's type is const int&

    // In case whit void A(const T &param)
    // A(x);// T is int, param's type is const int&
    // A(cx);// T is int, param's type is const int&
    // A(rx);// T is int, param's type is const int&

    // In this other case void A(T* param)
    //
    // const int *px = &x; // px is a ptr to x as a const int
    //
    // A(&x);// T is int, param's type is int*
    // A(px);// T is const int, param's type is const int*
}

template <typename T>
void B(T &&param) // param is a universal reference
{
    return;
}

void case_B()
{
    int x = 27;        // x is an int
    const int cx = x;  // cx is a const int
    const int &rx = x; // rx is a reference to x as a const int

    B(x);  // x is lvalue, so T is int&, param's type is also int&
    B(cx); // cx is lvalue, so T is const int&, param's type is also const int&
    B(rx); // rx is lvalue, so T is const int&, param's type is also const int&
    B(27); // 27 is rvalue, so T is int, param's type is therefore int&&
}

template <typename T>
void C(T param)
{
    return;
}

void case_C()
{
    int x = 27;        // x is an int
    const int cx = x;  // cx is a const int
    const int &rx = x; // rx is a reference to x as a const int

    C(x);  // T's and param's types are both int
    C(cx); // T's and param's types are again both int
    C(rx); // T's and param's types are still both int

    // If void C(T param);
    //
    // const char* const ptr = "Fun with pointers"; // ptr is const pointer to const object
    //
    // C(ptr); // pass arg of type const char * const, the content thisn't modifiable, because param it's a pointer pointing to const char
    // however, the adrress in this copy pointer is.

    //C({2}); ERROR
    //
    //if: void C(std::initializer_list<T> param)
    //C({2}) is correct and T is int, param is std::initializer_list<int>
}

void someFunc(int, double)
{
    return;
}

template <typename T>
void D1(T param) // param passed by value
{
    return;
} 

template <typename T>
void D2(T &param) // param passed by ref
{
    return;
}

void case_D()
{
    D1(someFunc); // param deduced as ptr-to-func; type is void (*)(int, double)

    D2(someFunc); // param deduced as ref-to-func; type is void (&)(int, double). Thisn't decay to pointer
}

template <typename T, size_t N>
constexpr size_t array_size(T (&)[N]) noexcept // avoid decay to pointer
{
    return N;
}

int main()
{
    int keyVals[] = {1, 3, 7, 9, 11, 22, 35};
    array<int, array_size(keyVals)> mappedVals;

    for (auto &&i : mappedVals)
    {
        i = 1 + rand() % array_size(keyVals);
        cout << i << endl;
    }
}
