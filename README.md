# SMS_CPP_project
1. Requirement Analysis for System 
1.1 The Background and Motivation of System
Consuming in the supermarket is already a common activity for customers. However, for the shop owners, managing a shop is not an easy thing. To ensure the normal operation of the supermarket, the owner should record the purchasing cost, update inventory situation, calculate daily, monthly, quarterly and annual sales information, collect member information, hold special offers and propagandize promotion activity through SMS. The data is quite enormous and complicated. Dealing with these data is also a huge project. 
If all the aforementioned work is accomplished by people, it is too tedious, time-consuming and complicated, along with a high probability of mistakes. The enormity of the project suggests work involving a computer system, so we propose to build a supermarket system, which contains all the functions necessary for the daily operation of a supermarket, to replace manual work for these tasks efficiently with a lower error rate. This system also has other advantages: it reduces the costs of hiring more assistants and accountants, timely notifies owners to stock and deal with overdue goods in time, calculate automatically once the supermarket is on sale, settles accounts daily and  monthly automatically.
1.2 System Objectives
1) The system is supposed to gather the basic information of commodities, such as name, number, price, quantity in stock, etc., in order to build a database for the stock information as well as update the record according to each transaction. All of the information can be created, updated, modified and deleted by users.

2) As the supermarket offers membership, the system is required to record the members’ personal information, including name, phone number and birthday. Also, every sale record is linked with the member. Record for non-members are not required to recorded specially. The VIP members are also provided with member points, every consumption can add points to the membership account. The points can be used to exchange for gifts. Super VIP members are provided with membership discount, which depends on the total points. All of the information can be created, updated, modified and deleted by users.

3) This system is also supposed to keep every record for sales, including date, time, total price and profit earned, so that the owner can summarize the sales information daily and monthly. This will interact with the stock information and membership points. All of the information can be created, updated, modified and deleted by users.

4) The system help the shop owner to provide some special offers. At the birthday of a super VIP member, a 0.9 discount is provided to him or her. When holidays are approaching, a discount can also be set by the shop owner. When a discount is set or other special offer is provided, the system is required to do the calculation automatically. 

2. Program Analysis
2.1 Key Issues for System
1)Arrangement for base classes and data members
At first, we will create 4 base classes: 
The first one is “DateAndTime”, which contains year, month and day as its data members. It provides three get functions, three set functions and a print function.
The second one is “Goods”, which includes the name, number, price, cost and quantity of the goods as its data members. 
The second one is “VIP”, which includes a member’s phone number, his birthday (a composition of class “Date”) and his membership points. When a VIP customer buys the goods, the “increasePoint” function will add certain points to membership points. What’s more, when a VIP customer choose to use these points to buy things or exchange for gifts, member function “decreasePoint” is needed. 
2) Class inheritance structure and composition
And then, we will initially create 3 derived classes based on the base classes (maybe add more or decrease some of them while practice as appropriate). 
The first derived class “SuperVIP” derived from “VIP”, whose additional data member is membership discount. Member function “getVipDiscount” will return the discount rate in other classes. With higher points, the super VIP member will enjoy a higher discount compared to those with lower points. Member function “setVipDiscount” will determine the discount rate automatically when an object is constructed. 
The composite class “Account”, which includes the purchaser that is a composition of class “VIP”, an array containing information of items (a composition of an object from class “Good”), another array to store their quantities, purchasing time and date that is a composition of class “DateAndTime”, a total cost of type double and a profit of type profit. The class has two virtual member function called “calculateTotal” and “calculateProfit” ,which will be override in the derived class “DiscountAccount”. 
The second derived class is “DiscountAccount” whose base class is “Account”. It inherits the information of goods, date, time, total cost and total profit. Its additional data member is “svipmember” that is an object of “SuperVip” class. As is mentioned above, the class will override the “calculateTotal” and “calculateProfit”, taking the discount rate into consideration. 

