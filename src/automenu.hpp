#ifndef AUTO_MENU_202110_c8758f4c
#define AUTO_MENU_202110_c8758f4c
#include <cstddef>
#include <vector>
#include <string>
#include <exception>
namespace am {
    /**
     * Contains function and description for the item.
     * Data Members:
     * first -- void(*)(): Menu item function with no parameters and returning void.
     * second -- std::string: Menu Item Descriptioin
     */
    typedef std::pair<void(*)(), std::string> MENU_ITEM;
    // Exceptions
    class invalid_option: public std::exception{
        std::string message;
    public:
        size_t opt;
        size_t maxRange;
        invalid_option(size_t max, size_t opt){
            this->opt = opt;
            message = "\nInvalid option: should be within range 1 to "+std::to_string(maxRange)+", was - "+std::to_string(opt);
        }
        const char * what() const noexcept override{
            return message.c_str();
        }
    };
    class Menu{
    public:
        // default constructor
        Menu();
        // Initialize Menu with std::vector<MENU_ITEM>
        Menu(std::vector<MENU_ITEM> init, std::string title);
        // Copy Constructor
        Menu(Menu &src):
            options(src.options),
            title(src.title),
            CLEAR_ON_FINISH(src.CLEAR_ON_FINISH)
        {}
        // Add new MENU_ITEM
        void  addItem(MENU_ITEM it);
        // Run menu once
        size_t once() const;
        // Run menu loop
        void run() const;
        // Set menu title
        void setTitle(std::string title);
        // set clear screen
        void setClear(bool clear);
        // Assignment Operator overloading
        void operator=(Menu src);
        //Call function
        void callFunc(std::size_t option) const;
        // Add Menu Items In Bulk
        void bulkAdd(std::vector<MENU_ITEM> bulk);
        
    private:
        std::vector<MENU_ITEM> options;
        std::string title;
        bool CLEAR_ON_FINISH;
    };
}
#endif
