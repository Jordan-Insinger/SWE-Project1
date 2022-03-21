#include <fstream>
#include <vector>
#include <iostream>
#include "task.h"
#include <string>

using namespace std;

vector<task> Open_File() {
	ifstream tasks("Resources\\tasks.tsk");
	vector<task> returner;
	if (!tasks.is_open()) {
		cout << "Cannot open the tasks file!" << endl;
	}
	else {
		string looper;
		getline(tasks, looper);
		while (looper == "START") {
			// Task data
			string name;
			string course;
			string duedate;
			string desc;
			int weight;
			int difficulty;

			string tempWeight;
			string tempDiff;

			getline(tasks, name);
			getline(tasks, course);
			getline(tasks, duedate);
			getline(tasks, tempWeight);
			weight = stoi(tempWeight);
			getline(tasks, tempDiff);
			difficulty = stoi(tempDiff);
			getline(tasks, desc);

			task temp(name, course, duedate, weight, difficulty, desc, true);

			returner.push_back(temp);

			//END
			string tempS;
			getline(tasks, tempS);

			//either next start or end of file.
			getline(tasks, looper);

		}
	}
	tasks.close();
	return returner;
}

void Write_File(vector<task> tasks){
	fstream save_file;
	save_file.open("Resources\\tasks.tsk");
	for (int i = 0; i < tasks.size(); i++) {
		if (tasks.at(i).get_valid()) {
			save_file << "START\n";
			save_file << tasks.at(i).get_name() << "\n";
			save_file << tasks.at(i).get_course() << "\n";
			save_file << tasks.at(i).get_duedate() << "\n";
			save_file << tasks.at(i).get_weight() << "\n";
			save_file << tasks.at(i).get_diff() << "\n";
			save_file << tasks.at(i).get_description() << "\n";
			save_file << "END\n";
		}
	}
}