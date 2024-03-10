#include <iostream>
#include <fstream>
#include <string>
//#include<stdlib.h> 
#include <iomanip>
using namespace std;

 class Administrator
 {
 	protected:
     int pcode;
     float price;
     float dis;
     string pname;  
    
    public:
     void administrator();
     void add();
     void edit();
     void rem();
     
     	
};
class Buyer
{
	protected:
	 int pcode;
     float price;
     float dis;
     string pname;
     
	 public:	
	  void list();
      void receipt();
      void buyer();
      int productsAvailable(); 
		
};
class Shopping : public Administrator,public Buyer   //inherit class shopping from administrator and buyer (multiple inheritance)
 {
 

  public:
    void menu();
   
 };
void Shopping::menu()               //it displays te main menu ofts smbs
 {
    int choice;
    string email;
    string password;

    while (true) 
	{   cout<<endl; cout<<endl; cout<<endl; cout<<endl; cout<<endl;cout<<endl; cout<<endl;cout<<endl;
	    cout << "\t\t\t\t\t\t\t\t\t|------------------------------------------|\n";
        cout << "\t\t\t\t\t\t\t\t\t|__________________________________________|\n";
        cout << "\t\t\t\t\t\t\t\t\t|                                          |\n";
        cout << "\t\t\t\t\t\t\t\t\t|       Super Market Main Menu             |\n";
        cout << "\t\t\t\t\t\t\t\t\t|__________________________________________|\n";
        cout << "\t\t\t\t\t\t\t\t\t|                                          |\n";
        cout << "\t\t\t\t\t\t\t\t\t| 1) Administrator                         |\n";
        cout << "\t\t\t\t\t\t\t\t\t|                                          |\n";
        cout << "\t\t\t\t\t\t\t\t\t| 2) Buyer                                 |\n";
        cout << "\t\t\t\t\t\t\t\t\t|                                          |\n";
        cout << "\t\t\t\t\t\t\t\t\t| 3) Exit                                  |\n";
        cout << "\t\t\t\t\t\t\t\t\t|                                          |\n";
        cout << "\t\t\t\t\t\t\t\t\t| You have to select from above options    |\n";
        cout << "\t\t\t\t\t\t\t\t\t|------------------------------------------|\n";
        cout<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t Enter your choice=>";
        cin>>choice;
        cout<<endl;
        system("CLS");
        switch (choice) {
            case 1:
          	    cout<<endl;
          	    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _   \n";
            	cout<<endl;
            	cout<<endl;
            	cout<<endl;
				cout << "\t\t\t\t\t\t\t\t\t\t ADMINISTRATOR LOGIN PAGE\n";
				cout<<endl;
				cout<<endl;
                cout << "\t\t\t\t\t\t\t\t\t\t **Please login** ";
                cout<<endl;cout<<endl;
                cout << "\t\t\t\t\t\t\t\t\t\t Enter email: ";
                cin >> email;
                cout<<endl;
                cout << "\t\t\t\t\t\t\t\t\t\t Enter password: ";
                cin >> password;
                cout<<endl;

                if (email == "virti@gmail.com" && password == "virti123")  //administrator will login using his/her email id and password
				{
                    administrator();                                       //if email id and password matches then administrator function will be called
                } else 
				{
                    cout <<endl<< "\t\t\t\t\t\t\t\t\tInvalid email/password\n";
                }
                break;

            case 2:
                buyer();
                break;

            case 3:
                exit(0);

            default:
                cout << "\t\t\t\t\t\t\t\t\tPlease select from the given options\n";
        }
    }
}

