#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>

using namespace std;

template <typename T>
void print_container(T container)
{
    for (auto &e : container)
    {
        cout << e << ", ";
    }
    cout << endl;
}

template <typename T>
void print_container_directions(T& container)
{
    for (auto &c : container)
    {
        cout << "&" << &c << ", ";
    }
}

int main()
{
    vector<string> names{"Julian", "Ambar", "Franchesca", "Milena"};
    cout << "The vector of names is: ";
    print_container(names);

    names.push_back("Benicio");
    cout << "The vector of names after add new name: ";
    print_container(names);

    array<int, 5> numbers{10, 11, 13, 12};
    cout << "The array of numbers is: ";
    print_container(numbers);

    numbers.at(4) = 17;
    cout << "The array of numbers after modify 5 element: ";
    print_container(numbers);

    
    list<string> things{"Car", "TV", "Bed", "Notebook"};
    cout << "The list of things is: ";
    print_container(things);

    long a = 1000; // guarantees that the new element of list is not continuous of the las element in it

    things.push_back("Keyboard");
    cout << "The list of things after add new thing: ";
    print_container(things);


    cout << "names[";
    print_container_directions(names);
    cout << "]" << endl;

    cout << "things[";
    print_container_directions(things);
    cout << "]" << endl;

    return 0;
}
