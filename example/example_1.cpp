#include <iostream>
#include <string>
#include <vector>
#include "../src/automenu.hpp"

void test(){
    std::cout<<"Printing Hello World...";
}

int square(int x){
    return x*x;
}

int main(){
    using namespace am;
    using namespace std;
    Menu newMenu;
    auto squareFunc = [](){
        int x;
        cout<<"Enter the number you want to square: ";
        cin>>x;
        cout<<"The Sqare of the number is: "<<square(x);
    };
    auto sayHi = [](){
        cout<<"Enter Your Name: ";
        string name;
        getline(cin>>ws,name);
        cout<<"Hi! "<<name;
    };
    newMenu.setTitle("Example AutoMenu: Add entries one by one");
    newMenu.addItem({squareFunc,"Print square of a number"});
    newMenu.addItem({test, "Print Hello World"});
    newMenu.addItem({sayHi, "Say Hi!"});
    newMenu.setClear(true);
    newMenu.run();
}
