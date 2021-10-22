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
        cout<<square(5);
    };
    auto sayHi = [](){
        cout<<"Enter Your Name: ";
        string name;
        getline(cin,name);
    };
    newMenu.setTitle("Test AutoMenu");
    const vector<MENU_ITEM> itemlist{
        {squareFunc,"Print square"},
        {test, "Print Hello World"},
        {test, "Print Hello World"},
    };
    newMenu.addItem({squareFunc,"Print square"});
    newMenu.addItem({test, "Print Hello World"});
    newMenu.addItem({test, "Print Hello World"});
    newMenu.setClear(true);
    newMenu.run();
}
