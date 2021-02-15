
// swaps two integer's
static void swap(int *a, int *b) ;

void BSort(int *r, int len)
{
	for( int i = 0 ; i < len ; i++ )
		for( int j = 0 ; j < len-1 ; j++ )
			if( r[j] > r[j+1] )
				swap(r+j, r+j+1) ;
}

static void swap(int *a, int *b)
{
	int i = *a; 
	*a = *b ;
	*b = i ;
}

void SSort(int *r, int len)
{
	for( int i = 0 ; i < len ; i++ )
	{
		int g = i ;
		for( int j = 0 ; j < len ; j++ )
		{
			if( r[g] < r[j] )
				g = j ;
		}
		swap(r+g, r+i) ;
	}
}

static void merge(int *x, int lx, int *y, int ly, int *r);
void MSort(int *r, int len)
{
	if( len  == 1  ) return ;

	int lenx = len/2 ;
	int leny = len/2+len%2 ;

	MSort(r, lenx) ; 
	MSort(r+lenx, leny) ;

	merge(r, lenx, r+lenx, leny, r) ;
}

static void merge(int *x, int lx, int *y, int ly, int *r)
{
	int m[lx+ly] ;
	int im = 0 ;
	int ix = 0 ; 
	int iy = 0 ;

	while(ix < lx && iy < ly)
	{		
		if( x[ix] < y[iy] )
			m[im] = x[ix++] ;
		else
			m[im] = y[iy++] ;
		im++ ;
	}

	while(ix < lx)
	{
		m[im] = x[ix++] ;
		im++ ;
	}

	while(iy < ly)
	{
		m[im] = y[iy++] ;
		im++ ;
	}

	for( int i = 0 ; i < lx+ly ; i++ )
		r[i] = m[i] ;
}

static int partition(int *a, int l, int h);
void QSort(int *a, int l, int h)
{
	if( l >= h ) return ;

	int p = partition(a, l, h) ;

	QSort(a, l, p) ;
	QSort(a, p+1, h) ;
}
/*
// selecting the end as the pivot
static int partition(int *a, int l, int h)
{
	int pivot = a[h] ;

	int i = l ; 
	int j = l ;
	for(; j < h ; j++ )
	{
		if( a[j] > pivot )
		{
			swap(a+j, a+i) ;
			i++ ;
		}
	}
	swap(a+j, a+i) ;
	return i ;
}*/

// selecting pivot to be center
static int partition(int *a, int l, int h)
{
	int pivot = a[(l+h)/2] ;
	
	int i = l ; 
	int j = h ;
	while(1)
	{
		while(a[i] < pivot)i++;
		while(a[j] > pivot)j--;
		
		if( j <= i ) return i;
		swap(a+i, a+j) ;
	}
	return i ;
}
