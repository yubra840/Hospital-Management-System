#include <stdio.h>
#include <windows.h> 
#include <stdlib.h> 
#include <string.h>
#include <conio.h> 

// Colors
#define RESET "\033[0m" 
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define REVERSED "\033[7m"

struct Patient
{
    char name[50];
    int age;
    char gender[10];
    char National_Id[20];
    char type[20];       // inpatient or outpatient
    char wardNumber[10]; // applicable for inpatients only
    char phone_number[15];
};

struct Doctor
{
    char name[50];
    int age;
    char gender[10];
    char id[20];
    char specialty[50];
};

// Animations
void Delay_100();                             // Only for the dots
void Clear_Screen();                          // Clear Screen
void Delay_Modifying();                       // Modifying with dots
void Delay_Deleting();                        // Deleting with dots
void Delay_Searching();                       // Searching with dots
void Delay_Loading();                         // Loading with dots
void Delay_Please_Wait();                     // Please wait with dots
void Delay_dots();                            //
void Delay_Exiting();                         // Exiting with dots
void Hide_Cursor();                           // Hides cursor
void Show_Cursor();                           // Shows cursor
void Welcome_Screen();                        // Welcome screen animation
void typeEffect(const char *text, int delay); // Type effect

// Security
void get_password(char *password, int max_len);

// Function prototypes
void adminLogin();     // Login area
void adminMenu();      // Overal menu
void patientMenu();    // Patient menu
void doctorMenu();     // Doctor's menu
void in_out_patient(); // Patient type menu
void inpatient();      // Inpatient menu
void outpatient();     // Outpatient menu
void viewPatient();    // View patients function
void searchPatient();  // Search patient function
void deletePatient();  // Delete patient function
void modifyPatient();  // Modify patient function
void addDoctor();      // Add doctor function
void viewDoctor();     // View doctor function
void searchDoctor();   // Search Doctor function
void deleteDoctor();   // Delete doctor function
void modifyDoctor();   // Modify doctor function

// Entry point
int main()
{
    Hide_Cursor();
    Welcome_Screen();
    adminLogin();
    return 0;
}

// Admin Login
void adminLogin()
{
    Clear_Screen();
    char username[20], password[20];
    int attempts = 3;

    do
    {
        Hide_Cursor();
        typeEffect(REVERSED "\n=== Admin Login ===\n" RESET, 30);
        Show_Cursor();
        typeEffect("Username: " GREEN, 30);
        scanf("%s", username);
        typeEffect(RESET "Enter password: " GREEN, 30);
        get_password(password, sizeof(password));
        Hide_Cursor();

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
        {
            typeEffect(GREEN "\nLogin was successful.\n" RESET, 20);
            Delay_Loading();
            adminMenu();
            return;
        }
        else
        {
            attempts--;
            printf(RED "Incorrect login! %d attempts left.\n" RESET, attempts);
        }
    } while (attempts > 0);
    typeEffect(RED "Too many failed attempts\n" RESET, 20);

    Delay_Exiting();
    // Delay_100();
    printf("\n");
    exit(1);
}

// Admin Menu
void adminMenu()
{
    Sleep(2000);
    Clear_Screen();
    int choice;
    while (1)
    {
        Hide_Cursor();
        typeEffect(YELLOW "\n=== Admin Menu ===\n1. Patient Menu\n2. Doctor Menu\n3. Exit\n" RESET, 20);
        Show_Cursor();
        typeEffect("Enter choice: " GREEN, 30);
        scanf("%d", &choice);
        Hide_Cursor();
        switch (choice)
        {
        case 1:
            Delay_Loading();
            Clear_Screen();
            patientMenu();
            break;
        case 2:
            Delay_Loading();
            Clear_Screen();
            doctorMenu();
            break;
        case 3:
            Delay_Exiting();
            exit(0);
        default:
            typeEffect(RED "Invalid option.\n" RESET, 20);
        }
    }
}