void Administrator::administrator() 
{    
system("CLS");
    int choice;
    int flag=1;
    while (flag)
	 {
	 	cout<<endl;
    	cout<<endl;
    	cout << "\n\t\t\t\t\t\t\t\t\t********** YOU HAVE ENTERED ADMINISTRATOR MENU PAGE **********";
    	cout<<endl;
    	cout<<endl;
    	cout<<endl;
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|       Administrator Menu       |"; // the folloeing menu will be displayed to the administartor who will add products in his shopping mall
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|                                |";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|______1) Add the product________|";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|                                |";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|______2) Modify the product_____|";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|                                |";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|______3) Delete the product_____|";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|                                |";
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t|______4) Back to the menu_______|";
        cout<<endl<<endl;
        cout << "\n\t\t\t\t\t\t\t\t\t Please enter your choice: ";
        cin >> choice;
        system("CLS");

        switch (choice) 
		{
            case 1:
                add();
                break;

            case 2:
                edit();
                break;

            case 3:
                rem();
                break;

            case 4:
            	flag=0;
                return;

            default:
                cout << "Invalid choice\n";
        }
    }
}
int Buyer::productsAvailable() 
{
    fstream data;
    data.open("database.txt", ios::in);
    if (!data) {
        data.close();
        return 0;  // Returning 0 to indicate no products
    } else {
        int pcode;
        data >> pcode;
        data.close();
        return (pcode > 0) ? 1 : 0;  // Returning 1 to indicate products available
    }
}
void Buyer::buyer() {
    system("CLS");
    int choice;
    
    // Check if there are products available
    system("CLS");
    int productAvailability = productsAvailable();
    system("CLS");
    if (productAvailability == 0) 
	{    
	    system("CLS");
        cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t No products available. Please return to the main menu to add products.\n";
        return;
    }

    while (true) {
        cout << "\t\t\t\t\t\t\t\t\t\t     BUYER MENU\n";
        cout << "\t\t\t\t\t\t\t\t\t\t_____________________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t                     \n";
        cout << "\t\t\t\t\t\t\t\t\t\t 1)  Buy products\n";
        cout << "\t\t\t\t\t\t\t\t\t\t                     \n";
        cout << "\t\t\t\t\t\t\t\t\t\t 2)  Go Back\n";
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t  Please enter your choice: ";
        cin >> choice;
        system("CLS");
        
        switch (choice) {
            case 1:
                if (productAvailability == 1) {
                    receipt();
                } else {
                    cout << "No products available. Please return to the main menu to add products.\n";
                }
                break;
            case 2:
                return;
            default:
                cout << "\t\t\t\t\t\tInvalid choice\n";
        }
    }
}

//adminstrator menu functions
void Administrator::add() {
    fstream data;
    int c;
    bool recordExists = false; // Flag to check if a record with the same product code exists

    cout << endl;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _   \n";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Add new product:\n";
    cout << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product code of the product: ";
    cin >> pcode;
    
    // Reset variables for new product
    pname = ""; // Reset product name
    price = 0;  // Reset price
    dis = 0;    // Reset discount
    
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Name of the Product: ";
    cin.ignore(); // Ignore any remaining newline characters in the buffer
    getline(cin, pname);
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Price of the product: ";
    cin >> price;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Discount on the product: ";
    cin >> dis;

    data.open("database.txt", ios::in);
    
    while (data >> c) {
        string tempName;
        float tempPrice, tempDis;
        data >> tempName >> tempPrice >> tempDis;
        
        if (c == pcode) {
            recordExists = true;
            break; // Exit the loop if a matching product code is found
        }
    }
    data.close();
    
    if (recordExists) 
	{
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t Record already exists!\n";
    } else
	 {
        data.open("database.txt", ios::app | ios::out); //open file in append and output mode
        data << "  " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
        cout << "\n\t\t\t\t\t\t\t\t\t\t\t Record inserted successfully!\n";
    }
}



void Administrator::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
     cout<<endl;
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _   \n";
    cout<<endl; cout<<endl; cout<<endl; cout<<endl; 
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Modify the record:\n";
    cout<<endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
	 {
        cout << "File doesn't exist\n";
    } else {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter Product of new code: ";
                cin >> pcode;
                cout << "\n\t\t\t\t\t\t\t\t\t\t\t Name of the product is: ";
                cin >> pname;
                cout << "\n\t\t\t\t\t\t\t\t\t\t\t Enter the price of the product: ";
                cin >> price;
                cout << "\n\t\t\t\t\t\t\t\t\t\t\t Discount: ";
                cin >> dis;
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << " ";
                cout << "\n\t\t\t\t\t\t\t\t\t\t The record modified succesfully!!\n";
                token++;
            } else {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
		{
            cout << "\n\n \t\t\t\t\tRecord not found! Sorry\n";
        }
    }
}

void Administrator::rem() 
{  
    fstream data, data1;
    int pkey;
    int token = 0;
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _   \n";
    cout<<endl; cout<<endl; cout<<endl;	cout<<endl;	cout<<endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t Delete the product:"<<endl;
    cout << "\n\t\t\t\t\t\t\t\t\t\t Product Code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
	 {
        cout << "File doesn't exist\n";
     } 
	else
	 {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof()) {
            if (pcode == pkey)
			 {
                cout << "\n\t\t\t\t\t\t\t\t\t\tProduct deleted successfully\n";
                token++;
            } 
			else 
			{
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0) {
            cout << "\n\n Record not found\n";
        }
    }
}


	void Buyer::list() {
    fstream data;
    data.open("database.txt", ios::in);

    if (!data) {
        cout << "File doesn't exist\n";
    } else
	 {
	 	cout<<endl; cout<<endl; cout<<endl;	cout<<endl;	cout<<endl;
	
    	cout<<"\t\t\t\t\t\t\t\t  ****  THE PRODUCTS AVAILAIBLE IN MARKET ****";
        cout <<"\n\t\t\t\t\t\t\t\t|=================================================|\n";
        cout <<  "\t\t\t\t\t\t\t\t|                Product List                     |\n";
        cout << "\t\t\t\t\t\t\t\t==================================================|\n";
        cout << "\t\t\t\t\t\t\t\t| Product No |   Name     |  Price    |  Discount |\n";
        cout << "\t\t\t\t\t\t\t\t|=================================================|\n";

        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
           
            cout << "\t\t\t\t\t\t\t\t| " << setw(10) << pcode << " | " << setw(10) << pname << " | " << setw(9) << price << " | " << setw(9) << dis << " |\n";
            data >> pcode >> pname >> price >> dis;
        }

        cout << "\t\t\t\t\t\t\t\t|=================================================|\n";
        data.close();
    }
}



