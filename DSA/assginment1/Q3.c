#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct employee
    {
        char name[30];
        int age;
        float salary;
    };

    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct employee *emp = malloc(n * sizeof(struct employee));
    FILE *fp;
    fp = fopen("employee.txt", "wb+");

    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", emp[i].name);
        printf("Enter the age of employee %d: ", i + 1);
        scanf("%d", &emp[i].age);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%f", &emp[i].salary);
        fwrite(&emp[i], sizeof(emp[i]), 1, fp);
    }

    rewind(fp);

    for (int i = 0; i < n; i++)
    {
        fread(&emp[i], sizeof(emp[i]), 1, fp);

        if (emp[i].salary < 15000)
        {
            emp[i].salary = emp[i].salary + (emp[i].salary * 0.05);
        }
        else if (emp[i].salary >= 15000 && emp[i].salary <= 20000)
        {
            emp[i].salary = emp[i].salary + (emp[i].salary * 0.10);
        }
        else
        {
            emp[i].salary = emp[i].salary + (emp[i].salary * 0.15);
        }

        fseek(fp, -sizeof(struct employee), SEEK_CUR);
        fwrite(&emp[i], sizeof(emp[i]), 1, fp);
        fflush(fp);
    }

    free(emp);
    fclose(fp);

    return 0;
}