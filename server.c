#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"

char phy_cycle[][2][50] = {{"UE20MA101", "Engineering Mathematics-1"}, {"UE20CS101", "Python for Computational Problem Solving"}, {"UE20PH101", "Engineering Physics"}, {"UE20ME101", "Mechanical Engineering Sciences"}, {"UE20EE101", "Elements of Electrical Engineering"}, {"UE20EV101", "Environmental Studies and Life Sciences"}, {"UE20CS102", "PCPS Lab"}, {"UE20PH102", "Engineering Physics Lab"}};
char chem_cycle[][2][50] = {{"UE20MA151", "Engineering Mathematics-2"}, {"UE20CS151", "Problem Solving with C"}, {"UE20CY101", "Engineering Chemistry"}, {"UE20EC101", "Electronic Principles and Devices"}, {"UE20CV101", "Engineering Mechanics-Statics"}, {"UE20CE101", "Constitution of India,Cyber law and Professional Ethics"}, {"UE20CS152", "PSWC Lab"}, {"UE20CY101", "Engineering Chemistry Lab"}};

//Head message
void headMessage(const char *message)
{
    system("clear");
    printf("\t############################################################");
    printf("\n\t\t\tSIMPLE RESULT MANAGEMENT SYSTEM");
    printf("\n\t############################################################");
    printf("\n\t\t------------------------------------------\n");
    for (int i = 0; i < 37 - (strlen(message) / 2); i++)
        printf(" ");
    printf("%s", message);
    printf("\n\t\t------------------------------------------");
}
//Display message
void welcomeMessage()
{
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\n\t      *****************");
    printf("\n\t      *    WELCOME TO SIMPLE RESULT MANAGEMENT SYSTEM   *");
    printf("\n\t      *****************\n");
    getchar();
}
int is_exist(char s[])
{
    s_StudentInfo addStudentInfoInDataBase;
    FILE *fp = NULL;
    fp = fopen(RECORD_FILE, "rb");
    if (fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        getchar();
        exit(1);
    }
    while (fread(&addStudentInfoInDataBase, RECORD_FILE_SIZE, 1, fp))
    {
        if (!strcmp(addStudentInfoInDataBase.student_srn, s))
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
void displaymarks(s_StudentInfo *stu)
{
    int i;
    printf("\n\nSubjects\tISA1\tISA2\tAssignment\tEsa");
    if (stu->cycle[0] == 'c')
    {
        for (i = 0; i < 8; i++)
        {
            printf("\n%s\t", chem_cycle[i][0]);
            (stu->isa1.mark[i] < 0) ? printf(" -\t") : printf(" %2.f\t", stu->isa1.mark[i]);
            (stu->isa2.mark[i] < 0) ? printf(" -\t    ") : printf(" %2.f\t    ", stu->isa2.mark[i]);
            (stu->assignment.mark[i] < 0) ? printf("-\t\t") : printf("%2.f\t\t", stu->assignment.mark[i]);
            (stu->esa.mark[i] < 0) ? printf(" -\t") : printf(" %2.f\t", stu->esa.mark[i]);
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            printf("\n%s\t", phy_cycle[i][0]);
            (stu->isa1.mark[i] < 0) ? printf(" -\t") : printf(" %2.f\t", stu->isa1.mark[i]);
            (stu->isa2.mark[i] < 0) ? printf(" -\t    ") : printf(" %2.f\t    ", stu->isa2.mark[i]);
            (stu->assignment.mark[i] < 0) ? printf("-\t\t") : printf("%2.f\t\t", stu->assignment.mark[i]);
            (stu->esa.mark[i] < 0) ? printf(" -\t") : printf(" %2.f\t", stu->esa.mark[i]);
        }
    }
}
void askmarks(s_StudentInfo *stu, int e)
{
    int i;
    printf("\n\n\n\t\t\tEnter the marks...");
    if (stu->cycle[0] == 'c')
    {
        for (i = 0; i < 8; i++)
        {
            printf("\n\t\t\t%s :", chem_cycle[i][0]);
            switch (e)
            {
            case 1:
                scanf("%f", &stu->isa1.mark[i]);
                while (stu->isa1.mark[i] > 60)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->isa1.mark[i]);
                }
                break;
            case 2:
                scanf("%f", &stu->isa2.mark[i]);
                while (stu->isa2.mark[i] > 40)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->isa2.mark[i]);
                }
                break;
            case 3:
                scanf("%f", &stu->assignment.mark[i]);
                while (stu->assignment.mark[i] > 10)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->assignment.mark[i]);
                }
                break;
            case 4:
                scanf("%f", &stu->esa.mark[i]);
                while (stu->esa.mark[i] > 100)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->esa.mark[i]);
                }
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            printf("\n\t\t\t%s :", phy_cycle[i][0]);
            switch (e)
            {
            case 1:
                scanf("%f", &stu->isa1.mark[i]);
                while (stu->isa1.mark[i] > 60)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->isa1.mark[i]);
                }
                break;
            case 2:
                scanf("%f", &stu->isa2.mark[i]);
                while (stu->isa2.mark[i] > 40)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->isa2.mark[i]);
                }
                break;

            case 3:
                scanf("%f", &stu->assignment.mark[i]);
                while (stu->assignment.mark[i] > 10)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->assignment.mark[i]);
                }
                break;
            case 4:
                scanf("%f", &stu->esa.mark[i]);
                while (stu->esa.mark[i] > 100)
                {
                    printf("\t\t\tMarks entered is exceeding the maximum limit!!\n");
                    printf("\t\t\tEnter the correct marks: ");
                    scanf("%f", &stu->esa.mark[i]);
                }
                break;
            }
        }
    }
}
// Add student in list
void addStudentInDataBase()
{
    s_StudentInfo addStudentInfoInDataBase;
    FILE *fp = NULL;
    int status = 0;
    int choice, i;
    fp = fopen(RECORD_FILE, "ab+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW Students");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t-----------------------------------------------------\n");
    printf("\n\t\t\tStudent SRN  = ");
    fflush(stdin);
    scanf("%s", addStudentInfoInDataBase.student_srn);
    if (is_exist(addStudentInfoInDataBase.student_srn))
    {
        printf("\n\t\t\tData already exists...!");
        getchar();
    }
    else
    {
        printf("\n\t\t\tStudent Name  = ");
        fflush(stdin);
        scanf("%s", addStudentInfoInDataBase.studentName);
        fflush(stdin);
        printf("\n\t\t\tEnter the Semester number of the student: ");
        scanf("%d", &addStudentInfoInDataBase.sem);
        printf("\n\t\t\tEnter the cycle: 1.chemistry  2.physics");
        printf("\n\n\t\t\tEnter your choice...");
        do
        {
            fflush(stdin);
            scanf("%d", &choice);
            if (choice != 1 && choice != 2)
            {
                choice = 0;
                printf("\n\t\t\tEnter correct choice...");
            }
        } while (!choice);
        if (choice == 1)
            strcpy(addStudentInfoInDataBase.cycle, "chemistry");
        else
            strcpy(addStudentInfoInDataBase.cycle, "physics");
        printf("\n\t\t\tCreate a password for student to login:");
        fflush(stdin);
        scanf("%s", addStudentInfoInDataBase.pass);
        for (i = 0; i < 8; i++)
        {
            addStudentInfoInDataBase.isa1.mark[i] = -1.0;
            addStudentInfoInDataBase.isa2.mark[i] = -1.0;
            addStudentInfoInDataBase.assignment.mark[i] = -1.0;
            addStudentInfoInDataBase.esa.mark[i] = -1.0;
        }
        fwrite(&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp);
        fclose(fp);
        printf("\n\t\t\tStudent added successfully!");
        getchar();
    }
}
// search student