// Patient Menu
void patientMenu()
{
    int choice;
    do
    {
        Hide_Cursor();
        typeEffect(YELLOW "\n=== Patient Menu ===\n1. Add Patient\n2. View Patients\n3. Search Patient\n4. Delete Patient\n5. Modify Patient\n6. Back to Admin Menu\n" RESET, 30);
        Show_Cursor();
        typeEffect("Enter choice: " GREEN, 50);
        scanf("%d", &choice);
        Hide_Cursor();
        switch (choice)
        {
        case 1: 
            Delay_Loading();
            Clear_Screen();
            in_out_patient();
            break;
        case 2:
            Delay_Loading();
            Clear_Screen();
            viewPatient();
            break;
        case 3:
            Delay_Loading();
            Clear_Screen();
            searchPatient();
            break;
        case 4:
            Delay_Loading();
            Clear_Screen();
            deletePatient();
            break;
        case 5:
            Delay_Loading();
            Clear_Screen();
            modifyPatient();
            break;
        case 6:
            Delay_Please_Wait();
            Clear_Screen();
            return;
        default:
            typeEffect(RED "Invalid option.\n" RESET, 20);
        }
    } while (choice != 6);
}

// Doctor Menu
void doctorMenu()
{
    int choice;
    while (1)
    {
        Hide_Cursor();
        typeEffect(YELLOW "\n=== Doctor Menu ===\n1. Add Doctor\n2. View Doctors\n3. Search Doctor\n4. Delete Doctor\n5. Modify Doctor\n6. Back to Admin Menu\n" RESET, 30);
        Show_Cursor();
        printf("Enter choice: " GREEN);
        scanf("%d", &choice);
        Hide_Cursor();
        switch (choice)
        {
        case 1:
            Delay_Loading();
            Clear_Screen();
            addDoctor();
            break;
        case 2:
            Delay_Loading();
            Clear_Screen();
            viewDoctor();
            break;
        case 3:
            Delay_Loading();
            Clear_Screen();
            searchDoctor();
            break;
        case 4:
            Delay_Loading();
            Clear_Screen();
            deleteDoctor();
            break;
        case 5:
            Delay_Loading();
            Clear_Screen();
            modifyDoctor();
            break;
        case 6:
            Delay_Please_Wait();
            Clear_Screen();
            return;
        default:
            typeEffect(RED "Invalid option.\n" RESET, 20);
        }
    }
}

void in_out_patient()
{
    int choice;
    while (1)
    {
        Hide_Cursor();
        typeEffect(YELLOW "\n=== Add Patient Menu ===\n1. Add In Patient\n2. Add Out Patient\n3. Back to Patient Menu\n" RESET, 20);
        Show_Cursor();
        typeEffect("Enter choice: " GREEN, 50);
        scanf("%d", &choice);
        Hide_Cursor();
        switch (choice)
        {
        case 1:
            Delay_Loading();
            Clear_Screen();
            inpatient();
            break;
        case 2:
            Delay_Loading();
            Clear_Screen();
            outpatient();
            break;
        case 3:
            Delay_Please_Wait();
            Clear_Screen();
            return;
        default:
            typeEffect(RED "Invalid option.\n" RESET, 20);
        }
    }
}

void outpatient()
{
    // decrypt_patient_file();
    struct Patient p;
    FILE *fp = fopen("patients.data", "ab");

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize == 0)
    {
        fprintf(fp, "==========================================================================\n");
        fprintf(fp, "%-20s %-5s %-10s %-15s %-10s %-10s %-10s\n", "Name", "Age", "Gender", "National Id", "Type", "Ward No", "Phone Number");
        fprintf(fp, "==========================================================================\n");
    }
    Show_Cursor();
    typeEffect("Enter Name: " GREEN, 30);
    scanf(" %[^\n]", p.name);
    typeEffect(RESET "Enter Age: " GREEN, 30);
    scanf("%d", &p.age);
    typeEffect(RESET "Enter Gender: " GREEN, 30);
    scanf("%s", p.gender);
    typeEffect(RESET "Enter ID: " GREEN, 30);
    scanf("%s", p.National_Id);
    strcpy(p.type, "Outpatient");
    strcpy(p.wardNumber, "-");
    typeEffect(RESET "Enter Phone Number: " GREEN, 30);
    scanf("%s", p.phone_number);
    Hide_Cursor();

    fprintf(fp, "%-20s %-5d %-10s %-15s %-10s %-10s %-15s\n", p.name, p.age, p.gender, p.National_Id, p.type, p.wardNumber, p.phone_number);
    // encrypt_patient_file();
    fclose(fp);
    Delay_Loading();
    typeEffect(GREEN "Outpatient added successfully.\n" RESET, 20);
}

