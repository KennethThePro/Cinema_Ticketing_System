#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

//Declaring Constants For Each Ticket Price
constexpr auto adult_class_0 = 20.00;
constexpr auto children_class_0 = 10.00;
constexpr auto student_class_0 = 12.00;

constexpr auto adult_class_1 = 16.00;
constexpr auto children_class_1 = 6.00;
constexpr auto student_class_1 = 8.00;

constexpr auto adult_class_2 = 18.00;
constexpr auto children_class_2 = 8.00;
constexpr auto student_class_2 = 10.00;

string movie_selection();
string day_date_selection();
string time_selection();
int class_selection(int& current_capacity_0, int& current_capacity_1, int& current_capacity_2);
void seat_selection0(int& current_capacity_0, string seat_no_class0[], int class_size_0, string& adult_ticket0, string& children_ticket0, string& student_ticket0,
	int& count_adult_seat, int& count_children_seat, int& count_student_seat);
void seat_selection1(int& current_capacity_1, int seat_no_class1[], int class_size_1, vector <int>& adult_ticket1, vector <int>& children_ticket1, vector <int>& student_ticket1,
	int& count_adult_seat, int& count_children_seat, int& count_student_seat);
void seat_selection2(int& current_capacity_2, int seat_no_class2[], int class_size_2, vector <int>& adult_ticket2, vector <int>& children_ticket2, vector <int>& student_ticket2,
	int& count_adult_seat, int& count_children_seat, int& count_student_seat);
void bill_calculation(int class_selected, int& count_adult_seat, int& count_children_seat, int& count_student_seat,
	double& total_adult_cost, double& total_children_cost, double& total_student_cost,
	int& total_overall_adult, int& total_overall_children, int& total_overall_student);
void ticket_printing0(string& adult_ticket0, string& children_ticket0, string& student_ticket0, string movie, string day_date, string time, int class_selected);
void ticket_printing1(vector <int>& adult_ticket1, vector <int>& children_ticket1, vector <int>& student_ticket1, string movie, string day_date, string time, int class_selected);
void ticket_printing2(vector <int>& adult_ticket2, vector <int>& children_ticket2, vector <int>& student_ticket2, string movie, string day_date, string time, int class_selected);
void summary_sales(string movie, string day_date, string time, int capacity_class_0, int capacity_class_1, int capacity_class_2,
	int& current_capacity_0, int& current_capacity_1, int& current_capacity_2,
	int& total_overall_adult, int& total_overall_children, int& total_overall_student,
	double& total_adult_cost, double& total_children_cost, double& total_student_cost);

int main() {
	//Selection Done Once Only

	string movie, day_date, time;
	cout << " =============================== " << endl;
	cout << "||       Welcome Staff!        ||" << endl;
	cout << " =============================== " << endl;

	cout << "\nMovie, Day/Date, Time To Be Selected By Staff In Charge\n" << endl;
	movie = movie_selection();
	day_date = day_date_selection();
	time = time_selection();

	cout << "Choice Confirmed By Staff" << endl;
	system("pause");
	system("CLS");

	//Initialise Seating Positions
	int class_size_0, class_size_1, class_size_2;
	//SEATING FOR CLASS 0
	string seat_no_class0[15] = { "001", "002", "003", "004", "005", "006", "007", "008", "009", "010", "011", "012", "013", "014", "015" };
	class_size_0 = sizeof(seat_no_class0) / sizeof(seat_no_class0[0]);

	//SEATING FOR CLASS 1
	int seat_no_class1[15] = {};
	for (int seat_no = 100; seat_no < 115; seat_no++) {
		seat_no_class1[seat_no - 100] = seat_no + 1;
	}
	class_size_1 = sizeof(seat_no_class1) / sizeof(seat_no_class1[0]);

	//SEATING FOR CLASS 2
	int seat_no_class2[30];
	for (int seat_no = 200; seat_no < 230; seat_no++) {
		seat_no_class2[seat_no - 200] = seat_no + 1;
	}
	class_size_2 = sizeof(seat_no_class2) / sizeof(seat_no_class2[0]);

	//Initilise Originial Capacity
	int capacity_class_0 = 15, capacity_class_1 = 15, capacity_class_2 = 30;

	//Initilise Current Capacity
	int current_capacity_0 = 15, current_capacity_1 = 15, current_capacity_2 = 30;

	//Initilise Ticket Arrays For Printing
	string adult_ticket0, children_ticket0, student_ticket0;
	vector <int> adult_ticket1, children_ticket1, student_ticket1, adult_ticket2, children_ticket2, student_ticket2;

	//Initilise Number Of Adult, Children, Student For Cost Calculations
	int count_adult_seat = 0, count_children_seat = 0, count_student_seat = 0;

	//Final Sales Report
	int total_overall_adult = 0, total_overall_children = 0, total_overall_student = 0;
	double total_adult_cost = 0, total_children_cost = 0, total_student_cost = 0;

	//Start Program
	char next_customer = 'Y';
	bool new_customer = false;
	bool correct_data = false;

	//Loop Until No Capacity Left or User Enters No
	while (next_customer == 'Y' && (current_capacity_0 + current_capacity_1 + current_capacity_2) != 0) {
		//Diplay Selected Movie That Has Already Been Selected From The Start
		cout << "\n";
		cout << " =============================== " << endl;
		cout << "||  Simple Movie Ticket System ||" << endl;
		cout << " =============================== " << endl;


		cout << " =============================== " << endl;
		cout << "||    WELCOME TO THE CINEMA    ||" << endl;
		cout << " =============================== " << endl;

		cout << "\n===========================================" << endl;
		cout << "MOVIE SELECTED: " << movie << endl;
		cout << "DAY / DATE SELECTED: " << day_date << endl;
		cout << "TIME SELECTED: " << time << endl;
		cout << "\nCounter Is Now Open For Selling Of Tickets" << endl;
		cout << "===========================================" << endl;

		if (new_customer == true) {
			cin.clear();
			cin.ignore();
		}
		//Class Selection
		int class_selected;
		class_selected = class_selection(current_capacity_0, current_capacity_1, current_capacity_2);

		//If Class Selected Is 0
		if (class_selected == 0) {
			seat_selection0(current_capacity_0, seat_no_class0, class_size_0, adult_ticket0, children_ticket0, student_ticket0, count_adult_seat, count_children_seat, count_student_seat);
			bill_calculation(class_selected, count_adult_seat, count_children_seat, count_student_seat, total_adult_cost, total_children_cost, total_student_cost, total_overall_adult, total_overall_children, total_overall_student);
			ticket_printing0(adult_ticket0, children_ticket0, student_ticket0, movie, day_date, time, class_selected);
		}

		//If Class Selected Is 1
		else if (class_selected == 1) {
			seat_selection1(current_capacity_1, seat_no_class1, class_size_1, adult_ticket1, children_ticket1, student_ticket1, count_adult_seat, count_children_seat, count_student_seat);
			bill_calculation(class_selected, count_adult_seat, count_children_seat, count_student_seat, total_adult_cost, total_children_cost, total_student_cost, total_overall_adult, total_overall_children, total_overall_student);
			ticket_printing1(adult_ticket1, children_ticket1, student_ticket1, movie, day_date, time, class_selected);
		}
		//If Class Selected Is 2
		else {
			seat_selection2(current_capacity_2, seat_no_class2, class_size_2, adult_ticket2, children_ticket2, student_ticket2, count_adult_seat, count_children_seat, count_student_seat);
			bill_calculation(class_selected, count_adult_seat, count_children_seat, count_student_seat, total_adult_cost, total_children_cost, total_student_cost, total_overall_adult, total_overall_children, total_overall_student);
			ticket_printing2(adult_ticket2, children_ticket2, student_ticket2, movie, day_date, time, class_selected);
		}

		//Ask User If Want To Continue For Next Customer
		cout << "\nDo You Want To Continue? Y for Yes, N For No: ";
		cin >> next_customer;
		next_customer = toupper(next_customer);

		//Validation Of Choice 
		while (correct_data == false) {
			switch (next_customer) {
			case 'Y':
			case 'N':
				correct_data = true;
				break;
			default:
				cout << "Invalid Input. Please Try Again!" << endl;
				cout << "\nDo You Want To Continue? Y for Yes, N for No: ";
				cin >> next_customer;
				next_customer = toupper(next_customer);
				break;
			}
		}

		//For cin.clear() to avoid cin buffer overflow
		if (next_customer == 'Y') {
			new_customer = true;
			system("CLS");
		}
	}
	//If No Seats Left
	if (current_capacity_0 + current_capacity_1 + current_capacity_2 == 0) {
		cout << "No more capacity of seats. Counter Is Now Closed!";
	}
	//If User Ends Program Before Capacity Is 0
	else
		cout << "Movie is about to start soon. Counter Is Closed!";

	//Output Summary of Sales
	summary_sales(movie, day_date, time, capacity_class_0, capacity_class_1, capacity_class_2, current_capacity_0, current_capacity_1, current_capacity_2, total_overall_adult, total_overall_children, total_overall_student, total_adult_cost, total_children_cost, total_student_cost);

	system("pause");
	return 0;

}

