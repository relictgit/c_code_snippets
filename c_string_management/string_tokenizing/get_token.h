#ifndef GET_TOKEN_H
#define GET_TOKEN_H

void tokenize_string();
char *get_specific_token_value(char string[], char delimeter[], int position);
void get_specific_token_referenze(char string[], char delimeter[], int position,
                                  char **string_token);

#endif // GET_TOKEN_H
