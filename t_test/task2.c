#include "task1.c"
#include<math.h>

// Function for computing mean and variance
// The mean is stored in *mean and the variance is stored in *variance 
void mean_variance(float *measurements, int size, float *mean, float *variance)
{
	int i;
	float sum=0;

    //  Compute  mean	
    for (i = 0; i < size; i++)
    {
        sum = sum + measurements[i];
    }
    *mean = sum /size;

    //  Compute  variance
	sum = 0;	
    for (i = 0; i < size; i++)
    {
        sum = sum + (measurements[i]-*mean)*(measurements[i]-*mean);
    }
    *variance = sum /(size-1);
}

// Function for computing the t-static
// For computing square-root of a float data 'a' use b = sqrt(a) where type of b is also float.
float t_test(float *measurements1, int size1, float *measurements2, int size2)
{
	float t=0;
    int newsize1, newsize2;
    float median1=sort_and_find_median(measurements1, size1);
    float median2=sort_and_find_median(measurements2, size2);
    float *measurements1_wo_outliers=discard_outliers(measurements1, size1, median1, &newsize1);
    float *measurements2_wo_outliers=discard_outliers(measurements2, size2, median2, &newsize2);

    float mean1, mean2;
    float variance1, variance2;

    mean_variance(measurements1_wo_outliers, newsize1, &mean1, &variance1);
    mean_variance(measurements2_wo_outliers, newsize2, &mean2, &variance2);
    
    free(measurements1_wo_outliers);
    free(measurements2_wo_outliers);
    
    t = (mean1-mean2) / sqrt((variance1/(float)newsize1) + (variance2/(float)newsize2));
	return t;
}