3)Global function 
This part contains some functions which enable the workers and the boss to search, delete or modify the file of data according to their wishes and actual requirements (such as a completed transaction). 
The functions are divided into five groups for goods, VIP members, accounts, daily summary and monthly summary respectively. 
4)Files
There are five files to record all the information of this system. 
a.	A file made up of Goods class to record all the stock information. 
b.	A file made up of VIP class to record all the information of VIP Members. 
c.	A file made up of SuperVIP class to record all the information of super VIP members.
d.	A file to store every account’s main information.
e.	A file to record everyday profit and turnover.
f.	A file to record every month’s profit and turnover. 
2.2 Duty Assignments
Because this system is complex, and our group wants every member to take part in the production of the system, we made a plan about how we allocate tasks according to what everyone is good at.
From week 10 to 12, we will mainly focus on the plan as well as the proposal writing task. Xu Chenshu came up with the idea of what we would do, a system which can help shop owners do their works better and more conveniently. She also finishes most of the introductions about this system. Deng Jing wrote the background part and also is responsible for the presentation. Feng Shilong and Li Mingyang wrote the Program Analysis part. Besides, Deng Jing and Xu Chenshu are responsible for the checking of this proposal. 
From week 12 to 13, we need to write the source code in order to achieve our goals. In C++, we should create basic classes and derived classes, containing lots of data members and functions. Deng Jing and Xu Chenshu are careful and meticulous, having better understanding on the related knowledge, so they can do this work. As for the check and correct work, Li Mingyang and Feng Shilong will write the file processing functions. In this way, our group can finish the source code. 
In week 14 and 15, Deng Jing and Xu chenshu will connect the functions and classes to the UI system. Also the debugging work is supposed to be done. 
In week 16, we will prepare for the defense together. 
3. Technical Routine
3.1 Runtime Environment
Windows 10, Qt Creator 4.5.1 (Community)
3.2 General Design
1) Classes for data files
i) “DateAndTime” class
ii) “Goods” class
iii) “Vip” class
iv) “Super Vip” class
v) “Account” class
vi) “DiscountAccount” class
2) Functions for file processing
  i) Functions for goods file
  ii) Functions for VIP and super VIP files
  iii) Functions for account file
  iv) Functions for daily account file
  v) Functions for monthly account file
  3) UI design

i)	Commodity Part: Goods In Dialog, Update/Search/Delete Goods Dialog, View All Dialog
ii)	Members’ Part: New Member Dialog, Update/Search/Delete Member Dialog, View All Dialog
iii)	Check Out Part: Search Member Dialog, Check Out Dialog
iv)	Account Summary Part: Daily Account Dialog, Monthly Account Dialog, Search Account Dialog
v)	Login Part: Login Dialog, Change Password Dialog
3.3 Detailed Design
1) Functions and data members in classes
In class account, we declare an array whose elements are objects of class goods. When we check out, we add goods we buy to this goods array and we store the quantity of the goods we buy in another array called goodQuantity.







     In class dateAndTime, we use operator overloading to compare two objects of class dateAndTime. In the function shown below, we compare the time by compare the year, month, day, hour, minute, second one after another. 











     In class vip, we have two data members, namely point and totalPoint. The two points are different, as point represents the current points of the vip (or super vip) member and total point is the nondecreasing points only increased when the vip (or super vip) member buy goods. The point data member is decreased when the points are used to exchange for gifts. The totalPoint data member determine the discount of a certain vip (or super vip) member. In short, you can use your points to exchange gift, and for super VIP members, the more goods you have bought, the more discount you will get.










Additionally, super VIP member have a function to determine their final account if it is his birthday. 
There is polymorphism in the design of Account and DiscountAccount class so that when a pointer of base class Account is pointed to a DiscountAccount object, they invoke the functions differently. 

2) Functions for file processing
i) Functions for goods file
  In this part we used random file processing. We store the Goods object with the number of it. We initialized the file in class-sized empty objects, then we can write the goods according to its numbers, that determine their locations. We access the file randomly using its fixed location. This technique avoids going through all the file and save time. 
ii) Functions for VIP and super VIP files
  In this part, we used sequential file processing in order that we can search for a member with its phone number. We persistently add new members at the end of the file, and every searching action will go through the whole file. 
iii) Functions for account file
  In this part we specially use binary search for the sequential file. Since the file is arranged in time-order, we use the binary search to get the number of record that just after the specific time and also the number of record that just before a time. By using these two numbers, we can get all the records of accounts between two given time. 

iv) Functions for daily account file and Functions for monthly account file
In the two parts we also apply binary search to depend the date or month to display account and profits. The record of daily account and monthly account are updated automatically and dynamically to store information correctly. If it is a new day or a new month, a new record is created. 

