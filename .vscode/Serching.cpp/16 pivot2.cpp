#include <iostream>
#include <vector>
using namespace std;
int findPivot(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            //    single element
            // vector<int> arr{2,4,6,8,9,10};
            // vector<int> arr{2};
            return s;
        }

        if (mid <= e && arr[mid] > arr[mid + 1])

            return mid;

        if (mid - 1 >= s && arr[mid - 1] > arr[mid])

            return mid - 1;

        if (mid - 1 >= s && arr[mid - 1] > arr[mid])

            return mid - 1;
        if (arr[s] > arr[mid])

            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    // vector<int> arr{2,4,6,8,9,10};
    // vector<int> arr{2};
    vector<int> arr{
        9,
        10,
        2,
        4,
        6,
        8,
    };
    int ans = findPivot(arr);

    if (ans == -1)
    {
        cout << "somthing went to wroung" << endl;
    }
    else
    {
        cout << "Ans is at index" << ans << endl;
        cout << "value of ans is" << arr[ans] << endl;
    }

    return 0;
}