// Add Inpatient
void inpatient()
{
    // decrypt_patient_file();
    struct Patient p;
    FILE *fp = fopen("patients.dat", "ab");

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize == 0)
    {
        fprintf(fp, YELLOW "==========================================================================\n");
        fprintf(fp, "%-20s %-5s %-10s %-15s %-10s %-10s %-10s\n", "Name", "Age", "Gender", "National Id", "Type", "Ward No", "Phone Number");
        fprintf(fp, "==========================================================================\n" RESET);
    }

    Show_Cursor();
    typeEffect("Enter Name: " GREEN, 30);
    scanf(" %[^\n]", p.name);
    typeEffect(RESET "Enter Age: " GREEN, 30);
    scanf("%d", &p.age);
    typeEffect(RESET "Enter Gender: " GREEN, 30);
    scanf("%s", p.gender);
    typeEffect(RESET "Enter ID: " GREEN, 30);
    scanf("%s", p.National_Id);
    strcpy(p.type, "Inpatient");
    typeEffect(RESET "Enter Ward Number: " GREEN, 30);
    scanf("%s", p.wardNumber);
    typeEffect(RESET "Enter Phone Number: " GREEN, 30);
    scanf("%s", p.phone_number);
    Hide_Cursor();

    fprintf(fp, "%-20s %-5d %-10s %-15s %-10s %-10s %-15s\n", p.name, p.age, p.gender, p.National_Id, p.type, p.wardNumber, p.phone_number);
    // encrypt_patient_file();
    fclose(fp);
    Delay_Loading();
    typeEffect(GREEN "Inpatient added successfully.\n" RESET, 20);
}

