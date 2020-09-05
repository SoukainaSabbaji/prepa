element* tri_bulle(element*l)
{
	int i,cmp,k;
	element* p,*s;
	if(l==NULL)
	{
		return l;
	}
	do
	{
		cmp=0;
		p=l;
		s=l->suivant;
		while(s!=NULL)
		{
			if( p->val > s->val)
			{
				k=p->val;
				p->val=s->val;
				s->val=k;
				cmp++;
			}
			p=p->suivant;
			s=s->suivant;
		}
	}
	while(cmp>0);
	return l;
}

element* tri_selection(element*l)
{
	element*p,*ps,*finliste;
	int v,max,n;
	n=tailleliste(l);
	while(n>0)
	{
		finliste=recherch_po(l,n);
		max=l->val;
		p=l;ps=l;
		while(p!=finliste)
		{
			if(p->val>max)
			{
				max=p->val;
				ps=p;
			}
			p=p->suivant;
		}
		while(ps!=finliste)
		{
			ps->val=ps->suivant->val;
			ps=ps->suivant;}
		ps->val=max;
		n--;
	}
	return l;
}

