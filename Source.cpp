#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


struct invoice {
	string invoiceID;
	string carTitle;
	string date;
	string seller;
	string clientname;
	string identify;
	string price;
	string fee;
	string discount;
	string deposit;
	string totalPrice;
	invoice* nextaddressSales;
	invoice* prevaddressSales;
};
class InvoiceSystem {
	invoice* head = NULL;
	invoice* tail = NULL;
	int sizeOfLinkedListInvoice = 0;

	invoice* createNewNodeInvoice(string invoiceID, string carTitle, string date, string seller, string clientname,
		string identify, string price, string fee, string discount, string deposit, string totalPrice)
	{
		invoice* newnodeInvoice = new invoice;
		newnodeInvoice->invoiceID = invoiceID;
		newnodeInvoice->carTitle = carTitle;
		newnodeInvoice->date = date;
		newnodeInvoice->seller = seller;
		newnodeInvoice->clientname = clientname;
		newnodeInvoice->identify = identify;
		newnodeInvoice->price = price;
		newnodeInvoice->fee = fee;
		newnodeInvoice->discount = discount;
		newnodeInvoice->deposit = deposit;
		newnodeInvoice->totalPrice = totalPrice;
		newnodeInvoice->nextaddressSales = NULL;
		newnodeInvoice->prevaddressSales = NULL;
		return newnodeInvoice;
	}

public:
	InvoiceSystem() {}

	void insertOfFrontListInvoice(string invoiceID, string carTitle, string date, string seller, string clientname,
		string identify, string price, string fee, string discount, string deposit, string totalPrice)
	{
		invoice* newnodeInvoice = createNewNodeInvoice(invoiceID, carTitle, date, seller, clientname,
			identify, price, fee, discount, deposit, totalPrice);
		if (head == NULL)
		{
			head = tail = newnodeInvoice;
		}
		else
		{
			newnodeInvoice->nextaddressSales = head;
			head->prevaddressSales = newnodeInvoice;
			head = newnodeInvoice;
		}
		sizeOfLinkedListInvoice++;
	}

	void displayLinkedListItem()
	{
		invoice* current = head;
		while (current != NULL)
		{
			cout << current->invoiceID << " - " << current->carTitle << " - " << current->price << " - " << current->totalPrice << endl;
			current = current->nextaddressSales;
		}
		cout << "List is ended here!" << endl << endl;
	}
	void SalesReport() {
		invoice* current = tail;
		double Price = 0;
		double TotalSales = 0;
		//Print sales
		cout << string(100, '-') << endl;
		cout << "Seller" << "-" << "Identity" << "-" << "CarTitle" << "-" << "ClientName" << "-" << "SalesDate" << "-" << "TotalPrice" << endl;
		while (current != NULL) {
			

			cout << current->seller << "-" << current->identify << "-" << current->carTitle << "-" << current->clientname << "-"
				<< current->date << "-" << current->totalPrice << endl;
			Price = stod(current->totalPrice);
			TotalSales = TotalSales + Price;
			current = current->prevaddressSales;

		}
		cout << string(20, '*') << endl;
		cout << "Total Sales:" << TotalSales << endl;
		cout << string(20, '*') << endl;
	}
};



struct Bill {
	string BillID;
	string carTitle;
	string date;
	string buyer;
	string price;
	string fee;
	string discount;
	string payEndDate;
	string totalprice;
	Bill* nextaddressBill;
	Bill* prevaddressBill;

};
class BillSystem {
	Bill* head = NULL;
	Bill* tail = NULL;
	int sizeOfLinkedListBill = 0;
	Bill* createNewNodeBill(string BillID, string carTitle, string date, string buyer, string price,
		string fee, string discount, string payEndDate, string totalprice)
	{
		Bill* newnodeBill = new Bill;
		newnodeBill->BillID = BillID;
		newnodeBill->carTitle = carTitle;
		newnodeBill->date = date;
		newnodeBill->buyer = buyer;
		newnodeBill->price = price;
		newnodeBill->fee = fee;
		newnodeBill->discount = discount;
		newnodeBill->payEndDate = payEndDate;
		newnodeBill->totalprice = totalprice;
		newnodeBill->nextaddressBill = NULL;
		newnodeBill->prevaddressBill = NULL;
		return newnodeBill;
	}

public:
	BillSystem() {}

	void insertOfFrontListBill(string BillID, string carTitle, string date, string price,
		string totalprice, string buyer, string fee, string discount, string payEndDate)
	{
		Bill* newnodeBill = createNewNodeBill(BillID, carTitle, date, buyer, price, fee, discount, payEndDate, totalprice);
		if (head == NULL)
		{
			head = tail = newnodeBill;
		}
		else
		{
			newnodeBill->nextaddressBill = head;
			head->prevaddressBill = newnodeBill;
			head = newnodeBill;
		}
		sizeOfLinkedListBill++;
	}
	void displayLinkedListItem()
	{
		Bill* current = head;
		while (current != NULL)
		{
			cout << current->BillID << " - " << current->carTitle << " - " << current->price << " - " << current->totalprice << endl;
			current = current->nextaddressBill;
		}
		cout << "List is ended here!" << endl << endl;
	}

	void BillingReport() {
		Bill* current = tail;
		cout << string(100, '-') << endl;
		cout << "BillID" << " - " << "CarTitle" << " - " << "Buyer" << " - " << "Total Price" << " - " << "Sale Date" << " - " << "Pay End Date" << endl;
		while (current != NULL)
		{
			cout << current->BillID << " - " << current->carTitle << " - " << current->buyer << " - " << current->totalprice << " - " << current->date << " - " << current->payEndDate << endl;
			current = current->prevaddressBill;
		}
		cout << "Billing Report is ended here!" << endl << endl;
	}
};


