#include<stdio.h>
#include<conio.h>
void main()
{
    int num_col, num_row, mach, job;
    int freq[10];
    int j, count;
   static int eliminate_col=-1;
    float opt_mach[10][10];
    printf("ENTER THE NUMBER OF MACHINES AND JOBS RESPECTIVELY");
    scanf("\n%d%d",&num_row,&num_col);
    printf("\nENTER THE NUMBER OF HOURS FOR EACH JOB AT EACH MACHINE");
    for(mach=0; mach<num_row; mach++)
    {
        for(job=0; job<num_col; job++)
        {
            scanf("\n%f",&opt_mach[mach][job]);
        }
    }
    printf("\nSUBSTRACTING ROW MINIMUM FROM EACH ELEMENT OF EACH ROW");
    for(mach=0; mach<num_row; mach++)
    {
        float smallest=opt_mach[mach][0];
        for(job=0; job<num_col; job++)
        {
            if(opt_mach[mach][job]<smallest)
            {
                smallest=opt_mach[mach][job];
            }
        }
        for(job=0; job<num_col; job++)
        {
            opt_mach[mach][job]=opt_mach[mach][job]-smallest;
        }
    }
    printf("\nTHE NEW MATRIX IS");
    for(mach=0; mach<num_row; mach++)
    {
        for(job=0; job<num_col; job++)
        {
            printf("\n%f",opt_mach[mach][job]);
        }
    }
    printf("\nSUBSTRACTING COLUMN MINIMUM FROM EACH ELEMENT OF EACH COLUMN");
    for(job=0; job<num_col; job++)
    {
        float smallest=opt_mach[0][job];
        for(mach=0; mach<num_row; mach++)
        {
            if(opt_mach[mach][job]<smallest)
            {
                smallest=opt_mach[mach][job];
            }
        }
        for(mach=0; mach<num_row; mach++)
        {
            opt_mach[mach][job]=opt_mach[mach][job]-smallest;
        }
    }
    printf("\nTHE NEW MATRIX IS");
    for(mach=0; mach<num_row; mach++)
    {
        for(job=0; job<num_col; job++)
        {
            printf("\n%f",opt_mach[mach][job]);
        }
    }
//FINAL ALLOCATION
    for(mach=0; mach<num_row; mach++)
    {
        for(job=0; job<num_col; job++)
        {
            /* Initially initialize frequencies to -1 */
            freq[job] = -1;
        }
        for(job=0; job<num_col; job++)
        {
            count = 1;
            for(j=job+1; j<num_col; j++)
            {
                /* If duplicate element is found */
                if(opt_mach[mach][job]==opt_mach[mach][j])
                {
                    count++;

                    /* Make sure not to count frequency of same element again */
                    freq[j] = 0;
                }
            }
            if(freq[job] != 0)
            {
                freq[job] = count;
            }
        }
        /* If frequency of current element is not counted */
        /*
         * Print frequency of each element
         */
        for(job=0; job<num_col; job++)
        {
            if(freq[job] != 0)
            {
                printf("%f occurs %d times\n", opt_mach[mach][job], freq[job]);
            }
        }
        for(job=0; job<num_col; job++)
        {
            if(opt_mach[mach][job]==0&&freq[job]==1)
            {
                opt_mach[mach][job]=eliminate_col;
                printf("\nTHE JOB %d WILL BE ALLOTED TO THE MACHINE %d",job,mach);
            }
        }
    }
    for(job=0; job<num_col; job++)
    {
        for(mach=0; mach<num_row; mach++)
        {
            /* Initially initialize frequencies to -1 */
            freq[mach] = -1;
        }
        for(mach=0; mach<num_row; mach++)
        {
            count = 1;
            for(j=mach+1; j<num_row; j++)
            {
                /* If duplicate element is found */
                if(opt_mach[mach][job]==opt_mach[j][mach])
                {
                    count++;

                    /* Make sure not to count frequency of same element again */
                    freq[j] = 0;
                }
            }
        }
        /* If frequency of current element is not counted */
        if(freq[mach] != 0)
        {
            freq[mach] = count;
        }
        /*
         * Print frequency of each element
         */
        printf("\nFrequency of all elements of array : \n");
        for(mach=0; mach<num_row; mach++)
        {
            if(freq[mach] != 0)
            {
                printf("\n%f occurs %d times\n", opt_mach[mach][job], freq[mach]);
            }
        }
        for(mach=0; mach<num_row; mach++)
        {
            if(opt_mach[mach][job]==eliminate_col)
            {
                continue;
            }
            if(opt_mach[mach][job]==0&&freq[mach]==1)
            {
                printf("\nTHE JOB %d WILL BE ALLOTED TO THE MACHINE %d",job,mach);
            }
        }
    }
    return 0;
}