void updateStudent()
{
    int found = 0, choice;
    char studentUpdate[12];
    s_StudentInfo addStudentInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    headMessage("Update Student Details");
    fp = fopen(RECORD_FILE, "rb");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin", "wb");
    if (tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    printf("\n\t\t\tEnter Student SRN for Update:");
    fflush(stdin);
    scanf("%s", studentUpdate);
    while (fread(&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))
    {
        if (strcmp(addStudentInfoInDataBase.student_srn, studentUpdate) != 0)
        {
            fwrite(&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, tmpFp);
        }
        else if (!strcmp(addStudentInfoInDataBase.student_srn, studentUpdate))
        {
            system("clear");
            headMessage("Mark details");
            printf("\n\t\t\t1.ISA 1");
            printf("\n\t\t\t2.ISA 2");
            printf("\n\t\t\t3.Assignment");
            printf("\n\t\t\t4.ESA");
            printf("\n\t\t\tEnter your choice(Enter any other key to return)....");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                system("clear");
                headMessage("ISA 1");
                askmarks(&addStudentInfoInDataBase, 1);
                break;
            case 2:
                system("clear");
                headMessage("ISA 2");
                askmarks(&addStudentInfoInDataBase, 2);
                break;
            case 3:
                system("clear");
                headMessage("ASSIGNMENT");
                askmarks(&addStudentInfoInDataBase, 3);
                break;
            case 4:
                system("clear");
                headMessage("ESA");
                askmarks(&addStudentInfoInDataBase, 4);
                break;
            default:
                menu();
            }
            fwrite(&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, tmpFp);
            found = 1;
        }
    }
    (found) ? printf("\n\t\t\tRecord updated successfully.....") : printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(RECORD_FILE);
    rename("tmp.bin", RECORD_FILE);
    getchar();
}

