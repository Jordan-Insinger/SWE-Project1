#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "task.h"
using namespace std;

// Used in sort functions.
enum class attributes { weight, diff, course, date };



/*------------------------------------------ Main Sort -----------------------------------------*/
vector<task*> task_sort(vector<task*> tasks, attributes parameter, bool ascending= true);

/*------------------------------------------ Merge Sort -----------------------------------------*/

vector<task*> merge_sort(vector<task*> tasks, int left, int right, attributes var);
vector<task*> merge(vector<task*> left, vector<task*> right, char var);

/*------------------------------------------ Helpers -----------------------------------------*/

string lower_string(string s);
bool before(string l, string r);
vector<task*> reverse(vector<task*> v);