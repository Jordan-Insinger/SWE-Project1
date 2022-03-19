#include "task.h"

/*---------------------------------------- Constructor ---------------------------------------*/
task::task(string _name, string _course, string _duedate, 
	int _weight, int _diff,string _description, bool _valid) {
	name = _name;
	course = _course;
	duedate = _duedate;
	weight = _weight;
	difficulty = _diff;
	description = _description;
	valid = _valid;
}

/*------------------------------------------ Getters -----------------------------------------*/

bool task::get_valid() {
	return valid;
}

int task::get_weight() {
	return weight;
}

int task::get_diff() {
	return difficulty;
}

string task::get_duedate() {
	return duedate;
}

string task::get_course() {
	return course;
}

string task::get_name() {
	return name;
}

string task::get_description() {
	return description;
}

/*------------------------------------------ Setters -----------------------------------------*/
void task::set_valid(bool _valid) {
	valid = _valid;
}

void task::set_weight(int _weight) {
	weight = _weight;
}

void task::set_diff(int _diff) {
	difficulty = _diff;
}

void task::set_duedate(string _duedate) {
	duedate = _duedate;
}

void task::set_course(string _course) {
	course = _course;
}

void task::set_name(string _name) {
	name = _name;
}

void task::set_description(string _description) {
	description = _description;
}