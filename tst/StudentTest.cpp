#include "classes/student.h"
#include "gtest/gtest.h"

TEST(StudentTestSuite, SetFirstName){
  Student s;

  s.setFirstName("Pedro");
  EXPECT_EQ(s.getFirstName(), "Pedro");
}

TEST(StudentTestSuite, RuleOfThree){
  Student stud;

  stud.setFirstName("Pedro");
  stud.setLastName("Guzman");
  stud.setExamGrade(10);

  Student studCopy(stud);
  EXPECT_EQ(studCopy.getFirstName(), stud.getFirstName());
  EXPECT_EQ(studCopy.getLastName(), stud.getLastName());
  EXPECT_EQ(studCopy.getExamGrade(), stud.getExamGrade());

  Student studCopy2;
  studCopy2 = stud;
  EXPECT_EQ(studCopy2.getFirstName(), stud.getFirstName());
  EXPECT_EQ(studCopy2.getLastName(), stud.getLastName());
  EXPECT_EQ(studCopy2.getExamGrade(), stud.getExamGrade());
}