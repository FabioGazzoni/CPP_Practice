#include "server.h"
#include <iostream>

using namespace std;

int main(){
    Server s(8080);
    s.new_connection();
    
    return 0;
}