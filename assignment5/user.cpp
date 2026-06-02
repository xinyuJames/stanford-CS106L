#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

std::ostream& operator << (std::ostream& cout, const User& cur)
{
  cout << "User(name="
    << cur._name
    << ", friends=[";

  for (int i=0; i<cur._size; i++)
  {
    cout << cur._friends[i];
    if (i != cur._size-1) cout << ", ";
  }
  cout << "])";
  
  return cout;
}

User::~User()
{
  delete [] _friends;
}

// member function can access private, always use initialization list to construct
// assignment to a naked
User::User(const User& other)
: _name(other._name), 
_size(other._size),
_capacity(other._capacity),
_friends(new std::string[other._size])
{
  for (int i=0; i<other._size; i++)
  {
    _friends[i] = other._friends[i];
  }
}

// copy assignment has return value, assignment to a already existing
User& User::operator = (const User& other)
{
  if (&other == this) return *this;

  this->_name = other._name;
  this->_size = other._size;
  this->_capacity = other._capacity;
  
  delete[] this->_friends;
  this->_friends = new std::string[this->_size];

  for (int i=0; i<this->_size; i++)
  {
    this->_friends[i] = other._friends[i];
  }

  return *this;
}

User& User::operator += (User& other)
{
  this->add_friend(other._name);
  other.add_friend(this->_name);

  return *this;
}

bool User::operator < (const User& other) const
{
  return this->_name.compare(other._name) < 0;
}



