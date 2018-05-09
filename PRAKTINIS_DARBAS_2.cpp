#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <typeinfo>
#include <regex>
using namespace std;
int main()
{
    ifstream read ("1500000 Sales Records.csv");
    ofstream write ("rezults.txt");
    string line;
    getline(read, line);
    write << line << endl;
    regex int_item("[+-]?[0-9]+");
    regex float_item("[+-]?([0-9]*[.])?[0-9]+");
    regex char_item("[a-zA-Z]");
    regex data_item("\\d{1,2}[/]\\d{1,2}[/]\\d{4}");
    while(!read.eof())
    {
        for(int i=0; i<14; i++)
        {
        	if(i != 13) getline(read, line,',');
        	else read >> line;
            if(i != 0)write<< " ";
            if(regex_match(line, int_item))
            {
                write << "int";
            }
            else if(regex_match(line, float_item))
            {
                write << "float";
            }
            else if(regex_match(line, char_item))
            {
                write << "char";
            }
            else if(regex_match(line, data_item))
            {
                write << "data";
            }
            else
            {
                write << "string";
            }
            if(i != 13) write << ',';
            else write << endl;
		}
		read.ignore();
    }
    write.close();
    read.close();
}
