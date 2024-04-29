


#include <iostream>
#include <cstdlib>
#include <string>
#include "functions.h"

enum CHOICE {
	ADD_NOTE = 1,
	SEE_ALL_NOTES = 2,
    FIND_ONE_NOTE = 3,
	REMOVE_ONE_NOTE =4,
	REMOVE_ALL_NOTES =5

};

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	while (true) {
		show_menu();
		cout << "Enter your choice:";
		int choice = 0;
		cin >> choice;
		if (choice == ADD_NOTE) {
			system("cls");
			string new_note;
			getline(cin, new_note);//пропуск переноса строки после cin
			cout << "add_note()" << endl;
			getline(cin, new_note);//для считывания новой заметки
			add_note(new_note);
			system("pause");

		}
		else if (choice == SEE_ALL_NOTES) {
			system("cls");
			cout << "See_all_notes()" << endl;
			system("pause");
		}
		else if (choice == FIND_ONE_NOTE) {
			system("cls");
			string note_to_find;
			getline(cin, note_to_find);//пропуск переноса строки после cin
			cout << " find_note:";
			getline(cin, note_to_find);

			int n_found = 0;
			string* found_notes = find_one_note( note_to_find,n_found);
			if (found_notes) {
				cout << "Found notes:" << endl;
				for (int i = 0; i < n_found; i++)
					cout <<found_notes [i] << endl;
				delete[]found_notes;
			}
			
			else {
				cout << "no such note" << endl;
			}
			system("pause");
		}
		else if (choice == REMOVE_ONE_NOTE) {
			system("cls");
			//получаем все заметки
			int count = 0;
			string* all_notes_arr =all_notes(count);
			
			//выводим их в консоль
			cout << "All_notes:" << endl;
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
			cout << "Number of note to remove:";
			int choice = 0;
			cin >> choice;
			remove_one_note(all_notes_arr,count,choice);
			cout << "Your note removed!"<<endl;
			delete[]all_notes_arr;
			system("pause");
		}
		else if (choice == REMOVE_ALL_NOTES) {
			system("cls");
			remove_all_notes();
			cout << "remove_all_notes()" << endl;
			system("pause");
		}
		else
			break;
}
} 
