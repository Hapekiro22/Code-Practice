void  adjust(DuLinkList  L)
{
/**********Begin**********/
    Dnode *start = L -> next;
    Dnode *p = L -> next;

    if(start -> next == L) return;

    while(p -> next != L && p -> next -> next != L)
    {
        p -> next = p -> next -> next;
        //printf("Now link is %d\n",p -> next -> data);
        p = p -> next;
    }
    
    Dnode *half_start = NULL;
    Dnode *half_end = p;
    if(p -> next -> next == L) p = p -> next;
    else p = p -> prior;
    half_start = p;
    //printf("End is %d\n", half_start -> data);
    while(p -> prior != L && p -> prior -> prior != L)
    {
        p -> next = p -> prior -> prior;
        //printf("Now link is %d\n",p -> next -> data);
        p = p -> next;
    }

    half_end -> next = half_start;
    p -> next = L;

    return;
 /**********End**********/
}