string movie_selection() {
	bool correct_data = false;
	string movie_choice;

	string movies[3] = { "GEOSTORM", "AVENGERS ENDGAME", "EDGE OF TOMORROW" };

	//Menu For Movie
	cout << "Movie List" << endl;
	cout << "==================" << endl;
	cout << "1. " << movies[0] << endl;
	cout << "2. " << movies[1] << endl;
	cout << "3. " << movies[2] << endl;

	//Validation Of Choice
	while (correct_data == false) {
		cout << "\nEnter a movie choice: ";
		getline(cin, movie_choice);

		//Validate If Input Is A Letter or Not Suitable Length
		while (isalpha(movie_choice[0]) || movie_choice.size() != 1) {
			cout << "\nInvalid Input. Please Try Again!" << endl;
			cout << "\nEnter a movie choice: ";
			getline(cin, movie_choice);
		}

		//Obtain Movie Choice
		switch (stoi(movie_choice)) {
		case 1:
			correct_data = true;
			return movies[0];
			break;
		case 2:
			correct_data = true;
			return movies[1];
		case 3:
			correct_data = true;
			return movies[2];
			break;
		default:
			cout << "\nInvalid Input. Please Try Again!" << endl;
			break;
		}
	}
}

string day_date_selection() {
	bool correct_data = false;
	string day_date_choice;


	time_t t = time(NULL);
	tm* tPtr = localtime(&t);

	//Menu For Day and Date
	const string DAY[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

	time_t rawtime;
	tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	// }
	int day_today = timeinfo->tm_wday;
	int day_tomorrow = timeinfo->tm_wday + 1;
	int day_after_tomorrow = timeinfo->tm_wday + 2;

	cout << "\nDay and Date Choice" << endl;
	cout << "===========================" << endl;
	cout << "1. " << DAY[day_today]  << ", " << (tPtr->tm_mday) << "-" << (tPtr->tm_mon) + 1 << "-" << (tPtr->tm_year) + 1900 << endl;
	cout << "2. " << DAY[day_tomorrow] << ", " << (tPtr->tm_mday) + 1 << "-" << (tPtr->tm_mon) + 1 << "-" << (tPtr->tm_year) + 1900 << endl;
	cout << "3. " << DAY[day_after_tomorrow] << ", " << (tPtr->tm_mday) + 2 << "-" << (tPtr->tm_mon) + 1 << "-" << (tPtr->tm_year) + 1900 << endl;

	//Validation Of Choice
	while (correct_data == false) {
		cout << "\nEnter choice of day and date: ";
		getline(cin, day_date_choice);

		//Validate If Input Is A Letter or Not Suitable Length
		while (isalpha(day_date_choice[0]) || day_date_choice.size() != 1) {
			cout << "\nInvalid Input. Please Try Again!" << endl;
			cout << "\nEnter choice of day and date: ";
			getline(cin, day_date_choice);
		}

		//Obtain Day and Date Choice
		switch (stoi(day_date_choice)) {
		case 1:
			correct_data = true;
			return DAY[day_after_tomorrow] + ", " + to_string(tPtr->tm_mday) + "-" + to_string((tPtr->tm_mon) + 1) + "-" + to_string((tPtr->tm_year) + 1900);
			break;
		case 2:
			correct_data = true;
			return DAY[day_tomorrow] + ", " + to_string((tPtr->tm_mday) + 1) + "-" + to_string((tPtr->tm_mon) + 1) + "-" + to_string((tPtr->tm_year) + 1900);
			break;
		case 3:
			correct_data = true;
			return DAY[day_after_tomorrow] +  ", " + to_string((tPtr->tm_mday) + 2) + "-" + to_string((tPtr->tm_mon) + 1) + "-" + to_string((tPtr->tm_year) + 1900);
			break;

		default:
			cout << "\nInvalid Input. Please Try Again!" << endl;
			break;
		}
	}
}

string time_selection() {
	bool correct_data = false;
	string time_choice;

	//Menu For Time
	cout << "\nTime Choice" << endl;
	cout << "=============" << endl;
	cout << "1. 6:00 p.m." << endl;
	cout << "2. 8:00 p.m." << endl;
	cout << "3. 10:00 p.m." << endl;

	//Validation Of Choice
	while (correct_data == false) {
		cout << "\nEnter choice of day and date: ";
		getline(cin, time_choice);

		//Validate If Input Is A Letter or Not Suitable Length
		while (isalpha(time_choice[0]) || time_choice.size() != 1) {
			cout << "\nInvalid Input. Please Try Again!" << endl;
			cout << "\nEnter a movie choice: ";
			getline(cin, time_choice);
		}

		//Obtain Time Choice
		switch (stoi(time_choice)) {
		case 1:
			correct_data = true;
			return "6:00 p.m.";
			break;
		case 2:
			correct_data = true;
			return "8:00 p.m.";
		case 3:
			correct_data = true;
			return "10:00 p.m.";
			break;
		default:
			correct_data = false;
			cout << "\nInvalid Input. Please Try Again!" << endl;
			break;
		}
	}
}

int class_selection(int& current_capacity_0, int& current_capacity_1, int& current_capacity_2) {
	bool correct_data = false;
	string class_selected;

	//Display Seats Capacity
	cout << "\nSeats Available: " << endl;
	cout << "VIP   - CLASS 0 - " << current_capacity_0 << endl;
	cout << "FRONT - CLASS 1 - " << current_capacity_1 << endl;
	cout << "BACK  - CLASS 2 - " << current_capacity_2 << endl;
	cout << "\n";

	//Class Selection
	while (correct_data == false) {
		cout << "Class Required (0,1,2)? : ";
		getline(cin, class_selected);

		//Validate If Input Is A Letter or Not Suitable Length
		while (isalpha(class_selected[0]) || class_selected.size() != 1) {
			cout << "\nInvalid Input. Please Try Again!" << endl;
			cout << "\nEnter a movie choice: ";
			getline(cin, class_selected);
		}

		//Check If A Class Has 0 Capacity So That User Has To Pick Another Class
		switch (stoi(class_selected)) {
		case 0:
			if (current_capacity_0 == 0) {
				cout << "Class 0 Has No Capacity Left. Please Select Another Class.\n";
			}
			else {
				correct_data = true;
				return 0;
			}
			break;

		case 1:
			if (current_capacity_1 == 0) {
				cout << "Class 1  Has No Capacity Left. Please Select Another Class.\n";
			}
			else {
				correct_data = true;
				return 1;
			}
			break;

		case 2:
			if (current_capacity_2 == 0) {
				correct_data = false;
				cout << "Class 2  Has No Capacity Left. Please Select Another Class.\n";
			}
			else {
				correct_data = true;
				return 2;
			}
			break;

		default:
			correct_data = false;
			cout << "\nInvalid Input. Please Try Again!" << endl;
			break;
		}
	}
}

void seat_selection0(int& current_capacity_0, string seat_no_class0[], int class_size_0, string& adult_ticket0, string& children_ticket0, string& student_ticket0,
	int& count_adult_seat, int& count_children_seat, int& count_student_seat) {
	bool correct_data = false;
	string no_adult_seat = "0";
	string no_children_seat = "0";
	string no_student_seat = "0";
	string seat_number;

	cout << "\n";

	//Validate Total Seats, If 0 Seats Selected, Ask User To Input Again
	while (stoi(no_adult_seat + no_children_seat + no_student_seat) == 0) {
		//Output Seating
		for (int i = 0; i < class_size_0; i++) {
			cout << seat_no_class0[i] << " || ";
		}
		cout << "\n";

		while (correct_data == false) {
			//Get Number Of Adults
			cout << "\nCurrent Number Of Seats Left: " << current_capacity_0 << endl;
			cout << "\nNumber Of Adult Seats Required: ";
			getline(cin, no_adult_seat);

			//Validate Input Is The First, Second Is Letters or Not Required Length
			while (isalpha(no_adult_seat[0]) || isalpha(no_adult_seat[1]) || stoi(no_adult_seat) < 0 || no_adult_seat.size() > 2) {
				cout << "\nInvalid Input. Please Try Again!" << endl;
				cout << "\nNumber Of Adult Seats Required: ";
				getline(cin, no_adult_seat);
			}
			//Check If It Is More Than Entered Capacity
			if (stoi(no_adult_seat) > current_capacity_0) {
				cout << "\nCapacity Exceeded. Please Enter Again!" << endl;
			}
			else {
				//Reduce The Current Capacity
				current_capacity_0 = current_capacity_0 - stoi(no_adult_seat);
				correct_data = true;
			}
		}
		int count = 1;


		//Enter choice of seat
		while (count <= stoi(no_adult_seat)) {
			cout << "\nEnter Seat Number From 001 until 015: ";
			cin >> seat_number;

			//Validate Choice Of Seat
			while (seat_number == "0" || seat_number.size() != 3) {
				cout << "\nInvalid Seat or Seat Is Taken. Please Try Again: ";
				cout << "\nEnter Seat Number From 001 until 015: ";
				cin >> seat_number;
			}
			//Validate If User Enters Out Of Range Seat Number
			for (int i = 0; i < class_size_0; i++) {

				//Update Seat Selected To 0
				if (seat_number.compare(seat_no_class0[i]) == 0) {
					seat_no_class0[i] = "0";
					count = count + 1;
					//To break out from loop
					i = class_size_0;
					adult_ticket0.append(seat_number);
					//Add Up Total Adult In Current Transection For Payment
					count_adult_seat = count_adult_seat + 1;
				}
				//If seat not found at all
				else if (i == 14) {
					cout << "\nSeat Not Found. Please Enter Again." << endl;
				}
			}
		}

		//Show Updated Seats After Adult Seat Selection
		if (stoi(no_adult_seat) != 0) {
			cin.clear();
			cin.ignore();
			cout << "\n";
			for (int i = 0; i < class_size_0; i++) {
				cout << seat_no_class0[i] << " || ";
			}
			cout << "\n";
		}

		//If Maximum Capacity Is Reached, Skip To Ticket Printing
		if (current_capacity_0 != 0) {
			correct_data = false;

			//Get Number of Children
			while (correct_data == false) {
				cout << "\nCurrent Number Of Seats Left: " << current_capacity_0 << endl;
				cout << "\nNumber Of Children Seats Required: ";
				getline(cin, no_children_seat);

				//Validate Input
				while (isalpha(no_children_seat[0]) || isalpha(no_children_seat[1]) || stoi(no_children_seat) < 0 || no_children_seat.size() > 2) {
					cout << "\nInvalid Input. Please Try Again" << endl;
					cout << "\nNumber Of Children Seats Required: ";
					getline(cin, no_children_seat);
				}

				//Validate If Number Of Seats Exceeds Current Capacity
				if (stoi(no_children_seat) > current_capacity_0) {
					cout << "\nCapacity Exceeded. Please Enter Again" << endl;
				}
				else {
					//Update Capacity of Class 0
					current_capacity_0 = current_capacity_0 - stoi(no_children_seat);
					correct_data = true;
				}
			}
			//Reset count
			count = 1;

			//Entering seat number
			while (count <= stoi(no_children_seat)) {
				cout << "\nEnter Seat Number From 001 until 015: ";
				cin >> seat_number;

				//Check if seat taken or other invalid inputs
				while (seat_number == "0" || seat_number.size() != 3) {
					cout << "\nInavlid Seat or Seat Is Taken. Please Try Again! ";
					cout << "\nEnter Seat Number From 001 until 015: ";
					cin >> seat_number;
				}

				for (int i = 0; i < class_size_0; i++) {

					//Update Seat Selected To 0
					if (seat_number.compare(seat_no_class0[i]) == 0) {
						seat_no_class0[i] = "0";
						count = count + 1;
						i = class_size_0;
						children_ticket0.append(seat_number);
						count_children_seat += 1;
					}

					else if (i == 14) {
						cout << "\nSeat Not Found. Please Enter Again." << endl;
					}
				}
			}
			//Show Updated Seat After Children Selection
			if (stoi(no_children_seat) != 0) {
				cin.clear();
				cin.ignore();
				cout << "\n";
				for (int i = 0; i < class_size_0; i++) {
					cout << seat_no_class0[i] << " || ";
				}
				cout << "\n";
			}
		}

		//Check if current capacity is 0 to proceed to payment
		if (current_capacity_0 != 0) {
			correct_data = false;

			while (correct_data == false) {
				//Get number of Student Seats
				cout << "\nCurrent Number Of Seats Left: " << current_capacity_0 << endl;
				cout << "\nNumber Of Students Seats Required: ";
				getline(cin, no_student_seat);

				//Validate Input
				while (isalpha(no_student_seat[0]) || isalpha(no_student_seat[1]) || stoi(no_student_seat) < 0 || no_student_seat.size() > 2) {
					cout << "\nInvalid Input. Please Try Again!" << endl;
					cout << "\nNumber Of Children Seats Required: ";
					getline(cin, no_student_seat);
				}
				//Ensure capacity does not exceed maximum
				if (stoi(no_student_seat) > current_capacity_0) {
					cout << "\nCapacity Exceeded. Please Enter Again" << endl;
				}
				else {
					//Update Current Capacity of Class 0
					current_capacity_0 = current_capacity_0 - stoi(no_student_seat);
					correct_data = true;
				}
			}
			//Reset counter
			count = 1;

			//Obtain seat number of stundent
			while (count <= stoi(no_student_seat)) {
				cout << "\nEnter Seat Number From 001 until 015: ";
				cin >> seat_number;

				//Validate input 
				while (seat_number == "0" || seat_number.size() != 3) {
					cout << "\nInavlid Seat or Seat Is Taken. Please Try Again!";
					cout << "\nEnter Seat Number From 001 until 015: ";
					cin >> seat_number;
				}

				for (int i = 0; i < class_size_0; i++) {
					//Update Seat Selected To 0
					if (seat_number.compare(seat_no_class0[i]) == 0) {
						seat_no_class0[i] = "0";
						count = count + 1;
						i = class_size_0;
						student_ticket0.append(seat_number);
						count_student_seat += 1;
					}
					else if (i == 14) {
						cout << "\nSeat Not Found. Please Enter Again." << endl;
					}
				}
			}
			//Output final current available seat numbers 
			if (stoi(no_student_seat) != 0) {
				cout << "\n";
				for (int i = 0; i < class_size_0; i++) {
					cout << seat_no_class0[i] << " || ";
				}
			}
		}
		//Check if user inputs no seats at all
		if (stoi(no_adult_seat + no_student_seat + no_children_seat) == 0) {
			cout << "\nNo seat has been selected. Please try again!\n" << endl;
			correct_data = false;
			system("pause");
			system("CLS");
		}
		else {
			cout << "\n\nThank You For Selecting Your Seats!\n";
		}
	}
	system("pause");
}

void seat_selection1(int& current_capacity_1, int seat_no_class1[], int class_size_1, vector <int>& adult_ticket1, vector <int>& children_ticket1, vector <int>& student_ticket1,
	int& count_adult_seat, int& count_children_seat, int& count_student_seat) {
	bool correct_data = false;
	string no_adult_seat = "0";
	string no_student_seat = "0";
	string no_children_seat = "0";
	string seat_number;

	cout << "\n";

	//Validate Total Seats, If All 0 Ask User To Input Again
	while (stoi(no_adult_seat + no_student_seat + no_children_seat) == 0) {
		for (int i = 0; i < class_size_1; i++) {
			cout << seat_no_class1[i] << " || ";
		}
		cout << "\n";

		while (correct_data == false) {
			//Get Number Of Adults
			cout << "\nCurrent Number Of Seats Left: " << current_capacity_1 << endl;
			cout << "\nNumber Of Adult Seats Required: ";
			getline(cin, no_adult_seat);

			//Validate Input
			while (isalpha(no_adult_seat[0]) || isalpha(no_adult_seat[1]) || stoi(no_adult_seat) < 0 || no_adult_seat.size() > 2) {
				cout << "\nInvalid Input. Please Try Again!" << endl;
				cout << "\nNumber Of Adult Seats Required: ";
				getline(cin, no_adult_seat);
			}
			//Check If Number of Adult Seat Exceeds Current Capacity
			if (stoi(no_adult_seat) > current_capacity_1) {
				cout << "\nCapacity Exceeded. Please Enter Again!" << endl;
			}
			else {
				//Update current capacity of Class 1
				current_capacity_1 = current_capacity_1 - stoi(no_adult_seat);
				correct_data = true;
			}
		}
		int count = 1;

		//Get Seat Number For Each Adult
		while (count <= stoi(no_adult_seat)) {
			cout << "\nEnter Seat Number From 101 until 115: ";
			cin >> seat_number;

			//Validate seat number
			while (seat_number == "0" || seat_number.size() != 3) {
				cout << "\nInvalid Sear or Seat Is Taken. Please Try Again: ";
				cout << "\nEnter Seat Number From 101 until 115: ";
				cin >> seat_number;
			}
			//Validated If Users Enters Out Of Range Seat Number
			for (int i = 0; i < class_size_1; i++) {

				//Update seat number to 0 once seat is found
				if (seat_number.compare(to_string(seat_no_class1[i])) == 0) {
					seat_no_class1[i] = 0;
					count = count + 1;
					i = class_size_1;
					adult_ticket1.push_back(stoi(seat_number));
					count_adult_seat += 1;
				}

				//Check If Seat Is Not Found 
				else if (i == 14) {
					cout << "\nSeat Not Found. Please Enter Again." << endl;
				}
			}
		}

		//Output Updated Seats After Entering
		if (stoi(no_adult_seat) != 0) {
			cin.clear();
			cin.ignore();
			cout << "\n";
			for (int i = 0; i < class_size_1; i++) {
				cout << seat_no_class1[i] << " || ";
			}
			cout << "\n";
		}

		//Check If No More Cpacity To Proceed To Payment
		if (current_capacity_1 != 0) {
			correct_data = false;

			//Obtain Number Of Children Seats
			while (correct_data == false) {
				cout << "\nCurrent Number Of Seats Left: " << current_capacity_1 << endl;
				cout << "\nNumber Of Children Seats Required: ";
				getline(cin, no_children_seat);

				//Validate Input
				while (isalpha(no_children_seat[0]) || isalpha(no_children_seat[1]) || stoi(no_children_seat) < 0 || no_children_seat.size() > 2) {
					cout << "\nInvalid Input. Please Try Again" << endl;
					cout << "\nNumber Of Children Seats Required: ";
					getline(cin, no_children_seat);
				}
				//Check If Number Of Children Exceeds Current Capacity
				if (stoi(no_children_seat) > current_capacity_1) {
					cout << "\nCapacity Exceeded. Please Enter Again" << endl;
				}
				else {
					//Update Capacity of Class 1
					current_capacity_1 = current_capacity_1 - stoi(no_children_seat);
					correct_data = true;
				}
			}
			count = 1;

			//Obtain Seat Number For Each Children
			while (count <= stoi(no_children_seat)) {
				cout << "\nEnter Seat Number From 101 until 115: ";
				cin >> seat_number;

				//Validate Seat Input
				while (seat_number == "0" || seat_number.size() != 3) {
					cout << "\nInavlid Seat or Seat Is Taken. Please Try Again! ";
					cout << "\nEnter Seat Number From 101 until 115: ";
					cin >> seat_number;
				}
				//Validated If Users Enters Out Of Range Seat Number
				for (int i = 0; i < class_size_1; i++) {

					//Update Seat Number to 0 If Found
					if (seat_number.compare(to_string(seat_no_class1[i])) == 0) {
						seat_no_class1[i] = 0;
						count = count + 1;
						i = class_size_1;
						children_ticket1.push_back(stoi(seat_number));
						count_children_seat += 1;
					}
					//Check if seat not found
					else if (i == 14) {
						cout << "\nSeat Not Found. Please Enter Again." << endl;
					}
				}
			}
			//Output Updated Seat After Selection Of Children Seat
			if (stoi(no_children_seat) != 0) {
				cin.clear();
				cin.ignore();
				cout << "\n";
				for (int i = 0; i < class_size_1; i++) {
					cout << seat_no_class1[i] << " || ";
				}
				cout << "\n";
			}
		}
		//Check If Capacity Is 0 To Proceed To Payment
		if (current_capacity_1 != 0) {
			correct_data = false;

			while (correct_data == false) {
				//Get Number of Student Seats
				cout << "\nCurrent Number Of Seats Left: " << current_capacity_1 << endl;
				cout << "\nNumber Of Students Seats Required: ";
				getline(cin, no_student_seat);

				//Validate Input
				while (isalpha(no_student_seat[0]) || isalpha(no_student_seat[1]) || stoi(no_student_seat) < 0 || no_student_seat.size() > 2) {
					cout << "\nInvalid Input. Please Try Again!" << endl;
					cout << "\nNumber Of Children Seats Required: ";
					getline(cin, no_student_seat);
				}
				//Check If Number Entered Exceeds Capacity
				if (stoi(no_student_seat) > current_capacity_1) {
					cout << "\nCapacity Exceeded. Please Enter Again" << endl;
				}
				else {
					//Update Current Capacity Of Class 1
					current_capacity_1 = current_capacity_1 - stoi(no_student_seat);
					correct_data = true;
				}
			}
			//Reset count
			count = 1;

			//Get Seat Number of Each Student
			while (count <= stoi(no_student_seat)) {
				cout << "\nEnter Seat Number From 101 until 115: ";
				cin >> seat_number;

				//Validate Input
				while (seat_number == "0" || seat_number.size() != 3) {
					cout << "\nInavlid Seat or Seat Is Taken. Please Try Again!";
					cout << "\nEnter Seat Number From 101 until 115: ";
					cin >> seat_number;
				}

				for (int i = 0; i < class_size_1; i++) {

					//Update Seat Number To 0 Once Seat Number Is Found
					if (seat_number.compare(to_string(seat_no_class1[i])) == 0) {
						seat_no_class1[i] = 0;
						count = count + 1;
						i = class_size_1;
						student_ticket1.push_back(stoi(seat_number));
						count_student_seat += 1;
					}
					//Check If Seat Is Not Found 
					else if (i == 14) {
						cout << "\nSeat Not Found. Please Enter Again." << endl;
					}
				}
			}
			//Output Updated Seat After Completing All Selection
			if (stoi(no_student_seat) != 0) {
				cout << "\n";
				for (int i = 0; i < class_size_1; i++) {
					cout << seat_no_class1[i] << " || ";
				}
				cout << "\n";
			}
		}
		//Output Error Message If User Picks No Seats
		if (stoi(no_adult_seat + no_student_seat + no_children_seat) == 0) {
			cout << "No seat has been selected. Please try again!\n" << endl;
			correct_data = false;
			system("pause");
			system("CLS");
		}
		else {
			cout << "\nThank You For Selecting Your Seats!\n" << endl;
		}
	}
	system("pause");
}

void seat_selection2(int& current_capacity_2, int seat_no_class2[], int class_size_2, vector <int>& adult_ticket2, vector <int>& children_ticket2, vector <int>& student_ticket2,
	int& count_adult_seat, int& count_children_seat, int& count_student_seat) {
	bool correct_data = false;
	string no_adult_seat = "0";
	string no_student_seat = "0";
	string no_children_seat = "0";
	string seat_number;

	cout << "\n";

	//Validate Total Seats, If All 0 Ask User To Input Again
	while (stoi(no_adult_seat + no_student_seat + no_children_seat) == 0) {
		for (int i = 0; i < class_size_2; i++) {
			cout << seat_no_class2[i] << " | ";
		}
		//Get Number Of Adults
		while (correct_data == false) {
			cout << "\nCurrent Number Of Seats Left: " << current_capacity_2 << endl;
			cout << "\nNumber Of Adult Seats Required: ";
			getline(cin, no_adult_seat);

			//Validate Input
			while (isalpha(no_adult_seat[0]) || isalpha(no_adult_seat[1]) || stoi(no_adult_seat) < 0 || no_adult_seat.size() > 2) {
				cout << "\nInvalid Input. Please Try Again!" << endl;
				cout << "\nNumber Of Adult Seats Required: ";
				getline(cin, no_adult_seat);
			}
			//Check If Number Exceeds The Current Capacity
			if (stoi(no_adult_seat) > current_capacity_2) {
				cout << "\nCapacity Exceeded. Please Enter Again!" << endl;
			}
			else {
				//Update Current Capacity Of Class 2
				current_capacity_2 = current_capacity_2 - stoi(no_adult_seat);
				correct_data = true;
			}
		}

		int count = 1;

		//Obatain Seat Number For Each Adult
		while (count <= stoi(no_adult_seat)) {
			cout << "\nEnter Seat Number From 201 until 230: ";
			cin >> seat_number;

			//Validate Input
			while (seat_number == "0" || seat_number.size() != 3) {
				cout << "\nInvalid Sear or Seat Is Taken. Please Try Again: ";
				cout << "\nEnter Seat Number From 201 until 230: ";
				cin >> seat_number;
			}
			//Validated If User Enters Out Of Range Seat Number
			for (int i = 0; i < class_size_2; i++) {

				//Update Seat Selected To 0
				if (seat_number.compare(to_string(seat_no_class2[i])) == 0) {
					seat_no_class2[i] = 0;
					count = count + 1;
					i = class_size_2;
					adult_ticket2.push_back(stoi(seat_number));
					count_adult_seat += 1;
				}
				//Check If Seat Not Found
				else if (i == 29) {
					cout << "\nSeat Not Found. Please Enter Again." << endl;
				}
			}
		}
		//Output Latest Seat Number
		if (stoi(no_adult_seat) != 0) {
			cin.clear();
			cin.ignore();
			cout << "\n";
			for (int i = 0; i < class_size_2; i++) {
				cout << seat_no_class2[i] << " | ";
			}
			cout << "\n";
		}

		//If Maximum Capacity Is Reached, Skip To Ticket Printing
		if (current_capacity_2 != 0) {
			correct_data = false;

			//Get Number Of Children
			while (correct_data == false) {
				cout << "\nCurrent Number Of Seats Left: " << current_capacity_2 << endl;
				cout << "\nNumber Of Children Seats Required: ";
				getline(cin, no_children_seat);

				//Validate Input
				while (isalpha(no_children_seat[0]) || isalpha(no_children_seat[1]) || stoi(no_children_seat) < 0 || no_children_seat.size() > 2) {
					cout << "\nInvalid Input. Please Try Again" << endl;
					cout << "\nNumber Of Children Seats Required: ";
					getline(cin, no_children_seat);
				}

				//Check If Number Exceeds Current Cpacity
				if (stoi(no_children_seat) > current_capacity_2) {
					cout << "\nCapacity Exceeded. Please Enter Again" << endl;
				}
				else {
					//Update Current Capacity Of Class 2
					current_capacity_2 = current_capacity_2 - stoi(no_children_seat);
					correct_data = true;
				}
			}
			//Reset Counter
			count = 1;

			//Obtain Seat Number For Each Children
			while (count <= stoi(no_children_seat)) {
				cout << "\nEnter Seat Number From 201 until 230: ";
				cin >> seat_number;

				//Validate Input
				while (seat_number == "0" || seat_number.size() != 3) {
					cout << "\nInavlid Seat or Seat Is Taken. Please Try Again! ";
					cout << "\nEnter Seat Number From 201 until 230: ";
					cin >> seat_number;
				}

				//Validated If User Enters Out Of Range Seat Number
				for (int i = 0; i < class_size_2; i++) {

					//Validate Seat Selected To 0
					if (seat_number.compare(to_string(seat_no_class2[i])) == 0) {
						seat_no_class2[i] = 0;
						count = count + 1;
						i = class_size_2;
						children_ticket2.push_back(stoi(seat_number));
						count_children_seat += 1;
					}

					else if (i == 29) {
						cout << "\nSeat Not Found. Please Enter Again." << endl;
					}
				}
			}
			//Output Latest Seats
			if (stoi(no_children_seat) != 0) {
				cin.clear();
				cin.ignore();
				cout << "\n";
				for (int i = 0; i < class_size_2; i++) {
					cout << seat_no_class2[i] << " | ";
				}
				cout << "\n";
			}
		}

		//If Maximum Capacity Is Reached, Skip To Ticket Printing
		if (current_capacity_2 != 0) {
			correct_data = false;

			//Get Number Of Seats
			while (correct_data == false) {
				cout << "\nCurrent Number Of Seats Left: " << current_capacity_2 << endl;
				cout << "\nNumber Of Students Seats Required: ";
				getline(cin, no_student_seat);

				//Validate User Input
				while (isalpha(no_student_seat[0]) || isalpha(no_student_seat[1]) || stoi(no_student_seat) < 0 || no_student_seat.size() > 2) {
					cout << "\nInvalid Input. Please Try Again!" << endl;
					cout << "\nNumber Of Children Seats Required: ";
					getline(cin, no_student_seat);
				}
				//Check If Number Exceeds Capacity
				if (stoi(no_student_seat) > current_capacity_2) {
					cout << "\nCapacity Exceeded. Please Enter Again" << endl;
				}
				else {
					//Update Current Capacity Of Class 2
					current_capacity_2 = current_capacity_2 - stoi(no_student_seat);
					correct_data = true;
				}
			}
			//Reset Counter
			count = 1;

			//Get Seat Number For Each Student
			while (count <= stoi(no_student_seat)) {
				cout << "\nEnter Seat Number From 201 until 230: ";
				cin >> seat_number;

				//Validate User Input
				while (seat_number == "0" || seat_number.size() != 3) {
					cout << "\nInavlid Seat or Seat Is Taken. Please Try Again!";
					cout << "\nEnter Seat Number From 201 until 230: ";
					cin >> seat_number;
				}
				//Check If User Input Out Of Range
				for (int i = 0; i < class_size_2; i++) {

					//Update Seat Selected To 0
					if (seat_number.compare(to_string(seat_no_class2[i])) == 0) {
						seat_no_class2[i] = 0;
						count = count + 1;
						i = class_size_2;
						student_ticket2.push_back(stoi(seat_number));
						count_student_seat += 1;
					}
					//Check If Seat Not Found
					else if (i == 29) {
						cout << "\nSeat Not Found. Please Enter Again." << endl;
					}
				}
			}
			//Output Latest Seats
			if (stoi(no_student_seat) != 0) {
				cout << "\n";
				for (int i = 0; i < class_size_2; i++) {
					cout << seat_no_class2[i] << " | ";
				}
			}
		}
		//Output Message If No Seats Are Selected
		if (stoi(no_adult_seat + no_student_seat + no_children_seat) == 0) {
			cout << "No seat has been selected. Please try again!\n" << endl;
			correct_data = false;
			system("pause");
			system("CLS");
		}
		else {
			cout << "\nThank You For Selecting Your Seats!\n" << endl;
		}
	}
	system("pause");
}

void bill_calculation(int class_selected, int& count_adult_seat, int& count_children_seat, int& count_student_seat,
	double& total_adult_cost, double& total_children_cost, double& total_student_cost,
	int& total_overall_adult, int& total_overall_children, int& total_overall_student) {
	system("CLS");
	double total, adult_cost, children_cost, student_cost, cash_paid, balance;
	cout << "\n\n================================================" << endl;
	cout << "\nBill Calculations - Class " << class_selected << endl << "\n";

	if (class_selected == 0) {
		//calculate cost of each age group
		adult_cost = adult_class_0 * count_adult_seat;
		children_cost = children_class_0 * count_children_seat;
		student_cost = student_class_0 * count_student_seat;

		cout << "Number of adults   = ";
		cout << setw(2) << right << count_adult_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << adult_class_0 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << setw(1) << right << adult_cost << endl;

		cout << "Number of children = ";
		cout << setw(2) << right << count_children_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << children_class_0 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << setw(1) << right << children_cost << endl;

		cout << "Number of students = ";
		cout << setw(2) << right << count_student_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << student_class_0 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << setw(1) << right << student_cost << endl;

		//Sum The Total Cost
		total = adult_cost + children_cost + student_cost;
	}

	else if (class_selected == 1) {
		//calculate cost of each age group
		adult_cost = adult_class_1 * count_adult_seat;
		children_cost = children_class_1 * count_children_seat;
		student_cost = student_class_1 * count_student_seat;

		cout << "Number of adults   = ";
		cout << setw(2) << right << count_adult_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << adult_class_1 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << setw(1) << right << adult_cost << endl;

		cout << "Number of children = ";
		cout << setw(2) << right << count_children_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << "  " << children_class_1 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " ";
		cout << setw(1) << right << " " << children_cost << endl;

		cout << "Number of students = ";
		cout << setw(2) << right << count_student_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << "  " << student_class_1 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " ";
		cout << setw(1) << right << " " << student_cost << endl;

		//Sum The Total Cost
		total = adult_cost + children_cost + student_cost;
	}
	else {
		//calculate cost of each age group
		adult_cost = adult_class_2 * count_adult_seat;
		children_cost = children_class_2 * count_children_seat;
		student_cost = student_class_2 * count_student_seat;

		cout << "Number of adults   = ";
		cout << setw(2) << right << count_adult_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << adult_class_2 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << setw(1) << right << adult_cost << endl;

		cout << "Number of children = ";
		cout << setw(2) << right << count_children_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << "  " << children_class_2 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " ";
		cout << setw(1) << right << " " << children_cost << endl;

		cout << "Number of students = ";
		cout << setw(2) << right << count_student_seat;
		cout << setw(1) << left << " " << " x ";
		cout << setw(1) << left << " " << "RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << student_class_2 << " = RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << setw(1) << right << student_cost << endl;

		//Sum The Total Cost
		total = adult_cost + children_cost + student_cost;

	}
	//Display Total Amount Required To Pay
	cout << left << setw(6) << "" << "Total To Pay = " << left << setw(17) << " " << "= RM ";
	cout << fixed;
	cout << setprecision(2) << setw(1) << right << " " << total;

	//Get Payment From Customer
	cout << "\n";
	cout << left << setw(6) << "" << "Total Payment: " << left << setw(17) << " " << "  RM  ";
	cin >> cash_paid;

	//Check If Insufficent Payment Is Given
	if (cash_paid < total) {
		cout << "Insufficient Payment. Please Enter Amount Equal or More Than The Cost." << endl;
		system("pause");
		bill_calculation(class_selected, count_adult_seat, count_children_seat, count_student_seat, total_adult_cost, total_children_cost, total_student_cost, total_overall_adult, total_overall_children, total_overall_student);
		
	}
	else {
		//Calculate Balance To Pay Back
		balance = cash_paid - total;
		cout << left << setw(6) << "" << "Change Due   = " << left << setw(17) << " " << "  RM ";
		cout << fixed;
		cout << setprecision(2) << setw(1) << right << " " << balance;
		cout << "\n================================================" << endl;
	}


	//Overall Total Cost For Summary Sales
	total_adult_cost = total_adult_cost + adult_cost;
	total_children_cost = total_children_cost + children_cost;
	total_student_cost = total_student_cost + student_cost;

	//Summary Total OF Number Of Adults, Children, Student 
	total_overall_adult = total_overall_adult + count_adult_seat;
	total_overall_children = total_overall_children + count_children_seat;
	total_overall_student = total_overall_student + count_student_seat;

	count_adult_seat = 0;
	count_children_seat = 0;
	count_student_seat = 0;
	system("pause");
	system("CLS");
}

void ticket_printing0(string& adult_ticket0, string& children_ticket0, string& student_ticket0, string movie, string day_date, string time, int class_selected) {
	cout << "\nTICKET PRINTING IN PROCESS";

	int count = 1;
	int i = 0;

	while (count <= adult_ticket0.length()) {

		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "               " << "Adult - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: ";

		//Index 0,1 and 2 and Next 3 Index Keeps Seat Number Per Person, Breaks To Next Ticket When Count Reach 3

		for (i; i < adult_ticket0.length(); i++) {
			if (count % 3 == 0 && i != 0) {
				count = count + 1;
				cout << adult_ticket0[i] << "                Price - RM " << fixed << setprecision(2) << adult_class_0 << endl;
				i = i + 1;
				break;
			}
			else {
				count = count + 1;
				cout << adult_ticket0[i];
			}
		}
		cout << "================================================" << endl;
	}

	count = 1;
	i = 0;

	while (count <= children_ticket0.length()) {

		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "            " << "Children - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: ";

		//Index 0,1 and 2 and Next 3 Index Keeps Seat Number Per Person, Breaks To Next Ticket When Count Reach 3
		for (i; i < children_ticket0.length(); i++) {
			if (count % 3 == 0 && i != 0) {
				count = count + 1;
				cout << children_ticket0[i] << "                Price - RM " << fixed << setprecision(2) << children_class_0 << endl;
				i = i + 1;
				break;
			}
			else {
				count = count + 1;
				cout << children_ticket0[i];
			}
		}
		cout << "================================================" << endl;
	}

	count = 1;
	i = 0;

	while (count <= student_ticket0.length()) {

		cout << "\n================================================" << endl;
		cout << "   Cinema Ticket " << "             " << "Student - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: ";

		//Index 0,1 and 2 and Next 3 Index Keeps Seat Number Per Person, Breaks To Next Ticket When Count Reach 3
		for (i; i < student_ticket0.length(); i++) {
			if (count % 3 == 0 && i != 0) {
				count = count + 1;
				cout << student_ticket0[i] << "                Price - RM " << fixed << setprecision(2) << student_class_0 << endl;;
				i = i + 1;
				break;
			}
			else {
				count = count + 1;
				cout << student_ticket0[i];
			}
		}
		cout << "================================================" << endl;
	}
	adult_ticket0 = "";
	children_ticket0 = "";
	student_ticket0 = "";

}

void ticket_printing1(vector <int>& adult_ticket1, vector <int>& children_ticket1, vector <int>& student_ticket1, string movie, string day_date, string time, int class_selected) {
	cout << "\nTICKET PRINTING IN PROCESS";

	//Loop the entire vector
	for (auto i = adult_ticket1.begin(); i != adult_ticket1.end(); i++) {
		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "               " << "Adult - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: " << *i << "                Price - RM " << fixed << setprecision(2) << adult_class_1 << endl;
		cout << "================================================" << endl;
	}

	//Loop the entire vector
	for (auto i = children_ticket1.begin(); i != children_ticket1.end(); i++) {
		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "            " << "Children - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: " << *i << "                Price - RM " << fixed << setprecision(2) << children_class_1 << endl;
		cout << "================================================" << endl;
	}

	//Loop the entire vector
	for (auto i = student_ticket1.begin(); i != student_ticket1.end(); i++) {
		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "             " << "Student - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: " << *i << "                Price - RM " << fixed << setprecision(2) << student_class_1 << endl;
		cout << "================================================" << endl;
	}

	//Clear All Elements From Vector
	adult_ticket1.clear();
	children_ticket1.clear();
	student_ticket1.clear();

}

void ticket_printing2(vector <int>& adult_ticket2, vector <int>& children_ticket2, vector <int>& student_ticket2, string movie, string day_date, string time, int class_selected) {
	cout << "\nTICKET PRINTING IN PROCESS";

	//Loop the entire vector
	for (auto i = adult_ticket2.begin(); i != adult_ticket2.end(); i++) {
		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "               " << "Adult - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: " << *i << "               Price - RM " << fixed << setprecision(2) << adult_class_2 << endl;
		cout << "================================================" << endl;
	}

	//Loop the entire vector
	for (auto i = children_ticket2.begin(); i != children_ticket2.end(); i++) {
		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "            " << "Children - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: " << *i << "               Price - RM " << fixed << setprecision(2) << children_class_2 << endl;
		cout << "================================================" << endl;
	}

	//Loop the entire vector
	for (auto i = student_ticket2.begin(); i != student_ticket2.end(); i++) {
		cout << "\n================================================" << endl;
		cout << "    Cinema Ticket " << "             " << "Student - Class " << class_selected << endl;
		cout << "Movie - " << movie << endl;
		cout << "Date / Time - " << day_date << " (" << time << ")" << endl;
		cout << "Seat Number: " << *i << "               Price - RM " << fixed << setprecision(2) << student_class_2 << endl;
		cout << "================================================" << endl;
	}

	//Clear All Elements From Vector
	adult_ticket2.clear();
	children_ticket2.clear();
	student_ticket2.clear();

}

void summary_sales(string movie, string day_date, string time, int capacity_class_0, int capacity_class_1, int capacity_class_2,
	int& current_capacity_0, int& current_capacity_1, int& current_capacity_2,
	int& total_overall_adult, int& total_overall_children, int& total_overall_student,
	double& total_adult_cost, double& total_children_cost, double& total_student_cost) {
	int total_original_capacity = 0, total_current_capacity = 0, total_people = 0;
	double total_cost;

	//Get Total Capacity and Number Of Seats Taken Up
	total_original_capacity = capacity_class_0 + capacity_class_1 + capacity_class_2;
	total_current_capacity = current_capacity_0 + current_capacity_1 + current_capacity_2;

	//Total Up Number Of People and Cost
	total_people = total_overall_adult + total_overall_children + total_overall_student;
	total_cost = total_adult_cost + total_children_cost + total_student_cost;

	//Output Each Class Details
	cout << "\n================================================" << endl;
	cout << "\nTICKET SALES REPORT" << endl;
	cout << "\nMovie Title: " << movie << endl;
	cout << "Date / Time: " << day_date << " (" << time << ")" << endl;
	cout << "\nSEAT OCCUPANCY FOR EACH CLASS:" << endl << "\n";
	cout << setw(10) << left << " " << setw(11) << left << "Total Seats" << "   " << setw(13) << left << "Quantity Sold" << "   " << setw(5) << left << "Sold%" << endl;
	cout << setw(10) << left << "Class 0" << setw(11) << left << "    " + to_string(capacity_class_0) << "   " << setw(13) << left << "      " + to_string(capacity_class_0 - current_capacity_0) << "   " << setw(6) << left << "  " + to_string(((capacity_class_0 - current_capacity_0) * 100) / capacity_class_0) << endl;
	cout << setw(10) << left << "Class 1" << setw(11) << left << "    " + to_string(capacity_class_1) << "   " << setw(13) << left << "      " + to_string(capacity_class_1 - current_capacity_1) << "   " << setw(6) << left << "  " + to_string(((capacity_class_1 - current_capacity_1) * 100) / capacity_class_1) << endl;
	cout << setw(10) << left << "Class 2" << setw(11) << left << "    " + to_string(capacity_class_2) << "   " << setw(13) << left << "      " + to_string(capacity_class_2 - current_capacity_2) << "   " << setw(6) << left << "  " + to_string(((capacity_class_2 - current_capacity_2) * 100) / capacity_class_2) << endl;
	cout << setw(10) << left << "       " << setw(11) << left << "  ------" << "   " << setw(13) << left << "   -------" << setw(6) << left << "   -----" << endl;
	cout << setw(10) << left << "TOTAL" << setw(11) << left << "    " + to_string(total_original_capacity) << "   " << setw(13) << left << "      " + to_string(total_original_capacity - total_current_capacity) << "   " << setw(6) << left << "  " + to_string(((total_original_capacity - total_current_capacity) * 100) / total_original_capacity) << endl;

	//Output Each Category Details
	cout << "\nSALES FOR EACH CATEGORY TYPE\n" << endl;
	cout << setw(8) << left << "Category" << "   " << setw(5) << left << "Seats" << "   " << setw(10) << left << "Sales(RM)" << endl;
	cout << setw(8) << left << "ADULT" << setw(5) << left << "   " << total_overall_adult << setw(7) << left << "  " << total_adult_cost << endl;
	cout << setw(8) << left << "CHILD" << setw(5) << left << "   " << total_overall_children << setw(7) << left << "  " << total_children_cost << endl;
	cout << setw(8) << left << "STUDENT" << setw(5) << left << "   " << total_overall_student << setw(7) << left << "  " << total_student_cost << endl;
	cout << setw(8) << left << " " << setw(5) << left << "    ---" << setw(4) << left << "  " << " ------" << endl;
	cout << setw(8) << left << "TOTAL" << setw(5) << left << "   " << total_people << setw(7) << left << "  " << total_cost << endl;

	cout << "\n================================================" << endl;
}
