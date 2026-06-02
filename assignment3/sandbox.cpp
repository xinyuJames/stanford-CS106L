/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include  "class.h"
#include <iostream>
#include <typeinfo>

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  
  Student * classroom[4] = {
    new Good_Kid(),
    new Bad_Kid("b", "boy", 99, "kyle and jason", "play with shit"),
    new Good_Kid("c", "girl", 2, "Alice and Oliver", "read books"),
    new Good_Kid("d", "girl", 3, "Wong and Kim", "play badminton")
  };

  classroom[0]->set_name("a");
  classroom[0]->set_gender("girl");
  classroom[0]->set_student_number(5);
  
  std::cout << "===== Welcome to the class =====" << "\n";

  for (Student * stu : classroom)
  {
    stu->play_hobby();

    if (Good_Kid* gk = dynamic_cast<Good_Kid*>(stu)) gk->good_kid_stuff();
    else if (Bad_Kid* bk = dynamic_cast<Bad_Kid*>(stu)) bk->bad_kid_stuff();
    
    if (*stu > *(classroom[0]))
    {
      std::cout << stu->get_name() << " is Bigger than "
        << classroom[0]->get_name()
        << "\n";
    } else
    {
      std::cout << stu->get_name() << " is smaller or equal than "
        << classroom[0]->get_name()
        << "\n";
    }
  }

  for (Student * stu : classroom)
  {
    delete stu;
  }

  std::cout << "===== End the class =====" << "\n";

}