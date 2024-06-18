#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cash {100}, option_input {0};
    
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
                  40, // Banana
                  //ADD AS MUCH ITEM PRICE AS YOU WANT HERE
                };
                
                vector <string> shop_options
                {
                  "Apple",
                  "Orange", 
                  "Mango",
                  "Banana",
                  // ADD AS MUCH ITEM AS YOU WANT HER
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
                                
                                final_order = "x" + to_string(item_quantity) + " " + shop_options.at(item_recorded) + " >> " + prefix + to_string(result);
                            
                                order_list.push_back(final_order);
                            }   
                            else
                                cout << endl << "Could not complete the transaction." << endl;
                            break;
                        }
                        case false:
                            cout << "Not able to buy less then 0 " << shop_options.at(item_recorded) << ".";
                            break;
                        }
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
            break;
        }
    } while (option_input != 4 && option_input != 4);
    
    return 0;
}
