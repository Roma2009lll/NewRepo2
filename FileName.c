#include<stdlib.h>
#include<stdio.h>
struct Task {
	char description[20];
	int priority;
	int complete;
	struct Task* next;

};
struct Task* head=NULL;
void add_task() {
	struct Task* NewNode = (struct Task*)malloc(sizeof(struct Task));
	printf("Enter the description\n");
	scanf_s("%19s", NewNode->description, 20);
	printf("Enter the priority(number)\n");
	scanf_s("%d", &NewNode->priority);
	printf("Status of complete(0)\n");
	NewNode->complete = 0;
   
    
	NewNode->next = head;
	head = NewNode;
	printf("Task added successfully!\n");

}
void show_all() {
    int i = 1;
    if (head == NULL) {
        printf("The list is empty\n");
        return;

    }
    struct Task* NewNode = head;
    printf("***ALL THE TASK***\n");
    while (NewNode != NULL) {
        
    
        printf("Number %d:Description:%s Priority:%d Status:%d", i, NewNode->description, NewNode->priority, NewNode->complete);
        printf("\n");
        i++;
        NewNode = NewNode->next;
       

    }

}
void change_the_ststus() {
    int del;
    if (head == NULL) {
        printf("The list is empty\n");
        return;

    }
    show_all();
    int i = 1;
    printf("Enter the number of task you have done\n");
    scanf_s("%d", &del);
    
    struct Task* NewNode = head;
   
    while (NewNode != NULL) {
        if (del == i) {
            NewNode->complete=1;
            if (NewNode->complete == 1)printf("Done");
            printf("Number %d:Description:%s Priority:%d Status:%d", i, NewNode->description, NewNode->priority, NewNode->complete);
            printf("\n");
            return;
        }
        i++;
       
        NewNode = NewNode->next;


    }

    
    

}
void delete_task(int del1) {
    
    if (head == NULL) {
        printf("The list is empty\n");
        return;

    }
    if (del1 < 1) {
        printf("Invalid task number!\n");
        return;
    }
    
    struct Task* NewNode = head;
    struct Task* tmp2;
    if (del1 == 1) {
        struct Task* delete = head;
        head= head->next;
        free(delete);
        return;
        

    }
    
    for (int i = 0; i < del1 - 2; i++) {
        NewNode = NewNode->next;//n-1
    }
    tmp2 = NewNode->next;//n
    
    NewNode->next = tmp2->next;//n
    
    printf("Task deleted succsexfully\n");
    free(tmp2);



}
void show_higth_priorty() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Task* NewNode = head;
    int i = 0, found = 0;
    while (NewNode != NULL) {
        i++;
        if (NewNode->priority<=3&& NewNode->complete!=1) {
            
            printf("Number %d:Description:%s Priority:%d Status:%d", i, NewNode->description, NewNode->priority, NewNode->complete);
            printf("\n");
            found++;
        }
        NewNode = NewNode->next;
       
    }
    if (found == 0) {
        printf("No high priority tasks\n");
       
    }
    
}
void show_uncomplite() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Task* NewNode = head;
    int i = 0, found = 0;
    while (NewNode != NULL) {
        i++;
        if (NewNode->complete == 0) {

            printf("Number %d:Description:%s Priority:%d Status:%d", i, NewNode->description, NewNode->priority, NewNode->complete);
            printf("\n");
            found++;
        }
        NewNode = NewNode->next;

    }
    if (found == 0) {
        printf("No high priority tasks\n");

    }


}
void stat() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Task* NewNode = head;
    int total = 0;
    int completed = 0;
    int pending = 0;
    int high = 0;
    int medium = 0;
    int low = 0;
    while (NewNode != NULL) {
        total++;
        if (NewNode->complete == 1) {
            completed++;

        }
        else {
            pending++;


        }
        NewNode = NewNode->next;

        


    }
    
    
    printf("***STATS***");
    printf("ALL tasks:%d\ncompleted:%d\nuncompleted:%d\n", total, completed, pending);
    if (completed < pending) {
        printf("Try harder you are running out of time\n");

    }
    else {
        printf("You are doing really good\n");
    }

}
void clear_all_done() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;

    }
    int del = 0;
    while (1) {
        int found = 0;
        int i = 1;
        struct Task* tmp = head;
        while (tmp!=NULL) {
            
           
            if (tmp->complete == 1) {
                delete_task(i);
                found=1;
                del++;
                break;
               


            }
            else {
                tmp = tmp->next;
                i++;
            }

        }
        if (found == 0) {
            
            break;


        }
        
    }
    if (del == 0) {
        printf("No tasks completed yet\n");
       
    }
    else {
        printf("Succsesfully deleted:%d tasks", del);
    }
}
void free_all_tasks() {
    struct Task* current = head;
    struct Task* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All memory freed!\n");
}
int main() {
    int choice;
    int del1;
    while (1) {
        printf("\n=== TASK MANAGER ===\n");
        printf("1. Add task\n");
        printf("2. Show all tasks\n");
        printf("3. Mark as done\n");
        printf("4. Delete task\n");
        printf("5. Show hight priority task\n");
        printf("6. Show undone  task\n");
        printf("7. Clear all done tasks\n");
        printf("8. Show the stats\n");
        printf("0. Exit\n");
        printf(">> ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            add_task();
            break;
        case 2:
            show_all();
            break;
        case 3:
           
           
            change_the_ststus();
            break;

          
        case 4:
            if (head == NULL) {
                printf("The list is empty\n");
                break;

            }
            show_all();
            printf("Enter the number of task you want to delete\n");
            scanf_s("%d", &del1);
           
            
            delete_task(del1);
            break;
        case 5:
            show_higth_priorty();
            break;
        case 6:
            show_uncomplite();
            break;
        case 7:
            clear_all_done();
            break;
        case 8:
            stat();
            break;


        case 0:
            free_all_tasks();
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

}
