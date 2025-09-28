#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//struct untuk menyimpan data-data dari file
struct Data{
	char location[100];
	char city[100];
	char price[20];
	char room[20];
	char bathroom[20];
	char carpark[20];
	char type[100];
	char furnish[100];
};

struct Data data[5000];

struct Data sorted[5000];

//function untuk membaca file
int readFile(){
	
	int counter = 0;
	
	FILE *fptr = fopen("file.csv", "r");
	
	while(!feof(fptr)){
		fscanf(fptr, "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%[^\n]\n",
		data[counter].location, data[counter].city, data[counter].price, data[counter].room, data[counter].bathroom, data[counter].carpark, data[counter].type, data[counter].furnish);
		counter++;
	}
	
	fclose(fptr);
	
	return counter;	
}


//mergesort
void merge(int left, int right, int mid, char select[], char type[]){
	int lengthL = mid - left + 1;
	int lengthR = right - mid;
	int idxL = 0, idxR = 0, idxM = left;

	struct Data arrL[lengthL];
	struct Data arrR[lengthR];
	
	for(int i = 0; i < lengthL; i++){
		arrL[i] = data[left + i];
	}
	for(int i = 0; i < lengthR; i++){
		arrR[i] = data[mid + 1 + i];
	}
	
	if(strcmp(type, "ascending") == 0){
		while(idxL < lengthL && idxR < lengthR){
			if(strcmp(select, "Location") == 0){
				if(strcmp(arrL[idxL].location, arrR[idxR].location) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "City") == 0){
				if(strcmp(arrL[idxL].city, arrR[idxR].city) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Price") == 0){
				if(strcmp(arrL[idxL].price, arrR[idxR].price) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Rooms") == 0){
				if(strcmp(arrL[idxL].room, arrR[idxR].room) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Bathroom") == 0){
				if(strcmp(arrL[idxL].bathroom, arrR[idxR].bathroom) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Carpark") == 0){
				if(strcmp(arrL[idxL].carpark, arrR[idxR].carpark) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Type") == 0){
				if(strcmp(arrL[idxL].type, arrR[idxR].type) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Furnish") == 0){
				if(strcmp(arrL[idxL].furnish, arrR[idxR].furnish) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
		}
		while(idxL < lengthL){
			sorted[idxM] = arrL[idxL];
			idxM++; idxL++;
		}
		
		while(idxR < lengthR){
			sorted[idxM] = arrR[idxR];
			idxM++; idxR++;
		}	
	}
	else if(strcmp(type, "descending") == 0){
		while(idxL < lengthL && idxR < lengthR){
			if(strcmp(select, "Location") == 0){
				if(strcmp(arrL[idxL].location, arrR[idxR].location) < 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "City") == 0){
				if(strcmp(arrL[idxL].city, arrR[idxR].city) < 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Price") == 0){
				if(strcmp(arrL[idxL].price, arrR[idxR].price) < 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Rooms") == 0){
				if(strcmp(arrL[idxL].room, arrR[idxR].room) < 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Bathroom") == 0){
				if(strcmp(arrL[idxL].bathroom, arrR[idxR].bathroom) > 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Carpark") == 0){
				if(strcmp(arrL[idxL].carpark, arrR[idxR].carpark) < 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Type") == 0){
				if(strcmp(arrL[idxL].type, arrR[idxR].type) < 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
			else if(strcmp(select, "Furnish") == 0){
				if(strcmp(arrL[idxL].furnish, arrR[idxR].furnish) < 0){
					sorted[idxM] = arrR[idxR];
					idxM++; idxR++;
				}
				else{
					sorted[idxM] = arrL[idxL];
					idxM++; idxL++;
				}
			}
		}
		while(idxL < lengthL){
			sorted[idxM] = arrL[idxL];
			idxM++; idxL++;
		}
		
		while(idxR < lengthR){
			sorted[idxM] = arrR[idxR];
			idxM++; idxR++;
		}	
	}
}

void mergeSort(int left, int right, char select[], char type[]){
	
	int mid = (left + right) / 2;
	
	if(left >= right){
		return;
	}
	
	mergeSort(left, mid, select, type);
	mergeSort(mid + 1, right, select, type);
	merge(left, right, mid, select, type);
}

//function untuk display main menu
int mainMenu(int number){
	
	do{
		printf("What do you want to do?\n");
		printf("1. Display Data\n");
		printf("2. Search Data\n");
		printf("3. Sort Data\n");
		printf("4. Export Data\n");
		printf("5. Exit\n");
		printf("Your choice: ");
		scanf("%d", &number);
		system("cls");
	} while(number < 1 || number > 5);
	
	return number;
}

//function untuk display menu Display Data
void displayDataMenu(int counter){
	
	int numOfRows;
	char space = ' ';
	
	do{
		printf("Number of rows: ");
		scanf("%d", &numOfRows);
		system("cls");	
	} while(numOfRows <= 0);
	
	printf("Location%-20cCity%-12cPrice%-6cRooms%-6cBathroom%-3cCarpark%-4cType%-9cFurnish \n", space, space, space, space, space, space, space);
	
	if(numOfRows <= counter){
		for(int i = 1; i <= numOfRows; i++){
			printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
			data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
		}
	}
	else if(numOfRows > counter){
		for(int i = 1; i <= counter; i++){
			printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
			data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);			
		}
	}
	printf("\n");
	printf("\n");
	printf("Press any keys to continue"); getch();
}

//function untuk display menu Select Row
void selectRowMenu(int counter){
	
	char select[100];
	char dataToFind[500];
	int check = 0;
	
	do{
		printf("Choose column {Location, City, Price, Rooms, Bathroom, Carpark, Type, Furnish}: ");
		scanf("%s", select);
		system("cls");		
	} while(strcmp(select, "Location") != 0 && strcmp(select, "City") != 0 && strcmp(select, "Price") != 0 && strcmp(select, "Rooms") != 0 && 
	strcmp(select, "Bathroom") != 0 && strcmp(select, "Carpark") != 0 && strcmp(select, "Type") != 0 && strcmp(select, "Furnish") != 0); 
	
	printf("What data do you want to find?: ");
	scanf("%s", dataToFind);
	system("cls");
	
	if(strcmp(select, "Location") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].location, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}
	}
	else if(strcmp(select, "City") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].city, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}
	}
	else if(strcmp(select, "Price") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].price, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}		
	}
	else if(strcmp(select, "Rooms") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].room, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}		
	}
	else if(strcmp(select, "Bathroom") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].bathroom, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}		
	}	
	else if(strcmp(select, "Carpark") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].carpark, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}		
	}
	else if(strcmp(select, "Type") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].type, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}		
	}
	else if(strcmp(select, "Furnish") == 0){
		for(int i = 1; i <= counter; i++){
			if(strcmp(data[i].furnish, dataToFind) == 0){
				check = 1;
				printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
				data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
			}
		}
		if(check == 0){
			printf("Data not found!\n");
		}		
	}
	
	printf("\n");
	printf("\n");
	printf("Press any keys to continue"); getch();
}