struct car
{
	string carTitle;
	string carPrice, carEngine;
	string carRegistration, carMileage, age;
	string carFuel, carTransmission, carDoor, carColor, carBody;
	string carURL, carSale, customerName, gender, status;
	car* nextAddressCar; //pointer
	car* prevAddressCar;
};
class Carlist {
	car* head = NULL;
	int sizeOfLinkedListCar = 0;
	car* createNewNodeCar(string carTitle, string carPrice, string carRegistration, string carMileage,
		string carFuel, string carTransmission, string carEngine, string carDoor, string carColor,
		string carBody, string carURL, string carSale, string customerName, string age, string gender, string status)
	{
		//1. create structure in the heap location
		car* newnodeCar = new car;
		newnodeCar->carTitle = carTitle;
		newnodeCar->carPrice = carPrice;
		newnodeCar->carRegistration = carRegistration;
		newnodeCar->carMileage = carMileage;
		newnodeCar->carFuel = carFuel;
		newnodeCar->carTransmission = carTransmission;
		newnodeCar->carEngine = carEngine;
		newnodeCar->carDoor = carDoor;
		newnodeCar->carColor = carColor;
		newnodeCar->carBody = carBody;
		newnodeCar->carURL = carURL;
		newnodeCar->carSale = carSale;
		newnodeCar->customerName = customerName;
		newnodeCar->age = age;
		newnodeCar->gender = gender;
		newnodeCar->status = status;
		newnodeCar->nextAddressCar = NULL;
		newnodeCar->prevAddressCar = NULL;
		return newnodeCar;
	}

public:
	Carlist() {}

	//method used in each CarList
	void  insertOfFrontListCar(string carTitle, string carPrice, string carRegistration, string carMileage, string carFuel, string carTransmission,
		string carEngine, string carDoor, string carColor, string carBody, string carURL, string carSale, string customerName, string age, string gender, string status)
	{
		//call the create function to create a new node
		car* newnodeCar = createNewNodeCar(carTitle, carPrice, carRegistration, carMileage, carFuel,
			carTransmission, carEngine, carDoor, carColor, carBody, carURL, carSale, customerName, age, gender, status);

		//add to the list
		if (head == NULL)
		{
			head = newnodeCar;
		}
		else //list not empty?
		{
			newnodeCar->nextAddressCar = head;
			head = newnodeCar;
		}
		sizeOfLinkedListCar++;

	}
	void displayLinkedListItem() //R - O(N)
	{
		car* current = head;
		while (current != NULL)
		{
			cout << current->carTitle << " - " << current->carPrice << " - ";
			cout << current->carRegistration << " - " << current->carMileage << " - ";
			cout << current->carSale << endl;
			current = current->nextAddressCar;
		}
		cout << "List is ended here!" << endl << endl;
	}
	void bookingsystem()
	{

		string title;
		cout << "\n\tPlease enter the car title" << endl;
		cin.ignore();
		getline(cin, title);
		car* current = head;
		if (current == NULL) {
			cout << "Unable to find car base on title!" << endl;
		}
		while (current != NULL) //is it end of the list?
		{

			if (title == current->carTitle)
			{
				cout << current->carTitle << " - ";
				cout << current->carPrice << endl;
				cout << current->status << endl;
				cout << "\n\tDo you want to book this car? Enter 1 for Yes , 2 for No or 0 for exit system." << endl;
				string choose;
				cin >> choose;
				if (choose == "1")
				{
					current->status = "book";
					cout << current->carTitle;
					cout << current->status;
					cout << "\n\tCar booked successfully!" << endl;
					break;
				}
				else if (choose == "2")
				{
					cout << "\n\tCar not booked." << endl;
					break;
				}
				else if (choose == "0")
				{
					exit(0);
				}
				else
				{
					cout << "\n\tInvalid input. Car not booked." << endl;
					continue;
				}
			}
			current = current->nextAddressCar;
		}
	}

