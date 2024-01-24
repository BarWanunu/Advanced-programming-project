# Advanced-programming-project

# How to compile and run our program:

1. download our Advanced-programming-project folder
2. put the next commands in that folder on termianl:
3. cd src
4. g++ -o myprogram ./main.cpp ./InputArr.cpp ./BloomPart.cpp ./AddURL.cpp ./CheckURL.cpp ./BytesArray.cpp ./URLlist.cpp ./HashFunction.cpp ./Node.cpp
5. ./myprogram
6. our program is now run on your computer!



# Our workflow

At first we divided the missions between us and updated it in the Jira. <br>
By using the refactor principle we created the ICommand class and created both AddURL and CheckURL that implement it. <br>
Each one of them has its own execute function that their implement as required. <br>
We created the tests for the program and by them we built the classes with different and specific roles for each class. <br>
After that we mereged everything and compiled it all together and started to run the program by checking basic and edge cases. <br>
When everything worked as we expected we upload our program to dockerhub and checked that it worked after we downloaded it from there.