//function untuk display menu Sort Data
void sortDataMenu(int counter){
	
	char select[100];
	char type[100];
	char space = ' ';

	do{
		printf("Choose column {Location, City, Price, Rooms, Bathroom, Carpark, Type, Furnish}: ");
		scanf("%s", select);
		system("cls");		
	} while(strcmp(select, "Location") != 0 && strcmp(select, "City") != 0 && strcmp(select, "Price") != 0 && strcmp(select, "Rooms") != 0 && 
	strcmp(select, "Bathroom") != 0 && strcmp(select, "Carpark") != 0 && strcmp(select, "Type") != 0 && strcmp(select, "Furnish") != 0); 
	
	do{
		printf("Sort ascending or descending? ");
		scanf("%s", type);
		system("cls");
	}while(strcmp(type, "ascending") != 0 && strcmp(type, "descending") != 0);
	
	mergeSort(1, counter - 1, select, type);
	
	printf("Location%-20cCity%-12cPrice%-6cRooms%-6cBathroom%-3cCarpark%-4cType%-9cFurnish \n", space, space, space, space, space, space, space);
	
	for(int i = 1; i <= 10; i++){
		printf("%-27s %-15s %-10s %-10s %-10s %-10s %-12s %s\n", 
		sorted[i].location, sorted[i].city, sorted[i].price, sorted[i].room, sorted[i].bathroom, sorted[i].carpark, sorted[i].type, sorted[i].furnish);
	}
	
	printf("\n");
	printf("\n");
	printf("Press any keys to continue"); getch();
}

//function untuk display menu Export Data
void exportDataMenu(int counter){
	
	char fileName[1000];
	
	printf("File name: ");
	scanf("%s", fileName); getchar();
	
	strcat(fileName, ".csv");
	
	FILE *fp = fopen(fileName, "w");
	
	for(int i = 0; i < counter; i++){
		fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s\n", 
		data[i].location, data[i].city, data[i].price, data[i].room, data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
	}
	
	fclose(fp);
	
	printf("Data successfully written to file %s\n", fileName);
	printf("Press any key to return"); getch();
}

int main(){
	
	int counter = readFile();
	int number;
	
	do{
		number = mainMenu(number);

		if(number == 1){
			displayDataMenu(counter);	
			system("cls");
		}
		else if(number == 2){
			selectRowMenu(counter);
			system("cls");
		}
		else if(number == 3){
			sortDataMenu(counter);
			system("cls");
		}
		else if(number == 4){
			exportDataMenu(counter);
			system("cls");
		}		
	} while (number != 5);
	
	printf("Thank you for using this program!\n");
	
	return 0;
}