3) UI design
i) Open txt in a dialog to display information:
      In the viewAllMember dialog and stockInformation dialog, we use a line edit to print the content of the txt line by line. We first open a txt file using QFile, then use the function of QTextStream----atEnd to judge if pointer is pointing to the end of the file. If not,  append function and readline function will be invoked to display the information in the txt line by line. The codes which implement the aforementioned function is as following:










ii) slots connections between buttons and dialogs
When we clicked the button or menu in the mainwindow or in a dialog, the interface will skip to another dialog naturally. That’s because we use slots to connect the button with the next dialog. In mainwindow, a certain function connect()with four parameters is invoked, which will be shown below. As for buttons in a dialog or mainwindow, we declare an open function in the private slots, and in this function, we new a pointer point to the dialog, the wen invoke the show() function to open the dialog. The codes that implement the aforementioned function is as follows:







iii) Use file processing to change password 
When the old pass word entered is correct, if the new passwords in the two line edits are the same, the file named "pw.dat" will be opened with ofstream. If open successfully, the new password will take the place of the old one and be written out to file. If not, an error message will be sent to remind you of the failure of opening the file.













iv) Use tab widgets to display VIP and super VIP information separately.
There are three classes in the viewAllMember dialog, a class for main dialog, a class for VIP tab widget and a class for super VIP tab widget. The layout and widget of the two tabs class are separated, and the each button has its own slot function to open different txt files, one for VIP only and one for super VIP only. 
vi)	Set holiday discount.
When it comes to holiday, the system is allowed to set discount for holiday by just clicking the set discount button in the main window and entering the number at the discretion of the store owner. 
vii)	Check out
First, in Search-Phone-Number Dialog, we enter the phone number to search the VIP or Super VIP member information. A VIP or Super VIP object is created. If the customer is not a member, we click “Skip” button to get into next part directly. 
Then we pass the object using slots to next dialog, which is the Check-Out Dialog. The objects are used to initialize a pointer to an Account object. 
In the Check-Out part, we apply polymorphism to the Account and DiscountAccount. When “Add” Button is clicked, a commodity is added to the table, with its quantity. If the required quantity is more than the stock quantity, a warning will be thrown out. When check out button is clicked, the pointer to Account will invoke function CalculateTotal and CalculateProfit respectively and polymorphism is applied in this part. 
After that, we click “OK” button to update goods’, member’s and account’s files.
4. Programming Progress
Phases of Mission	Period	Planned Completion	Actual Completion
Determining the topic and submit the proposal	2018.05.09-2016.05.16	Survey the interesting topics and writing the proposal.	Finish our proposal and decide the divide of work.
Build up the basic classes and derived classes.	2018.05.17-2016.05.23	Finish writing all the .cpp file and .h file of both basic and derived classes. Debug the codes written.	Finish writing all the .cpp file and .h file of both basic and derived classes. Debug the codes written.
Build up fundamental user interface with QT 	2018.05.24-2016.05.30	Divide work again. Learn the basic operation of QT online and build up a general framework of the interface. Continue to debugging the codes written.	The basic interface is build without seriously designed. Continue to debugging the code written.
Continue to learning QT deeply and design the interface, make it user-friendly. 	2018.05.31-2016.06.6	Learn UI deign online, determine the theme color, add background layouts and design our own logo.	Decide green and blue to be the skin color, beautify all the dialogs, including all the widgets in the certain window.
Continue to beautify the UI interface, debug all the codes, eliminate all the bugs, finish the finally report and ppt.	2018.06.07-2016.06.13	Slightly adjust the interface, test the system to eliminate all the bugs, finish the finally report and ppt.	Set the final vision of the interface, finish the final report and the ppt of the presentation.

Note: The progress for each week should be recorded. The project will be started from May 9, 2018 and ended at June 13, 2018. 

5. Testing Report
5.1 Function testing
1. Add new goods
 
2.Modify goods
 
There are too many functions for file processing, so we do not list all of them one by one. All of them have been tested successfully. 
3.View All Information

4.Search account according to date: Success
5.Access daily and monthly account: Success
  

5.2 System testing
1.Search a VIP member with phone number
 
2.add goods to the account
 
3.Check out
 
4. Add points to member record and change the goods information, create account record and update daily account. It runs successfully. 
 
 
 

5. Set discount manually
 
6. Exchange gifts
 
7. Change password: Success
 
Summary: All the functions and the system run smoothly and successfully. They are designed user-friendly. And the UI design is beautiful and concise. It is a comprehensive program and easy to use. 
