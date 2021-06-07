#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
//Disable CRT Secure Warnings
#pragma warning(disable:4996)

using namespace std;

//Methods Used (Functions)
int numValidator(int num);
long long longValidator(long long num);
void display_examin_lastMonth();
void display_info_patientsWithComplains();
void display_most_common_diagnosis();
void enter_and_save_Patients();
void delete_patient();


//Define Class Date
class Date {
private:
    // Private attribute
    string day;
    string month;
    string year;
    string full_date;


public:
    //Defaulth Constructor + Setter
    Date() {
        full_date = "01/01/2021";
    }
    // Non-default Constructor (parameterized) + Setter
    Date(string d, string m, string y) {
        day = d;
        month = m;
        year = y;
        full_date = day + "/" + month + "/" + year;
    }
    //getter
    string getter() {
        
        return full_date;
    }
};

//Define Class Patient
class Patient {
    public:
        // Public attribute
        long  egn;
        string patient_name;
        string complaints;
        string checkup_date;
        string past_complains;
        string diagnosis;
        string medicine[5];

        //Constructor with parameters
        Patient(long  e, string p, string c,string ch,string pco, string d, string m0, string m1, string m2, string m3, string m4) {
                egn = e;
                patient_name = p;
                complaints = c;
                checkup_date = ch;
                past_complains = pco;
                diagnosis = d;
                medicine[0] = m0;
                medicine[1] = m1;
                medicine[2] = m2;
                medicine[3] = m3;
                medicine[4] = m4;
        }
};


int main()
{
    
    int choice;
    bool menuOn = true;
    int numChecker;
    //Open menu with options
    while (menuOn != false) {
        system("CLS");
        cout << "**********************************************************************\n";
        cout << "* 1 - Display information about patients examined in the last month .*\n";
        cout << "* 2 - Displaying information for patients with complaints.           *\n";
        cout << "* 3 - Determining the most common diagnosis.                         *\n";
        cout << "* 4 - Enter a new patient.                                           *\n";
        cout << "* 5 - Delete all patients.                                           *\n";
        cout << "* 6 - Exit.                                                          *\n";
        cout << "**********************************************************************\n";
        cout << "Enter your choice and press ENTER: ";
        
        cin >> choice; 
        choice = numValidator(choice);
   
            switch (choice)
            {
            case 1:
                display_examin_lastMonth();
                break;
            case 2:
                display_info_patientsWithComplains();
                break;
            case 3:
                display_most_common_diagnosis();
                break;
            case 4:
                enter_and_save_Patients();
                break;
            case 5:
                delete_patient();
                break;
            case 6:
                cout << "End of Program.\n";
                menuOn = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again:";
                cin >> choice;
                break;
            }
        
    }
    return 0;
}

