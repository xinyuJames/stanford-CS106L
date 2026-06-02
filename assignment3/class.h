#ifndef CLASS_H
#define CLASS_H

#include <string>

class Student
{
protected:
// protected variables
    std::string name = "default name";
    std::string gender = "default gender";
    int student_number = 0;
    
public:
    // constructor
    Student();
    Student(std::string name, std::string gender, int number);
    // deconstructor
    virtual ~Student();
    // get functions
    std::string get_name()   const;
    std::string get_gender() const;
    int get_student_number() const;

    // set functions
    void set_name(std::string name);
    void set_gender(std::string gender);
    void set_student_number(int student_number);

    // virtual functions
    virtual void play_hobby()        const = 0;

    // operator overloading
    // const func when *this may be called, friend only for non-member
    friend bool operator < (const Student& a, const Student& b);
    friend bool operator > (const Student& a, const Student& b);

    // operator only for member
    bool operator == (const Student& a) const;
    Student& operator = (const Student& other);
    // disable copy constructor
    Student(const Student& other) = delete;
};

// if protected Student, outside cannot convert Good_Kid to Student
class Good_Kid : public Student
{
private:
    std::string family = "=== empty ===";    
    std::string hobby = "=== empty ===";
    
public:
    Good_Kid();
    Good_Kid(
        std::string name,
        std::string gender,
        int number,
        
        std::string family,
        std::string hobby
    );
    ~Good_Kid() override;

    std::string get_family()       const;
    std::string get_hobby()        const;
    void set_family(std::string family);
    void set_hobby(std::string hobby);

    void play_hobby()       const override;
    void good_kid_stuff()   const;
};

class Bad_Kid : public Student
{
private:
    std::string hommie = "=== empty ===";
    std::string hobby = "=== empty ===";

public:
    Bad_Kid();
    Bad_Kid(
        std::string name,
        std::string gender,
        int number,
        
        std::string hommie,
        std::string hobby
    );
    ~Bad_Kid() override;

    std::string get_hommie()       const;
    std::string get_hobby()        const;
    void set_hommie(std::string hommie);
    void set_hobby(std::string hobby);

    void play_hobby()       const override;
    void bad_kid_stuff()    const;
};

#endif