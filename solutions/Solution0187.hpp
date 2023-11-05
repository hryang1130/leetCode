struct my_struct {
    char str[11];
    int value;
    UT_hash_handle hh;
};
struct my_struct *elems =NULL;

void add_elem(char *str, int value)
{
    struct my_struct *s;
    s = malloc(sizeof(*s));
    strcpy(s->str,str);
    s->value = value;
    HASH_ADD_STR(elems,str,s);
}

struct my_struct *find_elem(char *str){
    struct my_struct *s;
    HASH_FIND_STR(elems,str,s);
    if (s==NULL){
        printf("null.\n");
    }
    return s;
}

char** findRepeatedDnaSequences(char* s, int* returnSize) {
    HASH_CLEAR(hh,elems);
    int n = strlen(s);
    int idxs[n];
    int cnt =0;
    for (int i=0;i<=n-10;i++){
        struct my_struct* el;
        char st[11];
        strncpy(st,s+i,10);
        st[10]='\0';
        el = find_elem(st);
        if (el==NULL){
            add_elem(st,1);
        } else {
            if(el->value==1){
                idxs[cnt]=i;
                cnt++;
                add_elem(st,2);
            }
        }
    }
    char **res = (char **) malloc(sizeof(char*)*cnt);
    for (int i=0;i<cnt;i++){
        res[i]=(char *) malloc(sizeof(char)*11);
        strncpy(res[i],s+idxs[i],10);
        res[i][10]='\0';
    }
    *returnSize=cnt;
    return res;
}
