#include "task_sorting.h"

/*------------------------------------------ Main Sort -----------------------------------------*/
vector<task> task_sort(vector<task> tasks, attributes parameter, bool ascending) {
	vector<task> result = merge_sort(tasks, 0, tasks.size() - 1, parameter);
	if (ascending)
		return result;
	else
		return reverse(result);
}


/*------------------------------------------ Merge Sort -----------------------------------------*/

vector<task> merge_sort(vector<task> tasks, int left, int right, attributes var) {
	if (right > left) {
		int middle = left + (right - left) / 2;
		vector<task> one = merge_sort(tasks, left, middle, var);
		vector<task> two = merge_sort(tasks, middle + 1, right, var);
		switch (var) {
		case (attributes::weight):
			return merge(one, two, 'w');
			break;
		case (attributes::diff):
			return merge(one, two, 'd');
			break;
		case (attributes::course):
			return merge(one, two, 'c');
			break;
			case (attributes::date):
			return merge(one, two, 'z');
			break;
		default:
			break;
		}
		
	}
	else {
		vector<task> hold;
		hold.push_back(tasks[left]);
		return hold;
	}
}

// Merge vectors in ascending order for merge_sort.
vector<task> merge(vector<task> left, vector<task> right, char var) {
	vector<task> res;
	unsigned int i = 0, j = 0;
	while (i < left.size() || j < right.size()) {
		if (i < left.size() && j < right.size()) {

			// Sort by weights.
			if (var == 'w') {
				if (left[i].get_weight() < right[j].get_weight()) {
					res.push_back(left[i]);
					i++;
				}
				else {
					res.push_back(right[j]);
					j++;
				}
			}

			// Sort by difficulty.
			else if (var == 'd') {
				if (left[i].get_diff() < right[j].get_diff()) {
					res.push_back(left[i]);
					i++;
				}
				else {
					res.push_back(right[j]);
					j++;
				}
			}

			// Sort by difficulty.
			else if (var == 'c') {
				if (lower_string(left[i].get_course()) < lower_string(right[j].get_course())) {
					res.push_back(left[i]);
					i++;
				}
				else {
					res.push_back(right[j]);
					j++;
				}
			}

			// Sort by due date.
			else if (var == 'z') {
				string l_date = left[i].get_duedate(), r_date = right[j].get_duedate();

				if (before(l_date, r_date)) {
					res.push_back(left[i]);
					i++;
				}
				else {
					res.push_back(right[j]);
					j++;
				}

			}
		}
		else if (i < left.size()) {
			res.push_back(left[i]);
			i++;
		}
		else {
			res.push_back(right[j]);
			j++;
		}
	}
	return res;
}


/*------------------------------------------ Helpers -----------------------------------------*/


// Make a string all lowercase.
string lower_string(string s) {
	for (unsigned int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

// True if the first date is the earliest.
bool before(string l_date, string r_date) {
	int l_m = stoi(l_date.substr(0, 2)), r_m = stoi(r_date.substr(0, 2));
	int l_d = stoi(l_date.substr(3, 2)), r_d = stoi(r_date.substr(3, 2));
	int l_yr = stoi(l_date.substr(6, 4)), r_yr = stoi(r_date.substr(6, 4));

	if (l_yr < r_yr) {
		return true;
	}
	else if (l_yr > r_yr) {
		return false;
	}
	else {
		if (l_m < r_m) {
			return true;
		}
		else if (l_m > r_m) {
			return false;
		}
		else {
			if (l_d < r_d) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

// Reverse a task vector.
vector<task> reverse(vector<task> v) {
	int len = v.size();
	for (unsigned int i = 0; i < v.size()/2; i++) {
		task temp = v[len - 1 - i];
		v[len - 1 - i] = v[i];
		v[i] = temp;
	}
	return v;
}
