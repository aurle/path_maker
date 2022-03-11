/* Convert a dxf file with a path created with librecad into a path */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
    char line[50];
    FILE *dxf_fp = fopen(argv[1],"r");
    int start_x(0), start_y(0), target_x(0), target_y(0);//, heading(0);
	float heading(0.0);
    float last_heading(0.0);
    float rotate(0.0); //- robot rotates left, + robot rotates right

    int first=1;
    while(fgets(line, sizeof line, dxf_fp))
    {
        if (strcmp(line, "AcDbLine\n")==0)
        {
            fgets(line,sizeof line, dxf_fp); //Read the 10 after
            fgets(line,sizeof line, dxf_fp); //Read the x start point
            sscanf(line, "%d", &start_x);

            fgets(line,sizeof line, dxf_fp); //Read the 20 after
            fgets(line,sizeof line, dxf_fp); //Read the y start point
            sscanf(line, "%d", &start_y);

            fgets(line,sizeof line, dxf_fp); //Read the 11 after
            fgets(line,sizeof line, dxf_fp); //Read the x target point
            sscanf(line, "%d", &target_x);

            fgets(line,sizeof line, dxf_fp); //Read the 21 after
            fgets(line,sizeof line, dxf_fp); //Read the y target point
            sscanf(line, "%d", &target_y);

            float length = sqrt(  pow( target_x - start_x, 2) 
                                + pow( target_y - start_y, 2) );

            heading = (atan2((target_y-start_y),(target_x-start_x)) * 180 / M_PI);

            // The heading from the above calculation is +/- 180 degrees
            // Normalize heading to a number between 0 - 360 with 0 being right, rotating counter clockwise
            if (heading < 0)
            {
                heading += 360.00;
            }

            if (first)
            {
                first=0;
                last_heading = heading;
            }
            else {
                rotate = last_heading - heading;
                //Rotation should never be > +/- 180 degrees. If it is, rotate in the other direction, because
                //it will be a shorter distance, aka a faster move. For exampe 185 degrees right == 95 degrees left
                if (rotate > 180)
                {
                    rotate -= 360;
                }
                else if (rotate < -180)
                {
                    rotate +=360;
                }
                printf("rotate %f \n\n", rotate);
            }

            printf("drive straight %f: \n", length);
            last_heading = heading;
        }
    }
    return 0;
}




