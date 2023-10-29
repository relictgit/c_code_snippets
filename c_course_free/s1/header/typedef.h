#ifndef TYPEDEF_H
#define TYPEDEF_H

typedef char user[25];
typedef struct {
  char name[25];
  char password[12];
  int id;
} user_t;

/* declaration of struct without using typedef
struct user_t {
  char name[25];
  char password[12];
  int id;
};
*/

short main_typedef();

#endif // TYPEDEF_H
