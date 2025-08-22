#include "client.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Client c(8080);
    c.new_connection();
    while(1){
        string message;
        cin>>message;
        c.send_message(message);
        
        c.receive_message();

    }
    return 0;
}