//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

//gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"
int main(void){
    //defined in employeeSearchOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    //declaring new variables
    PtrToEmployee searchEmployeeByPhoneNum(PtrToConstEmployee ptr, int sizeTable, char * phoneNum);
    PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int sizeTable, double salary);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];    
    extern const int EmployeeTableEntries;     

    PtrToEmployee matchPtr;  //Declaration
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045);

    //Example not found
    if (matchPtr != NULL)
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");

    //Example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");
    
    //search by phone number
    //example of non match
    char* phoneNum = "012-345-6789";
    matchPtr = searchEmployeeByPhoneNum(EmployeeTable, EmployeeTableEntries, phoneNum);
    /*
    //example of match
    char* phoneNumNotFound = "213-555-1212";
    matchPtr = searchEmployeeByPhoneNum(EmployeeTable, EmployeeTableEntries, phoneNum);
    */

    //displays when phone number matches
    if(matchPtr!=NULL){
        printf("Employee with phone number %s is in record %d\n", phoneNum, (matchPtr-EmployeeTable));
    }
    //displays when phone number does not match
    else{
        printf("Employee with phone number %s is NOT found in the record\n", phoneNum);
    }

    //search by salary
    //example of match
    double salary = 7.80;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salary);
    /*
    //example of non match
    double salary = 38.20;
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, salary);
    */

    //displays when salary matches
    if(matchPtr!=NULL){
        printf("Employee with salary $%.2f is in record %d\n", salary, (matchPtr-EmployeeTable));
    }
    //displays when salary does not match
    else{
        printf("Employee with salary $%.2f is NOT found in the record\n", salary);
    }

    return EXIT_SUCCESS;
}