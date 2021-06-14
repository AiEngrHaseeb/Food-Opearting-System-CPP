#include <iostream> //input/output stream provides with cin and cout function
#include <windows.h> //provides system functions like sleep function etc 
#include <cstdlib>	//c standard library provides random numbers function
#include <conio.h>	//C header file used mostly by MS-DOS compilers to provide console input/output. Here used for getch()
#include <fstream>	//file stream, provides with filee input/output functions
#include <string> //string library
using namespace std;

void admin()
{
	ifstream admin;
	admin.open("orderhistory.bin");
	string line;
	while(!admin.eof())
	{
		getline(admin, line);
		cout << line <<endl;
	}
	admin.close();
}
void admin1()
{
	ifstream suggest;
	suggest.open("suggestions.txt");
	string line;
	while(!suggest.eof())
	{
		getline(suggest, line);
		cout << line <<endl;
	}
	suggest.close();
}

void suggest()
{
		char myChars[256];
		string suggest, name, yes;
		cout<<"Name: ";
		cin.ignore();
		getline(cin, name);
		cout<<"Suggestion: ";
		cin.ignore();
		cin.getline(myChars,256);
		ofstream sugg;
		sugg.open("suggestions.txt", ios::app);
		sugg << "\t" << name << ":\t\t" << myChars <<endl;
		sugg.close();
				
}

void logo(){
	
	ifstream logo;
	logo.open("logo.bin");
	string line;
	while(!logo.eof())
	{
		getline(logo, line);
		cout << line <<endl;
	}
	logo.close();
		
}

void menu()
{
	
	cout<<"\n\t\t\t\t\t\t                  [1] Veggie Supreme\t\t(Rs.480)"  <<endl;
	cout<<"\t\t\t\t\t\t                  [2] Chicken Sizzler\t\t(Rs.580)"   <<endl;
	cout<<"\t\t\t\t\t\t                  [3] Spaghetti\t\t\t(Rs.350)"       <<endl;
	cout<<"\t\t\t\t\t\t                  [4] Tetrazzini\t\t(Rs.420)"        <<endl;
	cout<<"\t\t\t\t\t\t                  [5] Makizushi\t\t\t(Rs.548)"       <<endl;
	cout<<"\t\t\t\t\t\t                  [6] Margherita Pizza\t\t(Rs.525)"  <<endl;
	cout<<"\t\t\t\t\t\t                  [7] Fish 'n' Chips\t\t(Rs.425)"    <<endl;
	cout<<"\t\t\t\t\t\t                  [8] Fajitas\t\t\t(Rs.335)"         <<endl;
	cout<<"\t\t\t\t\t\t                  [9] Tempura\t\t\t(Rs.324)"			<<endl;
	cout<<"\t\t\t\t\t\t                  [10] Hot Dog\t\t\t(Rs.360)"        <<endl;
	cout<<"\n\t\t\t\t\t\t\t                     [11] Logout"					<<endl;
	cout<<"\t\t\t\t\t\t\t                     [0] Suggestions"					<<endl;
}