	void CreateBillInvoice()
	{
		string title;
		Bill Bills;
		cout << "\nPlease enter the car title" << endl;
		cin.ignore();
		getline(cin, title);
		car* current = head;
		if (current == NULL) {
			cout << "Cant open the file" << endl;
		}
		while (current != NULL) //is it end of the list?
		{
			if (current->carTitle == title)
			{
				ofstream FileO;
				FileO.open("Bill.txt", ios::app);
				cout << "\nEnter Bill ID :";
				cin >> Bills.BillID;
				cin.ignore();
				Bills.carTitle = title;
				cout << "\n Enter date (DD/MM/YYYY):";
				getline(cin, Bills.date);
				cout << "\n Enter buyer:";
				getline(cin, Bills.buyer);
				cout << "\n Enter Price:";
				double cprice;
				cin >> cprice;
				Bills.price = to_string(cprice);
				cout << "\n Enter fee:";
				double cfee;
				cin >> cfee;
				Bills.fee = to_string(cfee);
				cout << "\n Enter discount:";
				double cdiscount;
				cin >> cdiscount;
				Bills.discount = to_string(cdiscount);
				cin.ignore();
				cout << "Enter pay end date (DD/MM/YYYY):";
				getline(cin, Bills.payEndDate);
				// check if any required information is missing or invalid
				if (Bills.BillID.empty() || Bills.date.empty() || Bills.buyer.empty() || Bills.payEndDate.empty() ||
					Bills.price.empty() || Bills.fee.empty() || Bills.discount.empty())
				{
					cout << "Some information is missing or invalid. Please try again." << endl << endl;
					continue; // prompt user to re-enter information
				}
				double ctotalprice = cprice + cfee - cdiscount;
				Bills.totalprice = to_string(ctotalprice);
				FileO << Bills.BillID + ",";
				FileO << Bills.carTitle + ",";
				FileO << Bills.date + ",";
				FileO << Bills.buyer + ",";
				FileO << Bills.price + ",";
				FileO << Bills.fee + ",";
				FileO << Bills.discount + ",";
				FileO << Bills.payEndDate + ",";
				FileO << Bills.totalprice << endl;
				FileO.close();
				cout << "Crerate Successfully" << endl << endl;
				break;
			}
			current = current->nextAddressCar;
		}
	}
	void CreateInvoice()
	{
		string title;
		invoice Invoice;

		cout << "\nPlease enter the car title" << endl;
		cin.ignore();
		getline(cin, title);
		car* current = head;
		if (current == NULL) {
			cout << "Cant open the file" << endl;
		}
		while (current != NULL) //is it end of the list?
		{
			if (current->carTitle == title)
			{
				ofstream FileO;
				FileO.open("Invoice.txt", ios::app);
				cout << "\nEnter Invoice ID :";
				cin >> Invoice.invoiceID;
				cin.ignore();
				Invoice.carTitle = title;
				cout << "\n Enter date (DD/MM/YYYY):";
				getline(cin, Invoice.date);
				cout << "\n Enter seller:";
				getline(cin, Invoice.seller);
				cout << "\n Enter Price:";
				double cprice;
				cin >> cprice;
				Invoice.price = to_string(cprice);
				cout << "\n Enter fee:";
				double cfee;
				cin >> cfee;
				Invoice.fee = to_string(cfee);
				cout << "\n Enter the deposit:";
				double cdeposit;
				cin >> cdeposit;
				Invoice.deposit = to_string(cdeposit);
				cout << "\n Enter discount:";
				double cdiscount;
				cin >> cdiscount;
				Invoice.discount = to_string(cdiscount);
				cin.ignore();
				cout << "\nEnter the client Name:";
				getline(cin, Invoice.clientname);
				cout << "\nEnter the identify:";
				cin >> Invoice.identify;

				// check if any required information is missing or invalid
				if (Invoice.invoiceID.empty() || Invoice.date.empty() || Invoice.seller.empty() ||
					Invoice.clientname.empty() || Invoice.identify.empty() ||
					Invoice.price.empty() || Invoice.fee.empty() || Invoice.deposit.empty() || Invoice.discount.empty())
				{
					cout << "Some information is missing or invalid. Please try again." << endl << endl;
					continue; // prompt user to re-enter information
				}
				double ctotalprice;
				ctotalprice = cprice + cfee - cdiscount - cdeposit;
				Invoice.totalPrice = to_string(ctotalprice);
				cout << "This is your Invoice detatils" << endl;
				cout << "Invoice ID:" << Invoice.invoiceID << endl;
				cout << "CarTitle:" << Invoice.carTitle << endl;
				cout << "Date:" << Invoice.date << endl;
				cout << "Seller:" << Invoice.seller << endl;
				cout << "ClientName" << Invoice.clientname << endl;
				cout << "Identify:" << Invoice.identify << endl;
				cout << "Price:" << Invoice.price << endl;
				cout << "Fee:" << Invoice.fee << endl;
				cout << "Discount:" << Invoice.discount << endl;
				cout << "Deposit:" << Invoice.deposit << endl;
				cout << "TotalPrice:" << Invoice.totalPrice << endl;
				FileO << Invoice.invoiceID + ",";
				FileO << Invoice.carTitle + ",";
				FileO << Invoice.date + ",";
				FileO << Invoice.seller + ",";
				FileO << Invoice.clientname + ",";
				FileO << Invoice.identify + ",";
				FileO << Invoice.price + ",";
				FileO << Invoice.fee + ",";
				FileO << Invoice.discount + ",";
				FileO << Invoice.deposit + ",";
				FileO << Invoice.totalPrice << endl;
				FileO.close();
				cout << "Create Successfully" << endl << endl;
				break;
			}
			current = current->nextAddressCar;



		}

	}
	void ManageClient() {
		int option;
		string editCus, DeletCus;
		cout << "Please enter the option for managing customer" << endl;
		cout << "1 for Edit\n2 for Delete" << endl;
		cin >> option;
		system("cls");
		if (option == 1) {
			displayCustomer();
			cout << "Edit Function" << endl;
			cout << string(20, '-') << endl;
			cout << "Please enter the customer name you want to edit:" << endl;
			cin.ignore();
			getline(cin, editCus);
			EditCustomer(editCus);
		}
		else if (option == 2) {
			displayCustomer();
			cout << "Delete Function:" << endl;
			cout << string(20, '-') << endl;
			cout << "Please enter the customer name you want to delete:" << endl;
			cin.ignore();
			getline(cin, DeletCus);
			DeleteCustomer(DeletCus);



		}
	}
	void displayCustomer()
	{
		car* current = head;
		cout << string(100, '-') << endl;
		cout << "Cliet Name\tAge\tGender\tPrice\tSaleDate\tCarTitle\n";
		cout << string(100, '-') << endl;
		while (current != NULL)
		{
			cout << current->customerName << "\t" << current->age << " \t" << current->gender
				<< "\t" << current->carPrice << "\t" << current->carSale << "\t" << current->carTitle << endl;
			current = current->nextAddressCar;
		}
		cout << endl << string(20, '-') << "List is ended here!" << string(20, '-') << endl;
	}
	void EditCustomer(string editCus) {
		car* current = head;
		int con;
		if (current == NULL) {
			cout << "Unable to find Customer base on name!" << endl;
		}
		while (current != NULL)
		{
			if (current->customerName == editCus)
			{
				cout << "Client name : " << current->customerName << endl;
				cout << "Age : " << current->age << endl;
				cout << "Gender : " << current->gender << endl;
				cout << "Car Price: " << current->carPrice << endl;
				cout << "Car SaleDate: " << current->carSale << endl;
				cout << "Car Title: " << current->carTitle << endl;
				int part;
				cout << "Which part do you want to edit?\n 1 - Age, 2 - Gender, 3 - Price, 4 - Date, 5 - Title, 0 - No: ";
				cin >> part;
				if (part == 1)
				{
					cout << "\nEnter your new customer age :";
					cin >> current->age;
					cout << current->customerName << "\t" << current->age << " \t" << current->gender
						<< "\t" << current->carPrice << "\t" << current->carSale << "\t" << current->carTitle << endl;
					cout << "Do you want to continue for manage customer?1 for yes,2 for no" << endl;
					cin >> con;
					if (con == 1) {
						ManageClient();
					}
					else if (con == 2) {
						exit(2);
					}
					break;
				}
				else if (part == 2) {
					cout << "\nEnter your new customer gender :";
					cin >> current->gender;
					cout << current->customerName << "\t" << current->age << " \t" << current->gender
						<< "\t" << current->carPrice << "\t" << current->carSale << "\t" << current->carTitle << endl;
					cout << "Do you want to continue for manage customer?1 for yes,2 for no" << endl;
					cin >> con;
					if (con == 1) {
						ManageClient();
					}
					else if (con == 2) {
						exit(2);
					}
					break;
				}
				else if (part == 3) {
					cout << "\nEnter your new car price :";
					cin >> current->carPrice;
					cout << current->customerName << "\t" << current->age << " \t" << current->gender
						<< "\t" << current->carPrice << "\t" << current->carSale << "\t" << current->carTitle << endl;
					cout << "Do you want to continue for manage customer?1 for yes,2 for no" << endl;
					cin >> con;
					if (con == 1) {
						ManageClient();
					}
					else if (con == 2) {
						exit(2);
					}
					break;
				}
				else if (part == 4) {
					cout << "\nEnter your new car sale date :";
					cin >> current->carSale;
					cout << current->customerName << "\t" << current->age << " \t" << current->gender
						<< "\t" << current->carPrice << "\t" << current->carSale << "\t" << current->carTitle << endl;
					cout << "Do you want to continue for manage customer?1 for yes,2 for no" << endl;
					cin >> con;
					if (con == 1) {
						ManageClient();
					}
					else if (con == 2) {
						exit(2);
					}
					break;
				}
				else if (part == 5) {
					cout << "\nEnter your new car title :";
					cin >> current->carTitle;
					cout << current->customerName << "\t" << current->age << " \t" << current->gender
						<< "\t" << current->carPrice << "\t" << current->carSale << "\t" << current->carTitle << endl;
					cout << "Do you want to continue for manage customer?1 for yes,2 for no" << endl;
					cin >> con;
					if (con == 1) {
						ManageClient();
					}
					else if (con == 2) {
						exit(2);
					}
					break;
				}
				else if (part == 0) {
					exit(0);
				}
				else {
					cout << "Invalid number!! Please try again" << endl;
					continue;
				}
				return;
			}

			current = current->nextAddressCar;
		}
	}
	void DeleteCustomer(string DeletCus) {
		car* current = head;
		car* prev = NULL;
		int con;
		if (current == NULL) {
			cout << "List is not existing!" << endl;
		}
		while (current != NULL) {

			if (current->customerName == DeletCus)
			{
				prev->nextAddressCar = current->nextAddressCar;
				cout << "Delete Customer Details" << endl;
				cout << "Customer name : " << current->customerName << endl;
				cout << "Age : " << current->age << endl;
				cout << "Gender : " << current->gender << endl;
				cout << "Car Price: " << current->carPrice << endl;
				cout << "Car SaleDate: " << current->carSale << endl;
				cout << "Car Title: " << current->carTitle << endl;

				delete current;
				cout << "Deleted" << endl;
				displayCustomer();
				sizeOfLinkedListCar--;
				cout << "Do you want to continue for manage customer?1 for yes,2 for no" << endl;
				cin >> con;
				if (con == 1) {
					ManageClient();
				}
				else if (con == 2) {
					exit(2);
				}
			}
			prev = current;
			current = current->nextAddressCar;

		}



	}

