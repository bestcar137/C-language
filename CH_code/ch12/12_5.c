void inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap) {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

void shell_sort(int list[], int n) {
    int gap, i;
    for (gap = n / 2; gap > 0; gap = gap / 2)
        for (i = 0; i < gap; i++)
            inc_insertion_sort(list, i, n - 1, gap);
}
