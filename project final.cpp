#include <iostream>
using namespace std;
struct information {
	int staffNumber;
	string staffName;
	string sex;
	int age;
	string education;
	int salary;
	string address;
	string phoneNumber;
	string departement;
};
void major() {
	cout << "=====================================================\n"
		<< "\tStaff Information Management System \n"
		<< "=====================================================\n\n";
	cout << "1) Department Mangement\n";
	cout << "2) Staff Mangement\n";
	cout << "3) Exit\n";
}
void departMangement() {
	cout << "===========================================\n"
		<< "\tDepartment Mangement \n"
		<< "===========================================\n\n";
	cout << "1) Add Department\n";
	cout << "2) Show All Department\n";
	cout << "3) modify Department\n";
	cout << "4) Delete Departement\n";
	cout << "5) back to main\n";
}
void staffManement() {
	cout << "===============================\n"
		<< "\tStaff Mangement"
		<< "===============================\n\n";
		cout << "1) Add Staff\n";
		cout << "2) Show All Staff\n";
		cout << "3) Modify Staff\n";
		cout << "4) Delete Staff\n";
		cout << "5) back to main Menu\n";
}
int main() {
	int choiceMain = 0;
	information staff;
	information listStaff[10];
	int count = 0;
	string departements[10] = {"iti", "nti", "ieee"};
	int counter = 3;
	while (choiceMain != 3) {
		major();
		cout << "enter your choice: ";
		cin >> choiceMain;
		while (choiceMain > 3 || choiceMain < 0) {
			cout << "please enter your choice between (1 to 3): ";
			cin >> choiceMain;
		}
		system("cls");
		if (choiceMain == 1) {
			int choiceLocal;
			departMangement();
			cout << "enter your choice: ";
			cin >> choiceLocal;
			while (choiceLocal > 5 || choiceLocal < 0) {
				cout << "please enter your choice between (1 to 5): ";
				cin >> choiceLocal;
			}
			system("cls");
			if (choiceLocal == 1) {
				bool found = false;
				string newDepartement;
				cout << "============================\n"
					<< "\tAdd Departement\n"
					<< "============================\n\n";
				cout << "Enter The New Departement: ";
				cin >> newDepartement;
				for (int i = 0; i < counter; i++) {
					if (newDepartement == departements[i]) {
						found = true;
						cout << "The Operation Is Faild (Depatement Is Existing) \n";
						break;
					}
				}
				if (found == false) {
					cout << "The Operation Was Completed Successfully\n";
					departements[counter] = newDepartement;
					counter++;
				}
			}
			else if (choiceLocal == 2) {
				cout << "=========================================\n"
					<< "\tShow All Depatements\n"
					<< "=========================================\n\n";
				for (int i = 0; i < counter; i++) {
					cout << departements[i] << " ";
				}
				cout << endl << endl;
			}
			else if (choiceLocal == 3) {
				string newDepartement;
				string editDepartement;
				bool found = false;
				int state;
				cout << "=======================================\n"
					<< "\tModify Departement\n"
					<< "=======================================\n\n";
				cout << "Please Enter The Departement to need modify: ";
				cin >> editDepartement;
				for (int i = 0; i < counter; i++) {
					if (departements[i] == editDepartement) {
						cout << "\nEnter The New Departement: ";
						cin >> newDepartement;
						departements[i] = newDepartement;
						found = true;
					}
				}
				if (found == false) {
					cout << "\nThe Deartement Name is Not Correct\n" << endl;
				}
				else {
					cout << "\nThe Operation Was Completed Successfully\n" << endl;
				}
			}
			else if (choiceLocal == 4) {
				cout << "============================\n"
					<< "\tDelete Departement\n"
					<< "============================\n\n";
				string deleteDepartement;
				bool found = false;
				cout << "Please Enter The Departement To Need Delete: ";
				cin >> deleteDepartement;
				for (int i = 0; i < counter ; i++) {
					if (departements[i] == deleteDepartement) {
						for (int j = i; j < counter; j++) {
							departements[j] = departements[j + 1];
						}
						counter--;
						found = true;
					}
				}
				if (found == false) {
					cout << "\nThe Deartement Name is Not Correct\n" << endl;
				}
				else {
					cout << "\nThe Operation Was Completed Successfully\n" << endl;
				}
			}
			else if (choiceLocal == 5) {
			}
		}
		else if (choiceMain == 2) {
			int choiceLocal;
			bool found;
			int empty = 0;
			staffManement();
			cout << "please Enter Your Choice: ";
			cin >> choiceLocal;
			if (choiceLocal == 1) {
				cout << "=========================\n"
					<< "\tAdd Staff\n"
					<< "=========================\n\n";
				cout << "Enter Staff Number: ";
				cin >> staff.staffNumber;
				for (int i = 0; i < count+1; i++) {
					while (listStaff[i].staffNumber == staff.staffNumber) {
						cout << "Please Enter The Another Staff Number: ";
						cin >> staff.staffNumber;
					}
				}
				cout << "\nEnter Staff Name: ";
				cin >> staff.staffName;
				cout << "\nEnter Sex (Male/Female): ";
				cin >> staff.sex;
				cout << "\nEnter Age: ";
				cin >> staff.age;
				cout << "\nEnter Education: ";
				cin >> staff.education;
				cout << "\nEnter Salary: ";
				cin >> staff.salary;
				cout << "\nEnter Address: ";
				cin >> staff.address;
				cout << "\nEnter Phone Number: ";
				cin >> staff.phoneNumber;
				do {
					if (empty == 0) {
						cout << "\nEnter Departement: ";
						empty++;
					}
					else {
						cout << "\nThe Departement Is Not Eisxt\n";
						cout << "\nEnter Anather Departement: ";
					}				
					cin >> staff.departement;
					for (int i = 0; i < count + 1; i++) {
						if (departements[i] != staff.departement) {
							found = false;
						}
						else {
							found = true;
						}
					}
				} while (!found);	
				cout << "\nThe operation was completed successfully\n";
				listStaff[count] = staff;
				count++;
			}
			else if (choiceLocal == 2) {
				cout << "============================\n"
					<< "\tShow All Staff\n"
					<< "============================\n\n";
				if (count == 0) {
					cout << "Not Exist Staff\n";
				}
				else {
					for (int i = 0; i < count; i++) {
						cout << "Staff Number: " << listStaff[i].staffNumber << endl;
						cout << "Name: " << listStaff[i].staffName << endl;
						cout << "Sex: " << listStaff[i].sex << endl;
						cout << "Age: " << listStaff[i].age << endl;
						cout << "Education: " << listStaff[i].education << endl;
						cout << "Salary: " << listStaff[i].salary << endl;
						cout << "Address: " << listStaff[i].address << endl;
						cout << "Phone Number: " << listStaff[i].phoneNumber << endl;
						cout << "Departement: " << listStaff[i].departement << endl;
						cout << "----------------------------\n";
					}
				}
			}
			else if (choiceLocal == 3) {
				int selectStaffNumber;
				bool found = false;
				int state;
				cout << "============================\n"
					<< "\tModify Staff f\n"
					<< "============================\n\n";
				cout << "Please Enter The Staff Number: ";
				cin >> selectStaffNumber;
				for (int i = 0; i < count; i++) {
					if (listStaff[i].staffNumber == selectStaffNumber) {
						found = true;
						cout << "Do You Want Change The Staff Name (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Name: " << listStaff[i].staffName << endl;
							cout << "Enter The New Staff Name: ";
							cin >> listStaff[i].staffName;
						}
						cout << "\nDo You Want Change The Sex (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Sex: " << listStaff[i].sex << endl;
							cout << "Enter The New Sex: ";
							cin >> listStaff[i].sex;
						}
						cout << "\nDo You Want Change The Age (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Age: " << listStaff[i].age << endl;
							cout << "Enter The New Age: ";
							cin >> listStaff[i].age;
						}
						cout << "\nDo You Want Change The Education (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Education: " << listStaff[i].education << endl;
							cout << "Enter The New Education: ";
							cin >> listStaff[i].education;
						}
						cout << "\nDo You Want Change The Salary (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Salary: " << listStaff[i].salary << endl;
							cout << "Enter The New Salary: ";
							cin >> listStaff[i].salary;
						}
						cout << "\nDo You Want Change The Address (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Address: " << listStaff[i].address << endl;
							cout << "Enter The New Address: ";
							cin >> listStaff[i].address;
						}
						cout << "\nDo You Want Change The Phone Number (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Address: " << listStaff[i].phoneNumber << endl;
							cout << "Enter The New Phone Number: ";
							cin >> listStaff[i].phoneNumber;
						}
						cout << "\nDo You Want Change The Departement (1)yes / (2)no): ";
						cin >> state;
						if (state == 1) {
							cout << "Department: " << listStaff[i].departement << endl;
							cout << "Enter The New Departement: ";
							cin >> listStaff[i].departement;
						}
						cout << "\nThe Operation Was Completed Successfully\n";
						break;
					}
				}
				if (found == false) {
					cout << selectStaffNumber << " Is Not Exist\n";
				}
			}
			else if (choiceLocal == 4) {
				int selectStaffNumber;
				bool found = false;
				cout << "============================\n"
					<< "\tDelete Staff f\n"
					<< "============================\n\n";
				cout << "Please Enter The Staff Number: ";
				cin >> selectStaffNumber;
				for (int i = 0; i < count; i++) {
					if (selectStaffNumber == listStaff[i].staffNumber) {
						found = true;
						for (int j = i; j < count - 1; j++) {
							listStaff[j].staffNumber = listStaff[j + 1].staffNumber;
							listStaff[j].staffName = listStaff[j + 1].staffName;
							listStaff[j].sex = listStaff[j + 1].sex;
							listStaff[j].age = listStaff[j + 1].age;
							listStaff[j].education = listStaff[j + 1].education;
							listStaff[j].salary = listStaff[j + 1].salary;
							listStaff[j].address = listStaff[j + 1].address;
							listStaff[j].phoneNumber = listStaff[j + 1].phoneNumber;
							listStaff[j].departement = listStaff[j + 1].departement;
						}
						count--;
						cout << "The Operation Was Completed Successfully\n";
						break;
					}
				}
				if (found == false) {
					cout << selectStaffNumber << " Is Not Exist\n";
				}
			}
			else if (choiceLocal == 5) {
			}
		}
		else if (choiceMain == 3) {
			cout << endl;
			break;
		}
	}
	return 0;
}