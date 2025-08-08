#include "utility.h"

int fileReader(char *fileName)
{
    client *data;
    char line[128];
    int len;

    /* FileReader to read file from based on user input */
    FILE *streams = fopen(fileName, "r");
    if (streams == NULL)
    {
        printf("Error! unable to open the file.\n");
        return err + 1;
    }

    /* Each new lines (from file) gets memory allocated and distributed to the proper linked list for filtering */
    while (fgets(line, 128, streams) != NULL)
    {
        /* allocating memory for data struct to put as nodes in linked list */
        char *token = strtok(line, ",");
        data = (clientptr)malloc(sizeof(client));

        /* Catch Allocation Failure */
        if (data == NULL)
        {
            printf("Memory allocation failed\n");
            return err + 1;
        }

        /* Delimiter "," to store values accordingly in client struct */
        
        /* Remove leading whitespaces */
        while (*token && isspace((unsigned char)*token))
            token++;

        /* Copy the string */
        strncpy(data->name, token, sizeof(data->name) - 1);
        data->name[sizeof(data->name) - 1] = '\0'; /* Ensure null termination */

        /* Remove trailing whitespaces */
        len = strlen(data->name);
        while (len > 0 && isspace((unsigned char)data->name[len - 1]))
        {
            data->name[--len] = '\0';
        }
        token = strtok(NULL, ",");
        data->type = atoi(token);
        token = strtok(NULL, ",");
        data->field1 = atoi(token);
        token = strtok(NULL, ",");
        data->field2 = atoi(token);
        token = strtok(NULL, ",");
        data->field3 = atoi(token);
        token = strtok(NULL, ",");

        /* store linked list based on proper type value (food, drink, show) */
        linkedList(data, data->type);
    }
    fclose(streams);
    return err;
}
