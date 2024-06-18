#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cash {0}, option_input {0};
    
    const char prefix {'$'};
    
    string welcome_message {"Welcome to the hotel. Please enter an option to get started!"};
    
    vector <string> options
    {
      "===--- OPTIONS ---===",
      "Hotel shop.",
      "List down your order.",
      "Top-up your cash.",
      "Quit the menu.",
    };
    
    vector <string> order_list {};
    
    do
    {
        cout << welcome_message << endl << endl;
        
        for (int i {0}; i < static_cast<signed int> (options.size()); i++)
            if (i == 0)
                cout << options.at(i) << endl;
            else
                cout << i << ") " << options.at(i) << endl;

        cout << "Your cash: " << prefix << cash << endl;
        cout << endl << "Enter an option: ";
        cin >> option_input;
        
        // Handling option input
        switch(option_input)
        {
            case 1:
            {
                int result {0}, item_quantity {0}, item_recorded {0};
                
                vector <int> item_prices 
                {
                  10, // Apple
                  20, // Orange
                  30, // Mango
                };
                
                vector <string> shop_options
                {
                  "Apple",
                  "Orange", 
                  "Mango",
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
                            result *= option_input;
                            cout << "You are buying x" << item_quantity << " " << shop_options.at(item_recorded) << endl;
                            cout << "Your total will be: " << prefix << " " << result;
                            break;
                        }
                        case false:
                            cout << "Not able to buy less then 0 " << shop_options.at(item_recorded);
                            break;
                        }
                    }
                }
                break;
            case 2:
                if (order_list.empty()) 
                {
                    cout << "You have not ordered anything yet." << endl;
                } else {
                    cout << "===--- Order history ---===" << endl;
                    for (auto ol: order_list)
                    {
                        cout << ol << endl;
                    }
                }
                break;
            case 3:
            {
                cout << "How much cash do you want to top up? ";
                cin >> option_input;
                
                if (option_input <= 0)
                    cout << "Can't top up less then " << prefix << 0 << " dollars." << endl;
                else
                    cash += option_input;
                    cout << "Updated cash: " << prefix << cash << endl;
            } 
            break;
            default:
                option_input = 4;
                break;
        }
    } while (option_input != 4 && option_input != 4);
    
    return 0;
}
