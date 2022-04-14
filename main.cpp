#include <iostream>

using namespace std;

class Animal {
private:
  int weight;
  int height;
  int age;
  int Id;
public:
  string colorOfSkin;
  string colorOfEye;
//1. Create a protected member named cookies. The feed() method that we will write later, will use this variable.
protected:
int cookies;

public:
Animal() {//const with no param
  weight=0;
  height=0;
  age=0;
  Id=-1;
  cookies = 50;
}
Animal(int Weight, int Height, int Age) {//const with 3 param
  weight=Weight;
  height=Height;
  age=Age;
  Id=-1;
  cookies = 50;
}
Animal(int Weight, int Height, int Age, int aId) {//const with 4 param
  weight=Weight;
  height=Height;
  age=Age;
  Id=aId;
  cookies = 50;
}
public:
    int getWeight() {
      return weight;
    }
    void setWeight(int x) {
      if(x<0){
        cout<<"invalid input for weight '"<<x<<"' ignored\n";
      } else {
      x = weight;
    }
  }
      public:
   
    int getHeight() {
      return height;
    }
    void setHeight(int x) {
      if(x<0){
        cout<<"invalid input for height '"<<x<<"' ignored\n";
      } else {
      x = height;
    }
  }
      public:
    int getAge() {
      return age;
    }
    void setAge(int a) {
      if(a>0 && a<120){
        a = age;
    } else {
        cout<<"invalid input for age '"<<a<<"' ignored\n";
    }
  }
virtual void Speak(int x) {
  if (x<0){
    x=0;
  }
  for (int i=0; i<x;i++){
  cout<< "some random animal sound\n";
  }
}

/* 4. Create a method called as Feed that takes no parameters and does not return any value.
a) Inside this method, decrease cookies by 1 and write a message "Fed the animal 1 cookie".
b) Set this method to be virtual*/
virtual void Feed() {
  cookies -= 1;
  cout<< "Fed the animal 1 cookie\n";
}
  
void intro() {
  cout<<"Weight: " <<weight<< " Height: " <<height<< " Age: " <<age<< " Id: " <<Id<<"\n";
  cout<<"Color of skin: " <<colorOfSkin<< "\n"" Color of Eyes: " <<colorOfEye<<"\n\n\n";
}
};

class Dog: public Animal {
private:
string breed;
string size;

public:
string getBreed(){
  return breed;
}
string setBreed(string b){
  return breed=b;
}
/*Add getter and setter for size. Valid values are "L", "M" and "S" to denote large, medium and small dogs. Any other value should be ignored and a message should display that the value has been ignored.*/
string getSize() {
  return size;
}
string setSize(string s) {
  if (size=="L" || size=="M" || size=="S") {
    return size = s;
  } else {
    return "Value has been ignored\n";
  }
}
public:
/*4. Add a constructor with no parameters. It should call the base constructor with no parameter. Insdie this constructor, set size to "L" and breed to "Unknown" and cookies to 50.*/
Dog() : Animal() {
  size="L";
  breed="Unknown";
  cookies=50;
}
/*5. Add a constructor with 3 parameters - weight, height and age. It should call the base constructor with 3 parameter. Insdie this constructor, set size to "L" and breed to "Unknown" and cookies to 50.*/
Dog(int Weight,int Height,int Age) : Animal(Weight,Height,Age) {
  size="L";
  breed="Unknown";
  cookies=50;
}

/*6. Create a method called Speak (it should be similar to base class Speak method) and add logic to display "bark" x number of times. x is the input parameter. The function does not return any value.*/
void Speak(int x) {
  if (x<0){
    x=0;
  }
  for (int i=0; i<x;i++){
  cout<< "bark\n";
  }
}

/*7. Create a method called Feed (it should be similar to base class Feed method). Add logic to subtract 1 from cookies if size is "S", 2 from cookies if size is "M" and 4 from cookies if size is "L". For any other value of size, display message "Invalid size value. So we cannot determine the number of cookies to feed the dog". 
At the end, display the message "Remaining cookies" and display cookies variable value.*/
void Feed() {
  if(size=="S") {
    cookies -= 1;
  }else if(size=="M"){
    cookies -= 2;
  }else if(size=="L") {
    cookies -= 4;
  } else {
    cout<<"Invalid size value. So we cannot determine the number of cookies to feed the dog\n";
  }
  cout<< "Remaining cookies: " <<cookies << "\n";
}
};

int main() {
  //Test all newly updated functionality by creating appropriate objects in main.cpp for both Animal and Dog. 
  cout << "|c++Lab11|Author:Charles Yingling\n";
Dog a1 (5,15,4);
  a1.colorOfSkin = "Black";
  a1.colorOfEye = "Brown";
  a1.Speak(5);
  a1.Feed();
  a1.intro();
Animal a2 (6,2,8);
  a2.colorOfSkin = "Spotted";
  a2.colorOfEye = "Blue";
  a2.Speak(4);
  a2.Feed();
  a2.intro();
Dog a3;
  a3.colorOfSkin = "Black";
  a3.colorOfEye = "Brown";
  a3.Speak(2);
  a3.Feed();
  a3.intro();
Animal a4 (6,2,8,3);
  a4.colorOfSkin = "Spotted";
  a4.colorOfEye = "Blue";
  a4.Speak(3);
  a4.Feed();
  a4.intro();
}