# Practices


# Practice 1
## P1.Exercise 1
> cd Practica 1 && g++ exercise_1.cpp -o exercise_1 && ./exercise_1
- Design a C ++ program that allows through a menu to make a set of operations of a calculator. Each type of operation has to be programmed in a method. The operation menu will be as follows:
  - a. Add
  - b. Subtract
  - c. Multiply
  - d. Divide
  - e. Modulus calculation
  - f. Factorial of a Number.
  - g. Squared (Can't use pow function)
- Remember that you can perform as many operations as the user wants


## P1.Exercise 2
> cd Practica 1 && g++ exercise_2.cpp -o exercise_2 && ./exercise_2
- Design a program to print Pascal's triangle on the screen. Remember make an original implementation.

## P1.Exercise 3
> cd Practica 1 && g++ exercise_3.cpp -o exercise_3 && ./exercise_3
- Design a program that allows inserting the personal information of a number n of people (name, age, marital status, weight, height) and allow calculating through a menu of operations.
  - a) Calculate body mass index: it will calculate if the person is at their ideal weight (weight in kg / (height ^ 2 in meters)), if this formula returns a value less than 20, the function returns "Under your weight", if it returns a number between 21 and 25 (inclusive), it means that is below its ideal weight, the function returns an "Ideal Weight" and if it returns a A value greater than 25 means that you are overweight, the function returns "Overweight". Tea I recommend that you use constants to return these values.
  - b) If he is of legal age: indicates if he is of legal age, it will return a Boolean True / False
  - c) Enter Sex (sex char): check that the gender entered is correct. If it's not Right, you must issue a message and request it again.
  - d) GeneraDNI (): generates a random number of 8 digits, generates its number from this its corresponding letter.

## P1.Exercise 4
> cd Practica 1 && g++ exercise_4.cpp -o exercise_4 && ./exercise_4
- Design a function that allows you to calculate your age from a given date in the future (year, month and day). The program must allow you to insert your current age and print the age in the future. For example:
- If you enter a date for example year = 2019, month = 10 and age 19 and you want know your age on the following date year = 2025, month = 7 then the program mus returns that the age for July 2025 will be 24 years and 8 months

## P1.Exercise 5
> cd Practica 1 && g++ exercise_5.cpp -o exercise_5 && ./exercise_5
- Design a free program that allows you to solve a problem. He must have at less 4 methods and a menu of operations managed from the main program.



# Practice 2
## P2.Exercise 1
- Design a program that, given a vector of n elements, sorts it in ascending order and descending.
> cd Practica 2 && g++ exercise_1.cpp -o exercise_1 && ./exercise_1

## P2.Exercise 2
- Write a program that given a vector A and a vector B, all the elements of Vector B in vector A, starting from a position given by the user.

## P2.Exercise 3
- Given a vector of n random elements, create a frequency histogram. Help to build a histogram, https://ingenioempresa.com/histograma/

- The final result can be done by printing the data as follows



                *
                *
      f1     *  *  *
          *  *  *  *  *
          *  *  *  *  *
          R1 R2 R3 R4 R5

       Where f1 is the frequency and R is range


## P2.Exercise 4
- Given a vector of N positions, perform a statistical analysis that allows you to find the mean, median, mode, standard deviation, variance, and if you can calculate the outliers that has that data set.

## P2.Exercise 5
- Dada tres strings de dimensión N, genera un password y luego almacénalo en un cuarto string.
- El password se realizará con la combinación de una letra por cada string.
- Ejemplo string1 = casa
- String2 = mesa
- String3 = coche
- String Resultado = cmcaeosscaahe