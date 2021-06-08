//Library Database
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <bitset>
#include <vector>
#include <algorithm>
#include <fstream>

//Setting the std so we can get rid of writting std::cout or std::cin
using namespace std;
//function devlaration
int numValidator(int num);

//Book class with pointer and a constuctor with methods 
class books
{
    char** author, ** authortwo, ** authorthree, ** authorfour, ** title, ** availible;
    char** borrowing_date;
    static int count;
public:

    books(void);   //constructor
    void getdata(void);
    void display_stock(void);
    void search(void);
    void display_availible(void);
    void titles_resurved(void);
    void record_in_txt(void);
};

//Global variable for number of authors of all books
int author_num[100];
//Global derivative variable for the book class 
int books::count = 0;

//derivative class for the book class
books::books(void)
{
    //declaring pointers to the priveta variables in the book class and setting theyr size
    author = new char* [15];
    authortwo = new char* [15];
    authorthree = new char* [15];
    authorfour = new char* [15];

    title = new char* [15];
    availible = new char* [15];
    borrowing_date = new char*[15];
    //filling all the book date from user inputs
    for (int i = 0; i < 15; i++)
    {
        author[i] = new char;
        authortwo[i] = new char;
        authorthree[i] = new char;
        authorfour[i] = new char;
        title[i] = new char;
        availible[i] = new char;
        borrowing_date[i] = new char;
    }
}


//Function for inputing new books 
void books::getdata(void)
{
   

    cout << "\n\n\nInstead of space use _ or . Examplne : The_Story_OF_Jon\n";
    cout << " Enter Book name :";
    cin >> title[count];
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter number of  Authors Minimum 1 - Maximum 4 (incase of a different number Defaulth value 1 will be set):";
    cin >> author_num[count];
    author_num[count] = numValidator(author_num[count]);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //Validaring for correct input of number of authors
    if (author_num[count] < 1 || author_num[count] >4) { author_num[count] = 1; }
    //Deppeing on the unput you will get N number of inputs for the authors
    if (author_num[count] ==1) {
        cout << "Enter Author name 1:";
        cin >> author[count];
    }
    if (author_num[count] == 2) {
        cout << "Enter Author name 1:";
        cin >> author[count];
        cout << "Enter Author name 2:";
        cin >> authortwo[count];
    }
    if (author_num[count] == 3) {
        cout << "Enter Author name 1:";
        cin >> author[count];
        cout << "Enter Author name 2:";
        cin >> authortwo[count];
        cout << "Enter Author name 3:";
        cin >> authorthree[count];
    }
    if (author_num[count] == 4) {
        cout << "Enter Author name 1:";
        cin >> author[count];
        cout << "Enter Author name 2:";
        cin >> authortwo[count];
        cout << "Enter Author name 3:";
        cin >> authorthree[count];
        cout << "Enter Author name 4:";
        cin >> authorfour[count];
    }
    cout << "Enter Available is the book availible 'Yes' or 'No':";
        cin >> availible[count];
    cout << "Enter Borrowing Date (Example input 26/06/201): ";
        cin >> borrowing_date[count];
    count++;
   
}
//Function to dispay all the currently inputed books
void books::display_stock(void)
{
    system("CLS");
    cout << "\n\n\n";
        cout << setw(15) << "Book Name"<<setw(20)<<"Author Name/s"<<setw(20)<<"Availible"<<setw(20)<<"Borrowing Date"<<endl<<endl;
        cout << "---------------------------------------------------------------------------------------------- \n";
        //Looping thout all of the book and printing them respectively
        for (int i = 0; i < count; i++)
        {
            
            cout << setw(15) << title[i] << setw(20) << author[i] << setw(20) << availible[i] << setw(20) << borrowing_date[i] << endl;
            //Validator if there is more then 1 author of a given book
            if (author_num[i] == 2 || author_num[i] == 3 || author_num[i] == 4) { cout << setw(35) << authortwo[i] << endl; };
            if (author_num[i] == 3 || author_num[i] == 4) { cout << setw(35) << authorthree[i] << endl; };
            if (author_num[i] == 4) { cout << setw(35) << authorfour[i] << endl; };
            cout << "---------------------------------------------------------------------------------------------- \n";
        }
    cout << "\n\nTotal Number of Books Names are "<<count;
}
//Function for searching books by name and author
void books::search(void)
{
    system("CLS");
    char  name[20], writer[20];
    cout << "\nnEnter Book name:";
    cin >> name;
    cout << "Enter Author of Book:";
    cin >> writer;
    //Looping trought all the books for the searched results and printing them out
    for (int i = 0; i < count; i++)
    {
        if ((strcmp(title[i], name) == 0) && (strcmp(author[i], writer) == 0))
        {
            cout << "\n\nEntered Information Book Available\n";
            cout << "Borrowing Date: " << borrowing_date[i];
            break;
        }
    }
    cout << "\n\nBook is not Available in stock\n";
    
}

