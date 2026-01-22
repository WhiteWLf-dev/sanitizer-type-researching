.// ./expN -fork=1 -ignore-crashes=1 -seed=1 inputs/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include <haproxy/cfgparse.h>
#include "./src/cfgparse-tcp.c"

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
      char filename[256];
      sprintf(filename, "exp1_1cfg.%d", getpid()); 

      FILE *fp = fopen(filename, "wb");
      if (!fp) {
        exit(1);
      }

      fwrite(Data, Size, 1, fp);
      fclose(fp);
      readcfgfile(filename); //target function

      unlink(filename);
}
