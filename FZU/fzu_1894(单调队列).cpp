#include<stdio.h>
#include<string.h>
#define MAXN 1100000
struct node
{
    int key, tag;
    node (int k = 0, int t = 0): key(k), tag(t) {}
}q[MAXN];
int main()
{
    int i, j, front, last, T, k;
    char ch, str[1000];
    node temp;
    scanf("%d", &T);
    while(T--)
    {
        front = last = i = j = 0;
        scanf("%s", str);
        while(scanf("%s", str) && strcmp(str, "END"))
        {
            if(str[0] == 'C')
            {
                scanf("%s%d", str, &k);
                while(front != last && q[last-1].key <= k) last--;
                q[last++] = node(k, i++);
            }
            else if(str[0] == 'G')
            {
                while(front != last && q[front].tag <= j) front++;
                j++;
            }
            else if(str[0] == 'Q')
            {
                printf("%d\n", front == last ? -1 : q[front].key);
            }
        }
    }
    return 0;
}