void searchStudent(char *u)
{
    int found = 0;
    char studentId[MAX_SIZE_PASSWORD];
    s_StudentInfo addStudentInfoInDataBase;
    FILE *fp = NULL;
    fp = fopen(RECORD_FILE, "rb");
    if (fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH STUDENTS");
    if (u == NULL)
    {
        printf("\n\n\t\t\tEnter Student SRN to search:");
        fflush(stdin);
        scanf("%s", studentId);
    }
    else
        strcpy(studentId, u);
    while (fread(&addStudentInfoInDataBase, RECORD_FILE_SIZE, 1, fp))
    {
        if (!strcmp(addStudentInfoInDataBase.student_srn, studentId))
        {
            found = 1;
            break;
        }
    }
    if (found)
    {
        printf("\nSRN:%s", addStudentInfoInDataBase.student_srn);
        printf("\t\tname:%s", addStudentInfoInDataBase.studentName);
        printf("\tSemester:%d", addStudentInfoInDataBase.sem);
        printf("\tcycle:%s\n", addStudentInfoInDataBase.cycle);
        displaymarks(&addStudentInfoInDataBase);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    if (u == NULL)
        printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    else
        printf("\n\n\n\t\t\tPress any key to go to login page.....");
    fflush(stdin);
    getchar();
}
// view students function
void viewStudent()
{
    int found = 0;
    s_StudentInfo addStudentInfoInDataBase = {0};
    FILE *fp = NULL;
    //unsigned int countStudent = 1;
    headMessage("VIEW STUDENT DETAILS");
    fp = fopen(RECORD_FILE, "rb");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    while (fread(&addStudentInfoInDataBase, RECORD_FILE_SIZE, 1, fp))
    {
        //printf("\n\t\t\tStudent Count = %d\n\n",countStudent);
        printf("\nSRN:%s", addStudentInfoInDataBase.student_srn);
        printf("\t\tName:%s", addStudentInfoInDataBase.studentName);
        printf("\tSemester:%d", addStudentInfoInDataBase.sem);
        printf("\tCycle:%s\n", addStudentInfoInDataBase.cycle);
        displaymarks(&addStudentInfoInDataBase);
        printf("\n");
        found = 1;
        //++countStudent;
    }
    fclose(fp);
    if (!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
// Delete student entry
void deleteStudent()
{
    int found = 0;
    char studentDelete[12];
    s_StudentInfo addStudentInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    headMessage("Delete Student Details");
    fp = fopen(RECORD_FILE, "rb");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin", "wb");
    if (tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    printf("\n\t\t\tEnter Student SRN for delete:");
    fflush(stdin);
    scanf("%s", studentDelete);
    while (fread(&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, fp))
    {
        if (strcmp(addStudentInfoInDataBase.student_srn, studentDelete) != 0)
        {
            fwrite(&addStudentInfoInDataBase, sizeof(addStudentInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found) ? printf("\n\t\t\tRecord deleted successfully.....") : printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(RECORD_FILE);
    rename("tmp.bin", RECORD_FILE);
    getchar();
}
//function to update credential
void updateCredential()
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    char userName[MAX_SIZE_USER_NAME] = {0};
    char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("Update Credential");
    fp = fopen(ADMIN_FILE, "rb+");
    if (fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread(&fileHeaderInfo, RECORD_FILE_SIZE, 1, fp);
    if (fseek(fp, 0, SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(userName, MAX_SIZE_USER_NAME, stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password, MAX_SIZE_PASSWORD, stdin);
    strncpy(fileHeaderInfo.username, userName, sizeof(userName));
    strncpy(fileHeaderInfo.password, password, sizeof(password));
    fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\n\t\t\tLogin Again!");
    fflush(stdin);
    getchar();
    login();
}
//Display menu
void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Student");
        printf("\n\t\t\t2.Search Student");
        printf("\n\t\t\t3.View Student");
        printf("\n\t\t\t4.Update student details");
        printf("\n\t\t\t5.Delete Student");
        printf("\n\t\t\t6.Update Password");
        printf("\n\t\t\t7.Login page");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStudentInDataBase();
            break;
        case 2:
            searchStudent(NULL);
            break;
        case 3:
            viewStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            updateCredential();
            break;
        case 7:
            login();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        } //Switch Ended
    } while (choice != 0);
    //Loop Ended
}
//login password
void login()
{
    char userName[MAX_SIZE_USER_NAME] = {0};
    char password[MAX_SIZE_PASSWORD] = {0};
    int choice, count = 3;
    int found = 0;
    sFileHeader fileHeaderInfo = {0};
    s_StudentInfo s;
    FILE *fp = NULL;
    headMessage("Login");
    printf("\n\n\n\t\t\t1.Admin login");
    printf("\n\t\t\t2.Student login");
    printf("\n\t\t\t3.Exit");
    printf("\n\t\t\tEnter your choice...");
    scanf("%d", &choice);
    while (count--)
    {
        switch (choice)
        {
        case 1:
            system("clear");
            headMessage("Login");
            fp = fopen(ADMIN_FILE, "rb");
            if (fp == NULL)
            {
                printf("File is not opened\n");
                exit(1);
            }
            fread(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
            printf("\n\n\n\t\t\tusername:");
            scanf("%s", userName);
            printf("\n\t\t\tPassword:");
            scanf("%s", password);
            if ((!strcmp(userName, fileHeaderInfo.username)) && (!strcmp(password, fileHeaderInfo.password)))
            {
                menu();
            }
            else
            {
                printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
                getchar();
            }
            break;

        case 2:
            system("clear");
            headMessage("Login");
            fp = fopen(RECORD_FILE, "rb");
            if (fp == NULL)
            {
                printf("File is not opened\n");
                exit(1);
            }
            printf("\n\n\n\t\t\tSRN:");
            scanf("%s", userName);

            while (fread(&s, RECORD_FILE_SIZE, 1, fp))
            {
                if (!strcmp(s.student_srn, userName))
                {
                    found = 1;
                    break;
                }
            }
            fclose(fp);
            if (!found)
            {
                printf("Detailes still not updated by the exam commitee...");
                fflush(stdin);
                getchar();
                exit(0);
            }
            else
            {
                printf("\n\t\t\tPassword:");
                scanf("%s", password);
                if (!strcmp(password, s.pass))
                {
                    searchStudent(s.student_srn);
                    login();
                }
                else
                {
                    printf("\t\t\t\tLogin Failed Enter correct Password and SRN:\n\n");
                    getchar();
                }
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            if (count > 0)
            {
                printf("\t\t\tEnter a correct choice...");
                fflush(stdin);
                scanf("%d", &choice);
            }
        }
        if (count == 0)
        {
            headMessage("Login Failed");
            printf("\t\t\t\tSorry,Unknown User.");
            getchar();
            system("clear");
            exit(0);
        }
    }
}
//Check file exist or not
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}
void check_all_files()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] = "pes";
    const char defaultPassword[] = "pes";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(ADMIN_FILE);
    if (!status)
    {
        //create the binary file
        fp = fopen(ADMIN_FILE, "wb");
        if (fp != NULL)
        {
            //Copy default password
            strcpy(fileHeaderInfo.password, defaultPassword);
            strcpy(fileHeaderInfo.username, defaultUsername);
            fwrite(&fileHeaderInfo, FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
    status = isFileExists(RECORD_FILE);

    if (!status)
    {
        fp = fopen(RECORD_FILE, "wb");
        if (fp != NULL)
            fclose(fp);
    }
}