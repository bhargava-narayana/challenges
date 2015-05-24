/*Problem Statement:
 *      Given a list containing N integers,
 *      calculate the XorSum of all the 
 *      non-empty subsets of the list 
 *      and print the value of XorSum % (109+7).
 *
 *      XOR operation on a list is defined 
 *      as the xor (⊕), of all the elements 
 *      present in it, e.g.
 *              XOR({A,B,C})=A⊕B⊕C.
 *
 *      XorSum of a list is the sum of the 
 *      XORs of every possible non-empty 
 *      subset of the list. 
 * 
 *Example: 
 *       for list X={x1,x2,x3} all 
 *       possible non-empty subsets are 
 *       [{x1},{x2},{x3},{x1,x2},{x1,x3},
 *                    {x2,x3},{x1,x2,x3}] 
 *       XorSum(X)=x1+x2+x3+(x1⊕x2)+(x1⊕x3)+
 *                           (x2⊕x3)+(x1⊕x2⊕x3)
 *
 * Input Format: 
 *       An integer T, denoting the 
 *       number of testcases. 2×T lines follow.
 *      Each testcase contains two lines,
 *      first line will contains an integer 
 *      N followed by second line containing 
 *      N integers, a1,a2,…,aN, separated 
 *      by a single space.
 *
 * Output Format 
 *      T lines, ith line containing 
 *      the output of the ith testcase.
 *
 * Sample Input 
 * 1
 * 3
 * 1 2 3
 Sample Output 
 * 12
 *Explanation: 
 *       The given case will have 7 
 *       non-empty subsets whose XOR is given below
 *       1=1
 *       2=2
 *       3=3
 *       1⊕2=3
 *       2⊕3=1
 *       3⊕1=2
 *       1⊕2⊕3=0
 *       So sum of all such XORs is 12.
 *
 * Solution: 
 *      Find OR of all the elements and 
 *      multiply it with 2^(n-1) where n
 *      is the total number of elements.
 *      This gives us the answer.
 *Idea:
 *      There will be total 2^n subsets.
 *      If ith bit of any element is set,
 *      then that bit will be set in xor 
 *      of half of the total subsets which 
 *      is 2^(n-1).
 *
 *      To find out all the set bits in 
 *      all the numbers we find OR of all
 *      the numbers.
 *
 *      Since each set bit appears in half 
 *      of the total subsets we multiply OR 
 *      of all numbers with 2^n-1 to get the 
 *      final result.
*/
#include <iostream>
#include <cassert>
#include <cstdlib>

#define MOD 1000000007

using namespace std;

long long int power(long long int n, long long int k)
{
        long long int result;
        long long int pow;
        if(k == 0)
                return 1;
        if(n == 0)
                return 0;
        if(n == 1)
                return 1;
        result = n % MOD;
        pow = 1;
        while(pow * 2 <= k)
        {
                pow = pow * 2;
                result = (result * result);
                result = result % MOD;
        }//end while
        
        if(k - pow != 0)
                result = result * power (n, k-pow);
        
        result =result % MOD;
        
        return result;
}

int main(int argc, char *argv[])
{
        int t;
        cin>>t;

        while(t--)
        {
                int n;
                cin>>n;
                long long ans = 0;
                long long temp;
                for(int i = 0; i < n; i++)
                {
                        cin>>temp;
                        ans |= temp;
                }
                ans *= power(2,n-1);
                ans %= MOD;
                cout<<ans<<"\n";
        }//end while

        return 0;
}
