// function to sort the array in ascending order
float sort_and_find_median(float *measurements , int size)
{ 

    int i=0 , j=0;
    float temp=0;

    for(i=0 ; i<size ; i++)
    {
        for(j=0 ; j<size-1 ; j++)
        {
            if(measurements[j]>measurements[j+1])
            {
                temp        = measurements[j];
                measurements[j]    = measurements[j+1];
                measurements[j+1]  = temp;
            }
        }
    }
	
	return measurements[size/2];
}

float *discard_outliers(float *measurements, int size, float median, int *new_size)
{
    //int *outliers = malloc(size * sizeof(int));
	// write the body of the function
    int i=0 , j=0;
    float max=1.5*median, min=0.5*median;
    int number_of_outliers=0;
    for(i=0 ; i<size ; i++)
    {
        if(measurements[i]>=max || measurements[i]<=min)
        {
            number_of_outliers++;
        }
    }

    *new_size = size - number_of_outliers;

    float *measurements_wo_outliers = malloc((*new_size) * sizeof(float));
    // Add non outlier elements to array
    
    for(i=0 ; i<size ; i++)
    {
        if(measurements[i]<max && measurements[i]>min)
        {
            measurements_wo_outliers[j++] = measurements[i];
        }
    }
    return measurements_wo_outliers;
}