#include "Cinema.h"

Cinema::Cinema(){
	int Number;
	cout << "Enter the number of movies: ";
	cin >> Number;
	cout << endl;

	for (int i = 0; i < Number; i++) {
		Movie movie;
		Database.push_back(movie);
	}
}

void Cinema::Replase(){
	Database.clear();

	Cinema NewCinema;

	Database = NewCinema.Database;
}

void Cinema::ModifyTheContainer(){
	int Element;

	do {
		cout << "Enter the number of the movie you want to replace or enter 0 to exit: ";
		cin >> Element;
		cout << endl;

		if (Element != 0) {
			Database[Element - 1] = Movie();
		}
		else if (Element - 1 > Database.size()) {
			cout << "Error! Invalid number!" << endl;
		}

	} while (Element != 0);
	
}

void Cinema::PrintIterator(){

	for (auto it = Database.begin(); it != Database.end(); it++) {
		cout << "<======== " << it - Database.begin() + 1 << " movie ========>" << endl;
		it->Print();
		cout << "<=========================>" << endl;
	}
	cout << endl;
}

void Cinema::Change_the_first_container_and_add_elements_of_the_second_container(Cinema cinema){
	int n;
	cout<< "enter the number of the item from which the first container will be deleted: ";
	cin >> n;
	cout << endl;

	for (int i = Database.size() ; i >= n; i--) {
		if (Database.size() == 0) {
			cout << "The container is empty!" << endl;
			break;
		}

		Database.pop_back();
	}	

	for (int i = 0; i < cinema.Database.size(); i++) {
		Database.push_back(cinema.Database[i]);
	}

	cout << "The first container was changed and the elements of the second container were added!" << endl;
}

void Cinema::Print(){
	for (int i = 0; i < Database.size(); i++) {
		cout << "<======== " << i + 1 << " movie ========>" << endl;
		Database[i].Print();
		cout << "<=========================>" << endl;
	}
	cout << endl;
}
