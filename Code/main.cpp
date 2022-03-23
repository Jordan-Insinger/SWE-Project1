#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "task.h"
#include "task_sorting.h"
#include "FileIO.h"

using namespace std;

int main() {
	vector<task> tasks = Open_File();
	task taskObj;

	task t1 = task("t1", "Chemistry", "10-30-2021", 1, 0, "chem before hoes", true);
	task t3 = task("t3", "Bio", "01-01-2000", 8, 2);
	task t4 = task("t4", "Physics", "01-01-1400", 1, 3);

	t1.add_Task(tasks, t3);
	taskObj.delete_Task(tasks, t1);

	for (int i = 0; i < tasks.size(); i++) {
		cout << tasks.at(i).get_description() << endl;
	}
	Write_File(tasks);
	return 1;
}


int main1() {
	vector<task> tasks;
	task t1 = task("t1", "Chemistry", "10-30-2021", 1, 0);
	task t2 = task("t2", "Chemistry", "01-01-1969", 6, 1);
	task t3 = task("t3", "Bio", "01-01-2000", 8, 2);
	task t4 = task("t4", "Physics", "01-01-1400", 1, 3);
	task t5 = task("t5", "Comp Sci", "01-11-1969", 9, 4);
	task t6 = task("t6", "Personal", "01-08-1969", 6, 5);
	task t7 = task("t7", "Physics", "07-01-1969", 2, 6);
	task t8 = task("t8", "Bio", "04-04-1969", 6, 7);
	tasks.push_back(t1);
	tasks.push_back(t2);
	tasks.push_back(t3);
	tasks.push_back(t4);
	tasks.push_back(t5);
	tasks.push_back(t6);
	tasks.push_back(t7);
	tasks.push_back(t8);

	vector<task> sorted = task_sort(tasks, date);
	for (unsigned int i = 0; i < sorted.size(); i++) {
		cout << sorted[i].get_duedate() << endl;
	}

	return 0;
}