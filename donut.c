#include <stdio.h>
#include <unistd.h>

int main() {
  int i, frame;
  char *donut[5] = {
    "         o         ",
    "        o o        ",
    "       o   o       ",
    "      o     o      ",
    "     o       o     "
  };

  for (frame = 0;; frame = (frame + 1) % 5) {
    for (i = 0; i < 5; i++) {
      printf("\033[%d;%dH%s\n", i + 5, 20, donut[(frame + i) % 5]);
    }
    usleep(100000); // sleep for 0.1 seconds
    printf("\033[%dA", 5); // move cursor up 5 lines
  }

  return 0;
}