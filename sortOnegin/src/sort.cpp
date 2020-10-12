// #include "utils.cpp"

Line *bubbleSort(int n, Line arr[], int (*comparisonFcn)(const Line, const Line))
{
        for (int i = 0; i < n - 1; i++)
        {
                for (int j = 0; j < n - i - 1; j++)
                {
                        Line temp;
                        if (comparisonFcn(arr[j + 1], arr[j]))
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
        return arr;
}