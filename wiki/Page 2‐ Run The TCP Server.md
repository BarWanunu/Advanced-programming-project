This page is referring to this Repository:https://github.com/BarWanunu/Advanced-programming-project/tree/ex4_branch

## About the TCP server and Bloom Filter.
 The Bloom Filter acts as an array housing URLs categorized as "invalid URLs." Upon a user's attempt to publish a post on Facebook containing one of these URLs, the post gets rejected.<br>
 The Bloom Filter operates alongside a hash function responsible for URL insertion and retrieval.<br> 
 Initially developed as the first part of the project, we later upgraded it to collaborate with the TCP server in the project's fourth phase.<br>

The TCP server operates as a multi-threaded entity, managing the Bloom Filter's functionality and interfacing with the Node.js server, which oversees all Facebook applications. <br>
Communication between the Node.js server and the TCP server follows predetermined protocols established in earlier project phases.<br>
Initialization values for the Bloom Filter and the invalid URL list are configured in the Node.js server's environment file.

When a user attempts to upload a post containing a URL, the Node.js server forwards the URL to the Bloom Filter to verify its legitimacy. Subsequently, the Node.js server receives a response from the TCP server, determining whether the URL is permissible. If deemed invalid, the post is withheld from publication.

For operational clarity, refer to the provided screenshot:
![image](https://github.com/BarWanunu/Advanced-programming-project/assets/132774208/f75b057d-cd55-4589-a54a-e8493d8f34ce)

# Before running:
You need to make sure you have a VS code Software that will help you run this code.<br>
You also need to make sure you have tools that are used to compile C++ programs.<br>
open the terminal and run these:<br>
-sudo apt-get update<br>
-sudo apt-get install -y g++.<br>
-sudo apt-get install lightest-dev cmake<br>


# How to compile and run our program:

1. download our Advanced-programming-project folder (from branch "ex4-branch"!) 
https://github.com/BarWanunu/Advanced-programming-project/tree/ex4_branch
2. put the next commands in that folder on the terminal:
3. cd src
4. make
5. ./myprogram
6. our program is now running on your computer!

# Use the Docker to run:
1. enter the terminal in the folder of this repo.
2. run the following commands:
3. sudo docker build -t myprogram .
4. docker run -p 5555:5555 myprogram
5. our program is now running on your computer!

