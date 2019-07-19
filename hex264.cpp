#include<iostream>
#include<bitset>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<cstdlib>

using namespace std; 
string hex2bin(char value);
static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";


int main()
{
 string input;
 int size;
 int counter;
 
 jump:
    cout<<"Enter Hex string to be converted to Base64: ";
    cin>>input;  
    cout<<"\nYou have entered:\n"<<input<<endl;
  
    string hex1 = "0123456789abcdef";
    
    counter = 0;

    //validation that user input is a hex value
    for(int i = 0; i < input.length(); i++)
    { 
       for(int j =0; j < 16; j++)
       {
       if(input[i] == hex1[j])
         counter++;    
       }
    }
    if(counter != input.length())
    {
       cout<<"You have entered an invalid hex value\n";
       cout<<endl;
       goto jump;
    }

    int n = input.length();
    char hexi[n+1];
    strcpy(hexi,input.c_str());
    string bin[n+1];
    string binary;
    for(int i =0; i < input.size(); i++)
    {
      bin[i] = hex2bin(hexi[i]);
      binary.append(bin[i]);
      
    }
    cout<<"your hex value in binary: "<< binary<<endl;
    string base[n+1];
    int x = 0;
    for(int i = 0; i < input.length()*4;i=i+6)
    {
       
       base[i-(5*x)] =  binary.substr(i,6);
       x++;
       
    }
    int temp;
    cout<<base[0]<<endl;
    cout<<base[1]<<endl;
    int temp2 = x;
    cout<<temp2;
    for(int i = 0; i < x; i++){
       temp2 = stoi(base[i]);
       
    }   
              
 return 0;

}

string hex2bin(char value)
{
  string binary;
  switch(value)
  {
    case'0':
       
       binary = "0000";
       break;
    case'1':
       binary = "0001";
       break;
    case'2':
       binary = "0010";
       break;
    case'3':
       binary = "0011";
       break;
    case'4':
       binary = "0100";
       break;
    case'5':
       binary = "0101";
       break;
    case'6':
       binary = "0110";
       break;
    case'7':
       binary = "0111";
       break;
    case'8':
       binary = "1000";
       break;
    case'9':
       binary = "1001";
       break;
    case'a':
       binary = "1010";
       break;
    case'b':
       binary = "1011";
       break;
    case'c':
       binary = "1100";
       break;
    case'd':
       binary = "1101";
       break;
    case'e':
       binary = "1110";
       break;
    case'f':
       binary = "1111";
       break;

  }
 
  return binary;

}




