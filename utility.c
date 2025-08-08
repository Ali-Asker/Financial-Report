#include "utility.h"

int err = 0;
static clientptr foodHead = NULL;
static clientptr drinkHead = NULL;
static clientptr showHead = NULL;

int linkedList(clientptr data, int option)
{
    /* add node into food linked list */
    if (option == 0)
    {
        /* first node will be the head */
        if (foodHead == NULL)
        {
            foodHead = data;
        }
        else
        {
            clientptr food = foodHead;
            while (food->next != NULL)
            {
                food = food->next;
            }
            food->next = data;
            data->prev = food;
        }
    }

    /* add node into drink linked list */
    if (option == 1)
    {
        /* first node will be the head */
        if (drinkHead == NULL)
        {
            drinkHead = data;
        }
        else
        {
            clientptr drink = drinkHead;
            while (drink->next != NULL)
            {
                drink = drink->next;
            }
            drink->next = data;
            data->prev = drink;
        }
    }

    /* add node into show linked list */
    if (option == 2)
    {
        /* first node will be the head */
        if (showHead == NULL)
        {
            showHead = data;
        }
        else
        {
            clientptr show = showHead;
            while (show->next != NULL)
            {
                show = show->next;
            }
            show->next = data;
            data->prev = show;
        }
    }
    return err;
}

/* cobmine necessary data and print out the formatted response onto console */
int printData(void)
{
    clientptr food = foodHead;
    clientptr drink = drinkHead;
    clientptr show = showHead;
    int foodSelection = 0, hours = 0, wage = 20, salary = 0;
    int drinkSelection = 0, roundedTaxes = 0;
    int fine = 500;
    int revenue = 0, totalRevenue = 0;
    float taxes = 0;

    /* iterating food linked list and tallying calculation */
    while (food != NULL)
    {
        foodSelection += food->field1;
        totalRevenue += (food->field2 * food->field1);
        hours += (food->field3 * food->field1);
        food = food->next;
    }

    hours = (hours + 59) / 60; /* convert to rounded hours */
    salary = (hours * wage);
    printf("\n /========================\\ \n");
    printf("|     Financial Report     |\n");
    printf(" \\========================/ \n\n");
    printf("%d food items, generating $%d revenue.\n", foodSelection, totalRevenue);
    printf("Chef time is %.1f hours, costing $%.2f\n", (float)hours, (float)salary);

    /* iterating drink linked list and tallying calculation */
    if ((totalRevenue - revenue) > 0)
    {
        printf("Net profit from the kitchen is $%.2f\n", (float)(totalRevenue - salary));
        printf("Kitchen is profitable\n");
    }
    else
    {
        printf("Net loss from the kitchen is $%.2f\n", (float)(totalRevenue - salary) * -1);
        printf("Kitchen isn't profitable\n");
    }

    /* iterating drink linked list and tallying calculation */
    while (drink != NULL)
    {
        drinkSelection += drink->field2;
        if (drink->field3 == 1)
            taxes += (drink->field2 * 0.10);
        if (drink->field3 == 2)
            taxes += (drink->field1 * drink->field2 * 0.05);
        drink = drink->next;
    }

    roundedTaxes = (int)(taxes + .99);

    printf("\n");
    printf("%d drinks served, accumulating $%.2f in taxes due.\n", drinkSelection, (float)roundedTaxes);
    printf("\n");

    totalRevenue = 0;

    /* tallying the concerts revenue and fines from noise violation */
    while (show != NULL)
    {
        revenue = (show->field1 * show->field2);
        totalRevenue += revenue;
        printf("Band %s brought in $%d revenue. ", show->name, revenue);
        if (show->field3 == 1)
        {
            totalRevenue -= fine;
            printf("(Noise Violation)");
            if (revenue < fine)
            {
                printf("\nNB:  %s is not profitable due to noise violations.", show->name);
            }
        }
        printf("\n");
        show = show->next;
    }
    printf("\nTotal band revenue: $%d\n\n", totalRevenue);

    return err;
}

/* go through each node and free them within the linked list */
int freeList(clientptr *headRef)
{
    clientptr current = *headRef;
    clientptr next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;

    return err;
}

/* will free memory for each linked list category */
int freeAllList()
{
    freeList(&foodHead);
    freeList(&drinkHead);
    freeList(&showHead);

    return err;
}