	void searchMenu() {
		int choice;
		string titleSearch;
		float lowestPrice;
		float highestPrice;
		cout << "Which method that you want to searching: " << endl;
		cout << "1.Car Title" << endl;
		cout << "2.Price range" << endl;
		cout << "Please insert you choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Car Title Search" << endl;
			cout << "Please insert the title you want to search: ";
			cin.ignore();
			getline(cin, titleSearch);
			searchByTitle(titleSearch);
			break;
		case 2:
			system("cls");
			cout << "Price Range Search" << endl;
			cout << "Please insert the price range you want to search: " << endl;
			cout << "The lowest price: ";
			cin >> lowestPrice;
			cout << "The highest price: ";
			cin >> highestPrice;
			searchByPriceRange(lowestPrice, highestPrice);
			break;
		}


	}

	void printCarDetails(car* carNode) {
		cout << "Title: " << carNode->carTitle << " , ";
		cout << "Price: " << carNode->carPrice << " , ";
		cout << "Registration: " << carNode->carRegistration << " , ";
		cout << "Mileage: " << carNode->carMileage << " , ";
		cout << "Fuel: " << carNode->carFuel << " , ";
		cout << "Transmission: " << carNode->carTransmission << " , ";
		cout << "Engine: " << carNode->carEngine << " , ";
		cout << "Door: " << carNode->carDoor << " , ";
		cout << "Color: " << carNode->carColor << " , ";
		cout << "Body: " << carNode->carBody << " , ";
		cout << "URL: " << carNode->carURL << " , ";
		cout << "Sale: " << carNode->carSale << " , ";
		cout << "Customer Name: " << carNode->customerName << " , ";
		cout << "Age: " << carNode->age << " , ";
		cout << "Gender: " << carNode->gender << " , ";
		cout << "Status: " << carNode->status << endl << endl;
	}

	car* searchByTitle(string title) {
		car* current = head;
		while (current != NULL) {
			if (current->carTitle == title) {
				printCarDetails(current);
				return current;
			}
			current = current->nextAddressCar;
		}
		return NULL;
	}

	car* searchByPriceRange(float minPrice, float maxPrice) {
		car* current = head->nextAddressCar;
		while (current != NULL) {
			float price = stof(current->carPrice);
			if (price >= minPrice && price <= maxPrice) {
				printCarDetails(current);
			}
			current = current->nextAddressCar;
		}
		return NULL;
	}

	int getDate(string date) {
		int day, year;
		string month;

		istringstream iss(date);
		iss >> day >> month >> year;

		// Convert month name to number
		static const string monthNames[] = {
			"",     // Month 0
			"Jan",  // Month 1
			"Feb",  // Month 2
			"Mar",  // Month 3
			"Apr",  // Month 4
			"May",  // Month 5
			"Jun",  // Month 6
			"Jul",  // Month 7
			"Aug",  // Month 8
			"Sep",  // Month 9
			"Oct",  // Month 10
			"Nov",  // Month 11
			"Dec"   // Month 12
		};
		int monthNumber = 0;
		for (int i = 1; i <= 12; i++) {
			if (monthNames[i] == month) {
				monthNumber = i;
				break;
			}
		}

		// Return date as a single integer in the format YYYYMMDD
		return year * 10000 + monthNumber * 100 + day;
	}

	void bubbleSortBySalesDate()
	{
		car* current = head;
		car* index = NULL;
		string temp;
		int currentSales;
		int indexSales;

		if (head == NULL) {
			return;
		}
		else {
			while (current != NULL) {
				index = current->nextAddressCar;

				while (index != NULL) {
					//compare the carSale dates of current and index node
					currentSales = getDate(current->carSale);
					indexSales = getDate(index->carSale);

					if (currentSales > indexSales) {
						//swap the data of current and index node
						temp = current->carTitle;
						current->carTitle = index->carTitle;
						index->carTitle = temp;

						temp = current->carPrice;
						current->carPrice = index->carPrice;
						index->carPrice = temp;

						temp = current->carRegistration;
						current->carRegistration = index->carRegistration;
						index->carRegistration = temp;

						temp = current->carMileage;
						current->carMileage = index->carMileage;
						index->carMileage = temp;

						temp = current->carFuel;
						current->carFuel = index->carFuel;
						index->carFuel = temp;

						temp = current->carTransmission;
						current->carTransmission = index->carTransmission;
						index->carTransmission = temp;

						temp = current->carEngine;
						current->carEngine = index->carEngine;
						index->carEngine = temp;

						temp = current->carDoor;
						current->carDoor = index->carDoor;
						index->carDoor = temp;

						temp = current->carColor;
						current->carColor = index->carColor;
						index->carColor = temp;

						temp = current->carBody;
						current->carBody = index->carBody;
						index->carBody = temp;

						temp = current->carURL;
						current->carURL = index->carURL;
						index->carURL = temp;

						temp = current->carSale;
						current->carSale = index->carSale;
						index->carSale = temp;

						temp = current->customerName;
						current->customerName = index->customerName;
						index->customerName = temp;

						temp = current->age;
						current->age = index->age;
						index->age = temp;

						temp = current->gender;
						current->gender = index->gender;
						index->gender = temp;

						temp = current->status;
						current->status = index->status;
						index->status = temp;
					}
					index = index->nextAddressCar;
				}
				current = current->nextAddressCar;
			}
		}
	}
	void GenerateReport() {
		int option;
		InvoiceSystem  invoice;
		string invoiceID, cTitle, date, price;
		string totalPrice, deposit, fee;
		string discount, seller, clientname;
		string identify;
		ifstream fin("Invoice.txt");
		while (fin.good()) {
			getline(fin, invoiceID, ',');
			if (invoiceID == "") {
				break;
			}
			getline(fin, cTitle, ',');
			getline(fin, date, ',');
			getline(fin, seller, ',');
			getline(fin, clientname, ',');
			getline(fin, identify, ',');
			getline(fin, price, ',');
			getline(fin, fee, ',');
			getline(fin, discount, ',');
			getline(fin, deposit, ',');
			getline(fin, totalPrice);
			invoice.insertOfFrontListInvoice(invoiceID, cTitle, date, seller, clientname, identify, price, fee, discount, deposit, totalPrice);

		}
		fin.close();
		BillSystem Bill1;
		string BillID, cbTitle, bdate;
		string bprice, btotalprice, buyer;
		string bfee, bdiscount, payEndDate;
		ifstream fbill("Bill.txt");
		while (fbill.good()) {
			getline(fbill, BillID, ',');
			if (BillID == "") {
				break;
			}
			getline(fbill, cbTitle, ',');
			getline(fbill, bdate, ',');
			getline(fbill, buyer, ',');
			getline(fbill, bprice, ',');
			getline(fbill, bfee, ',');
			getline(fbill, bdiscount, ',');
			getline(fbill, payEndDate, ',');
			getline(fbill, btotalprice);
			Bill1.insertOfFrontListBill(BillID, cbTitle, bdate, bprice, btotalprice, buyer, bfee, bdiscount, payEndDate);

		}
		fbill.close();

		cout << "\nPlease enter the option for generating report" << endl;
		cout << "1. Customer Report\n2. Sales Report\n3. Billing Report " << endl;
		cin >> option;
		switch (option) {
		case 1:
			system("cls");
			cout << string(20, '-') << endl;
			cout << "Customer Report\n";
			CustomerReport();
			break;
		case 2:
			system("cls");
			cout << string(20, '-') << endl;
			cout << "Sales Report\n";
			invoice.SalesReport();
			break;
		case 3:
			system("cls");
			cout << string(20, '-') << endl;
			cout << "Billing Report\n";
			Bill1.BillingReport();
			break;
		default:
			cout << "Invalid option. Please try again." << endl;
			break;
		}
	}
	//for customer data
	void CustomerReport() {
		car* current = head;
		cout << string(100, '-') << endl;
		while (current != NULL)
		{
			cout << current->customerName << "\t" << current->age << " \t" << current->gender
				<< "\t" << current->carPrice << "\t" << current->carSale << "\t" << current->carTitle << endl;
			current = current->nextAddressCar;
		}
		cout << "Customer Report is ended here!" << endl << endl;
	}

};



