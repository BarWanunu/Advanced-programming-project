This page is referring to this Repository:https://github.com/shakedg1234/ex3/tree/ex4_final_branch

## About the Node.js server
Welcome to our facebook server. This server is made for out React and android Facebook app that we developed during the course of Advensed Programming in BIU.
Our Node.js server serves as the central backend component for our Facebook project, facilitating communication between our React web app, Android mobile app,
and database. Built on Express.js, it follows an MVC architecture, handling user authentication, data management, and real-time updates. With RESTful APIs,
it seamlessly integrates with our client applications, ensuring smooth user interactions.

## How to Run the Server?
To begin, clone the project from the following URL: https://github.com/shakedg1234/ex3.

### Before Running
Before running the server, please ensure the following:

1. Make sure that you have MongoDB Compass installed on your computer.
2. Ensure that the TCP server is running on your computer. You can download it from here: https://github.com/BarWanunu/Advanced-programming-project/tree/ex4_branch.
3. Open the project in VS Code. In the env.local file, you can adjust the size and the number of hash functions you want to initialize the Bloom filter with using the BLOOM_PART_INITIALIZE variable. Additionally, you can modify the list of invalid URLs using the URL_LIST variable.
4. To connect to the TCP server, adjust the IP address in the TCP_SERVER_IP variable. If you are running the TCP server on a virtual machine, you will need to use the machine's IP address, which you can find using the command ifconfig.
![image](https://github.com/shakedg1234/ex3/assets/132774208/bed8ed8c-2f56-489a-8d95-e5f16ecd2ddc)

   ![image](https://github.com/shakedg1234/ex3/assets/132774208/3f264bb5-9fa4-4644-817a-d9d639dd6a9d)

### How to Run the Project
To run the project, follow these steps: <br>

Open a terminal and run the command:<br>
npm install<br>
npm install mongodb <br>
Start the server by running:<br>
npm start<br>
The server is now running, and MongoDB should have the relevant collection with our database.<br>
To view the web app, navigate to http://localhost:80/ using port 80.<br>

