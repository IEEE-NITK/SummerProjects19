#include <stdio.h>
#include <string.h>

char input1[] = "1c0111001f010100061a024b53535009181c";
char input2[] = "686974207468652062756c6c277320657965";
char output[38];
char lookup[17] = "0123456789abcdef";


unsigned int hex2dec(char x)
{
  char val = 0;
  if(x > 'a') { val = x - 'a' + 10; }
  else if(x > 'A') { val = x - 'A' + 10; }
  else { val = x - '0'; }
  return val;
}

int main()
{
  unsigned int input_length = strlen(input1);
  unsigned int n1 = 0, n2 = 0, op_num = 0;;
  for(unsigned int i = 0; i < input_length; ++i)
  {
    n1 = hex2dec(input1[i]);
    n2 = hex2dec(input2[i]);
    op_num = n1 ^ n2;
    output[i] = lookup[op_num];
  }
  printf("Input1: %s\nInput2: %s\nOutput: %s", input1, input2, output);
  return 0;
}