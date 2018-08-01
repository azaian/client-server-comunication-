#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char txt[100], ptxt[100];
  int fd, fPointer, index = 0;

  /* read from the keyboard */
  fPointer = read(STDIN_FILENO, txt, 100);
  txt[fPointer] = '\0';

  /* open file1 with read write option */
  fd = open("file1.txt", O_RDWR | O_CREAT);
  if (0 > fd) {
    printf("unable to open file1.txt  \n");
    exit(1);
  }

  /* write the text from the keyboard to file1.txt */
  write(fd, txt, fPointer);

  /* set the file pointer to the beginning of the file1.txt */
  lseek(fd, 0, SEEK_SET);

  /* read form file1.txt */
  fPointer = read(fd, txt, fPointer);
  txt[fPointer] = '\0';
  close(fd);

  /* processing in txt get form the file1.txt */
  for (int i = 0; i < fPointer || txt[i] == '#'; i++) {

    if (txt[i] == '*') {
      while (txt[++i] != '*' || txt[i] == '#')
        ptxt[index++] = txt[i];
      ptxt[index] = '\0';
      break;
    }
  }

  /* open the file2.txt */
  fd = open("file2.txt", O_RDWR | O_CREAT);

  /*write the txt after the processing to file2.txt*/
  write(fd, ptxt, index);

  // set the file pointer to the begging of the file2
  lseek(fd, 0, SEEK_SET);

  /* read the content of file2.txt */
  fPointer = read(fd, txt, index);
  close(fd);

  /*write the content of file2.txt to the screen*/
  write(STDOUT_FILENO, txt, fPointer);

  return 0;
}
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  char txt[100], ptxt[100];
  int fd, fPointer, index = 0;

  /* read from the keyboard */
  fPointer = read(STDIN_FILENO, txt, 100);
  txt[fPointer] = '\0';

  /* open file1 with read write option */
  fd = open("file1.txt", O_RDWR | O_CREAT);
  if (0 > fd) {
    printf("unable to open file1.txt  \n");
    exit(1);
  }

  /* write the text from the keyboard to file1.txt */
  write(fd, txt, fPointer);

  /* set the file pointer to the beginning of the file1.txt */
  lseek(fd, 0, SEEK_SET);

  /* read form file1.txt */
  fPointer = read(fd, txt, fPointer);
  txt[fPointer] = '\0';
  close(fd);

  /* processing in txt get form the file1.txt */
  for (int i = 0; i < fPointer || txt[i] == '#'; i++) {

    if (txt[i] == '*') {
      while (txt[++i] != '*' || txt[i] == '#')
        ptxt[index++] = txt[i];
      ptxt[index] = '\0';
      break;
    }
  }

  /* open the file2.txt */
  fd = open("file2.txt", O_RDWR | O_CREAT);

  /*write the txt after the processing to file2.txt*/
  write(fd, ptxt, index);

  // set the file pointer to the begging of the file2
  lseek(fd, 0, SEEK_SET);

  /* read the content of file2.txt */
  fPointer = read(fd, txt, index);
  close(fd);

  /*write the content of file2.txt to the screen*/
  write(STDOUT_FILENO, txt, fPointer);

  return 0;
}
