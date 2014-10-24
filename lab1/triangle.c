/*
*	C program that asks for X and Y coordinates for 3 points of a triangle,
*	then calculates & prints the lengths of the 3 sides, the circumference of
*	the triangle, and the area of the triangle.
*	By Alex Shoop
*	For CS2303 lab 1 (9/4/13)
*/

#include <stdio.h>
#include <math.h>

int main() 
{
	double xA, yA, xB, yB, xC, yC;
	
	printf("Enter the x- and y-coordinates of point A: ");
	scanf("%lf%lf", &xA, &yA);
	printf("Enter the x- and y-coordinates of point B: ");
	scanf("%lf%lf", &xB, &yB);
	printf("Enter the x- and y-coordinates of point C: ");
	scanf("%lf%lf", &xC, &yC);
	
	double ABl = sqrt(((xA-xB)*(xA-xB))+((yA-yB)*(yA-yB)));
	double BCl = sqrt(((xB-xC)*(xB-xC))+((yB-yC)*(yB-yC)));
	double CAl = sqrt(((xC-xA)*(xC-xA))+((yC-yA)*(yC-yA)));
	
	double circum = ABl + BCl + CAl;
	
	double s = 0.5 * circum;	// Originally used (1/2), but it was wrong. So I used 0.5
	
	double area = sqrt(s * (s - ABl) * (s - BCl) * (s - CAl));
	
	printf("\nLength of AB is %lf\n", ABl);
	printf("Length of BC is %lf\n", BCl);
	printf("Length of CA is %lf\n", CAl);
	printf("Circumference is %lf\n\n", circum);
	printf("Area is %lf\n", area);
	
	return 0;
}	// int main