struct staff
{
	int staffID; //data
	string staffName;
	string staffPassword;
	string staffPosition;

	staff* nextAddressStaff; //pointer

};
class Staff {
	staff* head = NULL;
	int sizeOfLinkedListStaff = 0;

	staff* createNewNode(int staffID, string staffName, string staffPassword, string staffPosition)
	{
		//1. create structure in the heap location
		staff* newnode = new staff;

		//2. assigning the data into the node
		newnode->staffID = staffID;
		newnode->staffName = staffName;
		newnode->staffPassword = staffPassword;
		newnode->staffPosition = staffPosition;
		newnode->nextAddressStaff = NULL; //always start with NULL first in newnode

		//3. return back the new created node to the other function
		return newnode;
	}
public:Staff() {}
	  //method used in each CarList
	  void InsertToFrontOfList(int staffID, string staffName, string staffPassword, string staffPosition)
	  {
		  //call the create function to create a new node
		  staff* newnode = createNewNode(staffID, staffName, staffPassword, staffPosition);

		  //add to the list
		  if (head == NULL)
		  {
			  head = newnode;
		  }
		  else //list not empty?
		  {
			  newnode->nextAddressStaff = head;
			  head = newnode;
		  }
		  sizeOfLinkedListStaff++;

	  }

	  void displayLinkedListStaff() //R - O(N)
	  {
		  staff* current = head;
		  while (current != NULL)
		  {
			  cout << current->staffName << " - ";
			  cout << current->staffPassword << endl;
			  current = current->nextAddressStaff;
		  }
		  cout << "List is ended here!" << endl << endl;
	  }
	  void isLogin() {
		  string user, password;
		  cout << "        Welcome to Login Page" << endl << endl;
		  cout << "UserName: ";
		  getline(cin, user);
		  cout << "Password: ";
		  getline(cin, password);
		  staff* current = head;
		  while (current != NULL) {
			  if (current->staffName == user && current->staffPassword == password && current->staffPosition == "staff") {
				  cout << "Login successful!" << endl << endl;
				  menuStaff(); // Call menu function here
				  return;
			  }
			  else if (current->staffName == user && current->staffPassword == password && current->staffPosition == "manager") {
				  cout << "Login successful!" << endl << endl;
				  menuManager(); // Call menu function here
				  return;
			  }
			  else if (current->staffName == user && current->staffPassword == password && current->staffPosition == "salesperson") {
				  cout << "Login successful!" << endl << endl;
				  menuSalesperson(); // Call menu function here
				  return;
			  }

			  current = current->nextAddressStaff;
		  }

		  cout << "Invalid username or password. Please try again." << endl;
	  }
	  void menuStaff() {
		  Carlist car1;
		  string carTitle, carPrice, carRegistration, carMileage;
		  string carFuel, carTransmission, carEngine, carDoor, carColor,
			  carBody, carURL, carSale, customerName, age, gender, status;
		  //read the file
		  ifstream File("carlist.csv");
		  //insert 1 by 1 
		  while (File.good()) {
			  getline(File, carTitle, ',');
			  if (carTitle == "") {
				  break;
			  }
			  getline(File, carPrice, ',');
			  getline(File, carRegistration, ',');
			  getline(File, carMileage, ',');
			  getline(File, carFuel, ',');
			  getline(File, carTransmission, ',');
			  getline(File, carEngine, ',');
			  getline(File, carDoor, ',');
			  getline(File, carColor, ',');
			  getline(File, carBody, ',');
			  getline(File, carURL, ',');
			  getline(File, carSale, ',');
			  getline(File, customerName, ',');
			  getline(File, age, ',');
			  getline(File, gender, ',');
			  getline(File, status);
			  car1.insertOfFrontListCar(carTitle, carPrice, carRegistration, carMileage, carFuel, carTransmission, carEngine, carDoor
				  , carColor, carBody, carURL, carSale, customerName, age, gender, status);

		  }
		  File.close();
		  InvoiceSystem  invoice;
		  string invoiceID, cTitle, date, price;
		  string totalPrice, deposit, fee;
		  string discount, seller, clientname;
		  string identify;
		  ifstream fin("Invoice.txt");
		  while (fin.good()) {
			  getline(fin, invoiceID, ',');
			  if (invoiceID == "") {
				  break;
			  }
			  getline(fin, cTitle, ',');
			  getline(fin, date, ',');
			  getline(fin, seller, ',');
			  getline(fin, clientname, ',');
			  getline(fin, identify, ',');
			  getline(fin, price, ',');
			  getline(fin, fee, ',');
			  getline(fin, discount, ',');
			  getline(fin, deposit, ',');
			  getline(fin, totalPrice);
			  invoice.insertOfFrontListInvoice(invoiceID, cTitle, date, seller, clientname, identify, price, fee, discount, deposit, totalPrice);

		  }
		  fin.close();
		  BillSystem Bill1;
		  string BillID, cbTitle, bdate;
		  string bprice, btotalprice, buyer;
		  string bfee, bdiscount, payEndDate;
		  ifstream fbill("Bill.txt");
		  while (fbill.good()) {
			  getline(fbill, BillID, ',');
			  if (BillID == "") {
				  break;
			  }
			  getline(fbill, cbTitle, ',');
			  getline(fbill, bdate, ',');
			  getline(fbill, buyer, ',');
			  getline(fbill, bprice, ',');
			  getline(fbill, bfee, ',');
			  getline(fbill, bdiscount, ',');
			  getline(fbill, payEndDate, ',');
			  getline(fbill, btotalprice);
			  Bill1.insertOfFrontListBill(BillID, cbTitle, bdate, bprice, btotalprice, buyer, bfee, bdiscount, payEndDate);

		  }
		  fbill.close();
		  cout << "System Loading....." << endl;
		  car1.bubbleSortBySalesDate();
		  system("cls");
		  int select;
		  cout << "              Welcome to Menu Function" << endl << endl;
		  cout << "1. Search Vehicle Function" << endl << "2. Sale Invoice Creating Function" << endl << "3. Bill Creating Function" << endl << "4. Logout" << endl;
		  cout << "Select the function (1 - 4): ";
		  cin >> select;
		  switch (select) {
		  case 1:
			  system("cls");
			  cout << "Search function" << endl << endl;
			  car1.searchMenu();
			  menuStaff();
			  break;
		  case 2:
			  system("cls");
			  cout << "Sale Invoice";
			  car1.CreateInvoice();
			  menuStaff();
			  break;
		  case 3:
			  system("cls");
			  cout << "Bill Creating";
			  car1.CreateBillInvoice();
			  menuStaff();
			  break;
		  case 4:
			  system("cls");
			  cout << "Logout Successful!! Thank You";
			  break;
		  default:
			  cout << "Invalid select. Please try again." << endl;
			  break;
		  }



	  }
	  void menuSalesperson() {
		  int select;
		  Carlist car1;
		  string carTitle, carPrice, carRegistration, carMileage;
		  string carFuel, carTransmission, carEngine, carDoor, carColor,
			  carBody, carURL, carSale, customerName, age, gender, status;
		  //read the file
		  ifstream File("carlist.csv");
		  //insert 1 by 1 
		  while (File.good()) {
			  getline(File, carTitle, ',');
			  if (carTitle == "") {
				  break;
			  }
			  getline(File, carPrice, ',');
			  getline(File, carRegistration, ',');
			  getline(File, carMileage, ',');
			  getline(File, carFuel, ',');
			  getline(File, carTransmission, ',');
			  getline(File, carEngine, ',');
			  getline(File, carDoor, ',');
			  getline(File, carColor, ',');
			  getline(File, carBody, ',');
			  getline(File, carURL, ',');
			  getline(File, carSale, ',');
			  getline(File, customerName, ',');
			  getline(File, age, ',');
			  getline(File, gender, ',');
			  getline(File, status);
			  car1.insertOfFrontListCar(carTitle, carPrice, carRegistration, carMileage, carFuel, carTransmission, carEngine, carDoor
				  , carColor, carBody, carURL, carSale, customerName, age, gender, status);

		  }
		  File.close();
		  InvoiceSystem  invoice;
		  string invoiceID, cTitle, date, price;
		  string totalPrice, deposit, fee;
		  string discount, seller, clientname;
		  string identify;
		  ifstream fin("Invoice.txt");
		  while (fin.good()) {
			  getline(fin, invoiceID, ',');
			  if (invoiceID == "") {
				  break;
			  }
			  getline(fin, cTitle, ',');
			  getline(fin, date, ',');
			  getline(fin, seller, ',');
			  getline(fin, clientname, ',');
			  getline(fin, identify, ',');
			  getline(fin, price, ',');
			  getline(fin, fee, ',');
			  getline(fin, discount, ',');
			  getline(fin, deposit, ',');
			  getline(fin, totalPrice);
			  invoice.insertOfFrontListInvoice(invoiceID, cTitle, date, seller, clientname, identify, price, fee, discount, deposit, totalPrice);

		  }
		  fin.close();
		  BillSystem Bill1;
		  string BillID, cbTitle, bdate;
		  string bprice, btotalprice, buyer;
		  string bfee, bdiscount, payEndDate;
		  ifstream fbill("Bill.txt");
		  while (fbill.good()) {
			  getline(fbill, BillID, ',');
			  if (BillID == "") {
				  break;
			  }
			  getline(fbill, cbTitle, ',');
			  getline(fbill, bdate, ',');
			  getline(fbill, buyer, ',');
			  getline(fbill, bprice, ',');
			  getline(fbill, bfee, ',');
			  getline(fbill, bdiscount, ',');
			  getline(fbill, payEndDate, ',');
			  getline(fbill, btotalprice);
			  Bill1.insertOfFrontListBill(BillID, cbTitle, bdate, bprice, btotalprice, buyer, bfee, bdiscount, payEndDate);

		  }
		  fbill.close();
		  cout << "System Loading....." << endl;
		  car1.bubbleSortBySalesDate();
		  system("cls");
		  cout << "              Welcome to Menu Function" << endl << endl;
		  cout << "1. Search Vehicle Function" << endl << "2. Sale Invoice Creating Function" << endl << "3. Bill Creating Function" << endl << "4. Booking Function" << endl
			  << "5. Manage Client Function" << endl << "6. Logout" << endl;
		  cout << "Select the function (1 - 6): ";
		  cin >> select;
		  switch (select) {
		  case 1:
			  system("cls");
			  cout << "Search Function" << endl << endl;
			  car1.searchMenu();
			  menuSalesperson();
			  break;
		  case 2:
			  system("cls");
			  cout << "Sale Invoice";
			  car1.CreateInvoice();
			  menuSalesperson();
			  break;
		  case 3:
			  system("cls");
			  cout << "Bill Creating";
			  car1.CreateBillInvoice();
			  menuSalesperson();
			  break;
		  case 4:
			  system("cls");
			  cout << "Booking";
			  car1.bookingsystem();
			  menuSalesperson();
			  break;
		  case 5:
			  system("cls");
			  cout << "Manage Client";
			  car1.ManageClient();
			  menuSalesperson();
			  break;
		  case 6:
			  system("cls");
			  cout << "Logout Successful!! Thank You";
			  break;
		  default:
			  cout << "Invalid select. Please try again." << endl;
			  break;
		  }

	  }
	  void menuManager() {
		  int select;
		  Carlist car1;
		  string carTitle, carPrice, carRegistration, carMileage;
		  string carFuel, carTransmission, carEngine, carDoor, carColor,
			  carBody, carURL, carSale, customerName, age, gender, status;
		  //read the file
		  ifstream File("carlist.csv");
		  //insert 1 by 1 
		  while (File.good()) {
			  getline(File, carTitle, ',');
			  if (carTitle == "") {
				  break;
			  }
			  getline(File, carPrice, ',');
			  getline(File, carRegistration, ',');
			  getline(File, carMileage, ',');
			  getline(File, carFuel, ',');
			  getline(File, carTransmission, ',');
			  getline(File, carEngine, ',');
			  getline(File, carDoor, ',');
			  getline(File, carColor, ',');
			  getline(File, carBody, ',');
			  getline(File, carURL, ',');
			  getline(File, carSale, ',');
			  getline(File, customerName, ',');
			  getline(File, age, ',');
			  getline(File, gender, ',');
			  getline(File, status);
			  car1.insertOfFrontListCar(carTitle, carPrice, carRegistration, carMileage, carFuel, carTransmission, carEngine, carDoor
				  , carColor, carBody, carURL, carSale, customerName, age, gender, status);

		  }
		  File.close();
		  InvoiceSystem  invoice;
		  string invoiceID, cTitle, date, price;
		  string totalPrice, deposit, fee;
		  string discount, seller, clientname;
		  string identify;
		  ifstream fin("Invoice.txt");
		  while (fin.good()) {
			  getline(fin, invoiceID, ',');
			  if (invoiceID == "") {
				  break;
			  }
			  getline(fin, cTitle, ',');
			  getline(fin, date, ',');
			  getline(fin, seller, ',');
			  getline(fin, clientname, ',');
			  getline(fin, identify, ',');
			  getline(fin, price, ',');
			  getline(fin, fee, ',');
			  getline(fin, discount, ',');
			  getline(fin, deposit, ',');
			  getline(fin, totalPrice);
			  invoice.insertOfFrontListInvoice(invoiceID, cTitle, date, seller, clientname, identify, price, fee, discount, deposit, totalPrice);

		  }
		  fin.close();
		  BillSystem Bill1;
		  string BillID, cbTitle, bdate;
		  string bprice, btotalprice, buyer;
		  string bfee, bdiscount, payEndDate;
		  ifstream fbill("Bill.txt");
		  while (fbill.good()) {
			  getline(fbill, BillID, ',');
			  if (BillID == "") {
				  break;
			  }
			  getline(fbill, cbTitle, ',');
			  getline(fbill, bdate, ',');
			  getline(fbill, buyer, ',');
			  getline(fbill, bprice, ',');
			  getline(fbill, bfee, ',');
			  getline(fbill, bdiscount, ',');
			  getline(fbill, payEndDate, ',');
			  getline(fbill, btotalprice);
			  Bill1.insertOfFrontListBill(BillID, cbTitle, bdate, bprice, btotalprice, buyer, bfee, bdiscount, payEndDate);

		  }
		  fbill.close();
		  cout << "System Loading....." << endl;
		  car1.bubbleSortBySalesDate();
		  system("cls");
		  cout << "              Welcome to Menu Function" << endl << endl;
		  cout << "1. Search Vehicle Function" << endl << "2. Sale Invoice Creating Function" << endl << "3. Bill Creating Function" << endl << "4. Booking Function" << endl
			  << "5. Manage Client Function" << endl << "6. Report Function " << endl << "7. Logout" << endl;
		  cout << "Select the function (1 - 7): ";
		  cin >> select;
		  switch (select) {
		  case 1:
			  system("cls");
			  cout << "Search Function" << endl << endl;
			  car1.searchMenu();
			  menuManager();
			  break;
		  case 2:
			  system("cls");
			  cout << "Sale Invoice";
			  car1.CreateInvoice();
			  menuManager();
			  break;
		  case 3:
			  system("cls");
			  cout << "Bill Creating";
			  car1.CreateBillInvoice();
			  menuManager();
			  break;
		  case 4:
			  system("cls");
			  cout << "Booking";
			  car1.bookingsystem();
			  menuManager();
			  break;
		  case 5:
			  system("cls");
			  cout << "Manage Client";
			  car1.ManageClient();
			  menuManager();
			  break;
		  case 6:
			  system("cls");
			  cout << "Report Function";
			  car1.GenerateReport();
			  menuManager();
			  break;
		  case 7:
			  system("cls");
			  cout << "Logout Successful!! Thank You";
			  break;
		  default:
			  cout << "Invalid select. Please try again." << endl;
			  break;
		  }

	  }


};

int main() {

	Staff staff1;
	string staffID; //data
	string staffName;
	string staffPassword;
	string staffPosition;
	ifstream fstaff("staff.txt");
	while (fstaff.good()) {
		getline(fstaff, staffID, ',');
		if (staffID == "") {
			break;
		}
		getline(fstaff, staffName, ',');
		getline(fstaff, staffPassword, ',');
		getline(fstaff, staffPosition);
		staff1.InsertToFrontOfList(stoi(staffID), staffName, staffPassword, staffPosition);
	}
	fstaff.close();
	staff1.isLogin();

}