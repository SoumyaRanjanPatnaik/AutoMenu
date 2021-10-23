# Introduction

Auto Menu is an open-source library to automatically generate a text based interface for your programs and libraries.

# Installation

Clone the repository and copy the `src/automenu.hpp` and `src/automenu.cpp` files to your working directory.

# Usage

## Importing

To import automenu into your project, run add the following to the top of the program.

```cpp
#include<path_to_dir/automenu.hpp>
```

The library is inside a namespace `am`. To access the contents of the library, either use scope resolution operator `am::`, or add the following to your code.

```cpp
using namespace am;
```

## Creating a menu

1. Create an object of Menu class

   ```cpp
   am::Menu nameOfMenu;
   ```

1. Set title (optional)

   ```cpp
   nameOfMenu.setTitle("Title");
   ```

1. Create menu entries 
   Each enty is of type `std::par<void(*)(),std::string>`. For ease of use, a typedef `am::MENU_ITEM` exists. `void(*)()` is the pointer to a function with no arguments and return type void. The second parameter is a `std::string` that storers the description for the entry. To pass the function, you may also use lambda functions. 
   
   **Example:**

   ```cpp
   am::MENU_ITEM item1= {[](){std::cout<<"Hello World";}, "sayHello"};  
   am::MENU_ITEM item2 = {functionPointer, "Using Function Pointer"}
   std::pair<void(*)(),std::string> item3 = {[](){
       std::cout<<"Using lambda function";
   },"Lamda Function"}
   ```

1. Add menu entries  
   There are two ways to add menu items:  
   - Individually, using `am::Menu::addItem` function.
     ```cpp
     am::newMenu.addItem(nameOfEntry);
     ```
   - Using `vector<am::MENU_ITEM>`  
    vector<am::MENU_ITEM> menuVector = {item1, {functionPointer, description}, {[](){std::cout<<"Lamda";},"Lamda"}};
    ```cpp
    am::newMenu.bulkAdd(menuVector);
    ```
1. Set Clear (optional):  
   If you want the output to be erased after execution of an option, you need to add the following to your code.  
   ```cpp
   am::newMenu.setClear(true);
   ```
1. Run the menu once:  
   ```cpp
   am::newMenu.once();
   ```
1. Run menu loop:  
   ```cpp
   am::newMenu.run();
   ```