// View Patients
void viewPatient()
{
    // decrypt_patient_file();
    FILE *fp = fopen("patients.dat", "rb");
    char ch;
    if (fp == NULL)
    {
        typeEffect(RED "File not found.\n" RESET, 20);
        return;
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    // encrypt_patient_file();

    fclose(fp);
}

// Search Patient
void searchPatient()
{
    // decrypt_patient_file();
    char sec_National_Id[20];
    struct Patient p;
    int found = 0;

    FILE *fp = fopen("patients.dat", "rb");
    if (fp == NULL)
    {
        typeEffect(RED "Error opening file.\n" RESET, 20);
        return;
    }

    Show_Cursor();
    typeEffect("Enter Patient National ID to search: " GREEN, 30);
    scanf("%s", sec_National_Id);
    Hide_Cursor();

    Delay_Searching();

    char header[3][200];
    for (int i = 0; i < 3; i++) // skip headers
    {
        if (fgets(header[i], sizeof(header[i]), fp) == NULL)
        {
            typeEffect(RED "File is empty or corrupted.\n" RESET, 20);
            fclose(fp);
            return;
        }
    }

    while (fscanf(fp, "%s %d %s %s %s %s %s",
                  p.name, &p.age, p.gender, p.National_Id,
                  p.type, p.wardNumber, p.phone_number) == 7)
    {
        if (strcmp(sec_National_Id, p.National_Id) == 0)
        {
            typeEffect(GREEN "\nPatient Found:\n" RESET, 20);
            printf("Name         : %s\n" GREEN, p.name);
            printf(RESET "Age          : %d\n" GREEN, p.age);
            printf(RESET "Gender       : %s\n" GREEN, p.gender);
            printf(RESET "National ID  : %s\n" GREEN, p.National_Id);
            printf(RESET "Type         : %s\n" GREEN, p.type);
            printf(RESET "Ward Number  : %s\n" GREEN, strcmp(p.type, "Inpatient") == 0 ? p.wardNumber : "N/A");
            printf(RESET "Phone Number : %s\n" GREEN, p.phone_number);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf(RED "Patient with ID '%s' not found.\n" RESET, sec_National_Id);
    }
    // encrypt_patient_file();

    fclose(fp);
}

// Delete Patient
void deletePatient()
{
    // decrypt_patient_file();
    char id[20];
    struct Patient p;
    int found = 0;

    Show_Cursor();
    typeEffect("Enter the National ID of the patient to delete: " GREEN, 30);
    scanf("%s", id);
    Hide_Cursor();

    FILE *fp = fopen("patients.dat", "rb");
    FILE *fp_temp = fopen("temp.dat", "wb");

    if (fp == NULL || fp_temp == NULL)
    {
        typeEffect(RED "Error opening files.\n" RESET, 20);
        return;
    }

    // Copy headers
    char line[200];
    for (int i = 0; i < 3; i++)
    {
        if (fgets(line, sizeof(line), fp))
            fputs(line, fp_temp);
    }

    while (fscanf(fp, "%s %d %s %s %s %s %s",
                  p.name, &p.age, p.gender, p.National_Id,
                  p.type, p.wardNumber, p.phone_number) == 7)
    {
        if (strcmp(id, p.National_Id) == 0)
        {
            found = 1;
            // Skip writing this record
            continue;
        }
        fprintf(fp_temp, "%s\t%d\t%s\t%s\t%s\t%s\t%s\n",
                p.name, p.age, p.gender, p.National_Id,
                p.type, p.wardNumber, p.phone_number);
    }

    // encrypt_patient_file();

    fclose(fp);
    fclose(fp_temp);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found)
    {
        Delay_Please_Wait();
        printf(RED "Patient with ID '%s' not found.\n" RESET, id);
    }
    else
    {
        Delay_Please_Wait();
        Delay_Deleting();
        typeEffect(GREEN "Patient record deleted successfully.\n" RESET, 20);
    }
}

// Modify Patient
void modifyPatient()
{
    // decrypt_patient_file();
    char id[20];
    struct Patient p;
    int found = 0;

    Show_Cursor();
    typeEffect("Enter the National ID of the patient to modify: " GREEN, 30);
    scanf("%s", id);
    Hide_Cursor();

    FILE *fp = fopen("patients.dat", "rb");
    FILE *fp_temp = fopen("temp.dat", "wb");

    if (fp == NULL || fp_temp == NULL)
    {
        typeEffect(RED "Error opening files.\n" RESET, 20);
        return;
    }

    // Copy headers
    char line[200];
    for (int i = 0; i < 3; i++) // Assuming 3 header lines
    {
        if (fgets(line, sizeof(line), fp))
            fputs(line, fp_temp);
    }

    while (fscanf(fp, "%s %d %s %s %s %s %s",
                  p.name, &p.age, p.gender, p.National_Id,
                  p.type, p.wardNumber, p.phone_number) == 7)
    {
        if (strcmp(id, p.National_Id) == 0)
        {
            found = 1;
            Show_Cursor();
            typeEffect("Enter new name: " GREEN, 30);
            getchar(); // to consume newline left by previous scanf
            fgets(p.name, sizeof(p.name), stdin);
            p.name[strcspn(p.name, "\n")] = 0; // Remove trailing newline

            typeEffect(RESET "Enter new age: " GREEN, 30);
            scanf("%d", &p.age);

            typeEffect(RESET "Enter new gender: " GREEN, 30);
            getchar(); // to consume newline
            fgets(p.gender, sizeof(p.gender), stdin);
            p.gender[strcspn(p.gender, "\n")] = 0; // Remove trailing newline

            typeEffect(RESET "Enter new type (Inpatient/Outpatient): " GREEN, 30);
            scanf("%s", p.type);

            if (strcmp(p.type, "Inpatient") == 0)
            {
                typeEffect(RESET "Enter new ward number: " GREEN, 30);
                scanf("%s", p.wardNumber);
            }
            else
            {
                strcpy(p.wardNumber, "N/A");
            }

            typeEffect(RESET "Enter new phone number: " GREEN, 30);
            scanf("%s", p.phone_number);
            Hide_Cursor();

            // Writing updated patient data to temp file
            fprintf(fp_temp, "%-20s %-5d %-10s %-15s %-12s %-10s %-15s\n",
                    p.name, p.age, p.gender, p.National_Id,
                    p.type, p.wardNumber, p.phone_number);
        }
        else
        {
            // Writing unmodified patient data to temp file
            fprintf(fp_temp, "%-20s %-5d %-10s %-15s %-12s %-10s %-15s\n",
                    p.name, p.age, p.gender, p.National_Id,
                    p.type, p.wardNumber, p.phone_number);
        }
    }
    // encrypt_patient_file();

    fclose(fp);
    fclose(fp_temp);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found)
    {
        Delay_Please_Wait();
        printf(RED "Patient with ID '%s' not found.\n" RESET, id);
    }

    else
    {
        Delay_Please_Wait();
        Delay_Modifying();
        typeEffect(GREEN "Patient record updated successfully.\n" RESET, 20);
    }
}

