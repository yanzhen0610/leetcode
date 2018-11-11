int lengthOfLastWord(char* s) {
    char* e = s + strlen(s) - 1;
    while (s <= e && isspace(*e)) --e;
    *(e + 1)=0;
    while (s <= e && !isspace(*e)) --e;
    return strlen(e + 1);
}