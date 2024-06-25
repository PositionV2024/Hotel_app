# Update logs
<details>
  <summary>Remove an item from the shopping cart</summary>
  <img src=https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/Screenshot%202024-06-25%20032340.png alt="Shopping cart" width="900" height="400">
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
  A struct is meant to keep all the relevant variables together.
struct Level {
An int means an integer (A whole number). This will track how many exp does the user has.
	int total_exp {0};
This will track the user’s level.
	int level {4};
A const keyword is there to keep the value read-only therefore, you can’t change or assign a new value to the variable.
	const int max_level {20};
This is how much exp the application would give you for every completed transaction.
	int base_exp {100};
    A vector is similar to an arraylist. A vector can store a collection of data. For this example, I have a collection of ints. Ints is a data type that can only store a whole number. A vector or an arraylist begins from index 0.
	vector <int> level_exp
	{
    	5, // Level 0
    	6, // Level 1
    	10, // Level 2
    	20, // Level 3
    	30, // Level 4
    	40, // Level 5
    	50, // Level 6
    	80, // Level 7
    	150, // Level 8
    	155, // Level 9
    	158, // Level 10
    	158, // Level 11
    	158, // Level 12
    	158, // Level 13
    	158, // Level 14
    	158, // Level 15
    	158, // Level 16
    	158, // Level 18
    	158, // Level 19
    	158, // Level 20
	};
};
</details>

#### Short demo
![Watch the video](https://raw.githubusercontent.com/PositionV2024/Hotel_app/main/ezgif.com-effects.gif)
#### Video
[Full video](https://youtu.be/_vXoWpodXsI?si=GQls5ioPoWfY30U3) (1:20)
#### Made by Clarence