// Add Doctor
void addDoctor()
{
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "a+");

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    if (fileSize == 0)
    {
        fprintf(fp, YELLOW "===============================================================\n");
        fprintf(fp, "%-20s %-5s %-10s %-15s %-15s\n", "Name", "Age", "Gender", "ID", "Specialty");
        fprintf(fp, "===============================================================\n" RESET);
    }

    Show_Cursor();
    typeEffect("Enter Name: " GREEN, 50);
    scanf("%s", d.name);
    typeEffect(RESET "Enter Age: " GREEN, 50);
    scanf("%d", &d.age);
    typeEffect(RESET "Enter Gender: " GREEN, 50);
    scanf("%s", d.gender);
    typeEffect(RESET "Enter ID: " GREEN, 50);
    scanf("%s", d.id);
    typeEffect(RESET "Enter Specialty: " GREEN, 50);
    scanf("%s", d.specialty);
    Hide_Cursor();

    Delay_Please_Wait();
    fprintf(fp, "%-20s %-5d %-10s %-15s %-15s\n", d.name, d.age, d.gender, d.id, d.specialty);
    fclose(fp);
    typeEffect(GREEN "Doctor added successfully.\n" RESET, 50);
}

// View Doctors
void viewDoctor()
{
    Delay_Loading();
    FILE *fp = fopen("doctors.txt", "r");
    char ch;
    if (fp == NULL)
    {
        typeEffect(RED "File not found.\n" RESET, 50);
        return;
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}

// Search Doctor
void searchDoctor()
{
    char id[20];
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "r");
    int found = 0;

    Show_Cursor();
    typeEffect("Enter Doctor ID to search: " GREEN, 50);
    scanf("%s", id);
    Hide_Cursor();

    Delay_Searching();

    while (fscanf(fp, "%s %d %s %s %s", d.name, &d.age, d.gender, d.id, d.specialty) != EOF)
    {
        if (strcmp(d.id, id) == 0)
        {
            typeEffect(GREEN "\nDoctor Found:\n" RESET, 50);
            printf("Name: %s\nAge: %d\nGender: %s\nID: %s\nSpecialty: %s\n",
                   d.name, d.age, d.gender, d.id, d.specialty);
            found = 1;
            break;
        }
    }

    if (!found)
        typeEffect(RED "Doctor not found.\n" RESET, 50);
    fclose(fp);
}

