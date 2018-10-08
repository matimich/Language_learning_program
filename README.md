# Language_learning_program

Author:Mateusz Michalski
Platform:Linux/Windows

The program was created to help people with learning foreign languages. It can be compiled by using makefile attached to project and started in CMD. 
An user may learn language in two different modes. By first step, student has to choose if they want to learn in „normal mode” or „random mode”. Normal mode displays words from file one after another, on contrary to random mode which does that randomly. The aim of the learning is to translate displayed words. In addition, an user may choose if they want to translate words from their native language or to their native language. By default native language is set as „Polish”. To change that all you have to do is rename: „DEFAULT_LANGUAGE” macro which is set in “FileOperation.hpp”. It is possible to display all saved words in application and edit it from the application menu.

File Settings:
All languages have their own text file. An user may type new words directly to txt file or do it by using application. It is crucial to type words in order:
foreign_language – default(native)_language 
In case of adding words in application, you don’t have to remember about line separation, program does that on its own. Remember to do not change txt file name!
