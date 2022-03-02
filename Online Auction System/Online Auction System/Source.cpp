#include <iostream>
#include <string>

using namespace std;

const int SIZE = 100;
int i = 0, m = 0, c = 0, count1 = 0, count2 = 0;
struct Date
{
	int day, month, year;
};
struct members
{
	// information about members
	string name, delivery_address, email, phone_number, ID, password;
	int   points;
}member[SIZE];
struct items
{
	// information about items
	string category, status, ID1;
	Date show_date, delete_date, Sale_date;
	int item_number;
	float  price;
}market_place[SIZE];
struct message_box
{
	string item_name, ID_buyer, name_buyer, ID_seller;
	int item_num, Message_number;
	float price_item, Suggested_price;
	bool reply = false;
}message[SIZE];
struct top_category
{
	string cate;
	int counter[12] = { 0 };
}top_Category[SIZE];
struct feedback
{
	string comment, ID;
	int rate;
	bool done = false;
}array_feedback[SIZE];
void check_number(string& number, int x)     //function to check on number if it = x or no
{

	while (true)
	{

		if (number.size() == x)
		{
			break;
		}
		else
		{
			cout << " Invalid, please try again.\n";
			cin >> number;
		}
	}
}
void check_password(string& num)      //function to check on password if more than 7 digits or no 
{
	while (true)
	{
		if (num.size() > 7)
			break;
		else
		{
			cout << " Password must be at least 8 characters, please try again\n";
			cin >> num;
		}
	}
}
bool try_again = false, check = false, cheeck2 = false;
void new_account(members arr[])      //function to create a new account 
{
	cout << " Enter your name\n ";
	cin.ignore();
	getline(cin, arr[i].name);
	cout << "\n Enter your ID (10 numbers)\n ";
	cin >> arr[i].ID;
	check_number(arr[i].ID, 10);
	cout << "\n Enter your phone number\n ";
	cin >> arr[i].phone_number;
	check_number(arr[i].phone_number, 11);
	cout << "\n Enter your address\n ";
	cin.ignore();
	getline(cin, arr[i].delivery_address);
	cout << "\n Enter The Email\n ";
	cin >> arr[i].email;
	cout << "\n Enter The password\n ";
	cin >> arr[i].password;
	check_password(arr[i].password);
	i++;
	cout << "\t\t\t\twelcome, you now have an account on our system.\n ";
}
void login(members arr[])      //function to login on the system
{
	string Email, Password;
	int chosse_login;
	while (true)
	{
		cout << "\n Enter your Email\n ";
		cin >> Email;
		cout << "\n Enter your password\n ";
		cin >> Password;
		for (int j = 0; j < SIZE; j++)
		{
			if (Email == arr[j].email && Password == arr[j].password)
			{
				cout << "\n Name : " << arr[j].name << '\n';
				cout << " ID : " << arr[j].ID << '\n';
				cout << " Address : " << arr[j].delivery_address << '\n';
				cout << " Phone number : " << arr[j].phone_number << '\n';
				cout << " Points : " << arr[j].points << '\n';
				try_again = true;
				check = true;
			}
		}
		if (check == false)
		{
			cout << " There is a mistake.\n";
			while (true)
			{
				cout << " Do you want creat a new account or try again ?\n 1-create account\n 2-try again\n ";
				cin >> chosse_login;
				if (chosse_login == 1)
				{
					new_account(member);
					try_again = true;
					break;
				}
				else if (chosse_login == 2)
				{
					break;
				}
				else
					cout << " This offer is not allowed.\n";
			}
		}
		if (try_again)
			break;
	}
	check = false;
	try_again = false;
}
void get_expirydate(Date date, items arr1[], int x)     ////to calculate the end date
{
	date.day += 7;
	if (date.day > 30)
	{
		date.month += 1;
		date.day -= 30;
	}
	if (date.month > 12)
	{
		date.year += 1;
		date.month -= 12;
	}
	arr1[x].delete_date.day = date.day;
	arr1[x].delete_date.month = date.month;
	arr1[x].delete_date.year = date.year;
}
void fun_sell(items arr[], members arr2[])    //this function is to add items by the seller
{
	char chosse;
	string id;
	while (true)
	{
		try_again = false;
		check = false;
		cout << " enter your ID\n ";
		cin >> id;
		for (int j = 0; j < SIZE; j++)
		{
			if (id == arr2[j].ID)
			{
				cout << " Add items\n";
				cout << " Enter an item category\n ";
				cin >> arr[m].category;
				for (int k = 0; k < SIZE; k++)
				{
					if (arr[m].category != top_Category[k].cate)
					{
						top_Category[count1].cate = arr[m].category;
						count1++;
						break;
					}
				}
				cout << " Enter the price\n ";
				cin >> arr[m].price;
				cout << " Enter the date\n ";
				while (true)
				{
					cin >> arr[m].show_date.day >> arr[m].show_date.month >> arr[m].show_date.year;
					if ((arr[m].show_date.day > 0 && arr[m].show_date.day < 31) && (arr[m].show_date.month > 0 && arr[m].show_date.month < 13) && (arr[m].show_date.year > 2019))
					{
						break;
					}
					else
					{
						cout << "There is a mistake in the date, please enter the correct date\n ";
					}
				}
				get_expirydate(arr[m].show_date, arr, m);
				arr[m].item_number = m + 1;
				arr[m].status = "available";
				arr[m].ID1 = arr2[j].ID;
				m++;
				try_again = true;
				check = true;
			}

		}
		if (check == false)
		{
			cout << "Please enter the correct ID\n ";
		}
		if (try_again)
		{
			cout << " Do you want to add another item ?\n 1-Yes\n 2-No\n ";
			cin >> chosse;
			if (chosse == '1')
				continue;
			else if (chosse == '2')
				break;
		}

	}
	try_again = false;
	check = false;
}
void feedback(members arr[])      //this function to record feedback from members
{
	check = false;
	try_again = false;
	string ID_;
	int rating;
	cout << " Enter the ID you want to evaluate it\n ";
	while (true)
	{
		cin >> ID_;
		for (int j = 0; j < SIZE; j++)
		{
			if (ID_ == arr[j].ID)
			{
				array_feedback[count2].ID = arr[j].ID;
				cout << " Enter your rating for the user (1 to 5)\n ";
				while (true)
				{
					cin >> rating;
					if (rating == 1 || rating == 2)
					{
						array_feedback[count2].rate = rating;
						break;
					}
					else if (rating == 3 || rating == 4 || rating == 5)
					{
						array_feedback[count2].rate = rating;
						arr[j].points++;
						break;
					}
					else
						cout << " Please enter rating 1 to 5\n ";
				}
				cout << " Enter your comment, please\n ";
				cin.ignore();
				getline(cin, array_feedback[count2].comment);
				array_feedback[count2].done = true;
				cout << " Done\n";
				count2++;
				check = true;
				try_again = true;
			}
		}
		if (check == false)
		{
			cout << " Please enter the correct ID\n ";
		}
		if (try_again)
			break;
	}
	try_again = false;
	check = false;
}
void buying_request(items arr[], members arr2[])      // this function to send buying request 
{
	cheeck2 = false;
	string Id_buyer;
	int itemnumber;
	float suggested_price;
	char choose;
	while (true)
	{
		cout << " Do you want to buy or suggest a price to buy ?\n 1-buy\n 2-suggest a price to buy\n ";
		cin >> choose;
		if (choose == '1')
		{
			cout << " enter your ID\n ";
			cin >> Id_buyer;
			cout << "Enter the product number you want to buy it.\n ";
			cin >> itemnumber;
			for (int j = 0; j < SIZE; j++)
			{
				if (itemnumber == arr[j].item_number && arr[j].status == "available")
				{
					if (Id_buyer != arr[j].ID1)
					{
						message[c].item_num = arr[j].item_number;
						message[c].item_name = arr[j].category;
						message[c].ID_seller = arr[j].ID1;
						message[c].price_item = arr[j].price;
						message[c].Suggested_price = arr[j].price;
						message[c].Message_number = c + 1;
						for (int k = 0; k < SIZE; k++)
						{
							if (Id_buyer == arr2[k].ID)
							{
								message[c].ID_buyer = arr2[k].ID;
								message[c].name_buyer = arr2[k].name;
								break;
							}
						}
						cheeck2 = true;
						cout << " The buying request has been sent.\n";
						c++;
					}
					check = true;
				}
			}
			if (check == false)
			{
				cout << " This product does not exist.\n";
			}
			if (cheeck2 == false && check == true)
			{
				cout << " This is your product and may not be purchased.\n";
			}
			check = false;
			cheeck2 = false;
			break;
		}
		else if (choose == '2')
		{
			cout << " Enter your ID\n ";
			cin >> Id_buyer;
			cout << " Enter the product number you want to buy it.\n ";
			cin >> itemnumber;
			cout << " Enter the price you want.\n ";
			cin >> suggested_price;
			for (int j = 0; j < SIZE; j++)
			{
				if (itemnumber == arr[j].item_number)
				{
					if (Id_buyer != arr[j].ID1)
					{
						message[c].item_num = arr[j].item_number;
						message[c].item_name = arr[j].category;
						message[c].ID_seller = arr[j].ID1;
						message[c].price_item = arr[j].price;
						message[c].Suggested_price = suggested_price;
						message[c].Message_number = c + 1;
						for (int k = 0; k < SIZE; k++)
						{
							if (Id_buyer == arr2[k].ID)
							{
								message[c].ID_buyer = arr2[k].ID;
								message[c].name_buyer = arr2[k].name;
								break;
							}
						}
						cheeck2 = true;
						cout << " The buying request has been sent.\n";
						c++;
					}
					check = true;
				}
			}
			if (check == false)
			{
				cout << " This product does not exist.\n";
			}
			if (cheeck2 == false)
			{
				cout << " This is your product and may not be purchased.\n";
			}
			check = false;
			cheeck2 = false;
			break;
		}
		else
		{
			cout << " This offer is not allowed.\n";
		}
	}
}
void Show_messages(message_box arr[], items arr2[])     // this function to view buying requests
{
	string id;
	int Reply_to_the_message, index1;
	char choose;
	while (true)
	{
		cout << " Choose waht do you want . \n 1-New purchase requests.\n 2-Respond to my requests.\n ";
		cin >> choose;
		if (choose == '1')
		{
			cout << " Enter your ID\n ";
			cin >> id;
			check = false;
			for (int j = 0; j < SIZE; j++)
			{
				if (id == arr[j].ID_seller && arr[j].reply == false)
				{
					cout << "\t\t\t\t\t< Purchase order for a product >\n";
					cout << " Message number : " << arr[j].Message_number << '\n';
					cout << " The name of the buyer : " << arr[j].name_buyer << '\n';
					cout << " ID of the buyer : " << arr[j].ID_buyer << '\n';
					cout << " Product number : " << arr[j].item_num << '\n';
					cout << " Product name : " << arr[j].item_name << '\n';
					cout << " The price of the product : " << arr[j].price_item << '\n';
					cout << " The price suggested by the buyer : " << arr[j].Suggested_price << '\n' << '\n';
					check = true;
				}
			}
			if (check == false)
			{
				cout << " There are no messages.\n";
			}

			if (check)
			{
				cout << "Enter the number of the message you want to reply it.\n ";
				while (true)
				{
					cin >> Reply_to_the_message;
					for (int j = 0; j < SIZE; j++)
					{
						if (Reply_to_the_message == arr[j].Message_number && arr[j].reply == false)
						{
							cout << " Do you agree to the request ?\n 1-Yes\n 2-No\n ";
							cin >> choose;
							if (choose == '1')
							{
								cout << " Enter the date of sale\n ";
								arr[j].reply = true;
								for (int k = 0; k < SIZE; k++)
								{
									if (arr[j].item_num == arr2[k].item_number)
									{
										while (true)
										{
											cin >> arr2[k].Sale_date.day >> arr2[k].Sale_date.month >> arr2[k].Sale_date.year;
											if ((arr2[k].Sale_date.day > 0 && arr2[k].Sale_date.day < 31) && (arr2[k].Sale_date.month > 0 && arr2[k].Sale_date.month < 13) && (arr2[k].Sale_date.year > 2019))
											{
												break;
											}
											else
											{
												cout << "There is a mistake in the date, please enter the correct date\n ";
											}
										}
										index1 = arr2[k].Sale_date.month - 1;
										arr2[k].status = "Sold";
										for (int b = 0; b < SIZE; b++)
										{
											if (arr2[k].category == top_Category[b].cate)
											{
												top_Category[b].counter[index1]++;
											}
										}
									}
								}
								try_again = true;
								cout << " You have successfully replied to the message.\n";
							}
							else if (choose == '2')
							{
								arr[j].reply = true;
								try_again = true;
								cout << " You have successfully replied to the message.\n";
							}
							cheeck2 = true;
						}
					}
					if (cheeck2 == false)
					{
						cout << " This message does not exist.\n Please enter a valid message number.\n ";
					}
					if (try_again)
						break;
				}
				while (true)
				{
					cout << " Do you want to provide feedback ?\n 1-Yes\n 2-No\n ";
					cin >> choose;
					if (choose == '1')
					{
						feedback(member);
						break;
					}
					else if (choose == '2')
					{
						break;
					}
					else
					{
						cout << " This offer is not allowed\n";
					}
				}
			}
			check = false;
			try_again = false;
			break;
		}
		else if (choose == '2')
		{
			check = false;
			cout << " Enter your ID\n ";
			cin >> id;
			for (int j = 0; j < SIZE; j++)
			{
				if (id == arr[j].ID_buyer && arr[j].reply == true)
				{
					cout << "\n ID of the seller : " << arr[j].ID_seller << '\n';

					for (int k = 0; k < SIZE; k++)
					{
						if (arr[j].item_num == arr2[k].item_number)
						{
							if (arr2[k].status == "Sold")
							{
								cout << " Congratulations, your order to buy a " << arr[j].item_name << " has been approved\n";
							}
							else if (arr2[k].status == "available")
							{
								cout << " Your request to buy a " << arr[j].item_name << " was rejected\n";
							}
						}
					}
					check = true;
				}
			}
			if (check)
			{
				while (true)
				{
					cout << " Do you want to provide feedback ?\n 1-Yes\n 2-No\n ";
					cin >> choose;
					if (choose == '1')
					{
						feedback(member);
						break;
					}
					else if (choose == '2')
					{
						break;
					}
					else
					{
						cout << " This offer is not allowed\n";
					}
				}
			}
			if (check == false)
			{
				cout << " There are no messages.\n";
			}
			check = false;
			break;
		}
		else
		{
			cout << " This offer is not allowed\n";
		}
	}
}
void fun_buy(items arr[])      //this function is for members to buy products
{
	string category;
	float price;
	char choose;
	while (true)
	{
		cout << " Do you want to search for an item ?\n 1-Yes\n 2-No\n ";
		cin >> choose;
		if (choose == '1')
		{
			while (true)
			{
				cout << " Do you want to search by category or category and price ?\n 1-Category.\n 2-Category and pric.\n ";
				cin >> choose;
				if (choose == '1')
				{
					cout << " Enter the category, please.\n ";
					cin >> category;
					for (int j = 0; j < SIZE; j++)
					{
						if (category == arr[j].category && arr[j].status == "available")
						{
							cout << " Item number : " << arr[j].item_number << '\n';
							cout << " seller ID : " << arr[j].ID1 << '\n';
							cout << " the category : " << arr[j].category << '\n';
							cout << " the price : " << arr[j].price << '\n';
							cout << " Dste : " << arr[j].show_date.day << "/" << arr[j].show_date.month << '/' << arr[j].show_date.year << '\n';
							cout << " ex Date : " << arr[j].delete_date.day << "/" << arr[j].delete_date.month << '/' << arr[j].delete_date.year << '\n' << '\n';
							check = true;
							cheeck2 = true;
						}
					}
					if (check == false)
					{
						cout << " There are no products\n";
					}
					check = false;
					try_again = true;
				}
				else if (choose == '2')
				{
					cout << " enter the category, please.\n ";
					cin >> category;
					cout << " enter the price, please.\n ";
					cin >> price;
					for (int j = 0; j < SIZE; j++)
					{
						if ((category == arr[j].category) && ((price - (price * 0.4)) <= arr[j].price && arr[j].price <= (price + (price * 0.4))) && (arr[j].status == "available"))
						{
							cout << " Item number : " << arr[j].item_number << '\n';
							cout << " seller ID : " << arr[j].ID1 << '\n';
							cout << " the category : " << arr[j].category << '\n';
							cout << " the price : " << arr[j].price << '\n';
							cout << " Dste : " << arr[j].show_date.day << "/" << arr[j].show_date.month << '/' << arr[j].show_date.year << '\n';
							cout << " ex Date : " << arr[j].delete_date.day << "/" << arr[j].delete_date.month << '/' << arr[j].delete_date.year << '\n' << '\n';
							check = true;
							cheeck2 = true;
						}
					}
					if (check == false)
					{
						cout << " There are no products\n";
					}
					check = false;
					try_again = true;
				}
				else
				{
					cout << " This offer is not allowed\n";
				}
				if (try_again)
				{
					break;
				}
			}
			try_again = false;
			//break;
		}
		else if (choose == '2')
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (arr[j].status == "available")
				{
					cout << " Item number : " << arr[j].item_number << '\n';
					cout << " seller ID : " << arr[j].ID1 << '\n';
					cout << " the category : " << arr[j].category << '\n';
					cout << " the price : " << arr[j].price << '\n';
					cout << " Dste : " << arr[j].show_date.day << "/" << arr[j].show_date.month << '/' << arr[j].show_date.year << '\n';
					cout << " ex Date : " << arr[j].delete_date.day << "/" << arr[j].delete_date.month << '/' << arr[j].delete_date.year << '\n' << '\n';
					check = true;
					cheeck2 = true;
				}
			}

			if (check == false)
			{
				cout << " There are no products\n";
			}
			check = false;
			try_again = false;
			//break;
		}
		else
		{
			cout << " This offer is not allowed.\n";
		}
		if (cheeck2)
		{
			buying_request(market_place, member);
		}
		cheeck2 = false;
		while (true)
		{
			cout << " Do you want to buy another thing ?\n 1-Yes\n 2-NO\n ";
			cin >> choose;
			if (choose == '1')
			{
				break;
			}
			else if (choose == '2')
			{
				cheeck2 = true;
				break;
			}
			else
			{
				cout << " This offer is not allowed.\n";
			}
		}
		if (cheeck2)
			break;
	}
	cheeck2 = false;
}
void show_feedback()     // this function show to people's opinions
{
	check = false;
	for (int j = 0; j < SIZE; j++)
	{
		if (array_feedback[j].done == true)
		{
			cout << " User " << array_feedback[j].ID << " got a rating " << array_feedback[j].rate << " out of 5\n ";
			cout << array_feedback[j].comment << '\n';
			check = true;
		}
	}
	if (check == false)
	{
		cout << " There are no comments from users\n";
	}
	check = false;
}
void show_top_category()      // this function to show top category 
{
	int month, max = 0, index_max = 0, index;
	cout << " Enter the month do you want (1 to 12)\n ";
	while (true)
	{
		cin >> month;
		if (0 < month && month < 13)
		{
			index = month - 1;
			max = 0;
			index_max = 0;
			for (int j = 0; j < SIZE; j++)
			{
				if (top_Category[j].counter[index] > max)
				{
					max = top_Category[j].counter[index];
					index_max = j;
				}
			}
			if (max != 0)
			{
				cout << " The top category sold in a month " << month << " is a " << top_Category[index_max].cate << '\n';
			}
			else
			{
				cout << " There are no sales this month\n";
			}
			max = 0;
			break;
		}
		else
		{
			cout << "  Please enter month 1 to 12\n ";
		}
	}
}
int main()
{
	cout << "\t\t\t\t\twelcome to Online Auction System\n\n";
	while (true)
	{
		int chosse_members, chosse_login;
		while (true)
		{
			cout << " 1-login\n 2-create account\n ";
			cin >> chosse_login;
			if (chosse_login == 1)
			{
				login(member);
				try_again = true;
			}
			else if (chosse_login == 2)
			{
				new_account(member);
				try_again = true;
			}
			else
			{
				cout << " This offer is not allowed\n";
			}
			if (try_again)
				break;
		}
		try_again = false;
		while (true)
		{
			cout << "\n\n Choose waht do you want . \n   1-buy\n   2-sell\n   3-Show messages\n   4-Show people's opinions\n   5-Show top category sold in a given month\n   6-logout\n ";
			cin >> chosse_members;
			if (chosse_members == 1)
			{
				fun_buy(market_place);

			}
			else if (chosse_members == 2)
			{
				fun_sell(market_place, member);

			}
			else if (chosse_members == 3)
			{
				Show_messages(message, market_place);

			}
			else if (chosse_members == 4)
			{
				show_feedback();
			}
			else if (chosse_members == 5)
			{
				show_top_category();
			}
			else if (chosse_members == 6)
			{
				break;
			}
			else
			{
				cout << " This offer is not allowed\n";
			}

		}
		try_again = false;
		cout << "-----------------------------------------------------------------------------------\n";
	}
	return 0;
}
