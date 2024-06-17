#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    int cash {0};
    char option_input;
    
    string welcome_message {"Welcome to the hotel. Please enter an option to get started!"};
    
    vector <string> options
    {
      "===--- OPTIONS ---===",
      "A) Hotel shop.",
      "B) List down your order.",
      "C) Top-up your cash.",
      "Q) Quit the menu.",
    };
    
    vector <string> order_list {};
    
    do
    {
        cout << welcome_message << endl << endl;
        
        for (auto ops: options)
            cout << ops << endl;
        cout << endl;
        if (cash == 0)
            cout << "You have $" << cash << "." << " Please top up more.";
        else
            cout << "You have $" << cash << ".";
        cout << endl;
        cout << endl << "Enter an option: ";
        cin >> option_input;
        
        int item_amount {0};
        int result {0};
        
        // Handling option input
        switch(option_input)
        {
            case 'A':
            case 'a':
            {
                vector <string> shop_options
                {
                  "A) Apple / $10", "B) Orange / $20", "C) Mango / $30",
                };
                
                cout << endl << "===--- Welcome to the hotel shop ---===" << endl;
                for (auto so: shop_options)
                    cout << so << endl;
                    
                char input;
                
                cout << "Enter an option: ";
                cin >> input;
                
                switch(input)
                {
                    case 'A':
                    case 'a':
                    {
                        int apple {10};
                        
                        cout << "How many do you need: ";
                        cin >> item_amount;
                        
                        string final_order {};
                        final_order = "x" + to_string(item_amount) + " Apple(s)";
                        
                        result += item_amount * apple;
                        
                        cout << "Your total will be $" << result; 
                        
                        cout << endl << "Confirm : Y : N? ";
                        cin >> input;
                        
                        if (input == 'Y' || input == 'y')
                        {
                            bool is_cash {false};
                            is_cash = ((cash >= result ? true : false));
                        
                            switch (is_cash)
                            {
                                case true:
                                    cash -= result;
                                    order_list.push_back(final_order);
                                    cout << endl << "Purchase completed." << endl;
                                    break;
                                case false:
                                    cout << endl << "Purchase failed. Not enough funds." << endl;
                                    break;
                            }
                        }
                    } break;
                    case 'B':
                    case 'b':
                    {
                        int oranges {20};
                        
                        cout << "How many do you need: ";
                        cin >> item_amount;
                        
                        string final_order {};
                        final_order = "x" + to_string(item_amount) + " Oranges(s)";
                        
                        result += item_amount * oranges;
                        
                        cout << "Your total will be $" << result; 
                        
                        cout << endl << "Confirm : Y : N? ";
                        cin >> input;
                        
                        if (input == 'Y' || input == 'y')
                        {
                            bool is_cash {false};
                            is_cash = ((cash >= result ? true : false));
                        
                            switch (is_cash)
                            {
                                case true:
                                    cash -= result;
                                    order_list.push_back(final_order);
                                    cout << endl << "Purchase completed." << endl;
                                    break;
                                case false:
                                    cout << endl << "Purchase failed. Not enough funds." << endl;
                                    break;
                            }
                        }
                    } break;
                    case 'C':
                    case 'c':
                    {
                        int mango {30};
                        
                        cout << "How many do you need: ";
                        cin >> item_amount;
                        
                        string final_order {};
                        final_order = "x" + to_string(item_amount) + " Mango(s)";
                        
                        result += item_amount * mango;
                        
                        cout << "Your total will be $" << result; 
                        
                        cout << endl << "Confirm : Y : N? ";
                        cin >> input;
                        
                        if (input == 'Y' || input == 'y')
                        {
                            bool is_cash {false};
                            is_cash = ((cash >= result ? true : false));
                        
                            switch (is_cash)
                            {
                                case true:
                                    cash -= result;
                                    order_list.push_back(final_order);
                                    cout << endl << "Purchase completed." << endl;
                                    break;
                                case false:
                                    cout << endl << "Purchase failed. Not enough funds." << endl;
                                    break;
                            }
                        }
                    } break;
                }
                
            } break;
            case 'B':
            case 'b':
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
            case 'C':
            case 'c':
            {
                int input {0};
                
                cout << "How much cash do you want to top up? ";
                cin >> input;
                
                if (input <= 0)
                    cout << "Can't top up the amount!" << endl;
                else
                    cash += input;
            } break;
            case 'Q':
            case 'q':
                cout << "Qutting the menu.";
                break;
        }
    } while (option_input != 'Q' && option_input != 'q');
    
    return 0;
}