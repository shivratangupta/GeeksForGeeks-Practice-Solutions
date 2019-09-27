/*
Count the number of 2s as digit in all numbers from 0 to n.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains the input integer n.

Output:
Print the count of the number of 2s as digit in all numbers from 0 to n.

Constraints:
1<=T<=100
1<=N<=10^5
*/

/* Counts the number of 2s in a number at d-th
   digit */
long long int count2sinRangeAtDigit(long long int number, long long int d)
{
// Your code goes here
    long long int power, nextpower, right, digit, result;
    power = pow(10, d);
    nextpower = power * 10;
    right = number % power;
    
    result = number - number % nextpower;
    digit = (number / power) % 10;
    
    if(digit < 2)
        return result / 10;
        
    if(digit == 2)
        return result / 10 + right + 1;
        
    return (result + nextpower) / 10;
}
/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
// Your code goes here
    string s;
    long long int n, result;
    s = to_string(number);
    n = s.size();
    result = 0;
    
    for(int i=s.size()-1; i>=0; i--)
        result += count2sinRangeAtDigit(number, i);
        
    return result;
}