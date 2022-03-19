#include <fstream>
#include <vector>
#include <iostream>
#include "task.h"
#include <string>

using namespace std;

vector<task> Open_File() {
	ifstream tasks("tasks.tsk");
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