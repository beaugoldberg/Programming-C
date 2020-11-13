#include <stdio.h>

int main(void) {
	int numRead;
	int num1count = 0;
	int num2count = 0;
	int num3count = 0;
	int num4count = 0;
	int num5count = 0;
	int num6count = 0;
	int num7count = 0;
	int num8count = 0;
	int num9count = 0;
	int totalValues = 0;
	FILE* inFile = NULL;
	char yes1, yes2, yes3, yes4, yes5, yes6, yes7, yes8, yes9;
	double avg1, avg2, avg3, avg4, avg5, avg6, avg7, avg8, avg9;
	int hist1, hist2, hist3, hist4, hist5, hist6, hist7, hist8, hist9;
	
	inFile = fopen("example2.txt", "r");
	if (inFile == NULL) {
                printf("Could not open file\n");
		return -1;
	}

	while (!feof(inFile)) {
		char inputValue[100] = " ";
        	numRead = fscanf(inFile, "%s", inputValue);
        	if ( numRead == 1 ) {
			totalValues += 1;
        		if (inputValue[0] == '1') { num1count += 1; }
			else if (inputValue[0] == '2') { num2count += 1; }
			else if (inputValue[0] == '3') { num3count += 1; }
			else if (inputValue[0] == '4') { num4count += 1; }
			else if (inputValue[0] == '5') { num5count += 1; }
			else if (inputValue[0] == '6') { num6count += 1; }
			else if (inputValue[0] == '7') { num7count += 1; }
			else if (inputValue[0] == '8') { num8count += 1; }
			else if (inputValue[0] == '9') { num9count += 1; }
      		}
   	}

	if (num1count != 0) { avg1 = (num1count / (totalValues / 1.0)) * 100; }
	if (num1count != 0) { hist1 = (int)avg1 / 1; }
	if (num2count != 0) { avg2 = (num2count / (totalValues / 1.0)) * 100; }
	if (num2count != 0) { hist2 = (int)avg2 / 1; }
	if (num3count != 0) { avg3 = (num3count / (totalValues / 1.0)) * 100; }
	if (num2count != 0) { hist3 = (int)avg3 / 1; }
	if (num4count != 0) { avg4 = (num4count / (totalValues / 1.0)) * 100; }
	if (num4count != 0) { hist4 = (int)avg4 / 1; }
	if (num5count != 0) { avg5 = (num5count / (totalValues / 1.0)) * 100; }
	if (num5count != 0) { hist5 = (int)avg5 / 1; }
	if (num6count != 0) { avg6 = (num6count / (totalValues / 1.0)) * 100; }
	if (num6count != 0) { hist6 = (int)avg6 / 1; }
	if (num7count != 0) { avg7 = (num7count / (totalValues / 1.0)) * 100; }
	if (num7count != 0) { hist7 = (int)avg7 / 1; }
	if (num8count != 0) { avg8 = (num8count / (totalValues / 1.0)) * 100; }
	if (num8count != 0) { hist8 = (int)avg8 / 1; }
	if (num9count != 0) { avg9 = (num9count / (totalValues / 1.0)) * 100; }
	if (num9count != 0) { hist9 = (int)avg9 / 1; }

	printf("Number of Inputs: %d\n", totalValues);
	printf("Counts: %d,%d,%d,%d,%d,%d,%d,%d,%d\n",num1count,num2count,num3count,num4count,num5count,num6count,num7count,num8count,num9count);
	printf("%-6.2lf% 1:", avg1);
	for (int i = 0; i < hist1; i++) { printf("*"); }
	printf("\n%-6.2lf% 2:", avg2);
	for (int i = 0; i < hist2; i++) { printf("*"); }
	printf("\n%-6.2lf% 3:", avg3);
	for (int i = 0; i < hist3; i++) { printf("*"); }
	printf("\n%-6.2lf% 4:", avg4);
	for (int i = 0; i < hist4; i++) { printf("*"); }
	printf("\n%-6.2lf% 5:", avg5);
	for (int i = 0; i < hist5; i++) { printf("*"); }
	printf("\n%-6.2lf% 6:", avg6);
	for (int i = 0; i < hist6; i++) { printf("*"); }
	printf("\n%-6.2lf% 7:", avg7);
	for (int i = 0; i < hist7; i++) { printf("*"); }
	printf("\n%-6.2lf% 8:", avg8);
	for (int i = 0; i < hist8; i++) { printf("*"); }
	printf("\n%-6.2lf% 9:", avg9);
	for (int i = 0; i < hist9; i++) { printf("*"); }
	printf("\n");

	if (avg1 >= 28.0 && avg1 <= 38.0) { yes1 = 'y'; }
	if (avg2 >= 15.0 && avg2 <= 21.0) { yes2 = 'y'; }
	if (avg3 >= 10.0 && avg3 <= 13.0) { yes3 = 'y'; }
	if (avg4 <= avg3) { yes4 = 'y'; }
	if (avg5 <= avg4) { yes5 = 'y'; }
	if (avg6 <= avg5) { yes6 = 'y'; }
	if (avg7 <= avg6) { yes7 = 'y'; }
	if (avg8 <= avg7) { yes8 = 'y'; }
	if (avg9 <= avg8) { yes9 = 'y'; }

	if (yes1 == 'y' && yes2 == 'y' && yes3 == 'y' && yes4 == 'y' && yes5 == 'y' && yes6 == 'y' && yes7 == 'y' && yes8 == 'y' && yes9 == 'y') {
		printf("Benford's Law? Yes\n");
	}
	else { printf("Benfords's Law? No\n"); }

	return 0;
}