// Funtions for alphabetic ordering of the authors
bool mycomp(string a, string b) {
    return a < b;
}
//Checks for wich letter is bigger then the other meaning bigger possitions
//Letter in C++ can also be represented as a binary values (number)
vector<string> alphabaticallySort(vector<string> a) {
    int n = a.size();
    sort(a.begin(), a.end(), mycomp);
    return a;

}

//////////////////////////////////////////////

void books::display_availible(void)
{
    system("CLS");
    cout<< "Currently available books, arranged alphabetically by authors: ";
    //Opening a vector to store the Author names
    vector<string> names;
    string name;
    int correct_possition[100];
    int counter = 0;
    string y = "y";
    string yes = "yes";
    string Yes = "Yes";
    //Loop to sotre only if the availible is set to Yes yes or y
    for (int i = 0; i < count; i++)
    {
        cout << availible[i];
        if (availible[i] == Yes || availible[i] == yes || availible[i] == y)
        {
            names.push_back(author[i]);
        }
    }
    //Initializing the function for alphabetic sorting of the author names and saving the correcnt new possitions 
    // to the correct_possition array with the counter as an index
    names = alphabaticallySort(names);
    for (int i = 0; i < names.size(); i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (names[i] == author[j]){
                correct_possition[counter] = j;
                counter++;
            }
        }
    }
    //Loop for the alhabetic order 
    int corr_index;
    cout << "\n\n\n";
    cout << setw(15) << "Book Name" << setw(20) << "Author Name/s" << setw(20) << "Availible" << setw(20) << "Borrowing Date" << endl << endl;
    cout << "---------------------------------------------------------------------------------------------- \n";
    for (int i = 0; i < counter; i++)
    {
        //Printing in the alphabetig order
        corr_index = correct_possition[i];
       

        cout << setw(15) << title[corr_index] << setw(20) << author[corr_index] << setw(20) << availible[corr_index] << setw(20) << borrowing_date[corr_index] << endl;
        //Validator for more then 1 author
        if (author_num[corr_index] == 2 || author_num[corr_index] == 3 || author_num[corr_index] == 4) { cout << setw(35) << authortwo[corr_index] << endl; };
        if (author_num[corr_index] == 3 || author_num[corr_index] == 4) { cout << setw(35) << authorthree[corr_index] << endl; };
        if (author_num[corr_index] == 4) { cout << setw(35) << authorfour[i] << endl; };
        cout << "---------------------------------------------------------------------------------------------- \n";
    }
   
};


