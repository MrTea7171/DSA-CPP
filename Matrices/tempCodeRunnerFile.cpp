{
    Sparse *sum=new Sparse(rows,columns,elements+s.elements);
    int i,j,k;
    i=j=k=0;

    sum->E=new Element[sum->elements];
    while(i<elements && j<s.elements)
    {
        if(E[i].row_no<s.E[j].row_no)
        {
            sum->E[k++]=E[i++];
        }
        else if(E[i].row_no>s.E[j].row_no)
        {
            sum->E[k++]=s.E[j++];
        }
        else if(E[i].column_no<s.E[j].column_no)
        {
            sum->E[k++]=E[i++];
        }
        else if(E[i].column_no>s.E[j].column_no)
        {
            sum->E[k++]=s.E[j++];
        }
        else
        {
            sum->E[k]=E[i];
            sum->E[k++].data=E[i++].data+s.E[j++].data;
        }
    }
    while(i<elements)
    {
        sum->E[k++]=E[i++];
    }
    while(j<s.elements)
    {
        sum->E[k++]=s.E[j++];
    }

    return *sum;
}
