#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void print_menu(WINDOW *menu_win, int highlight);
void execute_command(char *command);

int startx = 0;
int starty = 0;

char *choices[] = {
    "ls",
    "ls -la",
    "df -h",
    "quit",
};
int n_choices = sizeof(choices) / sizeof(char *);

int main() {
  // printf("sizeof(choices): %lu\nsizeof(char *): %lu\nn_choices: %lu\n",
  //        sizeof(choices), sizeof(char *), sizeof(choices) / sizeof(char *));
  WINDOW *menu_win;
  const int WIDTH = 30;
  const int HEIGHT = 10;
  const int OUTPUT_WIDTH = 80;
  const int OUTPUT_HEIGHT = 14;
  const int OUTPUT_STARTY = 12;
  int highlight = 1;
  int choice = 0;
  int c;

  initscr();
  clear();
  noecho();
  cbreak(); /* Line buffering disabled. pass on everything */
  startx = (80 - WIDTH) / 2;
  starty = (24 - HEIGHT) / 2;

  menu_win = newwin(HEIGHT, WIDTH, starty, startx);
  keypad(menu_win, TRUE);
  mvprintw(0, 0,
           "Use arrow keys to go up and down, Press enter to select a choice");
  refresh();
  print_menu(menu_win, highlight);
  while (1) {
    c = wgetch(menu_win);
    switch (c) {
    case KEY_UP:
      if (highlight == 1)
        highlight = n_choices;
      else
        --highlight;
      break;
    case KEY_DOWN:
      if (highlight == n_choices)
        highlight = 1;
      else
        ++highlight;
      break;
    case 10:
      choice = highlight;
      break;
    default:
      mvprintw(24, 0,
               "Charcter pressed is = %3d Hopefully it can be printed as '%c'",
               c, c);
      refresh();
      break;
    }
    print_menu(menu_win, highlight);
    if (choice != 0)
      break;
  }
  if (strcmp(choices[choice - 1], "quit") == 0) {
    endwin();
    return 0;
  }
  // execute command and print output
  WINDOW *output_win;
  output_win = newwin(OUTPUT_HEIGHT, OUTPUT_WIDTH, OUTPUT_STARTY, 0);
  scrollok(output_win, TRUE);
  wprintw(output_win, "Command: %s\n\n", choices[choice - 1]);
  wrefresh(output_win);
  execute_command(choices[choice - 1]);
  mvprintw(24, 0, "Press 'b' to go back to the main menu");
  refresh();
  while (1) {
    c = getch();
    if (c == 'b') {
      break;
    }
  }
  delwin(output_win);
  main();
  // return 0;
}

void print_menu(WINDOW *menu_win, int highlight) {
  int x, y, i;

  x = 2;
  y = 2;
  box(menu_win, 0, 0);
  for (i = 0; i < n_choices; ++i) {
    if (highlight == i + 1) /* High light the present choice */
    {
      wattron(menu_win, A_REVERSE);
      mvwprintw(menu_win, y, x, "%s", choices[i]);
      wattroff(menu_win, A_REVERSE);
    } else
      mvwprintw(menu_win, y, x, "%s", choices[i]);
    ++y;
  }
  wrefresh(menu_win);
}

void execute_command(char *command) {
  pid_t pid;
  int status;
  // char output[80];

  pid = fork();

  if (pid == -1) {
    // Fork error
    printf("Error creating child process\n");
    exit(1);
  } else if (pid == 0) {
    // Child process
    char *args[4];
    args[0] = "/bin/sh";
    args[1] = "-c";
    args[2] = command;
    args[3] = NULL;
    dup2(STDOUT_FILENO, STDERR_FILENO);
    dup2(fileno(stdout), fileno(stderr));
    execv(args[0], args);
    exit(1);
  } else {
    // Parent process
    waitpid(pid, &status, 0);
  }
}
