#include "dna.h"
#include <iostream>
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/
double get_gc_content(const std::string& sDNA)
{
    double dGCCount = 0.0;

    for (int i = 0; i < sDNA.length(); ++i)
    {
        if (sDNA[i] == 'C' || sDNA[i] == 'G')
        {
            dGCCount++;
        }
    }

    return dGCCount / sDNA.length();
}


/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
std::string get_reverse_string(std::string sDNA)
{
    std::string sNewString = sDNA; //sets the new string to proper length
    int iStartIndex = 0;

    for (int i = sDNA.length() - 1; i >= 0; i--)
    {
        sNewString[iStartIndex] = sDNA[i];
        iStartIndex++;
    }

    return sNewString;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string

*/
std::string get_dna_complement(std::string sDNA)
{
    std::string sDNAReverse = "";

    sDNAReverse = get_reverse_string(sDNA);

    for (int i = 0; i < sDNAReverse.length(); ++i)
    {
        if (sDNAReverse[i] == 'A')
        {
            sDNAReverse[i] = 'T';
        }
        else if (sDNAReverse[i] == 'T')
        {
            sDNAReverse[i] = 'A';
        }
        else if (sDNAReverse[i] == 'C')
        {
            sDNAReverse[i] = 'G';
        }
        else if (sDNAReverse[i] == 'G')
        {
            sDNAReverse[i] = 'C';
        }
    }

    return sDNAReverse;
}
