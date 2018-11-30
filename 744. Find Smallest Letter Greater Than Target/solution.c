char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int l = 0, r = lettersSize - 1, m;
    if (target < letters[l] || letters[r] <= target) return letters[l];
    while (l < r)
    {
        m = l + (r - l) / 2;
        if (letters[m] > target) r = m;
        else l = m + 1;
    }
    return letters[r];
}