#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD 201
#define RECORD_FILE "studentRecordSystem.bin"
#define ADMIN_FILE "adminpassword.bin"
// Macro related to the students info
#define MAX_STUDENT_NAME 50
#define FILE_HEADER_SIZE sizeof(sFileHeader)
#define RECORD_FILE_SIZE sizeof(s_StudentInfo)

typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;

//Elements of structure
typedef struct
{
    float mark[8];
    float total;
} marks;

typedef struct // to call in program
{
    char student_srn[MAX_SIZE_PASSWORD]; // declare the integer data type
    char cycle[MAX_SIZE_PASSWORD];
    char studentName[MAX_STUDENT_NAME]; // declare the character data type
    char pass[MAX_SIZE_PASSWORD];
    int sem;
    marks isa1;
    marks isa2;
    marks assignment;
    marks esa;
    char grade;
    int result;
} s_StudentInfo;

void headMessage(const char*);

void welcomeMessage();

int is_exist(char[]);

void displaymarks(s_StudentInfo*);

void askmarks(s_StudentInfo*, int );

void addStudentInDataBase();

void updateStudent();

void searchStudent(char*);

void viewStudent();

void deleteStudent();

void updateCredential();

void menu();

void login();

int isFileExists(const char*);

void check_all_files();
