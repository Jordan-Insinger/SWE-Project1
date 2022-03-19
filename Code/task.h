#pragma once
#include <string>
using namespace std;

class task
{
	bool valid;
	int weight, difficulty;
	string duedate, course, name, description;

public:
	/*---------------------------------------- Constructor ---------------------------------------*/
	task(string _name = "Task", string _course = "None", string _duedate = "01-01-1969",
		int _weight = 0, int _diff = 0, string _description = "", bool _valid = true);


	/*------------------------------------------ Getters -----------------------------------------*/
	bool get_valid();
	int get_weight();
	int get_diff();
	string get_duedate();
	string get_course();
	string get_name();
	string get_description();

	/*------------------------------------------ Setters -----------------------------------------*/
	void set_valid(bool _valid);
	void set_weight(int _weight);
	void set_diff(int _diff);
	void set_duedate(string _duedate);
	void set_course(string _course);
	void set_name(string _name);
	void set_description(string _description);

};