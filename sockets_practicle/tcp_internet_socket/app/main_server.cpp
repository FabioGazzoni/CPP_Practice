#include "server.h"
#include <iostream>

using namespace std;

int main(){
    Server s(8080);
    s.new_connection();
    while(1){
        s.receive_data();
        s.response_data("Respondiendo", sizeof("Respondiendo"));
    }
    return 0;
}