//Validator for all numbers
int numValidator(int num) {
    //if its a number it passes it back without looping
    if (std::cin.good()) {
        return num;
    }
    //Infinity loop untill the user input a number
    while (cin.fail())
    {
        std::cout << "Please enter numbers only: \n";
        std::cin.clear();
        std::cin.ignore(20000, '\n');
        std::cout << "Try again: \n";
        cin >> num;
        if (std::cin.good()) {
            return num;
        }
    }

};
// Function to check for book titles wich are resurved for the inputed date
void books::titles_resurved(void) {
    system("CLS");
    //Declaring set string n,no,No and the input string wich will recive the user input 
    string searched_date;
    string n = "n";
    string no = "no";
    string No = "No";
    string titles_to_dispaly[100];
    int counter = 0;

    cout << "Enter a date to check for unavailible book titles: \n";
    cout << "Example input 04/12/2021 \n";
    cout << "day/mothn/year\n";
    cout << "Enter Date:";
    cin >> searched_date;
   
    //Loop to check for unavailible book titles on the user inputed date and stroing in titles_to_dispaly
    for (int i = 0; i < count; i++)
    {
        if ((availible[i] == No || availible[i] == no || availible[i] == n) && borrowing_date[i] == searched_date)
        {
            titles_to_dispaly[counter] = title[i];
            counter++;
        }
     
    }
    //Printing titles_to_dispaly -> the correct values that were saved 
    cout << "\n\nResurved Titles of book on date : " << searched_date << "\n";
    for (int i = 0; i < counter; i++)
    {
        cout << "Title number "<< i+1 << " :" << titles_to_dispaly[i] << "\n";
    }



}
//Function to record all the books with more then one author 
void books::record_in_txt(void) {
    system("CLS");
    //Open file to write in it OR create one 
    ofstream myfile;
    myfile.open("library.txt");

    myfile << setw(15) << "Book Name" << setw(20) << "Author Name/s" << setw(20) << "Availible" << setw(20) << "Borrowing Date" << endl << endl;
    myfile << "----------------------------------------------------------------------------------------------------------------- \n";
    //Looping thout all of the book and saving only the books with 2 or more authors in the txt file
    for (int i = 0; i < count; i++)
    {
 
        //Validator if there is more then 1 author of a given book
        if (author_num[i] == 2 || author_num[i] == 3 || author_num[i] == 4) {
         myfile << setw(15) << title[i] << setw(20) << author[i] << setw(20) << availible[i] << setw(20) << borrowing_date[i] << endl;
         myfile << setw(35) << authortwo[i] << endl;
         myfile << setw(35) << authorthree[i] << endl;
         myfile << setw(35) << authorfour[i] << endl;
         myfile << "--------------------------------------------------------------------------------------------- \n";
        };
       
    }
    //Closing the file
    myfile.close();
    cout << "Everything has been recorded in library.txt";
}
//Main function that opens the menu for options
void main()
{
    //clears console
    system("CLS");
    //Declaring a book class to open all the method in the constructor as options
    books methods;
    bool menuOn = true;
    int choice;
    //To loop on the menu untill you press 7
    while (menuOn)
    {   
        //Dispaly options
        cout << "\n\nChoose your choice \n";
            cout << "1) Entering Information for book \n";
            cout << "2) To See Actual stock \n";
            cout << "3) To Search for a Particular book \n";
            cout << "4) Display information about currently available books, arranged alphabetically by authors \n";
            cout << "5) Display titles of books that are resurved on a given date \n";
            cout << "6) Records information about books with more than one author in the library.txt file \n";
            cout << "7) Exit \n";
            cout << "Enter your choice:";
            //Enter you choice
            cin >> choice;
            //Upon charecter input instead of a number
            choice = numValidator(choice);
            //Function to activate on a given number input
        switch (choice)
        {
        case 1: methods.getdata();
            break;
        case 2: methods.display_stock();
            break;
        case 3: methods.search();
            break;
        case 4: methods.display_availible();
            break;
        case 5: methods.titles_resurved();
            break;
        case 6: methods.record_in_txt();
            break;
        case 7: 
            cout << "End of Program.\n";
            menuOn = false;
            break;
            // Upon no matches with the numbers from 1 to 7 
        default: cout << "Enter choice is invalid \nTry again\n";
        }
    }
}
