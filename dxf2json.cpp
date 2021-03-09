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
    printf("{ \"path\": [");

    int first=1;
    while(fgets(line, sizeof line, dxf_fp))
    {
        if (strcmp(line, "AcDbLine\n")==0)
        {
            if (first)
            {
                first=0;
            }
            else
            {
                printf(",");
            }
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

            start_x *= -1;
            target_x *= -1;

            heading = (atan2((target_x-start_x),(target_y-start_y)) * 180 / M_PI);

            if (heading < 0)
            {
                heading += 360.00;
            }

            printf("\n  {\n    \"x\":\"%d\",\n    \"y\":\"%d\",\n    \"heading\":\"%.2f\",\n  }", start_x, start_y, heading);
        }
    }
    printf("\n]}\n");
    return 0;
}




