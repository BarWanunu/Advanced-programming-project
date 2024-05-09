# Page 4 - The Android Facebook App
This page is refering to the facebook app on android. The link to the repository is : https://github.com/shakedg1234/Foobar_Application/tree/ex3_branch

## Before we begin
In oreder to demonstrate all of the functions and actions you can do in our app you can check out the next video if you would like to : <br>
https://www.youtube.com/watch?v=9AOOTYsxuxs

This facebook app was developed in android studio envionement and it's linked to the Node Js server and the TCP, so please make sure they're both running before you work on this app. <br>
The work on this app in android studio is divided to 2 parts. In the first part we worked only on the basic functions as login screen, and sign in screen of course with all of the functionality. <br>
We had hard coded users we could log in with and inside the main page you could scroll down and see hard coded feed from a json list of posts. <br>
In the second part, we developed the app to make all of the required functions with the server when we need to fetch data or to post data.
If you want to read about each part you can go to specific repositories. <br>
Use the link we gave above for the second part, and for the first part just switch to the maim branch.

## Running the app
Now let's strat the app ! <br>
We will guide you with several steps in order to run the android app. <br>
First, make sure you followed the previous steps of running the TCP server and Node Js server as required. <br>
Afterwards, make sure you download the Pixel 2 device and then press "Sync Project with Gradle Files" button. <br>
Then, make sure the configuration is App and you can start running our facebook app by pressing the green triangle !! <br>
We hope you'll enjoy your experience !

## Login and Sign in
The first page you'll encounter after starting the app is the Sign in page. <br>
In order to sign in to our facebook app you can take one of the users from the mongoDB or to create one for yourself. <br>
If you want to make your own profile you can press the sign up button. <br>
<img width="191" alt="image" src="https://github.com/BarWanunu/Advanced-programming-project/assets/139462169/34c623cf-f02e-440e-9fac-6feaabbc3e3b"> <br>
Afterwards, you'll be transferd to the sign up page where you'll need to fill the required fields. <br>
<img width="191" alt="image" src="https://github.com/BarWanunu/Advanced-programming-project/assets/139462169/a7cac971-b2e9-4151-bcf3-67c5e7a18142">
Be aware, you'll have to fill all of the fields in order to finish the form. <br>
For example - the email address you sign up with must be from the pattern of name@example.com. <br>
For the password choosing it must be in the length of minimum 8 characters and contain letters and numbers. Afterwards, you will have to confirm your password and the values must be identical of course. <br>
After you'll choose your display name for the application and the photo that will be shown you'll get a massage that the form was submmited successfuly and you'll find yourself back in the sign in page. <br>
After you sign in with us you'll get a spesific token that will allow you to make some of the activities we offer for our users by making sure you are indeed the person who are authorized to make the action. <br>
