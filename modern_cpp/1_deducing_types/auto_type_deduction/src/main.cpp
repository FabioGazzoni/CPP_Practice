/**
 * auto type deduction for:
 * - auto =>    ✅️ copy | ❌️ presevere const | ❌️ presevere l/r value
 * - auto& y *=>❌️ copy | ✅️ presevere const | ❌️ presevere l/r value
 * - auto&& =>  ❌️ copy | ✅️ presevere const | ✅️ presevere l/r value
 */

#include <iostream>
#include <vector>
#include <initializer_list>

int main()
{

    auto x = 27;
    const auto cx = x;
    const auto &rx = x;
    std::cout << "x= " << x << " cx= " << cx << " rx= " << rx << std::endl;
    std::cout << "&x= " << &x << " &cx= " << &cx << " &rx= " << &rx << std::endl;
    // The type specifier is neither a pointer nor a reference. it's a copy

    auto a_0 = 27;      // int
    const auto a_1 = x; // const int

    // The type specifier is a pointer or reference, but not a universal reference.

    auto &b_0 = x;       // refrence to x
    const auto &b_1 = x; // const reference to x

    // The type specifier is a universal reference.

    auto &&c_0 = x;  // reference to x (lvalue)
    auto &&c_1 = cx; // const reference to x (lvalue)
    auto &&c_2 = 27; // int (rvalue)

    std::cout << "auto:: &a_0 (x): " << &a_0 << " , const &a_1 (cx): " << &a_1 << std::endl;
    std::cout << "auto &:: &x: " << &b_0 << " , const &cx: " << &b_1 << std::endl;
    std::cout << "auto &&:: &x: " << &c_0 << " , &rcx: " << &c_1 << std::endl;

    // Arrays
    const char name[] = "R. N. Briggs";
    std::cout << "array:: " << name << " &:" << &name << std::endl;

    auto arr_1 = name; // const char *
    std::cout << "auto array:: " << arr_1 << " &:" << &arr_1 << std::endl;

    auto &arr_2 = name; // const char &
    std::cout << "auto &array:: " << arr_2 << " &:" << &arr_2 << std::endl;

    // Functions

    // void someFunction(int, double);
    // auto func_1 = someFunction(); // void (*)(int, double)
    // auto &func_2 = someFunction(); // void (&)(int, double)

    // if auto return type in c++14:
    // auto createInitList()
    //{
    //   return {1, 2, 3}; //ERROR
    //}

    // This is possible
    //     auto summ(int a, int b)
    // {
    //     return a + b;
    // }

    // {} initializer_list
    auto il_1 = {27}; // std::initializer_list<int>
    auto il_2{27};    // std::initializer_list<int> (in c++17 -> int)
    // auto il_3{1, 2, 3.0}; // ERROR

    // Lambda (C++14)
    std::vector<int> v;

    auto resetV =
        [&v](const auto &newValue)
    { v = newValue; };

    // resetV({ 1, 2, 3 }); // ERROR

    const auto &asd = 1; // Is possible because the compiler create itself an const int value, and asd
                         // take reference to this
    
    // auto &asd_2 = 1; // This isn't posssible ERROR
    std::cout<<"const auto& = rv: "<<asd<<" &:"<<&asd;
}