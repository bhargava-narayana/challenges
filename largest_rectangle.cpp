/*There are N buildings in a certain one-dimensional landscape. 
 * If you join K adjacent buildings, they will form a 
 * solid rectangle of area K×min(h1,h2…,hk).
 *
 * Given N buildings, find the greatest such 
 * solid area formed by consecutive buildings.
 *
 * OR
 *
 * Find the largest rectangular area possible in a given 
 * histogram where the largest rectangle can be made of 
 * a number of contiguous bars. For simplicity, assume 
 * that all bars have same width and the width is 1 unit.
 *
 * For example, consider a histogram with 
 * 7 bars of heights {6, 2, 5, 4, 5, 2, 6}. 
 * The largest possible rectangle possible is 12
 *
 * area of rectangle = height * width
 *
 *Alogrithm:
 * 
 *1) Create an empty stack.
 * 
 *2) Start from first bar, and do following 
 * for every bar ‘height[i]’ where ‘i’ varies 
 * from 0 to n-1.
 * 
 * ……a) If stack is empty or height[i] is 
 * higher than the bar at top of stack, 
 * then push ‘i’ to stack.
 * 
 * ……b) If this bar is smaller than the top 
 * of stack, then keep removing the top of 
 * stack while top of the stack is greater. 
 * Let the removed bar be height[stack_ptr].
 * Calculate area of rectangle with height[stack_ptr] 
 * as smallest bar. For height[stack_ptr], 
 * the ‘left index’ is previous (previous to stack_ptr)
 * item in stack and ‘right index’ is ‘i’ (current index).
 *
 *3) If the stack is not empty, then one by one 
 *remove all bars from stack and do step 2.b for every removed bar.
 *
*/
#include <iostream>
#include <stack>
#include <cstdlib>

#define BUFFER 10
using namespace std;

int largest_rectangle(int n, int height[])
{
        int max_area = 0;       //current biggest area found
       
        int top_area;       //to store area of highest and smallest buildings
        
        //create a stack that contains the index's of 
        //height array in ascending order        
        stack<int> my_stack;

        int stack_ptr;  //to store top of stack
        
        //run through all the heights
        int i = 0;
        while(i < n)
        {
                //if height is greater then the height at top of stack push
                //to stack
                if(my_stack.empty() || height[my_stack.top()] <= height[i])
                        my_stack.push(i++);

                //if height is lower then height at top of stack then
                //calc area of rectangle with top of stack and smallest
                //height. "i" is 'right-index' from top and the top-1 element 
                //is the 'left index' 
                else
                {
                        stack_ptr = my_stack.top();
                        my_stack.pop();

                        top_area = height[stack_ptr] * (my_stack.empty() ? i : i - my_stack.top() - 1);

                        if(max_area < top_area)
                                max_area = top_area;
                }
        }
        
        //pop remaining heights and calc area with every popped
        //height as smallest height
        while(!my_stack.empty())
        {
                stack_ptr = my_stack.top();
                my_stack.pop();

                top_area = height[stack_ptr] * (my_stack.empty() ? i : i - my_stack.top() - 1);

                if(max_area < top_area)
                        max_area = top_area;
        }
        
        return max_area;
}

int main(int argc, char *argv[])
{
        int num_of_buildings;
        int  building_height[BUFFER];

        cout<<"enter number of buildings: ";
        cin>>num_of_buildings;
        
        cout<<"enter height of the buildings:\n";
        for(int i = 0; i < num_of_buildings; i++)
                cin>>building_height[i];

        cout<<"maximum area is: "<<largest_rectangle(num_of_buildings, building_height)<<endl;

        return EXIT_SUCCESS;
}
