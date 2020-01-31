// EXTERNAL VARIABLES
extern const int ENTRIES;
extern char choice;
extern double first, last, delta;


// Required Prototypes
void initialize();
bool checkCode(char);
void readDataFromFile(const char *);
void writeDataToFile(const char *);
double findNyanCatValue(double);


// Additional Prototypes
char selectProgram();
bool askValidateInput();
