#include <iostream>
#include <vector>

using namespace std;

struct Level {
    int total_exp {5};
    int level {0};
    const int max_level {10};
    int base_exp {150};
    vector <int> level_exp
    {
        5, // Level 0 - 0 exp
        6, // Level 1 - 0 exp
        10, // Level 2 - 0 exp
        20, // Level 3 - 0 exp
        30, // Level 4 - 0 exp
        40, // Level 5 - 0 exp
        50, // Level 6 - 0 exp
        80, // Level 7 - 0 exp
        150, // Level 8 - 0 exp
        155, // Level 9 - 0 exp
        158, // Level 10 - NO LIMIT EXP
    };
};

struct Hotel {
    const string welcome_message {"Welcome to the hotel. Please enter an option to get started!"};
    
    vector <string> options
    {
      "",
      "Hotel shop.",
      "List down your order.",
      "Top-up your cash.",
      "Check level and exp.",
      "Quit the menu.",
    };  
};

int main()
{
    Hotel hotel;
    Level level;
    
    bool is_looping {true};
    
    int cash {0}, option_input {0};
    
    const char prefix {'$'};
    
    vector <string> order_list {};
    
    do
    {
         if (level.level < level.max_level) 
        {
            if (level.total_exp >= level.level_exp.at(level.level))
            {
                level.total_exp -= level.level_exp.at(level.level);
                level.level += 1;
                cout << ">> You advanced to level " << level.level << endl;
            }
        }
        
        cout << hotel.welcome_message << endl << endl;
        
        for (int i {0}; i < static_cast<signed int> (hotel.options.size()); i++)
            if (i == 0)
                cout << "===--- OPTIONS ---===" << endl;
            else
                cout << i << ") " << hotel.options.at(i) << endl;

        cout << "===--- Stats ---===" << endl;
        cout << "Your cash: " << prefix << cash << endl;
        cout << ">> Your level: " << level.level << "/" << level.level_exp.size() - 1 << " Remaining EXP: " << static_cast<double> (level.total_exp) << endl;
        cout  << "Enter an option: ";
        cin >> option_input;
        
        switch(option_input)
        {
            case 1:
            {
                int result {0}, item_quantity {0}, item_recorded {0};
                
                vector <int> item_prices
                {
                    // ADD UNLIMITED ITEM PRICES HERE
                    3,
                    5,
                    7,
                };
                
                vector <string> shop_options
                {
                    // ADD UNLIMITED ITEMS HERE
                    "Apple",
                    "Pear",
                    "Mango",
                };
                
                cout << endl << "===--- Welcome to the hotel shop ---===" << endl;
                
                if (!item_prices.empty() && !shop_options.empty())
                {
                    for (int i {0}; i < static_cast<signed int> (item_prices.size()); i++)
                        cout << i << ") " << shop_options.at(i) << " / " << prefix << item_prices.at(i) << endl;
                } else {
                    cout << endl << "Hotel shop is not available right now." << endl;
                    break;
                }
                
                cout << "Enter an option: (You need to enter a number based on the item you want to buy): ";
                
                cin >> option_input;
                
                // Fixed an error here
                
                if (option_input >= 0 && option_input < static_cast<signed int> (item_prices.size()))
                {
                    result = item_prices.at(option_input);
                    
                item_recorded = option_input;
                    
                cout << "How many " << shop_options.at(option_input) << "s do you want to buy? ";
                cin >> option_input;
                item_quantity = option_input;
                    
                result *= item_quantity;
                            
                if (item_quantity >= 1) {
                    cout << "You are buying " << item_quantity << " " << shop_options.at(item_recorded) << "s." << endl;
                } else { break; }
                
                    cout << "===--- Final confirmation ---===" << endl;
                    cout << "Your total will be: " << prefix << result;
                        
                    if (cash >= result)
                    {
                        cash -= result;
                        cout << endl << "Transaction complete.";
                                
                        string final_order {""};
                                
                        final_order = "x" + to_string(item_quantity) + " " + shop_options.at(item_recorded) + " for " + prefix + to_string(result);
                            
                        order_list.push_back(final_order);
                                
                        level.total_exp += level.base_exp;
                        cout << "You have just recieved " << level.base_exp << " exp for this transaction." << endl;
                    }
                    else
                        cout << endl << "Error: Could not complete the transaction. Please top up more cash." << endl;
                    } else {
                        cout << "Error: There is no such option number."<<endl;
                    }
            } break;
            case 2:
                if (order_list.empty())
                {
                    cout << "Error: You have not ordered anything yet." << endl;
                } else {
                    cout << endl << "===--- Order history ---===" << endl;
                    for (int i {0}; i < static_cast<signed int> (order_list.size()); i++)
                            cout << i << ") " << order_list.at(i) << endl;
                    cout << endl;
                }
                break;
            case 3:
            {
                cout << "How much cash do you want to top up? ";
                cin >> option_input;
                
                if (option_input <= 0) 
                {
                    cout << "Can't top up less then " << prefix << 0 << " dollars." << endl;
                }
                else {
                    cash += option_input;
                }
            } break;
            case 4:
            {
                cout << "===--- Levels ---===" << endl;
                
                for (auto i {1}; i <= level.max_level; i++)
                {
                    if (level.level > i)
                        cout << i << ")" << " Level: " << i << " (completed)." << endl;
                    else if (level.level == i && level.level != level.max_level)
                        cout << i << ")" << " Level: " << i << " (You are here)." << endl;
                    else if (level.level == level.max_level)
                        cout << i << ")" << " Level: " << i << " (You are at the max level)." << endl;
                    else
                        cout << i << ")" << " Level: " << i << " (requires) / " << level.level_exp.at(i) << "." << endl;
                }
                cout << endl << level.level_exp.at(level.level) - level.total_exp << " exp to reach to the next level." << endl;
            }
                break;
            case 5:
            {
                cout << "You've quit the program." << endl;
                is_looping = false;
                break;
            }
            default:
                cout << "Unknown command." << endl;
                break;
        }
    } while (is_looping);
    
    return 0;
}
