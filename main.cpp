#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string welcome_message {"Welcome to the hotel. Please enter an option to get started!"};
    
    vector <string> options
    {
      "",
      "Hotel shop.",
      "List down your order.",
      "Top-up your cash.",
      "Check level and exp.",
      "Quit the menu.",
    };
    
    vector <int> level_exp
    {
        0, // Level 0 - 0 exp
        0, // Level 1 - 0 exp
        0, // Level 2 - 0 exp
        0, // Level 3 - 0 exp
        0, // Level 4 - 0 exp
        0, // Level 5 - 0 exp
        0, // Level 6 - 0 exp
        0, // Level 7 - 0 exp
        0, // Level 8 - 0 exp
        0, // Level 9 - 0 exp
        0, // Level 10 - NO LIMIT EXP
    };
    
    int cash {0}, option_input {0}, total_exp {0}, level {0};
    
    const int max_level {10};
    
    const char prefix {'$'};
    
    vector <string> order_list {};
    do
    {
        if (level < max_level) 
        {
            if (total_exp >= level_exp.at(level))
            {
                total_exp -= level_exp.at(level);
                level += 1;
                cout << "You've leveled up" << endl;
            } else {
                cout << "You do not have enough EXP to level up." << endl;
            }
        } else {
            cout << endl << "You are at the final level." << endl;
        }
    
        cout << welcome_message << endl << endl;
        
        for (int i {0}; i < static_cast<signed int> (options.size()); i++)
            if (i == 0)
                cout << "===--- OPTIONS ---===" << endl;
            else
                cout << i << ") " << options.at(i) << endl;

        cout << "Your cash: " << prefix << cash << endl;
        
        if (level < max_level)
            cout << "Here is your current level: " << level << ". Next level: " << level + 1 << "." << " Required exp: " << level_exp.at(level);
        else
            cout << "Here is your current level: " << level << ". You are at the last level." ;
            
        cout << " Remaining EXP: " << static_cast<double> (total_exp);
        cout << endl << "Enter an option: ";
        cin >> option_input;
        
        switch(option_input)
        {
            case 1:
            {
                int result {0}, item_quantity {0}, item_recorded {0};
                
                vector <int> item_prices 
                {
                  10, // Apple
                };
                
                vector <string> shop_options
                {
                  "Apple",
                };
                
                cout << endl << "===--- Welcome to the hotel shop ---===" << endl;
                
                for (int i {0}; i < static_cast<signed int> (item_prices.size()); i++)
                    cout << i << ") " << shop_options.at(i) << " / " << prefix << item_prices.at(i) << endl;
                
                cout << "Enter an option: ";
                cin >> option_input;
            
                if (option_input <static_cast<signed int>(shop_options.size()))
                {
                    
                    result = item_prices.at(option_input);
                    item_recorded = option_input;
                    
                    cout << "How many " << shop_options.at(option_input) << "s do you want to buy? ";
                    cin >> option_input;
                    item_quantity = option_input;
                    
                    bool is_quantity {false};
                    is_quantity = ((option_input > 0 ? true : false));
                    
                    switch(is_quantity)
                    {
                        case true:
                        {
                            result *= item_quantity;
                            cout << "===--- Final confirmation ---===" << endl;
                            
                            if (item_quantity > 1)
                                cout << "You are buying " << item_quantity << " " << shop_options.at(item_recorded) << "s." << endl;
                            else
                                cout << "You are buying " << item_quantity << " " << shop_options.at(item_recorded) << "." << endl;
                            
                            cout << "Your total will be: " << prefix << result;
                            
                            if (cash >= result)
                            {
                                cash -= result;
                                cout << endl << "Transaction complete.";
                                
                                string final_order {""};
                                
                                final_order = "x" + to_string(item_quantity) + " " + shop_options.at(item_recorded) + " for " + prefix + to_string(result);
                            
                                order_list.push_back(final_order);
                                
                                total_exp += 100;
                                cout << "You have just recieved 100 exp for this transaction" << endl;
                            }   
                            else
                                cout << endl << "Could not complete the transaction." << endl;
                            break;
                        }
                        case false:
                            cout << "Not able to buy less then 0 " << shop_options.at(item_recorded) << ".";
                            break;
                        } break;
                    }
                    else {
                        cout << "Invalid input." << endl;
                    }
                }
                break;
            case 2:
                if (order_list.empty())
                {
                    cout << "You have not ordered anything yet." << endl;
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
            } 
            case 4:
                // check level
                cout << "===--- Levels ---===" << endl;
                
                    for (auto i {1}; i <= max_level; i++)
                    {
                        if (level > i)
                            cout << i << ")" << " Level: " << i << " (completed)." << endl;
                        else if (level == i && level != max_level)
                            cout << i << ")" << " Level: " << i << " (You are here)." << endl;
                        else if (level == max_level)
                            cout << i << ")" << " Level: " << i << " (You are at the max level)." << endl;
                        else
                            cout << i << ")" << " Level: " << i << " (requires) " << level_exp.at(i) << "." << endl;
                    }
                break;
            case 5:
                cout << "You've quit the program" << endl;
                break;
            default:
                cout << "Unknown command." << endl;
                break;
        }
    } while (option_input != 5 && option_input != 5);
    
    return 0;
}
