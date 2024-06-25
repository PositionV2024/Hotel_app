# Update logs
<details>
  <summary>Remove an item from the shopping cart</summary>
  <img src=https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/Screenshot%202024-06-26%20054728.png alt="Shopping cart" width="900" height="400">
  <img src=https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/Screenshot%202024-06-25%20032404.png alt="After removing mango from the shopping cart" width="900" height="400">
</details>

<details>
  <summary>Level</summary>
    Each level contains a certain amount of experience needed to level up. In the future, I can add more functionality to it.
<img src=https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/Screenshot%202024-06-24%20093236.png alt="Level" width="400px" height="400">
</details>

<details>
  <summary>Shopping cart</summary>
    <img src=https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/Screenshot%202024-06-24%20094719.png alt="Shopping cart" width="900px" height="400">
</details>

<details>
  <summary>Order history</summary>
  <img src=https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/Screenshot%202024-06-24%20120915.png alt="Order history" width="900px" height="400">
</details>

### Details of the project
---
This is meant to be a hobby project. When this application is executed in the IDE (Integrated Development Environment), you can choose four options. You can either: explore the hotel shop; look up your order history; top up more cash to your account; or exit the program. Before choosing the first option, you will need to top up more cash in your account. By default, this is set to 0. After you have successfully topped up your account, you are ready to make a purchase. Head over to the "Hotel Shop" option to explore various products. Each product will have its own price; you can purchase as much as you want, as long as the funds are sufficient. After you have purchased an item, you can check what you have bought. Head over to the "List down your order." option to see what you have bought; this will show you how much you have spent on each item.

<details>
	<summary>Part of the code</summary>
	

                    if (option_input == 1)
                {
                    if (item_quantity >= 1)
                    {
                        final_order = "x" + to_string(item_quantity) + " " + shop_options.at(item_recorded) + "(s)" + " / " + prefix + to_string(result);
                        
                        shopping_cart.push_back(final_order);
                        
                        item_names.push_back(shop_options.at(item_recorded));
                        items.push_back(item_quantity);
                        item_prices_.push_back(result);
                        
                        cout << "Successfully added x" << item_quantity << " " << shop_options.at(item_recorded) << " to shopping chart." << endl;
                        
                        hotel.options.at(5) = "Check shopping cart (" + to_string(shopping_cart.size()) + ")";
                    } else {
                        cout << "Error: Couldn't add to basket." << endl;
                    }
                }

</details>

#### Short demo
![Watch the video](https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/ezgif.com-effects.gif)
#### Video
[Full video](https://youtu.be/_vXoWpodXsI?si=GQls5ioPoWfY30U3) (1:20)
#### Made by Clarence
