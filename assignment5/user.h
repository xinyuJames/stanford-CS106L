/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);

  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const;
  void set_friend(size_t index, const std::string& name);

  /** 
   * STUDENT TODO:
   * Your custom operators and special member functions will go here!
   */

  // stream non-member overload
  friend std::ostream& operator << (std::ostream& cout, const User& cur);

  // deconstructor
  ~User();

  // copy
  User(const User& other);
  User& operator = (const User& other);

  // move
  User(User&& other) = delete;
  User& operator = (User&& other) = delete;

  // operator member overload
  User& operator += (User& other);
  bool operator < (const User& other) const;

private:
  std::string _name;
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};