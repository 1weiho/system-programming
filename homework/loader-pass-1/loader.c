#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTableHead() { printf("CS\tSN\tADDR\tLENGTH\n"); }

void printSectionHead(char csName[], int address, int length) {
  printf("%s\t\t%.4X\t%.4X\n", csName, address, length);
}

void printSymbol(char symbol[], int address) {
  printf("\t%s\t%.4X\t\n", symbol, address);
}

char *readProgName(char *str) {
  int i;
  char temp[100];
  char *res = NULL;

  memset(temp, 0, sizeof(temp));

  for (i = 1; i < strlen(str); i++) {
    if (str[i] == ' ') {
      break;
    }
    strncat(temp, &str[i], 1);
  }

  asprintf(&res, "%s", temp);

  return res;
}

int readProgLength(char *str) {
  int i, j;
  char temp[100];
  int res;

  memset(temp, 0, sizeof(temp));

  for (i = 1; i < strlen(str); i++) {
    if (str[i] == ' ') {
      for (j = i + 1; j < strlen(str); j++) {
        strncat(temp, &str[j], 1);
      }
      break;
    }
  }

  res = (int)strtol(temp, NULL, 16);

  return res;
}

void readSymbol(char *str, int currentAddress) {
  int i, j;
  char symbol[100];
  char addr[100];
  int addrInt;
  char *res = NULL;
  memset(symbol, 0, sizeof(symbol));
  memset(addr, 0, sizeof(addr));

  for (i = 1; i < strlen(str);) {
    if (str[i] < 48 || str[i] > 57) {
      strncat(symbol, &str[i], 1);
      i++;
    }
    if (str[i] == ' ') {
      for (j = i + 1;;) {
        if (str[j] == ' ') {
          j++;
        } else if (str[j] >= 48 && str[j] <= 57) {
          strncat(addr, &str[j++], 1);
        } else {
          i = j;
          addrInt = (int)strtol(addr, NULL, 16);
          addrInt += currentAddress;
          printSymbol(symbol, addrInt);
          memset(symbol, 0, sizeof(symbol));
          memset(addr, 0, sizeof(addr));
          break;
        };
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int progAddr;
  int progLength;
  int startAddress;
  int currentAddress;
  FILE *file;
  char word;
  char str[100];
  int i, j, k;

  startAddress = (int)strtol(argv[1], NULL, 16);
  currentAddress = startAddress;
  memset(str, 0, sizeof(str));

  if (argc < 2) {
    printf("file not found!");
    return 1;
  }

  printTableHead();

  for (i = 2; i < argc; i++) {
    file = fopen(argv[i], "r");

    while (fgets(str, sizeof(str), file)) {
      if (str[0] == 'H') {
        progLength = readProgLength(str);
        printSectionHead(readProgName(str), currentAddress, progLength);
      }
      if (str[0] == 'D') {
        readSymbol(str, currentAddress);
      }
    }
    currentAddress += progLength;
  }

  fclose(file);
  return 0;
}