// #include  <iostream>
// #include  <print>
// #include <cstring>
// #include <filesystem>
//
// class Secret
// {
//     private:
//         char * taskDescription = nullptr;
//         char * password = nullptr;
//         mutable int unsuccessfulEntries = 0;
//
//     void setTaskDesc(const char *TaskDesc)
//     {
//         if (!TaskDesc)
//         {
//             std::println("No task description is entered!");
//             return;
//         }
//
//         delete [] taskDescription;
//
//         int inpDescLength = strlen(TaskDesc);
//         taskDescription = new char[inpDescLength + 1];
//         strcpy(taskDescription, TaskDesc);
//         taskDescription[inpDescLength] = '\0';
//     }
//
//     void setPassword(const char *inpPass)
//     {
//         if (!inpPass)
//         {
//             std::println("No password is inputed!");
//             return;
//         }
//
//         delete [] password;
//
//         int inpPassLen = strlen(inpPass);
//         password = new char[inpPassLen + 1];
//         strcpy(password, inpPass);
//         password[inpPassLen] = '\0';
//     }
//     public:
//     Secret() = default;
//
//     Secret(const char * taskDesc, const char *pswrd)
//     {
//         setTaskDesc(taskDesc);
//         setPassword(pswrd);
//     }
//
//     ~Secret()
//     {
//         delete [] taskDescription;
//         delete [] password;
//     }
//
//     const char * getTaskDesc() const
//     {
//         return taskDescription;
//     }
//
//     const char* getPswrd() const
//     {
//         return password;
//     }
//
//     const char *getTask(const char *pwd) const
//     {
//         if (!pwd)
//         {
//             std::println("No password is inputed");
//             return nullptr;
//         }
//
//         if (strcmp(password, pwd) == 0)
//         {
//             return taskDescription;
//         }
//         else
//         {
//             unsuccessfulEntries++;
//             std::println("Incorrect password!");
//             return nullptr;
//         }
//     }
//
//     void setPassword(const char* newPassword, const char* oldPassword)
//     {
//         if (!newPassword || !oldPassword)
//             return;
//
//         if (strcmp(password, oldPassword) == 0)
//         {
//
//             setPassword(newPassword);
//             std::println("Successful change of the old password!");
//             std::println("The new password is: {}", password);
//         }
//         else
//         {
//             std::println("Incorrectly entered password. The password can not be changed");
//             unsuccessfulEntries++;
//             return;
//         }
//     }
//
//     void setTask(const char* newTask, const char* passwd)
//     {
//         if (!newTask || !passwd)
//                 return;
//
//         if (strcmp(password, passwd) == 0)
//         {
//             this->setTaskDesc(newTask);
//
//             std::println("The task description is successfully changed to: {}", taskDescription);
//
//         }
//         else
//         {
//             std::println("Incorrectly entered password. The task description can not be changed");
//             unsuccessfulEntries++;
//             return;
//         }
//     }
//
//     int getLoginFails() const
//     {
//         return unsuccessfulEntries;
//     }
// };
// int main()
// {
//     Secret Exam("task 4", "samo levski");
//
//     const char *task = Exam.getTask("samo levski");
//     if (task)
//     {
//         std::println("correct password!");
//         std::println("The task description is: {}", task);
//     }
//
//     Exam.setPassword("cska", "samo levski");
//     Exam.setTask("task 1", "samo levski");
//
//    int unsuccess =  Exam.getLoginFails();
//     std::println("The unsuccessful logins are: {}", unsuccess);
//     return 0;
// }