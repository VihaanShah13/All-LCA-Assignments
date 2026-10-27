#include <stdio.h>
int main() {
	int r, c, i, j;
	printf("Enter rows and columns : ");
	scanf("%d %d", &r, &c);
	int sensor1[r][c],sensor2[r][c],result[r][c];
	
	printf("Enter elements for sensor1:\n");
	for  (i = 0;i < r; i++)
	{
		for  (j = 0; j < c; j++)
		{
			scanf("%d", &sensor1[i][j]);
		}}	
	printf("Enter elements for sensor2:\n");
	for  (i = 0;i < r; i++)
	{
		for  (j = 0; j < c; j++)
		{
			scanf("%d", &sensor2[i][j]);
		}}
	printf("Subtraction of two \n");
	for  (i = 0;i < r; i++)
	{
		for  (j = 0; j < c; j++)
		{
			result[i][j] = sensor1[i][j] - sensor2[i][j];
		}}
		
	printf("\nResult:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
		{
			printf("%d",result[i][j]);
			printf("\n");
		}}

return 0;
}
