/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
 

Constraints:

The given address is a valid IPv4 address.
*/

/*************************************************************************/

char * defangIPaddr(char * address){
    char *res = (char*)malloc(((strlen(address))*3 + 1) * sizeof(char));
    int j=0;
    for(int i=0; address[i] != '\0'; i++){
        if(address[i] == '.'){
            res[j++] = '[';
            res[j++] = '.';
            res[j++] = ']' ;
        }
        else
            res[j++] = address[i];
    }
    res[j] = '\0';
    return res;

}