// Delete Doctor
void deleteDoctor()
{
    char id[20];
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "r");
    FILE *temp = fopen("doctororiginal.txt", "w");

    int found = 0;

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    if (fileSize > 0)
    {
        char line[200];
        for (int i = 0; i < 3; i++)
        {
            fgets(line, sizeof(line), fp);
            fputs(line, temp);
        }
    }

    Show_Cursor();
    typeEffect("Enter Doctor ID to delete: " GREEN, 50);
    scanf("%s", id);
    Hide_Cursor();

    while (fscanf(fp, "%s %d %s %s %s", d.name, &d.age, d.gender, d.id, d.specialty) != EOF)
    {
        if (strcmp(d.id, id) != 0)
        {
            fprintf(temp, "%-20s %-5d %-10s %-15s %-15s\n", d.name, d.age, d.gender, d.id, d.specialty);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("doctors.txt");
    rename("doctororiginal.txt", "doctors.txt");

    if (!found)
    {
        Delay_Please_Wait();
        typeEffect(RED "Doctor not found.\n" RESET, 50);
    }
    else
    {
        Delay_Please_Wait();
        Delay_Deleting();
        typeEffect(GREEN "Doctor deleted successfully.\n" RESET, 50);
    }
}

// Modify Doctor
void modifyDoctor()
{
    char id[20];
    struct Doctor d;
    FILE *fp = fopen("doctors.txt", "r");
    FILE *temp = fopen("doctororiginal.txt", "w");
    int found = 0;

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    if (fileSize > 0)
    {
        char line[200];
        for (int i = 0; i < 3; i++)
        {
            fgets(line, sizeof(line), fp);
            fputs(line, temp);
        }
    }

    Show_Cursor();
    typeEffect("Enter Doctor ID to modify: " GREEN, 50);
    scanf("%s", id);
    Hide_Cursor();

    while (fscanf(fp, "%s %d %s %s %s", d.name, &d.age, d.gender, d.id, d.specialty) != EOF)
    {
        if (strcmp(d.id, id) == 0)
        {
            typeEffect(RESET "Enter New Name: " GREEN, 50);
            scanf("%s", d.name);
            typeEffect(RESET "Enter New Age: " GREEN, 50);
            scanf("%d", &d.age);
            typeEffect(RESET "Enter New Gender: " GREEN, 50);
            scanf("%s", d.gender);
            typeEffect(RESET "Enter New Specialty: " GREEN, 50);
            scanf("%s", d.specialty);
            found = 1;
        }
        fprintf(temp, "%-20s %-5d %-10s %-15s %-15s\n", d.name, d.age, d.gender, d.id, d.specialty);
    }

    fclose(fp);
    fclose(temp);
    remove("doctors.txt");
    rename("doctororiginal.txt", "doctors.txt");

    if (!found)
    {
        Delay_Please_Wait();
        typeEffect(RED "Doctor not found.\n" RESET, 50);
    }
    else
    {
        Delay_Please_Wait();
        Delay_Modifying();
        typeEffect(GREEN "Doctor modified successfully.\n" RESET, 50);
    }
}

void Delay_100()
{
    for (int times = 0; times < 3; times++)
    {
        for (int i = 0; i < 3; i++)
        {
            printf(GREEN "." RESET);
            Sleep(100);
            fflush(stdout);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(100);
        }
    }
}

void Clear_Screen()
{
    system("cls");
}

void Delay_Loading()
{
    typeEffect(GREEN "Loading"RESET, 50);
    for (int times = 0; times < 3; times++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(GREEN"." RESET);
            Sleep(100);
            fflush(stdout);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(100);
        }
    }
    printf("\n");
}

void Delay_Searching()
{
    typeEffect(GREEN "Searching"RESET, 50);
    for (int times = 0; times < 3; times++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(GREEN"." RESET);
            Sleep(100);
            fflush(stdout);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(100);
        }
    }
    printf("\n");
}

void Delay_Deleting()
{
    typeEffect(RED "Deleting"RESET, 50);
    for (int times = 0; times < 3; times++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(RED"." RESET);
            Sleep(100);
            fflush(stdout);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(100);
        }
    }
    printf("\n");
}

void Delay_Modifying()
{
    typeEffect(GREEN "Modifying"RESET, 50);
    for (int times = 0; times < 3; times++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(GREEN"." RESET);
            Sleep(100);
            fflush(stdout);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(100);
        }
    }
    printf("\n");
}

void Delay_Please_Wait()
{
    typeEffect(GREEN "Please Wait"RESET, 50);
    for (int times = 0; times < 3; times++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(GREEN"." RESET);
            Sleep(100);
            fflush(stdout);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(100);
        }
    }
    printf("\n");
}

void typeEffect(const char *text, int delay)
{
    while (*text)
    {
        printf("%c", *text++);
        fflush(stdout);
        Sleep(delay); // delay is already in milliseconds
    }
}

void Delay_dots()
{
    for (int times = 0; times < 3; times++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf(GREEN "." RESET);
            Sleep(300);
            fflush(stdout);
        }

        for (int j = 0; j < 1; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(300);
        }
    }
}

void Hide_Cursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Show_Cursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void Welcome_Screen()
{
    typeEffect(YELLOW "HELLO", 50);
    Delay_dots();
    typeEffect(YELLOW " WELCOME TO MEDICORE HOSPITAL" RESET, 50);
    Delay_100();
    Clear_Screen();
}

void Delay_Exiting()
{
    typeEffect(RED "Exiting"RESET, 50);
    for (int times = 0; times < 3; times++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(RED"." RESET);
            Sleep(100);
            fflush(stdout);
        }

        for (int j = 0; j < 3; j++)
        {
            printf("\b \b");
            fflush(stdout);
            Sleep(100);
        }
    }
    printf("\n");
}

// Security functions
void get_password(char *password, int max_len)
{
    int i = 0;
    char ch;

    while ((ch = getch()) != '\r' && i < max_len - 1)
    {
        if (ch == '\b')
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
    printf("\n");
}

