#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "automenu.hpp"

using namespace am;

Menu::Menu(std::vector<MENU_ITEM> init, std::string title){
    options = init;
    this->title = title;
}

Menu::Menu(){
    options = std::vector<MENU_ITEM>();
    this->title = "AUTO MENU";
}

void Menu::addItem(MENU_ITEM it){
    options.push_back(it);
}

void Menu::operator=(Menu src){
    this->options = src.options;
    this->title = src.title;
    this->CLEAR_ON_FINISH = src.CLEAR_ON_FINISH;
}

size_t Menu::once() const{
    int option = 0;
    auto addLine = [=](){
        for(int i=0; i<50; i++)
            std::cout<<"=";
        std::cout<<'\n';
    };
    auto printItem = [=](int index, std::string desc){
        std::cout << "\t"<<index+1<< "   -   "<<desc<< std::endl;
    };

    addLine();
    std::cout<<std::endl<<title<<'\n';
    addLine();
    std::cout << std::endl;
    for(int i=0; i<options.size(); i++){
        printItem(i, options[i].second);
    }
    printItem(options.size(), "QUIT MENU");
    addLine();
    std::cout<<"Enter the option you want to select: ";
    std::cin>>option;
    callFunc(option);
    return option;
}

void Menu::run() const{
    char exit = 'n';
    const auto getValiOpt= [](){
        char cont = 'y';
        do{
            std::cout<<"\nAre you sure you want to quit(y/n)? ";
            std::cin>>cont;
        }
        while(cont!='y'&&cont!='Y'&&cont!='n'&&cont!='N');
        std::cout<<"Exiting..";
        return cont;
    };

    if(CLEAR_ON_FINISH){
        system("clear");
    }
    
    while(exit != 'y'||exit != 'y'){
        try{
            size_t opt = once();
            if(opt == options.size()+1){
                exit = getValiOpt();
                continue;
            }
        }
        catch(invalid_option e){
            std::cout<<e.what();
        }
        if(CLEAR_ON_FINISH){
            std::cout<<"\nPress ENTER to continue...";
            std::cin.ignore(INT64_MAX,'\n');
            std::cin.get();
            system("clear");
        }
    }
}

void Menu::callFunc(std::size_t opt) const{
    if(opt>options.size()+1||opt<1){
        throw invalid_option(opt,options.size());
    }
    if(opt == options.size()+1){
        return ;
    }
    options[opt-1].first(); 
}

void Menu::setClear(bool clear){
    CLEAR_ON_FINISH = clear;
}

void Menu::setTitle(std::string title){
    this->title = title;
}
