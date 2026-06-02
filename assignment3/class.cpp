#include "class.h"
#include <iostream>

Student::Student(std::string name, std::string gender, int number) :
name(name), gender(gender), student_number(number) {};

Student::Student() {}

Student::~Student()
{
    std::cout << "deconstructing student..." << "\n";
}

std::string Student::get_name() const
{
    return this->name;
}

std::string Student::get_gender() const
{
    return this->gender;
}

int Student::get_student_number() const
{
    return this->student_number;
}

void Student::set_name(std::string name)
{
    this->name = name;
}

void Student::set_gender(std::string gender)
{
    this->gender = gender;
}

void Student::set_student_number(int num)
{
    this->student_number = num;
}

bool operator < (const Student& a, const Student& b)
{
    return a.student_number < b.student_number;
}

bool operator > (const Student& a, const Student& b)
{
    return !(a<b);
}

Good_Kid::Good_Kid(
    std::string name,
    std::string gender,
    int number,
    
    std::string family,
    std::string hobby
) : Student(name, gender, number), family(family), hobby(hobby) {};

Good_Kid::Good_Kid() : Student() {};

Good_Kid::~Good_Kid()
{
    std::cout << "deconstructing good kid "
        << this->name << "\n";
}

std::string Good_Kid::get_family() const
{
    return this->family;
}

std::string Good_Kid::get_hobby() const
{
    return this->hobby;
}

void Good_Kid::set_family(std::string family)
{
    this->family = family;
}

void Good_Kid::set_hobby(std::string hobby)
{
    this->hobby = hobby;
}

void Good_Kid::play_hobby() const
{
    std::cout << name << ", " << student_number
        << " is playing with" << hobby << "\n";
}

void Good_Kid::good_kid_stuff() const
{
    std::cout << "Hi, I am " << name
        << ", and I am a good kid with a family of "
        << family << "\n";
}

Bad_Kid::Bad_Kid() : Student() {}

Bad_Kid::Bad_Kid(
    std::string name,
    std::string gender,
    int number,

    std::string hommie,
    std::string hobby
) : Student(
    name,
    gender,
    number
), hommie(hommie), hobby(hobby) {};

Bad_Kid::~Bad_Kid()
{
    std::cout << "deconstructing bad kid " << this->name
        << "\n";
}

std::string Bad_Kid::get_hommie() const
{
    return this->hommie;
}

std::string Bad_Kid::get_hobby() const
{
    return this->hobby;
}

void Bad_Kid::set_hommie(std::string hommie)
{
    this->hommie = hommie;
}

void Bad_Kid::set_hobby(std::string hobby)
{
    this->hobby = hobby;
}

void Bad_Kid::play_hobby() const
{
    std::cout << "yo, it's " << name
        << ", #" << student_number
        << ", out here messin' with "
        << hobby << ", lessgo\n";
}

void Bad_Kid::bad_kid_stuff() const
{
    std::cout << "ayo, the name's " << name
        << ", I'm a bad kid an' I roll deep with my hommie "
        << hommie << "\n";
}


