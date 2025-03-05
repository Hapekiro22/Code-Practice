#include <iostream>
#include <algorithm>
#include <string.h>
#define LEN 10
#define STEP 3

using namespace std;

bool check(int *count)
{
    int i = 1;
    while(i < 10)
    {
        if(count[i] > 1) return false;
        else i++;
    }
    //memset(count, 0, 10 * sizeof(int)); // Reset count array
    return true;
}

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int num[LEN] = {1,2,3,4,5,6,7,8,9};
    int count[10] = {0};
    int start = 123;
    int end = 987;
    int flag = 0;

    if(a*b*c == 0)
    {
        cout << "No!!!" << endl;
        return 0;
    }
    while(start / a * c <= end)
    {
        //cout << "check" << start << endl;
        int temp = start;
        for(int i = 0; i < STEP;i++)
        {
            count[temp%10]++;
            temp /= 10;
        }
        if(!check(count) || (start % a) != 0)
        {
            //cout << check(count) << " " << (start % a) << endl;
            //cout << "Failed" << endl;
            if(start % a != 0) start += a - start % a;
            else
                start += a;
            memset(count,0,sizeof(count));
        }

        else
        {
            int num2 = start / a * b;
            int num3 = start / a * c;
            //cout << "num2: " << num2 << " num3: " << num3 << endl;
            for(int i = 0; i < STEP;i++)
            {
                count[num2%10]++;
                count[num3%10]++;
                num2 /= 10;
                num3 /= 10;
            }
            if(count[0] != 0)
            {
                start++;
                memset(count,0,sizeof(count));
            }
            else
            if(!check(count))
            {
                start++;
                memset(count,0,sizeof(count));
            }
            else
            {
                flag = 1;
                cout << start << " " << start / a * b << " " << start / a * c << endl;
                start++;
                memset(count,0,sizeof(count));
            }
        }

    }

    if(flag == 0) cout << "No!!!" << endl;

    return 0;

}