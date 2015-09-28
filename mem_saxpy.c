#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<stdint.h>
#include <malloc.h>


double wclk_secs_dif(struct timeval end,struct timeval start)
{
    unsigned long isec = (unsigned long)end.tv_sec - (unsigned long)start.tv_sec;
    int usec = end.tv_usec - start.tv_usec;
    if (usec < 0){
        usec += 1000000;
        isec--;
    }
    return (double)isec + (double)usec * .000001;
}


void dummy(float *a, float *b, float *c, float *d)
{
}

int main()
{

        struct timeval t1, t2;
        double elapsedTime;

        long long N2=10000;
        long k=0;
	long MAX_SIZE=393216;
	
        //init array

        long long m;
        for(m=N2;m>=1000;m=m/10)
        {


                for(long vec=10;vec<1000000000;vec=vec*10)
                {

                	long N1 = vec;

	                float *a=(float*)memalign(32,sizeof(float)*N1);
	                float *b=(float*)memalign(32,sizeof(float)*N1);
	                float *c=(float*)memalign(32,sizeof(float)*N1);
	                float *d=(float*)memalign(32,sizeof(float)*N1);

	                while(k<N1)
	                {
	                        a[k]=1.0;
	                        b[k]=2.0;
	                        c[k]=3.0;
	                        d[k]=4.0;
	                        k++;
	                }

	                gettimeofday(&t1, NULL);
	                int j=0;
	                for(k=0;k<m;k=k+1)
	                {

	                        for(j=0;j<N1;j++)
	                        {
	                                a[j]=b[j]+c[j]*d[j];
	                                j++;
				}


	                        if(a[2]== -123)
	                        {
	                                dummy(a,b,c,d);
	                        }

	                }

	                gettimeofday(&t2, NULL);
	                elapsedTime = wclk_secs_dif(t2,t1);


			free(a);
			free(b);
			free(c);
			free(d);
	                long long flop = 2*N1*m;
	                double flops = (double)flop/elapsedTime;
	                double gflops = flops/1000000000;

                	printf("%ld %ld %f gflops %f\n",N1,(N1*sizeof(double)*4)/1024,gflops,elapsedTime);
            	}
        }

return 0;
}

