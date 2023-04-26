#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;

/*Salvador Medina-Ruiz COSC 341*/
/*Number 1: Computes the value of the mathematical constant π*/
double compute_pi(int n){
    double pi = 0; /*Creates pi with 0*/
    double nextNumInPi = 0; /*Creates nextNumInPi with 0*/
    double sum; /*Creates sum*/

    /*The infinite sum formula*/
    for (int i = 0; i < n; i++){
        /*pow(-1, i) alternates - and + based on the result*/
        nextNumInPi = pow(-1, i)/(2*i+1); /*Nerd stuff*/
        sum += nextNumInPi; /*Adds nextNumInPi to the sum*/
    }
    pi = 4 * sum; /*Pi equals 4 times the sum*/
    return pi;
}

/*Number 2: Reads student scores from a user and displays the following: the
average score, the minimum score, and the maximum score.*/
void scores(){
    double sumOfScores = 0; /*Creates sumOfScores with 0 value*/
    double numOfScores = 0; /*Creates numOfScores with 0 value*/
    double averageScore = 0; /*Creates averageScore with 0 value*/
 
    double currentScore = 0; /*Creates currentScore with 0 value*/
    double maxScore = 0; /*Creates maxScore with 0 value*/
    double minScore; /*Creates minScore*/
    cout << "Please enter the score of a student, or -1 to quit: ";
    cin >> currentScore;
    if (currentScore == -1){ /*Checks if imput was -1*/
        minScore = 0; /*If yes, sets minScore to 0*/
    }
    else{
        minScore = currentScore; /*Else, sets it to the current score*/
    }
    while (currentScore != -1){ /*Keeps going if current score (input) is not -1*/
        sumOfScores += currentScore; /*Adds current score to sumOfScores*/
        numOfScores++; /*Increments numOfScores*/

        if (currentScore > maxScore){ /*Checks if current score is bigger than maxScore*/
            maxScore = currentScore; /*If yes, then current score is new maxScore*/
        }

        if (minScore > currentScore){ /*Checks if the minScore is larger than the current score*/
            minScore = currentScore; /*If yes, then current score is new minScore*/
        }

        cout << "Please enter the score of a student, or -1 to quit: ";
        cin >> currentScore;
        averageScore = sumOfScores/numOfScores; /*averageScore equals sumOfScores divided by numOfScores*/
    }
    cout << "The average score is: " << averageScore << "\n";
    cout << "The minimum score is: " << minScore << "\n";
    cout << "The maximum score is: " << maxScore << "\n";
}

/*Number 3: Reads an input file and creates a sorted output file. */
void file_sort(char *infile, char *outfile){
    ifstream fin(infile); /*Creates input file*/
    ofstream sortedOut(outfile); /*Creates output file*/

    int numOfStudents; /*Created numOfStudents*/
    fin >> numOfStudents; /*Reads first line from input file and puts the int into numOfStudents*/

    /*Creates dynamics arrays for id, grade, and gpa*/
    int *id = new int[numOfStudents];
    char *grade = new char[numOfStudents];
    double *gpa = new double[numOfStudents];

    /*Creates temp variables for id, grade, and gpa to be used later for sorting*/
    int tempId;
    char tempGrade;
    double tempGpa;

    /*Goes trough the whole input file and saves id, grade, and gpa to coressponding array*/
    for (int i = 0; i < numOfStudents; i++){
        fin >> id[i] >> grade[i] >> gpa[i];
    }

    sortedOut << numOfStudents << "\n"; /*Puts the numOfStudents back onto the first line of the output file*/
    /*Selection sort is used here in order to properly sort the arrays into ascending order of Id*/
    for (int i = 0; i < numOfStudents; i++){
        for (int i2 = i + 1; i2 < numOfStudents; i2++){
            if (id[i] > id[i2]){
                tempId = id[i];
                id[i] = id[i2];
                id[i2] = tempId;

                tempGrade = grade[i];
                grade[i] = grade[i2];
                grade[i2] = tempGrade;

                tempGpa = gpa[i];
                gpa[i] = gpa[i2];
                gpa[i2] = tempGpa;
            }
        }
    }
    
    /*Once arrays are sorted, they are printed BACK into the input file*/
    for (int i = 0; i < numOfStudents; i++){
        sortedOut << id[i] << " " << grade[i] << " " << gpa[i] << "\n";
    }

    /*Just closes the input and output files, as well as deletes the arrays from earlier*/
    fin.close();
    sortedOut.close();
    delete []id;
    delete []grade;
    delete []gpa;
}

/*Number 4: Rectangle class*/
class Rectangle
{
private:
    double width; /*Private width*/
    double height; /*Private height*/
public:
    Rectangle(); /*No parameter constructor*/
    Rectangle(double size); /*Constructor takes size and sets width and height to it*/
    Rectangle(double width, double height); /*Constructor takes width and height and sets to it the class width and height*/
    void setWidth(double width); /*Takes a width and sets to class width to it*/
    void setHeight(double height); /*Takes a height and sets to class height to it*/
    double getWidth(); /*Returns width*/
    double getHeight(); /*Returns height*/
    double area(); /*Computes the area*/
    void display(); /*Displays width and height*/
};

