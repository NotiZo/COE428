void mySort(int d[], unsigned int n)
{
	int i, j;
	int swapped;
	int x;

	for (i = 0; i<n-1; i++){
		swapped=0;
		for (j=0; j<n-i-1; j++){
  			if(d[j]>d[j+1]){
   				x=d[j];
				d[j]=d[j+1];
				d[j+1]=x;
				swapped=1;}
		}
		if (swapped==1)
		break;
 	}
}
