#include <iostream>
#include <set>
#include <assert.h>
#include "bp.hpp"


using namespace std;

//Pool of registers

class Registers{
    set<string>* registersSet;

    Registers(){
        registersSet = new set<string>();
        int i=0;
        while(i!=8){
            registersSet->insert("$t"+to_string(i));
            registersSet->insert("$s"+to_string(i));
            i++;
        }
        registersSet->insert("$t"+to_string(8));
        registersSet->insert("$t"+to_string(9));
    }

    ~Registers(){}

    string allocate(){
        assert(registersSet->size()!=18);
        string reg = *(registersSet->begin());
        registersSet->erase(reg);
        return reg;
    }

    void release(string reg){
        assert(registersSet->find(reg)==registersSet->end());
        registersSet->insert(reg);
    }

    unsigned long long int numOfValidRegisters(){
        return registersSet->size();
    }

};

/***************Aritmetics calculations*****************/


void addu (unsigned int num1, unsigned int num2){
    string Rsrc = registersSet.allocate();
    string Rdest = registersSet.allocate();
    string command = "addu" + Rdest + "," + Rsrc + "," + to_string(num2);
    //add emit
}


void subu (unsigned int num1, unsigned int num2){
    string Rsrc = registersSet.allocate();
    string Rdest = registersSet.allocate();
    string command = "subu" + Rdest + "," + Rsrc + "," + to_string(num2);
    //add emit
}

void mulo (unsigned int num1, unsigned int num2){
    string Rsrc = registersSet.allocate();
    string Rdest = registersSet.allocate();
    string command = "mulo" + Rdest + "," + Rsrc + "," + to_string(num2);
    //add emit
}

void divu (unsigned int src1, unsigned int src2){
    if(src2==0) {
        printf("Error division by zero\n");
        exit(0);
    }
    string Rsrc1 = registersSet.allocate();
    string Rsrc2 = registersSet.allocate();
    string command = "divu" + Rsrc1 + "," + Rsrc2;
    //add emit

}

void move (unsigned int src, unsigned int dest){
    string Rsrc = registersSet.allocate();
    string Rdest = registersSet.allocate();
    string command = "move" + Rdest + "," + Rsrc;
    //add emit
}




int main() {
    cout << "Hello, World!" << endl;
    return 0;
}