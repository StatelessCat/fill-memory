#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main ( int arc, char **argv ) {
  srand(time(NULL));
  unsigned int CHUNKS = 1024 * 1024;
  unsigned int ALLOC_SIZE = 1024 * 1024 * sizeof(char); // 1MB
  unsigned int allocated_bytes = 0;
  unsigned int i = 0;

  char ** ptrs = malloc(CHUNKS * sizeof(char *));
  do {
    ptrs[i] = malloc(ALLOC_SIZE);
    for (int j = 0; j < ALLOC_SIZE; ++j) {
      ptrs[i][j] = rand();
    }
    allocated_bytes += ALLOC_SIZE/1024;
    printf("%d Mbytes allocated\n", allocated_bytes);
    // usleep(10000);
    ++i;
  } while (1);

  return 0;
}
