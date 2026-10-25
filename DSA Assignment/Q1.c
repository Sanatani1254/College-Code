#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{   
    char *msg;
    struct node *next;
    struct node *prev;
    struct node *ptrp;
};

struct user
{
    int id;
    struct node *messagehead;
    bool ban;
};

struct chat
{
    struct user *v;
    int n;//views
    struct node *head,*tail;//tail to put new message
};

int compuser(const void *id,const void *b)
{
    struct user *x = (struct user *)id;
    struct user *y = (struct user *)b;
    if (x->id < y->id) return -1;
    if (x->id > y->id) return 1;
    return 0;
}

struct chat *build(int *id,int n)
{
    struct chat *c = malloc(sizeof(struct chat));
    c->v = malloc(sizeof(struct user) * n);
    c->n = n;
    c->head = NULL;
    c->tail = NULL;

    for(int i = 0;i<n;i++)
    {
        c->v[i].id = id[i];
        c->v[i].messagehead = NULL;
        c->v[i].ban = false;
    }
    
    qsort(c->v,n,sizeof(struct user),compuser);//sort to search binary
    return c;
}

struct user *find(struct chat *c, int id) 
{//O(logn)
    int lo = 0, hi = c->n - 1;
    while (lo <= hi) 
    {
        int mid = lo + (hi - lo) / 2;
        if (c->v[mid].id == id) return &c->v[mid];
        if (c->v[mid].id < id) lo = mid + 1;
        else hi = mid - 1;
    }
    return NULL;
}

bool send(struct chat *c, int id, const char *m)
{
    struct user *u = find(c,id);
    if (u == NULL || u->ban) return false;
 
    struct node *x = malloc(sizeof(struct node));
    x->msg = strdup(m);
    x->next = NULL;
 
    x->prev = c->tail;
    if (c->tail != NULL) c->tail->next = x;
    else c->head = x;
    c->tail = x;
    x->ptrp = u->messagehead;
    u->messagehead = x;
    return true;
}

void recent(struct chat *c, int k)
{
    struct node *cur = c->tail;
    int count = 0;
    while (cur != NULL&&count < k)
    {
        printf("%s\n", cur->msg);
        cur = cur->prev;
        count++;
    }
}

void ban(struct chat *c, int id)
{
    struct user *u = find(c,id);
    if (u == NULL || u->ban) return;
    u->ban = true;
 
    struct node *x = u->messagehead;
    while (x != NULL)
    {
        // remove x from global list
        if (x->prev != NULL) x->prev->next = x->next;
        else c->head = x->next;
 
        if (x->next != NULL) x->next->prev = x->prev;
        else c->tail = x->prev;
 
        struct node *nxt = x->ptrp;
        free(x->msg);
        free(x);
        x = nxt;
    }
    u->messagehead = NULL;
}

void destroy(struct chat *c)
{
    struct node *x = c->head;
    while (x != NULL)
    {
        struct node *nx = x->next;
        free(x->msg);
        free(x);
        x = nx;
    }
    free(c->v);
    free(c);
}

int main()
{
    int id[] = {5,3,9,1};
    struct chat *room = build(id,4);
 
    send(room,3,"Hello");
    send(room,5,"My name is Suryansh");
    send(room,3,"I am doing btech at NIT Jalandhar");
    send(room,9,"how do you do?");
 
    printf("Recent 10 messages:\n");
    recent(room,10);
    
    printf("BANNING User 3");
    int x = 3;
    ban(room,x);
    printf("\nafter ban(3):\n");
    recent(room, 10);
 
    if (!send(room,x,"x"))
    {
        printf("\nuser %d is banned,cannot chat\n",x);
    }
    printf("\nrecent(2):\n");
    recent(room,2);
    destroy(room);
}