int main ()
{
	//main variables
	int i,input,input1,paid,remaining;
	int total = 0;
	string username,n2,yes,no,pass = "";
	string suggesti, first_name;
	
	//menu strings
	string a1 = "Veggie Supreme";
	string a2 = "Chicken Sizzler";
	string a3 = "Spaghetti";
	string a4 = "Tetrazzini";
	string a5 = "Makizushi";
	string a6 = "Margherita";
	string a7 = "Fish 'n' Chips";
	string a8 = "Fajitas";
	string a9 = "Tempura";
	string a10 = "Hot Dog";
	
		system("color 9"); //changes to blue color
		cout<<"\n\n\n\n\n\n\t\t\t\t\t\t _____               _ ";
		cout<<"\n\t\t\t\t\t\t|  ___|__   ___   __| |";
		cout<<"\n\t\t\t\t\t\t| |_ / _ \\ / _ \\ / _` |";
		cout<<"\n\t\t\t\t\t\t|  _| (_) | (_) | (_| |";
		cout<<"\n\t\t\t\t\t\t|_|  \\___/ \\___/ \\__,_|";
		Sleep (1000);
		cout<<"\n\t\t\t\t\t\t\t  ___          _           _";
		cout<<"\n\t\t\t\t\t\t\t / _ \\ _ __ __| | ___ _ __(_)_ __   __ _";
		cout<<"\n\t\t\t\t\t\t\t| | | | '__/ _` |/ _ \\ '__| | '_ \\ / _` |";
		cout<<"\n\t\t\t\t\t\t\t| |_| | | | (_| |  __/ |  | | | | | (_| |";
		cout<<"\n\t\t\t\t\t\t\t\\___/|_|  \\__,_|\\___|_|  |_|_| |_|\\__,  |";
		cout<<"\n\t\t\t\t\t\t\t                                    |___/ ";
		Sleep (1000);
		cout<<"\n\t\t\t\t\t\t\t\t                _";
		cout<<"\n\t\t\t\t\t\t\t\t  ___ _   _ ___| |_ ___ _ __ ___";
		cout<<"\n\t\t\t\t\t\t\t\t / __| | | / __| __/ _ \\ '_ ` _ \\ ";
		cout<<"\n\t\t\t\t\t\t\t\t \\__ \\ |_| \\__ \\ ||  __/ | | | | |";
		cout<<"\n\t\t\t\t\t\t\t\t |___/\\__, |___/\\__\\___|_| |_| |_|";
		cout<<"\n\t\t\t\t\t\t\t\t      |___/\n\n\n\n\n";
		Sleep (1000);
		system("cls");

	
	again1: //flag point for returning to login screen
	
	system("color 2"); // changes text color to green
	cout<<"\n\n\n\n\n\n\n\n"<<endl;
	cout<<"\t\t\t\t\t\t\t\t     Welcom to Food Ordering System"<<endl;
	cout<<"\n\n\t\t\t\t\t\t\t\t\tPlease enter username: ";
	cin>>username;
	cout<<"\t\t\t\t\t\t\t\t\tPlease enter password: ";
	
	//shows **** instead of real password
		char ch;
		ch = _getch();
	while(ch != 13 ) //character 13 is enter key
    {  
	  	pass.push_back(ch); //function is used to push elements into the vector from the back
      	cout << '*';
      	ch = _getch();
	}
	
   	//condition to login into admin or user account
   if(username == "admin" && pass == "pass1")
   {
   	system("cls"); // opens a section in new window
   	system("color 7");
   	cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t   Welcome Admin!" << endl << endl;
   	cout << "\t\t\t\t\t\t\t\t\t   Orders History " << endl << endl;;
   	cout << "1- Orders History" <<endl;
   	cout << "2- Customer Suggestions" <<endl;
   	cout << "3- Logout" <<endl;
	   	int admin_input;
	   	do{
		   
	   	cin >> admin_input;
	   	cout << endl;
	   	if(admin_input == 1)
		   {
		   admin();
		   cout << endl;
		   }
		   else if(admin_input == 2)
		   {
		   admin1();
		   cout << endl;
		   }
			else if(admin_input == 3)
   			{
   			system("cls");
	   		goto again1; // taskes back to login screen
	   		}
	   	}while(admin_input != 4);
   }
   else if(username == "user" && pass == "pass1")
	{
      cout << "\n\n\n\t\t\t\t\t\t\t\t\t     Access granted \n";
      Sleep(300); // pausing screen 300 msecs
   
   	again: //flag point for returning to menu screen
		
	system("cls"); // opens a section in new window
	system("color 3"); // changes text color to skyblue
	
	logo();
	
	//Menu Labels
  	menu();
	
	//price variables
	int q,w,e,r,t,y,u,o,p,l;
	
	cout<<"\n\t\t\t================================================================================================================================"<<endl;
	
	//storing orders to  orders.txt
	ofstream order; // Declaring the object
	ofstream admin;
	order.open("orders.txt", ios::binary); //Creating file
	admin.open("orderhistory.bin", ios::app );
	order << "\t\t\t\t\t\t\t\t\t\tOrders"<<endl;
	order << "\t\t\t\t\t\tBill No : LHR"<<(rand() % 300) + 1<<"\t\t              		Order No: BU"<<(rand() % 1000) + 1<<endl;
	admin << "\t\t\t\t\t\tBill No : LHR"<<(rand() % 300) + 1<<"\t\t                		Order No: BU"<<(rand() % 1000) + 1<<endl;
	admin << "\t\t\t\t\t\t\t\t\t\tOrders"<<endl;
	
	do 
	{
	cout<<"Please Enter a Selection: ";
	order << "\n\t\t\t\t\t\tName\t\t\t     Quantity\t\t\t        Price\n"<< endl;
	admin << "\n\t\t\t\t\t\tName\t\t\t     Quantity\t\t\t        Price\n"<< endl;
	cin>> input;
	if(input == 11)
	goto end; //if user entered 11, program will be closed
	else if(input == 0)
	{
		suggest(); // suggestion function
		cout << "Do you want to make order? (y or n)" <<endl;
		cin >> yes;
		if(yes == "y") //condition, if true menu will be presented
		goto again;
		else
		{
		system("cls");
		goto again1; 
		}
	}
	cout<< "Quantity: ";
	cin >> input1 ;
	
	if(input == 1)
	{
		q = 480*input1;
		total += q; //calculates grand total one by one
	order <<"\t\t\t\t\t\t"<< a1 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<q<<endl;
	admin <<"\t\t\t\t\t\t"<< a1 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<q<<endl;
	}
	else if(input == 2)
	{
		w = 580*input1;
		total += w;
	order <<"\t\t\t\t\t\t"<< a2 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<w<<endl;
	admin <<"\t\t\t\t\t\t"<< a2 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<w<<endl;
	}
	else if(input == 3)
	{
		e = 350*input1;
		total += e;
	order <<"\t\t\t\t\t\t"<< a3 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<e<<endl;
	admin <<"\t\t\t\t\t\t"<< a3 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<e<<endl;
	}	
	else if(input == 4)
	{
		r = 420*input1;
		total += r;
	order <<"\t\t\t\t\t\t"<< a4 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<r<<endl;
	admin <<"\t\t\t\t\t\t"<< a4 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<r<<endl;
	}	
	else if(input == 5)
	{
		t = 548*input1;
		total += t;
	order <<"\t\t\t\t\t\t"<< a5 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<t<<endl;
	admin <<"\t\t\t\t\t\t"<< a5 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<t<<endl;
	}
	else if(input == 6)
	{
		y = 525*input1;
		total += y;
	order <<"\t\t\t\t\t\t"<< a6 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<y<<endl;
	admin <<"\t\t\t\t\t\t"<< a6 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<y<<endl;
	}
	else if(input == 7)
	{
		u = 425*input1;
		total += u;
	order <<"\t\t\t\t\t\t"<< a7 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<u<<endl;
	admin <<"\t\t\t\t\t\t"<< a7 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<u<<endl;
	}
	else if(input == 8)
	{
		o = 335*input1;
		total += o;
	order <<"\t\t\t\t\t\t"<< a8 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<o<<endl;
	admin <<"\t\t\t\t\t\t"<< a8 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<o<<endl;
	}
	else if(input == 9)
	{
		p = 324*input1;
		total += p;
	order <<"\t\t\t\t\t\t"<< a9 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<p<<endl;
	admin <<"\t\t\t\t\t\t"<< a9 <<"\t\t\t"<< input1 <<"\t\t\t\t"<<p<<endl;
	}
	else if(input == 10)
	{
		l = 360*input1;
		total += l;
	order <<"\t\t\t\t\t\t"<< a10 <<"\t\t\t"<< input1 <<"\t\t\t"<<l<<endl;
	admin <<"\t\t\t\t\t\t"<< a10 <<"\t\t\t"<< input1 <<"\t\t\t"<<l<<endl;
	}
	cout << "Do you want more? (y or n) ";
	cin >> no;
	
	i++;
	}while(no != "n" ); //end of do while
	
	order <<"\n\t\t\t\t\t\t\t\t\t\t\t\t    Grand Total "<< total<<endl;
	admin <<"\n\t\t\t\t\t\t\t\t\t\t\t\t    Grand Total "<< total<<endl;
	order.close(); //closing the file before outputing
	admin.close();
	//outputs the contents of the file (orders.txt)
	ifstream orderfile; //new object
	orderfile.open("orders.txt");

	if(!orderfile.is_open()) //if file couldn't be created then the user will be notified
	{
		cout<<"Error opening file"<<endl;
		exit(1); // returns status 1 which indicates that file was'nt created
	}
	else 
	{
		system("color 6");
		system("cls");
		while(orderfile)
		{
		getline(orderfile, n2);
		cout << n2 <<endl;
		}
	}
		
			Sleep(500); // pausing screen 500 secs
			cout<<"\n\t======================================================================================================================================="<<endl;
			cout<<"\n\t\t\t\t\t\t   THANK YOU FOR YOUR ORDER, GENERATING BILL ";
   		for(int a=1;a<5;a++) //loop for printing ...
	{
		Sleep(500); // pausing screen m500 secs
		cout << "...";
	}
			do{
	
			system("cls");
			system("color 4"); // changes text color to red
			cout << "\n\n\n\t\t\t\t\t\t\t           ========================================"<<endl;
			cout << "\t\t\t\t\t\t\t      =================================================="<<endl;
			cout << "\t\t\t\t\t\t\t ============================================================"<<endl;
			cout << "\t\t\t\t\t\t\t||                                                          ||"<<endl;
			cout << "\t\t\t\t\t\t\t||                   Food Ordering System                   ||"<<endl;
			cout << "\t\t\t\t\t\t\t||                                                          ||"<<endl;
			cout << "\t\t\t\t\t\t\t ============================================================"<<endl;
			cout << "\t\t\t\t\t\t\t      =================================================="<<endl;
			cout << "\t\t\t\t\t\t\t           ========================================"<<endl;
			cout << endl;
			cout << "\t\t\t\t\t\t\t ============================================================="<<endl;
			cout << "\t\t\t\t\t\t\t  Bill No : LHR"<<(rand() % 500) + 1<<"\t\t                Order No: BU"<<(rand() % 1000) + 1<<endl;
			
			cout << endl;
			cout << "\t\t\t\t\t\t\t  Cashier :  \t\t\t\t\tQasim Haseeb Amir"<<endl;
    	    cout<<"\n\t\t\t\t\t\t\t  Total:\t\t\t\t\t"<<total<<endl;
			cout <<"\t\t\t\t\t\t\t  Amount paid: \t\t\t\t\t";
			cin>>paid;
		}while(paid <total); // keep runing untill user pays more than or equal to the total amount
			remaining = paid - total;
			cout <<"\t\t\t\t\t\t\t  Remaining: \t\t\t\t\t"<<remaining<<endl;
            cout << "\t\t\t\t\t\t\t ============================================================="<<endl;

			system("pause"); //pasues screen till user hit enter
	
			system("cls");
		goto again;	
			
	} // end of if login
   else
   {
      cout << "\n\n\n\t\t\t\t\t\t\t\t\t     Access aborted...\n";
   			system("cls"); // opens a section in new window
		   goto again1;
   }
	
	end: //if input is 11, program will be  closed
	
	return 0;
}