void Buyer::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float total = 0;

    list();

   
    do {
        cout << "\n\n\t\t\t\t\t\t\tEnter Product Code of the item you want to buy: ";
        cin >> arrc[c];
        cout << "\n\t\t\t\t\t\t\tEnter the product quantity: ";
        cin >> arrq[c];

        for (int i = 0; i < c; i++) 
		{
            if (arrc[c] == arrc[i]) 
			{
                cout << "\n\t\t\t\t\t\t\tDuplicate product code. Please try again!\n";
                c--;
                break;
            }
        }

        c++;

        cout << "\n\t\t\t\t\t\t\tDo you want to buy another product? (y/n): ";
        cin >> choice;
        
    } while (choice == 'y' || choice == 'Y');
    system("CLS");
    
    cout << "\n\n\n\t\t\t\t\t****************************************** RECEIPT ****************************************  \n";
    cout<<endl<<endl<<endl;
    cout <<"\t\t\t\t\t"<<"Product Code \t"<<"Product Name \t"<<"Quantity\t"<<"Price \t"<<"  Amount\t"<<" Amount with discount\t\n";
    cout <<" \t\t\t\t\t_______________________________________________________________________________________________\n";

    for (int i = 0; i < c; i++) 
	{
		
        data.open("database.txt", ios::in);  //opening file everytime when we add a product to cart
    
        data >> pcode >> pname >> price >> dis;

        while (!data.eof()) {
            if (pcode == arrc[i]) 
			{
                float amount = price * arrq[i];
                float discount = amount - (amount * dis / 100);
                total += discount;
                cout <<"\t\t\t\t\t"<< setw(12)<<pcode << " " << setw(12) << pname << " "<< setw(12) << arrq[i] << " " << setw(15)<< price << "   " << setw(12)<< amount << " "<< setw(12) << discount<<"\n" ;   
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }
     
	  cout <<" \t\t\t\t\t_______________________________________________________________________________________________\n";
    
    double cgst_rate = 0.025;  // 2.5% CGST
    double sgst_rate = 0.025;  // 2.5% SGST

    double cgst = total * cgst_rate;
    double sgst = total * sgst_rate;
    double finalTotalAmount = total + cgst + sgst;
    
    cout << setprecision(2) << fixed; // Set precision for decimal values
    cout <<"\n\t\t\t\t\t"<< "Tax Type"<< setw(10) << "Amount" << endl;
    cout <<"\n\t\t\t\t\t"<< "CGST "<< setw(10)<< (cgst_rate * 100) << "%" << setw(7) <<"("<<cgst<<")" << endl;
    cout <<"\n\t\t\t\t\t"<< "SGST "<< setw(10)<< (sgst_rate * 100) << "%" << setw(7) << "("<<sgst<<")" << endl;
     cout <<" \t\t\t\t\t_______________________________________________________________________________________________\n";
    char carryBagChoice;
    cout << "\n\t\t\t\t\t Do you want a carry bag? (y/n): ";
    cin >> carryBagChoice;
    if (carryBagChoice == 'y' || carryBagChoice == 'Y') 
	{
        finalTotalAmount =finalTotalAmount+ 15; // Add 15 Rs for the carry bag
    }
    string payment_method;  // Collecting payment information
    cout << "\n\t\t\t\t\t Payment method (Cash/Card): ";
    cin >> payment_method;   
    string phone_number;
    cout << "\n\t\t\t\t\t Enter your phone number: ";
    cin >> phone_number;
    cout<<endl;
    cout <<" \t\t\t\t\t_______________________________________________________________________________________________\n";
    cout <<"\n\t\t\t\t\t\t\t\t"<< setw(20) << "GRAND TOTAL" << setw(10) <<"Rs "<<finalTotalAmount << endl;
    cout <<" \t\t\t\t\t_______________________________________________________________________________________________\n";
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t THANKYOU FOR SHOPPING WITH US , VISIT AGAIN !!";
    cout << "\n\n\t\t\t\t\t************************************************************************************************\n";
    char d;
    cout<<"\n\n\n\t\t\t\t\tEnter any character to go back to menu";
    cin>>d;
    system("CLS");
}

int main()
 {
    Shopping s;
    s.menu();
    return 0;
}