void enter_and_save_Patients() {

    long long  e;       int loop;
    int day;       int month;
    int year;

    string p;    string m0;
    string c;    string m1;
    string ch;   string m2;
    string pco;  string m3;
    string d;    string m4; 
    string day_valid;
    string month_valid;
    string year_valid;

    cout << "Enter EGN: ";
    cin >> e;
    e = longValidator(e);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter Patients Name: ";
    std::getline(std::cin, p);
    cout << "Enter Complaints: \n";
    cout << "If there are no complains just press ENTER: \n";
    std::getline(std::cin, c);
    cout << "Enter The Check Up date (example 03/04/2021) Wrong input will lead to a defualth date '01/01/2021':\n";
    cout << "Enter Day: ";
    cin >> day;
    day = numValidator(day);
    cout << "Enter Month: ";
    cin >> month;
    month = numValidator(month);
    cout << "Year must be between '1980' and '2021':\n";
    cout << "Enter Year: ";
    cin >> year;
    year = numValidator(year);

    // Validate date to have 0 if it is 1 expalne 1 -> 01
    if (day <= 31 && day >=1 && month<=12 && month >= 1 && year <= 2021 && year >= 1980) {
        
        if (day<10 && day >=1) {
            day_valid = "0" + std::to_string(day);
        }
        else { day_valid =std::to_string(day); }
        if (month < 10 && month >= 1) {
            month_valid = "0" + std::to_string(month);
        }
        else { month_valid = std::to_string(month); }
        
        year_valid = std::to_string(year);

        Date date(day_valid, month_valid, year_valid);
        ch = date.getter();
    }
    else {
        Date defaultDate;
        ch = defaultDate.getter();
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter Past Complaints: ";
    std::getline(std::cin, pco);
    cout << "Enter a Diagnosis: ";
    std::getline(std::cin, d);

    cout << "Enter the number of medicine prescribed: ";
    cin >> loop;
    loop = numValidator(loop);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //Validator for correct number of medicine
    while (loop > 5 || loop < 1)
    {
        cout << "The number of prescribed medicine has to be min 1 - max 5:\n ";
        cout << "Enter the number of medicine prescribed: ";
        cin >> loop;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < loop; i++)
    {
        if (i == 0) {
            cout << "Enter medicine [1]: ";
            std::getline(std::cin, m0);
        }
        if (i == 1) {
            cout << "Enter medicine [2]: ";
            std::getline(std::cin, m1);
        }
        if (i == 2) {
            cout << "Enter medicine [3]: ";
            std::getline(std::cin, m2);
        }
        if (i == 3) {
            cout << "Enter medicine [4]: ";
            std::getline(std::cin, m3);
        }
        if (i == 4) {
            cout << "Enter medicine [5]: ";
            std::getline(std::cin, m4);
        }


    }

    Patient newPatient(e, p, c, ch, pco, d, m0, m1, m2, m3, m4);
    //Open file and append the inputed date for a new patient
    ofstream outfile;
    outfile.open("patients.txt", std::ios_base::app); // append instead of overwrite
    outfile << "-----------------------------------------\n";
    outfile << newPatient.egn << "\n";
    outfile << newPatient.patient_name << "\n";
    outfile << newPatient.complaints << "\n";
    outfile << newPatient.checkup_date << "\n";
    outfile << newPatient.past_complains << "\n";
    outfile << newPatient.diagnosis << "\n";

    if (loop == 0) {
        outfile << newPatient.medicine[0] << "\n";
    }
    if (loop == 1) {
        outfile << newPatient.medicine[0] << "\n";
        outfile << newPatient.medicine[1] << "\n";
    }
    if (loop == 2) {
        outfile << newPatient.medicine[0] << "\n";
        outfile << newPatient.medicine[1] << "\n";
        outfile << newPatient.medicine[2] << "\n";
    }
    if (loop == 3) {
        outfile << newPatient.medicine[0] << "\n";
        outfile << newPatient.medicine[1] << "\n";
        outfile << newPatient.medicine[2] << "\n";
        outfile << newPatient.medicine[3] << "\n";
    }
    if (loop == 4) {
        outfile << newPatient.medicine[0] << "\n";
        outfile << newPatient.medicine[1] << "\n";
        outfile << newPatient.medicine[2] << "\n";
        outfile << newPatient.medicine[3] << "\n";
        outfile << newPatient.medicine[4];
    }
    outfile <<"-----------------------------------------\n";
};
//Validator for all numbers
int numValidator(int num) {
        if (std::cin.good()) {
            return num;
        }
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
//Validator function for bigger numbers (EGN)
long long longValidator(long long num) {
    if (std::cin.good()) {
        return num;
    }
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
////////////////////////
void display_examin_lastMonth() {
    //Current month
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    string curr_month = std::to_string(timePtr->tm_mon);

    string yes;
    string curr_line;
    int correct_possitions[100] = { 0 };
    int line_counter = 1;
    int correct_position_counter = 0;
    int a = 5;
    

    //Open Txt file to Read
    std::ifstream file("patients.txt");
    if (file.is_open()) {
        std::string line;
        //Loop to save correct possitions
        while (std::getline(file, line)) {

            if (line_counter == a) {
                curr_line = line.c_str();

                if (curr_month[0] == curr_line[4]) {
                    correct_possitions[correct_position_counter] = a;
                    correct_position_counter++;
                }

                a += 11;
            }
            line_counter++;

        }
        file.close();
    }
        //Loop to dispaly correct patients
        line_counter = 0;
        int curr_target;
        int loop_index = 0;
        std::ifstream fileB("patients.txt");
        if (fileB.is_open()) {
            std::string line;
            while (std::getline(fileB, line)) {
                curr_target = correct_possitions[line_counter];
                if (
                    loop_index == curr_target -1|| loop_index == curr_target - 2||
                    loop_index == curr_target - 3 || loop_index == curr_target - 4 ||
                    loop_index == curr_target - 5||
                    loop_index == curr_target || loop_index == curr_target +1||
                    loop_index == curr_target +2|| loop_index == curr_target +3||
                    loop_index == curr_target +4|| loop_index == curr_target +5
                    ){

                     cout << ("%s", line.c_str()) << "\n";
                     if (loop_index == curr_target + 5) { line_counter++; }
                    
                    
                }
                loop_index++;
            }
        }
        
    
    while (true)
    {
        std::cout << "To continue Enter |y| \n";
        cin >> yes;

        if (yes == "y") {
            break;
        }
    }
}
//////////////////////////////////////////////////
void display_info_patientsWithComplains() {

    string yes;
    string curr_line;
    int correct_possitions[100] = { 0 };
    int line_counter = 1;
    int correct_position_counter = 0;
    int a = 4;


    //Open Txt file to Read
    std::ifstream file("patients.txt");
    if (file.is_open()) {
        std::string line;
        //Loop to save correct possitions
        while (std::getline(file, line)) {

            if (line_counter == a) {
                curr_line = line.c_str();

                if (!line.empty()) {
                    correct_possitions[correct_position_counter] = a;
                    correct_position_counter++;
                }

                a += 11;
            }
            line_counter++;

        }
        file.close();
    }
    //Loop to dispaly correct patients
    line_counter = 0;
    int curr_target;
    int loop_index = 0;
    std::ifstream fileB("patients.txt");
    if (fileB.is_open()) {
        std::string line;
        while (std::getline(fileB, line)) {
            curr_target = correct_possitions[line_counter];
            if (
                loop_index == curr_target - 1 || loop_index == curr_target - 2 ||
                loop_index == curr_target - 3 || loop_index == curr_target - 4 ||
                loop_index == curr_target - 5 ||
                loop_index == curr_target || loop_index == curr_target + 1 ||
                loop_index == curr_target + 2 || loop_index == curr_target + 3 ||
                loop_index == curr_target + 4 || loop_index == curr_target + 5
                ) {

                cout << ("%s", line.c_str()) << "\n";
                if (loop_index == curr_target + 5) { line_counter++; }


            }
            loop_index++;
        }
    }


    while (true)
    {
        std::cout << "To continue Enter |y| \n";
        cin >> yes;

        if (yes == "y") {
            break;
        }
    }

}
/////////////////////////////
void display_most_common_diagnosis() {
    string most_fr_diagnosis;
    string yes;
    string curr_line;
    string correct_possitions[100];
    int line_counter = 1;
    int correct_position_counter = 0;
    int a = 7;


    //Open Txt file to Read
    std::ifstream file("patients.txt");
    if (file.is_open()) {
        std::string line;
        //Loop to save correct possitions
        while (std::getline(file, line)) {

            if (line_counter == a) {
                curr_line = line.c_str();

                if (line_counter == a) {
                    correct_possitions[correct_position_counter] = curr_line;
                    correct_position_counter++;
                }

                a += 11;
            }
            line_counter++;

        }
        file.close();
    }
    line_counter = 1;
    int max_count = 1;
    int n = sizeof(correct_possitions[correct_position_counter]) / sizeof(correct_possitions[0]);
    for (int i = 1; i < correct_position_counter; i++) {
        if (correct_possitions[i] == correct_possitions[i - 1])
            line_counter++;
        else {
            if (line_counter > max_count) {
                max_count = line_counter;
                most_fr_diagnosis = correct_possitions[i - 1];
            }
            line_counter = 1;
        }
    }

    // If last element is most frequent
    if (line_counter > max_count)
    {
        max_count = line_counter;
        most_fr_diagnosis = correct_possitions[n - 1];
    }
    cout << "The most frequent diagnosis is : " << most_fr_diagnosis << "\n";

    while (true)
    {
        std::cout << "To continue Enter |y| \n";
        cin >> yes;

        if (yes == "y") {
            break;
        }
    }
}

/// //////////////////
void delete_patient() {
    char choice;
    cout << "This will delete all content in the patients File ? \n";
    cout << "To confirm press |y|  to cancel press |n|\n";
    cin >> choice;
    if (choice == 'y') {
        std::ofstream ofs;
        ofs.open("patients.txt", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
}
