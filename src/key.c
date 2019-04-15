#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

int getkey();
struct termio tty_backup;
struct termio tty_change;

int getkey(){
  char in_char = 0;
  char in_char_ret = 0;
  char read_byte = 0;
  ioctl(0, TCGETA, &tty_backup);
  tty_change = tty_backup;
  tty_change.c_lflag &= ~(ECHO | ICANON);
  tty_change.c_cc[VMIN] = 0;
  tty_change.c_cc[VTIME] = 1;
  ioctl(0, TCSETAF, &tty_change);
  read_byte = read(0, &in_char, 1);
  if (read_byte == -1) {
    ioctl(0, TCSETAF, &tty_backup);
    return 1;
  }else{
    in_char_ret = in_char;
  }
  in_char = 0x00;
  ioctl(0, TCSETAF, &tty_backup);
  return in_char_ret;
}