Rectangle::Rectangle(){ /*No parameter constructor. Sets width and height to 0*/
    width = 0;
    height = 0;
}

Rectangle::Rectangle(double size){ /*Constructor takes size and sets width and height to it*/
    width = size;
    height = size;
}

Rectangle::Rectangle(double width, double height){ /*Constructor takes width and height and sets to it the class width and height*/
    this->width = width;
    this->height = height;
}

void Rectangle::setWidth(double width){ /*Takes a width and sets to class width to it*/
    this->width = width;
}

void Rectangle::setHeight(double height){ /*Takes a height and sets to class height to it*/
    this->height = height;
}

double Rectangle::getWidth(){ /*Returns width*/
    return width;
}

double Rectangle::getHeight(){ /*Returns height*/
    return height;
}

double Rectangle::area(){ /*Computes the area*/
    return (width * height);
}

void Rectangle::display(){ /*Displays width and height*/
    cout << "Width is " << getWidth() << " and Height is " << getHeight() << "\n";
}

/*Number 5: Score class*/
class Score
{
private:
    double *arrayScores; /*Private arrayScores*/
    int numOfStudents; /*Private numOfStudents*/
public:
    Score(int numOfStudents, double *arrayScores); /*Constructor takes numOfStudents and arrayScores and sets it to the class versions*/
    ~Score(); /*Deconstructor that deletes arrayScores array*/
    double average(); /*Computes the average by going through each value of the arrayScores array*/
    void display(); /*Displays each scores in the arrayScores array and the average. Uses average()*/
};

Score::Score(int numOfStudents, double *arrayScores){ /*Constructor takes numOfStudents and arrayScores and sets it to the class versions*/
    this->arrayScores = arrayScores;
    this->numOfStudents = numOfStudents;
}

double Score::average(){ /*Computes the average by going through each value of the arrayScores array*/
    double sumScores = 0;
    for (int i = 0; i < numOfStudents; i++){
        sumScores += arrayScores[i];
    }
    return (sumScores/(double)numOfStudents);
}

void Score::display(){ /*Displays each scores in the arrayScores array and the average. Uses average()*/
    cout << "Scores: ";
    for (int i = 0; i < numOfStudents; i++){
        cout << arrayScores[i] << " ";
    }
    cout << "\nAverage: " << average();
}

Score::~Score(){ /*Deconstructor that deletes arrayScores array*/
    delete []arrayScores;
}

/*Number 6: Person class and Student class*/
class Person
{
private:
    string name; /*Private name*/
    int age; /*Private age*/
public:
    Person(string name, int age); /*Constructor that takes name and age and sets it to class name and age*/
    void setName(string name); /*Takes a name and sets it to class name*/
    void setAge(int age); /*Takes an age and sets it to class age*/
    string getName(); /*Returns name*/
    int getAge(); /*Returns age*/
};

Person::Person(string name, int age){ /*Constructor that takes name and age and sets it to class name and age*/
    this->name = name;
    this->age = age;
}

void Person::setName(string name){ /*Takes a name and sets it to class name*/
    this->name = name;
}

void Person::setAge(int age){ /*Takes an age and sets it to class age*/
    this->age = age;
}

string Person::getName(){ /*Returns name*/
    return name;
}

int Person::getAge(){ /*Returns age*/
    return age;
}

class Student : public Person /*Inherits all the public methods from Person for Student*/
{
private:
    int id; /*Private id*/
    double gpa; /*Private gpa*/
public:
    Student(string name, int age, int id, double gpa); /*Constructor that sets class id and gpa. Name and age are passed to Person constructor*/
    void setId(int id); /*Takes an id and sets it to class id*/
    void setGpa(double gpa); /*Takes a gpa and sets it to class gpa*/
    int getId(); /*Returns id*/
    double getGpa(); /*Returns gpa*/
    void show(); /*Properly shows student's name, age, id, and gpa*/
};

Student::Student(string name, int age, int id, double gpa) : Person(name, age) /*Constructor that sets class id and gpa. Name and age are passed to Person constructor*/
{ 
    this->id = id;
    this->gpa = gpa;
}

void Student::setId(int id){ /*Takes an id and sets it to class id*/
    this->id = id;
}

void Student::setGpa(double gpa){ /*Takes a gpa and sets it to class gpa*/
    this->gpa = gpa;
}

int Student::getId(){ /*Returns id*/
    return id;
}

double Student::getGpa(){ /*Returns gpa*/
    return gpa;
}

void Student::show(){ /*Properly shows student's name, age, id, and gpa*/
    cout << "Name: " << getName() << " Age: " << getAge() << " Id: " << getId() << " Gpa: "<< getGpa() << "\n";
}