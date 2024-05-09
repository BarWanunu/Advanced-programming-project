# Advanced-programming-project

## Avout the TCP server and BloomFilter.
The Bloom Filter is an array that holds URLS, which are considered "invalid Urls". <br>
When a user tries to publish a Post on Facebook with one of the URLs, he will get rejected.<br>
The bloom filter works with a hash function that is in charge of the insertion and searching of URLs. <br>
We developed the BloomFilter in the first step of the project and updated it to work with the TCP server in the 4th part of the project.<br>
The TCP server is a multi-thread server whose purpose is to manage the bloom part and communicate with the Node.js server that is in charge of all the Facebook apps.<br>
the Node.js is sending a request for the TCP server, with the same protocols we decided on in the first parts.<br>
You can see the initialization of the bloom filter values and the invalid URL list on the env file of the node.js server.<br>
when a user is uploading a post with a URL the node.js server sends the URL to the Bloom Filter to see if the URL is allowed, and gets a response from the TCP server with the relevant answer. if the url is not allowed the post will not be posted.<br>

![image](https://github.com/BarWanunu/Advanced-programming-project/assets/132774208/db00a1f9-adeb-445f-b240-d1cc976f59bd)

# Before running:
You need to make sure you have a VS code Software that will help you run this code.<br>
You also need to make sure you have tools that are used to compile C++ programs.<br>
open the terminal and run these:<br>
-sudo apt-get update<br>
-sudo apt-get install -y g++.<br>
-sudo apt-get install lightest-dev cmake<br>


# How to compile and run our program:

1. download our Advanced-programming-project folder (from branch "ex4-branch"!) 
https://github.com/BarWanunu/Advanced-programming-project.git
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


# Our workflow

At first, we divided the missions between us and updated them in the Jira. <br>
We change the Bloom Filter to work as a TCP server and get all the inputs from clients instead of input from the terminal.
We connected the Node.js to the server and made sure everything was working correctly.
We created a new Docker file, and a new Releasse and uploaded an image to DockerHub.
When everything worked as we expected we uploaded our program to dockerhub and checked that it worked after we downloaded it from there.
By using the refactor principle we created the ICommand class and created both AddURL and CheckURL that implement it. <br>
