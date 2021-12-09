#include <string>
#include "gtest/gtest.h"
#include "Node.h"
TEST(TestCalc, t_1) {
  Node<int, 2> n1(1);
  Node<int, 2> n2(2);
  Node<int, 2> n3(3);
  n1.AddChild(&n2);
  EXPECT_EQ((n1.children()[0])->value(), 2);
}
TEST(TestCalc, t_2) {
  Node<int, 2> n1(1);
  Node<int, 2> n2(2);
  Node<int, 2> n3(3);
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  EXPECT_EQ((n1.children()[0])->value(), 2);
}
TEST(TestCalc, t_3) {
  Node<int, 2> n1(1);
  Node<int, 2> n2(2);
  Node<int, 2> n3(3);
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  EXPECT_EQ((n1.children()[1])->value(), 3);
}
TEST(TestCalc, t_4) {
  Node<int, 2> n1(3);
  Node<int, 2> n2(2);
  Node<int, 2> n3(3);
  Node<int, 2> n4(4);
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  n1.AddChild(&n4);
  EXPECT_EQ((n1.children()[0])->value(), 2);
}
TEST(TestCalc, t_5) {
  Node<int, 2> n1(3);
  Node<int, 2> n2(2);
  Node<int, 2> n3(3);
  Node<int, 2> n4(4);
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  n1.AddChild(&n4);
  EXPECT_EQ((n1.children()[1])->value(), 3);
}

TEST(TestCalc, t_6) {
  Node<std::string, 3> n1("aa");
  Node<std::string, 3> n2("bb");
  Node<std::string, 3> n3("cc");
  Node<std::string, 3> n4("dd");
  n1.AddChild(&n2);
  EXPECT_EQ((n1.children()[0])->value(), "bb");
}
TEST(TestCalc, t_7) {
  Node<std::string, 3> n1("aa");
  Node<std::string, 3> n2("bb");
  Node<std::string, 3> n3("cc");
  Node<std::string, 3> n4("dd");
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  EXPECT_EQ((n1.children()[0])->value(), "bb");
}
TEST(TestCalc, t_8) {
  Node<std::string, 3> n1("aa");
  Node<std::string, 3> n2("bb");
  Node<std::string, 3> n3("cc");
  Node<std::string, 3> n4("dd");
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  EXPECT_EQ((n1.children()[1])->value(), "cc");
}
TEST(TestCalc, t_9) {
  Node<std::string, 3> n1("aa");
  Node<std::string, 3> n2("bb");
  Node<std::string, 3> n3("cc");
  Node<std::string, 3> n4("dd");
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  n1.AddChild(&n4);
  EXPECT_EQ((n1.children()[0])->value(), "bb");
}
TEST(TestCalc, t_10) {
  Node<std::string, 3> n1("aa");
  Node<std::string, 3> n2("bb");
  Node<std::string, 3> n3("cc");
  Node<std::string, 3> n4("dd");
  n1.AddChild(&n2);
  n1.AddChild(&n3);
  n1.AddChild(&n4);
  EXPECT_EQ((n1.children()[2])->value(), "dd");
}
