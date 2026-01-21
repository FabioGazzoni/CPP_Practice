#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

template <typename T>
void print_container(T container)
{
    for (auto &c : container)
    {
        cout << c << ", ";
    }
    cout << endl;
}

int main()
{

    set<int> numbers;

    numbers.insert(5);
    numbers.insert(27);
    numbers.insert(32);
    cout << "set numbers wit 5, 27, 32: ";
    print_container(numbers);

    numbers.insert(2);
    cout << "set numbers before add number 2: ";
    print_container(numbers);

    cout << "possible tree:\n      5\n     / \\\n   27   2\n  /\n32" << endl;

    numbers.insert(10);
    cout << "set numbers before add number 10: ";
    print_container(numbers);
    cout << "possible tree:\n      5\n     / \\\n   27   2\n  / \\\n32  10" << endl;

    vector<char> letters{'A', 'B', 'C'};
    map<char, int> ascii_m;

    for (auto &l : letters)
    {
        ascii_m.insert(pair<char, int>(l, static_cast<int>(l)));
    }
    cout<<"The ascii numbers form map<char, int> are: ";
    for(auto &l : letters)
    {
        cout<<"<"<<l<<", "<<ascii_m.at(l)<<">, ";
    }
    cout<<endl;

    return 0;
}
