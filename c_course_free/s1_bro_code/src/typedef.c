#include "../header/typedef.h"
#include <stdio.h>

short main_typedef ()
{
  // typedef = reserved keyword that gives an existing datatype a "nickname"

  // char user1[25] = "bro"; // normal declaration and initialization of
  // varialbe user user2 = "code";    // declaration and initialization of user2
  // variable by using the nickname of "char user[25]"

  user_t user_1 = {"Mike", "passwd123", 155};
  user_t user_2 = {"bra", "12345", 255};

  printf (
    "the user: \"%s\" is using the password: \"%s\" and has the id: \"%d\"\n", user_1.name,
    user_1.password, user_1.id);
  printf (
    "the user: \"%s\" is using the password: \"%s\" and has the id: \"%d\"\n", user_2.name,
    user_2.password, user_2.id);

  return 0;
}
