/*
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/
bool isVowels(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u') return true;
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c =='U') return true;

    return false;
}

char* reverseVowels(char* s) {
    int iStart = 0;
    int iEnd   = strlen(s) - 1;
    char tmp;

    while(iStart < iEnd)
    {
        if(true == isVowels(s[iStart]) && true == isVowels(s[iEnd]))
        {
            tmp = s[iStart];
            s[iStart] = s[iEnd];
            s[iEnd] = tmp;
            iStart++;
            iEnd--;
        }

        if(false == isVowels(s[iStart])) iStart++;
        if(false == isVowels(s[iEnd])) iEnd--;
    }

    return s;
}
