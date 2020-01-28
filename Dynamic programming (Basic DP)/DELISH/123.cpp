//create executable
#include <unistd.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void parse(char *string1 ,char **argv)
{

    while (*string1!='\0')
    {
      while (*string1==' ')
      {
        *string1 ='\0';
        *string1++;
      }
        *argv = string1;
        *argv++;
      while (*string1!='\0' && *string1!= ' ')
      {
        string1++;

      }
    }
    *argv = '\0';
}


int main(int argc, char const *argv[])
{
  char sr1[1000];

  pid_t p1 ;
  string str1 = "g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -O2 -Wno-unused-result";
  str1 = "g++ -std=c++17 -Wshadow -Wall -o "%e" -O2 -Wno-unused-result";
  "g++ -std=c++17 -Wshadow -Wall -o "%e" "%f" -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG"

  return 0;
}

// compile1cpp
// buildcpp 
