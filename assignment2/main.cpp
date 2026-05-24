/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Xinyu Liu"; // Don't forget to change this!

std::vector<std::string> split(const std::string& string_to_split, char deli)
{
  std::vector<std::string> rtn;
  std::stringstream ss(string_to_split);
  std::string cur;
  while (std::getline(ss, cur, deli))
  {
    rtn.push_back(cur);
  }
  
  return rtn;
}

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> rtn;
  std::ifstream ifile;
  ifile.open(filename);
  std::string name;
  
  while (getline(ifile, name))
  {
    rtn.insert(name);  
  }
  ifile.close();

  return rtn;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::vector<std::string> name_split;
  std::set<std::vector<std::string>> students_split;
  std::queue<const std::string*> rtn;

  if (name.empty()) return rtn;
  // split name
  name_split = split(name, ' ');
  
  for (auto it = students.begin(); it != students.end(); ++it)
  {
    std::string cur = *it;
    std::vector<std::string> cur_split = split(cur, ' ');
    if (name_split.size() != cur_split.size()) continue;

    bool match = true;
    for (int i=0; i<name_split.size(); i++)
    {
      if (name_split[i][0] != cur_split[i][0]) match = false;
    }

    if (match)
    {
      rtn.push(&(*it));
    }
  }
  return rtn;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if (matches.empty()) return "NO MATCHES FOUND.";

  return *matches.back();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
