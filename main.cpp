#include <iostream>
#include <string>
#include <sstream>

#include "List.hpp"
#include "Node.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;
int main(){
    List2<int> list;
    list.push_front(1);
    list.push_back(2);
    std::cout << list[0] << std::endl;

    Queue<int> queue;
    queue.pop();
    queue.push(1); 
    queue.push(2);
    queue.pop();
    queue.search(2);

    /*cout << "Enter one of the commands:" << endl;
    cout << "\tFirst letter struct type (M, L, Q, S, H, T);" << endl;
    cout << "\tSET/PUSH/INSERT - add element;" << endl;
    cout << "\tDEL/POP - remove element;" << endl;
    cout << "\tGET - get element;" << endl;
    cout << "\tPRINT - print the struct;" << endl;
    cout << "\tEXIT - exit the program;" << endl << endl;

    while(true){
        string input;
        getline(cin, input);
        istringstream iss(input);
        char structType;
        string command;
        iss >> structType;
        iss >> command;

        if (structType == 'M') {
            if(command == "PUSH"){
                /*string name_product; пример считывания далее
                iss >> name_product;

                add(name_product, count_product, cell, wildberries);
            } else if(command == "DEL"){
                
            } else if(command == "GET"){
                
            }


        } else if (structType == 'L') {
            if(command == "PUSH"){

            } else if(command == "DEL"){
                
            } else if(command == "GET"){
                
            }

        } else if (structType == 'Q') {
            if(command == "PUSH"){

            } else if(command == "POP"){
                
            } else if(command == "GET"){
                
            }

        } else if (structType == 'S') {
            if(command == "PUSH"){

            } else if(command == "POP"){
                
            } else if(command == "GET"){
                
            }

        } else if (structType == 'H ') {
            if(command == "SET"){

            } else if(command == "DEL"){
                
            } else if(command == "GET"){
                
            }

        } else if (structType == 'T') {
            if(command == "INSERT"){

            } else if(command == "DEL"){
                
            } else if(command == "GET"){
                
            }

        } else if (structType == 'P' && command == "RINT") {


        } else if (structType == 'E' && command == "XIT") {
            return 0;

        } else {
            cout << "Wrong input, sorry, but you will not pass!!!" << endl;
        } 
    }
    return 0;*/
}