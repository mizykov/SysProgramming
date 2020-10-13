std::vector<Line> quick_sort(int n, std::vector<Line> arr, int (*comparisonFcn)(const Line, const Line), int first, int last)
{
        if (first != last)
        {
                size_t left = first;
                size_t right = last;
                size_t pivot = left++;
                Line temp;

                while (left != right)
                {
                        if (comparisonFcn(arr[left], arr[pivot]))
                        {
                                ++left;
                        }
                        else
                        {
                                while ((left != --right) && comparisonFcn(arr[pivot], arr[right]))
                                        ;
                                temp = arr[left];
                                arr[left] = arr[right];
                                arr[right] = temp;
                        }
                }
                --left;
                temp = arr[left];
                arr[left] = arr[first];
                arr[first] = temp;
                arr = quick_sort(n, arr, comparisonFcn, first, left);
                arr = quick_sort(n, arr, comparisonFcn, right, last);
        }
        return arr;
}
