/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("2");
	ASSERT_EQ(2,actual);
}

TEST(PasswordTest, no_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, two_repetitive_character)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aabcdefg");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, only_lowercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aaa");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, only_uppercase)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AAA");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aAaAa");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, speical_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aB1");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, special_case_2)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Ab_~");
	ASSERT_EQ(true, actual);
}
