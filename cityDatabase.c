#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct City{
	char name[100];
	int population;
};
struct Node{
	struct City city_info;
	struct Node* next;
};

void add_city(struct Node **head, char *name, int population){
	struct City city;
	strcpy(city.name, name);
	city.population = population;
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->city_info = city;
	new_node->next = NULL;
	
	if(*head == NULL){
		*head = new_node;
	}
	else{
		struct Node *current = *head;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = new_node;
	}
}

struct City* search_city(struct Node *head, char *name){
	struct Node *current = head;
	while(current != NULL){
		if(strcmp(current->city_info.name, name) == 0){
			return &(current->city_info);
		}
		current = current->next;
	}
	return NULL;
}

void remove_city(struct Node** head, char* name){
	if(*head == NULL){
		return;
	}
	if(strcmp((*head)->city_info.name, name) == 0){
		*head = (*head)->next;
		return;
	}
	struct Node* current = *head;
	while(current->next != NULL){
		if(strcmp(current->next->city_info.name, name) == 0){
			current->next = current->next->next;
		}
		current = current->next;
	}
}

void print_cities(struct Node* head){
	struct Node* current = head;
	while(current != NULL){
		printf("%s : %d\n", current->city_info.name, current->city_info.population);
		current = current->next;
	}
}

int main(){

	struct Node* city_db = NULL;
	add_city(&city_db, "Delhi", 1200000);
	add_city(&city_db, "Bhuj", 150000);
	add_city(&city_db, "Mumbai", 1240000);
	add_city(&city_db, "Ahmedabad", 154000);
	add_city(&city_db, "Surat", 156000);
	
	int choice = 0;
	while(choice != 4){
	printf("Your choices: \n");
	printf("1. Show Database \n");
	printf("2. Search in Database \n");
	printf("3. Delete from Database\n");
	printf("4. Quit \n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			print_cities(city_db);
			break;
		case 2:
			printf("Which city do you want to search ? \n");
			char name[100];
			scanf("%s", name);
			struct City* city_name = search_city(city_db, name);
			if(city_name == NULL){
				printf("No City found !");
			}
			else{
				printf("%s : %d\n", city_name->name, city_name->population);
			}
			break;
		case 3:
			printf("Which city do you want to remove ? \n");
			char remove_name[100];
			scanf("%s", remove_name);
			remove_city(&city_db, remove_name);
			printf("City Removed !\n");
			break;
		case 4:
			printf("Quitting...\n");
			break;
		default:
			printf("Wrong Choice !");
			break;
	}
	
	
	}
	return 0;
}



















