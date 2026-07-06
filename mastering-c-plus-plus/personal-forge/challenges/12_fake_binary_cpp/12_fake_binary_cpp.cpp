// This is the Codewar challenge {Fake Binary}

#include <iostream>
#include <string>
using std::cin;

bool boolean_converter_for_integer_thershold(int num)
{
  return num >= 5?  true:  false;
}

std::string fakeBin(std::string str)
{
  std::string binary_string_result = "";
  
  for(size_t i = 0; i < str.size(); i++)
    {
      int current_digit = str[i] - '0';
      binary_string_result += (boolean_converter_for_integer_thershold(current_digit) + '0');   
    } 
  return binary_string_result;
}

int main()
{
    std::string num;
    printf("Please, Enter a number: ");
    cin >> num;
    char choice = 'N';
    do
    {
        printf("The binary of: %s is %s\n", num.c_str(), fakeBin(num).c_str());
        printf("Enter Y/y for repeat, any key for exiting...\n");
        cin >> choice;
        printf("\n");
    }
    while(choice == 'Y' || choice == 'y');
}