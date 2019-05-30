#include <stdio.h>
#include <string.h>

char input[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
char output[200];
char base64_lookup_table[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


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
  unsigned int input_length = strlen(input);
  unsigned int leftover_bits = 4;
  unsigned int bits_needed = 6;
  unsigned int n = 0;
  for(unsigned int i = 0, j = 0; i < input_length; ++i)
  {
    do
    {
      int shift_amount = bits_needed - leftover_bits;
      unsigned int input_val = 0;
      if(shift_amount > 0)
      {
        input_val = hex2dec(input[i]) << (shift_amount);
        bits_needed -= leftover_bits;
        leftover_bits = 0;
      }
      else
      {
        input_val = hex2dec(input[i]) >> (-1 * shift_amount);
        leftover_bits -= bits_needed;
        bits_needed = 0;
      }
      n = (n | input_val) & 0x3F;
      if(bits_needed == 0)
      {
        output[j] = base64_lookup_table[n];
        ++j;
        n = 0;
        bits_needed = 6;
      }
    } while(leftover_bits);
    leftover_bits = 4;
  }
  printf("Input: %s\nOutput: %s", input, output);
  return 0;
}