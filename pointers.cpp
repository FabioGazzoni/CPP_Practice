#include <iostream>
#include <functional>
#include <algorithm>
#include <stdexcept> 


using namespace std;

void say_hello() {
    cout << "Hello, World!" << endl;
}

/**
 * Fuction whit parameter is a pointer to other function
 */
void call_fuction(function<void()> func){
    func();
}

void print_number(int number){
    cout << number << endl;
    if (number == 0)
    {
        throw logic_error("Number 4 is not allowed");
    }
    
}

int main(){
    // Pointer to function
    function<void()> func = say_hello;

    func();

    // Call fuction whit parameter is a pointer to other function
    call_fuction(func);

    // For each example
    vector numbers{1, 123, 2, 3, 4,0, 5};
    try{
        for_each(numbers.begin(),numbers.end(), print_number);
    } catch (const logic_error& e) {
        cerr << "Error: " << e.what() << endl;
        exit(EXIT_FAILURE);
    } catch (...) {
        cerr << "An unexpected error occurred." << endl;
        exit(EXIT_FAILURE);
    }

    cout<< "End of program" << endl;

    return 0;
}