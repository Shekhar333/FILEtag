# File-Tag-System

In this File-Tag-System we create a software that will help users organize their Files on disk using Tags.
• A tag is an arbitrary value that can be associated with a file. (Like names of people, places, events, etc.)
• Users should be able to tag their files and locate them using tags.
• A file can be associated with multiple tags, and a tag can be associated with multiple files.
• You can relate it to something like how an email-client help organize emails using labels.

ESSENTIAL FEATURES : 

The user is given the choice to tag any file he like with two option,either tag by name(in this the user will provide tags of any name they want , with execption that 
tag name cannot consist of space(' ') or hyphen('-'))or tag by color(in this user will be given the option to choose any color to tag a file).

The File-Tag relationships is stored in a file in the system and is used as storage and is also accesed by the program during execution.The file is maintained using
C/C++ command.In the program , the data is managed with the help of map and set data structure where with the help of map , we can simply link files to tags.

As the data is stored in file in user's system , it is free from any database and it forms a local txt file to store its data in the user's system itself.

The data is stored in txt file and is always reused , in order to do that , as soon as the program is executed , we call the class preprocessing , and it stores
all tag by name from the txt file database.txt to the map tag_by_name and similarly for all the tag by color , its stores all the tag by color from txt file
database_color.txt and stores it in the map tag_by_color.In case the program is executed for first time and the files do not exist , so it will not enter the 
preprocessing , as it will just slow down the program , or might give an error if we proceed furthrt , with garbage data.

LOCATING FILES :

As for tagging the file we provided the user with two options , tag by name or tag by color.Similarly in order to search , the user is provided with search by
tag name or tag color option. The tag name/color is taken from user as input and sent to corresponding functions of class Search.If the tag entered by user exist
in the file , the user will be provided with all the required locations related to tag.In case the given tag does not exist in the file , then we try to provide
the user with other possible tag names it could have been and respective file locations , for this we used a very known concept of dynamic programming , known as
LCS(Lowest Common Subsequence) and it provides all potential searches or related searches if exists , or simply , it will say no related searches.

DISPLAY TAGS :

We provide the user to view all the tags by name or tag by color or both as per the input provided by the user.

DELETING A FILE'S TAG :

User is first of all asked to provide with his choice whether he want to carry out this operation using tag by name or tag by color.The user is then asked to
provide details regarding the tag and file location . If the tag is not found in the file storing the file-tag relationships , then the user is simply informed
the given tag does not exist , or if the file doesnot exist at that tag it is informed to user that no such file found in that tag otherwise, the file's 
tag is removed . 

UPDATING TAG  :

If a file is renamed in the system , then the system is suppose to provide the program with suitable input of, if updation is done using tag name or tag color , 
then the files previous storage location and where it is currently going to be stored is taken as input , along with tag where we want to update it , and then the given file's previous data related to tag is deleted and new data is inserted back .
