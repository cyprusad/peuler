#include<stdio.h>
#include<stdlib.h>
int grid[20][20];


void readInput(FILE *in){
	int i, j;
	for (i=0; i< 20; i++){
		for (j=0; j<20; j++){
			fscanf(in, "%d", &(grid[i][j]));
			printf("%2d ", grid[i][j]);
		}
		printf("\n");
	}
}

long int horizontals(){
	long int max = 0;
	long int hprod = 1;
	int i, j;
	for (i=0; i< 20; i++){
		for (j=0; j< 16; j++){
			hprod = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
			if (max < hprod) {
				max = hprod;
			}
		}
	}
}

long int verticals(){
	long int max = 0;
	long int vprod = 1;
	int i, j;
	for (i=0; i< 16; i++){
		for (j=0; j< 20; j++){
			vprod = grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
			if (max < vprod) {
				max = vprod;
			}
		}
	}
}

long int leftdiag(){
	long int max = 0;
	long int ldprod = 1;
	int i, j;
	for (i=0; i< 16; i++){
		for (j=3; j< 20; j++){
			ldprod = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
			if (max < ldprod) {
				max = ldprod;
			}
		}
	}
}

long int rightdiag(){
	long int max = 0;
	long int rdprod = 1;
	int i, j;
	for (i=0; i< 16; i++){
		for (j=0; j< 16; j++){
			rdprod = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
			if (max < rdprod) {
				max = rdprod;
			}
		}
	}
}



int main (int argc, char** argv){
	readInput(stdin);
	printf ("\n\n --> Horizontal max is %ld\n", horizontals());
	printf ("\n\n --> Vertical max is %ld\n", verticals());
	printf ("\n\n --> Left Diag max is %ld\n", leftdiag());
	printf ("\n\n --> Right Diag max is %ld\n", rightdiag());


}
